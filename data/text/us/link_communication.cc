#include "link_communication_text.hh"

char const gText_LinkCommunication_Waiting[] =
    "Now communicating.\r\n"
    "Is other player prepared?\r\n"
    "(B Button to cancel)";

char const gText_LinkCommunication_SendingGameData[] =
    "Sending game data now...";

char const gText_LinkCommunication_TestingConnection[] =
    "Testing connection...";

char const gText_LinkCommunication_CannotResendPreviousData[] =
    "You won't be able to send\r\n"
    "previous game data.{Press}";

char const gText_LinkCommunication_ProceedQuestion[] =
    "OK?";

char const gText_LinkCommunication_Yes[] =
    "Yes";

char const gText_LinkCommunication_No[] =
    "No";

char const gText_LinkCommunication_WaitingForOtherPlayer[] =
    "Waiting for other player\r\n"
    "to respond.\r\n"
    "Press B Button to cancel.{Press}";

char const gText_LinkCommunication_NowSendingData[] =
    "Now sending dgata.";

char const gText_LinkCommunication_DataExchangeFailed[] =
    "Data exchange failed.\r\n"
    "Try again?{Press}";

char const gText_LinkCommunication_QuitCommunication[] =
    "OK, I'll quit\r\n"
    "communication, then.{Press}";

char const gText_LinkCommunication_OtherPlayerCanceled[] =
    "What's the matter?\r\n"
    "The other player seems\r\n"
    "to have canceled.{Press}";

char const gText_LinkCommunication_IncompatibleGameData[] =
    "Hmmm?\r\n"
    "This data and A Wonderful\r\n"
    "Life's data didn't{Press}\r\n"
    "go well together.{Press}";

char const gText_LinkCommunication_ExchangeRestriction[] =
    "You can only exchange data\r\n"
    "with Game Cube's Harvest\r\n"
    "Moon, and only if you{Press}\r\n"
    "haven't shared data with\r\n"
    "other games. {Press}";

char const gText_LinkCommunication_ActionQuestion[] =
    "Shall I stop communication?";

char const gText_LinkCommunication_Declined[] =
    "So you don't want to\r\n"
    "send data after all?\r\n"
    "Too bad...{Press}";

char const gText_LinkCommunication_Complete[] =
    "Communication complete.{Press}";

// The extended single-byte game-font glyphs have no independently verified
// Unicode names yet, so keep their proven ROM codes explicit.
u8 const gLinkCommunicationCharacterCodeTable[]
    SECTION(".rodata.link_communication_character_codes") ALIGN(2) =
    FOMT_GLYPH_TEXT(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789!%&\xBF()~\xA2\xA3<>.?\xA5+-x*/o\xB6\xB7\xB3\xB2\xB1\xC0"
        "\xBB\xBC\xBD\xBE\xC1\xC2\xC3 \xB4"
    );
