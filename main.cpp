#include <iostream>
#include <raylib.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
Color Green = {38, 185, 154, 255};
Color Dark_Green = {20, 160, 133, 255};
Color Light_Green = {129, 204, 184, 255};
Color Yellow = {243, 213, 91, 255};
using namespace std;

class Player
{
public:
    int PlayerSpeed_y = 20;
    int score = 0;
} A;

class Paddle
{
protected:
    void LimitMov()
    {
        int down_y = y + height;
        if (y < 0)
            y += A.PlayerSpeed_y;
        if (down_y > SCREEN_HEIGHT)
            y = y - A.PlayerSpeed_y;
    }

public:
    int x, y, space = 10;
    int height = 150, weight = 20;

    Paddle(int x, int y) : x(x), y(y) {}

    void Draw()
    {
        DrawRectangle(x, y, weight, height, WHITE);
    }

    void update()
    {

        if (IsKeyDown(KEY_UP))
            y = y - A.PlayerSpeed_y;
        else if (IsKeyDown(KEY_DOWN))
            y = y + A.PlayerSpeed_y;

        LimitMov();
    }
};

class cpuPaddle
{
protected:
    void LimitMov()
    {
        int down_y = y + height;
        if (y < 0)
            y += A.PlayerSpeed_y;
        if (down_y > SCREEN_HEIGHT)
            y = y - A.PlayerSpeed_y;
    }

public:
    int x, y, space = 10, score = 0;
    int height = 150, weight = 20;
    cpuPaddle(int x, int y) : x(x), y(y) {}

    void update(int Ball_y)
    {
        if (y + height / 2 >= Ball_y)
            y -= 6;
        if (y + height / 2 < Ball_y)
            y += 6;

        LimitMov();
    }

    void Draw()
    {
        DrawRectangle(x, y, weight, height, WHITE);
    }
};
Paddle Orgin(0, 0);
Paddle PLeft(Orgin.space, SCREEN_HEIGHT / 2 - 150 / 2);
cpuPaddle PRight(SCREEN_WIDTH - Orgin.space - Orgin.weight, SCREEN_HEIGHT / 2 - 150 / 2);

class Ball
{
public:
    int x;
    int y;
    float speed_x = 8, speed_y = 8;
    int radius = 20;

    Ball(int x, int y) : x(x), y(y) {}

    void Draw()
    {
        DrawCircle(x, y, radius, Yellow);
    }
    void update()
    {
        x += speed_x;
        y += speed_y;

        
        if (x < -100 || x > SCREEN_WIDTH + 100 )
        {
            x = SCREEN_WIDTH / 2 ;
            y = SCREEN_HEIGHT / 2 ; 
        } else if (y < 0 || y > SCREEN_HEIGHT)
        {
            speed_y *= -1;
        }
    }
};
void PongGame()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, " My Pong Game");
    SetTargetFPS(60);

    Ball Ball1(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        //Update 
        Ball1.update();
        PLeft.update();
        PRight.update(Ball1.y);
        //check for collisions
        if(CheckCollisionCircleRec( Vector2{static_cast<float>(Ball1.x), static_cast<float>(Ball1.y)}, Ball1.radius , Rectangle{static_cast<float>(PLeft.x), static_cast<float>(PLeft.y), static_cast<float>(PLeft.weight), static_cast<float>(PLeft.height)})){
            A.score++;
            Ball1.speed_x *= -1 ;
        }
        if (CheckCollisionCircleRec(Vector2{static_cast<float>(Ball1.x), static_cast<float>(Ball1.y)}, Ball1.radius , Rectangle{static_cast<float>(PRight.x), static_cast<float>(PRight.y), static_cast<float>(PRight.weight), static_cast<float>(PRight.height)}) ){
            PRight.score++ ;
            Ball1.speed_x *= -1 ;
        }
        //Draw
        DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
        ClearBackground(Dark_Green);
        DrawRectangle(0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, Green);
        DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 80 , Light_Green ) ;
        Ball1.Draw();
        PLeft.Draw();
        PRight.Draw();
        
        
        DrawText(TextFormat("%i", A.score), SCREEN_WIDTH / 4 - 20, 0, 50, WHITE);
        DrawText(TextFormat("%i", PRight.score), 3 * SCREEN_WIDTH / 4 + 20, 0, 50, WHITE);
        EndDrawing();
    }
    CloseWindow();
}
int main()
{
    PongGame();
}