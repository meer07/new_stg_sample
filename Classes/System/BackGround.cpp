//
//  BackGround.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/16.
//
//

#include "BackGround.h"

BackGround::BackGround(cocos2d::Size windowSize_, cocos2d::Layer &sceneLayer)
{
    std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("background.png");
    auto batchNode = cocos2d::SpriteBatchNode::create("background.png");
    sceneLayer.addChild(batchNode);
    windowSize = windowSize_;
    backGround_f = Sprite::createWithTexture(batchNode->getTexture());
    backGround_b = Sprite::createWithTexture(batchNode->getTexture());
    backGround_f->setPosition(windowSize.width/2, 0);
    backGround_b->setPosition(windowSize.width/2, windowSize.height);
    
    sceneLayer.addChild(backGround_f);
    sceneLayer.addChild(backGround_b);
}

void BackGround::Move(float speedRate)
{
    cocos2d::Sprite* backgrounds[2] = {backGround_f, backGround_b};
    
    for (int i = 0; i < 2; i++)
    {
        cocos2d::Point point = backgrounds[i]->getPosition();
        if (point.y < -backgrounds[0]->getTextureRect().size.height)
        {
            // 上まで戻す
            backgrounds[i]->setPosition(point.x, windowSize.height);
        }
        else
        {
            // スクロールする
            backgrounds[i]->setPosition(point.x, point.y+speedRate);
        }
    }
}

BackGround::~BackGround(){}