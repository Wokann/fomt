#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Doctor_BlocksClinicUpstairsAccess[] =
        "You can't go upstairs.{Press}";
};

void EventScript_NPCEvent_Doctor_BlocksClinicUpstairsAccess(void)
{
    int var_0;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        if (GetNpcFriendship(CHARACTER_DOCTOR) <= 100)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                var_0 = FALSE;
            }
            else
            {
                var_0 = TRUE;
            }
        }
        if (var_0 == TRUE)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_MINERAL_CLINIC_2F, X(24), Y(64));
            SetEntityPosition(ENTITY_PLAYER, X(24), Y(64), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_NPCEvent_Doctor_BlocksClinicUpstairsAccess);
            TalkClose();
            MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}
