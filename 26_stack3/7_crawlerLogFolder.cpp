#include <bits/stdc++.h>
using namespace std;

/*
The Leetcode file system keeps a log each time some user performs a change folder operation.
The operations are described below:

"../" : Move to the parent folder of the current folder.
(If you are already in the main folder, remain in the same folder).

"./" : Remain in the same folder.
"x/" : Move to the child folder named x (This folder is guaranteed to always exist).

You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.
The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder 
after the change folder operations.

 

Example 1:

Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
Example 2:

Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
Example 3:

Input: logs = ["d1/","../","../","../"]
Output: 0

*/

class Solution {
public:
    int minOperations(vector <string> &logs) {
        int count = 0;

        for (int i=0; i<logs.size(); i++){
            if (logs[i] == "../"){
                if (count == 0) continue;   // i am already in main directory nothing to do

                // not in main directory but this operation will help me to come 1 ladder closer to the main directory...
                else count--;
            }
            else if (logs[i] == "./") continue;
            else{   // kisi bhi directory mai andar andar jaao aate waqt mai time lagega..
                count++;
            }
        }
        return count;
    }
};


// ---- using stack -------


class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack <string> st;

        for (int i=0; i<logs.size(); i++){
            string ops = logs[i];

            if (ops == "../") {
                if (!st.empty()) st.pop();     
            }
            
            else if (ops == "./") continue;

            // pushing only directories...
            else{
                st.push(ops);
            }
        }

        return st.size();
    }
};

/*
using stack

iterate over logs if logs[i] = ../   => pop from stack..
                            == ./    => no operation 
                            else{
                                matlab kisi directory mai jaana chah rahe ho... then push it into stack...
                            }


finaly while (!st.empty()){
    count number of elements in stack....
}


*/

