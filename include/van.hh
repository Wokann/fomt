#ifndef VAN_HH
#define VAN_HH

#include "npc.hh"

// Character 33 resolves to NPC-group +0x310, save-image +0x1FE4.
struct Van : public Npc
{
    Van(ActorLocation const & location);
    bool IsAlbumAvailable(u32 index) const;
    void MarkAlbumUnavailable(u32 index);
    bool UnlockNextAlbum();

    /* +14 */ u16 removed_albums;
    /* +16 */ u8 unlocked_album_count;
};


#endif // VAN_HH
