#include <raylib.h>


class Enemy
{
private:


public:

    float randEnemySpawnY = GetRandomValue(50,750);
    float randEnemySpawnX = GetRandomValue (50,400);
    Vector2 position = {randEnemySpawnY,randEnemySpawnX};
    int health = 100;
    int width = 50;
    int height = 50;


    void update(){
        
    }

    void draw(){


        BeginDrawing();
        DrawRectangle(position.x, position.y, width, height, RED);


    }



};

