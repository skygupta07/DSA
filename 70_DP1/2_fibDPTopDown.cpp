// fibDpTopDown.cpp

#include<iostream>
#include<vector>
using namespace std;

vector <int> dp;  // declaring global parameter for ease
                // beech me jo subproblem calculate karoge usko yaad rakhne ke liye to koi jagah chahiye na,
                // isliye vector (hashmap set kucch bhi ho sakta tha...)


int fib(int n){
    if(n==0 || n==1) return n; // base case to chedo mat

    // dp check to identify if problem was solved earlier
    if (dp[n]!=-1) return dp[n];  
                    // means if we have already computed it so simply use it now...no need to fight to compute again
    // base case ke just baad dekho ki agar pehle se calculated hai to wahi se fetch karo..otherwise ye to dubara
    // se compute karne lagega...
    // mene kabhi time mai pehle jaake is state ko already compute kar rakha hai ab meri mehnat
    // ka fruit directly hi de do

    //dp[i] = -1 denotes that ith subproblem is not yet computed..    
    return dp[n] = fib(n-1) + fib(n-2); // function call to fill the dp values
    // jaise hi tum call laga ke value calculate kar rahe ho usi time dp me save bhi kar lo
}


int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    dp.clear();  // upar humne ekdum hi simply initialise kar diya tha it means ab hume 
                // us garbage value ko clear karna hoga before using this vector.. not mandatory showoff ke liye
    
    dp.resize(n+1,-1);  // n+1 size ka vector bana jisme ki saare element -1 se initilase hue hai..(kyuki aajtak mene copy kholi hi nahi thi...)
            // n+1 size ka vector banaya kyuki number of unique subproblems are n+1 => hum saara syllabus
            // to yaad nahi kar sakte isliye bas unique subproblems hi yaad rakhenge (faq)
            // f(0) f(1) f(2) f(3) ye sab yaad rakh lo bas aap...

    cout<<fib(n)<<"\n";
    return 0;

}

// by applying Dynamic Programming actually we are reducing our T.C. by using some extra S.C.
// recursive soln 0(2^^n) i.e. exponential  while dp soln is linear O(2n)
// s.c. now is O(n) stack space and O(n) -> dp vector
/*
you should carefully observe two properties before applying the dp solution
p1 -> repeating subproblem. -> f(5) baar baar aa raha tha 
p2 -> optimal substructure -> f(4) aur f(3) ka use karke f(5) ka answer nikal liya...


=> divide and conquer mai it is not necessary ki subproblem repeat ho  (jaise merge sort mai ek bar jo subproblem calculate kar li wo dubara 
thodi hum repeat karte hai!!)
=> while in pure brute force recursive solution you may observe repeating subproblem easily

=> optimal substructure -> if we have optimal answer of smaller subproblem and using them
we can find optimal answer of bigger subproblem. If this exist then we have optimal
substructure..

iterative solutions mai bhi dp lag sakti hai.. you may create vector or hashmap to
memoize base repetitive kaam hum faltu mai kar rahe hoi kahi bhi..


--- how to apply DP -----

1. identify if dp can be applied
2. identify the number of unique states.
3. identify state of subproblems.
4. update the brute force solution


*/

/*
top down -> recursive soln par dp lagana , also called memoization
=> for very very very tight constraint maybe bottom up solution may cause stackoverflow..

top down mai ye fayda recursion hi provide kar deta hai ki hume order of preparation 
of subproblem ke baare mai sochna hi nahi padta...

pehle mostly top down solution hi likhte hai ...

--------------
=> then we go for bottom up (iterative solution) => for loop laga ke
for bottom up soln along with the recurrence relation you need to find out figure out 
order of preparation of subproblem

iss baar function ko dubara call nahi lagayenge instead we can identify different states by 
the array only....

-> function ka f aapka dp se replace ho jaega




*/