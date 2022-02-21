#include "events.h"




void Desavanja::keyboard_pressed(Player &igrac,Player& igrac2,Event event){


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


void Desavanja::keyboard_released(Player &igrac,Player &igrac2,Event event){
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