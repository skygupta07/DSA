#include <bits/stdc++.h>
using namespace std;

class Node{
public: // in cpp
    int data;
    Node* next; // next is a node pointer to the next node..

    // constructor in cpp
    Node(int data){
       this->data = data;
       this->next = NULL; // by default koi bhi node banao aap uski next pointer to null ko hi point karegi..
    }
};

void insertATHead(Node* &head, int data){   // singly ll mai hum head maintain
                                    // karte huye chalte hai...
    // in general linked list is passed through head pointer important---

    // applying links using kua paani rule...

    Node* new_node = new Node(data);  // create a new node with name new_node 
    new_node->next = head;// read as: new_node ke next ko head pe point karaya(left ko right pe point karwaya # important)
                                // wo value hua karti thi jo ki aapka right to left mai assign hota hai....

    head = new_node; // then head ko new_node pe point karaya...
                    // since head should always point to the first node of linked list.. 

}


void insertAtTail(Node* &head, int data){
    // kisi bhi position pe insert karne ke liye node hona bhi to chahiye,isliye pehle to tum node banao..

    Node* new_node = new Node(data);
    Node* temp = head;  // ListNode* temp banaya jo ki head ko point kar rha hoga..filhaal
    
    // bol bacchan rule
    while (temp->next != NULL){
        temp = temp->next;
    }
    
    // now after the while loop i.e. now the control of program...
    // pointer temp has reached the last node
    temp->next = new_node;
    // new_node->next = NULL;  // No need to write since our constructor is smartly designed
}

void insertAtPosition(Node* &head, int data, int pos){
    // accha me chahta hu ki meri isi wali linked list me hi saare changes ho 
    // koi copy na bane isliye reference se bheja...#important
    Node* new_node = new Node(data);
    Node* temp = head;
    int current_pos = 0;
    

    // best practice to use here would be .. while (current_pos < pos - 1) 
    // if you want to reach say pos then your loop should have this condition coz when curr_pos == pos - 1
    // then this loop will break and after the loop break your control will be at pos

    while (current_pos != pos -1){  // ek pichli wali position tak hi jaenge..
        temp= temp->next;
        current_pos++;   
    }

    // kua paani rule
    // temp pointer is at pos-1
    new_node->next = temp->next;  // order is important else we can miss the access to our current node earlier...
    temp->next = new_node;
    // obviously pehle naye wale bande ko hi adjust hona hoga ussey hi haath badhana 
    // hoga pehle....
}

void deleteAtHead(Node* &head){
    Node* temp = head;  // poh(principle of homogenity)
    head = head->next;
    free(temp);     // efficiently saving memory....
}

void deleteAtTail(Node* &head){ // thoda sa indirectly hi hallal karke free karte hai...
    Node* temp = head;
    while(temp->next->next != NULL){ 
        temp= temp->next; 
    }

     // i.e. temp is at second last position
    Node* last = temp->next;    // save the last node
    temp->next = NULL;      // remove the last node
    free(last);         // free the memory of the last node
}   


void deleteAtPosition(Node* head, int pos){
    int curr_pos =0;
    Node* prev = head;

    while(curr_pos < pos-1){    // ekdum exact end mai aane se pehle ek baar just 
                                // thoda peeche ke cases dekh lena...
        curr_pos++;
        prev = prev->next;
    }

    // prev is pointing to node at pos-1
    Node* temp = prev->next;  // i.e. node to be deleted
    prev->next = prev->next->next;
    
    free(temp);
}

void display(Node* &head) {  // again -> while loop wala hi accha hota hai...
    // temp node banao jo ki iss bar head ko point kar rha ho, while loop laga ke saare node print karwao..
    Node* temp = head;
    while (temp!=NULL){ // matlab jab tak aakhri tak na pahuch jaye
        // jab temp-> next ka null hoga tab loop chalega and then andar ki line jab 
    // execute hongi then temp will point to NULL... so now the while loop condition is
    // violated and hence the loop breaks...

        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void displayRec(Node* head){ // O(n) space -> not better since there is call stack of O(n) and O(n) for making new variable

    if (head == NULL) return;   // base case
    cout<<head->data;           // kaam
    displayRec(head->next);     // fn call -> yaha har recursive call ke liye stack mai local variable ban raha hoga..
}

void displayRecRev(Node* head){ // O(n) space

    if (head == NULL) return;   // base case
    displayRecRev(head->next);  // fn call 
    cout<<head->data;       // aate waqt kaam
}




int main(){
    // start with empty linked list i.e. there will be no node and 
    // head pointer pointing to NULL;
    Node* head = NULL; // initial condition or base value..
    insertATHead(head, 3);
    display(head);
    insertATHead(head, 5);
    display(head);
    insertATHead(head, 9);
    display(head);

    insertAtTail(head, 10);
    display(head);
   
   insertAtPosition(head,83, 2);
   display(head);
   deleteAtHead(head);
   display(head);

   deleteAtTail(head);
   display(head);

   deleteAtPosition(head, 1);
   display(head);
}


// traversal in a singly linked list using head pointer
// head pointer is the pointer pointing to first node..
// basic functions implementation
// 1. display fn
// log to unordered_map bhi reference se maangte hai...
// to traverse or iterate over the ll we are using while loop




