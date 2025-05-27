#include <bits/stdc++.h>
using namespace std;

/*

Lily has been given N cards by Rose, each with a number on it, arranged in a line array A. 
Some of these numbers may repeat.

Rose has challenged Lily to find the "special" card number, 
which is the first card number that appears more than once when reading from left to right. 
If no card number repeats, then the "special" card number is considered to be -1.

Your task is to determine the 1-based index of the first repeating card number. 
If there are no repeating numbers, print -1.

Input Format

The first line contains an integer N, representing the number of cards.

The second line contains N space-separated integers, where each integer represents the number on a card.

Output Format

Print a single integer representing the 1-based index of the first repeating card number. 
If no such card number exists, print -1.


*/


int find_first_repeating_card_index(int n, vector<int>& cards) {
    unordered_map <int, int> mp;    // card, idx (1 based indexing)
    unordered_set <int> st; // stores repeating card

    for (int i=0; i<n; i++){
        // agar card already mil chuka h to repeating wale set mai daal do..
        if (mp.find(cards[i]) != mp.end()) st.insert(cards[i]);
        else mp[cards[i]] = i + 1;
    }

    if (!st.empty()){
        int minIdx = INT_MAX;

        for (int card : st){
            minIdx = min(minIdx, mp[card]);
        }  

        return minIdx; 
    }


    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }
    int result = find_first_repeating_card_index(n, cards);
    cout << result << endl;
    return 0;
}