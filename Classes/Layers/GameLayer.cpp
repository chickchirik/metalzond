/*

    GameLayer.cpp

    Created by <chickchirik> on 11/01/2020.

    DESCRIPTION:

*/

#include "Layers/GameLayer.hpp"

Scene* GameLayer::createScene() {
    auto scene = Scene::createWithPhysics();
    auto layer = GameLayer::create();
    scene->addChild(layer);
    PhysicsWorld* world = scene->getPhysicsWorld();
    world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    world->setGravity(Vec2(0, -16.2f));
    return scene;
}

bool GameLayer::init() {
    if (!Layer::init()) { return false; }
    auto director = Director::getInstance();
    auto visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();
    return true;
}
