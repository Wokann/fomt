#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_ChurchConfessional_InitialServicePrompt[] =
        "Ist irgendetwas?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_FollowupConcernPrompt[] =
        "Kann ich dir mit etwas \r\n"
        "helfen?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceRemoveCursedTool[] =
        "Fluch aufheben.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfess[] =
        "Beichten.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceJustSayingHi[] =
        "Nur 'Hallo' sagen.";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalFeePrompt[] =
        "Das macht 1.000 G.";

    const char gText_LocationInteraction_ChurchConfessional_ChoicePayRemovalFee[] =
        "OK.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceDeclineRemoval[] =
        "Nein, danke.";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalPrayer[] =
        "Dann lass und beten...{Press}\p"
        "Oh Erntegöttin, bitte hilf\r\n"
        "uns, diesen ungerechten \r\n"
        "Fluch aufzuheben...{Press}";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientMoneyForCursedToolRemoval[] =
        "Sorry, aber du hast wohl\r\n"
        "nicht genug Gold.\r\n"
        "Komm wann anders wieder.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalConfirmationPrompt[] =
        "Bist du sicher?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_NoCursedToolEquipped[] =
        "Aber du hast keine\r\n"
        "verfluchten Dinge!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionAvailableOncePerDay[] =
        "Tue einmal täglich Buße.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionTopicPrompt[] =
        "Wofür möchtest du\r\n"
        "Buße tun?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessInsufficientSleep[] =
        "Schlafe kaum.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessOverworkingHarvestSprites[] =
        "Überarbeite Wichtel.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessDesireToMarryHarvestGoddess[] =
        "Will EG heiraten.";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionForgiven[] =
        "Schlaf ist äußerst wichtig\r\n"
        "für jedermann!{Press}\p"
        "Ich weiß, dass du sehr\r\n"
        "beschäftigt bist, aber du\r\n"
        "solltest ab und zu ausruhen.{Press}Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionRejected[] =
        "Nicht zu schlafen, ist gegen\r\n"
        "die Natur, die die Ernte-\r\n"
        "göttin dir gegeben hat!{Press}\p"
        "Du hast sie verärgert!{Press}\p"
        "Sie hat dir nicht vergeben\r\n"
        "und eines Tages wirst du\r\n"
        "den Preis dafür bezahlen.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionForgiven[] =
        "Keine Angst. Die\r\n"
        "Erntewichtel helfen dir, \r\n"
        "weil sie es möchten.{Press}\p"
        "Trotzdem schlage ich vor,\r\n"
        "dass du ihnen ein Geschenk\r\n"
        "für ihre Bemühungen gibst -{Press}\r\n"
        "das macht sie glücklich.{Press}\p"
        "Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionRejected[] =
        "Was meinst du damit, du \r\n"
        "lässt die Erntewichtel zu \r\n"
        "hart für dich arbeiten?! Wie{Press}\r\n"
        "kannst du ihre Hilfs-\r\n"
        "bereitschaft so ausnutzen!\r\n"
        "Du schenkst ihnen nichts?{Press}\p"
        "Die Erntegöttin hat dir \r\n"
        "nicht vergeben und eines\r\n"
        "Tages zahlst du den Preis!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionForgiven[] =
        "Du willst also die Ernte-\r\n"
        "göttin heiraten?\r\n"
        "Ich bin sicher, sie ist {Press}\r\n"
        "sehr geschmeichelt.{Press}\p"
        "Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionRejected[] =
        "Wa-aas!? Du sagst, du\r\n"
        "willst die Erntegöttin\r\n"
        "heiraten!? Blasphemie!{Press}\r\n"
        "Das will ich zwar auch...\r\n"
        "Warte! Vergiss das!{Press}\p"
        "Die Erntegöttin hat dir \r\n"
        "nicht vergeben und eines\r\n"
        "Tages zahlst du den Preis!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessNeglectingAnimals[] =
        "Tiere vernachlässigt.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceWorkedUntilCollapsed[] =
        "Bis Umfallen gearbeitet.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceTownspeopleDislikePlayer[] =
        "Unbeliebt bei den anderen.";

    const char gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionForgiven[] =
        "Vergiss nicht, dass deine\r\n"
        "Tiere dir ihre Eier, Wolle\r\n"
        "und Milch geben!{Press}\p"
        "Zeige dich dankbar und \r\n"
        "pflege sie gut!{Press}\p"
        "Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionRejected[] =
        "Warum denkst du hat dir\r\n"
        "die Erntegöttin die Tiere\r\n"
        "überlassen!?{Press}\p"
        "Sie geben dir etwas von\r\n"
        "sich, also musst du ihnen\r\n"
        "etwas zurückgeben, indem{Press}\r\n"
        "du sie gut behandelst! Oh,\r\n"
        "die armen Tiere!{Press}\p"
        "Die Erntegöttin hat dir \r\n"
        "nicht vergeben und eines\r\n"
        "Tages zahlst du den Preis!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionForgiven[] =
        "Respekt für dein Streben \r\n"
        "nach harter Arbeit. Doch\r\n"
        "deine Kraft ist begrenzt.{Press}\p"
        "Wenn du bis zum Umfallen\r\n"
        "arbeitest, ignorierst du die\r\n"
        "Grenzen, die die Erntegöttin{Press}\r\n"
        "uns gesetzt hat.{Press}\p"
        "Nimm dir nächstes Mal\r\n"
        "Unterstützung oder ruh\r\n"
        "dich aus, bevor du so {Press}\r\n"
        "schwer arbeitest.{Press}\p"
        "Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionRejected[] =
        "Was denkst du dir, den\r\n"
        "Körper, den dir deine\r\n"
        "Eltern gegeben haben, zu{Press}\r\n"
        "Grunde zu richten! Du\r\n"
        "musst deinen Körper\r\n"
        "mehr respektieren!!{Press}\p"
        "Die Erntegöttin hat dir \r\n"
        "nicht vergeben und eines\r\n"
        "Tages zahlst du den Preis!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ForgivesPoorRelationsAndImprovesFriendship[] =
        "Wenn die Stadtbewohner\r\n"
        "dich nicht mögen, hat {Press}\p"
        "das einen Grund. Schau\r\n"
        "zuerst in dein Herz, dann\r\n"
        "dann versuche, alles{Press}\r\n"
        "wieder gutzumachen.{Press}\p"
        "Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_PoorRelationsConfessionRejected[] =
        "Nicht einmal ich mag \r\n"
        "dich besonders! Lass\r\n"
        "uns das Gespräch beenden!{Press}\r\n"
        "Die Erntegöttin hat dir \r\n"
        "nicht vergeben und eines\r\n"
        "Tages zahlst du den Preis!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessAnimalCruelty[] =
        "Tiere misshandelt.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessSleepingLate[] =
        "Verschlafen.";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessLittering[] =
        "Straße verschmutzt.";

    const char gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionForgiven[] =
        "Der Mensch ist schwach\r\n"
        "und versucht oft, sich\r\n"
        "stärker zu fühlen, indem{Press}\r\n"
        "er Schwächere \r\n"
        "unterdrückt. {Press}\p"
        "Bedenke, dass wahre \r\n"
        "Stärke in der Güte im\r\n"
        "Umgang mit anderen  {Press}\p"
        "liegt - besonders gilt \r\n"
        "dies für Schwächere.{Press}\p"
        "Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionRejected[] =
        "Ich fasse es nicht!\r\n"
        "Wie kannst du so...so...\r\n"
        "grausam zu den armen,{Press}\r\n"
        "hilflosen Tieren sein! \r\n"
        "Oh, die Menschen!{Press}\p"
        "So eine schwarze Seele\r\n"
        "kann nicht gerettet werden!{Press}\p"
        "Die Erntegöttin hat dir \r\n"
        "nicht vergeben und eines\r\n"
        "Tages zahlst du den Preis!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ForgivesSleepingLateAndReducesFatigue[] =
        "Keine Sorge.\r\n"
        "Manchmal ist das Fleisch\r\n"
        "schwach, selbst wenn der{Press}\r\n"
        "Geist willig ist.{Press}\p"
        "Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_SleepingLateConfessionRejected[] =
        "Verschlafen ist ein Zeichen\r\n"
        "von Faulheit!{Press}\p"
        "Wer weiß, wie viele du\r\n"
        "mit deiner Faulheit schon\r\n"
        "genervt hast! Damit {Press}\r\n"
        "gewinnst du keine Freunde!{Press}\p"
        "Die Erntegöttin hat dir \r\n"
        "nicht vergeben und eines\r\n"
        "Tages zahlst du den Preis!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_LitteringConfessionForgiven[] =
        "Deinen eigenen Müll zu ent-\r\n"
        "sorgen, sollte normal sein.{Press}\p"
        "Den Müll anderer Leute zu\r\n"
        "entsorgen, wird von der \r\n"
        "Erntegöttin gern gesehen.{Press}\p"
        "Die Erntegöttin hat dir\r\n"
        "nun vergeben.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_LitteringConfessionRejected[] =
        "...........................\r\n"
        "...........................\r\n"
        "Ich bin so geschockt, dass{Press}\r\n"
        "ich sprachlos bin{Press}\p"
        "Was würdest du denken, \r\n"
        "wenn jemand seinen Müll\r\n"
        "in dein Schlafzimmer wirft!?{Press}\r\n"
        "Du würdest es nicht \r\n"
        "mögen, oder?!{Press}\p"
        "Die Erntegöttin hat dir \r\n"
        "nicht vergeben und eines\r\n"
        "Tages zahlst du den Preis!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionSessionComplete[] =
        "Genug gebeichtet \r\n"
        "für heute.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_Greeting[] =
        "Hallo. Wie geht\x81\x4Cs dir?{Press}";

    const char gText_LocationInteraction_ChurchConfessional_Farewell[] =
        "Komm jederzeit wieder.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionalClosed[] =
        "Abgeschlossen.{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedHoePurified[] =
        "Der Fluch auf der Hacke\r\n"
        "wurde aufgehoben!{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedWateringCanPurified[] =
        "Der Fluch auf der Kanne\r\n"
        "wurde aufgehoben!{Press}";
};

