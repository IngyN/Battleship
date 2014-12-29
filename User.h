
//
//  User.h
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__User__
#define __battleeee__User__

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class User
{
public:
    User();
    ~User();
    void setNbOfGPl(int New);
    void setNbOfGW(int New);
    void setNbOfGL(int New);
    int getNbOfGL()const;
    int getNbOfGPl()const;
    int getNbOfGW()const;
private:
    int nbOfGPl; // number of games played
    int nbOfGW; // number of games Won
    std::string name;
    Texture imageVillain;
    Sprite Villain;
    
};

#endif /* defined(__battleeee__User__) */
