// C++ program to demonstrate use of decltype
#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
	int x = 5;

	// j will be of type int : data type of x
	decltype(x) j = x + 5;      // means data type of j will be same as you declared for x

	cout << typeid(j).name();

	return 0;
}
