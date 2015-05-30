#include "MenuScene.h"
#include "NavigationManager.h"

void MenuScene::onEscapeKeyPressed()
{
  Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
}

MenuScene* MenuScene::create(GameContext* gameContext, bool showSplashScreen)
{
  MenuScene *ret = new (std::nothrow) MenuScene(gameContext, showSplashScreen);
  if (ret && ret->init())
  {
    ret->autorelease();
    return ret;
  }
  else
  {
    CC_SAFE_DELETE(ret);
    return nullptr;
  }
}

void MenuScene::onEnter()
{
  Scene::onEnter();

  if (!m_isLayoutInitialized)
  {
    auto s = Director::getInstance()->getWinSize();

    auto startButton = MenuTextButton::create(m_pGameContext, "START"
      , MENU_BUTTON_TEXT_COLOR
      , MENU_BUTTON_BACKGROUND_COLOR
      , Size(s.width*GOLDEN_RATIO_PERCENTAGE, m_pGameContext->getFontHeightNormal() / GOLDEN_RATIO_PERCENTAGE)
    );
    startButton->setPosition(Point(s.width / 2.0f, s.height / 2.0f));
    startButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
      switch (type)
      {
      case ui::Widget::TouchEventType::BEGAN:
        break;
      case ui::Widget::TouchEventType::ENDED:
        NavigationManager::showParagraph(m_pGameContext, "chapters/chapter1/paragraph_1.xml");
        break;
      default:
        break;
      }
    });

    this->addChild(startButton);

    m_isLayoutInitialized = true;
  }
}