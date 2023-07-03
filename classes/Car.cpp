#include "Car.h"

using namespace olc;

Car::Car()
{
    nCarDirection = 0;
    nCarPos = 0;
    fCarPos = 0.0f;
    fSpeed = 0.0f;
    fCarCurvature = 0.0f;
}

Car::~Car()
{

}

int Car::getnCarDirection()
{
    return nCarDirection;
}

float Car::getfCarPos()
{
    return fCarPos;
}

float Car::getnCarPos()
{
    return nCarPos;
}

float Car::getfSpeed()
{
    return fSpeed;
}

float Car::getfCarCurvature()
{
    return fCarCurvature;
}

void Car::setnCarDirection(int newnDirection)
{
    nCarDirection = newnDirection;
}

void Car::setfCarPos(float newfCarPos)
{
    fCarPos = newfCarPos;
}

void Car::setnCarPos(int newnCarPos)
{
    nCarPos = newnCarPos;
}

void Car::setfSpeed(float newfSpeed)
{
    fSpeed = newfSpeed;
}

void Car::setfCarCurvature(float newCurvature)
{
    fCarCurvature = newCurvature;
}

void Car::addTofSpeed(float plusfSpeed)
{
    fSpeed += plusfSpeed;
}

void Car::deductFromfSpeed(float minusfSpeed)
{
    fSpeed -= minusfSpeed;
}

void Car::addTofCarCurvature(float plusCurvature)
{
    fCarCurvature += plusCurvature;
}

void Car::deductFromfCarCurvature(float minusCurvature)
{
    fCarCurvature -= minusCurvature;
}

void Car::drawSprite(olc::PixelGameEngine* game)
{
    switch (nCarDirection)
    {
    case 0:
        drawSpriteStill(game);
        break;

    case +1:
        drawSpriteRight(game);
        break;

    case -1:
        drawSpriteLeft(game);
        break;
    }
}

//TODO: Optimize this by using sprites for the car, loading it just once and saving as a 2d array
void Car::drawSpriteLeft(olc::PixelGameEngine* game)
{
    //Pixel Line 1
    game->Draw(nCarPos+6, 80, VERY_DARK_YELLOW);
    game->Draw(nCarPos+7, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+10, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+11, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+12, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+13, 80, VERY_DARK_YELLOW);

    //Pixel line 2
    game->Draw(nCarPos+9, 81, VERY_DARK_BLUE);
    game->Draw(nCarPos+10, 81, VERY_DARK_BLUE);

    //Pixel line 3
    game->Draw(nCarPos+7, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+10, 82, VERY_DARK_BLUE);

    //Pixel line 4
    game->Draw(nCarPos+6, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 83, VERY_DARK_BLUE);

    //Pixel line 5
    game->Draw(nCarPos, 84, BLACK);
    game->Draw(nCarPos+1, 84, BLACK);
    game->Draw(nCarPos+2, 84, BLACK);
    game->Draw(nCarPos+5, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+10, 84, BLACK);
    game->Draw(nCarPos+11, 84, BLACK);
    game->Draw(nCarPos+12, 84, BLACK);

    //Pixel line 6
    game->Draw(nCarPos, 85, DARK_GREY);
    game->Draw(nCarPos+1, 85, BLACK);
    game->Draw(nCarPos+2, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+3, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+4, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+5, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 85, BLACK);
    game->Draw(nCarPos+10, 85, BLACK);
    game->Draw(nCarPos+11, 85, BLACK);
    game->Draw(nCarPos+12, 85, BLACK);

    //Pixel line 7
    game->Draw(nCarPos, 86, BLACK);
    game->Draw(nCarPos+1, 86, BLACK);
    game->Draw(nCarPos+2, 86, BLACK);
    game->Draw(nCarPos+4, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+5, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 86, BLACK);
    game->Draw(nCarPos+10, 86, BLACK);
    game->Draw(nCarPos+11, 86, BLACK);
    game->Draw(nCarPos+12, 86, BLACK);
}

