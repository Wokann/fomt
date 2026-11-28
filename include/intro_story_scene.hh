#ifndef INTRO_STORY_SCENE_HH
#define INTRO_STORY_SCENE_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "ui_state.hh"
#include "scene.hh"

struct GameStateSaveImage;


struct IntroStorySceneCore;

#pragma interface "intro_story_scene.hh"
// Own the flashback core and release it through its virtual destructor.
struct IntroStoryCoreOwner
{
    IntroStorySceneCore * value;
    explicit IntroStoryCoreOwner(GameStateSaveImage * saved);
    ~IntroStoryCoreOwner();
private:
    IntroStoryCoreOwner(IntroStoryCoreOwner const &);
    IntroStoryCoreOwner & operator=(IntroStoryCoreOwner const &);
};

#pragma interface "intro_story_lifetimes.hh"
struct IntroStoryScene : AScene
{
    IntroStoryCoreOwner core;
    SceneTransitionOwner continuation;

    IntroStoryScene(SceneTransition *& next, GameStateSaveImage * saved);
    virtual ~IntroStoryScene();
    virtual SceneTransitionOwner Run();
};

// Variable context embedded in the childhood story. Its local selector is
// 0xFF; do not confuse this with a complete encoded control sequence.
struct IntroStoryTextVariables : ScriptTextVariableStore
{
    char const * player_name;
#pragma interface "intro_story_scene.hh"
    IntroStoryTextVariables() : player_name(nullptr) {}
#pragma interface "intro_story_lifetimes.hh"
    virtual ~IntroStoryTextVariables();
    virtual UiTextSubstitution Lookup(u32 code);
};



#pragma interface "intro_story_scene.hh"

// The flashback owns this dialog until its embedded variable context is gone.
struct IntroStoryUiOwner
{
    UiStateOwner * value;
    explicit inline IntroStoryUiOwner(u32 const & flags);
    ~IntroStoryUiOwner() { delete value; }
};

#pragma interface "intro_story_lifetimes.hh"
struct IntroStorySceneCore : HardwareContext
{
    explicit IntroStorySceneCore(GameStateSaveImage * saved);
    virtual ~IntroStorySceneCore();
    GameStateSaveImage * saved;
    u32 unk_0C;
    IntroStoryUiOwner ui_state;
    HardwareMusicPlayerSlot music_player_1;
    HardwareMusicPlayerSlot music_player_0;
    HardwareMusicPlayerSlot music_player_2;
    // Twenty 32-column, 20-row BG maps. Consecutive pairs upload to BG3/BG2.
    // Initialization leaves their storage untouched until the maps are unpacked.
    u16 background_tilemaps[20][20][32];
    i16 scene_step;
    i16 transition_phase;
    // Animation and dialogue share the story index. The dialogue coordinator
    // keeps its original numeric states until the complete animation loop is recovered.
    i16 story_step;
    i16 dialogue_state;
    IntroStoryTextVariables variables;
};


EXTERN_C
SceneTransitionOwner RunIntroStorySceneCore(IntroStorySceneCore *);
void UpdateIntroStoryUi(IntroStorySceneCore *);
void InitializeIntroStoryGraphics(IntroStorySceneCore *);
EXTERN_C_END


// The flashback transition owns its continuation and borrows saved world state.

EXTERN_C

extern u8 const gIntroStoryFrame00Bg3Tilemap[];
extern u8 const gIntroStoryFrame00Bg2Tilemap[];
extern u8 const gIntroStoryFrame01Bg3Tilemap[];
extern u8 const gIntroStoryFrame01Bg2Tilemap[];
extern u8 const gIntroStoryFrame02Bg3Tilemap[];
extern u8 const gIntroStoryFrame02Bg2Tilemap[];
extern u8 const gIntroStoryFrame03Bg3Tilemap[];
extern u8 const gIntroStoryFrame03Bg2Tilemap[];
extern u8 const gIntroStoryFrame04Bg3Tilemap[];
extern u8 const gIntroStoryFrame04Bg2Tilemap[];
extern u8 const gIntroStoryFrame05Bg3Tilemap[];
extern u8 const gIntroStoryFrame05Bg2Tilemap[];
extern u8 const gIntroStoryFrame06Bg3Tilemap[];
extern u8 const gIntroStoryFrame06Bg2Tilemap[];
extern u8 const gIntroStoryFrame07Bg3Tilemap[];
extern u8 const gIntroStoryFrame07Bg2Tilemap[];
extern u8 const gIntroStoryFrame08Bg3Tilemap[];
extern u8 const gIntroStoryFrame08Bg2Tilemap[];
extern u8 const gIntroStoryFrame09Bg3Tilemap[];
extern u8 const gIntroStoryFrame09Bg2Tilemap[];

// Physical order is BG3 then BG2 for each of the ten background frames.
extern u8 const * const gIntroStoryTilemapSources[20];

EXTERN_C_END

extern char const gText_IntroScene_MotherName[];
extern char const gText_IntroScene_MotherTravelGreeting[];
extern char const gText_IntroScene_FatherName[];
extern char const gText_IntroScene_FatherFishingInvitation[];
extern char const gText_IntroScene_MotherCannotFindPlayer[];
extern char const gText_IntroScene_PlayerResponseWhat[];
extern char const gText_IntroScene_OldManName[];
extern char const gText_IntroScene_OldManFindsPlayer[];
extern char const gText_IntroScene_MotherThanksOldMan[];
extern char const gText_IntroScene_FatherExplainsVacation[];
extern char const gText_IntroScene_OldManOffersStay[];
extern char const gText_IntroScene_FatherAsksAboutStay[];
extern char const gText_IntroScene_OldManWelcomesFamily[];
extern char const gText_IntroScene_MotherTellsPlayerToPlay[];
extern char const gText_IntroScene_UnknownName[];
extern char const gText_IntroScene_UnknownCallsPlayer[];
extern char const gText_IntroScene_UnknownFindsPlayer[];
extern char const gText_IntroScene_GirlName[];
extern char const gText_IntroScene_GirlThinksPlayerDead[];
extern char const gText_IntroScene_GirlInvitesPlayerToPlay[];
extern char const gText_IntroScene_GirlAsksPlayerStory[];
extern char const gText_IntroScene_OldManFarewell[];
extern char const gText_IntroScene_OldManRequestsLetter[];
extern char const gText_IntroScene_OldManGivesAddress[];
extern char const gText_IntroScene_GirlSaysGoodbye[];
extern char const gText_IntroScene_GirlAsksPlayerToReturn[];
extern char const gText_IntroScene_OldManNotesFriend[];
extern char const gText_IntroScene_OldManWaitsForLetter[];

#include "intro_story_lifetimes.hh"

#endif // INTRO_STORY_SCENE_HH
