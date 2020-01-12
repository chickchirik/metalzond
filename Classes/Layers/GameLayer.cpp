/*

    GameLayer.cpp

    Created by <chickchirik> on 11/01/2020.

    DESCRIPTION:

*/

#include "Layers/GameLayer.hpp"

Scene* GameLayer::createScene() {
    auto scene = Scene::create();
    auto layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameLayer::init() {
    if (!Layer::init()) { return false; }
    auto director = Director::getInstance();
    auto visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    auto logoSprite = Sprite::create("chickchirikMobileLogo.jpg");
    logoSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(logoSprite, 0);

    auto testlabel = Label::createWithTTF("TEST LABEL", "fonts/arial.ttf", 36);
    testlabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(testlabel, 1);
    return true;
}
