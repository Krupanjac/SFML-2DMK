#include <thread>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "pl_animation.h"
#include "Collision.hpp"
#include "global.h"
#include "snd.h"
#include "igrac.h"
#include "maps.h"
#include "FPS.h"
#include "health_bar.h"
#include "events.h"

using namespace sf;
using namespace std;
using namespace P;


void AABB(Player igrac, Player igrac2){

if(Collision::SimpleCollision(igrac,igrac2)){
        cout<<"collision\n";
    }

}








int main(){
    //thread direction;
    bool jump_trigger = false;
    FPS fps;
    pressed = 0;

    int switcher = 0;

    Clock clock;
    Clock clock2;
    Time t1;
    Time t2;
    double t2Sec;
    double t1Sec;
    Font font;
    Text fps_counter;
    fps_counter.setCharacterSize(24);
    fps_counter.setFillColor(Color::White);

    //sprites.loadTextures(txt,)
    Desavanja desavanja;


    decl(1024,768);
    
    Player igrac(pl_def_width,pl_def_height);
    Player igrac2(pl_def_width,pl_def_height);
    Maps mapa(scr_width,scr_height,igrac.get_pl_position_x(),igrac.get_pl_position_y());
    
    Animate map_state(&mapa,"res\\Maps\\mk_RockMountains\\",8,100,300);
    mapa.update_map_model(map_state.get_sprite());
    mapa.update_map_sprite_cord(igrac.get_pl_position_x(),igrac.get_pl_position_y(),igrac2.get_pl_position_x(),igrac2.get_pl_position_y());
    Animate pl_state_idle(&igrac,"res\\EvilWizard\\idle.png",8,107,68);
    Animate pl_state_run(&igrac,"res\\EvilWizard\\Run.png",8,107,68);
    Animate pl_state_jump(&igrac,"res\\EvilWizard\\Jump.png",2,90,70);
    Animate pl_state_fall(&igrac,"res\\EvilWizard\\Fall.png",2,90,70);
    Animate pl_state_attack(&igrac,"res\\EvilWizard\\Attack1.png",8,107,68);
    Animate pl_state_attack2(&igrac,"res\\EvilWizard\\Attack2.png",8,107,68);
    igrac2.change_pl_y();
    Animate pl_state_idle2(&igrac2,"res\\EvilWizard\\idle.png",8,107,68);
    Animate pl_state_run2(&igrac2,"res\\EvilWizard\\Run.png",8,107,68);
    
   // HealthBar helthbar;

    //font
    if (!font.loadFromFile("font\\arial.ttf"))
{
    cout<<"GRESKA!"<<endl;
}
fps_counter.setFont(font);

    //aa
   ContextSettings settings;
    settings.antialiasingLevel = 8;

    MusicSFML muzika("res\\audio\\music\\terenac.ogg");

    

    //stvaranje glavnog prozora
    RenderWindow window(VideoMode(scr_width, scr_height), "Ratko Mladic Kombat!");
    window.setKeyRepeatEnabled(false);
while (window.isOpen()){
        //hvatac desavanja
        Event event;

   t1 = clock.getElapsedTime();
   t1Sec = t1.asSeconds();

    t2 = clock2.getElapsedTime();
    t2Sec = t2.asSeconds();

   if(t1Sec>0.15f){
    igrac2.update_pl_model(pl_state_idle2.get_sprite());
    if(!run && !jump && !fall && !attack){
    igrac.update_pl_model(pl_state_idle.get_sprite());
    
    }
    else if (run){
    igrac.update_pl_model(pl_state_run.get_sprite());
    //igrac2.update_pl_model(pl_state_run2.get_sprite(sprite_buffer));
    }
    if (jump){
    igrac.update_pl_model(pl_state_jump.get_sprite());
    //igrac2.update_pl_model(pl_state_run2.get_sprite(sprite_buffer));
    }
    if(fall){
    igrac.update_pl_model(pl_state_fall.get_sprite());

    }
    if(attack){
       // cout<<"pl_state_attack.get_pl_model_numeration() = "<<pl_state_attack.get_pl_model_numeration()<<endl;
        if((pl_state_attack.get_pl_model_numeration() == 7) && (switcher == 0)){
            attack = false;
            switcher = 1;
        }
        else if((pl_state_attack2.get_pl_model_numeration() == 7) && (switcher == 1)){
            attack = false;
            switcher = 0;
        }
        if(!switcher)
    igrac.update_pl_model(pl_state_attack.get_sprite());
    else if(switcher)
    igrac.update_pl_model(pl_state_attack2.get_sprite());
    }
    //sprite_buffer ZA RELOAD!!!
   clock.restart();
   // mapa.update_map_model(map_state.get_sprite(),igrac.get_pl_position_x(),igrac.get_pl_position_y());
   }
while (window.pollEvent(event))
{
    if (event.type == Event::KeyPressed){

        desavanja.keyboard_pressed(igrac,igrac2,event,jump_trigger);
    }

    if (event.type == Event::KeyReleased){
        desavanja.keyboard_released(igrac,event);
       
    }  


            //zatvori prozor
            if (event.type == Event::Closed){
               //call destructor for all musicSFML objects
                muzika.~MusicSFML();
                
                //call destructor for all objects

               /* igrac.~PlayerSFML();
                igrac2.~PlayerSFML();
                mapa.~MapSFML();
                */


                window.close();

            }
            if (event.key.code == Keyboard::Escape){
                muzika.~MusicSFML();

                       /* igrac.~PlayerSFML();
                igrac2.~PlayerSFML();
                mapa.~MapSFML();
                */
                window.close();
            }

}   

        fps.update();
        fps_counter.setString("FPS: "+to_string((float)fps.getFPS()/100.f));
        
       //printf("%.2f fps\n",(float)fps.getFPS()/100.f);

        igrac.pl_model = igrac.pl_position_update(igrac.pl_model,igrac2,jump_trigger,Collision::SimpleCollision(igrac,igrac2));
        igrac.pl_direction_render(&igrac2);

        //AABB(igrac,igrac2);

        mapa.update_pl_x(igrac.get_pl_position_x());
        mapa.pl_move_y(igrac.get_pl_position_y());
        if(t2Sec>0.4f){
        mapa.update_map_model(map_state.get_sprite());
       // cout<<map_state.get_map_sec_name()<<endl;
        clock2.restart();
        }
        mapa.update_map_sprite_cord(igrac.get_pl_position_x(),igrac.get_pl_position_y(),igrac2.get_pl_position_x(),igrac2.get_pl_position_y());
       if(!isPressed)
        igrac.jump(jump_trigger);

        igrac.gravity(jump_trigger);
       
        window.clear();
        //cout<<igrac.get_pl_position_x()<<" "<<igrac2.get_pl_position_x()<<endl;
        window.draw(mapa.get_map_model());
        window.draw(igrac.get_pl_model());
        window.draw(igrac2.get_pl_model());
        window.draw(fps_counter);
       
        window.display();

    }

}