#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestSpriteTeaParty_ChefAsksIfEveryoneIsReady[] =
        "Is everybody ready? {Press}";

    const char gText_FestivalEvent_HarvestSpriteTeaParty_SpritesConfirmTheyAreReady[] =
        "Yes. {Press}";

    const char gText_FestivalEvent_HarvestSpriteTeaParty_ChefStartsTeaParty[] =
        "Alright, let the \r\n"
        "Tea Party begin budum!{Press}";

    const char gText_FestivalEvent_HarvestSpriteTeaParty_StaidAnnouncesTeaPartyEnded[] =
        "The Tea Party is \r\n"
        "over, budum. {Press}";

    const char gText_FestivalEvent_HarvestSpriteTeaParty_BoldCallsPlayerTheirGuest[] =
        "You are our guest, \r\n"
        "{Player}. {Press}";

    const char gText_FestivalEvent_HarvestSpriteTeaParty_AquaPresentsRelaxTeaLeaves[] =
        "So, we have a present \r\n"
        "for you. {Press}";

    const char gText_FestivalEvent_HarvestSpriteTeaParty_TimidInvitesPlayerNextYear[] =
        "Come again next year, budum!{Press}";
};

void EventScript_FestivalEvent_HarvestSpriteTeaParty(void)
{
    ChangeMap(MAP_HARVEST_SPRITES_HUT, X(172), Y(123));
    SetEntityPosition(ENTITY_PLAYER, X(172), Y(123), FACING_DOWN);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_STAID, X(147), Y(mary_negated_int(-8)), FACING_LEFT);
    SetEntityAnim(ENTITY_STAID, ANIMATION_STAID_TEA_PARTY);
    SetEntityPosition(ENTITY_NAPPY, X(107), Y(mary_negated_int(-25)), FACING_DOWN);
    SetEntityAnim(ENTITY_NAPPY, ANIMATION_NAPPY_TEA_PARTY);
    SetEntityPosition(ENTITY_BOLD, X(128), Y(6), FACING_UP);
    SetEntityAnim(ENTITY_BOLD, ANIMATION_BOLD_TEA_PARTY);
    SetEntityPosition(ENTITY_CHEF, X(93), Y(mary_negated_int(-8)), FACING_RIGHT);
    SetEntityAnim(ENTITY_CHEF, ANIMATION_CHEF_TEA_PARTY);
    SetEntityPosition(ENTITY_AQUA, X(112), Y(6), FACING_UP);
    SetEntityAnim(ENTITY_AQUA, ANIMATION_AQUA_TEA_PARTY);
    SetEntityPosition(ENTITY_HOGGY, X(119), Y(mary_negated_int(-25)), FACING_DOWN);
    SetEntityAnim(ENTITY_HOGGY, ANIMATION_HOGGY_TEA_PARTY);
    SetEntityPosition(ENTITY_TIMID, X(131), Y(mary_negated_int(-25)), FACING_DOWN);
    SetEntityAnim(ENTITY_TIMID, ANIMATION_TIMID_TEA_PARTY);
    SetEntitySpritePriority(ENTITY_HOGGY, ENTITY_SPRITE_PRIORITY_HIGH);
    SetEntitySpritePriority(ENTITY_TIMID, ENTITY_SPRITE_PRIORITY_HIGH);
    SetEntitySpritePriority(ENTITY_NAPPY, ENTITY_SPRITE_PRIORITY_HIGH);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CHEF);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_ChefAsksIfEveryoneIsReady);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STAID);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_SpritesConfirmTheyAreReady);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_NAPPY);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_SpritesConfirmTheyAreReady);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BOLD);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_SpritesConfirmTheyAreReady);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_AQUA);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_SpritesConfirmTheyAreReady);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_HOGGY);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_SpritesConfirmTheyAreReady);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_TIMID);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_SpritesConfirmTheyAreReady);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CHEF);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_ChefStartsTeaParty);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_DRINK);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_DRINK);
    ClearPlayerHeldItem();
    WaitFrames(72);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntitySpritePriority(ENTITY_HOGGY, ENTITY_SPRITE_PRIORITY_LOW);
    SetEntitySpritePriority(ENTITY_TIMID, ENTITY_SPRITE_PRIORITY_LOW);
    SetEntitySpritePriority(ENTITY_NAPPY, ENTITY_SPRITE_PRIORITY_LOW);
    ChangeMap(MAP_HARVEST_SPRITES_HUT, X(121), Y(165));
    SetEntityPosition(ENTITY_PLAYER, X(121), Y(165), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_STAID, X(91), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_STAID, ANIMATION_STAID_IDLE);
    SetEntityPosition(ENTITY_NAPPY, X(101), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_NAPPY, ANIMATION_NAPPY_IDLE);
    SetEntityPosition(ENTITY_BOLD, X(111), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_BOLD, ANIMATION_BOLD_IDLE);
    SetEntityPosition(ENTITY_CHEF, X(121), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_CHEF, ANIMATION_CHEF_IDLE);
    SetEntityPosition(ENTITY_AQUA, X(131), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_AQUA, ANIMATION_AQUA_IDLE);
    SetEntityPosition(ENTITY_HOGGY, X(141), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_HOGGY, ANIMATION_HOGGY_IDLE);
    SetEntityPosition(ENTITY_TIMID, X(151), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_TIMID, ANIMATION_TIMID_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STAID);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_StaidAnnouncesTeaPartyEnded);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BOLD);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_BoldCallsPlayerTheirGuest);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_AQUA);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_AquaPresentsRelaxTeaLeaves);
    TalkClose();
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldFood(ITEM_FOOD_RELAX_TEA_LEAVES);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_TIMID);
    TalkMessage(gText_FestivalEvent_HarvestSpriteTeaParty_TimidInvitesPlayerNextYear);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    AddNpcFriendship(CHARACTER_STAID, 10);
    AddNpcFriendship(CHARACTER_NAPPY, 10);
    AddNpcFriendship(CHARACTER_BOLD, 10);
    AddNpcFriendship(CHARACTER_CHEF, 10);
    AddNpcFriendship(CHARACTER_AQUA, 10);
    AddNpcFriendship(CHARACTER_HOGGY, 10);
    AddNpcFriendship(CHARACTER_TIMID, 10);
    MarkNpcSpokenTo(CHARACTER_STAID);
    MarkNpcSpokenTo(CHARACTER_NAPPY);
    MarkNpcSpokenTo(CHARACTER_BOLD);
    MarkNpcSpokenTo(CHARACTER_CHEF);
    MarkNpcSpokenTo(CHARACTER_AQUA);
    MarkNpcSpokenTo(CHARACTER_HOGGY);
    MarkNpcSpokenTo(CHARACTER_TIMID);
    ChangeMap(MAP_BEHIND_CHURCH, X(372), Y(312));
    SetEntityPosition(ENTITY_PLAYER, X(372), Y(312), FACING_DOWN);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetGameTime(18, 1);
    VarSet(VAR_HARVEST_SPRITE_TEA_PARTY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
