#include "npc_collection.hh"

static inline ActorLocation InitialNpcLocation(Location const & position)
{
    return ActorLocation(position, FACING_DOWN);
}

NpcCollection::NpcCollection()
    : unk_00_0(0), unk_00_6(0), unk_01_5(0), unk_02_5(false),
      unk_02_6(0), has_child(false), unk_03_2(0),
      unk_2C(0), unk_2D_0(0), unk_2D_2(0),
      lillia(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      rick(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      popuri(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      barley(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      may(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      saibara(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      gray(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      duke(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      manna(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      basil(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      anna(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      mary(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      thomas(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      harris(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      ellen(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      stu(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      jeff(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      sasha(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      karen(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      doctor(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      elli(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      carter(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      cliff(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      doug(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      ann(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      kai(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      gotz(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      zack(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      won(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      gourmet(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      harvest_goddess(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      kappa(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      van(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      lou(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      staid(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      nappy(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      bold(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      chef(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      aqua(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      hoggy(InitialNpcLocation(Location(MAP_NONE, 0, 0))),
      timid(InitialNpcLocation(Location(MAP_NONE, 0, 0)))
{
    days_since_pregnancy_event = 0;
    unk_474 = 0;
    // The remaining state bits, child walking bit and object padding are not cleared.
}
