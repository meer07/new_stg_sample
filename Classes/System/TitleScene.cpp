#include "TitleScene.h"
#include "UIManager.h"
#include "HelloWorldScene.h"
USING_NS_CC;

cocos2d::Scene* TitleScene::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = TitleScene::create();
    scene->addChild(layer);
    return scene;
}

bool TitleScene::init()
{
    if (!cocos2d::Layer::init())
    {
        return false;
    }
    
    cocos2d::Size windowSize = Director::getInstance()->getWinSize();
    
    /*
    UIManager *uiManager = new UIManager();
    uiManager->setTitleScene(*this);
     */
    UIManager::getIncetance().setTitleScene(*this);
    
    gameStart();
    
    return true;
}

void TitleScene::gameStart()
{
    auto listener = EventListenerTouchOneByOne::create();
    
    // タッチしたらゲームスタート
    listener->onTouchBegan = [](cocos2d::Touch *touch, cocos2d::Event *event){
        cocos2d::Scene *gameScene = HelloWorld::createScene();
        
        // フェードアウトする
        float duration = 1.0f;
        cocos2d::Scene *pScene = TransitionCrossFade::create(duration, gameScene);
        
        if (pScene) {
            Director::getInstance()->replaceScene(pScene);
        }
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}