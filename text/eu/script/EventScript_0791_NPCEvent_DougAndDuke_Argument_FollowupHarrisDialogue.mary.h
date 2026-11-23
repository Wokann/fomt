mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_StoppedFight_FirstTalk_HarrisRelievedFightEnded[] =
        "I was getting worried \r\n"
        "there!...{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_StoppedFight_RepeatTalk_HarrisThanksPlayerForHelp[] =
        "When those two start \r\n"
        "fighting, even I can't stop\r\n"
        "them by myself. {Press}\p"
        "Thanks, {Player}. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_NotIntervened_FirstTalk_HarrisDecidesToIntervene[] =
// A trailing space exceeds the 28-column row and overwrites its first glyph.
#ifdef BUGFIX
        "I should put a stop to this.{Press}";
#else
        "I should put a stop to this. {Press}";
#endif

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_NotIntervened_RepeatTalk_HarrisAdmitsHeCannotStopBothAlone[] =
        "But, I can't stop both of \r\n"
        "them all by myself...{Press}";
};
