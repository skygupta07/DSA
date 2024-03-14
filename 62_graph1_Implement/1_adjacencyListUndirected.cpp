#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector < list<int> > graph;      // globally banaya taki fn call me pass na karna pade
int v;     // no. of vertices

void addEdge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);     // square brackets used...

    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void display(){
    for (int i=0; i<graph.size(); i++){
        cout<<i<< " -> ";
        for (auto ele : graph[i]){      // to print the neighbour iterate over the ith 
                                        // linked list and print its element...
            cout<<ele<<" , ";
        }
        cout<<"\n";
    }
}


f
int main(){
    cout<<"enter number of vertices:"<<" ";
    cin>>v;
    graph.resize(v, list<int>());
    cout<<"enter number of edges:"<<" ";
    int e;   // number of edge
    cin>>e;

    while(e--){
        int s,d;
        cin>>s>>d;
        addEdge(s,d);  // add edge from source to destination
    }
    display();
}



// graph is represented as array of linked list
// vector of vector can be a good alternate in place of vector of list..
/*
Representation:
(n,m) => n nodes and m edges...
you will be given as input m lines representing edges...

*/