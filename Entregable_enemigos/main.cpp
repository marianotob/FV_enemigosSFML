/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rizado
 *
 * Created on March 14, 2017, 3:04 AM
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "SpriteGame.h"



using namespace std;
using namespace sf;

int main() {


    RenderWindow window(VideoMode(720, 480), "enemigos");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    
    Texture *textura1;
    textura1 = new Texture();
    if (!textura1->loadFromFile("resources/topo.png")) {
        cerr << "Error cargando la imagen";
        exit(0);
    }
    
    Texture *textura2;
    textura2 = new Texture();
    if (!textura2->loadFromFile("resources/mosquito.png")) {
        cerr << "Error cargando la imagen";
        exit(0);
    }
    
    
    
    SpriteGame t(*textura1,3,28,0,31);
    SpriteGame t1(*textura1,35,60,0,31);
    SpriteGame t2(*textura1,67,92,0,31);
    SpriteGame t3(*textura1,3,28,32,63);
    SpriteGame t4(*textura1,35,60,32,63);
    SpriteGame t5(*textura1,67,92,32,63);
    SpriteGame t6(*textura1,3,28,64,95);
    
    Sprite **topo=new Sprite*[8];
    for(int i=0; i<8;i++){
        topo[i]= new Sprite ();
    }
    *topo[0]=t.GetSprite();
    *topo[1]=t1.GetSprite();
    *topo[2]=t3.GetSprite();
    *topo[3]=t4.GetSprite();
    *topo[4]=t5.GetSprite();
    *topo[5]=t2.GetSprite();
    *topo[6]=t6.GetSprite();
    *topo[7]=t2.GetSprite();
    
    
    SpriteGame m(*textura2,7,25,10,19);
    SpriteGame m2(*textura2,41,53,5,19);
        
    
    //declaracion de array
    Sprite **mosquito= new Sprite*[2];
    mosquito[0]= new Sprite ();
    mosquito[1]= new Sprite ();
    *mosquito[0]=m.GetSprite();
    *mosquito[1]=m2.GetSprite();
    
    
    
    
    float lenght=0;
    float angle=0;
    
    float x;
    float y;
    
    float x_topo=0;
    float y_topo=0;
    
    Clock reloj;
    Time tiempo;
    
    
    int contador_vueltas=0;
    int cambio_sprite=0;
    int cambio_topo=0;
    int retraso=12;
    
    //Bucle del juego
    while (window.isOpen()) {
        
        tiempo=reloj.restart();
        
            
            angle+=0.1;
            x= (2*cos(angle)+ lenght);
            y= (2*sin(angle)+lenght);
       
            m.Mover(x,y);
            m2.Mover(x,y);
            *mosquito[0]=m.GetSprite();
            *mosquito[1]=m2.GetSprite();
            
             
             
        Event event;
        while (window.pollEvent(event)) {
            
            
            switch (event.type) {
                    //Si se recibe el evento de cerrar la ventana la cierro
                case Event::Closed:
                    window.close();
                    break;

                
            }
        }

        window.clear();
        
        
        if(contador_vueltas%10==0){
            cambio_sprite=(cambio_sprite+1)%2;
        }
        
        if(contador_vueltas%20==0){
            if(retraso>12){
                cambio_topo=(cambio_topo+1)%8;
                if(cambio_topo==6){
                retraso=0;
                }    
            }
            
            if(retraso==6){
                x_topo=random()%30-15;
                y_topo=random()%30-15;
                for(int i=0; i<8;i++){
                    topo[i]->move(x_topo*tiempo.asMilliseconds(),y_topo*tiempo.asMilliseconds());
                }
            }
            retraso++;
        }
        contador_vueltas++;
        
       
      
        
        window.draw(*mosquito[cambio_sprite]);
        //window.draw(t2.GetSprite());
        window.draw(*topo[cambio_topo]);
        
       
       
        window.display();
    }

    return 0;
}

       





