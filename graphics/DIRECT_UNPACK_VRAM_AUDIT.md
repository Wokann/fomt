# Direct `Unpack`-to-VRAM audit

This is a code-consumer inventory, not a broad claim that every direct ROM
include is graphics. `tools/unpack_vram_inventory.py` follows conservative
literal/register data flow through assembly and records a call only when a
named `g*` resource is passed to `Unpack` with a statically recoverable VRAM
destination. The current result has 30 calls and 29 distinct labels; one
label is consumed by both ordinary code and the Intro Scene code.

The inventory does not cover resources delivered through archive dispatch,
DMA copies, OAM tables, indirect pointer loads, or code paths whose target
cannot be recovered statically. It is an auditable subset used to choose safe
next graphics families.

## Classified direct consumers

| Consumer group | Labels / streams | Four-region state | Pipeline state |
| --- | --- | --- | --- |
| `func_080A2BA4` | `0874EF14`, `0874EF3C`, `0874EFEC`, `0874F050` | Every packed and decoded stream identical | Managed: four native streams. The exact palette copy is archive-owned, so it has only verified read-only regional PNG references and no editable/patchable palette source. |
| `func_080AE7D0` | `0872FC34`, `0872FE6C`, `0872FEF8` plus adjacent palette | Every packed and decoded stream plus palette identical | Managed: two tilemaps, 4bpp tiles, and 16-bank palette PNG. Its proven BG control priorities also produce code-backed layer and composite image references. |
| `func_080B7164` | `0872D5CC`, `0872D630`, `0872D6D8` | Every packed and decoded stream identical | Managed: two tilemaps, 4bpp tiles, and the code-bounded 0x200-byte BG palette; generated layer PNGs provide code-backed visual references. |
| `func_080B55D0` area | `086FB004`, `0872C5D0`, `0872C73C`, `0872C84C` | All labelled ranges are identical | The three later `020`/`030` streams are managed as two tilemaps plus 4bpp tiles. Two code-proven but overlapping palette operations now generate a read-only auxiliary BG reference. Main `086FB004` uses format `230`; a generic decoder-compatible encoder exists but its `0x21C0` result exceeds this `0x2198` retail slot, so it remains unmanaged. |
| `func_080BCFAC` | `0873BE24`, `0873BF48`, `0873BFF0` | Every packed and decoded stream plus the explicit 0x200-byte palette copy is identical | Managed: two 32-by-32 tilemaps, 4bpp tiles, code-bounded palette, and code-backed rendered layer references. |
| `func_080C160C` | `0873F3C8`, `0873F5D4`, `0873F6AC` | Every packed and decoded stream plus the literal-pool-confirmed 0x200-byte palette copy is identical | Managed: two 32-by-32 tilemaps, 4bpp tiles, bank-1 palette load, and code-backed rendered layer references. |
| `func_08054F40` | `08738AD8`, `08738D1C`, `087399C4` | Static BG3 map, packed tile stream, and runtime palette copy are identical in all four regions | Managed: exact 328-tile 4bpp BG buffer. The static 32-by-20 map and crossing palette copy generate a verified read-only beach-base reference; only the independently bounded tile stream is editable/patchable. |
| `func_0805AB08` | `0872F11C`, `0872F1BC`, `0872F1EC`, `0872FBFC`, `0872F21C`, `0872FA9C` | All four map templates, tile stream, and runtime palette copy are identical in all four regions | Managed: exact 358-tile 4bpp BG buffer. The code-built BG3/BG2/BG1 maps and crossing palette copy produce verified read-only layers and composite references; only the independently bounded tile stream is editable/patchable. |
| `func_0805FBB8` | `08743058` | Packed stream, decoded 4bpp tiles, and adjacent three palette banks identical in all four regions | Managed by the existing Intro Scene background PNG pipeline. The assembly symbol maps to regional physical locations, so it is not an invalid stream boundary. |
| Seasonal `func_08077EC0` BG group | non-winter `08755848`, winter `0875822C`, palettes `08757AE0` / `0875A358`, and paired `30×13` maps | The complete group is byte-identical in JP/US/EU/DE. DE physically reorders its records, so assembly selects exact regional build files. | The routine chooses winter only when `func_0800E324` returns season 3; both streams decode to 0x8000-byte 4bpp tile sets. Non-winter uses its verified `220` source set. Winter uses an indexed tile grid, six BGR555 palette banks and its unique BG29 map while reusing the byte-identical shared BG30 map. A one-pixel H8/LZ3 edit strictly decodes inside the immutable `0x212C` slot. `reference/*.png` files are code-backed views, not map-editing inputs. |
| Overseas `func_08077810` | character stream `0874E648`, palette `0874EB40`, `32×20` map `0874EB60`, `32×32` map `0874ECCC` | US/EU/DE bytes and decoded output are identical for both maps and the palette. JP uses different symbols (`084D4DDC` / `084D529C` / `084D52BC`) and decoded lengths, so it is not a shared counterpart. | Both BG maps are managed as native sources and direct assembly input. `0874EB60` is a complete `0x500`-byte format `100` / ladder `110` map; its bounded Huffman-4/LZ0 encoder passes a one-byte edit fixture at exactly its `0x16C` slot size. Its `0874E648` companion uses format `230` with a non-tile-aligned `0x2BE2` output. The two maps and one palette render the verified Natsume startup reference, but the trailing non-tile bytes keep this character stream read-only. |
| Overseas `func_0806EC94` Farm Status winter tiles | `0852AA6C` (US; EU header `0852AAC8`; DE `082B1B08`), selected palette `0852CA40` (EU header `0852CA9C`) | US/EU/DE packed bytes and decoded `0x4800` bytes are identical and use format `220`; US/DE palette bytes agree while EU has a distinct selected palette payload behind its archive header. JP has a separate layout path. | Managed: `winter/shared/tiles.png` rebuilds the common native 4bpp grid. An unchanged source preserves each retail stream byte-for-byte; an edited source uses a strictly decoded Huffman-8/LZ3 stream and is rejected beyond the `0x1FD4` tile slot. `reference/winter/tiles_us_de.png`, `tiles_eu.png`, and their matching palette PNGs remain hash-checked references; the EU archive-wrapped palette must be handled separately. |
| `asm/code_0803EE94.s` remaining isolated consumer | `0875822C` | Most full labelled ranges are shared | This uses unproven format `230` and still needs a fixed-slot encoder plus consumer/layout analysis. |
| `asm/intro_scene.s` direct consumers | `0874E648`, `0874EB60`, `0874A9C0` | Startup tiles at JP `4D1154`, US `74A9C0`, EU `74AA1C`, DE `4D1E2C` and their adjacent `0x200` palettes are byte-identical in all four retail ROMs. `0874E648`/`0874EB60` differ from JP. | The startup tile payload decodes as a `0x8000`-byte `230` stream and the four native maps are managed. Its sixteen palette banks and eight code-backed BG-map references are exported and four-region verified. Unchanged tiles retain retail bytes; the one-byte edit fixture strictly decodes inside the `0x3970` slot. |

