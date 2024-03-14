#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v1(5);  // 5 size ka vector ban gya jisme ki bydefault saare element zero honge.
    cout<<v1.size()<<endl;
    cout<<v1[2]<<endl;

    vector <int> v2(7,6);  // 7 size ka vector ban gya jisme ki har element 6 hai..
    cout<<v2[4];    
    cout<<endl;
    
    vector <int> v3(19,-1);  
    for (int i=0; i<v3.size(); i++){
        cout<<v3[i]<<" ";
    } 
    cout<<endl;
}
