//
//  Rules.h
//  battleeee
//
//  Created by Ingy on 11/24/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__Rules__
#define __battleeee__Rules__

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Rules
{
    
public:
    Rules(RenderWindow *, Text);
    ~Rules();
    void initialize(Text);
    void retrieve();
    
    
private:
    RenderWindow * rules;
    String rulesText;
    Font rulesFont;
    
};

#endif /* defined(__battleeee__Rules__) */
