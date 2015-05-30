#ifndef __NAVIGATION_MANAGER_H__
#define __NAVIGATION_MANAGER_H__

#include "cocos2d.h"
#include "GameConstants.h"
#include "Types.h"
#include "GameContext.h"

class NavigationManager
{
private:

  static cocos2d::CCScene* resetGameContextScene(SceneType sceneType, GameContext* gameContext, bool showSplashScreen);
  
public:

  NavigationManager() { }
  ~NavigationManager() { }
  
  static void showParagraph(GameContext* gameContext, std::string filename);
  static void showMainMenu(GameContext* gameContext, SceneRenderMode sceneRenderMode, bool showSplashScreen);
  static void showScene(SceneType sceneType, GameContext* gameContext, SceneRenderMode sceneRenderMode, bool showSplashScreen);

};

#endif  // __NAVIGATION_MANAGER_H__