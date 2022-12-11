#pragma once
#include <iostream>
#include "global.h"
#include "igrac.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Maps{

public:
Sprite* map_model;

void update_map_model(Sprite*);
void update_map_sprite_cord(int,int,int,int);

Sprite& get_map_model() const;

double get_map_width();
double get_map_height();

void pl_move_x(int);
void pl_move_y(int);

void update_pl_x(int);
void update_pl_y(int);

void pl_jump_acc();
void pl_jump_fall();

void update_map_scale();

Maps(double,double,int,int);

protected:
//Sirina i visina mape
double map_width;
double map_height;

double map_scale_w;
double map_scale_h;

int igrac_height = 50;

int pl_x;
int pl_y;

double x;
double y;

double over_bounds_x;

double incr_def = 0.0001;
double incr = 0.0001;

};