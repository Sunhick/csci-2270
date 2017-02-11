#include <iostream>
#include <chrono>

#include "WordAnalysis.h"

using namespace std;

// main expects 1 argument, filename
int main(int argc, char* argv[])
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    char* filename = argv[1];
    int n = atoi(argv[2]);
	
    WordAnalysis wa(100);
    
    if(wa.readDataFile(filename)) {
        //print common words
        wa.printCommonWords(n);
        
        cout << "#" << endl;
        //timesDoubled returned from WordAnalysis
        cout << "Array doubled: "<< wa.getArrayDoubling() << endl;
        
        // display the output
        cout << "#" << endl;
        //nonCommonWords returned from WordAnalysis
        cout<<"Unique non-common words: "<< wa.getUniqueWordCount() <<endl;
        
        cout<<"#"<<endl;
        //totalWords returned from WordAnalysis
        cout<<"Total non-common words: "<< wa.getWordCount() <<endl;
        // free the final array

    }
    
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}

