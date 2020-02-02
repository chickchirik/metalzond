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

//walls
    auto wall = Node::create();
    auto wallBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0.1f, 1.0f, 0.0f));
    wall->setPhysicsBody(wallBody);
    wall->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(wall);

    //Image will be returned instantly because file was loaded previously
    auto bgSprite = Sprite::create("gameBG.png");
    bgSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(bgSprite);

    player = new Player(visibleSize, origin);
    this->addChild(player->getSprite());
    //freeing memoray allocated for the player object
    this->setOnExitCallback([&](){
        delete player;
    });

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    this->scheduleUpdate();
    return true;
}

bool GameLayer::onTouchBegan(Touch *touch, Event *event) {
    touchLocation = touch->getLocation();
    return true;
}

void GameLayer::onTouchEnded(Touch *touch, Event *event) {
    touchLocation = Vec2::ZERO;
}

void GameLayer::update (float delta) {
    player->update(touchLocation);
}
