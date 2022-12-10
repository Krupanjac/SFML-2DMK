#include "global.h"

int scr_width;
int scr_height;
double model_size = 3.5f;

double pl_def_height = 100;
double pl_def_width = 60;

bool isPressed = false;
double pi = 3.14;

int pressed;

bool inAir = false;
bool run = false;
bool fall = false;
bool jump = false;
bool attack = false;
float incr = 0.00001;
//double pl_speed = 0.09;

void decl(int w,int h){

    scr_width = w;
    scr_height = h;

}