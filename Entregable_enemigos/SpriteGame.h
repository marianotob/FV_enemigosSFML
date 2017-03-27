/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SpriteGame.h
 * Author: rizado
 *
 * Created on March 14, 2017, 5:53 PM
 */

#ifndef SPRITEGAME_H
#define SPRITEGAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;
using namespace std;

class SpriteGame {
public:
    SpriteGame(Texture &tex,int xi, int xf, int yi, int yf);
    Sprite GetSprite();
    void Init();
    void Mover(float x, float y);
    

private:
    Vector2i inicio;
    Vector2i fin;
    Vector2i centro;
    Vector2i dimension;
    Sprite *dibujo;
    Sprite **animacion;

};

#endif /* SPRITEGAME_H */

