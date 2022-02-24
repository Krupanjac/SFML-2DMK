#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace P{

    class Player{

        public:
        Sprite* pl_model;
        void update_pl_model(Sprite*);

        Sprite& get_pl_model() const;

        void update_pl_width();
        void update_pl_height();

        int get_pl_width() const;
        int get_pl_height() const;
        int get_pl_position_x() const;
        int get_pl_position_y() const;

        bool get_right_collision() const;
        bool get_left_collision() const;

        void update_right_collision_true();
        void update_left_collision_true();

        void update_right_collision_false();
        void update_left_collision_false();

        void pl_direction_render(Player*);
        Player(double, double);


        void pl_render_reload();
        Sprite pl_render(Texture*);
        //pomeranje
        void pl_set_pos(int);
        void pl_update_pos(int);
        void jump(bool&);
        void gravity(bool);
        int duck();
        void change_pl_y();
        bool collision(Player);
        RectangleShape update_size(RectangleShape);

        Sprite* pl_position_update(Sprite*,Player,bool&,bool);


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
        

        bool LEFT_COLLISION;
        bool RIGHT_COLLISION;

        //Gravitacija
        double gr_acc;
        double pl_speed;

        
        
        bool flag = true;

        friend class Animate;


    };
}
