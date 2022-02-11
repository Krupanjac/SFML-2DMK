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

    for(int i = 0; i<n; i++){
       state[i].setTexture(*texture);
       state[i].setTextureRect(IntRect(x,y,get_pl_width(),get_pl_height()));
       state[i].setScale(2,2);
       update_pl_height();
       update_pl_width();
       state[i].setPosition(get_pl_position_x(),get_pl_position_y());
       x+=247;
    }

}

Sprite Animate::get_sprite(int br){
    return state[br];
}
