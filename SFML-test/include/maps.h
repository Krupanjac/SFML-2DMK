#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Maps{

public:
Sprite* map_model;

void update_map_model(Sprite*);

Sprite& get_map_model() const;





};