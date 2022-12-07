#pragma once

#include <iostream>
#include "global.h"
#include "igrac.h"
#include "maps.h"

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
void load_map_texture(Maps*,int,int,int);
Sprite* get_sprite();
Texture *init_texture(string);

Animate(Player*,string,int,int,int);
Animate(Maps*,string,int,int,int);

int pl_position_x() const;

int pl_position_y() const;

private:

state *head;

Texture *texture; //idle texture
Texture *run;

//INIT STATE IN CONSTRUCTOR



};

