//
//  Graph.cpp
//  zombies
//
//  Created by Sunil on 4/17/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Graph.h"

#include <set>
#include <queue>
#include <sstream>
#include <tuple>
#include <algorithm>

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
    
    if (weight == -1) {
        // no edge. ignore
        return;
    }
    
    for (int i = 0; i < vertices.size(); i++) {
        if(vertices[i].name != v1)
            continue;
        
        for (int j = 0; j < vertices.size(); j++) {
            if(vertices[j].name != v2 || i == j) continue;
            
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

template <class T>
void Graph<T>::addVertex(T n) {
    bool found = false;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name == n) {
            found = true;
            cout << vertices[i].name << " found." << endl;
        }
    }
    
    if (found == false){
        vertex<T> v;
        v.name = n;
        vertices.push_back(v);
        
    }
}

template <class T>
void Graph<T>::displayEdges(){
    //loop through all vertices and adjacent vertices
    for (auto& city : vertices) {
        cout << city.name << "-->";
        
        for (auto& adjCity : city.adj) {
            cout << adjCity.v->name << "***";
        }
        
        cout << endl;
    }
}

template <class T>
void Graph<T>::displayVertices() {
    for (auto& city : vertices) {
        cout << city.districtId << ":" << city.name << "-->";
        
        auto hasMultipleEntries = false;
        
        // print the adjacent cities.
        for (auto& adjCity : city.adj) {
            if (adjCity.weight == -1) continue;
            if (hasMultipleEntries) cout << "***";
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
vertex<T>* Graph<T>::findCity(string cityName) {
    // use stl algorithm find_if with lambda expression to specify search criteria
    auto iter = std::find_if(begin(vertices), end(vertices), [&cityName](vertex<T>& item) {
        return item.name == cityName;
    });
    
    auto found = iter != end(vertices) ? &(*iter) : nullptr;
    return found;
}

template <class T>
void Graph<T>::findShortestPath(std::string src, std::string dest) {
    
    auto srcCity = findCity(src);
    auto destCity = findCity(dest);
    
    if (!srcCity || !destCity) {
        // One or both cities not found:
        cout << "One or more cities doesn't exist" << endl;
        return;
    }
    
    if (srcCity->districtId == -1 || destCity->districtId == -1) {
        // Districts not set yet
        cout << "Please identify the districts before checking distances" << endl;
        return;
    }
    
    if (srcCity->districtId != destCity->districtId) {
        // Cities in different districts:
        cout << "No safe path between cities" << endl;
        return;
    }
    
    // if source and dest are same. Nothing to do.
    if (srcCity->name == destCity->name) {
        cout << "0, " << src << ", " << dest << endl;
        return;
    }
    
    // run a dijkstra's algorithm here to find the shortest path.
    dijkstra(src, dest);
}

template <class T>
int Graph<T>::length(vertex<T>* u, string v) {
    
    for (auto adjCity : u->adj) {
        if (adjCity.v->name == v) {
            auto weight = adjCity.weight;
            return weight == -1 ? INFINITY : 1;
        }
    }
    
    return INFINITY;
}

template <class T>
void Graph<T>::dijkstra(string src, string dest) {
    // I swap the parameters to get the output in right format.
    // By swapping src, dest. It doesn't change anything.
    
    // run a bfs to find the shortest distance.
    auto city = findCity(src);
    
    // tuple of bfs node and path to dest node.
    deque<tuple<vertex<T>*, vector<string>>> queue;
    
    vector<string> path {city->name};
    queue.push_back(std::make_tuple(city, path));
    
    vector<vector<string>> shortest;
    
    while(!queue.empty()) {
        auto tuple = queue.front();
        auto city = std::get<0>(tuple);
        auto path = std::get<1>(tuple);
        
        queue.pop_front();
        
        if (city->name == dest) {
            // printPath(path);
            // we have a path. Doesn't mean we have found shortest path.
            shortest.push_back(path);
            continue;
        }
        
        for (auto& adjCity : city->adj) {
            // check if have already visited adjCity before traversing
            if (std::find(path.begin(), path.end(), adjCity.v->name) != path.end()) {
                // already visited.
                continue;
            }
            
            vector<string> newPath {path};
            newPath.push_back(adjCity.v->name);
            queue.push_back(std::make_tuple(adjCity.v, newPath));
        }
    }
    
    // find the shortest path
    int minIndex = 0;
    auto minHops = shortest[minIndex].size();
    
    for (int i = 1; i < shortest.size(); i++) {
        auto hops = shortest[i].size();
        if (hops < minHops) {
            minHops = hops;
            minIndex = i;
        }
    }
    
    printPath(shortest[minIndex]);
}

template <class T>
void Graph<T>::printPath(vector<string> path) {
    auto hops = path.size();
    
    cout << hops-1 << ",";
    
    for (int i = 0; i < hops-1; i++) {
        cout << path[i] << ",";
    }
    
    cout << path[hops-1] << endl;
}
