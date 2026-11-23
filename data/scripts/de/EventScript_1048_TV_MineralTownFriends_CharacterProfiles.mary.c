#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1048_TV_MineralTownFriends_CharacterProfiles.mary.h"

void EventScript_1048_TV_MineralTownFriends_CharacterProfiles(void)
{
    int var_0;
    TalkOpen();
    switch (VarGet(VAR_TV_MINERAL_TOWN_FRIENDS_PROFILE_INDEX))
    {
        case 0:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessageSlow(gText_TV_MineralTownFriends_Rick_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Rick_FamilySibling);
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Rick_FamilyMother);
            ClearTalkNameplate();
            ClearTalkPortrait();
            TalkMessageSlow(gText_TV_MineralTownFriends_Rick_FamilyFather);
            SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessageSlow(gText_TV_MineralTownFriends_Rick_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Rick_NextEpisodePreview);
            break;
        case 1:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == SEASON_SUMMER && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == DAY_03)
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Popuri_ProfileHeaderBirthdayShiftedForPlayerConflict);
            }
            else
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Popuri_ProfileHeaderDefaultBirthday);
            }
            SetTalkPortrait(TALK_PORTRAIT_RICK_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessageSlow(gText_TV_MineralTownFriends_Popuri_FamilySibling);
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Popuri_FamilyMother);
            ClearTalkNameplate();
            ClearTalkPortrait();
            TalkMessageSlow(gText_TV_MineralTownFriends_Popuri_FamilyFather);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Popuri_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Popuri_NextEpisodePreview);
            break;
        case 2:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Lillia_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Lillia_FamilyDaughter);
            SetTalkPortrait(TALK_PORTRAIT_RICK_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessageSlow(gText_TV_MineralTownFriends_Lillia_FamilySon);
            ClearTalkNameplate();
            ClearTalkPortrait();
            TalkMessage(gText_TV_MineralTownFriends_Lillia_FamilyHusband);
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Lillia_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_CLIFF_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CLIFF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Lillia_NextEpisodePreview);
            break;
        case 3:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CLIFF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Cliff_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_CLIFF_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_CLIFF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Cliff_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessageSlow(gText_TV_MineralTownFriends_Cliff_NextEpisodePreview);
            break;
        case 4:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessageSlow(gText_TV_MineralTownFriends_Zack_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_WON);
            TalkMessageSlow(gText_TV_MineralTownFriends_Zack_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessageSlow(gText_TV_MineralTownFriends_Zack_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessageSlow(gText_TV_MineralTownFriends_Zack_NextEpisodePreview);
            break;
        case 5:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessageSlow(gText_TV_MineralTownFriends_Doctor_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Doctor_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessageSlow(gText_TV_MineralTownFriends_Doctor_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Doctor_NextEpisodePreview);
            break;
        case 6:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STAID_SCARED);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Staid_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberNappy);
            SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberBold);
            SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberChef);
            SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberAqua);
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberHoggy);
            SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberTimid);
            SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Staid_HarvestSpriteFamilyOverview);
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Staid_NextEpisodePreview);
            break;
        case 7:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_SCARED);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Nappy_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberStaid);
            SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberBold);
            SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberChef);
            SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberAqua);
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberHoggy);
            SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberTimid);
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Nappy_HarvestSpriteFamilyOverview);
            SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Nappy_NextEpisodePreview);
            break;
        case 8:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BOLD_SCARED);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Bold_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_SharedBoldOrChefProfile_HarvestSpriteFamilyMemberStaid);
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_BoldProfile_HarvestSpriteFamilyMemberNappy);
            SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberChef);
            SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberAqua);
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberHoggy);
            SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberTimid);
            SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Bold_HarvestSpriteFamilyOverview);
            SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Bold_NextEpisodePreview);
            break;
        case 9:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CHEF_SCARED);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Chef_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_SharedBoldOrChefProfile_HarvestSpriteFamilyMemberStaid);
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberNappy);
            SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberBold);
            SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberAqua);
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberHoggy);
            SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberTimid);
            SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Chef_HarvestSpriteFamilyOverview);
            SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Chef_NextEpisodePreview);
            break;
        case 10:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_AQUA_SCARED);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Aqua_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberStaid);
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_SharedAquaHoggyOrTimidProfile_HarvestSpriteFamilyMemberNappy);
            SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberBold);
            SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberChef);
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberHoggy);
            SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberTimid);
            SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Aqua_HarvestSpriteFamilyOverview);
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Aqua_NextEpisodePreview);
            break;
        case 11:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_SCARED);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Hoggy_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberStaid);
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_SharedAquaHoggyOrTimidProfile_HarvestSpriteFamilyMemberNappy);
            SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberBold);
            SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberChef);
            SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberAqua);
            SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberTimid);
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Hoggy_HarvestSpriteFamilyOverview);
            SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Hoggy_NextEpisodePreview);
            break;
        case 12:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_TIMID_SCARED);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Timid_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_STAID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STAID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberStaid);
            SetTalkPortrait(TALK_PORTRAIT_NAPPY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_NAPPY);
            TalkMessageSlow(gText_TV_MineralTownFriends_SharedAquaHoggyOrTimidProfile_HarvestSpriteFamilyMemberNappy);
            SetTalkPortrait(TALK_PORTRAIT_BOLD_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BOLD);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberBold);
            SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CHEF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberChef);
            SetTalkPortrait(TALK_PORTRAIT_AQUA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_AQUA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberAqua);
            SetTalkPortrait(TALK_PORTRAIT_HOGGY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HOGGY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_HarvestSpriteFamilyMemberHoggy);
            SetTalkPortrait(TALK_PORTRAIT_TIMID_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_TIMID);
            TalkMessageSlow(gText_TV_MineralTownFriends_Timid_HarvestSpriteFamilyOverview);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Timid_NextEpisodePreview);
            break;
        case 13:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == SEASON_SPRING && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == DAY_08)
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_HarvestGoddess_ProfileHeaderBirthdayShiftedForPlayerConflict);
            }
            else
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_HarvestGoddess_ProfileHeaderDefaultBirthday);
            }
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessageSlow(gText_TV_MineralTownFriends_HarvestGoddess_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_GOURMET_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_GOURMET);
            TalkMessageSlow(gText_TV_MineralTownFriends_HarvestGoddess_NextEpisodePreview);
            break;
        case 14:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_GOURMET_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_GOURMET);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gourmet_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_GOURMET_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_GOURMET);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gourmet_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gourmet_NextEpisodePreview);
            break;
        case 15:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Ellen_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Ellen_FamilyGranddaughter);
            SetTalkPortrait(TALK_PORTRAIT_STU_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessageSlow(gText_TV_MineralTownFriends_Ellen_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Ellen_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Ellen_NextEpisodePreview);
            break;
        case 16:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == SEASON_SPRING && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == DAY_16)
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Elli_ProfileHeaderBirthdayShiftedForPlayerConflict);
            }
            else
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Elli_ProfileHeaderDefaultBirthday);
            }
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Elli_FamilyGrandmother);
            SetTalkPortrait(TALK_PORTRAIT_STU_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessageSlow(gText_TV_MineralTownFriends_Elli_FamilyYoungerBrother);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Elli_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_STU_CRYING);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessageSlow(gText_TV_MineralTownFriends_Elli_NextEpisodePreview);
            break;
        case 17:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessageSlow(gText_TV_MineralTownFriends_Stu_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Stu_FamilySibling);
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_TV_MineralTownFriends_Stu_FamilyGrandmother);
            SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessageSlow(gText_TV_MineralTownFriends_Stu_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Stu_NextEpisodePreview);
            break;
        case 18:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Jeff_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Jeff_FamilyWife);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Jeff_FamilyDaughter);
            SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Jeff_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Jeff_NextEpisodePreview);
            break;
        case 19:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == SEASON_FALL && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == DAY_15)
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Karen_ProfileHeaderBirthdayShiftedForPlayerConflict);
            }
            else
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Karen_ProfileHeaderDefaultBirthday);
            }
            SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Karen_FamilyFather);
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Karen_FamilyMother);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Karen_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Karen_NextEpisodePreview);
            break;
        case 20:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Sasha_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessageSlow(gText_TV_MineralTownFriends_Sasha_FamilyHusband);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_TV_MineralTownFriends_Sasha_FamilyDaughter);
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Sasha_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
#ifdef BUGFIX
            TalkMessageSlow(gText_TV_MineralTownFriends_Sasha_NextEpisodePreview);
