#ifndef __LOAD_GAME_SCENE_H__
#define __LOAD_GAME_SCENE_H__

#include "cocos2d.h"
#include "GameEngineIncludes.h"
#include "BaseScene.h"
#include "BaseFileUtils.h"

class LoadGameScene : public BaseScene
{
private:

  bool m_isLayoutInitialized;

  LoadGameScene(GameContext* pGameContext)
    : BaseScene(pGameContext, true)
    , m_isLayoutInitialized(false)
  { }

public:
  
  ~LoadGameScene() { }

  static LoadGameScene *create(GameContext* gameContext);

  void onEnter() override;
  void loadGame(float delta);

};

#endif  // __LOAD_GAME_SCENE_H__