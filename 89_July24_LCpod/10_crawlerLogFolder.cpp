#include <iostream>
#include <vector>
using namespace std;
int main(){

}


class Solution {
public:
    int minOperations(vector<string>& logs) {
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


---- using stack -------


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

