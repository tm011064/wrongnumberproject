#ifndef _DEBUGDRAW_H
#define _DEBUGDRAW_H

#include "cocos2d.h"

using namespace cocos2d;

typedef struct {
  Vec2 pt1; 
  Vec2 pt2; 
  float r; 
  float g; 
  float b; 
} DebugLine; 

typedef struct 
{ 
  Vec2 pt; 
  float r; 
  float g; 
  float b; 
} DebugPoint; 

typedef struct 
{ 
  Vec2 pt; 
  float r; 
  float g; 
  float b; 
  float radius; 
} DebugCircle; 
typedef struct 
{ 
  Vec2 pt1; 
  Vec2 pt2; 
  Color4F color;
} DebugRect; 

class DebugDraw : public Node
{ 
  public: 
    static DebugDraw* create(); 
    DebugDraw(); 
    ~DebugDraw(); 
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    void appendLine(Vec2 pt1, Vec2 pt2, float r = 1, float g = 1, float b = 1); 
    void appendPoint(float x, float y, float r = 1, float g = 1, float b = 1); 
    void appendPoint(Vec2 pt, float r = 1, float g = 1, float b = 1); 
    void appendCircle(float x, float y, float radius, float r = 1, float g = 1, float b = 1); 
    void appendCircle(Vec2 pt, float radius, float r = 1, float g = 1, float b = 1); 
    void appendRect(Vec2 pt1, Vec2 pt2, float r = 1, float g = 1, float b = 1, float a = 1); 
private: 
  std::vector<DebugLine>* m_lines; 
  std::vector<DebugPoint>* m_points; 
  std::vector<DebugCircle>* m_circles; 
  std::vector<DebugRect>* m_rects; 
  
}; 

#endif