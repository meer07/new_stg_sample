#include "BackGround.h"
#include <iostream>

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
	cocos2d::log("%f", backgrounds[0]->getTextureRect().size.height);
	cocos2d::log("%f", windowSize.height);

    for (int i = 0; i < 2; i++)
    {
        cocos2d::Point point = backgrounds[i]->getPosition();
		// スクロールする
		backgrounds[i]->setPosition(point.x, point.y + speedRate);

		if (point.y <= -1024)
		{
			// 上まで戻す
			backgrounds[i]->setPosition(windowSize.width / 2, windowSize.height);
		}
    }
}

BackGround::~BackGround(){}