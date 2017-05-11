//
//  PlayerInfo.cpp
//  HashTables
//
//  Created by Sunil on 4/29/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "PlayerInfo.hpp"

#include <sstream>
#include <iostream>

using namespace std;

PlayerInfo::PlayerInfo(const PlayerInfo& rhs) {
    teams = rhs.teams;
    playerId = rhs.playerId;
    firstName = rhs.firstName;
    lastName = rhs.lastName;
    birthYear = rhs.birthYear;
    birthCountry = rhs.birthCountry;
    weight = rhs.weight;
    height = rhs.height;
    bats = rhs.bats;
    throws = rhs.throws;
}

PlayerInfo::~PlayerInfo() {
    
}

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
    
    TeamInfo teamInfo = {
        .yearId = yearId,
        .teamId = teamId,
        .leagueId = leagueId,
        .salary = salary
    };
    
    return {
        {teamInfo},
        playerId,
        firstName,
        lastName,
        birthYear,
        birthCountry,
        weight,
        height,
        bats,
        throws
    };
}

bool PlayerInfo::areSame(const PlayerInfo& player) const {
    return uid() == player.uid();
}

const string PlayerInfo::uid() const {
    // generate a unique identifier for this player.
    // Firstname, lastName, birth year, birth country, weight and height uniquely identifies a player.
    // Can i compare based on player Id ?
    auto uid = (
            firstName + lastName + birthYear + birthCountry + std::to_string(weight) + std::to_string(height)
    );
    
    // convert to lower
    std::transform(uid.begin(), uid.end(), uid.begin(), ::tolower);
    return uid;
}

void PlayerInfo::show() const {
    cout << endl;
    
    cout << "First name: "      << firstName        << endl;
    cout << "Last name: "       << lastName         << endl;
    cout << "Year born: "       << birthYear        << endl;
    cout << "Country born: "    << birthCountry     << endl;
    cout << "Weight: "          << weight           << endl;
    cout << "Height: "          << height           << endl;
    cout << "Bats: "            << bats             << endl;
    cout << "Throws: "          << throws           << endl;
    
    cout << "Teams and salary:" << endl;
    for (auto& teamInfo : teams) {
        cout << teamInfo.yearId << "," << teamInfo.teamId << "," << teamInfo.leagueId << ","
             << teamInfo.salary << endl;
    }
    
    cout << endl;
}

void PlayerInfo::addMoreInfo(const PlayerInfo& samePerson) {
    for (auto teamInfo : samePerson.teams)
        teams.push_back(teamInfo);
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
