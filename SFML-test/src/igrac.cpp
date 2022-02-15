#include "igrac.h"
#include "global.h"
#include "Collision.hpp"
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

void Player::update_pl_model(Sprite* state){
this->pl_model= state;
this->pl_model->setPosition(pos_x, pos_y);
}



void Player::update_pl_width(){
  this->pl_width*=2;
}
void Player::update_pl_height(){
  this->pl_height*=2;
   this->pos_y = scr_height-pl_height;
}


int Player::get_pl_width() const{
  return this->pl_width;
}

int Player::get_pl_height() const{
  return this->pl_height;
}


int Player::get_pl_position_x()const{
  return this->pos_x;
}

int Player::get_pl_position_y()const{
  return this->pos_y;
}


/*bool Player::collision(Player igrac){
  printf("%f,%f\n",this->pos_x+this->pl_width, igrac.pos_x+igrac.pl_width);
  if(this->pos_x+this->pl_width-igrac.pos_x+igrac.pl_width<pl_width/2 && this->pos_x+this->pl_width-igrac.pos_x+igrac.pl_width>pl_width/2.22){
    return true;
  }
  else
  return false;

}*/

void Player::change_pl_y(){
  pos_x=scr_width/2-pl_width;
}


RectangleShape Player::update_size(RectangleShape r){
  pl_height = duck();
  r.setSize(Vector2f(pl_width,pl_height));
  //printf("%f,%f,%d\n",pos_y,pl_height,pl_def_height);
  //if(pl_height<pl_def_height)
  pos_y-=pl_height/2;
  return r;

}



int Player::duck(){

return pl_def_height;

}
//COLLISION PROBLEM POPRAVITI!!!
Sprite* Player::pl_render_update(Sprite *r,Player igrac){
//cout<<pos_y<<" "<<scr_height-pl_height<<endl;
 if(UP &&(pos_y>scr_height-pl_height)&& (pos_x>0)&&(pos_x<scr_width-pl_width)){
     // Resiti ovaj deo!!!
      pos_y-=pl_height/1.1;
 }
 if(DOWN &&(floor(pos_y)==floor(scr_height-pl_height))){
   pl_height=pl_def_height/2;
   //r.setSize(Vector2f(pl_width,pl_height));
    }
 if(LEFT && (pos_x>0)) pos_x-=pl_speed;
 if(RIGHT&&(pos_x<scr_width-pl_width)) pos_x+=pl_speed;
 
r->setPosition(pos_x, pos_y);

return r;

}

void Player::pl_render_reload(){
  this->pl_model->setPosition(pos_x,pos_y);

}

Sprite Player::pl_render(Texture *txt){
    Sprite igr;
    igr.setTexture(*txt);
    igr.setTextureRect(IntRect(1,3,pl_width,pl_height));
    igr.setScale(2,2);
    update_pl_width();
    update_pl_height();
    igr.setPosition(pos_x,pos_y);
    return igr;

}

void Player::pl_direction_render(Player* igr2){

if(igr2->get_pl_position_x()>this->get_pl_position_x()){
  igr2->pl_model->setScale(-2.0f,2.0f);
  this->pl_model->setScale(2.0f,2.0f);
  //this->pl_model->setTextureRect(IntRect(1,3,-pl_width,pl_height));
}
  else{
    igr2->pl_model->setScale(2.0f,2.0f);
    this->pl_model->setScale(-2.0f,2.0f);
  }

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
//if(pos_y<=scr_height-pl_height)
//LEFT_TRIGGER = false;
break;

case 4:
//RIGHT_TRIGGER = false;
RIGHT = false;
//if(pos_y<=scr_height-pl_height)
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
      //printf("%f, %f\n",gr_acc,pi);
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
      //printf("%f, %f\n",gr_acc,pi);
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