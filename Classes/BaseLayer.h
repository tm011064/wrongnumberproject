#ifndef __BASELAYER_SCENE_H__
#define __BASELAYER_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class BaseLayer : public Layer
{
private:
  
  BaseLayer(const std::function<void()>& backKeyCallback);

public:
  //BaseLayer::~BaseLayer(){}

  virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
  virtual bool init();

  static BaseLayer *create(const std::function<void()>& backKeyCallback);

protected:
  std::function<void()> m_backKeyCallback;
};
#endif  // __BASELAYER_SCENE_H__