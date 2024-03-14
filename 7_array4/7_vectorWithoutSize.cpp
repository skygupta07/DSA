#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int> v;
    cout<<v[0]<<endl;
}

// will give segmentation fault if you initilased the vector without size and have not
// pushed any element even and trying to access any index ...