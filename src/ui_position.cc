#include "ui_position.hh"

void UiPosition::Set(u32 x, u32 y)
{
    this->x = x;
    this->y = y;
}

void UiPosition::Offset(u32 dx, u32 dy)
{
    x += dx;
    y += dy;
}
