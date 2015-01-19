#include "HelloWorldScene.h"
#include "../cocos2d/cocos/editor-support/cocostudio/CocoStudio.h"
#include "Player.h"
#include "TaskManager.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    windowSize = Director::getInstance()->getWinSize();
    TaskManager::getInstance().sceneLayer = this;
    
    //background = new BackGround(windowSize, *this);
    //setUI();
    PlayerSet(windowSize);
    
    gameScene = new GameScene();

    this->scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float frame)
{
    TaskManager::getInstance().player->Move();
    
    switch (nowStage) {
        case 1:
            gameScene->Scene01(windowSize);
            break;
            
        default:
            break;
    }
    
    //background->Move(-0.5);
    TaskManager::getInstance().DoTask(TaskManager::getInstance().enemyManager, *this);
    TaskManager::getInstance().DoTask(TaskManager::getInstance().bulletManager, *this);
    TaskManager::getInstance().DoTask(TaskManager::getInstance().playerBulletManager, *this);
}

void HelloWorld::PlayerSet(Size windowSize)
{
    TaskManager::getInstance().player = Player::create(this);
    TaskManager::getInstance().player->setPosition(windowSize.width/2, windowSize.height/2);
    this->addChild(TaskManager::getInstance().player);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setEnabled(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::setUI()
{
    UINode = CSLoader::getInstance()->createNode("MainScene.csb");
    this->addChild(UINode);
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
    
    startPoint = touch->getLocation();
    return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
    Size windowSize = Director::getInstance()->getWinSize();
    
    endPoint = touch->getLocation();
    float tempX = endPoint.x - startPoint.x;
    float tempY = endPoint.y - startPoint.y;
    
    Point playerPoint = TaskManager::getInstance().player->getPosition();
    Size playerSize = TaskManager::getInstance().player->getTextureRect().size;
    Point newPoint = Vec2(playerPoint.x + tempX, playerPoint.y + tempY);
    if ((newPoint.x >  playerSize.width/2 && newPoint.y > playerSize.height/2) && (newPoint.x < windowSize.width - playerSize.width/2 && newPoint.y < windowSize.height - playerSize.height/2))
    {
        TaskManager::getInstance().player->setPosition(newPoint);
        startPoint = endPoint;
    }
}