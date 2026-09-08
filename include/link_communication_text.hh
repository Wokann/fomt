#ifndef LINK_COMMUNICATION_TEXT_HH
#define LINK_COMMUNICATION_TEXT_HH

#include "prelude.h"

#define LINK_COMMUNICATION_TEXT SECTION(".rodata.link_communication")

extern char const gText_LinkCommunication_Waiting[];
extern char const gText_LinkCommunication_SendingGameData[];
extern char const gText_LinkCommunication_TestingConnection[];
extern char const gText_LinkCommunication_CannotResendPreviousData[];
extern char const gText_LinkCommunication_ProceedQuestion[];
extern char const gText_LinkCommunication_Yes[];
extern char const gText_LinkCommunication_No[];
extern char const gText_LinkCommunication_WaitingForOtherPlayer[];
extern char const gText_LinkCommunication_NowSendingData[];
extern char const gText_LinkCommunication_DataExchangeFailed[];
extern char const gText_LinkCommunication_QuitCommunication[];
extern char const gText_LinkCommunication_OtherPlayerCanceled[];
extern char const gText_LinkCommunication_IncompatibleGameData[];
extern char const gText_LinkCommunication_ExchangeRestriction[];
extern char const gText_LinkCommunication_ActionQuestion[];
extern char const gText_LinkCommunication_Declined[];
extern char const gText_LinkCommunication_Complete[];

#if defined(REGION_JP)
extern u16 const gLinkCommunicationCharacterCodeTable[];
#else
extern u8 const gLinkCommunicationCharacterCodeTable[];
#endif

#endif // LINK_COMMUNICATION_TEXT_HH
