#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[26];  // Array to hold references to child nodes (for 'a' to 'z')
    bool flag = false; // Flag to mark the end of a word

    // Checks if the node contains a reference for the given character
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL; // return wahi karte hai jo chahte hai...
    }

    // Adds a new node for the given character
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Returns the reference to the child node corresponding to the character
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};


class Trie {
    Node* root;  // Root node of the Trie

public:

    /** Initialize the Trie data structure. */
    Trie() {
        root = new Node();  // Initialize the root node
    }

    /** Insert a word into the Trie. */
    void insert(string word) {
        Node* node = root;  // Start from the root

        // Iterate over every character in the word
        for (int i = 0; i < word.size(); i++) {
            // If the current node doesn't contain the character, create a new node
            if (!node->containsKey(word[i])) {
                Node* newNode = new Node();
                node->put(word[i], newNode);
            }
            // Move to the next node (child)
            node = node->get(word[i]);
        }

        // Mark the end of the word
        node->flag = true;
    }

    /** Search for a word in the Trie. */
    bool search(string word) {
        Node* node = root;  // Start from the root

        // Iterate over every character in the word
        for (int i = 0; i < word.size(); i++) {
            // If the character is not found, return false
            if (!node->containsKey(word[i])) {
                return false;
            }
            // Move to the next node (child)
            node = node->get(word[i]);
        }

        // Check if the last node is marked as the end of a word
        return node->flag;
    }

    /** Check if there is any word in the Trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;  // Start from the root

        // Iterate over every character in the prefix
        for (int i = 0; i < prefix.size(); i++) {
            // If the character is not found, return false
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            // Move to the next node (child)
            node = node->get(prefix[i]);
        }

        // If the prefix is found, return true
        return true;
    }
};
