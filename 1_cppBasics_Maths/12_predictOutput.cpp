#include <iostream>
using namespace std;

int main() {
    int a[]={5,6,7,8};
    cout << * (a + 2) << " " << a[1]; // 7 6 yes, how?/
    return 0;
}