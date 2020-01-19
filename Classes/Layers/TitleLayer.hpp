/*

    TitleLayer.hpp

    Created by <chickchirik> on 16/01/2020.

    DESCRIPTION:

*/

#pragma once

#include "cocos2d.h"
#include "Layers/GameLayer.hpp"

USING_NS_CC;

class TitleLayer : public cocos2d::Layer {
public:
    static Scene* createScene();
    CREATE_FUNC(TitleLayer);
    virtual bool init();
    virtual void onEnterTransitionDidFinish();
};
