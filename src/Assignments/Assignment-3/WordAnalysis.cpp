//
//  WordAnalysis.cpp
//  Assignment3
//
//  Created by Sunil on 2/2/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <fstream>
#include <algorithm>
#include <iostream>

#include "WordAnalysis.h"

WordAnalysis::WordAnalysis(int wordCount) {
    this->wordCount = wordCount;
    this->words = new word[wordCount];
    this->timesDoubled = 0;
    this->index = 0;
}

WordAnalysis::~WordAnalysis() {
    delete[] this->words;
    this->words = nullptr;
    this->timesDoubled = 0;
    this->wordCount = 0;
    this->index = 0;
}

bool WordAnalysis::checkIfCommonWord(std::string word) {
    std::string commonWords[] = {"the", "you", "one", "be", "do", "all", "to", "at", "would", "of", "this", "there", "and", "but", "their", "a", "his", "what", "in", "by", "so", "that", "from", "up", "have", "they", "out", "i", "we", "if", "it", "say", "about", "for", "her", "who", "not", "she", "get", "on", "or", "which", "with", "an", "go", "he", "will", "me", "as", "my"};
    
    for(auto commonWord : commonWords) {
        if(word == commonWord) return true;
    }
    
    return false;
}

void WordAnalysis::doubleArrayAndAdd(std::string word) {
    auto darray = new struct word[2 * this->wordCount];
    
    std::copy(this->words, this->words+this->index, darray);
    delete[] this->words;
    
    this->timesDoubled++;
    this->wordCount *= 2;
    this->words = darray;
    
    // add the new word to the array
    this->words[this->index++] = {1, word};
}

void WordAnalysis::sortData() {
    std::sort(this->words, this->words+this->index, [](const word& w1, const word& w2) {
        return w1.count > w2.count;
    });
}

bool WordAnalysis::readDataFile(char* filename) {
    ifstream file;
    file.open(filename);
    if (!file.good()) return false;
    
    string word;
    while(getline(file, word, ' ')) {
        // remove the newline from the word if it has.
        word.erase(std::remove(word.begin(), word.end(), '\n'), word.end());
        
        if(this->checkIfCommonWord(word) || word == "") {
            continue;
        }
        
        auto existingWord = std::find_if(this->words, this->words+this->index, [&word](struct word& e) {
            return e.w == word;
        });
        
        if(existingWord != this->words + this->index) {
            existingWord->count++;
            continue;
        }

        if(this->index == this->wordCount) {
            // double and add the element
            this->doubleArrayAndAdd(word);
        } else {
            // Add the new item to the array
            this->words[index++] = { 1, word };
        }
    }
    this->sortData();
    return true;
}

int WordAnalysis::getWordCount() {
    int wc = 0;
    
    std::for_each(this->words, this->words+this->index, [&wc](struct word& e) {
        wc += e.count;
    });
    
    return wc;
}

int WordAnalysis::getUniqueWordCount() {
    return this->index;
}

int WordAnalysis::getArrayDoubling() {
    return this->timesDoubled;
}

void WordAnalysis::printCommonWords(int topN) {
    std::for_each(this->words, this->words+topN, [](struct word& e){
        cout << e.count << " - " << e.w << endl;
    });
}
