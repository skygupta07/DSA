//generate all binary strings of length n without consecutive 1's
// binary strings matlab zero one waali string...
#include <iostream>
using namespace std;

void generate(string s, int n){
    if (n==0){  // base case 
        cout<<s<<endl;
        return;
    }
    generate(s+'0' , n-1);  // zero wali string to hamesa generate karni hai...
    if (s==""){
        generate(s+'1',n-1);   // one wali string tab generate karni hogi jab ya to 
                            // string pehle se khaali ho ya phir just uske pehle wala 
                            // element zero ho...so that no there is no two consecutive 1

    }
    if (s[s.length()-1]=='0') generate (s+'1' , n-1);   
}



int main(){
    int n = 4;
    generate("",n);
}

// better option will be that you don't generate those strings.....



























// -------- --------      --------------        ----------


// //generate all binary strings of length n without consecutive 1's

// #include <iostream>
// #include <string>
// using namespace std;


// string consecutiveStr(string input, string output){
    
//     for (int i=0; i<input.length(); i++){
       
//         if (i==0){
//             output[i] = input[i];
//         }
//         else if (input[i-1]!= '1' && input[i]=='0'){
//             output[i] = input[i];
//         }
//         else if (input[i-1]!= '1' && input[i] == '1'){
//             output[i] = input[i];
//         }
//     }
    
//     return output;
// }


// int main(){
//     string s = "10110110101011100010";
//     cout<< consecutiveStr(s," ");
//     return 0;
// }
