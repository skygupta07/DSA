#include <iostream>
#include <vector>
using namespace std;
int main(){

}
qq
string timeConversion(string s) {
    // 18:45:34PM
    // 0123456789
    
    // mainly hour and period pe hi depend karega...
    string period = s.substr(8,2);
    int hour = stoi(s.substr(0,2));
    string minutes = s.substr(3,2);
    string seconds = s.substr(6,2);
    
    if (period == "AM"){
        if (hour == 12){
            hour = 0;
        }
    }
    
    else if (period == "PM"){
        if (hour != 12){
            hour = hour + 12;
        }
    }
    
    stringstream ss;
    ss<<setw(2)<<setfill('0')<<hour<<":"<<minutes<<":"<<seconds;
    return ss.str();
 
}