void EventScript_LocationInteraction_ChurchConfessional(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, unused_6, var_7, var_8, var_9;
    var_7 = 0;
    var_3 = FALSE;
    var_5 = VarGet(VAR_DAY_OF_WEEK);
    var_4 = VarGet(VAR_HOUR);
    if (VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MUSIC_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
    {
        var_3 = FALSE;
    }
    else
    {
        if (GetEntityLocation(ENTITY_CARTER) != MAP_NORTH_SIDE_TOWN && GetEntityLocation(ENTITY_CARTER) != MAP_CHURCH)
        {
            var_3 = TRUE;
        }
        else
        {
            var_3 = FALSE;
        }
    }
    if (var_3 == TRUE)
    {
        var_2 = FALSE;
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        OpenDoor(DOOR_SLOT_11);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
        }
        MoveEntityXTo(ENTITY_PLAYER, X(60), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        MoveEntityYTo(ENTITY_PLAYER, Y(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        do
        {
            if (var_2 != TRUE)
            {
                TalkMessage(gText_LocationInteraction_ChurchConfessional_InitialServicePrompt);
            }
            else
            {
                TalkMessage(gText_LocationInteraction_ChurchConfessional_FollowupConcernPrompt);
            }
            var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceRemoveCursedTool, gText_LocationInteraction_ChurchConfessional_ChoiceConfess, gText_LocationInteraction_ChurchConfessional_ChoiceJustSayingHi);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    if (GetPlayerHeldToolId() == ITEM_TOOL_SICKLE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_HOE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_AXE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_HAMMER_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_WATERING_CAN_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_FISHING_ROD_CURSED)
                    {
                        var_0 = TalkPromptChoice2(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalFeePrompt, gText_LocationInteraction_ChurchConfessional_ChoicePayRemovalFee, gText_LocationInteraction_ChurchConfessional_ChoiceDeclineRemoval);
                        switch (var_0)
                        {
                            case PROMPT_CHOICE_OPTION_1:
                                if (GetMoney() >= 1000)
                                {
                                    TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalPrayer);
                                    PlaySong(AUDIO_START, AUDIO_SFX_HEAL_OR_PURIFY);
                                    WaitFrames(60);
                                    SubtractMoney(1000);
                                    var_2 = FALSE;
                                    var_8 = GetPlayerHeldToolId();
                                    var_9 = var_8 + 1;
                                    var_7 = AttemptChurchCursedToolRemoval(var_8);
                                    if (var_7)
                                    {
                                        SetPlayerHeldTool(var_9, 1);
                                    }
                                    CycleBackwardToNonCursedTool();
                                }
                                else
                                {
                                    TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientMoneyForCursedToolRemoval);
                                    var_2 = TRUE;
                                }
                                break;
                            case PROMPT_CHOICE_OPTION_2:
                                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalConfirmationPrompt);
                                var_2 = TRUE;
                                break;
                        }
                    }
                    else
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_NoCursedToolEquipped);
                        var_2 = TRUE;
                    }
                    break;
                case CHOICE_OPTION_2:
                    if (VarGet(VAR_CHURCH_CONFESSION_USED_TODAY) == TRUE)
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionAvailableOncePerDay);
                        var_2 = TRUE;
                    }
                    else
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionTopicPrompt);
                        if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_HARVEST_GODDESS_MARRIAGE_BLESSING_RECEIVED) == TRUE)
                        {
                            var_1 = RandomIntInclusive(1, 4);
                        }
                        else
                        {
                            var_1 = RandomIntInclusive(0, 4);
                        }
                        switch (var_1)
                        {
                            case 0:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessInsufficientSleep, gText_LocationInteraction_ChurchConfessional_ChoiceConfessOverworkingHarvestSprites, gText_LocationInteraction_ChurchConfessional_ChoiceConfessDesireToMarryHarvestGoddess);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionForgiven);
                                                ChangePlayerStaminaAndFatigue(10, 0);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionForgiven);
                                                AddNpcFriendship(CHARACTER_STAID, 2);
                                                AddNpcFriendship(CHARACTER_NAPPY, 2);
                                                AddNpcFriendship(CHARACTER_BOLD, 2);
                                                AddNpcFriendship(CHARACTER_CHEF, 2);
                                                AddNpcFriendship(CHARACTER_AQUA, 2);
                                                AddNpcFriendship(CHARACTER_HOGGY, 2);
                                                AddNpcFriendship(CHARACTER_TIMID, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionRejected);
                                                break;
                                        }
                                        break;
                                    mary_dead_jump:
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 9);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionForgiven);
                                                VarSet(VAR_HARVEST_GODDESS_MARRIAGE_BLESSING_RECEIVED, TRUE);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                            case 4:
                                            case 5:
                                            case 6:
                                            case 7:
                                            case 8:
                                            case 9:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                            case 1:
                            case 2:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessNeglectingAnimals, gText_LocationInteraction_ChurchConfessional_ChoiceWorkedUntilCollapsed, gText_LocationInteraction_ChurchConfessional_ChoiceTownspeopleDislikePlayer);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionForgiven);
                                                AddAffectionToAllFarmAnimals(5);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionForgiven);
                                                ChangePlayerStaminaAndFatigue(10, 0);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_ForgivesPoorRelationsAndImprovesFriendship);
                                                AddNpcFriendship(CHARACTER_LILLIA, 2);
                                                AddNpcFriendship(CHARACTER_RICK, 2);
                                                AddNpcFriendship(CHARACTER_POPURI, 2);
                                                AddNpcFriendship(CHARACTER_BARLEY, 2);
                                                AddNpcFriendship(CHARACTER_MAY, 2);
                                                AddNpcFriendship(CHARACTER_SAIBARA, 2);
                                                AddNpcFriendship(CHARACTER_GRAY, 2);
                                                AddNpcFriendship(CHARACTER_DUKE, 2);
                                                AddNpcFriendship(CHARACTER_MANNA, 2);
                                                AddNpcFriendship(CHARACTER_BASIL, 2);
                                                AddNpcFriendship(CHARACTER_ANNA, 2);
                                                AddNpcFriendship(CHARACTER_MARY, 2);
                                                AddNpcFriendship(CHARACTER_THOMAS, 2);
                                                AddNpcFriendship(CHARACTER_HARRIS, 2);
                                                AddNpcFriendship(CHARACTER_ELLEN, 2);
                                                AddNpcFriendship(CHARACTER_STU, 2);
                                                AddNpcFriendship(CHARACTER_JEFF, 2);
                                                AddNpcFriendship(CHARACTER_SASHA, 2);
                                                AddNpcFriendship(CHARACTER_KAREN, 2);
                                                AddNpcFriendship(CHARACTER_DOCTOR, 2);
                                                AddNpcFriendship(CHARACTER_ELLI, 2);
                                                AddNpcFriendship(CHARACTER_CARTER, 2);
                                                AddNpcFriendship(CHARACTER_CLIFF, 2);
                                                AddNpcFriendship(CHARACTER_DOUG, 2);
                                                AddNpcFriendship(CHARACTER_ANN, 2);
                                                AddNpcFriendship(CHARACTER_KAI, 2);
                                                AddNpcFriendship(CHARACTER_GOTZ, 2);
                                                AddNpcFriendship(CHARACTER_ZACK, 2);
                                                AddNpcFriendship(CHARACTER_WON, 2);
                                                AddNpcFriendship(CHARACTER_GOURMET, 2);
                                                AddNpcFriendship(CHARACTER_HARVEST_GODDESS, 2);
                                                AddNpcFriendship(CHARACTER_VAN, 2);
                                                AddNpcFriendship(CHARACTER_LOU_OR_RUBY, 2);
                                                AddNpcFriendship(CHARACTER_CHILD, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_PoorRelationsConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                            case 3:
                            case 4:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessAnimalCruelty, gText_LocationInteraction_ChurchConfessional_ChoiceConfessSleepingLate, gText_LocationInteraction_ChurchConfessional_ChoiceConfessLittering);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionForgiven);
                                                AddAffectionToAllFarmAnimals(5);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_ForgivesSleepingLateAndReducesFatigue);
                                                ChangePlayerStaminaAndFatigue(0, mary_negated_int(-2));
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_SleepingLateConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_LitteringConfessionForgiven);
                                                AddNpcFriendship(CHARACTER_LILLIA, 2);
                                                AddNpcFriendship(CHARACTER_RICK, 2);
                                                AddNpcFriendship(CHARACTER_POPURI, 2);
                                                AddNpcFriendship(CHARACTER_BARLEY, 2);
                                                AddNpcFriendship(CHARACTER_MAY, 2);
                                                AddNpcFriendship(CHARACTER_SAIBARA, 2);
                                                AddNpcFriendship(CHARACTER_GRAY, 2);
                                                AddNpcFriendship(CHARACTER_DUKE, 2);
                                                AddNpcFriendship(CHARACTER_MANNA, 2);
                                                AddNpcFriendship(CHARACTER_BASIL, 2);
                                                AddNpcFriendship(CHARACTER_ANNA, 2);
                                                AddNpcFriendship(CHARACTER_MARY, 2);
                                                AddNpcFriendship(CHARACTER_THOMAS, 2);
                                                AddNpcFriendship(CHARACTER_HARRIS, 2);
                                                AddNpcFriendship(CHARACTER_ELLEN, 2);
                                                AddNpcFriendship(CHARACTER_STU, 2);
                                                AddNpcFriendship(CHARACTER_JEFF, 2);
                                                AddNpcFriendship(CHARACTER_SASHA, 2);
                                                AddNpcFriendship(CHARACTER_KAREN, 2);
                                                AddNpcFriendship(CHARACTER_DOCTOR, 2);
                                                AddNpcFriendship(CHARACTER_ELLI, 2);
                                                AddNpcFriendship(CHARACTER_CARTER, 2);
                                                AddNpcFriendship(CHARACTER_CLIFF, 2);
                                                AddNpcFriendship(CHARACTER_DOUG, 2);
                                                AddNpcFriendship(CHARACTER_ANN, 2);
                                                AddNpcFriendship(CHARACTER_KAI, 2);
                                                AddNpcFriendship(CHARACTER_GOTZ, 2);
                                                AddNpcFriendship(CHARACTER_ZACK, 2);
                                                AddNpcFriendship(CHARACTER_WON, 2);
                                                AddNpcFriendship(CHARACTER_GOURMET, 2);
                                                AddNpcFriendship(CHARACTER_HARVEST_GODDESS, 2);
                                                AddNpcFriendship(CHARACTER_VAN, 2);
                                                AddNpcFriendship(CHARACTER_LOU_OR_RUBY, 2);
                                                AddNpcFriendship(CHARACTER_CHILD, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_LitteringConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                        }
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionSessionComplete);
                        VarSet(VAR_CHURCH_CONFESSION_USED_TODAY, TRUE);
                        var_2 = FALSE;
                    }
                    break;
                case CHOICE_OPTION_3:
                    TalkMessage(gText_LocationInteraction_ChurchConfessional_Greeting);
                    var_2 = FALSE;
                    break;
            }
        }
        while (var_2 == TRUE);
        TalkMessage(gText_LocationInteraction_ChurchConfessional_Farewell);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
        }
        MoveEntityYTo(ENTITY_PLAYER, Y(64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        CloseDoor(DOOR_SLOT_11);
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionalClosed);
        TalkClose();
    }
    if (var_7)
    {
        switch (var_9)
        {
            case ITEM_TOOL_HOE_BLESSED:
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                    ShowPlayerHoldingTool(ITEM_TOOL_HOE_BLESSED);
                    WaitFrames(90);
                }
                TalkOpen();
                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedHoePurified);
                TalkClose();
                break;
            case ITEM_TOOL_WATERING_CAN_BLESSED:
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                    ShowPlayerHoldingTool(ITEM_TOOL_WATERING_CAN_BLESSED);
                    WaitFrames(90);
                }
                TalkOpen();
                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedWateringCanPurified);
                TalkClose();
                break;
        }
    }
}
