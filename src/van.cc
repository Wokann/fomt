#include "van.hh"

Van::Van(ActorLocation const & location)
    : Npc(location)
{
    removed_albums = 0;
    unlocked_album_count = 0;
}

bool Van::IsAlbumAvailable(u32 index) const
{
    u32 mask = 1 << index;
    if (index < unlocked_album_count && (removed_albums & mask) == 0)
        return true;
    else
        return false;
}

void Van::MarkAlbumUnavailable(u32 index)
{
    u32 mask = 1 << index;
    u16 albums = removed_albums;
    albums |= mask;
    removed_albums = albums;
}

bool Van::UnlockNextAlbum()
{
    if (unlocked_album_count != 10)
    {
        ++unlocked_album_count;
        return true;
    }
    else
    {
        return false;
    }
}
