
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
    User(bool e);
    ~User();
    
    // setters
    void setNbOfGPl(int New);
    void setNbOfGW(int New);
    void setAvatar(int avPosition);
    void setAvatarRE(); // sets a random avatar to be used for the enemy
    // getters
    int getNbOfGL()const;
    int getNbOfGPl()const;
    int getNbOfGW()const;
    
private:
    
    int nbOfGPl; // number of games played
    int nbOfGW; // number of games Won
    
    std::string name;
    Texture playerAvatars;
    Texture enemyAvatars;
    Sprite avatar;
    
};

#endif /* defined(__battleeee__User__) */
