#include "igrac.h"
#include "global.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace P;
using namespace std;


Player::Player(double width, double height){
pl_width = width;
pl_height = height;
pos_x = 200;
pos_y = 400;
UP = false;
DOWN = false;
LEFT = false;
RIGHT = false;
}

RectangleShape Player::pl_render_update(RectangleShape r){
 if(UP && (pos_y>0)) pos_y-=pl_speed;
 if(DOWN &&(pos_y<scr_height-pl_height)) pos_y+=pl_speed;
 if(LEFT && (pos_x>0)) pos_x-=pl_speed;
 if(RIGHT&&(pos_x<scr_width-pl_width)) pos_x+=pl_speed;
 
r.setPosition(pos_x, pos_y);
cout<<pos_x<<" "<<pos_y<<endl;
return r;

}



RectangleShape Player::pl_render(){
    RectangleShape rect(Vector2f(pl_width, pl_height));
    rect.setPosition(pos_x,pos_y);
    rect.setFillColor(Color::Green);
    return rect;
}

void Player::pl_set_pos(int izbor){

   switch(izbor){

case 1:
UP = true;
break;

case 2:
DOWN = true;
break;

case 3:
LEFT = true;
break;

case 4:
RIGHT = true;
break;

default:

break;

}
    //rect.setPosition();
}

void Player::pl_update_pos(int izb){

switch(izb){

case 1:
UP = false;
break;

case 2:
DOWN = false;
break;

case 3:
LEFT = false;
break;

case 4:
RIGHT = false;
break;

default:

break;

}

}

