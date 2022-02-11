#pragma once

#include <iostream>
#include "igrac.h"



class Animate : public Player
{

public:
void load_texture();

Sprite get_sprite(int);

Animate();

private:

Texture* texture;
Sprite* state;



};

