#pragma once
#include "igrac.h"

using namespace P;
namespace Collision {

    bool CreateTextureAndBitmask(sf::Texture &LoadInto, const std::string& Filename);
     bool SimpleCollision(const Player& igrac1, const Player& igrac2);
}



