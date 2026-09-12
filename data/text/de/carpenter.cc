#include "carpenter_text.hh"

#if defined(FOMT_TEXT_CARPENTER_MENU)

char const gText_Carpenter_Lumber[] =
    "Nutzholz";

char const gText_Carpenter_GoldenLumber[] =
    "Goldenes Nutzholz";

char const gText_Carpenter_HouseExtension[] =
    "Hausausbau";

char const gText_Carpenter_HouseExtensionFirstCost[] =
    "Kosten Hausausbau\r\n"
    "Gold           3.000G\r\n"
    "Nutzholz       200 Stück";

char const gText_Carpenter_HouseExtensionSecondCost[] =
    "Kosten Hausausbau\r\n"
    "Gold           10.000G\r\n"
    "Nutzholz       700 Stück";

char const gText_Carpenter_AddBathtub[] =
    "Badewanne anbauen";

char const gText_Carpenter_BathtubCost[] =
    "Kosten Badausbau\r\n"
    "Gold           30.000G\r\n"
    "Nutzholz       580 Stück";

char const gText_Carpenter_ExpandChickenCoop[] =
    "Hühnerstall";

char const gText_Carpenter_ChickenCoopCost[] =
    "Kosten Hühnerstall- \r\n"
    "ausbau{Press}\p"
    "Gold           5.000G\r\n"
    "Nutzholz       420 Stück";

char const gText_Carpenter_ExpandBarn[] =
    "Scheune umbauen";

char const gText_Carpenter_BarnCost[] =
    "Kosten Scheunenausbau\r\n"
    "Gold           6.800G\r\n"
    "Nutzholz       500 Stück";

char const gText_Carpenter_BuildVacationHouse[] =
    "Ferienhaus";

char const gText_Carpenter_VacationHouseCost[] =
    "Kosten Häuschen\r\n"
    "Gold           100.000.000G\r\n"
    "Nutzholz       999 Stück";

char const gText_Carpenter_RemodelWindow[] =
    "Fenster umändern";

char const gText_Carpenter_Rebuild[] =
    "Neuaufbau.";

char const gText_Carpenter_RemodelDoghouse[] =
    "Hundehütte ändern";

char const gText_Carpenter_RemodelMailbox[] =
    "Neuer Briefkasten";

char const gText_Carpenter_SquareWindowWithShutters[] =
    "Fenster m. Gitter";

char const gText_Carpenter_WindowCost[] =
    "Gold           25.000G\r\n"
    "Nutzholz       300 Stück";

char const gText_Carpenter_SquareWindowWithoutShutters[] =
    "Fenster o. Gitter";

char const gText_Carpenter_RoundWindow[] =
    "Rundes Fenster";

char const gText_Carpenter_RedDoghouse[] =
    "Rote Hundehütte";

char const gText_Carpenter_DoghouseCost[] =
    "Gold           20.000G\r\n"
    "Nutzholz       500 Stück";

char const gText_Carpenter_BlueDoghouse[] =
    "Blaue Hundehütte";

char const gText_Carpenter_BlueDoghouseCost[] =
    "Gold           20,000G\r\n"
    "Nutzholz       500 Stück";

char const gText_Carpenter_StrangeDoghouse[] =
    "Seltsame Hundeh.";

char const gText_Carpenter_RedMailbox[] =
    "Roter Briefkasten";

char const gText_Carpenter_MailboxCost[] =
    "Gold           10.000G\r\n"
    "Nutzholz       200 Stück";

char const gText_Carpenter_BlueMailbox[] =
    "Blauer Briefkasten";

char const gText_Carpenter_StrangeMailbox[] =
    "Seltsamer Briefk.";

#elif defined(FOMT_TEXT_CARPENTER_DIALOGUE)

char const gText_Carpenter_RebuildRequirements[] ALIGN(4) =
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

#else
#error "Select one carpenter text fragment before including this file."
#endif
