#include <iostream>
#include <SFML/Audio.hpp>
#include <snd.h>
#include <string>

using namespace std;
using namespace sf;

MusicSFML::MusicSFML(string ime)
{
     muzika = new Music;
    giveName(ime);
    playMusic();

   

}

MusicSFML::~MusicSFML()
{
    muzika->stop();
    delete muzika;
}

void MusicSFML::playMusic()
{
    if(!muzika->openFromFile(getName())){
        cout<<"Error loading music\n"<<endl;
    }
    else{
    cout<<"Playing music\n"<<getName()<<endl;
    muzika->setLoop(true);
    muzika->setVolume(60);
   // muzika->setPlayingOffset(sf::seconds(60));
    muzika->play();
    
    }
}

string MusicSFML::getName()
{
    return name;
}

void MusicSFML::giveName(string ime)
{
    name = ime;
}