#include "igrac.h"
#include "global.h"
#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace P;
using namespace std;


Player::Player(double width, double height){
pl_width = width;
pl_height = height;
pos_x = 0;
pos_y = scr_height-pl_height;
UP = false;
DOWN = false;
LEFT = false;
RIGHT = false;
gr_acc = 0;
pl_speed = 0.09;
pi = 3.14;

LEFT_TRIGGER = false;
RIGHT_TRIGGER = false;
FIRST_PASS = true;

}

RectangleShape Player::pl_render_update(RectangleShape r){
cout<<pos_y<<" "<<scr_height-pl_height<<endl;
 if(UP &&(pos_y>scr_height-pl_height)&& (pos_x>0)&&(pos_x<scr_width-pl_width)){
     // Resiti ovaj deo!!!
      pos_y-=pl_height/1.2;
     

 }
 if(DOWN &&(pos_y<scr_height-pl_height)){
    
    }
 if(LEFT && (pos_x>0)) pos_x-=pl_speed;
 if(RIGHT&&(pos_x<scr_width-pl_width)) pos_x+=pl_speed;
 
r.setPosition(pos_x, pos_y);

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
//if (UP)UP = false;

//else UP = true;

break;

case 2:
DOWN = true;
/*if (DOWN)DOWN = false;

else DOWN = true;*/
break;

case 3:
gr_acc = 0;
LEFT_TRIGGER = true;
RIGHT_TRIGGER = false;
LEFT = true;
/*if (LEFT)LEFT = false;
else LEFT = true;*/
break;

case 4:
/*if (RIGHT)RIGHT = false;

else RIGHT = true;*/
gr_acc = 0;
RIGHT_TRIGGER = true;
LEFT_TRIGGER = false;
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
//if(((scr_height-pl_height)-pos_y)<=1) flag = true;
//cout<<pos_y<<" "<<scr_height-pl_height<<" "<<pos_y-(scr_height-pl_height)<<endl;
break;

case 2:
DOWN = false;
break;

case 3:
//LEFT_TRIGGER = false;
LEFT = false;
if(pos_y<=scr_height-pl_height)
//LEFT_TRIGGER = false;
break;

case 4:
//RIGHT_TRIGGER = false;
RIGHT = false;
if(pos_y<=scr_height-pl_height)
//RIGHT_TRIGGER = false;
break;

default:

break;

}

}


void Player::gravity(){
  // Y IDE OD 0 DO 1 A X JE SIN
  if(RIGHT_TRIGGER){
    LEFT_TRIGGER = false;
    //cout<<pos_y<<" "<<scr_height-pl_height<<endl;
    if(pos_y<=scr_height-pl_height){
      printf("%f, %f\n",gr_acc,pi);
      if(gr_acc<=pi/2)
        pos_y+= sin(gr_acc)/2;
        else
        pos_y-=sin(gr_acc)/2;
        if(pos_x<scr_width-pl_width)
        pos_x += gr_acc;
        gr_acc+=0.0001;
        
        if(gr_acc>=pi)
         gr_acc=0;
        //RIGHT_TRIGGER = false;   
       //if(pos_x<scr_width-pl_width) pos_x+=gr_acc/30;
    }
   
  }

  else if(LEFT_TRIGGER){
    RIGHT_TRIGGER = false;
    //cout<<pos_y<<" "<<scr_height-pl_height<<endl;
    if(pos_y<=scr_height-pl_height){
      printf("%f, %f\n",gr_acc,pi);
      if(gr_acc<=pi/2)
        pos_y+= sin(gr_acc)/2;
        else
        pos_y-=sin(gr_acc)/2;
        if(pos_x>0)
        pos_x -= gr_acc;
        gr_acc+=0.0001;
        
        if(gr_acc>=pi)
         gr_acc=0;
        //RIGHT_TRIGGER = false;   
       //if(pos_x<scr_width-pl_width) pos_x+=gr_acc/30;
    }
   
  }
  else if(!LEFT_TRIGGER && !RIGHT_TRIGGER){

  }
  

}