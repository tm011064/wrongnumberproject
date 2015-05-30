#ifndef __GAME_CONTEXT_H__
#define __GAME_CONTEXT_H__

#include "cocos2d.h"
#include "Types.h"

#pragma once
class GameContext
{
private:

  ResolutionPolicy m_resolutionPolicy;

  cocos2d::Size m_originalSize;
  std::string m_fontNormalPath;
  ResourceDefinition m_resourceDefinition;
  float m_fontHeightNormal;

public:
  GameContext();
  ~GameContext();

  cocos2d::Size getOriginalSize() { return this->m_originalSize; }
  void setOriginalSize(cocos2d::Size originalSize) { this->m_originalSize = originalSize; }

  ResourceDefinition getResourceDefinition() { return this->m_resourceDefinition; }
  void setResourceDefinition(ResourceDefinition resourceDefinition) { this->m_resourceDefinition = resourceDefinition; }

  ResolutionPolicy getResolutionPolicy() { return this->m_resolutionPolicy; }
  void setResolutionPolicy(ResolutionPolicy resolutionPolicy) { this->m_resolutionPolicy = resolutionPolicy; }

  std::string getFontNormalPath() { return this->m_fontNormalPath; }
  void setFontNormalPath(std::string fontNormalPath) { this->m_fontNormalPath = fontNormalPath; }

  float getFontHeightNormal() { return this->m_fontHeightNormal; }
  void setFontHeightNormal(float fontHeightNormal) { this->m_fontHeightNormal = fontHeightNormal; }
};

#endif  // __GAME_CONTEXT_H__