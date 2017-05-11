//
//  PlayerInfo.hpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef PlayerInfo_hpp
#define PlayerInfo_hpp

#include <iostream>
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
    PlayerInfo() {}
    PlayerInfo(vector<TeamInfo> teams, string playerId, string firstName, string lastName,
               string birthYear, string birthCountry, float weight, float height, char bats, char throws)
    : teams(teams), playerId(playerId), firstName(firstName), lastName(lastName), birthYear(birthYear),
    birthCountry(birthCountry), weight(weight), height(height), bats(bats), throws(throws)
    { }
    
    PlayerInfo(const PlayerInfo& );
    ~PlayerInfo();
    
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
    
    virtual void show() const;

    static PlayerInfo ConstructFrom(string line);
    static string MakeKey(string firstName, string lastName);
    static string MakeKey(PlayerInfo& player);
};

class NullPlayerInfo : public PlayerInfo {
public:
    NullPlayerInfo() {}
    virtual void show() const override {
        cout << "Record not found!" << endl;
    }
};

#endif /* PlayerInfo_hpp */
