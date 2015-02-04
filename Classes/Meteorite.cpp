#include "Meteorite.h"

Meteorite* Meteorite::create(const float enemyParam[], std::string fileName)
{
    Meteorite *meteorite = new Meteorite();
    
    meteorite->hitpoint = 4;
    meteorite->score = 100;
    meteorite->speed = enemyParam[0];
    meteorite->speedRate = enemyParam[1];
    meteorite->angle = enemyParam[2];
    meteorite->angleRate = enemyParam[3];
    meteorite->isAlive = true;
    meteorite->setTag(4);
    meteorite->setName("Meteorite");
    
    if (meteorite && meteorite->initWithSpriteFrameName(fileName)) {
        meteorite->autorelease();
        meteorite->retain();
        
        return meteorite;
    }
    
    CC_SAFE_DELETE(meteorite);
    
    return NULL;
}

void Meteorite::Move()
{
    MoveBase();
    Destroy();
}

void Meteorite::Destroy()
{
    Mover::Destroy();
}
