/*

    TitleLayer.cpp

    Created by <chickchirik> on 16/01/2020.

    DESCRIPTION:

*/

#include "Layers/TitleLayer.hpp"

Scene* TitleLayer::createScene() {
    auto scene = Scene::create();
    auto layer = TitleLayer::create();
    scene->addChild(layer);
    return scene;
}

bool TitleLayer::init() {
    if (!Layer::init()) { return false; }
    auto director = Director::getInstance();
    auto visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();
    auto titleSprite = Sprite::create("chickchirikMobileLogo.png");
    titleSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(titleSprite);
    return true;
}