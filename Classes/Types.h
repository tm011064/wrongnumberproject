#ifndef __TYPES_H__
#define __TYPES_H__

#include "cocos2d.h"

using namespace cocos2d;

enum SceneType
{
  MENU_SCENE = 0,
  LOAD_GAME_SCENE = 1,
  PARAGRAPH_SCENE = 2,
};

enum SceneState
{
  RUNNING_SEQUENCE_ANIMATION = 0,
  AWAITING_INPUT = 1,
  PAUSED = 2,
  LOADING = 3,
  UNLOADED = 4,
};

enum SceneRenderMode
{
  NEW = 0,
  PUSH = 1,
  POP = 2,
  FIRST_RUN = 3,
};

enum ButtonState
{
  UNGRABBED,
  GRABBED,
};

typedef struct
{
  CCSize size;
  char directory[16];
} ResourceDefinition;

typedef struct 
{
  CCPoint leftBottom;
  CCPoint rightTop;
  ccColor4F borderColor;
  ccColor4F fillColor;
} ColoredRect;


#endif  // __TYPES_H__