#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;

    if (n == 0) {       // akash missed this point
        // Handle the case when n is 0
        cout << 1 << endl;
        return 0;
    }

    int x = 0;
    
    while (n > 0){
        n = n / 10;
        x++;
    }

    cout << x << endl;
    return 0;
}
