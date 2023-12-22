#include <cmath>
#include <iostream>
#include <math.h>
#include <raylib.h>
#define WINDOW_HEIGHT 800.0
#define WINDOW_WIDTH 800.0
#define LINE_THICKNESS 5

double degreeToRad(double x){
  return x * (M_PI/180);
}
class Ball{
  public:
    double ballX, ballY, radius = WINDOW_WIDTH/4, degree = 0, speed = 4;
};
class Movement{
  public:
    static void move(Ball &b){
      b.speed += GetMouseWheelMove();
      b.ballX = WINDOW_WIDTH/2 + b.radius * cos(degreeToRad(b.degree));
      b.ballY = WINDOW_HEIGHT/2 + b.radius * sin(degreeToRad(b.degree));
      b.degree = b.degree >= 360?0:b.degree+b.speed;
    }
};

class Graphics {
public:
  static void gameUI(Ball &b){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, b.radius, RED);
    DrawCircle(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, b.radius - LINE_THICKNESS, BLACK);
    DrawCircle(b.ballX, b.ballY, 20, BLUE);
    DrawText("Scroll the mouse to change the speed", 200, 700, 20, RAYWHITE);
    EndDrawing();
  }
};

class Window {
public:
  void windowLoop(){
    Ball ball;
    SetTargetFPS(60);
    InitWindow(WINDOW_HEIGHT, WINDOW_WIDTH, "Circle");
    SetExitKey(KEY_ESCAPE);
    while(!WindowShouldClose()){
      Movement::move(ball);
      Graphics::gameUI(ball);
    }
  } 
};

int main(){
  Window janela;
  janela.windowLoop();

}
