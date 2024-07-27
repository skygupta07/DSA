#include <bits/stdc++.h>

int main(){
    int arr[] = {1,3,5,7,9,10,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4; // window size
    int maxSum = INT_MIN;
    int maxIdx = -1;
    int prevSum = 0;
    for (int i=0; i<k; i++){    // sabse pehli baar to khidki bharni hi padegi
        prevSum += arr[i];
    }
    maxSum = prevSum;

    int i = 1; //imp -> i pointer denotes start of window
    int j = k; // imp -> j pointer denotes end of window

    while (j<n){  // constraint dusre waale hi pointer pe hai..

// currentWindowSum = prevWindowSum + lastElement of current window - first element of prev window

        int currSum = prevSum + arr[j] - arr[i-1]; // calculating current window sum
        
        // now check and update if maxSum has been changed
        if (currSum > maxSum){
            maxSum = currSum;
            maxIdx = i; // remembering the starting index of maxSum sliding window...
        }

        prevSum = currSum;  // next window banane se pehle ke updates

        i++;    // both i and j pointer will be incremented by 1
        j++; // window ko aage badaya
    }

    cout<<"max window sum is: "<<maxSum<<endl;

    for (int p=maxIdx; p<(maxIdx+k); p++){
        cout<<arr[p]<<" ";
    }
    cout<<endl;

        



}







/*
1 2 3 4 5 6 7 8 9 

1 2 3 = 6
2 3 4 = 9  =(2+3) + 4
3 4 5 = 13 = (3+4) + 5

currSum = prevSum + currNext - prevFirst

-> window starting from i pointer 




*/