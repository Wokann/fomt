#include "frisbee_scoreboard.hh"

char const gText_FrisbeeScoreboard_ContestantNames
    [FRISBEE_SCOREBOARD_CONTESTANT_COUNT]
    [FRISBEE_SCOREBOARD_CONTESTANT_NAME_WIDTH] ALIGN(1) = {
    "Fido",
    "Sox",
    "Sam",
    "Lady　",
    "Princess　",
    "Ginger　　",
    "Max　　　　",
    "Sam　　",
    "Rocky",
    "Buster　　　",
    "Charlie",
    "Rusty　　",
    "Zoe",
    "Daisy　",
    "Molly　　　",
    "Jess　　",
    "Tricky　　　",
    "Brewster　　",
    "Isis　",
    "Myst　　",
    "Amanda",
    "Amber　　",
    "Panda　",
    "Angel　　　　",
    "Fifi　　",
    "Echo　　　　",
    "Nic",
    "Quartz",
    "Betty",
    "Gertrude　",
};

u16 const gFrisbeeScoreboardCharacterCodes[21] = {
    "0123456789.m#"
};

char const gText_Frisbee_TournamentScoreboard[] =
    "Frisbee Contest　Scoreboard";
