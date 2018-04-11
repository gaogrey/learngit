//
//  MoveBgScene.cpp
//  Test
//
//  Created by ylkj on 16/11/2.
//
//

#include <stdio.h>
#include "MoveBgScene.h"

const int BG_LENGHT = 720;


Scene* MoveBgScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MoveBgScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


bool MoveBgScene::init()
{
    if(!Layer::init())
        return false;
    
    startTime = 0;
    
    createBackground();
    
    scheduleUpdate();
    
    return true;
}

void MoveBgScene::createBackground()
{
    Sprite* pBackgroundSprite = CCSprite::create("background.jpg");
    pBackgroundSprite->setAnchorPoint(Vec2(0,0));
    pBackgroundSprite->setPosition(Vec2(pLastBackgroundSprite == NULL ?
                                       0 : pLastBackgroundSprite->getPositionX() + BG_LENGHT,0));
    pLastBackgroundSprite = pBackgroundSprite;
    addChild(pBackgroundSprite);
}

void MoveBgScene::update(float delta)
{
    for(int i = 0; i < getChildren().size();i++)
    {
        Sprite* pBackground = (Sprite*)getChildren().at(i);
        //背景移动
        pBackground->setPositionX(pBackground->getPositionX() - 1);
        if(pBackground->getPositionX() + BG_LENGHT < 0)
        {
            //判断背景移除屏幕外，则删除背景文件
            removeChild(pBackground);
            i--;
        }
    }
    
    //判断是否创建添加新的背景图片
    float disLenght = Director::getInstance()->getVisibleSize().width - BG_LENGHT;
    if(pLastBackgroundSprite != NULL && (pLastBackgroundSprite->getPositionX() < disLenght))
    {
        createBackground();
    }
}