#include "prelude.h"
#pragma implementation "new_game_name_entry.hh"
#include "new_game_name_entry.hh"
#include "new_game.hh"
#include "new_game_identity.hh"
#include "new_game_name_input.hh"
#include "new_game_data.hh"
#include "game_scene.hh"
#include "hardware_manager.hh"
#include "hardware_song.hh"
#include "fomt_constants.hh"
#pragma implementation

void * operator new(unsigned long);
void operator delete(void *);

NewGameNameEntryScene::NewGameNameEntryScene() {}

NewGameNameEntryScene::~NewGameNameEntryScene() {}

SceneTransitionOwner NewGameNameEntryScene::Run()
{
    HardwareManagerOwner manager;
    func_08008DB8(AUDIO_BGM_TITLE_SCREEN);
    FixedStr<12> player_name ALIGN(4);
    FixedStr<12> farm_name ALIGN(4);
    FixedStr<12> dog_name ALIGN(4);
    GameDate birthday(SEASON_SPRING, 0);
    u8 confirmed;
    do {
        {
            NewGameNameInputScene input(gText_NewGameIdentity_PlayerPrefix, player_name);
            input.Run();
            player_name = input.GetName();
        }
        {
            NewGameBirthdayInputScene input(birthday);
            input.Run();
            birthday = input.GetDate();
        }
        {
            NewGameNameInputScene input(gText_NewGameIdentity_FarmPrefix, farm_name);
            input.Run();
            farm_name = input.GetName();
        }
        {
            NewGameNameInputScene input(gText_NewGameIdentity_DogPrefix, dog_name);
            input.Run();
            dog_name = input.GetName();
        }
        {
            NewGameIdentityScene input(player_name, birthday, farm_name, dog_name);
            input.Run();
            confirmed = input.GetConfirmed();
        }
    } while (!confirmed);
    return SceneTransitionOwner(new NewGameFreshSaveTransition(
        farm_name, player_name, birthday, dog_name));
}

SceneOwner NewGameFreshSaveTransition::CreateScene()
{
    return SceneOwner(new GameSceneScriptController(farm_name,
        player_name, birthday, dog_name));
}
