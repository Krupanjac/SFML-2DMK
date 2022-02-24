#include "igrac.h"
#include <Collision.hpp>
#include "pl_animation.h"
#include <iostream>

using namespace P;


Texture* Animate::init_texture(string model_status){
    Texture *temp = new Texture;
    //idle
    if(!Collision::CreateTextureAndBitmask(*temp,model_status)){
        cout<<"TEXTURE MISSING!"<<endl;
    }
    //temp->setSmooth(true);
    return temp;
}

void Animate::load_texture(Player *igrac,int model_buffer_size,int x_pos, int y_pos){
    state *temp = this->head;
    state *trenutni;
    int n = model_buffer_size;
    int x = x_pos;
    int y = y_pos;
    for(int i = 0; i<n; i++){
       temp->model->setTexture(*texture);
       temp->model->setTextureRect(IntRect(x,y,igrac->get_pl_width(),igrac->get_pl_height()));
       temp->model->setScale(model_size,model_size);
       // cout<<igrac->get_pl_width()<<" "<<igrac->get_pl_height()<<" "<<igrac->get_pl_position_x()<<" "<<igrac->get_pl_position_y()<<endl;
      if((pl_def_height*2)>igrac->get_pl_height()){
       igrac->update_pl_height();
       igrac->update_pl_width();
      
       temp->model->setPosition(igrac->get_pl_position_x(),igrac->get_pl_position_y());
      }
      else temp->model->setPosition(igrac->get_pl_position_x(),igrac->get_pl_position_y());
      
       x+=250;
  
           trenutni = temp;
           temp = temp->next;
           temp = new state;
           trenutni->next = temp;
           temp->model = new Sprite;

    }
    trenutni->next = head;
}

Sprite *Animate::get_sprite(){
    head = head->next;
    return head->model;
}

Animate::Animate(Player* igrac,string model_status,int model_buffer_size,int x_pos, int y_pos){

    //state = new Sprite[8];
    texture = new Texture;
    texture = init_texture(model_status);
    head = new state;
    head->next = nullptr;
    head->model = new Sprite;

    load_texture(igrac,model_buffer_size,x_pos,y_pos);
    
}


