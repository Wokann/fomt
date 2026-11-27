#ifndef FARMING_TUTORIAL_MAP_HH
#define FARMING_TUTORIAL_MAP_HH

#include "world_map.hh"
#include "field.hh"

// The tutorial owns its 12 by 7 plots instead of reading saved farm plots.
// The inherited map methods handle other tutorial locations normally.
#pragma interface "farming_tutorial_map.hh"
struct FarmingTutorialMap : GameSceneWorldMap {
    FarmingTutorialMap();
    virtual void LoadTiles(HardwareDmaQueue & queue);
    virtual void LoadTilemaps();
    virtual void LoadTimeOfDayPalette(i32 period, u32 buffer_index);

    void DrawPlot(i32 tile_x, i32 tile_y, FieldPlot const & plot,
        FieldPlotRenderData const * render_data);
    // x/y must lie within the field. Redraw this plot and its valid vertical
    // neighbors, whose borders depend on the changed plot.
    void SetPlot(i32 x, i32 y, FieldPlot const & plot);

    Field<12, 7> field;
};


#endif // FARMING_TUTORIAL_MAP_HH
