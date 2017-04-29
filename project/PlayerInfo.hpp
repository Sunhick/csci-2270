//
//  PlayerInfo.hpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef PlayerInfo_hpp
#define PlayerInfo_hpp

#include <string>

using namespace std;

class PlayerInfo {
public:
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
    
    string key() const;
    
    static PlayerInfo ConstructFrom(string line);
    static string MakeKey(string firstName, string lastName);
    static string MakeKey(PlayerInfo& player);
};

#endif /* PlayerInfo_hpp */
