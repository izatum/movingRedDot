#include <raylib.h>


class Player
{

    // variables
public:
    const float playerSpeed = 2;
    float sprint = 1;
    int stamina = 200;
    int health = 100;

    bool isSprinting = false;

    Vector2 ballPosition;

    // constructor
    Player(Vector2 pos)
    {

        ballPosition = pos;
    }

    // methods

    void update()
    {

        BeginDrawing();

        if (stamina < 0)
        {
            stamina = 0;
        }

        if (stamina > 200)
        {
            stamina = 200;
        }

        if (IsKeyDown(KEY_LEFT_SHIFT) && stamina > 0)
        {
            sprint = 2;
            isSprinting = true;
        }
        else if (IsKeyUp(KEY_LEFT_SHIFT))
        {
            sprint = 1;
            stamina++;
            isSprinting = false;
        }

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        {
            ballPosition.x += (playerSpeed * sprint);

            if (isSprinting)
                stamina--;
        }

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        {
            ballPosition.x -= (playerSpeed * sprint);

            if (isSprinting)
                stamina--;
        }

        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            ballPosition.y -= (playerSpeed * sprint);

            if (isSprinting)
                stamina--;
        }

        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            ballPosition.y += (playerSpeed * sprint);

            if (isSprinting)
                stamina--;
        }

        if (stamina < 0)
        {
            sprint = 1;
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            DrawCircleV(ballPosition, 60, YELLOW);
            stamina--;
            stamina--;
            stamina--;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            DrawCircleV(ballPosition, 40, GREEN);
            stamina--;
            stamina--;
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            DrawCircleV(ballPosition, 40, PURPLE);
            stamina--;
            stamina--;
        }


        DrawCircleV(ballPosition, 20, RED);

        void test();
    };
};
