//
//  PlayerInfo.cpp
//  HashTables
//
//  Created by Sunil on 4/29/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "PlayerInfo.hpp"

#include <sstream>

PlayerInfo PlayerInfo::ConstructFrom(string line) {
    stringstream lineStream(line);
    
    // Format of the line:
    // yearID       : int
    // teamID       : string
    // leagueID     : string
    // playerID     : string
    // salary       : long
    // firstName    : string
    // lastName     : string
    // birthYear    : string
    // birthCountry : string
    // weight       : float
    // height       : float
    // bats         : int
    // throws       : int
    
    int yearId;
    char bats, throws;
    long salary;
    float weight, height;
    string teamId, playerId, leagueId, firstName, lastName, birthYear, birthCountry;
    char ignoreComma;
    
    lineStream >> yearId;       lineStream >> ignoreComma;
    // lineStream >> teamId;       lineStream >> ignoreComma;
    std::getline(lineStream, teamId, ',');
    // lineStream >> leagueId;     lineStream >> ignoreComma;
    std::getline(lineStream, leagueId, ',');
    // lineStream >> playerId;     lineStream >> ignoreComma;
    std::getline(lineStream, playerId, ',');
    lineStream >> salary;       lineStream >> ignoreComma;
    // lineStream >> firstName;    lineStream >> ignoreComma;
    std::getline(lineStream, firstName, ',');
    // lineStream >> lastName;     lineStream >> ignoreComma;
    std::getline(lineStream, lastName, ',');
    // lineStream >> birthYear;    lineStream >> ignoreComma;
    std::getline(lineStream, birthYear, ',');
    // lineStream >> birthCountry; lineStream >> ignoreComma;
    std::getline(lineStream, birthCountry, ',');
    lineStream >> weight;       lineStream >> ignoreComma;
    lineStream >> height;       lineStream >> ignoreComma;
    lineStream >> bats;         lineStream >> ignoreComma;
    lineStream >> throws;
    
    return {
        .yearId = yearId,
        .teamId = teamId,
        .leagueId = leagueId,
        .playerId = playerId,
        .salary = salary,
        .firstName = firstName,
        .lastName = lastName,
        .birthYear = birthYear,
        .birthCountry = birthCountry,
        .weight = weight,
        .height = height,
        .bats = bats,
        .throws = throws
    };
}

string PlayerInfo::MakeKey(string firstName, string lastName) {
    //    if (firstName == "" && lastName == "")
    //        throw runtime_error("Cannot have a key with first and last name as empty!");
    return firstName + lastName;
}

string PlayerInfo::MakeKey(PlayerInfo& player) {
    return MakeKey(player.firstName, player.lastName);
}

string PlayerInfo::key() const {
    return MakeKey(firstName, lastName);
}
