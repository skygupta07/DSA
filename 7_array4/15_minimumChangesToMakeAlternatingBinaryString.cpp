class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        if (n == 1) return 0;
        if (n == 2){
            if (s[0] != s[1]) return 0;
            else return 1;
        }

        // Two patterns possible: "010101..." or "101010..."
        int count1 = 0, count2 = 0;
        
        // Count the changes needed for "010101..."
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] != '0') count1++;
            } else {
                if (s[i] != '1') count1++;
            }
        }

        // Count the changes needed for "101010..."
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] != '1') count2++;
            } else {
                if (s[i] != '0') count2++;
            }
        }

        // Return the minimum of the two counts
        return min(count1, count2);
    }
};


/*
easy questions mai possible cases hi soch liya karo....


*/