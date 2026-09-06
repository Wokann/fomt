#ifndef ANIMAL_STATUS_TEXT_HH
#define ANIMAL_STATUS_TEXT_HH

#include "prelude.h"

#define ANIMAL_STATUS_TEXT SECTION(".rodata.animal_status")

extern char const gText_AnimalStatus_Dog[];
extern char const gText_AnimalStatus_Puppy[];
extern char const gText_AnimalStatus_Chicken[];
extern char const gText_AnimalStatus_Chick[];
extern char const gText_AnimalStatus_Sick[];
extern char const gText_AnimalStatus_Unhappy[];
extern char const gText_AnimalStatus_Healthy[];

#endif // ANIMAL_STATUS_TEXT_HH
