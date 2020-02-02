/*

    Player.hpp

    Created by <chickchirik> on 12/01/2020.

    DESCRIPTION:

*/

#pragma once

#include "cocos2d.h"
#include "PhysicsShapeCache.h"
#include <string>
#include <cmath>

USING_NS_CC;

class Player {
private:
    std::string currEmotion = "happyFace";
    Sprite* playerSprite = nullptr;
    uint8_t fullHealth = 100;
    uint8_t health = 100;
    void handleInput(const Vec2& touchLocation);
    void processState();
public:
    Player(cocos2d::Size visibleSize, const Vec2& origin);
    ~Player();
    inline Sprite* getSprite() { return playerSprite; }
    void update(const Vec2& touchLocation);
};
