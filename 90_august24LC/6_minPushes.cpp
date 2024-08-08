class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(auto it : word) mp[it]++;
        priority_queue<int> pq;
        for(auto it : mp)
        {
            pq.push(it.second);
        }

        int count = 0; 
        int ans = 0;
        while(!pq.empty())
        {
            int n = pq.top(); pq.pop();
            ans += n *(count/8 +1);
            count++;
        }
        return ans;
    }
};



// ----------


class Solution {
public:

    unordered_map <char,int> mp;

    // Custom comparison function for sorting the freqVector in decreasing order
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
    }

    int minimumPushes(string word) {
        // Calculate frequency of each character
        for (auto ch : word) {
            mp[ch]++;
        }

        // Convert the frequency map to a vector of pairs for sorting -> good method
        vector<pair<char, int>> freqVec(mp.begin(), mp.end());

        // Sort the characters based on frequency in decreasing order
        sort(freqVec.begin(), freqVec.end(), cmp);

        // Map to store push values
        unordered_map<char, int> pushes;
        int bunch = 8;  // 8 8 8 2 ka guccha hi form hoga max since 26 chars
        int push = 1;

        // Assign push values to the first 8 unique characters, then to the next 8, and so on
        for (int i = 0; i < freqVec.size(); i++) {
            if (bunch == 0) {       // good way to update things in for loop as well
                push++;
                bunch = 8;
            }
            pushes[freqVec[i].first] = push;    // corresponding character ko uski push value assign karwayi....
            bunch--;
        }

        // Calculate the minimum pushes required
        int ans = 0;
        for (int i = 0; i < word.length(); i++) {
            ans += pushes[word[i]];
        }

        return ans;
    }
};