#include "events.h"
#include "global.h"




void Desavanja::keyboard_pressed(Player &igrac,Player& igrac2,Event event,bool jump_trigger){



                if (event.key.code == Keyboard::W)
        {
            igrac.pl_set_pos(1);

        }

           /* if (event.key.code == Keyboard::S)
            {
                igrac.pl_set_pos(2);
                //igrac.pl_model = igrac.pl_render_update(igrac.pl_model,igrac2,jump_trigger);
            }*/
                if (event.key.code == Keyboard::A)
            {
                if(igrac.get_pl_position_y() < (scr_height-igrac.get_pl_height()))
                ::inAir = true;
                else ::inAir = false;
                igrac.pl_set_pos(3);
                run = true;
            }

                if (event.key.code == Keyboard::D)
            {
                if(igrac.get_pl_position_y() < (scr_height-igrac.get_pl_height()))
                ::inAir = true;
                else ::inAir = false;
                igrac.pl_set_pos(4);
                run = true;
            }
            if (event.key.code == Keyboard::Space)
            {
            
            igrac.pl_set_pos(1);
            
            //printf("%d pressed\n",pressed);
            }    
            if (event.key.code == Keyboard::F){
                //
                 ::attack = true;
            }
    
}


void Desavanja::keyboard_released(Player &igrac,Event event){
         if (event.key.code == Keyboard::W)
        {
            isPressed = false;
            //isPressed = false;
            igrac.pl_update_pos(1);
            //trigger = false;
        }

            /*if (event.key.code == Keyboard::S)
            {
                igrac.pl_update_pos(2);
                //rect=igrac.update_size(rect);
                
            }*/
                if (event.key.code == Keyboard::A)
            {
                igrac.pl_update_pos(3);
                run = false;
            }

                if (event.key.code == Keyboard::D)
            {
                igrac.pl_update_pos(4);
                run = false;
                
            }
            if (event.key.code == Keyboard::Space)
        {
            isPressed = false;
           
            igrac.pl_update_pos(1);
        } 
        if (event.key.code == Keyboard::F){
          
            //::attack = false;
        }   


}