#include "maps.h"
#include "pl_animation.h"
#include "global.h"

using namespace std;

void Maps::update_map_model(Sprite *m_model,int pl_move_x,int pl_move_y) {
    x = pl_move_x;
    y = pl_move_y;
    m_model->setTextureRect(IntRect(x,y,this->get_map_width(),this->get_map_height()));
    this->map_model = m_model;
}

Sprite& Maps::get_map_model() const {
     auto temp = this->map_model;
     return temp[0];
}

double Maps::get_map_width() const {
    return this->map_width;
}

double Maps::get_map_height() const {
    return this->map_height;
}


Maps::Maps(double m_width, double m_height,int c_pl_x,int c_pl_y) {
    pl_x = c_pl_x;
    pl_y = c_pl_y;
    this->map_width = m_width;
    this->map_height = m_height;
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
    if(pl_y!=new_pl_y){
        if(pl_y<new_pl_y){
            this->y += 1;
        }
        else if(pl_y>new_pl_y){
            this->y -= 1;
        }
        update_pl_y(new_pl_y);
    }
}

void Maps::update_pl_x(int x) {
    this->pl_x = x;
}

void Maps::update_pl_y(int y) {
    this->pl_y = y;
}
