// rotateLinkedListByKSteps.cpp


//LC61

// rotate by k steps ka matlab last ke element ko pakdo then usey aage laga do..

/*

Given the head of a linked list, rotate the list to the right by k places.


Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 1e9

*/

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:    

    ListNode* rotateRight(ListNode* &head, int k){
        // handling zero or single node
        if (head == NULL || head->next == NULL) return head;
        
        int n = 0;  // for size
        
        ListNode* temp = head;
        ListNode* tail = NULL;
        
        while(temp != NULL){

            // very much smart strategy to find tail while finding the size itself...
            if (temp->next == NULL) tail = temp;
            temp = temp->next;

            n++;
        }

        // chota modulus bada = chota
        k = k%n;

        if (k == 0) return head;

        // temp ko le aao dubara se head pe...
        temp = head;  
        
         // i=1 se start karna must taki n-k-1 tak pe ruk jaee... 
        //  or standard way is for (int i=0; i<n-k-1; i++) 

        // i.e. in case you want to reach your control over the dth position when you died ... 
        // then please ye wali hi lic karwaye...
        // for (int i=0; i<d; i++)

        for(int i=1; i<n-k; i++){
            temp = temp->next;
        }
        
        // algorithm (kua paani rule)
        tail->next = head; // simply pure iss gucche ko head pe point karwa diya...
        head = temp->next; // new starting point
        
        temp->next = NULL; // kaam ho jaane ke baad riste naate sab khatam bhai...

        return head;     
    }
};



// ---------------- 

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node* &head, int data){
    node* new_node = new node(data);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(node* &head, int data){
    node* temp = head;

    while(temp->next!=NULL){
        temp= temp->next;
    }

    node* new_node = new node(data);
    temp->next = new_node;
}

void printNodes(node* &head){
    node* temp = head;

    while (temp != NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }

    cout<<"NULL"<<endl;
}

int lengthLL(node* &head){
    int n = 0;  // count variable as n
    node* temp = head;
    
    while(temp!=NULL){ // arey bhai jab puri length count karna chahta hai to puri LL traverse bhi to karega
        temp = temp->next; // but ha agar aisa kaam hai ki last wale node ki need hai tab to while(temp-next!=NULL) wali condition lagegi..
        n++;
    }

    return n;
}


void rotateLL(node* &head, int k){

    // any number of rotation will not affect
    if (head == NULL || head->next == NULL) return;

    node* temp = head;
    node* tail = NULL;  //Important (as we declared it somewhat globally) initially
    // kisi bhi nalle berojgar pointer ko null pe hi point karna chahiye.

    while(temp !=NULL){
        if (temp->next == NULL) tail = temp;
        temp = temp->next;   
    } 

    int n = lengthLL(head);
    k = k%n;  // to reduce number of operations.always do it..

    if(k == 0) return;

    temp = head;   // since already bane wale temp ko hi dubara se head pe point kara diya
                    // no need of declaring a new node pointer..(Reduce Reuse Recycle ) variables...

    for (int i=1; i<n-k; i++){
        temp = temp->next;
    }

    // algorithm
    tail->next = head; // to establish link with LL
    head = temp->next;  
    temp->next = NULL;

}



int main(){
     // start with empty linked list i.e. there will be no node and 
    // head pointer pointing to NULL   #important
    node* head = NULL;
    insertAtHead(head,7);
    insertAtHead(head,6);

    insertAtHead(head,5);
    insertAtHead(head,4);

    insertAtHead(head,3);
    insertAtHead(head,2);

    insertAtHead(head,1);
    
    printNodes(head);
    rotateLL(head, 3);
    printNodes(head);

    return 0;
}

// array me rotate karne ke liye: after k elements array ko divide kar diya then 
// dono part of array ko individually reverse karke finally purey array ko reverse kar do..f