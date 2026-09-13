#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Livestock_DeathConsequences_RickChastisesPlayer[] =
        "I thought you could\r\n"
        "do a better job than this!\r\n"
        "I believed in you...{Press}\p"
        "Just try harder from\r\n"
        "now on, OK!?{Press}";

    const char gText_FarmEvent_Livestock_DeathConsequences_RickWarnsAnimalsDependOnPlayer[] =
        "The animals' lives\r\n"
        "depend on you!{Press}\p"
        "You've got to take better\r\n"
        "care of them than this!{Press}";

    const char gText_FarmEvent_Livestock_DeathConsequences_CarterExplainsDeathIsInevitable[] =
        "I know they have to\r\n"
        "die sometime...\r\n"
        "Still...sob...sniffle...{Press}\p"
        "I hate when it happens!{Press}";

    const char gText_FarmEvent_Livestock_DeathConsequences_CarterEncouragesPlayer[] =
        "Don't get too upset, now.\r\n"
        "You did a good job of\r\n"
        "taking care of of it.{Press}";
};

void EventScript_FarmEvent_Livestock_DeathConsequences(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8;
    var_0 = CountAnimalsByLifeState(ANIMAL_KIND_COW, LIVESTOCK_LIFE_STATE_DIED_NATURALLY);
    var_1 = CountAnimalsByLifeState(ANIMAL_KIND_SHEEP, LIVESTOCK_LIFE_STATE_DIED_NATURALLY);
    var_2 = CountAnimalsByLifeState(ANIMAL_KIND_CHICKEN, LIVESTOCK_LIFE_STATE_DIED_NATURALLY);
    var_3 = var_0 + var_1 + var_2;
    var_4 = CountAnimalsByLifeState(ANIMAL_KIND_COW, LIVESTOCK_LIFE_STATE_DIED_FROM_NEGLECT);
    var_5 = CountAnimalsByLifeState(ANIMAL_KIND_SHEEP, LIVESTOCK_LIFE_STATE_DIED_FROM_NEGLECT);
    var_6 = CountAnimalsByLifeState(ANIMAL_KIND_CHICKEN, LIVESTOCK_LIFE_STATE_DIED_FROM_NEGLECT);
    var_7 = var_4 + var_5 + var_6;
    var_8 = var_3 + var_7;
    if (var_8 != 0)
    {
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(1095), Y(163));
        PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_SADNESS);
        SetEntityPosition(ENTITY_PLAYER, X(1095), Y(163), FACING_UP);
        PreparePlayerForScriptedAnimation();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityPosition(ENTITY_CARTER, X(1095), Y(140), FACING_DOWN);
        SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
        if (var_2 || var_6)
        {
            SetEntityPosition(ENTITY_RICK, X(1077), Y(163), FACING_UP);
            SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
        }
        if (var_0 || var_4 || var_1 || var_5)
        {
            SetEntityPosition(ENTITY_BARLEY, X(1115), Y(163), FACING_UP);
            SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        WaitFrames(30);
        if (var_7)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            ShowLivestockNeglectDeathSummary();
            TalkClose();
            if (var_6)
            {
                SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
                SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_RICK);
                TalkMessage(gText_FarmEvent_Livestock_DeathConsequences_RickChastisesPlayer);
                TalkClose();
                SetEntityFacing(ENTITY_RICK, FACING_UP);
                SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            }
            WaitFrames(30);
            if (var_4 || var_5)
            {
                SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
                SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FarmEvent_Livestock_DeathConsequences_RickWarnsAnimalsDependOnPlayer);
                TalkClose();
                SetEntityFacing(ENTITY_BARLEY, FACING_UP);
                SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            }
            RemoveLivestockDeadFromNeglect();
            AddNpcFriendship(CHARACTER_LILLIA, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_RICK, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_POPURI, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_BARLEY, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_MAY, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_SAIBARA, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_GRAY, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_DUKE, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_MANNA, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_BASIL, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_ANNA, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_MARY, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_THOMAS, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_HARRIS, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_ELLEN, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_STU, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_JEFF, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_SASHA, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_KAREN, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_DOCTOR, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_ELLI, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_CLIFF, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_DOUG, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_ANN, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_KAI, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_GOTZ, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_ZACK, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_WON, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_GOURMET, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_HARVEST_GODDESS, mary_negated_int(-3) * var_7);
            if (VarGet(VAR_VAN_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
            {
                AddNpcFriendship(CHARACTER_VAN, mary_negated_int(-3) * var_7);
            }
            if (VarGet(VAR_LOU_OR_RUBY_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
            {
                AddNpcFriendship(CHARACTER_LOU_OR_RUBY, mary_negated_int(-3) * var_7);
            }
            AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_STAID, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_NAPPY, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_BOLD, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_CHEF, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_AQUA, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_HOGGY, mary_negated_int(-3) * var_7);
            AddNpcFriendship(CHARACTER_TIMID, mary_negated_int(-3) * var_7);
            AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-300) * var_7);
            AddCharacterLove(CHARACTER_MARY, mary_negated_int(-300) * var_7);
            AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-300) * var_7);
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-300) * var_7);
            AddCharacterLove(CHARACTER_ANN, mary_negated_int(-300) * var_7);
            AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-300) * var_7);
        }
        if (var_3)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            ShowNaturalLivestockDeathSummary();
            TalkClose();
            if (var_2)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_RICK);
                TalkMessage(gText_FarmEvent_Livestock_DeathConsequences_CarterExplainsDeathIsInevitable);
                TalkClose();
            }
            WaitFrames(30);
            if (var_0 || var_1)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FarmEvent_Livestock_DeathConsequences_CarterEncouragesPlayer);
                TalkClose();
            }
            RemoveNaturallyDeadLivestock();
        }
        WaitFrames(30);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    CallScript(EventScript_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing);
}
