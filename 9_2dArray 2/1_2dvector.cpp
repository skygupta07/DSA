#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector < vector <int> > v(3, vector<int> (4,5));  // ek 2d vector bana do with name v jisme 3 row hongi
                                                    // aur 4 column honge...  
                                                    // aur har element ki value 5 hogi  
    
    cout<<v[2][3]<<endl;

    vector < vector <int> > v2(2, vector <int> (3,9));
    // data type of v2 just like int then varible name then 

    cout<<v2[1][2]<<endl;


}