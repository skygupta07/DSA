#include <bits/stdc++.h>
using namespace std;

// Function to find two unique numbers in the array where all other numbers appear twice
void findUnique(int *arr, int n) {
    int res = 0;
    // Taking XOR of all elements in the array
    for (int i = 0; i < n; i++) {
        res ^= arr[i];
    }
    // Now, 'res' contains XOR of the two unique elements

    // Find any first set bit in 'res'
    int temp = res;
    int k = 0;  // Variable to store the position of the first set bit

    // Loop to find the position of the first set bit
    while (true) {
        if ((temp & 1) == 1) {
            break;
        }
        temp = temp >> 1;   // temp = temp/2
        k++;
    }

    int retVal = 0;
    // XOR all elements having the k-th bit set
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        if (((num >> k) & 1) == 1) {
            retVal ^= num;
        }
    }

    // Print the first unique element
    cout << retVal << " ";
    // XOR the first unique element with 'res' to get the second unique element
    res = retVal ^ res;
    // Print the second unique element
    cout << res << " ";
}

int main() {
    int arr[] = {1, 2, 1, 3, 2, 5, 5, 9, 8, 8}; // Given array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    findUnique(arr, n); // Function call to find and print unique elements
    return 0;
}

/*
Explanation:
Given an integer array 'nums' in which exactly two elements appear only once
and all the other elements appear exactly twice. The task is to find the two elements that 
appear only once.

Approach:
1. XOR all the elements of the array. This will cancel out the duplicate elements,
   leaving us with the XOR of the two unique elements.
2. Find the position of any set bit in the result of the XOR operation. This bit will be set
   in one of the unique elements and not set in the other.
3. Use this set bit to divide the array elements into two groups. One group will have the set bit,
   and the other group will not.
4. XOR the elements in each group separately. This will cancel out the duplicate elements within the groups,
   leaving us with the unique elements.
*/



/*
given an integer array nums in which exactly two elements appear only once
and all the other elements appear exactly twice. find the two elements that 
appear only once....
*/



/*
duplicates wale to cancel ho jayenge... baaki bacche huye..
jo single freq wale element hai..unka xor ka kucch value aayega...obviously non zero aayega..
non zero hai matlab koi na koi bit set hai..
matlab dono number ki wo kth bit different hogi....

now kth bit ke saath sabka xor le lo......
again duplicates wale eliminate ho jaenge... and wo element jiski kth bit set thi wo mil jaega....
then second element find karne ke liye...




*/