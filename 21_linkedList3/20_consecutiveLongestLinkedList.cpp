// consecutiveLongestLinkedList.cpp

/*

Given an array arr[] of sorted and distinct positive integers. 
The task is to find the length of the longest arithmetic progression in a given array.

Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value 
(for 0 <= i < seq.length - 1).

Examples:

Input:arr[] = [1, 7, 10, 13, 14, 19]
Output: 4

Explanation: The longest arithmetic progression is [1, 7, 13, 19].


Input:arr[] = [2, 4, 6, 8, 10]
Output: 5
Explanation: The whole array is in AP.


Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 ≤ arr.size() ≤ 1000
1 ≤ arr[i] ≤ 1e4

*/


#include <bits/stdc++.h>
using namespace std;

// Linked list node structure
struct ListNode {
    
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}

};

// Function to find the length of the longest arithmetic progression in the linked list
int longest_arithmetic_progression(ListNode* head) {

    if (!head || !head->next) return 1; // Agar sirf ek ya zero nodes hain toh length 1 return karo

    int maxLength = 1;  // Maximum length of AP found so far
    int currLength = 2; // Current AP length (minimum 2 elements required)
    
    ListNode* prev = head;       // Pehle element ka pointer
    ListNode* curr = head->next; // Dusre element ka pointer
    
    int cd = (curr->val) - (prev->val); // Pehle do elements ka common difference


    while (curr->next) {

        int nextCd = curr->next->val - curr->val; // Agle element ka common difference
        
        // Agar difference same hai toh length badhayein
        if (nextCd == cd) currLength++; 
        
        else {
            cd = nextCd; // Naya difference set karein
            currLength = 2; // Reset length to 2 (kyunki do elements toh chahiye hi)
        }

        maxLength = max(maxLength, currLength); // Maximum length update karein
        curr = curr->next; // Next node pe jaayein
    
    }

    return maxLength;
}


int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    // Creating the linked list
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    // Find and print longest AP length
    int result = longest_arithmetic_progression(head);
    cout << result << endl;

    // Free memory to prevent leaks
    current = head;
    while (current != NULL) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
