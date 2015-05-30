#include "NavigationManager.h"
#include "GameConstants.h"
#include "BaseLayer.h"
#include "MenuScene.h"
#include "LoadGameScene.h"
#include "ParagraphScene.h"


using namespace cocos2d;

CCScene* NavigationManager::resetGameContextScene(SceneType sceneType, GameContext* gameContext, bool showSplashScreen)
{
  //BaseLayer* pLayer;
  //LoadGameScene* loadGameScene;

  switch (sceneType)
  {
  case LOAD_GAME_SCENE:

    auto loadGameScene = LoadGameScene::create(gameContext);
    auto layer = BaseLayer::create(CC_CALLBACK_0(BaseScene::onEscapeKeyPressed, loadGameScene));

    loadGameScene->addChild(layer);

    return loadGameScene;
    
    //case HIGHSCORE_SCENE: 
    //  
    //  highscoreScene = new HighscoreScene(gameContext, showSplashScreen);
    //      
    //  pLayer = new BaseLayer(highscoreScene, callfunc_selector( BaseScene::onBackKeyPressed ) );
    //  pLayer->init(); 
    //  pLayer->autorelease();

    //  highscoreScene->addChild(pLayer);
    //  
    //  return highscoreScene;
  }

  return NULL;
}

void NavigationManager::showParagraph(GameContext* gameContext, std::string filename)
{
  auto paragraphScene = ParagraphScene::create(gameContext, filename);
  auto layer = BaseLayer::create(CC_CALLBACK_0(BaseScene::onEscapeKeyPressed, paragraphScene));

  paragraphScene->addChild(layer);

  Director::getInstance()->replaceScene(paragraphScene);
}

void NavigationManager::showMainMenu(GameContext* gameContext, SceneRenderMode sceneRenderMode, bool showSplashScreen)
{
  auto menuScene = MenuScene::create(gameContext, showSplashScreen);

  auto layer = BaseLayer::create(CC_CALLBACK_0(BaseScene::onEscapeKeyPressed, menuScene));

  menuScene->addChild(layer);

  Director::getInstance()->purgeCachedData();
  switch (sceneRenderMode)
  {
  case FIRST_RUN: Director::getInstance()->runWithScene(menuScene); break;
  case NEW: Director::getInstance()->replaceScene(menuScene); break;
  }
}

void NavigationManager::showScene(SceneType sceneType, GameContext* gameContext, SceneRenderMode sceneRenderMode, bool showSplashScreen)
{
  Scene* scene;
  Director::getInstance()->purgeCachedData();

  switch (sceneRenderMode)
  {
  case FIRST_RUN:
    scene = resetGameContextScene(sceneType, gameContext, showSplashScreen);
    Director::getInstance()->runWithScene(scene);
    break;

  case NEW:
    scene = resetGameContextScene(sceneType, gameContext, showSplashScreen);
    Director::getInstance()->replaceScene(scene);
    break;

  case PUSH:
    scene = resetGameContextScene(sceneType, gameContext, showSplashScreen);
    Director::getInstance()->pushScene(scene);
    break;

  case POP:
    Director::getInstance()->popScene(); // TODO (Roman): does that clear???
    break;
  }
}