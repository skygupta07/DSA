#include <iostream>
#include <vector>
using namespace std;
int main(){

}






/*
merge Sort -> t.c.  = O(nlogn) , s.c. = O(N)
quick sort -> t.c. = O(nlogn) , s.c. = O(1) -> no extra vector is used here

steps 
1. pick up a pivot and place it in its correct place in the sorted array..
obviously array will get sorted as long as you are picking up all elements one by one

2. smaller on the left and larger on the right...

---------------------
instead of building new left right arrays we will track using pointers
sort only when we have more than one element

// remember i and j remain in the array itself...
left mai equal lelo taki agar repeated element bhi aaye to wo pivot ke hi just 
left mai rahe....

-> divide and conquer algo
*/