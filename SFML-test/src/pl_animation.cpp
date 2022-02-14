#include "igrac.h"
#include "pl_animation.h"
#include <iostream>

using namespace P;

void Animate::load_texture(Player *igrac){
    int n = 5;
    int x = 108;
    int y = 70;
    texture.loadFromFile("res/EvilWizard/idle.png");
    texture.setSmooth(true);
    // NE MOZE OVAKO
    for(int i = 0; i<n; i++){
       state[i].setTexture(texture);
       state[i].setTextureRect(IntRect(x,y,igrac->get_pl_width(),igrac->get_pl_height()));
       state[i].setScale(2,2);
       igrac->update_pl_height();
       igrac->update_pl_width();
       state[i].setPosition(igrac->get_pl_position_x(),igrac->get_pl_position_y());
       x+=247;
    }

}

Sprite Animate::get_sprite(int br){
    return state[br];
}

Animate::Animate(){

    state = new Sprite[8];

}
