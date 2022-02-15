#pragma once

#include <iostream>
#include "global.h"
#include "igrac.h"

using namespace P;
using namespace std;

class Animate
{

public:

struct state{
Sprite *model;

struct state *next;
};

void load_texture(Player*);
Sprite* get_sprite(int);
Texture *init_texture();

Animate();


private:

state *head;

Texture *texture;

//INIT STATE IN CONSTRUCTOR



};

