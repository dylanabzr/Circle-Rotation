#include <cmath>
#include <iostream>
#include <math.h>
#include <raylib.h>
#define WINDOW_HEIGHT 800.0
#define WINDOW_WIDTH 800.0

double degreeToRad(double x){
  return x * (M_PI/180);
}

class Movement{
  public:
    double ballX, ballY, radius = WINDOW_WIDTH/4, degree = 0, speed = 4;
    void move(){
      speed += GetMouseWheelMove();
      ballX = WINDOW_WIDTH/2 + radius * cos(degreeToRad(degree));
      ballY = WINDOW_HEIGHT/2 + radius * sin(degreeToRad(degree));
      degree = degree >= 360?0:degree+speed;
    }
};

class Graphics : public Movement{
public:
  void gameUI(){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(400, 400, radius, RED);
    DrawCircle(400, 400, radius - 5, BLACK);
    DrawCircle(ballX, ballY, 20, BLUE);
    DrawText("Scroll the mouse to change the speed", 200, 700, 20, RAYWHITE);
    EndDrawing();
  }
};

class Window : public Graphics{
public:
  void windowLoop(){
    SetTargetFPS(60);
    InitWindow(WINDOW_HEIGHT, WINDOW_WIDTH, "Circle");
    SetExitKey(KEY_ESCAPE);
    while(!WindowShouldClose()){
      move();
      gameUI();
    }
  } 
};

int main(){
  Window janela;
  janela.windowLoop();

}
