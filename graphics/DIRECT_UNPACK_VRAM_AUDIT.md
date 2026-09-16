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
| Overseas `func_08077810` | `0874E648`, palette `0874EB40`, tilemap `0874ECCC` | US/EU/DE tilemap stream and decoded 32-by-32 entries are byte-identical. JP uses different symbols (`084D4DDC` / `084D529C` / `084D52BC`) and decoded lengths, so it is not a shared counterpart. | The US/EU/DE `0874ECCC` Huffman-4/LZ3 tilemap is managed as a native source and direct assembly input. Its `0874E648` companion uses format `230` with a non-tile-aligned `0x2BE2` output; it remains unclassified. |
| `asm/code_0803EE94.s` remaining isolated consumers | `0852AA6C`, `0875822C` | Most full labelled ranges are shared | The first label is not a standalone `Unpack` stream in the selected data layout; the latter uses unproven format `230` and still needs consumer/layout analysis. |
| `asm/intro_scene.s` direct consumers | `0874E648`, `0874EB60`, `0874A9C0` | `0874E648`/`0874EB60` differ from JP; `0874A9C0` is shared | Unclassified by this audit. Existing Intro Scene pipelines cover other proven object/background streams separately. |

## Native-format evidence

The consumer scan establishes only which native decompression formats appear
at the label boundary. Where the checked source length is a complete packed
stream, these were observed:

| Format family | Direct-call examples | Current capability |
| --- | --- | --- |
| `020` / `030` Raw-LZ | all three managed UI groups; several remaining tilemap candidates | `tools/marvelous_codec.py` has a strict checked encoder. Edited data remains subject to its fixed original slot size. |
| `230` | `086FB004`, `0875822C`, `0874A9C0` | The generic Huffman-8/LZ3 encoder strictly decodes, but its `086FB004` output is `0x21C0`, exceeding the `0x2198` retail slot even without an edit. No fixed-slot encoder has been verified, so these are not presented as editable source assets. |
| invalid header at assembly-label boundary | `0852AA6C` | The selected label range is not itself a standalone `Unpack` stream. It must be split from its real runtime consumer before any extraction. |

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
