#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n.
Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.
​Return the minimum number of intervals required to complete all tasks
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n){
        priority_queue <int> pq;
        vector <int> mp(26,0);

        for (char i: tasks){
            mp[i - 'A']++;      // count the frequency of each task -> A aaya to zeroth index pe jaake ek count badha do...
        }

        for (int i=0; i<26; i++){
            if (mp[i]) pq.push(mp[i]);      // priority queue mai push kar di saari freq.
        }

        int time = 0;
        
        while (!pq.empty()){
            vector <int> remain;
            int cycle = n+1;    // cycle length = number of elements in cycle i.e. n+1

            while (cycle and !pq.empty()){
                int max_freq = pq.top();
                pq.pop();   // to po push

                if (max_freq > 1){
                    remain.push_back(max_freq - 1);
                }

                ++time;
                --cycle;
            }

            for (int count : remain){
                pq.push(count);
            }

            if (pq.empty()) break;
            time += cycle;
        }

        return time;
    }
};