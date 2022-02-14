#pragma once

#include <iostream>
#include "global.h"
#include "igrac.h"

using namespace P;

class Animate
{

public:
void load_texture(Player*);
Sprite get_sprite(int);

Animate();


private:


Texture texture;

//INIT STATE IN CONSTRUCTOR
Sprite* state;


};

