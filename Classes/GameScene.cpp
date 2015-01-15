//
//  GameScene.cpp
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/08.
//
//

#include "GameScene.h"
#include "GameData.h"
#include "Boss01.h"

GameScene::GameScene()
{
    frame = 0;
    pattern = new EnemyPattern();
    ui = new UIManager();
}

void GameScene::Scene01(cocos2d::Size windowSize)
{
    float second = frame / 60;
    frame++;
    /*
    if (second == 10 || second == 11 || second == 12 || second == 13 || second == 84 ||second == 85)
    {
        Pattern01(windowSize);
    }
    else if (second == 20 || second == 21 || second == 22 || second == 23 || second == 92 || second == 93)
    {
        Pattern02(windowSize);
    }
    else if (second == 28 || second == 29 || second == 30 || second == 31)
    {
        Pattern01(windowSize);
        Pattern02(windowSize);
    }
    else if (second == 45 || second == 54 || second == 57 || second == 64)
    {
        Pattern03(windowSize.width/6);
    }
    else if (second == 46 || second == 53 || second == 55 || second == 63)
    {
        Pattern03(windowSize.width/2);
    }
    else if (second == 47 || second == 52 || second == 56 || second == 62)
    {
        Pattern03(windowSize.width*5/6);
    }
    else if (second == 82)
    {
        Pattern01(windowSize);
        Pattern03(windowSize.width*5/6);
    }
    else if (second == 83)
    {
        Pattern01(windowSize);
        Pattern03(windowSize.width/2);
    }
    else if (second == 90)
    {
        Pattern02(windowSize);
        Pattern03(windowSize.width/6);
    }
    else if (second == 91)
    {
        Pattern02(windowSize);
        Pattern03(windowSize.width/2);
    }
    else if (second == 35 || second == 72 || second == 120)
    {
        float sceneOneEnemyParam[4] = {3, 1, 270, 0};
        float sceneOneEnemyPatternParam[4] = {100, 6, 1};
        pattern->EnemyPattern05(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.width/2 - 100);
    }
    else if (second == 150)
    {
        Boss01 *boss = Boss01::create("boss01.png");
        boss->setPosition(windowSize.width/2 - boss->getTextureRect().size.width/2, windowSize.height - boss->getTextureRect().size.height/2);
        TaskManager::getInstance().AddEnemyTask(*boss);
    }
    */
    
    if (second == 1)
    {
        Boss01 *boss = Boss01::create("boss01.png");
        boss->setPosition(windowSize.width/2 - boss->getTextureRect().size.width/2, windowSize.height - boss->getTextureRect().size.height/2);
        TaskManager::getInstance().AddEnemyTask(*boss);
    }

}

void GameScene::Pattern01(cocos2d::Size windowSize)
{
    float sceneOneEnemyParam[4] = {3, 1, 0, -1};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern01(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.height/2);
}

void GameScene::Pattern02(cocos2d::Size windowSize)
{
    float sceneOneEnemyParam[4] = {3, 1, 180, 1};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern02(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.height/2);
}

void GameScene::Pattern03(float pointX)
{
    float sceneOneEnemyParam[4] = {3, 1, 270, 0};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern04(sceneOneEnemyParam, sceneOneEnemyPatternParam, pointX);
}


GameScene::~GameScene(){
    pattern = NULL;
    ui = NULL;
    
    delete pattern;
    delete ui;
}