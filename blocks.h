#pragma once
#include "screen.h"

namespace blocks {
    const object Bomb = object('@',false,true,true,3);
    const object Wall = object('#',true,false,true);
    const object Switch = object('/',false,true,false,4);
    const object Obstacle = object('*',true,true,false,5);
}