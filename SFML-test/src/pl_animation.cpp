#include "igrac.h"
#include <Collision.hpp>
#include "pl_animation.h"
#include <iostream>

using namespace P;


Texture* Animate::init_texture(){
    Texture *temp = new Texture;
    
    if(!Collision::CreateTextureAndBitmask(*temp,"res/EvilWizard/idle.png")){
        cout<<"TEXTURE MISSING!"<<endl;
    }
    //temp->setSmooth(true);
    return temp;
}

void Animate::load_texture(Player *igrac){
    state *temp = this->head;
    state *trenutni;
    int n = 5;
    int x = 107;
    int y = 68;
    for(int i = 0; i<n; i++){
       temp->model->setTexture(*texture);
       temp->model->setTextureRect(IntRect(x,y,igrac->get_pl_width(),igrac->get_pl_height()));
       temp->model->setScale(2,2);
       // cout<<igrac->get_pl_width()<<" "<<igrac->get_pl_height()<<" "<<igrac->get_pl_position_x()<<" "<<igrac->get_pl_position_y()<<endl;
      if((pl_def_height*2)>igrac->get_pl_height()){
          cout<<"usao\n";
       igrac->update_pl_height();
       igrac->update_pl_width();
      
       temp->model->setPosition(igrac->get_pl_position_x(),igrac->get_pl_position_y());
      }
      else temp->model->setPosition(igrac->get_pl_position_x(),igrac->get_pl_position_y());
      
       x+=250;
       if(i<n){ 
           trenutni = temp;
           temp = temp->next;
           temp = new state;
           trenutni->next = temp;
           temp->model = new Sprite;
       }
       else
        temp->next = head;
    }

}

Sprite* Animate::get_sprite(int br){
    state *tmp = head;
    int i = 0;
    while (i<(br-1) && br!=0){
    tmp = tmp->next;
    i++;
    }

    return tmp->model;
}

Animate::Animate(Player* igrac){

    //state = new Sprite[8];
    texture = new Texture;
    texture = init_texture();
    head = new state;
    head->next = nullptr;
    head->model = new Sprite;

    load_texture(igrac);
    
}


