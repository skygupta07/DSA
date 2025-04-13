#include <bits/stdc++.h>
using namespace std;

// gives tle
vector<int> nextSmallerElement(vector<int> &arr, int n){
   vector <int> ans(n, -1);

   for(int i=0; i<n-1; i++){
       for (int j=i+1; j<n; j++){
           if (arr[j] < arr[i]){
               ans[i] = arr[j];
               break;
           }
       }
   }

   return ans;
}

// using stack
// nse(next smaller element) ya nge(next greater element) ke liye stack use karte h => offline salescode OA

#include <bits/stdc++.h> 
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    // Step 1: Answer vector banate hain jisme har element ke corresponding "Next Smaller Element" store hoga
    // Initially sabko -1 se fill kar dete hain, maan ke chalte hain ke kisi element ka NSE nahi mila
    vector<int> ans(n, -1);

    // Step 2: Stack banate hain jo indices ko store karega
    // Hum values nahi, balki indices stack mein daalte hain taki hum answer vector mein correct index update kar sakein
    stack <int> stk;

    // step 3: Traverse karte hain array ke har element par
    for (int i = 0; i < n; i++) {

        // Jab tak stack khali nahi ho jaata aur
        // current element chhota hai stack ke top wale index ke element se,
        // tab tak NSE mil gaya ka logic apply hoga
        while (!stk.empty() && arr[i] < arr[stk.top()]) {
            // stack ke top wale index ke element ke liye humne uska next smaller dhoond liya
            ans[stk.top()] = arr[i]; // us position par current chhota element assign kar do
            stk.pop(); // ab uska kaam ho gaya, us index ko stack se hata do
        }

        // Step 4: Current index ko stack mein push kar do
        // Ho sakta hai iske liye aage jaake koi chhota element mile
        stk.push(i);
    }

    // Step 5: Ab jinke liye koi next smaller nahi mila (jo stack mein reh gaye),
    // unka ans vector pehle hi -1 set tha, toh usko change karne ki zarurat nahi hai

    return ans; // Final answer return karo
}
