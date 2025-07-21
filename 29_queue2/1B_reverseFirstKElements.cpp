// reverseFirstKElements.cpp

/*

Given an integer k and a queue of integers, we need to reverse the order of the first k elements 
of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.

Note: The above operations represent the general processings. 
In-built functions of the respective languages can be used to solve the problem.

Examples:

Input: q = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
Explanation: After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5


Input: q = [4, 3, 2, 1], k = 4
Output: [1, 2, 3, 4] 
Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4 


Constraints:
1<= q[i] <= 1e5
1<= q.size() <=1e5
1 <= k <= 1e5

*/


#include <bits/stdc++.h>
using namespace std;

void display(queue <int> qu){
    int n = qu.size();
    for (int i=0; i<n; i++){
        int x = qu.front();
        cout<<x<<" ";
        qu.pop();
        qu.push(x);
    }
    cout<<endl;    
}
 

void revQu(queue <int> &qu, int k){ // lets not preserve qu
    stack <int> stk;
    // empty the whole queue into stack
    int n = qu.size();
    for (int i = 0; i<n; i++){
        int x = qu.front();
        qu.pop();

        stk.push(x);
    }

    // push stk into qu 
    while (stk.size()>0){
        int y = stk.top();
        stk.pop();

        qu.push(y);
    }

    // pop from queue n-k times and push it into stack
    for (int i=0; i<n-k; i++){
        int z = qu.front();
        qu.pop();
        stk.push(z);    
    }
    
    // push stk element at the end of queue...
    while (stk.size()>0){
        int x = stk.top(); // top pop push 
        stk.pop();
        qu.push(x);
    }

}


int main(){
    queue <int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.push(6);

    display(qu);
    revQu(qu,3); // reverse first 3 element of queue
    
    display(qu);    
} 



// reverse element of queue using stack
/*

ip: 1 2 3 4 5 6 , k = 3
op: 
to po push

*/  