#include "BaseLayer.h"

using namespace cocos2d;

BaseLayer::BaseLayer(const std::function<void()>& backKeyCallback)
  : m_backKeyCallback(backKeyCallback)
{

}

bool BaseLayer::init() 
{
  if (!Layer::init())
  {
    return false;
  }

  this->setKeypadEnabled(true);

  return true;
}


BaseLayer* BaseLayer::create(const std::function<void()>& backKeyCallback)
{
  BaseLayer* ret = new (std::nothrow) BaseLayer(backKeyCallback);
  if (ret && ret->init())
  {
    ret->autorelease();
  }
  else
  {
    CC_SAFE_DELETE(ret);
  }
  return ret;
}

void BaseLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{  
  if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
  {
    if (m_backKeyCallback)
      m_backKeyCallback();
  }
}