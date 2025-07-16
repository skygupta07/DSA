// formDoublyLinkedList.cpp

#include <bits/stdc++.h>
using namespace std;

struct DoubleNode {
    int doubledata;
    DoubleNode* doubleprev;
    DoubleNode* doublenext;
    DoubleNode(int val) : doubledata(val), doubleprev(nullptr), doublenext(nullptr) {}
};

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

DoubleNode* user_logic(int n, int m, const std::vector<std::vector<int>>& arr) {
    std::vector<Node*> nodeList;
    
    // Create Node arraylist from 2D array
    for (int i = 0; i < n; ++i) {
        Node* head = new Node(arr[i][0]);
        Node* current = head;

        for (int j = 1; j < m; j++) {
            Node* newNode = new Node(arr[i][j]);
            current->next = newNode;

            current = newNode;
        }
        nodeList.push_back(head);
    }

    DoubleNode* dummy = new DoubleNode(0);
    DoubleNode* tail = dummy;

    // Add nodes from even indices
    for (int i = 0; i < nodeList.size(); i += 2) {
        Node* current = nodeList[i];
        while (current != nullptr) {
            DoubleNode* newNode = new DoubleNode(current->data);
            tail->doublenext = newNode;
            newNode->doubleprev = tail;
            tail = newNode;
            current = current->next;
        }
    }

    // Add nodes from odd indices
    for (int i = 1; i < nodeList.size(); i += 2) {
        Node* current = nodeList[i];

        while (current != nullptr) {
            DoubleNode* newNode = new DoubleNode(current->data);
            tail->doublenext = newNode;

            newNode->doubleprev = tail;
            tail = newNode;
            current = current->next;
        }
    }

    DoubleNode* head = dummy->doublenext;
    
    if (head != nullptr) {
        head->doubleprev = nullptr;
    }

    delete dummy;
    return head;

}

void print_double_linked_list(DoubleNode* head) {
    DoubleNode* current = head;

    while (current != nullptr) {
        std::cout << current->doubledata << " <---> ";
        current = current->doublenext;
    }

    std::cout << "null" << std::endl;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> arr(n, std::vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            std::cin >> arr[i][j];
            
        }
    }

    DoubleNode* double_linked_list_head = user_logic(n, m, arr);
    print_double_linked_list(double_linked_list_head);

    return 0;
}