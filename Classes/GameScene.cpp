//
//  GameScene.cpp
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/08.
//
//

#include "GameScene.h"
#include "Boss01.h"

GameScene::GameScene()
{
    frame = 0;
    pattern = new EnemyPattern();
}

void GameScene::Scene01(cocos2d::Size windowSize)
{
    float second = frame / 60;
    frame++;
    
    if (second == 1) {
        Boss01 *boss = Boss01::create("boss01.png");
        boss->setPosition(windowSize.width/2 - boss->getTextureRect().size.width/2, windowSize.height - boss->getTextureRect().size.height/2);
        TaskManager::getInstance().AddEnemyTask(*boss);

    }
    /*
    if (second == 2)
    {
        float sceneOneEnemyParam[4] = {3, 1, 0, -1};
        float sceneOneEnemyPatternParam[4] = {90, 2, 1, 270};
        pattern->EnemyPattern01(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.height/2);
    }
    else if (second == 3)
    {
        float sceneOneEnemyParam[4] = {3, 1, 0, -1};
        float sceneOneEnemyPatternParam[4] = {90, 2, 1, 270};
        pattern->EnemyPattern01(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.height/2);
    }
    else if (second == 7)
    {
        float sceneOneEnemyParam[4] = {3, 1, 180, 1};
        float sceneOneEnemyPatternParam[4] = {90, 2, 1, 270};
        pattern->EnemyPattern02(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.height/2);
    }
    else if (second == 8)
    {
        float sceneOneEnemyParam[4] = {3, 1, 180, 1};
        float sceneOneEnemyPatternParam[4] = {90, 2, 1, 270};
        pattern->EnemyPattern02(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.height/2);
    }
    else if (second == 15)
    {
        float sceneOneEnemyParam[4] = {3, 1, 270, 0};
        float sceneOneEnemyPatternParam[4] = {100, 6, 1, 0};
        pattern->EnemyPattern05(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.width/2 - 100);
    }
     */
}

GameScene::~GameScene(){
    pattern = NULL;
    delete pattern;
}