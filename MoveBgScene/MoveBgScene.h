//
//  MoveBgScene.h
//  Test
//
//  Created by ylkj on 16/11/2.
//
//

#ifndef Test_MoveBgScene_h
#define Test_MoveBgScene_h

#include "cocos2d.h"
USING_NS_CC;

class MoveBgScene : public Layer
{
public:
    static cocos2d::Scene* createScene();
    bool init();
    CREATE_FUNC(MoveBgScene);
    
private:
    void update(float delta);
    //创建background
    void createBackground();
    
private:
    int startTime;
    //前一张背景图的指针
    Sprite* pLastBackgroundSprite;
    

};

#endif
