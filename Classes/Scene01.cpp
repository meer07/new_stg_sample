//
//  Scene01.cpp
//  SimpleSTG
//
//  Created by 海下 直哉 on 2015/02/03.
//
//

#include "Scene01.h"
#include "Enemy01.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"
#include "MidEnemy01.h"
#include "Boss01.h"
#include "Bullet.h"
#include "PlayerBullet.h"

void Scene01::Init(cocos2d::Layer &layer)
{
    taskManager = new TaskManager();
    frame = 0;
    taskManager->objectContainer.reserve(500);
    
    int i = 0;
    while (i < 200) {
        if (i < 5) {
            PushEnemy(layer);
        }
        PushBullet(layer);
    }
    
    auto boss = Boss01::create("boss01.png");
    layer.addChild(boss);
    taskManager->objectContainer.push_back(boss);
}

void Scene01::RunScene()
{
    frame++;
    
    if (frame == 60)
    {
        
    }
    else if ((frame > 60*2 && frame < 60*180) && frame % (60*5) == 0.0f)
    {
        // 3秒に一回
    }
}

void Scene01::PushEnemy(cocos2d::Layer &layer)
{
    float enemyParam[4] = {0,0,0,0};
    float shotParam[3] = {0,0,0};

    auto enemy = Enemy01::create(enemyParam, shotParam, "enemy.png");
    auto enemy02 = Enemy02::create(enemyParam, shotParam, "enemy02.png");
    auto enemy03 = Enemy03::create(enemyParam, shotParam, "enemy03.png");
    auto enemy04 = Enemy04::create(enemyParam, shotParam, "enemy04.png");
    auto enemy05 = MidEnemy01::create(enemyParam, shotParam, "midenemy01.png");
    
    Mover* moverlist[] = {enemy, enemy02, enemy03, enemy04, enemy05};
    for (int i = 0; i < 5; i++) {
        layer.addChild(moverlist[i]);
        moverlist[i]->setVisible(false);
        taskManager->objectContainer.push_back(moverlist[i]);
    }
}

void Scene01::PushBullet(cocos2d::Layer &layer)
{
    float shotParam[3] = {0,0,0};
    auto enemyBullet = Bullet::create(shotParam, "enemy_bullet01.png");
    auto playerBullet = PlayerBullet::create(0, 0, 0, "enemy_bullet02.png");
    Mover* moverlist[] = {enemyBullet, playerBullet};
    
    for (int i = 0; i < 2; i++) {
        layer.addChild(moverlist[i]);
        taskManager->objectContainer.push_back(moverlist[i]);
    }
}