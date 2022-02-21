#include <thread>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "pl_animation.h"
#include "Collision.hpp"
#include "global.h"
#include "igrac.h"
#include "FPS.h"
#include "events.h"

using namespace sf;
using namespace std;
using namespace P;


void PP(Sprite pl1, Sprite pl2){

if(Collision::BoundingBoxTest(pl1,pl2)){
        cout<<"collision\n";
    }
    else
     cout<<"no collision"<<endl;

}


int main(){
    //thread direction;

    int reload = 0;
    FPS fps;

    Desavanja desavanja;


    int sprite_buffer = 0;
    pressed = 0;

    Clock clock;
    Time t1;
    double t1Sec;

    //sprites.loadTextures(txt,)
   
    decl(1024,768);
    
    Player igrac(pl_def_width,pl_def_height);
    Player igrac2(pl_def_width,pl_def_height);
    
 
     
    Animate sprites(&igrac);
    igrac2.change_pl_y();
    Animate sprites2(&igrac2);

    


    //aa
   ContextSettings settings;
    settings.antialiasingLevel = 8;

    //stvaranje glavnog prozora
    RenderWindow window(VideoMode(scr_width, scr_height), "Ratko Mladic Kombat!");


    while (window.isOpen()){
        //hvatac desavanja
        Event event;
        if(sprite_buffer>5) sprite_buffer = 0;

   t1 = clock.getElapsedTime();
   t1Sec = t1.asSeconds();
   if(t1Sec>0.15f){
    igrac.update_pl_model(sprites.get_sprite(sprite_buffer));
    igrac2.update_pl_model(sprites2.get_sprite(sprite_buffer));
    //sprite_buffer ZA RELOAD!!!
    if(reload<10) {
        
    //igrac2.pl_render_reload();
    reload++;
    }
   clock.restart();
   }
   
while (window.pollEvent(event))
{
    if (event.type == Event::KeyPressed){

        desavanja.keyboard_pressed(igrac,igrac2,event);
    }

    if (event.type == Event::KeyReleased){
        desavanja.keyboard_released(igrac,igrac2,event);
       
    }  


            //zatvori prozor
            if (event.type == Event::Closed)
                window.close();
            if (event.key.code == Keyboard::Escape)
                window.close();

}   

       fps.update();
       //printf("%.2f fps\n",(float)fps.getFPS()/100.f);


        igrac.pl_model = igrac.pl_render_update(igrac.pl_model,igrac2);
        igrac.pl_direction_render(&igrac2,&reload);
        if(Collision::SimpleCollision(igrac,igrac2)){
            cout<<"collision\n";
        }
        //thread collision(PP,igrac.get_pl_model(),igrac2.get_pl_model());
        //collision.detach();
        //PP(igrac.get_pl_model(),igrac2.get_pl_model());
        igrac.gravity();
        window.clear();
        cout<<igrac.get_pl_position_x()<<" "<<igrac2.get_pl_position_x()<<endl;
        window.draw(igrac.get_pl_model());
        window.draw(igrac2.get_pl_model());
        window.display();
        sprite_buffer++;


        
    }

}