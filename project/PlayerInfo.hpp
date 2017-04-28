//
//  PlayerInfo.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef PlayerInfo_hpp
#define PlayerInfo_hpp

#include <string>

using namespace std;

struct PlayerInfo {
    int yearId;
    
    char bats;
    char throws;
    
    long salary;
    float weight;
    float height;
    
    string teamId;
    string playerId;
    string leagueId;
    string firstName;
    string lastName;
    string birthYear;
    string birthCountry;
};

#endif /* PlayerInfo_hpp */
