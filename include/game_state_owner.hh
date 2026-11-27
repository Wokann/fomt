#ifndef GAME_STATE_OWNER_HH
#define GAME_STATE_OWNER_HH

#include "prelude.h"

struct GameStateSaveImage;

// One-word owner of a native save image. Non-const copies transfer ownership,
// including by-value controller arguments whose cleanup belongs to the callee.
// Keep the pointer ownership interface independent of the saved-image layout.
class GameStateSaveImageOwner {
public:
    explicit GameStateSaveImageOwner(GameStateSaveImage * initial)
        : value(initial) {}
    GameStateSaveImageOwner(GameStateSaveImageOwner & other)
        : value(other.value) { other.value = nullptr; }
    inline ~GameStateSaveImageOwner();
    GameStateSaveImage * get() const { return value; }
    GameStateSaveImage * release()
    {
        GameStateSaveImage * result = value;
        value = nullptr;
        return result;
    }

private:
    GameStateSaveImage * value;
    GameStateSaveImageOwner & operator=(GameStateSaveImageOwner const &);
};


#endif // GAME_STATE_OWNER_HH
