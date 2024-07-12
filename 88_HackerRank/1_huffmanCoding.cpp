#include <iostream>
#include <vector>
using namespace std;
int main(){

}

void decode_huff(node * root, string s) {
    node* temp = root;
    
    for (char ch : s){
        if (ch == '0') temp = temp->left;
        else temp = temp->right;
        
        if (temp->left == NULL && temp->right == NULL){
            cout<<temp->data;
            temp = root;    // har bar apna character print karane ke baad next character ke liye dubara se temp ko root pe hi le jaake chodd diya....
        }
        
    }
}