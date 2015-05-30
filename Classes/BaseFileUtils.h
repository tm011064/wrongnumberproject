#ifndef __BASE_FILE_UTILS_H__
#define __BASE_FILE_UTILS_H__

#include "cocos2d.h"

using namespace cocos2d;

#pragma once
class BaseFileUtils
{
public:
  static std::vector<std::string> getNumberedKeys(ValueMap &valueMap, const std::string &key);
  //std::vector<std::string> getNumberedResourceFiles(const std::string &key);
  //std::string valueForKey(const std::string &key);
};

#endif  // __BASE_FILE_UTILS_H__