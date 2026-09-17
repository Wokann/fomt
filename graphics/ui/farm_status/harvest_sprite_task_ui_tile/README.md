# Farm Status Harvest Sprite task UI tile

`shared/harvest_sprite_task_ui_tile.png` is one complete 8-by-8 indexed 4bpp
OBJ image with its own sixteen-colour BGR555 palette.  Unlike the surrounding
raw UI tiles, this does not need a tilemap or a multi-piece OAM layout: the
retail initializer uploads exactly its sole tile to `0x060100A0` and its
adjacent palette record to `0x05000220`.

The upload pair is `gUnk_08750C4C` / `gUnk_08750C6C`.  It is shared byte for
byte by all four retail FoMT ROMs:

| Region | Tile offset | Palette offset |
| --- | ---: | ---: |
| JP | `0x4D6BF8` | `0x4D6C18` |
| US | `0x750C4C` | `0x750C6C` |
| EU | `0x750CA8` | `0x750CC8` |
| DE | `0x4D8168` | `0x4D8188` |

`func_080645F0` and `func_0806644C` upload this pair while constructing the
Harvest Sprite task/experience menu family.  The PNG is therefore an authored
source for the complete physical UI tile, not a reference montage or a
JSON-controlled layout.

```console
make gfx-farm-status-task-ui-tile-all
```

The command regenerates 4bpp and BGR555 outputs for every region and verifies
both ranges against JP, US, EU, and DE.
