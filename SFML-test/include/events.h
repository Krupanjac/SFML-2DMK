#include <iostream>
#include "igrac.h"

#pragma once

using namespace std;
using namespace P;

class Desavanja{

public:

void keyboard_pressed(Player&,Player&,Event,bool);

void keyboard_released(Player&,Event);


private:

Time t2;
double t2Sec;
Clock clock2;
};