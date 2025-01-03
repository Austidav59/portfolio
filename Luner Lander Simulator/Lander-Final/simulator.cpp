/**********************************************************************
 * LAB 06
 * Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/
#include "position.h"
#include "angle.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "test.h"
#include "lander.h"
#include "acceleration.h"
#include "star.h"
#include <cmath>
#include <cassert>
#include <string>

using namespace std;

/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   Ground ground;
   Simulator(const Position& posUpperRight);
   void update(const Interface* pUI, double time);
   void draw(ogstream& gout);
   bool isGameOver() const { return gameOver; }

private:
    Lander lander;
    Star stars[50];
    Angle angle;
    Position pos;
    Thrust thrust;
    bool gameOver;
    string gameOverMessage;
};

Simulator::Simulator(const Position& posUpperRight) :
   ground(posUpperRight),
   lander(posUpperRight),
   gameOver(false),
   gameOverMessage("")
{
   for (int i = 0; i < 50; i++)
      stars[i].reset(posUpperRight.getX(), posUpperRight.getY());
}

void Simulator::update(const Interface* pUI, double time)
{
    if (gameOver) return;
    
    thrust.set(pUI);
    
    double gravity = -1.625; // Moon's gravity in m/s^2
    Acceleration acceleration = lander.input(thrust, gravity);
    lander.coast(acceleration, time);
    
    if (lander.checkGroundCollision(ground))
    {
        if (!ground.onPlatform(lander.getPosition(), lander.getWidth()))
        {
            lander.crash();
            gameOver = true;
            gameOverMessage = "Houston, we have a problem! Missed the platform.";
        }
        else
        {
            lander.land();
            gameOver = true;
            gameOverMessage = "The Eagle has landed!";
        }
    }
}

void Simulator::draw(ogstream& gout)
{
    for (int i = 0; i < 50; i++)
        stars[i].draw(gout);
    
    ground.draw(gout);
    
    // Draw lander
    lander.draw(thrust, gout);

    // Draw flames if there's fuel and thrust is active
    if (lander.getFuel() > 0.0 && !gameOver) {
        Position pos = lander.getPosition();
        double angle = lander.getAngle();
        
        gout.drawLanderFlames(pos, angle,
            thrust.isMain(),
            thrust.isClock(),
            thrust.isCounter());
    }

    // Display game stats
    gout.setPosition(Position(10, 375));
    gout << "Fuel: " << lander.getFuel() << endl;
    gout << "Speed: " << (int)lander.getSpeed() << " m/s" << endl;
    gout << "Altitude: " << (int)lander.getAltitude() << " m" << endl;

    if (gameOver)
    {
        gout.setPosition(Position(200, 200)); // Adjust position as needed
        gout << gameOverMessage << endl;
    }

    gout.flush();
}

/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   Simulator* pSimulator = (Simulator*)p;
   
   if (!pSimulator->isGameOver())
   {
      pSimulator->update(pUI, 0.1); // 0.1 seconds per frame
   }
   
   ogstream gout;
   pSimulator->draw(gout);
}

/*********************************
 * MAIN
 * Initialize the simulator and start the game
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ LPSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Run the unit tests
   testRunner();

   // Initialize OpenGL
   Position posUpperRight(400, 400);
   Interface ui("Lunar Lander", posUpperRight);

   // Initialize the game class
   Simulator simulator(posUpperRight);

   // Set everything into action
   ui.run(callBack, (void*)&simulator);

   return 0;
}
