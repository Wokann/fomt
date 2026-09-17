# Viewable graphics references

This index separates readable game imagery from native authoring sources.
Every image linked below is generated from a code-proven tile/map/palette path
and has passed its recorded regional verification. A PNG in this page is a
reference for artists and reviewers; it is not a replacement for the native
tilemap, tile stream, OAM, or palette source used by the rebuild pipeline.

## Complete resource images

These are already full, editable image resources rather than arbitrary tile
grids:

- [Dialogue portraits](portraits/shared/full/) — named character portrait and
  expression PNGs; the portrait tile stream rebuilds from them.
- [Referenced actor frames](sprites/actor_archive/full/) — OAM-aware full frame
  PNGs; every retail-referenced descriptor is covered.
- [Farm-status buildings](ui/farm_status/reference/) — complete building and
  status-layout renderings backed by their shared tiles, palette banks, and
  native tilemaps.
- [Farm Status / Town Map OAM resources](ui/farm_status/resource_archive/full/)
  — complete indexed-PNG authoring sources with native archive descriptors.
- [Common OAM resources](common_resource_archive/full/) — complete indexed-PNG
  item/UI resource sources with native selector and OAM descriptors.
- [Small companion OAM resources](small_companion_archive/full/) — sixteen
  complete indexed-PNG OAM resource sources with native descriptors.
- [Small shared UI OAM resources](ui/small_resource_archive/full/) — three
  complete indexed-PNG OAM source views with one preserved native empty slot.
- [Cooking UI OAM resources](ui/cooking_resource_archive/full/) — two complete
  indexed-PNG OAM source views with one preserved native empty slot.
- [Menu UI OAM resources](ui/menu_resource_archive/full/) — eight complete
  indexed-PNG OAM source views with native selector and OAM descriptors.
- [Large shared OAM resources](large_resource_archive/full/) — 102 complete
  indexed-PNG OAM source views with neutral physical group names.
- [Shared OAM resource `08725DA0`](shared_resource_08725da0/full/) — six
  complete indexed-PNG OAM source views; the original address is retained until
  the gameplay semantics are independently established.
- [Shared OAM resource `086F2FAC`](shared_resource_086f2fac/full/) — sixteen
  complete indexed-PNG OAM source views; the original address is retained until
  the gameplay semantics are independently established.
- [Shared OAM resource `086FAA80`](shared_resource_086faa80/full/) — nine
  complete indexed-PNG OAM source views; the original address is retained until
  the gameplay semantics are independently established.
- [Shared OAM resource `0871ECAC`](shared_resource_0871ecac/full/) — four
  complete indexed-PNG OAM source views plus one preserved native empty slot.
- [Shared OAM resource `0871EDD4`](shared_resource_0871edd4/full/) — four
  complete indexed-PNG OAM source views plus one preserved native empty slot.
- [Shared OAM resource `08527094`](shared_resource_08527094/full/) — eight
  complete indexed-PNG OAM source views; native flipped compositions remain
  layout data.
- [Shared OAM resource `08726CCC`](shared_resource_08726ccc/full/) — one
  complete indexed-PNG OAM source view with its native descriptor layout.
- [Shared OAM resource `08727368`](shared_resource_08727368/full/) — nineteen
  complete indexed-PNG OAM source views plus two preserved native empty slots.
- [Shared OAM resource `08727A74`](shared_resource_08727a74/full/) — one
  complete indexed-PNG OAM source view; 36 native flips remain layout data.
- [Shared OAM resource `08728320`](shared_resource_08728320/full/) — twenty-one
  complete indexed-PNG OAM source views with native descriptor layout.
- [Shared OAM resource `0872937C`](shared_resource_0872937c/full/) — three
  complete indexed-PNG OAM source views with native descriptor layout.
- [Shared OAM resource `08729460`](shared_resource_08729460/full/) — three
  complete indexed-PNG OAM source views with native descriptor layout.
- [Shared OAM resource `0872EE78`](shared_resource_0872ee78/full/) — four
  complete indexed-PNG OAM source views with native descriptor layout.
- [Shared OAM resource `08731B40`](shared_resource_08731b40/full/) — twenty
  complete indexed-PNG OAM source views with native descriptor layout.
- [Shared OAM resource `0873AE54`](shared_resource_0873ae54/full/) — two
  complete indexed-PNG OAM source views with native descriptor layout.
- [Shared OAM resource `0873AFC8`](shared_resource_0873afc8/full/) — one
  complete indexed-PNG OAM source view with native descriptor layout.
- [Shared OAM resource `0873CCB4`](shared_resource_0873ccb4/full/) — two
  complete indexed-PNG OAM source views with native descriptor layout.
- [Shared OAM resource `0873CEAC`](shared_resource_0873ceac/full/) — one
  complete indexed-PNG OAM source view with native descriptor layout.
- [Records-screen task icons](ui/records_minigame/shared/) — seven complete
  16-by-16 icons with their native palettes.

## Code-backed UI views

The following are actual static renderings produced from the exact runtime
tile, map, palette and priority inputs identified by the consuming assembly.
They are useful for seeing what a resource is before editing its native
sources.

| Routine / resource | View | Scope |
| --- | --- | --- |
| `func_080A2BA4` | [JP](ui/scene_080a2ba4/reference/jp/screen.png), [US](ui/scene_080a2ba4/reference/us/screen.png), [EU](ui/scene_080a2ba4/reference/eu/screen.png), [DE](ui/scene_080a2ba4/reference/de/screen.png) | Per-region 240-by-160 view; the palette is archive-owned and read-only. |
| `func_080AE7D0` | [scene](ui/scene_080ae7d0/reference/scene.png) | Two code-priority BG layers; common across all four regions. |
| `func_080B7164` | [scene](ui/scene_080b7164/reference/scene.png) | Two code-priority BG layers; common across all four regions. |
| `func_080BCFAC` | [scene](ui/scene_080bcfac/reference/scene.png) | Two code-priority BG layers; common across all four regions. |
| `func_080C160C` | [scene](ui/scene_080c160c/reference/scene.png) | Two code-priority BG layers; palette begins at BG bank 1. |
| `func_080B55D0` auxiliary view | [screen](ui/scene_080b55d0_aux/reference/screen.png) | Verified visible auxiliary layers only; not claimed as the full final screen. |
| `func_08054F40` | [beach base](ui/scene_08054f40_tiles/reference/screen.png) | Static BG3 base only; later dynamic layers are intentionally excluded. |
| `func_0805AB08` | [three-BG base](ui/scene_0805ab08_tiles/reference/screen.png) | Static BG1/BG2/BG3 initialization result; later state updates are excluded. |

## Native source versus reference

For a scene with an editable/reversible route, work from its `shared/`
`*.4bpp`, `*.tilemap`, and `*.png` palette files. A reference image may be
regenerated through the `gfx-ui-scene-*-preview` or
`gfx-ui-scene-*-reference` Make target listed in that scene's documentation.

Do not treat a linear `*.4bpp` image grid or a raw tilemap dump as a completed
sprite or background unless this index or the owning scene document explicitly
identifies a proven layout.
