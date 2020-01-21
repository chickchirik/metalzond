/*

    Player.cpp

    Created by <chickchirik> on 12/01/2020.

    DESCRIPTION:

*/

#include "Player.hpp"

Player::Player(cocos2d::Size visibleSize)  {
    auto spriteCache = SpriteFrameCache::getInstance();
    spriteCache->addSpriteFramesWithFile("player.plist");
    auto playerStillFrame = spriteCache->getSpriteFrameByName("still/metalzond.png");
    playerSprite = Sprite::createWithSpriteFrame(playerStillFrame);

    auto playerSize = playerSprite->getContentSize();
    playerSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - playerSize.height));
    playerSprite->setScale(0.5);

    auto shapeCache = PhysicsShapeCache::getInstance();
    shapeCache->setBodyOnSprite("metalzond", playerSprite);
}

Player::~Player() {}
