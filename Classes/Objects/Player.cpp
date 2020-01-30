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

void Player::handleInput(const Vec2& touchLocation) {
    if (touchLocation == Vec2::ZERO) { return; }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto playerSize = playerSprite->getContentSize();
    auto body = playerSprite->getPhysicsBody();
    if (touchLocation.x < visibleSize.width / 2) {
        body->applyImpulse(Vec2(100, 1500), Vec2(-playerSize.width, -playerSize.height));
    } else {
        body->applyImpulse(Vec2(-100, 1500), Vec2(playerSize.width, -playerSize.height));
    }
    body->applyImpulse(Vec2(-1, 9500));
}

void Player::update(const Vec2& touchLocation) {
    this->handleInput(touchLocation);
}
