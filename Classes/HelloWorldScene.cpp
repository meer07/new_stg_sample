#include "HelloWorldScene.h"
#include "Player.h"
#include "GameData.h"
#include "TaskManager.h"
#include "UIManager.h"

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
    
    // スプライトシートをキャッシュ
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites.plist");

    windowSize = Director::getInstance()->getWinSize();
    
    
    background = new BackGround(windowSize, *this);
    
    GameData::getInstance()->init();
    UIManager::getIncetance().SetGameScene(*this);
    PlayerSet(windowSize);
    this->scheduleUpdate();
    
    return true;
}

// ゲームループ
void HelloWorld::update(float frame)
{
}

// 自機の設定をします
void HelloWorld::PlayerSet(Size windowSize)
{
    TaskManager::player = Player::create(this);
    TaskManager::player->setPosition(windowSize.width/2, windowSize.height/2);
    this->addChild(TaskManager::player);
    
    // タッチ(クリックとドラッグ)のためのイベントリスナーを設定
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setEnabled(true);
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    
    // イベントリスナーを適用
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

// クリックしたとき
bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
    // クリックした座標を取得
    startPoint = touch->getLocation();
    return true;
}

// ドラッグしたとき
void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
    Size windowSize = Director::getInstance()->getWinSize();
    // ドラッグしたときの座標を取得
	endPoint = touch->getLocation();

	// クリックした座標との差異を計算
    float tempX = endPoint.x - startPoint.x;
    float tempY = endPoint.y - startPoint.y;
    
	// 移動先の座標を計算
    Point playerPoint = TaskManager::player->getPosition();
    Point newPoint = Vec2(playerPoint.x + tempX, playerPoint.y + tempY);

	// 自機が画面をはみ出していなければ移動
	Size playerSize = TaskManager::player->getTextureRect().size;
    if ((newPoint.x >  playerSize.width/2 && newPoint.y > playerSize.height/2) && (newPoint.x < windowSize.width - playerSize.width/2 && newPoint.y < windowSize.height - playerSize.height/2))
    {
        TaskManager::player->setPosition(newPoint);
        startPoint = endPoint;
    }
    
    TaskManager::player->positionId = newPoint.y/512;
}