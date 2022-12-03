#include "maps.h"
#include "pl_animation.h"
#include "global.h"

using namespace std;

void Maps::update_map_model(Sprite *m_model) {
    this->map_model = m_model;
}

Sprite& Maps::get_map_model() const {
     auto temp = this->map_model;
     return temp[0];
}
