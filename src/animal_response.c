#include "animal_response.hh"

u32 CalculateAnimalResponseRadius(u32 value)
{
    return 48 + value * value * 432 / 62500;
}
