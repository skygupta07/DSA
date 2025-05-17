#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // students queue
        queue <int> q;
        int n = students.size();
        for(int i=0; i<n; i++){
            q.push(students[i]);
        }

        int count = 0;
        int i = 0;

        while(q.size()>0 && count!=q.size()){ // coz when count = q.size() -> then repeatedly loop works..
            if (q.front()==sandwiches[i]){
                q.pop();
                i++;
                count = 0;  // resetting count to zero coz we are in safe state still
            }
            else{
                int x = q.front();
                q.pop();    // line mai aage se hat ke
                q.push(x);  // peech jaake lag gya...
                count++;    // deadlock type critical condition mai count ko increment kiya ...
            }
        }
        return q.size();    // jab deadlock wali condtion ne loop break karwaya to ab line mai kitne log bhuke
        // reh gaye is my answer...
    }
};

// students ke liye to queue banayenge
// sandwiches pe iterate karne ke liye bas i variable rakh lo
// infinite loop se bachne ke liye jab students ki preference match na kar rahi ho to ....
// maintain a count variable if size of count variable equals size of queue then repetition starts

// since repeatedly kaam ho raha hai to while loop mai likha
// yes while loop has condtitions and can also contain conditions within it like if else statements...