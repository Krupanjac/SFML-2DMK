#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace P{

    class Player{

        public:

        Player(double, double);
        RectangleShape pl_render();
        //pomeranje
        void pl_set_pos(int);
        void pl_update_pos(int);
        RectangleShape pl_render_update(RectangleShape);


        private:
        double pl_width;
        double pl_height;

        double pos_x;
        double pos_y;

        bool UP;
        bool DOWN;
        bool LEFT;
        bool RIGHT;
        

        





    };
}