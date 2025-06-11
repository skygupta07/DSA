#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

string user_logic(ListNode* head) {
    /*
    Write your logic here.
    Parameters:
        head (ListNode*): Head node of the singly linked list
    Returns:
        string: "even" if the final number is an even number, otherwise "odd"
    */
    ListNode *p = head;

    string s = "";
    while(p && p -> val == 0){
        p = p -> next;
    }

    while(p){
        s += to_string(p -> val);
        p = p -> next;
    }
    
    int n = s.size();
    int i = n - 1;
    while(i >= 0 && s[i] == '0'){
        i--;
    }

    long long x = 1, res = 0, sum = 0, num = 0;

    for(int j = i; j >= 0; j--){
        num = s[j] - '0';
        sum += num;
        res = res * x + num;
        x *= 10;
    }

    int answer = res - sum;
    return (answer % 2 == 0) ? "even" : "odd";
}

int main() {
    int N;
    cin >> N;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    string result = user_logic(head);
    cout << result << endl;
    return 0;
}