#include "new_game_name_entry.hh"
#include FOMT_TEXT_INCLUDE(new_game_name_entry.cc)
#include "prelude.h"

#include "new_game_birthday_input.hh"
#include "new_game_identity.hh"
#include "new_game_name_input.hh"
#include "new_game_data.hh"
#include "hardware_manager.hh"
#include "hardware_sound.hh"
#include "fomt_constants.hh"

void * operator new(unsigned long);
void operator delete(void *);

#pragma interface "new_game_name_entry.hh"
inline NewGameFreshSaveTransition::NewGameFreshSaveTransition(char const * farm, char const * player,
        GameDate date, char const * dog)
    : farm_name(farm), player_name(player), birthday(date), dog_name(dog) {}

NewGameNameEntryScene::NewGameNameEntryScene() {}

NewGameNameEntryScene::~NewGameNameEntryScene() {}

SceneTransitionOwner NewGameNameEntryScene::Run()
{
    HardwareManagerOwner manager;
    StartOrChangeHardwareSong(AUDIO_BGM_TITLE_SCREEN);
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
