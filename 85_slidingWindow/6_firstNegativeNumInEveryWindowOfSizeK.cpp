// firstNegativeNumberInEveryWindowOfSizeK.cpp

/*

🧾 Problem: First Negative Number in Every Window of Size K
You are given an array of integers arr[] of size n and an integer k representing the size of a sliding window.

Your task is to find the first negative integer in every window of size k moving from left to right.

If a particular window does not contain any negative number, then that window should be ignored (not included in output).

🧿 Input:
An array:
arr[] = {2, -3, 4, 4, -7, -1, 4, -2, 6}
An integer:
k = 3
✅ Output:
A list of integers where each element is the first negative number of every window of size k, if it exists.

Sample Output:
-3 -7 -7 -7 -1 -1 -2

🔍 Explanation:
For arr = [2, -3, 4, 4, -7, -1, 4, -2, 6] and k = 3:

Window [2, -3, 4] → First negative = -3
Window [-3, 4, 4] → First negative = -3 (already counted, now we move)
Window [4, 4, -7] → First negative = -7
Window [4, -7, -1] → First negative = -7
Window [-7, -1, 4] → First negative = -7
Window [-1, 4, -2] → First negative = -1
Window [4, -2, 6] → First negative = -2
So the output is: -3 -7 -7 -7 -1 -2

(Your code only skips printing if no negative is found, so we assume all windows in this case have at least one negative.)

🧠 Constraints:
1 ≤ k ≤ n ≤ 10^5
-10^4 ≤ arr[i] ≤ 10^4
🚀 Follow-Up:
Can you optimize the solution to O(n) using a sliding window and queue?



*/


#include <bits/stdc++.h>
using namespace std;


int main(){
    int arr[] = {2,-3,4,4,-7,-1,4,-2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3; // window size

    vector <int> ans;

    for (int i=0; i<=n-k; i++){
        for (int j=i; j<=i+k-1; j++){
            if (arr[j] < 0){
                ans.push_back(arr[j]);
                break;
            }
        }
    }

    // display ans
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}



// optimised fot interviews
#include <bits/stdc++.h>
using namespace std;

vector <int> firstNegativeInWindow(int arr[], int n, int k) {
    deque <int> dq;  // stores indices of negative numbers
    vector<int> ans;

    int i = 0, j = 0;

    while (j < n) {

        // If current element is negative, add its index to deque
        if (arr[j] < 0) dq.push_back(j);

        // Window size not yet reached
        if (j - i + 1 < k) {
            j++;
        }

        // When window size hits k
        else if (j - i + 1 == k) {
            // If deque is not empty, front element is the first negative
            if (!dq.empty()) ans.push_back(arr[dq.front()]);
            
            // If no negative number found in this window
            else ans.push_back(0);  

            // Before sliding the window, check if the outgoing element was negative
            if (!dq.empty() && dq.front() == i) dq.pop_front();

            // Slide the window
            i++;
            j++;
        }
    }

    return ans;
}

int main() {
    int arr[] = {2, -3, 4, 4, -7, -1, 4, -2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    vector <int> result = firstNegativeInWindow(arr, n, k);

    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
