/*

    Player.cpp

    Created by <chickchirik> on 12/01/2020.

*/

#include "Player.hpp"

Player::Player(cocos2d::Size visibleSize, const Vec2& origin)  {
    auto spriteCache = SpriteFrameCache::getInstance();
    auto playerStillFrame = spriteCache->getSpriteFrameByName("playerBody.png");
    playerSprite = Sprite::createWithSpriteFrame(playerStillFrame);

    auto playerSize = playerSprite->getContentSize();
    playerSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height - playerSize.height + origin.y));
    playerSprite->setScale(0.5);

    auto shapeCache = PhysicsShapeCache::getInstance();
    shapeCache->setBodyOnSprite("playerBody", playerSprite);

    /*  get all sprite frames and set them to player instance   */
    for (auto spriteEntry : spriteCache->getSpriteFrames()) { /*    invoking custom written sprite frames getter (see CCSpriteFrameCache.h) */
        std::string spriteFileName = spriteEntry.first;
        std::string spriteName = spriteFileName.substr(0, spriteFileName.rfind("."));
        auto newSprite = Sprite::createWithSpriteFrame(spriteEntry.second);
        auto newSpriteSize = newSprite->getContentSize();
        /*  sprite frames invisible by default */
        newSprite->setVisible(false);
        if (spriteName.find("Left") != -1) {            /*  set jet fire sprite for left jet    */
            newSprite->setPosition(Vec2(newSpriteSize.width / 2.5, -newSpriteSize.height / 5));
            playerSprite->addChild(newSprite, -1, spriteName);
        } else if (spriteName.find("Right") != -1) {    /*  set jet fire sprite for right jet   */
            newSprite->setPosition(Vec2(playerSize.width - newSpriteSize.width / 2.5, -newSpriteSize.height / 5));
            playerSprite->addChild(newSprite, -1, spriteName);
        } else {                                        /*  set faces   */
            newSprite->setPosition(Vec2(playerSize.width / 2, playerSize.height / 2.5));
            newSprite->setScale(1.5);
            playerSprite->addChild(newSprite, 1, spriteName);
        }
    }
    playerSprite->getChildByName("happyFace")->setVisible(true); /* start with happy face on    */
}

Player::~Player() {}

void Player::handleInput(const Vec2& touchLocation) {
    if (touchLocation == Vec2::ZERO) {  /*  treat zero touch location as no input   */
        playerSprite->getChildByName("jetFireLeft")->setVisible(false);
        playerSprite->getChildByName("jetFireRight")->setVisible(false);
        return;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto playerSize = playerSprite->getContentSize();
    auto body = playerSprite->getPhysicsBody();
    if (touchLocation.x < visibleSize.width / 2) {      /*  touching left side of the screen invokes left jet fire impulse      */
        body->applyImpulse(Vec2(100, 1500), Vec2(-playerSize.width, -playerSize.height));
        playerSprite->getChildByName("jetFireLeft")->setVisible(true);
    } else {                                            /*  touching right side of the screen invokes right jet fire impulse    */
        body->applyImpulse(Vec2(-100, 1500), Vec2(playerSize.width, -playerSize.height));
        playerSprite->getChildByName("jetFireRight")->setVisible(true);
    }
    /*  give forward impulse bt default     */
    body->applyImpulse(Vec2(-1, 9500));
}

void Player::processState() {
    std::string prevEmotion = currEmotion;
    currEmotion = "happyFace";
    /*  checking for scared face    */
    if (health < fullHealth*0.5) { currEmotion = "scaredFace"; }
    /*  checking for surprised face */
    float playerRotation = (-playerSprite->getPhysicsBody()->getRotation() + 90) * M_PI / 180.0; /* cocos2d returns degrees, need to convert to radians */
    float sineValue = std::sin(playerRotation);
    if (sineValue >= -1 && sineValue <= 0) { currEmotion = "surprisedFace"; }   /*  if player is upside down - set surprised face   */
    /*  setting updated face emotion    */
    playerSprite->getChildByName(prevEmotion)->setVisible(false);
    playerSprite->getChildByName(currEmotion)->setVisible(true);
}

void Player::update(const Vec2& touchLocation) {
    this->handleInput(touchLocation);
    this->processState();
}
