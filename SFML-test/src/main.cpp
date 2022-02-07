#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "global.h"
#include "igrac.h"

using namespace sf;
using namespace std;
using namespace P;

int main(){
    pressed = 0;

    RectangleShape rect;
    RectangleShape rect2;
    decl(1024,768);
    Player igrac(pl_def_width,pl_def_height);
    Player igrac2(pl_def_width,pl_def_height);
    igrac2.change_pl_y();
    
    rect = igrac.pl_render();
    rect2 = igrac2.pl_render();

    //aa
   ContextSettings settings;
    settings.antialiasingLevel = 8;

    //stvaranje glavnog prozora
    RenderWindow window(VideoMode(scr_width, scr_height), "Ratko Mladic Kombat!");
    
    //glavna petlja
    //window.setKeyRepeatEnabled(false);
    while (window.isOpen()){
        //hvatac desavanja
        Event event;
while (window.pollEvent(event))
{
    if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::W)
        {
            igrac.pl_set_pos(1);

        }

            if (event.key.code == Keyboard::S)
            {
                igrac.pl_set_pos(2);
                rect = igrac.pl_render_update(rect,igrac2);
            }
                if (event.key.code == Keyboard::A)
            {
                igrac.pl_set_pos(3);
            }

                if (event.key.code == Keyboard::D)
            {
                igrac.pl_set_pos(4);
            }
            if (event.key.code == Keyboard::Space)
            {
            
            igrac.pl_set_pos(1);
            
            //printf("%d pressed\n",pressed);
            }    
    }

    if (event.type == Event::KeyReleased){
                if (event.key.code == Keyboard::W)
        {
            //isPressed = false;
            igrac.pl_update_pos(1);
        }

            if (event.key.code == Keyboard::S)
            {
                igrac.pl_update_pos(2);
                rect=igrac.update_size(rect);
                
            }
                if (event.key.code == Keyboard::A)
            {
                igrac.pl_update_pos(3);
            }

                if (event.key.code == Keyboard::D)
            {
                igrac.pl_update_pos(4);
                
            }
            if (event.key.code == Keyboard::Space)
        {
           
            igrac.pl_update_pos(1);
        }    
    }  


            //zatvori prozor
            if (event.type == Event::Closed)
                window.close();
            if (event.key.code == Keyboard::Escape)
                window.close();

}

        rect = igrac.pl_render_update(rect,igrac2);
        igrac.gravity();
        window.clear();
        window.draw(rect);
        window.draw(rect2);
        window.display();
    }

}