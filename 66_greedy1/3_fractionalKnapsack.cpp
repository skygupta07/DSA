// fractionalKnapsack.cpp


/*

Given two arrays, val[] and wt[], representing the values and weights of items, 
and an integer capacity representing the maximum weight a knapsack can hold, 
determine the maximum total value that can be achieved by putting items in the knapsack. 
You are allowed to break items into fractions if necessary.

Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000

Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item 
with value 120 and weight 30, to fit it into weight 20. 
so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value 
of item we can have is 240.00 from the given capacity of sack. 


Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
Output: 160.000000
Explanation: Take both the items completely, without breaking. 
Total maximum value of item we can have is 160.00 from the given capacity of sack.

Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
Output: 60.000000
Explanation: In this case, the knapsack capacity exceeds the combined weight of all items 
(5 + 10 + 15 = 30). Therefore, we can take all items completely, yielding a total maximum value 
of 10 + 20 + 30 = 60.000000.


Constraints:
1 <= val.size=wt.size <= 1e5
1 <= capacity <= 1e9
1 <= val[i], wt[i] <= 1e4

*/


// more standard code..


#include <bits/stdc++.h>
using namespace std;

// ========================== 🧱 Item Class ==========================

class Item {
public:

    double profit;
    double weight;

    Item(double p, double w) {
        profit = p;
        weight = w;
    }

    // Method to calculate profit-to-weight ratio
    double ratio() const { // using const you're promising the compiler that this function is read-only
        return profit / weight;
    }

};

// ========================== 🎯 Solver Class ==========================
class FractionalKnapsackSolver {
public:

    vector<Item> items;


    // Constructor: takes separate profit and weight arrays
    FractionalKnapsackSolver(const vector<double>& profits, const vector<double>& weights) {
        for (int i = 0; i < profits.size(); ++i) {
            items.emplace_back(profits[i], weights[i]);
        }
    }

    // Main method to compute max profit
    double getMaxProfit(double W) {
        // Sort items by profit-to-weight ratio in descending order
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.ratio() > b.ratio();
        });

        double totalProfit = 0.0;

        for (const Item& item : items) {
            if (item.weight <= W) {
                totalProfit += item.profit;
                W -= item.weight;
            } else {
                totalProfit += item.ratio() * W;
                break;  // Knapsack is full
            }
        }

        return totalProfit;
    }
};

// ========================== 🚀 Driver Code ==========================
int main() {

    vector <double> profits = {60, 100, 120};
    vector <double> weights = {10, 20, 30};

    double capacity = 50;

    FractionalKnapsackSolver solver(profits, weights);
    double maxProfit = solver.getMaxProfit(capacity);

    cout << fixed << setprecision(2) << "Maximum Profit: " << maxProfit << endl;

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

// Struct to hold profit and weight of an item
struct Item {
    double profit;
    double weight;
};

// Main function to solve the fractional knapsack problem
double fractionalKnapsack(const vector<double>& profits, const vector<double>& weights, int n, double W) {
    vector<Item> items;

    // Step 1️⃣: Create item list from input vectors
    for (int i = 0; i < n; ++i) {
        items.push_back({profits[i], weights[i]});
    }

    // Step 2️⃣: Sort items by decreasing profit-to-weight ratio
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return (a.profit / a.weight) > (b.profit / b.weight);
    });

    double totalProfit = 0.0;

    // Step 3️⃣: Pick items greedily
    for (const Item& item : items) {
        if (item.weight <= W) {
            totalProfit += item.profit;
            W -= item.weight;
        } else {
            totalProfit += (item.profit / item.weight) * W;
            break; // Knapsack is full
        }
    }

    return totalProfit;
}




#include <bits/stdc++.h> // includes all standard C++ libraries
using namespace std;

// =========================== 🔁 Custom Comparator Function ===============================

// This comparator is used to sort items based on their profit-to-weight ratio.
// Higher ratio items should be placed first because they give more "value per unit weight".
bool cmp(pair <int, int> &p1, pair <int, int> &p2) {
    // pair.first -> profit, pair.second -> weight

    double r1 = (p1.first * 1.0) / (p1.second * 1.0); // Convert to double for accurate division
    double r2 = (p2.first * 1.0) / (p2.second * 1.0);

    return (r1 > r2);  // item with higher profit/weight comes first
}

// =========================== 🎯 Main Function ===============================
double fractionalKnapsack(vector<int> &profit, vector<int> &weights, int n, int W) {

    vector <pair <int, int>> arr; // to hold {profit, weight} pairs

    // Step 1️⃣: Convert profit[] and weights[] into a single array of pairs
    for (int i = 0; i < n; i++) arr.push_back({profit[i], weights[i]});
    

    // Step 2️⃣: Sort items by their profit-to-weight ratio using custom comparator
    sort(arr.begin(), arr.end(), cmp); // Greedy logic applied here

    double result = 0; // To store the final total maximum profit

    // Step 3️⃣: Iterate through sorted items and greedily pick full or fractional items
    for (int i = 0; i < n; i++) {

        // 🧺 Case 1: If full item can fit in the knapsack
        if (arr[i].second <= W) {

            result += arr[i].first;        // Add full profit
            W -= arr[i].second;            // Reduce knapsack capacity

        }

        // 🧮 Case 2: Only a fraction of the item can be picked (last possible pick)
        else {
            // fractional profit = (profit/weight) * remaining capacity
            result += ((arr[i].first * 1.0) / (arr[i].second * 1.0)) * W;
            W = 0; // knapsack is full now
            break; // break since we can't pick more items
        }
    }

    return result; // return total maximum profit
}


int main(){
    vector <int> profit = {60,100,120};
    vector <int> weights = {10,20,30};

    int W = 50;
    int n = 3;
    
    cout<<fractionalKnapsack(profit, weights, n, W);
    
    return 0;
}


/*

greedy since fractional
sort in desc as per profit/weight ratio and pick with maximum ratio profit/weight 
sorting using custom comparator 

0/1 -> dp use 

*/