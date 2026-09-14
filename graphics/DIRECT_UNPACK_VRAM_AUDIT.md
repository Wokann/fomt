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
| `func_080A2BA4` | `0874EF14`, `0874EF3C`, `0874EFEC`, `0874F050` | Every packed and decoded stream identical | Managed: four native streams; the adjacent palette/archive overlap is intentionally excluded. |
| `func_080AE7D0` | `0872FC34`, `0872FE6C`, `0872FEF8` plus adjacent palette | Every packed and decoded stream plus palette identical | Managed: two tilemaps, 4bpp tiles, and 16-bank palette PNG. |
| `func_080B7164` | `0872D5CC`, `0872D630`, `0872D6D8` | Every packed and decoded stream identical | Managed: two tilemaps and 4bpp tiles; adjacent unproven palette span excluded. |
| `func_080B55D0` area | `086FB004`, `0872C5D0`, `0872C73C`, `0872C84C` | All labelled ranges are identical | The three later `020`/`030` streams are managed as two tilemaps plus 4bpp tiles. Main `086FB004` uses native format `230`, for which no verified encoder exists, and remains unmanaged. |
| `func_080BCFAC` | `0873BE24`, `0873BF48`, `0873BFF0` | Every packed and decoded stream is identical | Managed: two 32-by-32 tilemaps and one exact 4bpp native tile buffer; the adjoining unbounded palette copy remains excluded. |
| `func_080C160C` | `0873F3C8`, `0873F5D4`, `0873F6AC` | Every packed and decoded stream is identical | Managed: two 32-by-32 tilemaps and one 4bpp tile stream; the adjacent unbounded palette copy remains excluded. |
| `func_08054F40` | `08738D1C` | Packed and decoded stream identical in all four regions | Managed: exact 328-tile 4bpp OBJ buffer; its related palette copy remains excluded because it crosses a label boundary. |
| `asm/code_0803EE94.s` remaining isolated consumers | `0872F21C`, `08743058`, `0852AA6C`, `0874E648`, `0874ECCC`, `0875822C` | Most full labelled ranges are shared; `0874E648` and `0874ECCC` are not byte-identical with JP | Unclassified. Two ranges have no valid `Unpack` header at their assembly boundary; other ranges use either unproven format `230` or need consumer/layout analysis. |
| `asm/intro_scene.s` direct consumers | `0874E648`, `0874EB60`, `0874A9C0` | `0874E648`/`0874EB60` differ from JP; `0874A9C0` is shared | Unclassified by this audit. Existing Intro Scene pipelines cover other proven object/background streams separately. |

## Native-format evidence

The consumer scan establishes only which native decompression formats appear
at the label boundary. Where the checked source length is a complete packed
stream, these were observed:

| Format family | Direct-call examples | Current capability |
| --- | --- | --- |
| `020` / `030` Raw-LZ | all three managed UI groups; several remaining tilemap candidates | `tools/marvelous_codec.py` has a strict checked encoder. Edited data remains subject to its fixed original slot size. |
| `230` | `086FB004`, `0875822C`, `0874A9C0` | Strict decoder available through the retail-format reader; no encoder is accepted yet, so these are not presented as editable source assets. |
| invalid header at assembly-label boundary | `08743058`, `0852AA6C` | The label range is not itself a standalone `Unpack` stream. It must be split from its real runtime consumer before any extraction. |

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
