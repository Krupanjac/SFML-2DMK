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
        void gravity();
        int duck();
        void change_pl_y();
        bool collision(Player);
        RectangleShape update_size(RectangleShape);

        RectangleShape pl_render_update(RectangleShape,Player);


        private:
        //Sirina i visina igraca
        double pl_width;
        double pl_height;
        //Pozicija u odnosu na prozor
        double pos_x;
        double pos_y;
        //Smer kretanja
        bool UP;
        bool DOWN;
        bool LEFT;
        bool RIGHT;

        bool LEFT_TRIGGER;
        bool RIGHT_TRIGGER;
        bool FIRST_PASS;
        
        //Gravitacija
        double gr_acc;
        double pl_speed;

        
        bool flag = true;

        





    };
}