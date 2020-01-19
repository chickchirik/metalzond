/*

    GameLayer.hpp

    Created by <chickchirik> on 11/01/2020.

    DESCRIPTION:

*/

#pragma once

#include "cocos2d.h"
#include "Objects/Player.hpp"

USING_NS_CC;

class GameLayer : public cocos2d::Layer {
private:
    Player* player = nullptr;
public:
    static Scene* createScene();
    CREATE_FUNC(GameLayer);
    virtual bool init();
};
