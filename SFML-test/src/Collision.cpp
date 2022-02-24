#include <SFML/Graphics.hpp>
#include <map>
#include "Collision.hpp"
#include "global.h"
#include "igrac.h"

using namespace P;

namespace Collision
{
    class BitmaskManager
    {
    public:
        ~BitmaskManager() {
            std::map<const sf::Texture*, sf::Uint8*>::const_iterator end = Bitmasks.end();
            for (std::map<const sf::Texture*, sf::Uint8*>::const_iterator iter = Bitmasks.begin(); iter!=end; iter++)
                delete [] iter->second;
        }
        
        sf::Uint8 GetPixel (const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y) {
            if (x>tex->getSize().x||y>tex->getSize().y)
                return 0;
            
            return mask[x+y*tex->getSize().x];
        }
        
        sf::Uint8* GetMask (const sf::Texture* tex) {
            sf::Uint8* mask;
            std::map<const sf::Texture*, sf::Uint8*>::iterator pair = Bitmasks.find(tex);
            if (pair==Bitmasks.end())
            {
                sf::Image img = tex->copyToImage();
                mask = CreateMask (tex, img);
            }
            else
                mask = pair->second;
            
            return mask;
        }
        
        sf::Uint8* CreateMask (const sf::Texture* tex, const sf::Image& img) {
            sf::Uint8* mask = new sf::Uint8[tex->getSize().y*tex->getSize().x];
            
            for (unsigned int y = 0; y<tex->getSize().y; y++)
            {
                for (unsigned int x = 0; x<tex->getSize().x; x++)
                    mask[x+y*tex->getSize().x] = img.getPixel(x,y).a;
            }
            
            Bitmasks.insert(std::pair<const sf::Texture*, sf::Uint8*>(tex,mask));
            
            return mask;
        }
    private:
        std::map<const sf::Texture*, sf::Uint8*> Bitmasks;
    };
    
    BitmaskManager Bitmasks;

  bool CreateTextureAndBitmask(sf::Texture &LoadInto, const std::string& Filename)
    {
        sf::Image img;
        if (!img.loadFromFile(Filename))
            return false;
        if (!LoadInto.loadFromImage(img))
            return false;
        
        Bitmasks.CreateMask(&LoadInto, img);
        return true;
    }


bool SimpleCollision(const Player& igrac1, const Player& igrac2){

int pl1_width = igrac1.get_pl_width()*2;
int pl2_width = igrac2.get_pl_width()*2;

int pl1_height = igrac1.get_pl_height();
int pl2_height = igrac2.get_pl_height();

int x1 = igrac1.get_pl_position_x();
int x2 = igrac2.get_pl_position_x();

int y1 = igrac1.get_pl_position_y();
int y2 = igrac2.get_pl_position_y();


if((x1 < (x2+pl2_width)) && 
((x1 + pl1_width) > x2) &&  
(y1 < (y2 + pl2_height))&&
(y1+pl1_height > y2) ){
    return true;
}
else return false;



}


}





