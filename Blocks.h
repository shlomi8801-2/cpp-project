#pragma once
#include "Screen.h"

namespace Blocks
{
    // added to copy default blocks with copy constructor
    const Object Bomb = Object('@', false, true, true, 3);
    const Object Wall = Object('#', true, false, true);
    const Object Switch = Object('/', false, false, true, 4); // '\' when "on" state
    const Object Obstacle = Object('*', true, false, true, 5);
    const Object Air = Object(' ', false, false, false);
    const Object Door = Object(' ', true,false,true,1); // need to set door id and sprite - generate does it automatically
    const Object Key = Object('K', true,false,true,2); //need to set keyId
}