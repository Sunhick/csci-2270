//
//  Graph.cpp
//  zombies
//
//  Created by Sunil on 4/17/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Graph.h"

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

template <class T>
Graph<T>::Graph() {

}

template <class T>
Graph<T>::~Graph() {
    //dtor
}

template <class T>
void Graph<T>::addEdge(T v1, T v2, int weight) {
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i].name == v1) {
            for(int j = 0; j < vertices.size(); j++) {
                if(vertices[j].name == v2 && i != j) {
                    adjVertex<T> av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);

                    //add edge in the other direction
                    //vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    //adjVertex<T> av2;
                    //av2.v = &vertices[i];
                    //av2.weight = weight;
                    //vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

template <class T>
void Graph<T>::addVertex(T n) {
    bool found = false;
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i].name == n) {
            found = true;
            cout << vertices[i].name << " found." << endl;
        }
    }
    
    if(found == false){
        vertex<T> v;
        v.name = n;
        vertices.push_back(v);

    }
}

template <class T>
void Graph<T>::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i].name << "-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout << vertices[i].adj[j].v->name << "***";
        }
        cout << endl;
    }
}

template <class T>
void Graph<T>::displayVertices() {
    for (auto& city : vertices) {
        cout << city.districtId << ":" << city.name << "->";
        
        auto hasMultipleEntries = false;
        
        // print the adjacent cities.
        for (auto& adjCity : city.adj) {
            if (hasMultipleEntries) cout << "**";
            cout << adjCity.v->name;
            hasMultipleEntries = true;
        }
        
        cout << endl;
    }
}

template <class T>
void Graph<T>::assignDistrictIds() {
    int districtId = 1;
    for (auto& city : vertices) {
        // check if this city has district id assigned.
        if (city.districtId == -1) {
            // if district id not assigned, then do bfs to assign id to
            // it's connected cities.
            bfsAssignId(city, districtId);
            
            // increment the id
            districtId++;
        }
    }
}

template <class T>
void Graph<T>::bfsAssignId(vertex<T>& city, int id) {
    // do a bfs iterative traversal.
    
    // very important to have a queue of pointers.
    // otherwise district id would be assigned only to local copies.
    deque<vertex<T>*> queue;
    queue.push_back(&city);
    
    while(!queue.empty()) {
        auto city = queue.front();
        queue.pop_front();

        city->districtId = id;
        for (auto& adjCity : city->adj) {
            // ignore the current city.
            // Verify: Is this taken care while adding a edge ?
            cout << adjCity.v->name << endl;
            if (adjCity.v->name == city->name) {
                continue;
            }
            
            // Add the adjacent city if it doesn't have a district id assigned.
            // I could have used a variable like visited in vertex to track if it's
            // already visited or not. But i can get away with checking district id.
            if (adjCity.v->districtId == -1) {
                queue.push_back(adjCity.v);
            }
        }
    }
}

template <class T>
void Graph<T>::findShortestPath(std::string, std::string) {
    // run a dijkstra's algorithm here to find the shortest path.
    
}
