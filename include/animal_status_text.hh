#ifndef ANIMAL_STATUS_TEXT_HH
#define ANIMAL_STATUS_TEXT_HH

#include "prelude.h"

struct AnimalStatusScreenPrefixText
{
    char unavailable[6];
#if defined(REGION_JP)
    char digits[21];
    char digit_trailer[1];
#else
    char digits[10][2];
    char padding[2];
#endif
};

#if defined(REGION_JP)
struct AnimalStatusScreenText
{
    char healthy[8];
    char unhappy[8];
    char sick[8];
    char spring[4];
    char summer[4];
    char autumn[4];
    char winter[4];
    char age[4];
    char day[4];
};
#else
struct AnimalStatusScreenText
{
    char healthy[12];
    char unhappy[12];
    char sick[12];
    char spring[8];
    char summer[8];
    char autumn[8];
    char winter[8];
    char age[4];
    char day[4];
};
#endif

extern AnimalStatusScreenPrefixText const gAnimalStatusScreenPrefixText;
extern AnimalStatusScreenText const gAnimalStatusScreenText;

extern char const gText_AnimalStatus_Dog[];
extern char const gText_AnimalStatus_Puppy[];
extern char const gText_AnimalStatus_Chicken[];
extern char const gText_AnimalStatus_Chick[];
extern char const gText_AnimalStatus_Sick[];
extern char const gText_AnimalStatus_Unhappy[];
extern char const gText_AnimalStatus_Healthy[];

#endif // ANIMAL_STATUS_TEXT_HH
