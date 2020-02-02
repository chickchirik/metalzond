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

    for (auto spriteEntry : spriteCache->getSpriteFrames()) {
        std::string spriteFileName = spriteEntry.first;
        std::string spriteName = spriteFileName.substr(0, spriteFileName.rfind("."));
        auto newSprite = Sprite::createWithSpriteFrame(spriteEntry.second);
        auto newSpriteSize = newSprite->getContentSize();
        newSprite->setVisible(false);
        if (spriteName.find("Left") != -1) {
            newSprite->setPosition(Vec2(newSpriteSize.width / 2.5, -newSpriteSize.height / 5));
            playerSprite->addChild(newSprite, -1, spriteName);
        } else if (spriteName.find("Right") != -1) {
            newSprite->setPosition(Vec2(playerSize.width - newSpriteSize.width / 2.5, -newSpriteSize.height / 5));
            playerSprite->addChild(newSprite, -1, spriteName);
        } else {
            newSprite->setPosition(Vec2(playerSize.width / 2, playerSize.height / 2.5));
            newSprite->setScale(1.5);
            playerSprite->addChild(newSprite, 1, spriteName);
        }
    }
    playerSprite->getChildByName("happyFace")->setVisible(true);
}

Player::~Player() {}

void Player::handleInput(const Vec2& touchLocation) {
    if (touchLocation == Vec2::ZERO) {
        playerSprite->getChildByName("jetFireLeft")->setVisible(false);
        playerSprite->getChildByName("jetFireRight")->setVisible(false);
        return;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto playerSize = playerSprite->getContentSize();
    auto body = playerSprite->getPhysicsBody();
    if (touchLocation.x < visibleSize.width / 2) {
        body->applyImpulse(Vec2(100, 1500), Vec2(-playerSize.width, -playerSize.height));
        playerSprite->getChildByName("jetFireLeft")->setVisible(true);
    } else {
        body->applyImpulse(Vec2(-100, 1500), Vec2(playerSize.width, -playerSize.height));
        playerSprite->getChildByName("jetFireRight")->setVisible(true);
    }
    body->applyImpulse(Vec2(-1, 9500));
}

void Player::processState() {
    std::string prevEmotion = currEmotion;
    currEmotion = "happyFace";
    if (health < fullHealth*0.5) { currEmotion = "scaredFace"; }
    playerSprite->getChildByName(prevEmotion)->setVisible(false);
    playerSprite->getChildByName(currEmotion)->setVisible(true);
}

void Player::update(const Vec2& touchLocation) {
    this->handleInput(touchLocation);
    this->processState();
}
