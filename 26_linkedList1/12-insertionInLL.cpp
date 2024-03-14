#include <iostream>
#include <vector>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int data, ListNode* next = NULL){ //constructor
        this->val = data;
        this->next = NULL;
    }
};

void printLL(ListNode* &head){
    ListNode* temp = head;
    while (temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

ListNode* convertArr2LL(int arr[], int n){
    ListNode* head = new ListNode(arr[0]);  // don't touch the head node, to traverse
    // over the linked list create a ListNode* mover and place it on head initially...
    // #never ever temper the head...
    ListNode* mover = head;
    for (int i=1; i<n; i++){
        ListNode* temp = new ListNode(arr[i]);  //created node
        // now establish relations
        mover->next = temp;
        mover = temp;   // or mover = mover->next 
    }
    return head;
}

// insertion Operation...
ListNode* insertAtHead(ListNode* &head, int el){
    if (head == NULL) return new ListNode(el);  // very first node creation...
    ListNode* temp = new ListNode(el);
    temp->next = head;
    head = temp;
    return head;
}

ListNode* insertAtTail(ListNode* &head, int el){
    if (head == NULL) return new ListNode(el);
    ListNode* newNode = new ListNode(el);
    ListNode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    // now temp is at last element...
    temp->next = newNode;
    return head;
}

ListNode* insertAtPosition(ListNode* &head, int el, int k){
    if (head == NULL){
        if (k==1) return new ListNode(el);
        else return head;
    }
    if (k==1) return insertAtHead(head,el);

    int cnt = 0;
    ListNode* temp = head;
    while (temp!=NULL){
        cnt++;
        if (cnt == (k-1)){
            ListNode* x = new ListNode(el,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof (arr)/sizeof(arr[0]);
    ListNode* head = convertArr2LL(arr , n);
    printLL(head);

    insertAtHead(head,20);
    printLL(head);

    insertAtTail(head,45);
    printLL(head);

    insertAtPosition(head,30,5);
    printLL(head);
        
    
    

}