## Native-format evidence

The consumer scan establishes only which native decompression formats appear
at the label boundary. Where the checked source length is a complete packed
stream, these were observed:

| Format family | Direct-call examples | Current capability |
| --- | --- | --- |
| `020` / `030` Raw-LZ | all three managed UI groups; several remaining tilemap candidates | `tools/marvelous_codec.py` has a strict checked encoder. Edited data remains subject to its fixed original slot size. |
| `100` | overseas `func_08077810` map `0874EB60` | Huffman-4/LZ0 fixed-slot encoder is verified against the shared US/EU/DE stream. It retains retail bytes when unchanged, strictly decodes edited output, and the one-byte edit fixture fits the `0x16C` native slot. |
| `120` | JP `func_08000914` indexed archive `084CDBDC` | Huffman-4/LZ2 has a strict fixed-slot encoder. Its OAM-composited PNG source rebuilds the `0x2D90` JP slot byte-for-byte unchanged, and a real PNG pixel edit strictly decodes within that slot. |
| `220` | Farm Status winter `0852AA6C`, seasonal non-winter `08755848` | Valid Huffman-8/LZ2 streams. The strict decoder has confirmed their native bytes and output. The Farm Status winter grid has also passed a compatible Huffman-8/LZ3 size/decode proof (`0x1FD0` in its `0x1FD4` slot). The seasonal non-winter grid now has a native H8/LZ2 proof: its unchanged decoded payload rebuilds to `0x2160` in the original `0x2298` slot and strictly decodes with the original `25810111214` ladder. |
| `230` | `086FB004`, `0875822C`, `0874A9C0` | The generic Huffman-8/LZ3 encoder strictly decodes. Seasonal winter and the startup payload each have a verified pixel edit inside their immutable `0x212C` and `0x3970` slots, respectively; fixed-slot capability remains asset-specific rather than assumed for every `230` stream. |

## Verification rule

Every managed group must pass all of the following before it appears in
`graphics/COVERAGE.md` as managed:

1. Packed and decoded bytes match across JP, US, EU, and DE, or regional
   sources are explicitly separated.
2. Source rebuild matches each retail physical range byte-for-byte while
   unchanged.
3. Applying generated output to an unchanged ROM preserves the entire ROM
   byte-for-byte in a four-region post-link patch test.
4. A deterministic changed payload is re-encoded and strictly decoded back,
   without writing beyond its proven original slot.

Run the current consumer scan with:

```console
make unpack-vram-inventory
```
