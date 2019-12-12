class Platform : public gameObject
{
    public:
        
        int brsPlate = 0;
        int peresdPlate = 0;
        void setPlatform(float x, float y, float vx, float vy, sf::Texture* texturePointer);
        //sf::Texture* getTextureByNumber(int typeNumber);
        Platform();
        void generate(sf::Texture* texturePointer);

};



void Platform::setPlatform(float x, float y, float vx, float vy, sf::Texture* texturePointer)
{
  this->setSize(200, 80);
  this->setPosition(x, y);
  this->addSpeed(vx, vy);
  this->setTexture(texturePointer);
  this->isStrickingWithBorders = false;
}

Platform::Platform()
{
}

sf::Texture* getTextureByNumber(int typeNumber, sf::Texture* textures)
{
  if (typeNumber < 5)
    return (&(textures[typeNumber]));
}

void Platform::generate(sf::Texture* texturePointer)
{
  srand(time(NULL) + rand());
  int y = rand() % 640;
  int typeNumber = rand() % 5;
  this->setPlatform(1300, y, -200, 0, getTextureByNumber(typeNumber, texturePointer));
  
  if(typeNumber == 0)
    brsPlate = 1;
  if(typeNumber == 1)
    brsPlate = -3;
  if(typeNumber == 2)
    brsPlate = -1;
  if(typeNumber == 3)
    brsPlate = 3;
  if(typeNumber == 4)
    peresdPlate = -1;
}

Platform* generateNewPlate(sf::Texture* texturePointer)
{
  Platform* newPlate = new Platform;
  newPlate->generate(texturePointer);
  return newPlate;
}


class PlataformManager: public DrawableObj
{
  public:

    int len = 250;
    Platform* Plates = new Platform[len];
    int currentPos = 0; //current position, where new element will be placed

    void addPlate(Platform* newPlate)
        {
            if(currentPos > len - 1)
            {
                this->len = this->len * 2;
                Plates = (Platform*) realloc(Plates, this->len * sizeof(Platform));
            }
            Plates[this->currentPos] = *newPlate;
            this->currentPos += 1;   
        }

    void deletePlate(Platform* plateToDel)
    {
      for(int i = 0; i < currentPos - 1; i++)
        if(&Plates[i] == plateToDel)
        {
          for(int j = i; j < currentPos - 1; j++)
             Plates[j] = Plates[j+1];
           currentPos += -1; // in last filled cell is trash now
           return;
        }
    }

    void workOnCollisionWithPlayer(gameObject* player, int* BRS, int* peresd,HUD* interface, GrManager* objects)
    {
      for(int i = 0; i < currentPos; i++)
        if(player->checkObjectCollision(Plates[i]))
        {
          *BRS += Plates[i].brsPlate; // BRS and peresd are non-class variable in main(), like data base
          *peresd += Plates[i].peresdPlate;

          interface->setBRS(*BRS);
          interface->setPeresd(*peresd);

          this->deletePlate(&Plates[i]);
          //objects -> unregistrate(&Plates[i]);
        }

    }

    void deletePlatesOutOfScreen(GrManager* objects)
    {
      for(int i = 0; i < currentPos; i++)
      {
        if(Plates[i].Q.x < -200)
        {
          
          this->deletePlate(&Plates[i]);
          //objects -> unregistrate(&Plates[i]);
        }
      }
    }

    void draw(sf::RenderWindow* window)
    {
      for(int i = 0; i < currentPos; i++)
      {
        Plates[i].draw(window);
      }
    }

    void move(float dt, int screenY, int screenX)
    {
      for(int i = 0; i < currentPos; i++)
      {
        Plates[i].move(dt, screenY, screenX);
      }
    }

    ~PlataformManager()
    {
      delete[] Plates;
    }
};
 
  
