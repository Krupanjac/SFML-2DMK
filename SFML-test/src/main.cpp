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

    Clock clock;
    Time t1;
    double t1Sec;

    //sprites.loadTextures(txt,)
    Desavanja desavanja;


    decl(1024,768);
    
    Player igrac(pl_def_width,pl_def_height);
    Player igrac2(pl_def_width,pl_def_height);
    
 
     
    Animate pl_state_idle(&igrac,"res/EvilWizard/idle.png",8,107,68);
    Animate pl_state_run(&igrac,"res/EvilWizard/Run.png",8,107,68);
    Animate pl_state_jump(&igrac,"res/EvilWizard/Jump.png",2,90,70);
    Animate pl_state_fall(&igrac,"res/EvilWizard/Fall.png",2,90,70);
    igrac2.change_pl_y();
    Animate pl_state_idle2(&igrac2,"res/EvilWizard/idle.png",8,107,68);
    Animate pl_state_run2(&igrac2,"res/EvilWizard/Run.png",8,107,68);

    


    //aa
   ContextSettings settings;
    settings.antialiasingLevel = 8;

    //stvaranje glavnog prozora
    RenderWindow window(VideoMode(scr_width, scr_height), "Ratko Mladic Kombat!");


while (window.isOpen()){
        //hvatac desavanja
        Event event;

   t1 = clock.getElapsedTime();
   t1Sec = t1.asSeconds();
   if(t1Sec>0.15f){
    igrac2.update_pl_model(pl_state_idle2.get_sprite());
    if(!run && !jump && !fall){
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
    //sprite_buffer ZA RELOAD!!!
   clock.restart();
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
            if (event.type == Event::Closed)
                window.close();
            if (event.key.code == Keyboard::Escape)
                window.close();

}   

       fps.update();
       //printf("%.2f fps\n",(float)fps.getFPS()/100.f);

        igrac.pl_model = igrac.pl_position_update(igrac.pl_model,igrac2,jump_trigger,Collision::SimpleCollision(igrac,igrac2));
        igrac.pl_direction_render(&igrac2);

        //AABB(igrac,igrac2);

       if(!isPressed)
        igrac.jump(jump_trigger);

        igrac.gravity(jump_trigger);
       
        window.clear();
        //cout<<igrac.get_pl_position_x()<<" "<<igrac2.get_pl_position_x()<<endl;
        window.draw(igrac.get_pl_model());
        window.draw(igrac2.get_pl_model());
        window.display();

    }

}