#ifndef RECORD_PLAYER_HH
#define RECORD_PLAYER_HH

#include "prelude.h"

#include "item.hh"

struct RecordPlayer
{
    RecordPlayer();

    bool HasAlbum() const;
    u32 GetUnknown() const;
    ArticleStack RemoveAlbum();
    ArticleStack SetAlbum(Article const & album_article);

    /* +00 */ bool has_album : 1;
    /* +00 */ u32 album_id : 4;
};

#endif // RECORD_PLAYER_HH
