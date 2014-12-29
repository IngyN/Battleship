//
//  Settings.h
//  battleeee
//
//  Created by Ingy on 12/21/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef battleeee_Settings_h
#define battleeee_Settings_h

#include <string>
using namespace std;

class Settings
{
public:
    Settings () {};
    ~Settings (){};
    string language;
    int volume;
    int music;
    string theme;

};

#endif
