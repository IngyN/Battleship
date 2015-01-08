//
//  User.cpp
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "User.h"
#include <iostream>

using namespace std;
const string enemies = "enemies.png";
const string players = "players.png";

User::User()
{
        if (!enemyAvatars.loadFromFile(enemies.c_str()))
        {
        cout << "Unable to load file for enemy"<< endl;
        }
    
    else if(!playerAvatars.loadFromFile(players.c_str()))
        {
            cout << "Unable to load file for player"<< endl;
        }

    
        enemyAvatars.setSmooth(true);
        enemyAvatars.setRepeated(false);
        playerAvatars.setSmooth(true);
        playerAvatars.setRepeated(false);

    name =" ";
}
User::~User()
{
    
}

// setters
void User::setNbOfGPl(int New)
{
    nbOfGPl=New;
}
void User::setNbOfGW(int New)
{
    nbOfGW=New;
}

void User::setAvatar(int avPosition)//!!! check on number of variables needed
{
     avatar.setTextureRect(sf::IntRect(32*avPosition, 0, 32, 32)); // depends on the picture used.
}
void User::setAvatarRE()
{
    int r = rand()%9+1; // generate a random number according to the number of possible avatars
    
    // then select and avatar depending on the size of the avatar.
    avatar.setTextureRect(sf::IntRect(32*r, 0, 32, 32));
    
}// sets a random avatar to be used for the enemy

// getters
int User::getNbOfGL()const
{
    return nbOfGPl-nbOfGW;
}
int User::getNbOfGPl()const
{
    return nbOfGPl;
}
int User::getNbOfGW()const
{
    return nbOfGW;
}
