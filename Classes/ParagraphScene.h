#ifndef __PARAGRAPH_SCENE_H__
#define __PARAGRAPH_SCENE_H__

#include "cocos2d.h"
#include "BaseScene.h"
#include "ui/CocosGUI.h"
#include "MenuTextButton.h"
#include "GameEngineIncludes.h"

using namespace cocos2d::ui;

#pragma once
class ParagraphScene : public BaseScene
{
protected:
  
  virtual bool parseXml(const std::string& filename);
  virtual void onEscapeKeyPressed();

  ParagraphScene(GameContext* gameContext)
    : BaseScene(gameContext, false)
  {

  }

public:
  ~ParagraphScene(){}

  virtual void onEnter() override;
  virtual bool init(const std::string& filename);

  static ParagraphScene *create(GameContext* gameContext, const std::string& filename);
};

#endif  // __PARAGRAPH_SCENE_H__