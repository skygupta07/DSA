#include <bits/stdc++.h>
using namespace std;


int main(){

    int arr[] = {1,3,5,7,9,10,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 4; // window size

    int maxSum = INT_MIN;
    int maxIdx = -1;

    int sum = 0;  // basically for sum of elements of window...

    for (int i=0; i<k; i++){    // sabse pehli baar to khidki bharni hi padegi
        sum += arr[i];              // t.c. = O(k)
    }

    maxSum = sum;

    // khidki number 2 par chale jaiye...
    int i = 1; //imp
    int j = k; // imp

    while (j<n){  // constraint dusre waale hi pointer pe hai.. // t.c. = O(n-k)
        int sum = sum + arr[j] - arr[i-1]; // calculating current window sum
        
        // now check and update if maxSum has been changed
        if (sum > maxSum){
            maxSum = sum;
            maxIdx = i; // yaha se start hua bada maal milna
        }

        i++;
        j++; // window ko aage badaya
    }

    cout<<"max window sum is: "<<maxSum<<endl;
    
    for (int p=maxIdx; p<(maxIdx+k); p++){
        cout<<arr[p]<<" ";
    }

    cout<<endl;

        
    // total time is O(n) 

}



/*
1 2 3 4 5 6 7 8 9 

1 2 3 = 6
2 3 4 = 9  =(2+3) + 4
3 4 5 = 13 = (3+4) + 5

currSum = prevSum + currNext - prevFirst

-> window starting from i pointer 

*/