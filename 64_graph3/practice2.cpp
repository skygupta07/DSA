#include <iostream>
using namespace std;

// implementing linked list

class Node{
    public:
    int data;
    Node* next;

    // obviously class ka constructor to class ke andar hi banega...
    // aur ha as a base case ke similar single node to banani hogi jisme ki uska data aur next pointer hoga..
    Node(int d){ // constructor
        this->data = d;
        this->next = NULL;
    }
};

    // ab linked list me hum various fns execute kar sakte hai unko one by one likhte hai...
    void insertAtHead(Node* &head , int data){
        // yaha par reference isliye liya hai taki original linked list me changes aae, instead ki copy ban jae..
        Node* temp = new Node(data); // arey koi data dalna hai,, theek hai but aise hi thodi daal doge pehle node create karoge then put data..
        // aisa karne se ek nayi Node ban gayi temp naam se
        // Node ki class ka pointer declare kiya hai to ye to confirm hai ki usme data aur next pointer bydefault honge hi.. 

        temp->next = head;
        head = temp;
    }

    void insertAtTail(Node* &tail , int data){     
    }

    void print(Node* &head){
        Node* temp = head;
        while (temp!=NULL){
                // cout<<temp->data<<endl;
            temp = temp->next;
        }
    }





int main(){
    // dynamic memory allocation ke karan yaha hum pointers wala use karenge
    Node* Node1 = new Node(6); // creation of new node pointer whose name is Node1
    cout<<Node1->data<<endl;
    cout<<Node1->next<<endl;

    Node* head = Node1;
    // head ko Node1 pe point kiya
    print(head);
    insertAtHead(head, 9);
    print(head);

}





// class constructor par khatam ho jaati hai...