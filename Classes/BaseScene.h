#ifndef __BASE_SCENE_H__
#define __BASE_SCENE_H__

#include "cocos2d.h"
#include "GameEngineIncludes.h"

using namespace cocos2d;

#pragma once
class BaseScene : public Scene
{
protected:
  bool m_showSplashScreen;
  bool m_isLayoutInitialized;

#if IS_DEBUG
  DebugDraw* m_debugDraw;
#endif

  GameContext* m_pGameContext;

  void hideSplashScreen();

public:
  BaseScene(GameContext* gameContext, bool showSplashScreen)
    : m_showSplashScreen(showSplashScreen)
#if IS_DEBUG
    , m_debugDraw(NULL)
#endif
    , m_isLayoutInitialized(false)
  {
    this->m_pGameContext = gameContext;

#if IS_DEBUG
    if (!m_debugDraw)
    {
      m_debugDraw = DebugDraw::create();
      this->addChild(m_debugDraw, 1000);
    }
#endif
  }

  ~BaseScene()
  {
    this->m_pGameContext = NULL;
  }

  virtual void onEscapeKeyPressed() { /* can be overridden */ }
};

#endif  // __BASE_SCENE_H__