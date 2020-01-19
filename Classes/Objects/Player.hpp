/*

    Player.hpp

    Created by <chickchirik> on 12/01/2020.

    DESCRIPTION:

*/

#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Player {
private:
    Sprite* playerSprite = nullptr;
public:
    Player(Size visibleSize);
    ~Player();
    inline Sprite* getSprite() { return playerSprite; }
};
