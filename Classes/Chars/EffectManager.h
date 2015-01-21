//
//  EffectManager.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/21.
//
//

#ifndef __Getsuyoubi__EffectManager__
#define __Getsuyoubi__EffectManager__

#include <cocos2d.h>
#include "Mover.h"

class EffectManager {
public:
    static EffectManager& getInstance();
    EffectManager();
    EffectManager(const EffectManager &other){}
    EffectManager &operator=(const EffectManager &other){}
    
    ~EffectManager();
    cocos2d::Animate* DestroyEffect();
};
#endif /* defined(__Getsuyoubi__EffectManager__) */
