/*

    Player.hpp

    Created by <chickchirik> on 12/01/2020.

    DESCRIPTION:
    metalzond player class used in game scene. It handles player's input
    and processes player state.
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
    /*  temporary health placeholder    */
    uint8_t fullHealth = 100;
    uint8_t health = 100;
    void handleInput(const Vec2& touchLocation);    /*  affects on player physics body based on the input and sets fire sprites */
    void processState();                            /*  checks player current state and sets proper sprite based on it          */
public:
    Player(cocos2d::Size visibleSize, const Vec2& origin);
    ~Player();
    inline Sprite* getSprite() { return playerSprite; }
    void update(const Vec2& touchLocation); /* update method is invoked every frame by the game scene */
};
