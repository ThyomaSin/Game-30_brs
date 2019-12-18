#include "List.h"

class DrawableObj
{
  public:
  bool isvisible = true;
  virtual void draw(sf::RenderWindow* pointer);  
};

class GrManager
{
  public:
    List<DrawableObj*> list;
    void registrate(DrawableObj* dObj);
    void unregistrate(DrawableObj* dObj);
    void drawAll(sf::RenderWindow* pointer);
    void clear();
    //~GrManager();
};

void GrManager::registrate(DrawableObj* dObj)
{
  list.append(dObj);
}

void DrawableObj::draw(sf::RenderWindow* pointer)
{
}

void GrManager::unregistrate(DrawableObj* dObj)
{
  list.remove(dObj);
}

void GrManager::drawAll(sf::RenderWindow* pointer)
{ 
  pointer -> clear();
  for (int j = 0; j < list.len(); j++)
    (list[j]) -> draw(pointer);
  pointer -> display(); 
} 

