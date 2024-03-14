#include <iostream>
using namespace std;

class Node{  // class ka naam hi node rakh diya
public:
    int data;
    Node* next;   // class ki help se bhi to hum user defined data type hi define karte hai
                // isliye jaise int* pointername -> Node* pointername

    // constructor
    Node(int data){     // return type (parameter)
        this->data = data;
        this->next = NULL;
    }
};

int main(){
    Node* node1 = new Node(10); // dynamically creating new node
    cout<< node1->data <<endl;
    cout<< node1->next <<endl;  
}


// class ka variable banaya to object. i.e. object is an instance of class
// acha scope resolution of data :: na use karke this (->) ka use karo
// this matlab is wali class ka ilaaka batata hai na wo
// linked list me dabake pointer ka use i.e. daba ke dynamic memory allocation...

/* tuf
array element stored in contiguous location while ll element is at random location in heap..
starting point of the linked list is called head of ll
->we use ll to implement stack or queue...
-> ll used in browser search also different page one after other...

ListNode* temp = new ListNode(1);   // automatically temp is pointer to the memory location...
always they say to return the starting node i.e. the head node...



*/
