#include "maps.h"
#include "pl_animation.h"
#include "global.h"

using namespace std;

void Maps::update_map_model(Sprite *m_model) {
    this->map_model = m_model;
   // cout<<"x: "<<x<<" y: "<<y<<endl;
    
}

void Maps::update_map_sprite_cord(int pl_move_x,int pl_move_y) {
    x = pl_move_x;
    y = pl_move_y;
    this->map_model->setTextureRect(IntRect(x,y,this->get_map_width(),this->get_map_height()));
    this->map_model->setScale(this->map_scale_w,this->map_scale_h);
}

Sprite& Maps::get_map_model() const {
     auto temp = this->map_model;
     return temp[0];
}

double Maps::get_map_width(){
    return this->map_width;
}

double Maps::get_map_height() {
    return this->map_height;
}


Maps::Maps(double m_width, double m_height,int c_pl_x,int c_pl_y) {
    pl_x = c_pl_x;
    pl_y = c_pl_y;
    this->map_width = m_width;
    this->map_height = m_height;

    this->map_scale_w = 1.3;
    this->map_scale_h = 1.3;
}

void Maps::pl_move_x(int new_pl_x) {
    if(pl_x!=new_pl_x){
        if(pl_x<new_pl_x){
            this->x += 1;
        }
        else if(pl_x>new_pl_x){
            this->x -= 1;
        }
        update_pl_x(new_pl_x);
    }
    
}

void Maps::pl_move_y(int new_pl_y) {
 //  cout<<"pl_y: "<<pl_y<<endl;
  //  cout<<"new_pl_y: "<<new_pl_y<<endl;
    if(pl_y!=new_pl_y){
        if(pl_y<new_pl_y){
            pl_jump_fall();
           // cout<<"ovde padam"<<endl;
            //this->y += 1;cls
        }
        else if(pl_y>new_pl_y){
            pl_jump_acc();
            
              
           // cout<<"ovde skacem"<<endl;
            //this->y -= 1;
        }
        update_pl_y(new_pl_y);
        update_map_scale();
    }
}

void Maps::update_pl_x(int x) {
    this->pl_x = x;
}

void Maps::update_pl_y(int y) {
    this->pl_y = y;
}

void Maps::pl_jump_acc() {
    if(map_scale_w>1.0 && map_scale_h>1.0){
    map_scale_w -=incr;
    map_scale_h -=incr;
    incr+=(incr_def/50);
    //cout<<"map_scale_w: "<<map_scale_w<<" map_scale_h: "<<map_scale_h<<endl;
    }
}

void Maps::pl_jump_fall() {
    if(map_scale_w<1.3 && map_scale_h<1.3){
    map_scale_w +=incr;
    map_scale_h +=incr;
    if(incr>incr_def)
    incr-=(incr_def/50);
    //cout<<"map_scale_w: "<<map_scale_w<<" map_scale_h: "<<map_scale_h<<endl;
    }

}

void Maps::update_map_scale() {
    //cout<<"map_scale_w: "<<map_scale_w<<" map_scale_h: "<<map_scale_h<<endl;
    this->map_model->setScale(map_scale_w,map_scale_h);
}