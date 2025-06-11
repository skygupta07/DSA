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
    ListNode* temp = head;

    while (temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

// fn converts array to linked list and return its head node...
ListNode* convertArr2LL(int arr[], int n){
    ListNode* head = new ListNode(arr[0]);  //don't touch the head node, to traverse
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

ListNode* removeHead(ListNode* &head){  // actual ll mai change hoga agar reference 
                                        // se pass kiya to...
    if (head == NULL) return head;
    ListNode* temp = head;
    head = head->next;
    delete temp;    // or free(temp)
    return head;
}


ListNode* removeTail(ListNode* &head){
    if (head == NULL || head->next == NULL) return NULL;
    ListNode* temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    // now temp standing at second last node..
    free(temp->next);   // deleted the last element at tail..
    temp->next = NULL;
    return head;
}


ListNode* removeK(ListNode* &head, int k){
    if (head == NULL) return NULL;
    if (k==1) removeHead(head);

    int cnt = 0;
    ListNode* temp = head;
    ListNode* prev = NULL;

    while (temp != NULL){
        cnt++;
        if (cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;    // good trick to maintain prev and curr in singly linked list..
        temp = temp->next;
    }
    return head;
}

ListNode* removeEl(ListNode* &head, int el){
    if (head == NULL) return NULL;

    if (head->val == el){
        ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    ListNode* temp = head;  // you may maintain temp or curr also...
    ListNode* prev = NULL;

    while (temp != NULL){
        if (temp->val == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;    // good trick to maintain prev and curr in singly linked list..
        temp = temp->next;
    }
    return head;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof (arr)/sizeof(arr[0]);
    ListNode* head = convertArr2LL(arr , n); 
    cout<<"original linked list is: " ; 
    printLL(head);
    // try newhead
    ListNode* newHead = removeHead(head);
    printLL(head);
    printLL(newHead);
    head = removeTail(head);
    printLL(head);

    removeK(head,2);
    printLL(head);

    removeEl(head,2);
    printLL(head);
}