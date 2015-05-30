#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "BaseScene.h"
#include "ui/CocosGUI.h"
#include "MenuTextButton.h"
#include "GameEngineIncludes.h"

using namespace cocos2d::ui;

#pragma once
class MenuScene : public BaseScene
{
protected:
  
  virtual void onEscapeKeyPressed();

  MenuScene(GameContext* gameContext, bool showSplashScreen)
    : BaseScene(gameContext, showSplashScreen)
  {

  }

public:
  ~MenuScene(){}

  virtual void onEnter() override;

  static MenuScene *create(GameContext* gameContext, bool showSplashScreen);
};

#endif  // __MENU_SCENE_H__