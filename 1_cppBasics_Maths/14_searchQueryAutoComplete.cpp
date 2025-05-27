#include <bits/stdc++.h>
using namespace std;

/*


Search Query Auto Complete
Difficulty: HardAccuracy: 43.24%Submissions: 12K+Points: 8Average Time: 60m

Design a search query autocomplete system for a search engine.

The users will input a sentence ( which may have multiple words and ends with special character '#').

For each character they type except '#', you need to return the top 3 previously entered and most frequently queried sentences that have prefix the same as the part of sentence already typed.

Here are the specific rules:

The frequency for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 sentences should be sorted by frequency (The first is the most frequent).  If several sentences have the same frequency, you need to use ASCII-code order (smaller one appears first).
If less than 3 valid sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.


Your job is to implement the methods of the AutoCompleteSystem:

AutoCompleteSystem(String[] sentences, int[] times): This is the constructor. The input is previously used data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical sentences.
Now, the user wants to input a new sentence. The following function will provide the next character the user types:

String[] input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output an array will be the top 3 historical sentences that have prefix the same as the part of sentence already typed.


Example:

Operation:
AutoCompleteSystem(["i love you", "island",
"ironman", "i love geeksforgeeks"], [5,3,2,2])

The system have already tracked down the
following sentences and their corresponding
times:
"i love you" : 5 times
"island" : 3 times
"ironman" : 2 times
"i love geeksforgeeks" : 2 times

Now, the user begins another search:

Operation: input('i')
Output:
["i love you", "island","i love
                       geeksforgeeks"]

Explanation:
There are four sentences that have prefix
"i". Among them, "ironman" and "i love
geeksforgeeks" have same frequency. Since
' ' has ASCII code 32 and 'r' has ASCII code
 114, "i love geeksforgeeks" should be in
front of "ironman". Also we only need to
output top 3 most frequent sentences, so
"ironman" will be ignored.

Operation: input(' ')
Output: ["i love you","i love geeksforgeeks"]
Explanation:
There are only two sentences that have prefix
"i ".

Operation: input('a')
Output: []
Explanation:
There are no sentences that have prefix "i a"

Operation: input('#')
Output: []
Explanation:
The user finished the input, the sentence
"i a" should be saved as a historical
sentence in system. And the next input
will be counted as a new search.

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class AutoCompleteSystem
{
private:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> children; // Dynamic storage for characters
        bool isTerminal = false;                  // Marks end of a valid sentence
    };

    struct Compare
    {
        // Custom comparator: Higher frequency first, then lexicographical order
        bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        {
            if (a.first == b.first)
                return a.second > b.second; // Lexicographical order for tie
            return a.first < b.first;       // Higher frequency first
        }
    };

    TrieNode *root;
    unordered_map<string, int> count; // Frequency map
    string inProgress = "";
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

public:
    // Constructor to initialize Trie with sentences & frequencies
    AutoCompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++)
        {
            insert(sentences[i]);
            count[sentences[i]] = times[i];
        }
    }

    // Inserts a sentence into the Trie
    void insert(string str)
    {
        TrieNode *node = root;
        for (char ch : str)
        {
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isTerminal = true;
    }

    // DFS function to find all sentences with given prefix
    void search(TrieNode *node, string prefix, vector<string> &results)
    {
        if (node->isTerminal)
        {
            results.push_back(prefix); // Store all matching sentences
        }

        for (auto &child : node->children)
        {
            search(child.second, prefix + child.first, results); // Explore further
        }
    }

    // Handles user input character-by-character and returns top 3 autocomplete results
    vector<string> input(char c)
    {
        vector<string> ans;

        if (c == '#')
        {
            // End of sentence: Insert into Trie and reset input tracking
            count[inProgress]++;
            insert(inProgress);
            inProgress = "";
            return ans;
        }

        inProgress += c; // Append character to current input

        // Traverse Trie to find prefix match
        TrieNode *node = root;
        for (char ch : inProgress)
        {
            if (node->children.find(ch) == node->children.end())
                return ans; // No matching sentences
            node = node->children[ch];
        }

        // Find matching sentences using DFS
        vector<string> results;
        search(node, inProgress, results);

        // Sort results based on frequency and lexicographical order
        sort(results.begin(), results.end(), [&](string &a, string &b)
             {
                 if (count[a] == count[b])
                     return a < b;           // Lexicographical order for tie
                 return count[a] > count[b]; // Higher frequency first
             });

        // Keep only top 3 results
        for (int i = 0; i < min(3, (int)results.size()); i++)
        {
            ans.push_back(results[i]);
        }

        return ans;
    }
};

/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> sentences(n);
        vector<int> times(n);
        for (int i = 0; i < n; ++i)
        {

            getline(cin, sentences[i]);
            cin >> times[i];
            cin.ignore();
        }
        AutoCompleteSystem *obj = new AutoCompleteSystem(sentences, times);
        int q;
        cin >> q;
        cin.ignore();

        for (int i = 0; i < q; ++i)
        {
            string query;
            getline(cin, query);
            string qq = "";
            for (auto &x : query)
            {
                qq += x;
                vector<string> suggestions = obj->input(x);
                if (x == '#')
                    continue;
                cout << "Typed : \"" << qq << "\" , Suggestions: \n";
                for (auto &y : suggestions)
                {
                    cout << y << "\n";
                }
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends