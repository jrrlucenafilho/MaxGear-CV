#ifndef CAR_H
#define CAR_H

#pragma once

#include "olcPixelGameEngine.h"

enum carDirections {CAR_STILL = 0, CAR_LEFT = -1, CAR_RIGHT = +1};

class Car
{
    public:
        Car();
        virtual ~Car();

        int getnCarDirection();
        float getfCarPos();
        float getnCarPos();
        float getfSpeed();
        float getfCarCurvature();

        void setnCarDirection(int newnDirection);
        void setfCarPos(float newfCarPos);
        void setnCarPos(int newnCarPos);
        void setfSpeed(float newfSpeed);
        void setfCarCurvature(float newCurvature);

        void addTofSpeed(float plusfSpeed);
        void deductFromfSpeed(float minusfSpeed);
        void addTofCarCurvature(float plusCurvature);
        void deductFromfCarCurvature(float minusCurvature);
        void drawSprite(olc::PixelGameEngine* game);

    private:
        void drawSpriteLeft(olc::PixelGameEngine* game);    //To use the lib's functions
        void drawSpriteRight(olc::PixelGameEngine* game);
        void drawSpriteStill(olc::PixelGameEngine* game);

        int nCarDirection;  //Car direction (from input)
        float fCarPos;  //*Current* car position
        float nCarPos;  //Car position for sprite handling
        float fSpeed;   //Current speed
        float fCarCurvature;    //Acc of the car's curvature
};

#endif