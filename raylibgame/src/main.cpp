#include <raylib.h>
#include <iostream>
#include <string>
#include "enemy.h"
#include "player.h"
#include "medpacks.h"


int main()
{

    SetExitKey(KEY_NULL);

    const int screenWidth = 800;
    const int screenHeight = 450;

    Enemy slangen;
    Enemy rectY;

    Health healthpacks;

    Enemy allEnemies[2];

    allEnemies[0] = slangen;
    allEnemies[1] = rectY;

    


    Vector2 playerStart = {(int)screenWidth / 2, (int)screenHeight / 2};

    Player player(playerStart);

    InitWindow(screenWidth, screenHeight, "Moving Red Dot");

    bool exitWindowRequested = false;
    bool exitWindow = false;

    int frameCounter;
    int secAlive;
    int enemySec;
    int difficulty = 4;

    SetTargetFPS(60);

    while (!exitWindow)
    {
        //if enemySec > ;

        int randY = GetRandomValue(50, 750);
        int randX = GetRandomValue(50, 400);

        player.update();

        frameCounter ++;

        if (frameCounter > 59) { 
            frameCounter = 0;
            secAlive ++;
            enemySec ++;
        }
        
        if (enemySec > difficulty) {
            //
        }

        if (secAlive > 10) 
        {
            difficulty = 3;
        } else if (secAlive > 30)
        {
            difficulty = 2;
        } else if (secAlive > 50) 
        {
            difficulty = 1;
        } else if (secAlive > 80) 
        {
            difficulty = 0.5;
        }
        

        if (secAlive < 10) {
            DrawText((TextFormat("Seconds Survived: %01i", secAlive)), 400, 10, 6, BLACK);
            } else if (secAlive > 9)
            {
                DrawText((TextFormat("Seconds Survived: %02i", secAlive)), 400, 10, 6, BLACK);
            }
            

        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;

        if (exitWindowRequested){
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
        }

         if (player.stamina < 0) {
            player.stamina = 0;
        }

        if (player.stamina > 200) {
            player.stamina = 200;
        }

        DrawRectangle(130, 20, 215, 5, LIGHTGRAY);

        DrawRectangle(145, 45, 200, 5, LIGHTGRAY);

        DrawRectangle(10, 14, 115, 20, DARKGRAY);

        DrawRectangle(10, 39, 130, 20, BLACK); 

        DrawRectangle(130, 20, player.health*2.15f, 5, GREEN);

        DrawRectangle(145, 45, player.stamina, 5, YELLOW);

        if (player.stamina > 99) {                                                             //Stamina bar
            DrawText((TextFormat("Stamina: %03i", player.stamina)), 15, 40, 20, GREEN);
        } else if (player.stamina < 100 && player.stamina > 9) {
            DrawText((TextFormat("Stamina: %02i", player.stamina)), 15, 40, 20, YELLOW);
        } else {
            DrawText((TextFormat("Stamina: %01i", player.stamina)), 15, 40, 20, RED);
        }

        if (player.health > 99) {                                                             //Health bar
            DrawText((TextFormat("Health: %03i", player.health)), 15, 15, 20, GREEN);
        } else if (player.stamina < 100 && player.stamina > 9) {
            DrawText((TextFormat("Health: %02i", player.health)), 15, 15, 20, YELLOW);
        } else {
            DrawText((TextFormat("Health: %01i", player.health)), 15, 15, 20, RED);
        }

    
    
        
        for (unsigned int i = 0; i < 2; i++)



    {

        int offsetX = allEnemies[i].width /2;
        int offsetY = allEnemies[i].height /2;


        if (allEnemies[i].position.x > player.ballPosition.x - offsetX){
            allEnemies[i].position.x -= 2;
        }

        if (allEnemies[i].position.x < player.ballPosition.x - offsetX){
            allEnemies[i].position.x += 2;
        }

        if (allEnemies[i].position.y > player.ballPosition.y - offsetY){
            allEnemies[i].position.y -= 2;
        }

        if (allEnemies[i].position.y < player.ballPosition.y - offsetY){
            allEnemies[i].position.y += 2;
        }
   
        allEnemies[i].draw();

        healthpacks.draw();

        if (enemySec > difficulty){
            allEnemies[i].draw();
            enemySec = 0;
        }
   
    }

 
        
       

        if (exitWindowRequested){
            DrawRectangle(0, 100, screenWidth, 220, DARKGRAY);
            DrawRectangle(0, 110, screenWidth, 200, BLACK);
            DrawText("Do you want to close the game? (Y/N)", 40, 180, 30, WHITE);
            if (IsKeyPressed(KEY_N)){
                exitWindowRequested = false;
            }
        }

       
        ClearBackground(RAYWHITE);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}