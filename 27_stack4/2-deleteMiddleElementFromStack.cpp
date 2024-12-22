/*

#include <bits/stdc++.h> 

void solve(stack <int> &inputStack, int count, int size){
   if (count == size/2){
      inputStack.pop();
      return;
   }
   int num = inputStack.top();   // usko temporarily kahi store kar lo...
   inputStack.pop();

   // recursive call
   solve(inputStack, count+1, size);
   inputStack.push(num);
}


void deleteMiddle(stack<int>&inputStack, int N){
	int count = 0;
   solve(inputStack,count,N);
}




/*
recursion kehta hai ki ek case ke liye solve kar do baaki cases to mai sambhal lunga... 



*/