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

void update_map_model(Sprite*,int,int);

Sprite& get_map_model() const;

double get_map_width() const;
double get_map_height() const;

void pl_move_x(int);
void pl_move_y(int);

void update_pl_x(int);
void update_pl_y(int);

Maps(double,double,int,int);

protected:
//Sirina i visina mape
double map_width;
double map_height;

int pl_x;
int pl_y;

int x;
int y;

};