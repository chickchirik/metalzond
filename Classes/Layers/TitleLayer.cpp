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

void TitleLayer::onEnterTransitionDidFinish() {
    // game assets here loading will be here
    this->scheduleOnce([&](float d){
        auto nextScene  = GameLayer::createScene();
        auto transition = TransitionFade::create(1.0f, nextScene);
        Director::getInstance()->replaceScene(transition);
    }, 0.5f, "TitleToGameTransition");
}
