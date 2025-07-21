// removeElementsAtEvenIndex.cpp

#include <bits/stdc++.h>
using namespace std;


void display(queue <int> &q){
    int n = q.size();
    
    for (int i=0; i<n; i++){
        // to po push
        int x = q.front();
        cout<<x<<" ";
        q.pop();

        q.push(x);
    }

    cout<<endl;
}

void removeEven(queue <int> q){ // removing even indexed element...
    int n = q.size();

    for (int i=0; i<n; i++){
        // to po push
        if (i%2 != 0){
            int x = q.front();
            cout<<x<<" ";
            q.pop();
            
            q.push(x);
        }
        // even index means pop or remove the element....
        else{
            q.pop(); 
        }
    }
    cout<<endl;
}



int main(){
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    display(q);
    removeEven(q);
    display(q);
    


}