void Car::drawSpriteRight(olc::PixelGameEngine* game)
{
    //Pixel line 1
    game->Draw(nCarPos, 80, VERY_DARK_YELLOW);
    game->Draw(nCarPos+1, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+2, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+3, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+4, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+5, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 80, VERY_DARK_YELLOW);

    //Pixel line 2
    game->Draw(nCarPos+3, 81, VERY_DARK_BLUE);
    game->Draw(nCarPos+4, 81, VERY_DARK_BLUE);

    //Pixel line 3
    game->Draw(nCarPos+3, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+4, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+5, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 82, VERY_DARK_BLUE);

    //Pixel line 4
    game->Draw(nCarPos+4, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+5, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 83, VERY_DARK_BLUE);

    //Pixel line 5
    game->Draw(nCarPos+1, 84, BLACK);
    game->Draw(nCarPos+2, 84, BLACK);
    game->Draw(nCarPos+3, 84, BLACK);
    game->Draw(nCarPos+4, 84, BLACK);
    game->Draw(nCarPos+5, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+11, 84, BLACK);
    game->Draw(nCarPos+12, 84, BLACK);
    game->Draw(nCarPos+13, 84, BLACK);

    //Pixel line 6
    game->Draw(nCarPos+1, 85, BLACK);
    game->Draw(nCarPos+2, 85, BLACK);
    game->Draw(nCarPos+3, 85, BLACK);
    game->Draw(nCarPos+4, 85, BLACK);
    game->Draw(nCarPos+5, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+10, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+11, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+12, 85, BLACK);
    game->Draw(nCarPos+13, 85, DARK_GREY);

    //Pixel Line 7
    game->Draw(nCarPos+1, 86, BLACK);
    game->Draw(nCarPos+2, 86, BLACK);
    game->Draw(nCarPos+3, 86, BLACK);
    game->Draw(nCarPos+4, 86, BLACK);
    game->Draw(nCarPos+6, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+11, 86, BLACK);
    game->Draw(nCarPos+12, 86, BLACK);
    game->Draw(nCarPos+13, 86, BLACK);
}

void Car::drawSpriteStill(olc::PixelGameEngine* game)
{
    //Pixel line 1
    game->Draw(nCarPos+3, 80, VERY_DARK_YELLOW);
    game->Draw(nCarPos+4, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+5, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 80, VERY_DARK_BLUE);
    game->Draw(nCarPos+10, 80, VERY_DARK_YELLOW);

    //Pixel line 2
    game->Draw(nCarPos+6, 81, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 81, VERY_DARK_BLUE);

    //Pixel line 3 and 4
    game->Draw(nCarPos+5, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 82, VERY_DARK_BLUE);
    game->Draw(nCarPos+5, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 83, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 83, VERY_DARK_BLUE);

    //Pixel line 5
    game->Draw(nCarPos, 84, BLACK);
    game->Draw(nCarPos+1, 84, BLACK);
    game->Draw(nCarPos+2, 84, BLACK);
    game->Draw(nCarPos+5, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 84, VERY_DARK_BLUE);
    game->Draw(nCarPos+11, 84, BLACK);
    game->Draw(nCarPos+12, 84, BLACK);
    game->Draw(nCarPos+13, 84, BLACK);

    //Pixel line 6
    game->Draw(nCarPos, 85, BLACK);
    game->Draw(nCarPos+1, 85, BLACK);
    game->Draw(nCarPos+2, 85, BLACK);
    game->Draw(nCarPos+3, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+4, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+5, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+9, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+10, 85, VERY_DARK_BLUE);
    game->Draw(nCarPos+11, 85, BLACK);
    game->Draw(nCarPos+12, 85, BLACK);
    game->Draw(nCarPos+13, 85, BLACK);

    //Pixel line 7
    game->Draw(nCarPos, 86, BLACK);
    game->Draw(nCarPos+1, 86, BLACK);
    game->Draw(nCarPos+2, 86, BLACK);
    game->Draw(nCarPos+5, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+6, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+7, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+8, 86, VERY_DARK_BLUE);
    game->Draw(nCarPos+11, 86, BLACK);
    game->Draw(nCarPos+12, 86, BLACK);
    game->Draw(nCarPos+13, 86, BLACK);
}
