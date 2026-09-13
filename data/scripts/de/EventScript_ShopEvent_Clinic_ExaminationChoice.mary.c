#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_ShopEvent_Clinic_ExaminationChoice_Table[] =
        "Tisch{Press}";

    const char gText_ShopEvent_Clinic_ExaminationChoice_ExaminationPrice[] =
        "Untersuchung 10G.";

    const char gText_ShopEvent_Clinic_ExaminationChoice_PleaseExamineMe[] =
        "Bitte untersuchen.";

    const char gText_ShopEvent_Clinic_ExaminationChoice_NoThanks[] =
        "Nein, danke.";

    const char gText_ShopEvent_Clinic_ExaminationChoice_ImGoingToBeginTheExamination[] =
        "Ich fange jetzt mit der \r\n"
        "Untersuchung an.{Press}\p"
        "Ok, Mund aufmachen\r\n"
        "und AHHH sagen...{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_HmmCouldItBeNoVery[] =
        "...Ist das möglich? Nein.{Press}\r\n"
        "...Äußerst interessant...{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_OKTheExamIsOverHeres[] =
        "Ok, Untersuchung beendet!\r\n"
        "Hier der Bericht.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaAtLeast70Percent_FatigueBelow50[] =
        "Deine Ausdauer ist gut,\r\n"
        "du hast keinen \r\n"
        "Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaAtLeast70Percent_Fatigue50To69[] =
        "Deine Ausdauer ist gut, aber\r\n"
        "da ist etwas Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaAtLeast70Percent_Fatigue70To89[] =
        "Deine Ausdauer ist gut, aber\r\n"
        "der Energieverlust ist hoch.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaAtLeast70Percent_FatigueAtLeast90[] =
        "Deine Ausdauer ist gut, aber\r\n"
        "dein Energieverlust ist \r\n"
        "viel zu hoch. Du könntest {Press}\r\n"
        "jederzeit zusammenbrechen.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina50To69Percent_FatigueBelow50[] =
        "Deine Ausdauer ist etwas\r\n"
        "niedrig, aber du hast keinen\r\n"
        "Energieverlust, also sollte{Press}\r\n"
        "es kein Problem sein.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina50To69Percent_Fatigue50To69[] =
        "Deine Ausdauer ist etwas\r\n"
        "niedrig und du hast \r\n"
        "etwas Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina50To69Percent_Fatigue70To89[] =
        "Deine Ausdauer ist etwas\r\n"
        "niedrig, aber schlimmer ist \r\n"
        "dein Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina50To69Percent_FatigueAtLeast90[] =
        "Deine Ausdauer ist etwas\r\n"
        "niedrig und dein Energie-\r\n"
        "verlust ist sehr hoch. Du {Press}\r\n"
        "könntest jederzeit \r\n"
        "zusammenbrechen.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina20To49Percent_FatigueBelow50[] =
        "Deine Ausdauer ist  \r\n"
        "bedeutend reduziert, aber \r\n"
        "du hast keinen{Press}\r\n"
        "Energieverlust, also sollte{Press}\r\n"
        "es kein Problem sein.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina20To49Percent_Fatigue50To69[] =
        "Deine Ausdauer ist  \r\n"
        "bedeutend reduziert,\r\n"
        "und du hast {Press}\r\n"
        "etwas Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina20To49Percent_Fatigue70To89[] =
        "Deine Ausdauer ist  \r\n"
        "bedeutend reduziert, aber \r\n"
        "dein Energieverlust {Press}\r\n"
        "macht mir mehr Sorgen.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina20To49Percent_FatigueAtLeast90[] =
        "Deine Ausdauer ist  \r\n"
        "bedeutend reduziert und \r\n"
        "dein Energieverlust{Press}\r\n"
        "ist sehr hoch. Du {Press}\r\n"
        "könntest jederzeit \r\n"
        "zusammenbrechen.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina5To19Percent_FatigueBelow50[] =
        "Deine Ausdauer ist sehr\r\n"
        "niedrig, aber du hast keinen\r\n"
        "Energieverlust, also sollte{Press}\r\n"
        "es kein Problem sein.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina5To19Percent_Fatigue50To69[] =
        "Deine Ausdauer ist sehr\r\n"
        "niedrig und du hast \r\n"
        "etwas Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina5To19Percent_Fatigue70To89[] =
        "Deine Ausdauer ist sehr\r\n"
        "niedrig und du hast \r\n"
        "hohen Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina5To19Percent_FatigueAtLeast90[] =
        "Deine Ausdauer ist sehr\r\n"
        "niedrig und dein Energie-\r\n"
        "verlust ist sehr hoch. Du {Press}\r\n"
        "könntest jederzeit \r\n"
        "zusammenbrechen.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaBelow5Percent_FatigueBelow50[] =
        "Deine Ausdauer ist \r\n"
        "praktisch gleich null,  \r\n"
        "aber du hast keinen{Press}\r\n"
        "Energieverlust, also sollte{Press}\r\n"
        "es kein Problem sein.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaBelow5Percent_Fatigue50To69[] =
        "Deine Ausdauer ist \r\n"
        "praktisch gleich null, \r\n"
        "und du hast {Press}\r\n"
        "etwas Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaBelow5Percent_Fatigue70To89[] =
        "Deine Ausdauer ist \r\n"
        "praktisch gleich null, \r\n"
        "und du hast {Press}\r\n"
        "hohen Energieverlust.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaBelow5Percent_FatigueAtLeast90[] =
        "Deine Ausdauer ist \r\n"
        "praktisch gleich null, \r\n"
        "dein Energieverlust{Press}\r\n"
        "verlust ist sehr hoch. Du {Press}\r\n"
        "könntest jederzeit \r\n"
        "zusammenbrechen.{Press}\p";

    const char gText_ShopEvent_Clinic_ExaminationChoice_YouLookPerfectlyHealthyToMe[] =
        "Du siehst kerngesund\r\n"
        "aus, finde ich!\r\n"
        "{Press}";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_TurbojoltOrRest[] =
        "Eine Flasche Turboschub\r\n"
        "wäre am Besten, aber eine\r\n"
        "gute Mütze Schlaf und viel{Press}\r\n"
        "gutes Essen tun es auch!{Press}";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_TurbojoltOrFullDayRest[] =
        "Du solltest eine Flasche\r\n"
        "Turboschub nehmen, aber\r\n"
        "wenn du dir das nicht{Press}\p"
        "leisten kannst, dann geh\r\n"
        "heim und ruh dich aus.{Press}";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_BodigizerOrRest[] =
        "Eine Flasche Bodigizer\r\n"
        "wäre am Besten, aber eine\r\n"
        "gute Mütze Schlaf und viel{Press}\r\n"
        "gutes Essen tun es auch!{Press}";

    const char gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_BodigizerAndTurbojoltOrFullDayRest[] =
        "Du solltest eine Flasche\r\n"
        "Bodigizer und einen\r\n"
        "Turboschub nehmen, aber{Press}\p"
        "wenn du es dir nicht leisten\r\n"
        "kannst, geh nach Hause\r\n"
        "und nimm diesen Tag frei.{Press}";

    const char gText_ShopEvent_Clinic_ExaminationChoice_TooBadButYouDontHave[] =
        "Zu schade, aber du\r\n"
        "hast nicht genug Geld.{Press}";

    const char gText_ShopEvent_Clinic_ExaminationChoice_YourePositiveNowWellIfYou[] =
        "Du bist ok?\r\n"
        "Hm, wenn du denkst, dass\r\n"
        "du in Ordnung bist, gibt {Press}\r\n"
        "es keinen Grund zur Sorge.{Press}\p"
        "Pass jetzt gut auf dich\r\n"
        "auf, ok?{Press}";
};

