#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector < list<int> > graph;      // globally banaya taki fn call me pass na karna pade
int v;     // no. of vertices

void addEdge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);         // source me destination

    if(bi_dir){
        graph[dest].push_back(src);     // agar bidirectional to destination me bhi source
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



int main(){
    cout<<"enter number of vertices:"<<" ";
    cin>>v;
    graph.resize(v, list<int>());
    cout<<"enter number of edges:"<<" ";
    int e;   // number of edge
    cin>>e;
    cout<<"add source element then space then destination element "<<endl;
    while(e--){
        int s,d;
        cin>>s>>d;
        addEdge(s,d,false);  // add edge from source to destination
                            // false means directional graph
   
    }
    display();
}






// graph is represented as array of linked list
/*
final answer me linked list ke order se phark nahi padta
*/