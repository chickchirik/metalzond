/*

    GameLayer.hpp

    Created by <chickchirik> on 11/01/2020.

    DESCRIPTION:

*/

#pragma once

#include "cocos2d.h"
#include "Objects/Player.hpp"
#include "PhysicsShapeCache.h"

USING_NS_CC;

class GameLayer : public cocos2d::Layer {
private:
    Player* player = nullptr;
    bool isPressed = false;
    Vec2 touchLocation = Vec2::ZERO;
public:
    static Scene* createScene();
    CREATE_FUNC(GameLayer);
    virtual bool init();
    virtual bool onTouchBegan(Touch *touch, Event *event);
    virtual void onTouchEnded(Touch *touch, Event *event);
    virtual void update (float delta);
};