void EventScript_ShopEvent_Clinic_ExaminationChoice(void)
{
    int var_0, var_1;
    if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_KAREN_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_POPURI_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_MARY_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ELLI_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_KAREN_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_KAREN_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_KAREN_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_REFRIGERATOR_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_SHELF_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_KITCHEN_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_CARPET_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_LARGE_BED_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_KNIFE_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_FRYING_PAN_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_POT_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_MIXER_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_WHISK_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_ROLLING_PIN_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_OVEN_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_SEASONING_SET_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_POWER_BERRY_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_MIRROR_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_TV_SHOPPING_CLOCK_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_IN_PROGRESS || VarGet(VAR_POPURI_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_BARLEY_FOAL_OFFER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_BARLEY_HORSE_YEAR_EVALUATION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_BARLEY_REPLACEMENT_FOAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_001) == 1 || VarGet(VAR_UNKNOWN_002) == 1 || VarGet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_PLAYER_COLLAPSE_RECOVERY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_CONFRONTS_KAI_ABOUT_POPURI_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_ASKS_KAI_FOR_NECKLACE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_PLANS_LILLIA_BIRTHDAY_GIFT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_BARLEY_AND_DOUG_DISCUSS_JOANNAS_PHONE_CALL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_003) == 1 || VarGet(VAR_UNKNOWN_004) == 1 || VarGet(VAR_MAY_PHONE_CALL_WITH_JOANNA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_SAIBARA_VISITS_ELLEN_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_SAIBARA_VISITS_ELLEN_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_GRAY_AND_KAI_FRIENDSHIP_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_005) == 1 || VarGet(VAR_DUKE_GRAPE_HARVEST_INVITATION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_CLIFF_WINERY_EMPLOYMENT_STATUS) == CLIFF_WINERY_TEMPORARY_HARVEST_WORKER || VarGet(VAR_DUKE_AND_MANNA_MISSING_JUICE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_BASIL_LETTER_ADVICE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_BASIL_PUBLISHING_AWARD_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANNA_COOKING_LESSONS_INVITATION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANNA_COOKING_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_AND_GRAY_BOOK_AND_HEALTH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_MARRIED_LIFE_AND_WRITING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_FARM_INTRODUCTION_AND_SHIPPING_TUTORIAL_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_THOMAS_RANDOM_ITEM_REQUEST_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE) == THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_CHECKING_ITEM || VarGet(VAR_HARRIS_AJA_LETTER_ADVICE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARRIS_AJA_LETTER_REJECTION_FOLLOWUP_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLEN_WHITE_FLOWER_LEGEND_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLEN_WHITE_FLOWER_DISCOVERY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLEN_KNITS_STOCKING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_006) == 1 || VarGet(VAR_ELLI_AND_STU_PLAY_TOGETHER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WON_OFFERS_TO_BUY_JEFFS_PAINTING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_AND_DUKE_DRINKING_CONTEST_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WON_AND_KAREN_FIRST_MEETING_AT_ZACKS_HOUSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_TREATS_STUS_COLD_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_CARTER_CHURCH_BACK_DOOR_MUSHROOM_SECRET_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_PLAYER_SNEAKS_PAST_SLEEPING_CARTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_CLIFF_COLLAPSES_IN_SNOW_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_CLIFF_LEAVES_MINERAL_TOWN_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_GIVES_DOUG_BIRTHDAY_PRESENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_AND_CLIFF_SIBLING_COMPARISON_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_BRINGS_CUSTOMERS_TO_KAIS_BEACH_CAFE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAI_RETURNS_FOR_SUMMER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAI_RETURN_GREETING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAI_LEAVES_AFTER_SUMMER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_GOTZ_LOSES_MOTIVATION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_GOTZ_REGAINS_MOTIVATION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_GOTZ_AND_HARRIS_PATROL_DISCUSSION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ZACK_VISITS_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ZACK_GIVES_FISHING_ROD_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ZACK_CONGRATULATES_CATCHING_EVERY_FISH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WON_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WON_APPLE_CHALLENGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WON_VASE_PURCHASE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_VAN_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_008) == 1 || VarGet(VAR_UNKNOWN_009) == 1 || VarGet(VAR_LOU_OR_RUBY_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_010) == 1 || VarGet(VAR_UNKNOWN_011) == 1 || VarGet(VAR_HARVEST_SPRITE_TEA_PARTY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_FIRST_OFFERING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_TEN_OFFERINGS_MATCHMAKING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_TEN_OFFERINGS_POWER_BERRY_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_JEWEL_EXCHANGE_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAPPA_FIRST_CUCUMBER_OFFERING_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_COLLECT_POWER_BERRY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAPPA_MYSTIC_BERRY_REWARD_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAPPA_DAILY_APPEARANCE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_SLOT_334) == 1 || VarGet(VAR_UNKNOWN_014) == 1 || VarGet(VAR_UNKNOWN_015) == 1 || VarGet(VAR_GOLDEN_LUMBER_ANGER_DIALOGUE_VARIANT_STATE) == GOLDEN_LUMBER_ANGER_DIALOGUE_FIRST_SEQUENCE || VarGet(VAR_GOLDEN_LUMBER_ANGER_EVENT_TODAY_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_JEWELS_OF_TRUTH_EXCHANGE_RETRY_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_JEWELS_OF_TRUTH_REWARD_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_SHOOTING_STAR_WISH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_017) == 1 || VarGet(VAR_ACHIEVEMENT_WALKED_10000_STEPS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_WALKED_100000_STEPS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_WALKED_1000000_STEPS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_WALKED_10000000_STEPS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_WALKED_100000000_STEPS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_WALKED_1000000000_STEPS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_SHIPPED_10000_ITEMS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_SHIPPED_100000_ITEMS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_SHIPPED_1000000_ITEMS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_SHIPPED_10000000_ITEMS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_SHIPPED_100000000_ITEMS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_SHIPPED_1000000000_ITEMS_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_SHIPPED_EVERY_ITEM_KIND_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_CAUGHT_10000_FISH_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_CAUGHT_100000_FISH_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_CAUGHT_1000000_FISH_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_CAUGHT_10000000_FISH_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_CAUGHT_100000000_FISH_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_CAUGHT_1000000000_FISH_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_CAUGHT_EVERY_FISH_SPECIES_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_REACHED_SPRING_MINE_B100_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_REACHED_SPRING_MINE_B200_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_REACHED_SPRING_MINE_BOTTOM_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_COLLECTED_EVERY_SPRING_MINE_ITEM_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_ACHIEVEMENT_COLLECTED_EVERY_LAKE_MINE_ITEM_STATE) == ACHIEVEMENT_EVENT_PRESENTING || VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_FIFTIETH_ANNIVERSARY_GIFT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_018) == 1 || VarGet(VAR_UNKNOWN_019) == 1 || VarGet(VAR_UNKNOWN_020) == 1 || VarGet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_021) == 1 || VarGet(VAR_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_COOKING_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_COOKING_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_COOKING_FESTIVAL_COMPLETED) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_FRISBEE_TOURNAMENT_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_BEACH_DAY_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_CHICKEN_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_CHICKEN_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_COW_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_COW_FESTIVAL_SESSION_STATE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_FIREWORKS_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_MUSIC_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_MUSIC_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_HARVEST_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_HARVEST_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_SHEEP_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_IN_PROGRESS || VarGet(VAR_SHEEP_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_PUMPKIN_FESTIVAL_MAY_TREAT_VISIT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_PUMPKIN_FESTIVAL_STU_TREAT_VISIT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_PUMPKIN_FESTIVAL_POPURI_TREAT_VISIT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_PUMPKIN_FESTIVAL_FARMHOUSE_SPOUSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WINTER_THANKSGIVING_POPURI_VISIT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WINTER_THANKSGIVING_ANN_VISIT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WINTER_THANKSGIVING_ELLI_VISIT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WINTER_THANKSGIVING_KAREN_VISIT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WINTER_THANKSGIVING_MARY_VISIT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_UNKNOWN_SLOT_449) == 1 || VarGet(VAR_STARRY_NIGHT_POPURI_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_STARRY_NIGHT_ANN_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_STARRY_NIGHT_ELLI_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_STARRY_NIGHT_KAREN_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_STARRY_NIGHT_MARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_STARRY_NIGHT_FARMHOUSE_SPOUSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_THOMAS_STOCKING_DELIVERY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_NEW_YEAR_SUNRISE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        TalkOpen();
        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Table);
        TalkClose();
        return;
    }
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (GetEntityLocation(ENTITY_DOCTOR) == MAP_MINERAL_CLINIC_1F && VarGet(VAR_DAY_OF_WEEK) != DAY_OF_WEEK_WEDNESDAY)
        {
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            var_0 = TalkPromptChoice2(gText_ShopEvent_Clinic_ExaminationChoice_ExaminationPrice, gText_ShopEvent_Clinic_ExaminationChoice_PleaseExamineMe, gText_ShopEvent_Clinic_ExaminationChoice_NoThanks);
            switch (var_0)
            {
                case PROMPT_CHOICE_OPTION_1:
                    if (GetMoney() >= 10)
                    {
                        SubtractMoney(10);
                        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_ImGoingToBeginTheExamination);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_SLOW);
                        TalkOpen();
                        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_HmmCouldItBeNoVery);
                        TalkClose();
                        WaitFrames(30);
                        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_SLOW);
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
                        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_OKTheExamIsOverHeres);
                        if (VarGet(VAR_PLAYER_STAMINA) >= VarGet(VAR_PLAYER_MAX_STAMINA) * 70 / 100)
                        {
                            if (VarGet(VAR_PLAYER_FATIGUE) <= 49)
                            {
                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaAtLeast70Percent_FatigueBelow50);
                                var_1 = CLINIC_EXAM_RESULT_HEALTHY;
                            }
                            else
                            {
                                if (VarGet(VAR_PLAYER_FATIGUE) <= 69)
                                {
                                    TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaAtLeast70Percent_Fatigue50To69);
                                    var_1 = CLINIC_EXAM_RESULT_MODERATE_STAMINA_OR_FATIGUE;
                                }
                                else
                                {
                                    if (VarGet(VAR_PLAYER_FATIGUE) <= 89)
                                    {
                                        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaAtLeast70Percent_Fatigue70To89);
                                        var_1 = CLINIC_EXAM_RESULT_HIGH_FATIGUE;
                                    }
                                    else
                                    {
                                        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaAtLeast70Percent_FatigueAtLeast90);
                                        var_1 = CLINIC_EXAM_RESULT_HIGH_FATIGUE;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (VarGet(VAR_PLAYER_STAMINA) >= VarGet(VAR_PLAYER_MAX_STAMINA) * 50 / 100)
                            {
                                if (VarGet(VAR_PLAYER_FATIGUE) <= 49)
                                {
                                    TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina50To69Percent_FatigueBelow50);
                                    var_1 = CLINIC_EXAM_RESULT_MODERATE_STAMINA_OR_FATIGUE;
                                }
                                else
                                {
                                    if (VarGet(VAR_PLAYER_FATIGUE) <= 69)
                                    {
                                        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina50To69Percent_Fatigue50To69);
                                        var_1 = CLINIC_EXAM_RESULT_MODERATE_STAMINA_OR_FATIGUE;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_PLAYER_FATIGUE) <= 89)
                                        {
                                            TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina50To69Percent_Fatigue70To89);
                                            var_1 = CLINIC_EXAM_RESULT_HIGH_FATIGUE;
                                        }
                                        else
                                        {
                                            TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina50To69Percent_FatigueAtLeast90);
                                            var_1 = CLINIC_EXAM_RESULT_HIGH_FATIGUE;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (VarGet(VAR_PLAYER_STAMINA) >= VarGet(VAR_PLAYER_MAX_STAMINA) * 20 / 100)
                                {
                                    if (VarGet(VAR_PLAYER_FATIGUE) <= 49)
                                    {
                                        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina20To49Percent_FatigueBelow50);
                                        var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_PLAYER_FATIGUE) <= 69)
                                        {
                                            TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina20To49Percent_Fatigue50To69);
                                            var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_MODERATE_FATIGUE;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_PLAYER_FATIGUE) <= 89)
                                            {
                                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina20To49Percent_Fatigue70To89);
                                                var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_HIGH_FATIGUE;
                                            }
                                            else
                                            {
                                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina20To49Percent_FatigueAtLeast90);
                                                var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_HIGH_FATIGUE;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (VarGet(VAR_PLAYER_STAMINA) >= VarGet(VAR_PLAYER_MAX_STAMINA) * 5 / 100)
                                    {
                                        if (VarGet(VAR_PLAYER_FATIGUE) <= 49)
                                        {
                                            TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina5To19Percent_FatigueBelow50);
                                            var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_PLAYER_FATIGUE) <= 69)
                                            {
                                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina5To19Percent_Fatigue50To69);
                                                var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_MODERATE_FATIGUE;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_PLAYER_FATIGUE) <= 89)
                                                {
                                                    TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina5To19Percent_Fatigue70To89);
                                                    var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_HIGH_FATIGUE;
                                                }
                                                else
                                                {
                                                    TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_Stamina5To19Percent_FatigueAtLeast90);
                                                    var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_HIGH_FATIGUE;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_PLAYER_FATIGUE) <= 49)
                                        {
                                            TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaBelow5Percent_FatigueBelow50);
                                            var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_PLAYER_FATIGUE) <= 69)
                                            {
                                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaBelow5Percent_Fatigue50To69);
                                                var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_MODERATE_FATIGUE;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_PLAYER_FATIGUE) <= 89)
                                                {
                                                    TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaBelow5Percent_Fatigue70To89);
                                                    var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_HIGH_FATIGUE;
                                                }
                                                else
                                                {
                                                    TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Diagnosis_StaminaBelow5Percent_FatigueAtLeast90);
                                                    var_1 = CLINIC_EXAM_RESULT_LOW_STAMINA_AND_HIGH_FATIGUE;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        switch (var_1)
                        {
                            case CLINIC_EXAM_RESULT_HEALTHY:
                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_YouLookPerfectlyHealthyToMe);
                                break;
                            case CLINIC_EXAM_RESULT_MODERATE_STAMINA_OR_FATIGUE:
                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_TurbojoltOrRest);
                                break;
                            case CLINIC_EXAM_RESULT_HIGH_FATIGUE:
                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_TurbojoltOrFullDayRest);
                                break;
                            case CLINIC_EXAM_RESULT_LOW_STAMINA:
                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_BodigizerOrRest);
                                break;
                            case CLINIC_EXAM_RESULT_LOW_STAMINA_AND_MODERATE_FATIGUE:
                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_BodigizerAndTurbojoltOrFullDayRest);
                                break;
                            case CLINIC_EXAM_RESULT_LOW_STAMINA_AND_HIGH_FATIGUE:
                                TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Recommendation_BodigizerAndTurbojoltOrFullDayRest);
                                break;
                        }
                    }
                    else
                    {
                        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_TooBadButYouDontHave);
                    }
                    break;
                case PROMPT_CHOICE_OPTION_2:
                    TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_YourePositiveNowWellIfYou);
                    break;
            }
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Table);
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_ShopEvent_Clinic_ExaminationChoice_Table);
    }
    TalkClose();
}
