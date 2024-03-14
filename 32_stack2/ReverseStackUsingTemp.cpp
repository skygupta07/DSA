#include<iostream>
#include<stack>
 // push(), pop(),top(),size(), empty() SEEPPT
using namespace std;


int main(){
    stack <int> st; // using inbuilt stack
    cout<<st.empty()<<endl;
    // st.pop();  // dekh yha tera stack khali hai but tu tab bhi pop karna chah rha hai
            // matlab ab iss case me to segmentation fault aaega hi...
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.size()<<endl;
    st.pop();
    st.push(5);
    st.push(6);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;

    // printing stack elements in reverse order (matlab jo late daala ussey pehle nikalenge...)
    // cout<<"elements of stacks are: ";
    // while(st.size()>0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;
    // OMG, but stack ke saath ke element pop karte karte to aapne puri original stack hi khali kar di
    // aisa karo ek aur stack banao aur usme element ko saath hi saath push bhi karte chalo...


    stack <int> temp;
    cout<<"elements of stacks are: ";
    while(st.size()>0){
        cout<<st.top()<<" ";
        temp.push(st.top()); //temp stack me element ko push kardo
        st.pop();
    }
    cout<<endl;

    // putting elements back from temp to st...
    cout<<"elements of stacks in order are: ";
    while (temp.size()>0){  //1.
        st.push(temp.top()); //2.
        temp.pop();  // ab temp stack ko khali karte chalo...   //3.     
        // printing elements of stacks by help of st        
        cout<<st.top()<<" ";
    }
    cout<<endl;
}


// stack ka size unlimited..