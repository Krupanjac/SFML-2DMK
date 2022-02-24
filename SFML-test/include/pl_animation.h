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
Sprite *model; //idle

struct state *next;
};

void load_texture(Player*,int,int,int);
Sprite* get_sprite();
Texture *init_texture(string);

Animate(Player*,string,int,int,int);


private:

state *head;

Texture *texture; //idle texture
Texture *run;

//INIT STATE IN CONSTRUCTOR



};

