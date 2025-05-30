#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <stack>
using namespace std;

// 🧩 Function to insert an element in the sorted position in a stack
void sortedInsert(stack<int> &stk, int element) {

    //  Base case:
    // Agar stack empty hai ya top element se bada element aa raha hai,
    // to directly push kar do (yeh correct sorted position hogi)
    if (stk.empty() || element > stk.top()) {
        stk.push(element);
        return;
    }

    //  Step: Top element ko temporarily nikaal do
    int temp = stk.top();
    stk.pop();

    //  Recursively insert the element in sorted position
    sortedInsert(stk, element);

    //  Backtrack: Wapas baaki elements ko push karo
    stk.push(temp);
}

// 🧹 Function to sort the entire stack using recursion
void sortStack(stack<int> &stk) {
    
    // Base case: Jab stack empty ho jaye, return
    if (stk.empty()) return;

    // Step 1: Top element ko nikaal lo
    int temp = stk.top();
    stk.pop();

    // Step 2: Recursively sort the remaining stack
    sortStack(stk);

    // Step 3: Ab is element ko correct position me insert karo
    sortedInsert(stk, temp);
}




/// simple brute force 
void sortStack(stack<int> &st){
	vector <int> v;

	while (!st.empty()){
		v.push_back(st.top());
		st.pop();
	}

	sort(v.begin(), v.end());

	for (int i=0; i<v.size(); i++) st.push(v[i]);
	return;
}