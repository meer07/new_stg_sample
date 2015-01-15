//
//  GameData.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/14.
//
//

#ifndef __Getsuyoubi__GameData__
#define __Getsuyoubi__GameData__

class GameData {
public:
    static GameData& getInstance();
    int score;
    int playerHp;
    
    GameData();
    GameData(const GameData &other){}
    GameData &operator = (const GameData &other){}
    
    void ShowScore(cocos2d::Size windowSize);
};
#endif /* defined(__Getsuyoubi__GameData__) */
