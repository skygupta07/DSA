#include <bits/stdc++.h> 
bool oneSegment(string str) {
	int n = str.length();
	bool foundZero = false;

	for (int i=0; i<n; i++){
		if (str[i] == '0') foundZero = true;

		else if (foundZero && str[i] == '1') return false;
	}

	return true;
}