#endif
            break;
        case 21:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessageSlow(gText_TV_MineralTownFriends_Doug_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_ANN_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
#ifdef BUGFIX
            TalkMessageSlow(gText_TV_MineralTownFriends_Doug_FamilyDaughter);
#endif
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessageSlow(gText_TV_MineralTownFriends_Doug_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Doug_NextEpisodePreview);
            break;
        case 22:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == SEASON_SUMMER && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == DAY_17)
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Ann_ProfileHeaderBirthdayShiftedForPlayerConflict);
            }
            else
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Ann_ProfileHeaderDefaultBirthday);
            }
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessageSlow(gText_TV_MineralTownFriends_Ann_FamilyFather);
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessageSlow(gText_TV_MineralTownFriends_Ann_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_KAPPA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAPPA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Ann_NextEpisodePreview);
            break;
        case 23:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAPPA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAPPA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Kappa_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessageSlow(gText_TV_MineralTownFriends_Kappa_NextEpisodePreview);
            break;
        case 24:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessageSlow(gText_TV_MineralTownFriends_Basil_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Basil_FamilyWife);
            SetTalkPortrait(TALK_PORTRAIT_MARY_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Basil_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessageSlow(gText_TV_MineralTownFriends_Basil_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Basil_NextEpisodePreview);
            break;
        case 25:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == SEASON_WINTER && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == DAY_20)
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Mary_ProfileHeaderBirthdayShiftedForPlayerConflict);
            }
            else
            {
                TalkMessageSlow(gText_TV_MineralTownFriends_Mary_ProfileHeaderDefaultBirthday);
            }
            SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessageSlow(gText_TV_MineralTownFriends_Mary_FamilyFather);
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Mary_FamilyMother);
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Mary_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Mary_NextEpisodePreview);
            break;
        case 26:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Anna_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessageSlow(gText_TV_MineralTownFriends_Anna_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_MARY_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Anna_FamilyDaughter);
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Anna_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_WON);
            TalkMessageSlow(gText_TV_MineralTownFriends_Anna_NextEpisodePreview);
            break;
        case 27:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_WON);
            TalkMessageSlow(gText_TV_MineralTownFriends_Won_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessageSlow(gText_TV_MineralTownFriends_Won_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_WON);
            TalkMessageSlow(gText_TV_MineralTownFriends_Won_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Won_NextEpisodePreview);
            break;
        case 28:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Thomas_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Thomas_FamilySon);
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Thomas_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Thomas_NextEpisodePreview);
            break;
        case 29:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Harris_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Harris_FamilyFather);
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessageSlow(gText_TV_MineralTownFriends_Harris_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessageSlow(gText_TV_MineralTownFriends_Harris_NextEpisodePreview);
            break;
        case 30:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessageSlow(gText_TV_MineralTownFriends_Duke_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Duke_FamilyWife);
            ClearTalkNameplate();
            ClearTalkPortrait();
            TalkMessageSlow(gText_TV_MineralTownFriends_Duke_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessageSlow(gText_TV_MineralTownFriends_Duke_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Duke_NextEpisodePreview);
            break;
        case 31:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Manna_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessageSlow(gText_TV_MineralTownFriends_Manna_BiographyPart01);
            ClearTalkNameplate();
            ClearTalkPortrait();
            TalkMessageSlow(gText_TV_MineralTownFriends_Manna_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Manna_BiographyPart03);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessageSlow(gText_TV_MineralTownFriends_Manna_NextEpisodePreview);
            break;
        case 32:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessageSlow(gText_TV_MineralTownFriends_Carter_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessageSlow(gText_TV_MineralTownFriends_Carter_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_KAI_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_KAI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Carter_NextEpisodePreview);
            break;
        case 33:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Kai_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAI);
            TalkMessageSlow(gText_TV_MineralTownFriends_Kai_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_GRAY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Kai_NextEpisodePreview);
            break;
        case 34:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_GRAY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gray_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SAIBARA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gray_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_GRAY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gray_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SAIBARA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gray_NextEpisodePreview);
            break;
        case 35:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SAIBARA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Saibara_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_GRAY_WEDDING);
            SetTalkNameplateCharacter(CHARACTER_GRAY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Saibara_FamilyGrandson);
            SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SAIBARA);
            TalkMessageSlow(gText_TV_MineralTownFriends_Saibara_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_GOTZ);
            TalkMessageSlow(gText_TV_MineralTownFriends_Saibara_NextEpisodePreview);
            break;
        case 36:
