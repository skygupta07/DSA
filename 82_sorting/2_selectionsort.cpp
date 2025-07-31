// Selection Sort ka Implementation

// select the minimum and swap with the first element...

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 1, 3, 2, 7};

    int n = sizeof(arr) / sizeof(arr[0]);  // Array ka size nikal liya

    // Selection Sort Algorithm
    for (int i = 0; i < n - 1; i++) {  // Ye loop (n-1) times chalega 
        // (or you can say second last element tak hi chalega...), kyunki har iteration me ek 
        // element apni sahi jagah pe set hoga

        int mini = INT_MAX;  // Sabse pehle min ko ek badi value se initialize kar diya
        int mindx = -1;  // Minimum element ka index track karne ke liye ek variable liya
        
        //pure aage ke Unsorted part ke andar minimum element dhundhna hai
        for (int j = i; j < n; j++) { 

            // Agar koi aur chhota element milta hai toh usko update karenge
            if (arr[j] < mini) { 
                mini = arr[j];
                mindx = j;
            }

        }

        // Jo chhota element mila usko unsorted part ke first element se swap kar diya

        swap(arr[i], arr[mindx]); 

        // 🔹 Har iteration me ek element apni sahi jagah pe chala jayega (Sorted part badhta rahega)
    }


    // Sorted array print kar rahe hain
    for (int ele : arr) {
        cout << ele << " ";
    }

}



/*
📝 Selection Sort ka Logic:
---------------------------------
✅ Ek sorted part aur ek unsorted part maintain karna hota hai.
✅ Har iteration me unsorted part se ek minimum element dhundhkar
     usko sorted part ke end me rakh dete hain.

✅ Minimum element dhundhne ke liye pehle min ko INT_MAX set karte hain, 
    fir unsorted part me traverse karke minimum dhundhte hain.


⏳ Time Complexity:
-----------------------
🔹 Best Case: O(n²)
🔹 Worst Case: O(n²)
🔹 Average Case: O(n²)
👉 Yahaan koi optimization nahi hoti, har case me same time lagta hai.

⚠️ Selection Sort **Unstable** hota hai kyunki swapping ki wajah se elements ka order change ho sakta hai.

✅ Kab Use Kare?
-----------------------
🔹 Jab swapping ka cost kam ho (kam swaps wale cases me yeh accha perform karega)
🔹 K minimum elements nikalne ho
🔹 Chhoti size ka array sort karna ho
*/

