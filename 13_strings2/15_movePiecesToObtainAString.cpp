#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();

        // Remove all '_' and check if the relative order of 'L' and 'R' matches
        string startPieces, targetPieces;
        for (char ch : start) {
            if (ch != '_') startPieces += ch;
        }
        for (char ch : target) {
            if (ch != '_') targetPieces += ch;
        }
        if (startPieces != targetPieces) return false;

        // now, Check movement constraints for 'L' and 'R'

        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'L') {
                // Match 'L' in start with 'L' in target

                // skipping any underscore if come in raasta...
                while (target[j] != 'L') j++;

                // target mai 'L' character right mai mil to gya  ...but not possible to move to bhi return false...

                if (i < j) return false; // 'L' cannot move right
                ++j;
            }
        }

        j = 0;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'R') {
                // Match 'R' in start with 'R' in target
                while (target[j] != 'R') ++j;
                if (i > j) return false; // 'R' cannot move left -> eliminate karo ...
                ++j;    // for next target..
            }
        }

        return true;
    }
};
