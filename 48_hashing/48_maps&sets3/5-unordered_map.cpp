#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    unordered_map <int, int> mp;
    int arr[] = {3,4,5,9,1,1,7,0,4};
}


// unordered_map takes O(1) time in avg best case but takes O(n) in case of worst case(collision)
// always take the unordered_map first on priority in raremost case if it gives
// tle then try map

/*
hashing
1. division method (linear chaining) will be done...
2. folding method
3. mid square method


collision happens when all the hash ends up with same number and hence then you need 
to add them all in linear fashion...

-> only single data type allowed as key don't use pairs here....

*/