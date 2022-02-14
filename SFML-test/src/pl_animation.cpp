#include "igrac.h"
#include "pl_animation.h"
#include <iostream>

using namespace P;

void Animate::load_texture(){
    int n = 5;
    int x = 108;
    int y = 70;
    texture->loadFromFile("res/EvilWizard/idle.png");
    texture->setSmooth(true);
    // NE MOZE OVAKO
    for(int i = 0; i<n; i++){
       state[i].setTexture(*texture);
       state[i].setTextureRect(IntRect(x,y,get_pl_position_x(),get_pl_position_y()));
       state[i].setScale(2,2);
       update_pl_height();
       update_pl_width();
       state[i].setPosition(pos_x,pos_y);
       x+=247;
    }

}

Sprite Animate::get_sprite(int br){
    return state[br];
}
Animate::Animate(double w, double h, Texture *txt) : Player (w,h,txt){
pl_width = w;
pl_height = h;

pos_x = 0;
pos_y = 500;

}