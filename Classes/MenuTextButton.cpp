#include "MenuTextButton.h"


MenuTextButton* MenuTextButton::create(GameContext* gameContext, std::string text, Color3B textColor, Color4F backgroundColor
  , Size size)
{
  MenuTextButton *ret = new (std::nothrow) MenuTextButton(gameContext, text, textColor, backgroundColor, size);
  if (ret && ret->init())
  {
    ret->autorelease();
    ret->addEvents();
    
    return ret;
  }
  else
  {
    CC_SAFE_DELETE(ret);
    return nullptr;
  }

}

void MenuTextButton::onEnter()
{
  Node::onEnter();

  if (!this->m_isLayoutInitialized)
  {
    this->m_isLayoutInitialized = true;
        
    this->m_borderOrigin.setPoint(round(-this->m_size.width / 2), round(-this->m_size.height / 2));
    this->m_borderDestination.setPoint(round(this->m_size.width / 2), round(this->m_size.height / 2));

    auto label = LabelBMFont::create(m_text, m_pGameContext->getFontNormalPath());
    label->setColor(m_textColor);

    this->addChild(label);
  }
}

void MenuTextButton::addEvents()
{
  auto listener = EventListenerTouchOneByOne::create();
  listener->setSwallowTouches(true);

  listener->onTouchBegan = CC_CALLBACK_2(MenuTextButton::onTouchBegan, this);
  listener->onTouchEnded = CC_CALLBACK_2(MenuTextButton::onTouchEnded, this); 

  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


bool MenuTextButton::onTouchBegan(Touch  *touch, Event  *event)
{
  auto location = touch->getLocationInView();
  location = Director::getInstance()->convertToGL(location);
  
  auto fromOrigin = Node::convertToNodeSpace(location);
  if (fromOrigin.x >= -(m_size.width / 2.0f) && fromOrigin.x <= (m_size.width / 2.0f)
    && fromOrigin.y >= -(m_size.height / 2.0f) && fromOrigin.y <= (m_size.height / 2.0f))
  {
    m_buttonState = ButtonState::GRABBED;

    if (_touchEventCallback)
      _touchEventCallback(this, TouchEventType::BEGAN);

    return true;
  }
  else
  {
    m_buttonState = ButtonState::UNGRABBED;
    return false;
  }
}

void MenuTextButton::onTouchEnded(Touch  *touch, Event  *event)
{
  if (m_buttonState != ButtonState::GRABBED)
    return;

  m_buttonState = ButtonState::UNGRABBED;

  auto location = touch->getLocationInView();
  location = Director::getInstance()->convertToGL(location);

  auto fromOrigin = Node::convertToNodeSpace(location);
  if (fromOrigin.x >= -(m_size.width / 2.0f) && fromOrigin.x <= (m_size.width / 2.0f)
    && fromOrigin.y >= -(m_size.height / 2.0f) && fromOrigin.y <= (m_size.height / 2.0f))
  {
    if (_touchEventCallback)
      _touchEventCallback(this, TouchEventType::ENDED);
  }
}

void MenuTextButton::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
  ccDrawSolidRect(m_borderOrigin, m_borderDestination, m_backgroundColor);
}