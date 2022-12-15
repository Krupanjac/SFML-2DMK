#include <iostream>
#include <SFML/Audio.hpp>
#include <string>


using namespace std;
using namespace sf;

class MusicSFML
{
public:

MusicSFML(string);
~MusicSFML();

void playMusic();

string getName();

void giveName(string);

private:

Music *muzika;

string name;

};