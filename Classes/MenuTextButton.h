#ifndef __BASELAYER_SCENE_H__
#define __BASELAYER_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameEngineIncludes.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class MenuTextButton : public Widget
{
private:
  
  std::string m_text;
  Color3B m_textColor;
  Color4F m_backgroundColor;
  Size m_size;
  ButtonState m_buttonState;
  bool m_isLayoutInitialized;
  GameContext* m_pGameContext;

  Vec2 m_borderOrigin;
  Vec2 m_borderDestination;

  MenuTextButton(GameContext* gameContext, std::string text, Color3B textColor, Color4F backgroundColor
    , Size size)
    : m_text(text)
    , m_textColor(textColor)
    , m_backgroundColor(backgroundColor)
    , m_size(size)
    , m_buttonState(ButtonState::UNGRABBED)
    , m_isLayoutInitialized(false)
    , m_pGameContext(gameContext)
  {
  }
  void addEvents();

public:
  //MenuTextButton::~MenuTextButton(){}
  
  static MenuTextButton *create(GameContext* gameContext, std::string text, Color3B textColor, Color4F backgroundColor
    , Size size);
  
  virtual void onEnter() override;

  bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
  void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
  virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags) override;

protected:

};
#endif  // __BASELAYER_SCENE_H__