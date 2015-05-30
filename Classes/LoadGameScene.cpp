#include "LoadGameScene.h"
#include "NavigationManager.h"
#include "GameConstants.h"
#include <cstring> 
#include <sstream>

void LoadGameScene::onEnter()
{
  Scene::onEnter();

  if (!this->m_isLayoutInitialized)
  {  
    /*this->m_isLayoutInitialized = true;
    
    CCRect visibleRect = VisibleRect::getVisibleRect();  
    CCPoint center = VisibleRect::center()

    m_pGameContext->registerImageFile(
      CCFileUtils::sharedFileUtils()->fullPathForFilename(NavigationManager::getPath(m_pGameContext, "splash.png").c_str()).c_str()
      , "splash");
    m_pGameContext->registerImageFile(
      CCFileUtils::sharedFileUtils()->fullPathForFilename(NavigationManager::getPath(m_pGameContext, "splashLogo.png").c_str()).c_str()
      , "splashLogo");

    CCSprite* splashScreen = CCSprite::createWithSpriteFrame(m_pGameContext->getImageMap()->getTile("splash"));
    CCSize s = splashScreen->getContentSize();
    splashScreen->setScaleX(visibleRect.size.width / s.width);
    splashScreen->setScaleY(visibleRect.size.height / s.height);
    splashScreen->setPosition(center);
    this->addChild(splashScreen, SPLASH_ZORDER);
    
    CCSprite* splashLogo = CCSprite::createWithSpriteFrame(m_pGameContext->getImageMap()->getTile("splashLogo"));
    splashLogo->setPosition(center);
    s = splashLogo->getContentSize();
    splashLogo->setScale(visibleRect.size.width*.8f / s.width);
    this->addChild(splashLogo, SPLASH_ZORDER);
    
    CCTime::gettimeofdayCocos2d(&m_startTime, NULL);*/

    this->scheduleOnce(CC_SCHEDULE_SELECTOR(LoadGameScene::loadGame), .0f);
    //loadGame(.5f);
  }
}

void LoadGameScene::loadGame(float dt)
{
  auto fileUtils = FileUtils::getInstance();

  // Fonts
  ValueMap vm = fileUtils->getValueMapFromFile(
    fileUtils->sharedFileUtils()->fullPathForFilename("fontResourceLookup.plist"
    ));

  ValueMap valueMap = vm["filenames"].asValueMap();
  std::vector<std::string> mapFiles = BaseFileUtils::getNumberedKeys(valueMap, "fs_");
  std::vector<int> fontSizes;
  std::vector<std::string>::iterator it;
  for (it = mapFiles.begin(); it != mapFiles.end(); ++it)
  {
    // this will be fs_18, fs_20...
    fontSizes.push_back(atoi(((it)->substr(3, (it)->length() - 3)).c_str()));
  }

  int targetNormalFontSize = (int)round(m_pGameContext->getResourceDefinition().size.height * .0375);

  std::vector<int>::iterator itInt;
  int actualNormalFontSize, actualLargeFontSize, delta;
  int closestNormalFontSizeDistance = INT_MAX;

  for (itInt = fontSizes.begin(); itInt != fontSizes.end(); ++itInt)
  {
    delta = abs(targetNormalFontSize - *itInt);
    if (delta < closestNormalFontSizeDistance)
    {
      closestNormalFontSizeDistance = delta;
      actualNormalFontSize = *itInt;
    }
  }
    
  m_pGameContext->setFontNormalPath(
    fileUtils->sharedFileUtils()->fullPathForFilename(
      valueMap["fs_" + std::to_string(actualNormalFontSize)].asString())
    );

  m_pGameContext->setFontHeightNormal(actualNormalFontSize);

  NavigationManager::showMainMenu(m_pGameContext, NEW, true);
}


LoadGameScene* LoadGameScene::create(GameContext* gameContext)
{
  LoadGameScene* ret = new (std::nothrow) LoadGameScene(gameContext);
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