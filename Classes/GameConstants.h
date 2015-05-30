#ifndef __GAME_CONSTANTS_H__
#define __GAME_CONSTANTS_H__

#include "cocos2d.h"
#include "Types.h"

static const cocos2d::Color4B BACKGROUND_COLOR = { 0, 0, 0, 1};

//static const cocos2d::Color3B TEXT_BUTTON_BORDER_COLOR_ON  = {255.0f, 255.0f, 255.0f};

static ResourceDefinition SIZE_240x320    =  { cocos2d::CCSizeMake(240, 320),   "s240x320"   };
static ResourceDefinition SIZE_360x480    =  { cocos2d::CCSizeMake(360, 480),   "s360x480"   };
static ResourceDefinition SIZE_720x960    =  { cocos2d::CCSizeMake(720, 960),   "s720x960"   };
static ResourceDefinition SIZE_960x1280   =  { cocos2d::CCSizeMake(960, 1280),  "s960x1280"   };
static ResourceDefinition SIZE_1536x2048  =  { cocos2d::CCSizeMake(1536, 2048), "s1536x2048"   };


static const cocos2d::Color3B MENU_BUTTON_TEXT_COLOR = { 236, 236, 236 };
static const cocos2d::Color4F MENU_BUTTON_BACKGROUND_COLOR = { 48.0f / 255.0f, 48.0f / 255.0f, 48.0f / 255.0f, 1.0f };
//static const cocos2d::Color4F MENU_BUTTON_BACKGROUND_COLOR = { 48.0f, 48.0f, 48.0f, 1.0f };

static inline float floor_float(float f)
{
	int i = (int)f;
	return (float)((f < 0.0f && f != i) ? i - 1 : i);
}

#define round(__X__) floor_float( (float)(__X__) + .5f)

#define IS_DEBUG 1

#define GOLDEN_RATIO_PERCENTAGE           0.61803398f
#define GOLDEN_RATIO_NEGATIVE_PERCENTAGE  0.38196601f

#endif  // __GAME_CONSTANTS_H__