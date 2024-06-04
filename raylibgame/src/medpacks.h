#include <raylib.h>

class Health
{
    // Variables
public:
    const int HEALTHREGEN = 12;
    float medpackYRange = GetRandomValue(50, 750);
    float medpackXRange = GetRandomValue(50, 400);
    Vector2 position = {medpackYRange, medpackXRange};

    void draw(){


        BeginDrawing();
        DrawRectangle(position.x, position.y, 20, 20, GREEN);


    }

};