#pragma once

#include <iostream>
#include "global.h"
#include "igrac.h"



class Animate : public Player
{

public:
void load_texture();
Animate(double w, double h, Texture *txt);
Sprite get_sprite(int);




private:
        double pl_width;
        double pl_height;

        double pos_x;
        double pos_y;

Texture* texture;
Sprite* state;



};

