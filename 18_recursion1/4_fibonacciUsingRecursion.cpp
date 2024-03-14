#include <iostream>
using namespace std;

// int fibonacci(int num)
// {
//     if (num == 0)
//     {
//         return 1;
//     }
//     else if (num == 1)
//     {
//         return 1;
//     }
//     return fibonacci(num -1) + fibonacci(num - 2);
// }


// int main()
// {
//     int num;
//     cout << "enter the number :" << endl;
//     cin >> num;
//     // this fibonacci series is 1, 1, 2, 3, 5, 8, 13 and so on
//     cout <<  num << "th element of fibonacci series is : " << fibonacci (num-1)<<endl;

//     for (int i=0; i<num; i++){
//         cout<<fibonacci(i) <<" ";
//     }
//     return 0;
// }
// // 

int fibonacci(int n){
    if (n==1 || n==2) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<fibonacci(n)<<endl;
    // 1 1 2 3 5 8 13 21 34 55 89... 
}

// example of multiple recursion call...
// at each call itself calling two call so it is exponential time taking problem....