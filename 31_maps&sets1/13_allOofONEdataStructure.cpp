#include <bits/stdc++.h>
using namespace std;

class AllOne {
public:

    unordered_map <string, int> mp;
    set <pair <int, string> > st;

    AllOne() {
        mp.clear();
    }
    
    void inc(string key) {
        int n = mp[key];
        mp[key]++;

        st.erase({n, key});
        st.insert({n+1 , key});
    }
    
    void dec(string key) {
        int n = mp[key];
        mp[key]--;

        st.erase({n, key});
        if (mp[key] > 0) st.insert({n-1, key});
        else mp.erase(key);
    }
    
    string getMaxKey() {
        if (!st.empty()) return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if (!st.empty()) return st.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */