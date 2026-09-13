#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_HarvestGoddess_ProposalResponse_AcceptsProposal[] =
        "Wenn du willst, heirate\r\n"
        "ich dich, {Player}.{Press}";

    const char gText_LoveEvent_HarvestGoddess_ProposalResponse_RejectsProposalWhenRequirementsUnmet[] =
        "Nee.{Press}";
};

void EventScript_LoveEvent_HarvestGoddess_ProposalResponse(void)
{
    if (GetEntityLocation(ENTITY_PLAYER) == MAP_MOTHERS_HILL_MIDDLE)
    {
        VarSet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
        switch (GetEntityFacing(ENTITY_PLAYER))
        {
            case FACING_UP:
                PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
                SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) - 16), FACING_DOWN);
                SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
                FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
                FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
                HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                SetEntityPosition(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) - 16), FACING_DOWN);
                FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
                break;
            case FACING_DOWN:
                PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
                SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 16), FACING_DOWN);
                SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
                FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
                FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
                HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                SetEntityPosition(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 16), FACING_UP);
                FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
                break;
            case FACING_LEFT:
                PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
                SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER) - 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
                SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
                FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
                FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
                HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                SetEntityPosition(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) - 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_RIGHT);
                FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
                break;
            case FACING_RIGHT:
                PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
                SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER) + 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
                SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
                FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
                FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
                HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                SetEntityPosition(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_LEFT);
                FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
                break;
        }
        SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_IDLE);
        WaitFrames(60);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        if (VarGet(VAR_YEAR) >= 5 && GetCharacterLove(CHARACTER_HARVEST_GODDESS) >= LOVE_HEART_RED_MIN && VarGet(VAR_HARVEST_GODDESS_MARRIAGE_BLESSING_RECEIVED) == TRUE && VarGet(VAR_HARVEST_GODDESS_CHOSEN_AS_FAVORITE_VALUE) == HIDDEN_MARRIAGE_CANDIDATE_HARVEST_GODDESS && VarGet(VAR_HARVEST_GODDESS_JEWEL_EXCHANGE_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ACHIEVEMENT_SHIPPED_EVERY_ITEM_KIND_STATE) == ACHIEVEMENT_EVENT_COMPLETED && VarGet(VAR_ACHIEVEMENT_CAUGHT_EVERY_FISH_SPECIES_STATE) == ACHIEVEMENT_EVENT_COMPLETED && VarGet(VAR_ACHIEVEMENT_COLLECTED_EVERY_SPRING_MINE_ITEM_STATE) == ACHIEVEMENT_EVENT_COMPLETED && VarGet(VAR_ACHIEVEMENT_COLLECTED_EVERY_LAKE_MINE_ITEM_STATE) == ACHIEVEMENT_EVENT_COMPLETED && VarGet(VAR_TV_SHOPPING_LARGE_BED_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_COMPLETED)
        {
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            TalkMessage(gText_LoveEvent_HarvestGoddess_ProposalResponse_AcceptsProposal);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
            AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
            ClearPlayerHeldTool();
            VarSet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
            TalkMessage(gText_LoveEvent_HarvestGoddess_ProposalResponse_RejectsProposalWhenRequirementsUnmet);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
            VarSet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        }
        WaitFrames(60);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_HARVEST_GODDESS)), Y(GetEntityY(ENTITY_HARVEST_GODDESS) + 2), FACING_DOWN);
        SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
        HideEntity(ENTITY_HARVEST_GODDESS);
        WaitFrames(30);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    }
}
