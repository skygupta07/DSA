#include <iostream>
#include <vector>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int data){ //constructor
        this->val = data;
        this->next = NULL;
    }
};

void printLL(ListNode* &head){
    ListNode* temp = head;  // temp is ListNodePointer here
    
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

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof (arr)/sizeof(arr[0]);
    ListNode* llHead = convertArr2LL(arr , n);
    printLL(llHead);
}