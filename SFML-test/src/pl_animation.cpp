#include "igrac.h"
#include <Collision.hpp>
#include "pl_animation.h"
#include "maps.h"
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
        temp->pl_model_numeration = i;
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

void Animate::load_map_texture(Maps *mapa,int model_buffer_size,int x_pos, int y_pos,string model_status){
    state *temp = this->head;
    state *trenutni;
    int n = model_buffer_size;
    int x = x_pos;
    int y = y_pos;
    int j = 1;
    for(int i = 0; i<n; i++){
        if(i==0){
        temp->texture_idle = new Texture;
        temp->texture_idle = init_texture(model_status+"0.png");
       temp->model->setTexture(*temp->texture_idle);
       temp->map_sec_name = model_status+to_string(i)+".png";
       
       temp->model->setTextureRect(IntRect(x,y,mapa->get_map_width(),mapa->get_map_height()));
       temp->model->setScale(1.5,1.5); 
       temp->model->setPosition(0,0);
        }
        else if (i % 2 != 0){
            //cout<<i<<": "<<model_status+to_string(j)+".png"<<endl;
        temp->texture_idle = new Texture;
        temp->texture_idle = init_texture(model_status+to_string(j)+".png");
       temp->model->setTexture(*temp->texture_idle);
            temp->model->setTextureRect(IntRect(x,y,mapa->get_map_width(),mapa->get_map_height()));
            temp->model->setScale(1.5,1.5);
            temp->model->setPosition(0,0);
            temp->map_sec_name = model_status+to_string(j)+".png";
            j++;

        }
        else if (i % 2 == 0){
             //cout<<i<<":(nula) "<<model_status+"0.png"<<endl;
            init_texture(model_status+"0.png");
            temp->texture_idle = new Texture;
            temp->texture_idle = init_texture(model_status+"0.png");
            temp->model->setTexture(*temp->texture_idle);
            temp->model->setTextureRect(IntRect(x,y,mapa->get_map_width(),mapa->get_map_height()));
            temp->model->setScale(1.5,1.5);
            temp->model->setPosition(0,0);
            temp->map_sec_name = model_status+"0.png";
        }
  
           trenutni = temp;
           temp->next = nullptr;
           temp = temp->next;
           if(i+1<n)
           temp = new state;
           trenutni->next = temp;
              if(i+1<n)
           temp->model = new Sprite;
    }
    trenutni->next = head;
   }



Sprite *Animate::get_sprite(){
    head = head->next;
    return head->model;
}

string Animate::get_map_sec_name(){
    return head->map_sec_name;
}
 
Animate::state *Animate::get_master_state(){
    return master_head;
}

Sprite *Animate::get_master_sprite(){
    return master_head->model;
}

int Animate::get_pl_model_numeration(){
    return head->pl_model_numeration;
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

Animate::Animate(Maps* mapa,string model_status,int model_buffer_size,int x_pos, int y_pos){

    //state = new Sprite[8];
    texture = new Texture;
    texture = init_texture(model_status+"0.png");
    head = new state;
    head->next = nullptr;
    head->model = new Sprite;
    
    load_map_texture(mapa,model_buffer_size,x_pos,y_pos,model_status);
    master_head = head;
    
}

