#include <bits/stdc++.h> // agar coding ninja par code directly nahi run kare 
// to issey include karna mat bhulna...
using namespace std;


int NthRoot(int n, int m) {
  int lo = 0; // yaha lo mai sach mai jo bhi lowest possible tum soch paa rahe ho ussey initialise kiya jaata h..
  int hi = m;  // binary search mai hi ko jo bhi max possible value ho paati answer ki hum ussey initialise karte h..

  while (lo <= hi){

    int mid = lo + (hi - lo)/2;

    if (pow(mid,n) == m) return mid;

    else if (pow(mid,n) < m) lo = mid + 1;
    else hi = mid - 1;

  }
  return -1;
}