//
//  GameScene.cpp
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/08.
//
//

#include "GameScene.h"
#include "GameData.h"
#include "UIManager.h"
#include "TaskManager.h"
#include "Boss01.h"
#include "Boss02.h"
#include <random>

GameScene::GameScene()
{
    pattern = new EnemyPattern();
}

void GameScene::Scene01(cocos2d::Size windowSize)
{
    float second = GameData::getInstance().frame / 60;
    GameData::getInstance().frame++;
    if (second == 1) {
        UIManager::getIncetance().setLevelLabel(1, *TaskManager::getInstance().sceneLayer);
    }
    else if (second == 10)
    {
        Pattern03(windowSize.width / 5);
    }
    else if (second == 11)
    {
        Pattern03(windowSize.width * 2 / 5);
    }
    else if (second == 16)
    {
        Pattern03(windowSize.width * 3 / 5);
    }
    else if (second == 17)
    {
        Pattern03(windowSize.width * 4 / 5);
    }
    else if (second == 25 || second == 31 || second == 38) {
        Pattern03(windowSize.width / 5);
    }
    else if (second == 26 || second == 32 || second == 37)
    {
        Pattern03(windowSize.width * 4 / 5);
    }
    else if (second == 27 || second == 30 || second == 39)
    {
        Pattern03(windowSize.width / 2);
    }
    else if (second == 45 || second == 90)
    {
        float sceneOneEnemyParam[4] = {3, 0, 270, 0};
        float sceneOneEnemyPatternParam[4] = {100, 6, 1};
        pattern->EnemyPattern05(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.width/2 - 100);
    }
    else if (((second >= 55 && second <= 65) || (second >= 70 && second <= 80)) && static_cast<int>(GameData::getInstance().frame) % 60 == 0)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> randomPoint(1,5);
        
        Pattern04((windowSize.width * randomPoint(mt))/ 6);
    }
    else if (second == 100)
    {
        for (int i = 1; i < 3; i++) {
            Pattern03(windowSize.width * (5-i) / 5);
        }
        Pattern05(windowSize.height / 2);
    }
    else if (second == 101 || second == 102 || second == 103 || second == 104)
    {
        Pattern05(windowSize.height / 2);
    }
    else if (second == 110 || second == 111 || second == 112 || second == 113)
    {
        Pattern06(windowSize.height / 2);
    }
    else if (second == 109)
    {
        for (int i = 1; i < 3; i++) {
            Pattern03(windowSize.width * i / 5);
        }
        Pattern06(windowSize.height / 2);
    }
    else if (second == 115) // warning!!
    {
    }
    else if (second == 130) // ボス
    {
        std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("boss01.png");
        Boss01 *boss = Boss01::create(fullpath);
        boss->setPosition(windowSize.width/2 - boss->getTextureRect().size.width/2, windowSize.height - boss->getTextureRect().size.height/2);
        TaskManager::getInstance().AddEnemyTask(*boss);
    }
    else if (second >= 130)
    {
        if (static_cast<int>(GameData::getInstance().frame) % 120 == 0) {
            Pattern03(windowSize.width / 5);
            Pattern03(windowSize.width * 4 / 5);
        }
        
        if (GameData::getInstance().stageClear01) {
            // ステージクリア
            GameData::getInstance().nowStage = 2;
            GameData::getInstance().frame = 0;
        }
    }
}

void GameScene::Scene02(cocos2d::Size windowSize)
{
    float second = GameData::getInstance().frame / 60;
    GameData::getInstance().frame++;
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
        Boss02 *boss = Boss02::create("boss02.png");
        boss->setPosition(windowSize.width/2 - boss->getTextureRect().size.width/2, windowSize.height - boss->getTextureRect().size.height/2);
        TaskManager::getInstance().AddEnemyTask(*boss);
    }
}


void GameScene::Pattern01(cocos2d::Size windowSize)
{
    float sceneOneEnemyParam[4] = {3, 0, 0, -1};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern01(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.height/2);
}

void GameScene::Pattern02(cocos2d::Size windowSize)
{
    float sceneOneEnemyParam[4] = {3, 0, 180, 1};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern02(sceneOneEnemyParam, sceneOneEnemyPatternParam, windowSize.height/2);
}

void GameScene::Pattern03(float pointX)
{
    float sceneOneEnemyParam[4] = {6, -0.05f, 270, 0};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern04(sceneOneEnemyParam, sceneOneEnemyPatternParam, pointX);
}

void GameScene::Pattern04(float pointX)
{
    float sceneOneEnemyParam[4] = {3, 0, 270, 0};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern06(sceneOneEnemyParam, sceneOneEnemyPatternParam, pointX);
}

void GameScene::Pattern05(float pointY)
{
    float sceneOneEnemyParam[4] = {3, 0, 0, 0};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern07(sceneOneEnemyParam, sceneOneEnemyPatternParam, pointY);
}

void GameScene::Pattern06(float pointY)
{
    float sceneOneEnemyParam[4] = {3, 0, 180, 0};
    float sceneOneEnemyPatternParam[4] = {90, 2, 1};
    pattern->EnemyPattern08(sceneOneEnemyParam, sceneOneEnemyPatternParam, pointY);
}

GameScene::~GameScene(){
    pattern = NULL;
    delete pattern;
}