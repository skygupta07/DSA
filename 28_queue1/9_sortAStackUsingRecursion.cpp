#include <bits/stdc++.h>
using namespace std;


void sortedInsert(stack<int> &stack, int hold){
	if ( stack.empty() || (!stack.empty() && stack.top()<hold) ){
		stack.push(hold);			// only one condition changed
		return;
	}
	int n = stack.top();
	stack.pop();

	// recursive call
	sortedInsert(stack,hold);
	stack.push(n);
}



void sortStack(stack<int> &stack){
	if (stack.empty()) return;

	int hold = stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack,hold);
	
}

/// simple brute force 
void sortStack(stack<int> &st)
{
	vector <int> v;
	while (!st.empty()){
		v.push_back(st.top());
		st.pop();
	}

	sort(v.begin(), v.end());

	for (int i=0; i<v.size(); i++) st.push(v[i]);
	return;
}