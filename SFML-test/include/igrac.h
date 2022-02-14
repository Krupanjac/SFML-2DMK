#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace P{

    class Player{

        public:
        Sprite pl_model;
        void update_pl_model(Sprite);


        void update_pl_width();
        void update_pl_height();

        int get_pl_width();
        int get_pl_height();
        int get_pl_position_x();
        int get_pl_position_y();

        void pl_direction_render(Player*);
        Player(double, double, Texture*);


        void pl_render_reload();
        Sprite pl_render(Texture*);
        //pomeranje
        void pl_set_pos(int);
        void pl_update_pos(int);
        void gravity();
        int duck();
        void change_pl_y();
        bool collision(Player);
        RectangleShape update_size(RectangleShape);

        Sprite pl_render_update(Sprite,Player);


        protected:
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
