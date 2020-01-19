/*

    Player.cpp

    Created by <chickchirik> on 12/01/2020.

    DESCRIPTION:

*/

#include "Player.hpp"

Player::Player(Size visibleSize)  {
    auto spriteCache = SpriteFrameCache::getInstance();
    spriteCache->addSpriteFramesWithFile("player.plist");
    auto playerStillFrame = spriteCache->getSpriteFrameByName("still/metalzond.png");
    playerSprite = Sprite::createWithSpriteFrame(playerStillFrame);

    auto playerSize = playerSprite->getContentSize();
    playerSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - playerSize.height));
    auto physicsBody = PhysicsBody::createCircle(playerSize.width / 2);
    physicsBody->setDynamic(true);
    playerSprite->setPhysicsBody(physicsBody);
}

Player::~Player() {}