#ifdef BUGFIX
            // The following switch needs the channel input returned by this call.
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
#else
            TalkMessageSlow(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
#endif
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_GOTZ);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gotz_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_GOTZ);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gotz_BiographyPart01);
            SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Gotz_NextEpisodePreview);
            break;
        case 37:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MAY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessageSlow(gText_TV_MineralTownFriends_May_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessageSlow(gText_TV_MineralTownFriends_May_BiographyPart01);
            ClearTalkNameplate();
            ClearTalkPortrait();
            TalkMessageSlow(gText_TV_MineralTownFriends_May_BiographyPart02);
            SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessageSlow(gText_TV_MineralTownFriends_May_BiographyPart03);
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessageSlow(gText_TV_MineralTownFriends_May_NextEpisodePreview);
            break;
        case 38:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Barley_ProfileHeader);
            SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Barley_FamilyGranddaughter);
            ClearTalkNameplate();
            ClearTalkPortrait();
            TalkMessageSlow(gText_TV_MineralTownFriends_Barley_FamilyDaughter);
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessageSlow(gText_TV_MineralTownFriends_Barley_BiographyPart01);
            ClearTalkNameplate();
            ClearTalkPortrait();
            TalkMessageSlow(gText_TV_MineralTownFriends_Barley_NextEpisodePreview);
            break;
        case 39:
            var_0 = ShowTelevisionMessage(gText_TV_MineralTownFriends_Shared_AllCharacterProfileOpening);
            TalkClose();
            switch (var_0)
            {
                case TELEVISION_INPUT_UP_WEATHER:
                case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
                case TELEVISION_INPUT_RIGHT_NEWS:
                case TELEVISION_INPUT_LEFT_VARIETY:
                    VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
                    CallScript(EventScript_0540_TV_EntertainmentChannel);
                    break;
                case TELEVISION_INPUT_ADVANCE_TEXT:
                case TELEVISION_INPUT_TURN_OFF:
                    break;
                mary_dead_jump:
            }
            TalkOpen();
            TalkMessageSlow(gText_TV_MineralTownFriends_SeriesLoop_NextCycleTeaser);
            SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessageSlow(gText_TV_MineralTownFriends_SeriesLoop_NextEpisodePreview);
            break;
    }
    EndTelevisionProgram();
    TalkClose();
}
