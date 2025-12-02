#pragma once
#include "Screen.h"

namespace Blocks {
    //added to copy default blocks with copy constructor
    const object Bomb = object('@',false,true,true,3);
    const object Wall = object('#',true,false,true);
    const object Switch = object('/',false,true,false,4); // '\' when "on" state
    const object Obstacle = object('*',true,true,false,5);
    const object Air = object(' ',false,false,false);
}
