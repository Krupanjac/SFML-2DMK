#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "pl_animation.h"
#include "Collision.hpp"
#include "global.h"
#include "igrac.h"

using namespace sf;
using namespace std;
using namespace P;






int main(){
    int brojac = 0;
    pressed = 0;

    Texture txt;
    txt.loadFromFile("res/4.png");

    
    //sprites.loadTextures(txt,)
   
    decl(1024,768);
    
    Player igrac(pl_def_width,pl_def_height,&txt);
    Player igrac2(pl_def_width,pl_def_height,&txt);
    Animate sprites(pl_def_width,pl_def_height,&txt);
     igrac2.change_pl_y();
     igrac2.pl_render_reload();

    sprites.load_texture();
    
    //test.setTexture(txt);
    //test.setTextureRect(IntRect(10,10,100,200));



   
    
    //igrac.pl_model = igrac.pl_render(&txt);
    //igrac2.pl_model = igrac2.pl_render(&txt);


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
                igrac.pl_model = igrac.pl_render_update(igrac.pl_model,igrac2);
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
                //rect=igrac.update_size(rect);
                
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
    if(Collision::PixelPerfectTest(igrac.pl_model,igrac2.pl_model)){
        cout<<"collision\n";
    }

        igrac.pl_model = igrac.pl_render_update(igrac.pl_model,igrac2);
        igrac.pl_direction_render(&igrac2);
        igrac.gravity();
        igrac.update_pl_model(sprites.get_sprite(brojac));
        window.clear();
        window.draw(igrac.pl_model);
        window.draw(igrac2.pl_model);
        window.display();
        brojac++;
    }

}