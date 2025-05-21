// reconstructItinerary.cpp   // itinerary - a plan of a journey...

#include <bits/stdc++.h>
using namespace std;

/*

you are given a list of airline tickets where tickets[i] = [fromi, toi] 
represent the departure and the arrival airports of one flight. 
Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the 
smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary.
You must use all the tickets once and only once.


Example 1:

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]


Example 2:

Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]

Explanation: Another possible reconstruction is 
["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

*/


class Solution {
public:

        vector <string> findItinerary(vector <vector<string>> &tickets) {
            // Graph banaya hai jisme har airport ke destinations store honge
            unordered_map <string, vector <string>> graph;
    
            // Tickets ko iterate karke graph mein add kiya hai
            for (auto &ticket: tickets) graph[ticket[0]].push_back(ticket[1]);
    
            // Har airport ke destinations ko reverse lexical order mein sort kiya hai
            for (auto &[_, destinations] : graph){
                sort(destinations.rbegin(), destinations.rend());
            }
    
            // Itinerary store karne ke liye ek list banayi hai
            vector <string> itinerary;
    
            // Recursive DFS function banaya hai
            function <void (const string &)> dfs = [&](const string &airport){
                // Jab tak airport ke destinations khatam nahi hote, tab tak explore karo
                while (!graph[airport].empty()){
                    string next = graph[airport].back(); // Sabse chhota lexical order wala destination
                    graph[airport].pop_back(); // Us destination ko remove kiya hai
                    
                    dfs(next); // Recursively next destination par DFS call kiya hai
                }
    
                // Jab koi destination nahi bacha, toh current airport ko itinerary mein add kiya hai
                itinerary.push_back(airport);
            };
    
            // DFS "JFK" se start kiya hai
            dfs("JFK");
    
            // Itinerary ko reverse karke final answer return kiya hai
            reverse(itinerary.begin(), itinerary.end());
    
            return itinerary;
        }
    };