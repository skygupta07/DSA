#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    int score;          // Keeps track of how many words pass through this node (used for prefix scores)
    Trie *children[26]; // Array of child nodes for the 26 lowercase letters

    // Constructor to initialize the Trie node
    Trie()
    {
        score = 0;                             // Initialize the score as 0
        memset(children, 0, sizeof(children)); // Set all child pointers to NULL
    }

    // Add a word to the Trie, starting from the ith character
    void add(string &s, int i)
    {
        if (i)
            score++; // Increment the score if we're past the root node
        if (i == s.size())
            return; // If we've reached the end of the word, stop
        // If the child node for the current character doesn't exist, create it
        if (!children[s[i] - 'a'])
            children[s[i] - 'a'] = new Trie();
        // Move to the next character in the word
        children[s[i] - 'a']->add(s, i + 1);
    }

    // Perform DFS to calculate the total prefix score for a given word
    int dfs(string &s, int i)
    {
        if (i == s.size())
            return score; // If we've reached the end of the word, return the score of the current node
        // Add the score of the current node and move to the next character
        return score + children[s[i] - 'a']->dfs(s, i + 1);
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        Trie *trie = new Trie(); // Create a new Trie
        // Insert each word into the Trie
        for (string &s : words)
            trie->add(s, 0);
        vector<int> res; // Vector to store the result
        // For each word, calculate its total prefix score using DFS and store it in the result vector
        for (string &s : words)
            res.push_back(trie->dfs(s, 0));
        return res; // Return the result vector containing prefix scores
    }
};
