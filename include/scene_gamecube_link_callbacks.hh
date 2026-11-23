#ifndef SCENE_GAMECUBE_LINK_CALLBACKS_HH
#define SCENE_GAMECUBE_LINK_CALLBACKS_HH

#include "config.h"

#include "scene_gamecube_link.hh"

#pragma interface "scene_gamecube_link_callbacks.hh"

inline JoyBusLinkProtocol::JoyBusLinkProtocol()
{
    InitializeJoyBusContext(&context);
    SetMode(0);
}



inline void GameCubeLinkUiCore::MarkPhaseChanged()
{
    phase_changed = true;
}

inline void GameCubeLinkUiCore::SetPhase(u32 next)
{
    phase = next;
    phase_changed = true;
}

inline void GameCubeLinkUiCore::ActRetry()
{
}

inline u32 GameCubeLinkUiCore::PollRetry()
{
    u32 result = 0;
    switch (dialogue_phase) {
    case 0:
        if (ui_state == 3) {
            dialogue_phase = 1;
            func_08050E0C(&ui, gText_LinkCommunication_Yes,
                gText_LinkCommunication_No, nullptr, nullptr, nullptr, nullptr, nullptr);
        }
        break;
    case 1:
        if (ui_state == 3) {
            switch (ui.GetChoiceResult()) {
            case 1: result = 2; break;
            case 2: result = 3; break;
            }
        }
        break;
    }
    return result;
}

inline void GameCubeLinkUiCore::EnterRetry()
{
    unk_3E0 = 0;
    dialogue_phase = 0;
    func_08050D8C(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(gText_LinkCommunication_DataExchangeFailed));
    ui.ShowPortrait(0x3A);
#if defined(BUGFIX) || defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    // PollRetry runs before Run refreshes this cached window state.
    ui_state = 4;
#endif
}

inline void GameCubeLinkUiCore::ActPayload()
{
}

inline void GameCubeLinkUiCore::EnterPayload()
{
    func_08050D8C(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(gText_LinkCommunication_NowSendingData));
    ui.ShowPortrait(0x38);
}

inline u32 GameCubeLinkUiCore::PollDecision()
{
    u8 const pressed = ::GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & 2;
    return pressed != 0;
}

inline void GameCubeLinkUiCore::EnterDecision()
{
    func_08050DC8(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(gText_LinkCommunication_WaitingForOtherPlayer), 0, 0);
    ui.ShowPortrait(0x38);
}

inline void GameCubeLinkUiCore::ActConfirmation()
{
}

inline u32 GameCubeLinkUiCore::PollConfirmation()
{
    u32 result = 0;
    switch (dialogue_phase) {
    case 0:
        if (ui.GetState() == 3) {
            dialogue_phase = 1;
            func_08050E30(&ui, gText_LinkCommunication_ProceedQuestion,
                gText_LinkCommunication_Yes, gText_LinkCommunication_No,
                nullptr, nullptr, nullptr);
        }
        break;
    case 1:
        if (ui.GetState() == 3) {
            switch (ui.GetChoiceResult()) {
            case 1: result = 2; break;
            case 2: result = 3; break;
            }
        }
        break;
    }
    return result;
}

inline void GameCubeLinkUiCore::EnterConfirmation()
{
    unk_3E0 = 0;
    dialogue_phase = 0;
    func_08050DC8(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(gText_LinkCommunication_CannotResendPreviousData), 0, 0);
    ui.ShowPortrait(0x3A);
}

inline void GameCubeLinkUiCore::EnterRecordCheck()
{
    func_08050DC8(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(gText_LinkCommunication_TestingConnection), 0, 0);
    ui.ShowPortrait(0x38);
}

inline void GameCubeLinkUiCore::EnterMetadata()
{
    func_08050DC8(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(gText_LinkCommunication_SendingGameData), 0, 0);
    ui.ShowPortrait(0x38);
}

inline u32 GameCubeLinkUiCore::PollConnect()
{
    u8 const pressed = ::GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & 2;
    return pressed != 0;
}

inline void GameCubeLinkUiCore::EnterConnect()
{
    func_08050DC8(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(gText_LinkCommunication_Waiting), 0, 0);
    ui.ShowPortrait(0x39);
}

inline u32 GameCubeLinkUiCore::GetPressedKeys()
{
    return ::GetHardwarePressedKeys(reinterpret_cast<void * const *>(this));
}

inline u32 GameCubeLinkUiCore::GetHeldKeys()
{
    return ::GetHardwareHeldKeys(reinterpret_cast<void * const *>(this));
}


#endif // SCENE_GAMECUBE_LINK_CALLBACKS_HH
