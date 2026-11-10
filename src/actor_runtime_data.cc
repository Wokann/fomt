#include "actor_runtime_data.hh"

Unk_Actor_0809BFE8::Unk_Actor_0809BFE8()
    : Actor(ActorLocation(Location(MAP_NONE, 0, 0), 0)), unk_08_0(100), unk_0C(0)
{
}

extern "C" unsigned int func_0809C060(Unk_Actor_0809BFE8 const & self)
{
    return self.unk_08_0;
}

extern "C" void func_0809C068(Unk_Actor_0809BFE8 & self, int arg_0)
{
    int val = self.unk_08_0 - arg_0;

    if (val < 0)
        val = 0;
    else if (val > 100)
        val = 100;

    self.unk_08_0 = val;
}

extern "C" void func_0809C098(Unk_Actor_0809BFE8 & self, u32 const &)
{
    self.unk_0C = 0;
}

extern "C" void func_0809C0A0(Unk_Actor_0809BFE8 & self, u32 const & value)
{
    self.unk_10 = value;
    self.unk_0C = 1;
}

extern "C" void func_0809C0AC(Unk_Actor_0809BFE8 & self, Unk_Actor_0809C0AC const & value)
{
    u32 const unk_04 = value.unk_04;

    self.unk_10 = value.unk_00;
    self.unk_14 = unk_04;
    self.unk_0C = 2;
}

extern "C" void func_0809C0BC(Unk_Actor_0809BFE8 & self, u32 const & value)
{
    self.unk_10 = value;
    self.unk_0C = 3;
}

extern "C" void func_0809C0C8(Unk_Actor_0809BFE8 & self, u32 const & value)
{
    self.unk_10 = value;
    self.unk_0C = 4;
}

extern "C" void ResetActorRuntimeState(Unk_Actor_0809BFE8 & self)
{
    ActorLocation const location(Location(MAP_NONE, 0, 0), 0);
    u32 unused;

    self.SetLocation(location);
    func_0809C098(self, unused);
    self.unk_08_0 = 100;
}
