#include "world_furniture.hh"
#include "game_state.hh"

void GameSceneWorldPrefix::LightFireplaceAtLocation(MaryMapId map)
{
    switch (map) {
    case MAP_FARMHOUSE:
        if (!save->farm.farm_house.IsFireplaceLighted())
            save->farm.farm_house.LightFireplace();
        break;
    case MAP_MOUNTAIN_COTTAGE:
        save->unk_31 = true;
        break;
    case MAP_TOWN_COTTAGE:
        save->unk_32 = true;
        break;
    default:
        return;
    }
    if (vfunc_14() == map) {
        unk_1060 = 1;
        fireplace_sprite = new GameSceneIndexedSprite(vfunc_60(), 2, this,
            2, 0x1B, false);
    }
}

void GameSceneWorldPrefix::SetVaseArticleId(MaryItemArticleId article)
{
    save->farm.farm_house.SetVaseArticleId(article);
    RefreshWorldVase(*this);
}
