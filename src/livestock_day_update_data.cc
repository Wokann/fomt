#include "livestock_day_update_data.hh"

LivestockDayUpdateInfo const gChickenDayUpdateInfo = {
    40,
    70,
    { 0, 10, 50, 100, 100, 100, 100 },
    { 0, 5, 10, 30, 70 },
    { { 0, 0 }, { 361, 5 }, { 421, 30 }, { 481, 100 } },
};

LivestockDayUpdateInfo const gCowDayUpdateInfo = {
    40,
    50,
    { 0, 10, 20, 30, 40, 50, 100 },
    { 0, 0, 5, 10, 45 },
    { { 0, 0 }, { 601, 5 }, { 661, 30 }, { 721, 100 } },
};

LivestockDayUpdateInfo const gSheepDayUpdateInfo = {
    40,
    60,
    { 0, 10, 30, 50, 100, 100, 100 },
    { 0, 0, 5, 30, 70 },
    { { 0, 0 }, { 481, 5 }, { 541, 30 }, { 601, 100 } },
};
