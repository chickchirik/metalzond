/*

    Player.cpp

    Created by <chickchirik> on 12/01/2020.

    DESCRIPTION:

*/

#include "Player.hpp"

Player::Player(cocos2d::Size visibleSize)  {
    auto spriteCache = SpriteFrameCache::getInstance();
    auto playerStillFrame = spriteCache->getSpriteFrameByName("playerBody.png");
    playerSprite = Sprite::createWithSpriteFrame(playerStillFrame);

    auto playerSize = playerSprite->getContentSize();
    playerSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - playerSize.height));
    playerSprite->setScale(0.5);

    auto shapeCache = PhysicsShapeCache::getInstance();
    shapeCache->setBodyOnSprite("playerBody", playerSprite);
}

Player::~Player() {}

void Player::fireJet(const Vec2& touchLocation) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto playerSize = playerSprite->getContentSize();
    auto body = playerSprite->getPhysicsBody();
    if (touchLocation.x < visibleSize.width / 2) {
        body->applyImpulse(Vec2(-1, 10000));    //temporary
    } else {
        body->applyImpulse(Vec2(1, 10000));     //temporary
    }
}
