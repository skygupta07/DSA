#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int t;
	cin>>t;
	
	while (t--){
	    long long n;
	    cin>>n;
	    
	    cout<< 1 + (n-1)*(n-2) <<"\n";
	}
	
	return 0;
}

/*
Given an integer 
N, consider all arrays 
A, output the smallest possible sum of the elements of the array.

Note: Since the Input/Output may be large, it is preferred to use fast I/O.

1 0 2 4 6 8 10 12 14 16 18 20 

sum of ap laga diya 0 2 4 6 8 10    wale pe....
sn = n/2(2a + (n-1)*d)

we got (n-1)*(n-2) then finally add 1 taaki sum jo odd kar raha hai...
*/
