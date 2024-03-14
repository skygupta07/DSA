#include<iostream>
#include<queue>  // heap is the best data structure to implement priority.....
using namespace std;

int main(){
   
    priority_queue <int> pq; // maxheap -> arey bhai ye tumhara ek tarah se object hai.. 
    // === vector <int> v;
    priority_queue <int, vector<int>, greater<int> > minheap;  // syntax to declare minheap using priority queue
    // yaha vector <int> aur greater <int> aur aa jata hai..

    pq.push(1);
    pq.push(2);
    pq.push(6);
    pq.push(10);
    pq.push(5);
    pq.push(3);
    cout<<pq.top();  // max element in maxheap is topmost Element
    cout<<endl;   
    cout<<pq.empty()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    minheap.push(2);
    minheap.push(5);
    minheap.push(6);
    minheap.push(9);
    minheap.push(10);
    minheap.push(18);

    cout<<minheap.top() <<endl;
    
    
}

/*
hum bas element andhadundh push karte jaa rahe hai... aur wo bhi priority queue ko 
implement kar dega internally heap ko use karke....

by default max heap hoti hai...

helpful for those problem jisme ki ab tak ke bacche huye element ka overall max or overall
min. value chahiye ho...
*/