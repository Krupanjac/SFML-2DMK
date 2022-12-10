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
String map_sec_name;
Texture *texture_idle; //idle texture

struct state *next;
};

void load_texture(Player*,int,int,int);
void load_map_texture(Maps*,int,int,int,string);
string get_map_sec_name();
Sprite* get_sprite();
Texture *init_texture(string);

state *get_master_state();
Sprite *get_master_sprite();

Animate(Player*,string,int,int,int);
Animate(Maps*,string,int,int,int);

int pl_position_x() const;

int pl_position_y() const;

private:

state *head;
state *master_head;


Texture *texture; //idle texture
Texture *run;

//INIT STATE IN CONSTRUCTOR



};

