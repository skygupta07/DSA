#include <iostream>
#include <vector>
using namespace std;
int main(){

}

bool cmp(SinglyLinkedListNode* temp1, SinglyLinkedListNode* temp2) {
    return temp1->data < temp2->data;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    vector<SinglyLinkedListNode*> v;
    
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;
    
    while (temp1 != NULL) {
        v.push_back(temp1);
        temp1 = temp1->next;
    }
    
    while (temp2 != NULL) {
        v.push_back(temp2);
        temp2 = temp2->next;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    // Creating the linked list from the vector
    SinglyLinkedListNode dummy(0);
    SinglyLinkedListNode* dummyCopy = &dummy;
    
    for (int i = 0; i < v.size(); i++) {
        dummyCopy->next = v[i];
        dummyCopy = dummyCopy->next;
    }
    
    dummyCopy->next = nullptr; // Ensure the last node points to NULL
    
    return dummy.next;  
}



------ m2 --------

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;
    
    SinglyLinkedListNode dummy(0);
    SinglyLinkedListNode* dummyCopy = &dummy;
    
    while (temp1 != NULL && temp2 != NULL){
        if (temp1->data < temp2->data){
            dummyCopy->next = temp1;
            dummyCopy = dummyCopy->next;
            temp1 = temp1->next;
        }
        else{
            dummyCopy->next = temp2;
            dummyCopy = dummyCopy->next;
            temp2 = temp2->next;
        }
    }
    
    // ll1 exhausted 
    if (temp1 == NULL){
        dummyCopy->next = temp2;
    }
    
    if (temp2 == NULL){
        dummyCopy->next = temp1;
    }
    
    return dummy.next;
}
