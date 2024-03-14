#include <iostream>
#include <vector>
using namespace std;


int find(vector <int> &parent, int x){  // this method returns which group x belongs to..
    if (parent[x]==x) return x;
    else return find(parent , parent[x]); // recursively jao aur parent search
}


void Union(vector <int> &parent, vector <int> &rank, int a, int b){ // Union ka U kU capital
    // T.C. = log*n 
    a = find(parent, a);
    b = find(parent, b);

    if (rank[a] >= rank[b]){   // b group (smaller group) ko laake a mai merge kardo...
        rank[a]++;
        parent[b] = a;  // a ki rank jyada to rank[a] ko badhaya and a ko hi parent banaya
    }
    else{
        rank[b]++;
        parent[a] = b;
    }   
}



int main(){
    int n,m;
    cout<<"enter number of elements and number of queries you are going to perform...";
    cin>>n>>m;
    // n -> number of elements , m = number of queries
    vector <int> parent(n+1);
    vector <int> rank(n+1 , 0); // all initially initialised with zero

    for (int i=0; i<=n; i++){   // initially all pointing to themselves
        parent[i] = i;
    }

    while (m--){
        string str;
        cout<<"which operation union or find? write it...(union of find)";
        cin>>str;
        if (str == "union"){
            int x,y;
            cout<<"enter x and y on which union will be performed: ";
            cin>>x>>y;
            Union(parent,rank,x,y);

        }
        else{   // find fn
            int x;
            cout<<"enter the target element for find fn ";
            cin>>x;
            cout<<find(parent,x)<<"\n";
        }
    }

    return 0;

}





/*
Dsu requires two fn Union and find
union mai find ki need -> find pehle

find fn mai -> path compression union by rank

*/