//
//  Welcome.h
//  battleeee
//
//  Created by Ingy on 11/24/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__Welcome__
#define __battleeee__Welcome__

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Welcome
{
    
public:
    Welcome ();
    ~Welcome ();
    void initialize ();
    void process();
    
private:
    RenderWindow * wel;
    Font mainFont;
    Text welcomeText;
    
    
};
#endif /* defined(__battleeee__Welcome__) */
