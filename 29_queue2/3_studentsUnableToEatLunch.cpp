#include <bits/stdc++.h>
using namespace std;


/*
The school cafeteria offers circular and square sandwiches at lunch break, 
referred to by numbers 0 and 1 respectively. All students stand in a queue. 
Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. 
The sandwiches are placed in a stack. 

At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, 
they will take it and leave the queue.

Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich 
and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] 
is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) 
and students[j] is the preference of the j​​​​​​th student in the initial queue 
(j = 0 is the front of the queue). Return the number of students that are unable to eat.

 

Example 1:

Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0 
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.
Example 2:

Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
 

Constraints:

1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] is 0 or 1.
students[i] is 0 or 1.



*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        // students queue
        queue <int> q;
        for(int i=0; i<n; i++) q.push(students[i]);
        

        int count = 0;
        int i = 0;

        while(q.size() > 0 && count != q.size()){ // coz when count = q.size() -> then repeatedly loop works..
            
            if (q.front() == sandwiches[i]){
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