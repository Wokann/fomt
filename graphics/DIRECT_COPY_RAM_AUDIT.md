# Direct `func_08008E64` RAM-copy audit

`func_08008E64` is the ordinary guarded memory-copy helper used by the game.
Unlike `Unpack` and `func_08008F0C`, it does not itself identify an encoded
format. `tools/copy_ram_inventory.py` therefore follows only bounded
literal/register paths where a named `g*` label is copied to literal VRAM or
palette RAM, and records the supplied byte count when it is recoverable.

The current four-region FoMT assembly has sixteen such paths. Every recovered
destination is palette RAM; no named source is copied directly to literal VRAM
by this helper. A row is evidence of a palette upload, not proof that the
entire surrounding `incbin` range is a standalone palette resource.

| Consumer | Source label(s) | Copy destination / count | Classification |
| --- | --- | --- | --- |
| `func_08054F40` | `gUnk_087399C4` | `0x05000000`, `0x200` | Code-bounded palette used by the verified read-only reference of this UI scene. It remains a crossing resource rather than an independent editable palette source. |
| `func_0805AB08` | `gUnk_0872FA9C` | `0x05000000`, `0x200` | Code-bounded palette for the UI-scene reference layers; native bytes remain owned by the enclosing ROM range. |
| `func_0805FBB8` | `gUnk_08747A14` | `0x05000000`, `0x40` | Intro-scene background palette slice, already covered by the managed Intro Scene background pipeline. |
| `func_0806EC94` | `gUnk_08529794`, `gUnk_0852CA40` | `0x05000000`, `0x200` | Non-winter and winter Farm Status palette selections. The former is managed with `base_palettes.png`; the overseas winter palettes remain region-aware references. |
| `func_08077810` and `func_08000F5C` | `gUnk_0874EB40` | `0x05000000`, `0x20` | Shared overseas/intro palette slice associated with the managed `func_08077810` scene resources. |
| `func_08077EC0` | `gUnk_08757AE0`, `gUnk_0875A358` | `0x05000020`, `0xC0` | Non-winter and winter seasonal palette selections, both represented by their managed six-bank BGR555 sources. |
| `func_080A2BA4` | `gUnk_0874F2EC` | `0x05000000`, `0x200` | Archive-owned palette copied for the managed UI scene; preserved as a read-only reference. |
| `func_080AE7D0` | `gUnk_08731940` | `0x05000000`, `0x200` | Managed UI-scene BGR555 palette. |
| `func_080B55D0` | `gUnk_0872D5AC` | `0x050000E0`, `0x200` | Crossing palette upload for the managed auxiliary UI reference; deliberately non-editable by itself. |
| `func_080B7164` | `gUnk_0872DDE4` | `0x05000000`, `0x200` | Managed UI-scene BGR555 palette. |
| `func_080BCFAC` | `gUnk_0873CBF4` | `0x05000000`, `0x200` | Managed UI-scene BGR555 palette. |
| `func_080C160C` | `gUnk_087400E4` | `0x05000020`, `0x200` | Managed UI-scene BGR555 palette loaded at bank 1. |
| `func_080019D8` | `gUnk_0874E330` | `0x05000000`, `0x200` | Managed Intro Scene startup palette banks. |

The result closes the current literal-source `func_08008E64` copy layer. It
does not cover source addresses resolved through tables, caller-provided
pointers, or dynamic destinations; those require a separate consumer audit.

Run the reproducible scan with:

```console
make copy-ram-inventory
```
