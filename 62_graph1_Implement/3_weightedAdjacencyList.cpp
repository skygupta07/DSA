#include <bits/stdc++.h>
using namespace std;

vector < list <pair<int,int> > > graph;      // globally banaya taki fn call me pass na karna pade

// graph can be represented as vector of list, where each list's element is a pair of
// int and int storing the info of destination and the corresponding weight....

int v;     // no. of vertices

void addEdge(int src, int dest, int wt, bool bi_dir = true){
    graph[src].push_back({dest,wt});    // pushing a vector in a vector of vector
                                        // using curly braces se aapka vector ban jaata hai...
    if(bi_dir){
        graph[dest].push_back({src,wt});
    }
}

void display(){
    for (int i=0; i<graph.size(); i++){
        cout<<i<< " -> ";
        for (auto ele : graph[i]){      // to print the neighbour iterate over the ith 
                                        // linked list and print its element...
            cout<<"(" <<ele.first<< ele.second<<") , ";

        }
        cout<<"\n";
    }
}


int main(){
    cout<<"enter number of vertices:"<<" ";
    cin>>v;
    graph.resize(v, list <pair <int, int> >());   // har index pe list of integer ko add kiya
    cout<<"enter number of edges:"<<" ";
    int e;   // number of edge
    cin>>e;

    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        addEdge(s,d,wt,false);  // add edge from source to destination
   
    }
    display();
}


// graph is represented as array of linked list
/*
final answer me linked list ke order se phark nahi padta (obviously)

*/