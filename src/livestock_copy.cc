#include "sheep.hh"
#include "cow.hh"

Sheep & Sheep::operator=(Sheep const & other)
{
    BarnAnimal::operator=(other);
    days_until_product = other.days_until_product;
    return *this;
}

Cow & Cow::operator=(Cow const & other)
{
    BarnAnimal::operator=(other);
    milked = other.milked;
    return *this;
}

Livestock & Livestock::operator=(Livestock const & other)
{
    Animal::operator=(other);
    days_fed = other.days_fed;
    fed = other.fed;
    unhappy = other.unhappy;
    sick = other.sick;
    life_state = other.life_state;
    days_unhappy = other.days_unhappy;
    days_sick = other.days_sick;
    current_outdoor_minutes = other.current_outdoor_minutes;
    total_outdoor_minutes = other.total_outdoor_minutes;
    return *this;
}
