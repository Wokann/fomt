#include "record_player.hh"

// Album 1 through Album 15 select audio sequence IDs 18 through 32.
static u8 const sRecordPlayerAlbumAudioSequenceIds[] = {
    AUDIO_RECORD_SPRING_SONG,
    AUDIO_RECORD_TOWN_SPIRIT,
    AUDIO_RECORD_FLOWER_BUD_FALL,
    AUDIO_RECORD_64_MEMORIES,
    AUDIO_RECORD_MARINE_JAZZ,
    AUDIO_RECORD_BUTTERFLY,
    AUDIO_RECORD_SUMMER_MEMORIES,
    AUDIO_RECORD_AUTUMN_JOY,
    AUDIO_RECORD_QUIET_WINTER,
    AUDIO_RECORD_GRIFFIN_BLUE,
    AUDIO_RECORD_ALBUM_11,
    AUDIO_RECORD_ALBUM_12,
    AUDIO_RECORD_ALBUM_13,
    AUDIO_RECORD_ALBUM_14,
    AUDIO_RECORD_ALBUM_15,
};

RecordPlayer::RecordPlayer()
{
    has_album = false;
    album_id = 0;
}

bool RecordPlayer::HasAlbum() const
{
    return has_album;
}

u32 RecordPlayer::GetUnknown() const
{
    if (!HasAlbum())
        return 199;

    return sRecordPlayerAlbumAudioSequenceIds[album_id];
}

ArticleStack RecordPlayer::RemoveAlbum()
{
    if (!HasAlbum())
        return ArticleStack();

    has_album = false;

    return ArticleStack(Article(ITEM_ARTICLE_ALBUM_1 + album_id), 1);
}

ArticleStack RecordPlayer::SetAlbum(Article const & album_article)
{
    fu8 old_album_id;

    switch (album_article.GetId())
    {
        case ITEM_ARTICLE_ALBUM_1 ... ITEM_ARTICLE_ALBUM_15:
            has_album = true;
            old_album_id = album_id;
            album_id = album_article.GetId() - ITEM_ARTICLE_ALBUM_1;

            return ArticleStack(Article(old_album_id + ITEM_ARTICLE_ALBUM_1), 1);

        default:
            return ArticleStack();
    }
}
