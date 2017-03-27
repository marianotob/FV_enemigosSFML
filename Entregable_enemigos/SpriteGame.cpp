/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SpriteGame.cpp
 * Author: rizado
 * 
 * Created on March 14, 2017, 5:54 PM
 */

#include "SpriteGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//#include<Randomizer.hpp>
#include<stdlib.h>
#include<time.h>

using namespace sf;
using namespace std;

SpriteGame::SpriteGame(Texture &tex,int xi, int xf, int yi, int yf) {
    this->inicio.x = xi;
    this->inicio.y = yi;
    this->fin.x = xf;
    this->fin.y = yf;
    
    
    animacion= new Sprite*[7];
    dibujo = new Sprite();
    dibujo->setTexture(tex);

    this->dimension.x = this->fin.x - this->inicio.x;
    this->dimension.y = this->fin.y - this->inicio.y;

    this->centro.x = this->dimension.x / 2;
    this->centro.y = this->dimension.y / 2;


    Init();
   
      
}

void SpriteGame::Init() {
    
    srand(time(NULL));

    int initX =rand()%600;
    int initY =rand()%400;
    
    
    //Centroide
    this->dibujo->setOrigin(this->centro.x, this->centro.y);
    
    //Cojo el sprite que me interesa por defecto del sheet
    IntRect palaRect = IntRect(this->inicio.x, this->inicio.y, this->dimension.x, this->dimension.y);
    dibujo->setTextureRect(palaRect);

    // Colocar el sprite en la pantalla
    this->dibujo->setPosition(initX, initY);
    
    
}



Sprite SpriteGame::GetSprite(){
    return *dibujo;
}


void SpriteGame::Mover(float x, float y){
    //v=e/t---> e=v*t
    dibujo->move(x,y);
}











