// #include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

VideoMode vm(800,600);
RenderWindow window(vm,"Hello Screen");

int main(){
    while(window.isOpen()){

        window.clear();
        //draw
        window.display();
    }
    return 0;
}