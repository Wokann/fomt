#include "carpenter_data.hh"

// The Carpenter menu constructor seeds its working text buffer with this
// single page-break control code before adding the selected entry text.
char const gText_Carpenter_InitialPageBreak[] =
    "\p";

char const gText_Carpenter_RebuildRequirements[] =
    "Für den Neuaufbau\r\n";

char const gText_Carpenter_InsufficientGold[] =
    "Du hast nicht genug Gold.{Press}";

char const gText_Carpenter_LumberBinFull[] =
    "Dein Holzlager ist \r\n"
    "schon voll.{Press}";

char const gText_Carpenter_LumberHeader[] =
    "Nutzholz\r\n"
    "\r\n";

char const gText_Carpenter_EquipmentFull[] =
    "Du kannst nichts anderes\r\n"
    "mehr halten.{Press}";

char const gText_Carpenter_GoldenLumberHeader[] =
    "Goldenes Nutzholz\r\n"
    "\r\n";

char const gText_Carpenter_CannotAcceptAnotherJob[] =
    "Bevor ich diesen Auftrag\r\n"
    "nicht erledigt habe, nehme\r\n"
    "ich keinen anderen an.{Press}\p"
    "So arbeite ich eben.{Press}";

char const gText_Carpenter_InsufficientLumber[] =
    "Du hast nicht genug \r\n"
    "Nutzholz.{Press}";

char const gText_Carpenter_ThreeDayConfirmation[] =
    "Es wird 3 Tage bis\r\n"
    "zur Fertigstellung dauern.\r\n"
    "Bist du sicher?{Press}";

char const gText_Carpenter_NeedAnythingElse[] =
    "Brauchst du nichts\r\n"
    "anderes mehr?{Press}";

char const gText_Carpenter_AreYouSureNow[] =
    "Bist du sicher?{Press}";

char const gText_Carpenter_SameCurrentShape[] =
    "Sicher, dass du es nicht\r\n"
    "ändern willst?{Press}";

char const gText_Carpenter_StoreLumber[] =
    "Ich bringe das Holz\r\n"
    "dann ins Holzlager!{Press}";

char const gText_Carpenter_DeliveryAll[] =
    "Danke. Du kannst nichts mehr\r\n"
    "halten, also lasse ich\r\n"
    "es zu dir liefern.{Press}";

char const gText_Carpenter_DeliverySome[] =
    "Danke. Du kannst davon nicht\r\n"
    "mehrere halten, also lasse\r\n"
    "ich es zu dir liefern.{Press}";

char const gText_Carpenter_PurchaseComplete[] =
    "Sehr verbunden!{Press}";

char const gText_Carpenter_Build[] =
    "Bauen";

char const gText_Carpenter_DontBuild[] =
    "Nicht bauen";

char const gText_Carpenter_Upgrade[] =
    "Aufrüsten";

char const gText_Carpenter_DontUpgrade[] =
    "Nicht aufrüsten";

char const gText_Carpenter_StartUpgradeTomorrow[] =
    "Ok, ich fange morgen mit \r\n"
    "der Aufrüstung an.{Press}";

char const gText_Carpenter_NeedAnythingMore[] =
    "Noch etwas anderes?{Press}";

char const gCppRuntimeBadAlloc_Carpenter[] =
    "bad_alloc";
