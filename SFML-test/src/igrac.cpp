#include "igrac.h"
#include "global.h"
#include "Collision.hpp"
#include <cmath>
#include <SFML/Window.hpp>

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
pl_speed = 0.08;
pi = 3.14;

LEFT_TRIGGER = false;
RIGHT_TRIGGER = false;
FIRST_PASS = true;

LEFT_COLLISION = false;
RIGHT_COLLISION = false;
}

bool Player::get_right_collision() const{

return this->RIGHT_COLLISION;

}

bool Player::get_left_collision() const{

return this->LEFT_COLLISION;

}

void Player::update_right_collision_false() {

this->RIGHT_COLLISION = false;



}

void Player::update_left_collision_false() {

this->LEFT_COLLISION = false;



}


void Player::update_right_collision_true() {

this->RIGHT_COLLISION = true;



}

void Player::update_left_collision_true() {

this->LEFT_COLLISION = true;



}



Sprite& Player::get_pl_model() const{
  auto temp = this->pl_model;

  return temp[0];
}

void Player::update_pl_model(Sprite* state){
this->pl_model= state;
//this->pl_model->setPosition(pos_x, pos_y);
}



void Player::update_pl_width(){
  this->pl_width*=model_size;
}
void Player::update_pl_height(){
  this->pl_height*=model_size;
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
  pos_x=scr_width/2+pl_width;
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

void Player::jump(bool& trigger){

if(trigger){
::jump = true;
//cout<<pos_y<<" "<<scr_height-(this->pl_height)<<endl;
if(pos_y>scr_height-(this->pl_height*2.3f)){
  pos_y-=gr_acc;
  gr_acc+= incr;
  if(incr < 0.0001)
  incr*=2;


}
else{
isPressed = true;
trigger = false;
gr_acc = 0;
::fall = true;
::incr = 0.00001;
}



}


}


//COLLISION PROBLEM POPRAVITI!!!
Sprite* Player::pl_position_update(Sprite *r,Player igrac, bool& trigger,bool collision){
//cout<<pos_y<<" "<<pos_x<<endl;
 if(UP &&(pos_y>scr_height-pl_height)&& (pos_x>(-1))&&(pos_x<=scr_width+pl_width)){
     // Resiti ovaj deo!!!
     if(!isPressed)
      trigger = true;
 }
 if(DOWN &&(floor(pos_y)==floor(scr_height-pl_height))){
   pl_height=pl_def_height/2;
   //r.setSize(Vector2f(pl_width,pl_height));
    }

  
 if(LEFT && (pos_x>0)) {
 
   if(::inAir) pos_x -= pl_speed/2;
   else pos_x-=pl_speed;

 }

 if(RIGHT&&(pos_x<=scr_width)){ 
  
     if(::inAir) pos_x += pl_speed/2;
   else pos_x+=pl_speed;
    
 }

 
r->setPosition(this->pos_x, this->pos_y);

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
  //igr2->pl_render_reload();

if(igr2->get_pl_position_x()>this->get_pl_position_x()){
  igr2->pl_model->setScale(-model_size,model_size);
  this->pl_model->setScale(model_size,model_size);
  update_right_collision_true();
  update_left_collision_false();
  
  //this->pl_model->setTextureRect(IntRect(1,3,-pl_width,pl_height));
}
  else{
    igr2->pl_model->setScale(model_size,model_size);
    this->pl_model->setScale(-model_size,model_size);
    update_right_collision_false();
    update_left_collision_true();
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


void Player::gravity(bool jump_trigger){
if(!jump_trigger){
  ::jump = false;
  // Y IDE OD 0 DO 1 A X JE SIN
  if(pos_y-(scr_height-pl_height)<1 && pos_y-(scr_height-pl_height)>(-1)){
    ::fall = false;
  }

  if(RIGHT_TRIGGER){
    LEFT_TRIGGER = false;
    //cout<<pos_y<<" "<<scr_height-pl_height<<endl;
    if(pos_y<=scr_height-pl_height){
      //printf("%f, %f\n",gr_acc,pi);
      if(gr_acc<=pi/2)
        pos_y+= gr_acc;
        else
        pos_y-=gr_acc;
        if(pos_x<scr_width-pl_width/2)
        pos_x += gr_acc/2;
        gr_acc+=incr;

      if(incr <0.0001) incr*=2;
        
        if(gr_acc>=pi){
         // ::jump = false;
         gr_acc=0;
         incr = 0.00001;
        }
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
        pos_y+= gr_acc;
        else
        pos_y-=gr_acc;
        if(pos_x>0)
        pos_x -= gr_acc/2;
        gr_acc+=incr;
        if(incr < 0.0001)
        incr*= 2;
        if(gr_acc>=pi){
          //::jump = false;
          incr = 0.00001;
         gr_acc=0;
        }
        //RIGHT_TRIGGER = false;   
       //if(pos_x<scr_width-pl_width) pos_x+=gr_acc/30;
    }
   
  }
  else if(!LEFT_TRIGGER && !RIGHT_TRIGGER){
    if(pos_y<=scr_height-pl_height){
      //printf("%f, %f\n",gr_acc,pi);
      if(gr_acc<=pi/2)
        pos_y+= gr_acc;
        else
        pos_y-=gr_acc;
        gr_acc+=incr;
        if(incr < 0.0001)
        incr*=2;
        
        if(gr_acc>=pi){
         gr_acc=0;
        incr = 0.00001;
        }
        //RIGHT_TRIGGER = false;   
       //if(pos_x<scr_width-pl_width) pos_x+=gr_acc/30;
    }

  }
  
}else ::fall = false;
}