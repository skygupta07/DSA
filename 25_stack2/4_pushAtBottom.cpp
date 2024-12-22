#include <bits/stdc++.h>
using namespace std;

void print(stack <int> &s){
    stack <int> temp;
    while(s.size()>0){
        cout<<s.top()<<" "; // for printing 
        temp.push(s.top());
        s.pop();
    }
    while (temp.size()>0){
        s.push(temp.top());  // taki stack ke elements dubara usme daal saku..
        temp.pop();
    }
    cout<<endl;
}

void pushAtBottom(stack<int> &st, int n){

    stack <int> helper; // helper stack always helps 
    while (st.size()>0){
        helper.push(st.top());
        st.pop();  // st ko khali kiya...
    }
    // now st is empty just put the bottom most element in st and then push the elements back again..

    st.push(n);
    while(helper.size()>0){
        st.push(helper.top());
        helper.pop();
    }

    // print stack st element
    while(st.size()>0){
        cout<<st.top()<<" ";
        st.pop();
    }

}

void pushAtIdx(stack<int> &st, int idx, int n){
    stack <int> temp;
    while (st.size()>idx){
        temp.push(st.top());
        st.pop();
        
    }
    st.push(n);

    // pushing stack elements from temp into st back again...

    while (temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }


}

int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout<<st.size()<<endl;

    print(st);
    pushAtBottom(st, 19);

    pushAtIdx(st, 3, 15);
    print(st);


    


}

// dekh main fn me directly to saare code hamesha likhega nahi, matlab fn bana ke hi to karega 
// to simply fn me pass me reference hi kariyo i.e. & ki help se