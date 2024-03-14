#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair <int,int> &p1, pair <int, int> &p2){  // custom comparator used
    // pair <int, int> -> pair.first -> profit   pair.second -> weight
    double r1 = (p1.first)/(p1.second);
    double r2 = (p2.first)/(p2.second);
    return r1>r2;  
}

double fractionalKnapsack(vector <int> &profit, vector <int> &weights, int n, int W){
                    // profit vector, weight vector, no. of items (n) and total allowed weight()
    vector <pair <int, int> > arr;
    for (int i=0; i<n; i++){
        arr.push_back({profit[i], weights[i]});
    }
    sort(arr.begin(),arr.end(),cmp);    //inbuilt sorting but using custom comparator

    double result = 0;
    for (int i=0; i<n; i++){
        if (arr[i].second <= W){
            result += arr[i].first;
            W -= arr[i].second;
        }
        else{
            result += (arr[i].first*1.0)/(arr[i].second*1.0);
            W = 0;
            break;
        }

    }



}


int main(){
    vector <int> profit = {60,100,120};
    vector <int> weights = {10,20,30};
    int W = 50;
    int n = 3;
    cout<<fractionalKnapsack(profit,weights,n,W);
    return 0;
}


/*
greedy since fractional
sort in desc as per profit/weight ratio and pick with maximum ratio profit/weight 
sorting using custom comparator 

0/1 -> dp use 
*/