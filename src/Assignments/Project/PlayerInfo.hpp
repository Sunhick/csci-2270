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
#include <vector>

using namespace std;

struct TeamInfo {
    string teamId;
    string leagueId;
    int yearId;
    long salary;
};

class PlayerInfo {
public:
    
    char bats;
    char throws;
    
    float weight;
    float height;
    
    vector<TeamInfo> teams;
    
    string playerId;
    string firstName;
    string lastName;
    string birthYear;
    string birthCountry;
    
    string key() const;
    bool areSame(const PlayerInfo&) const;
    const string uid() const;
    void addMoreInfo(const PlayerInfo& samePerson);
    
    void show() const;
    
    static PlayerInfo ConstructFrom(string line);
    static string MakeKey(string firstName, string lastName);
    static string MakeKey(PlayerInfo& player);
};

#endif /* PlayerInfo_hpp */
