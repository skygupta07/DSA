#include<iostream>
#include<stack>
 
using namespace std;

void print(stack <int> s){
    stack <int> temp;
    while(s.size()>0){
        cout<<s.top()<<" ";
        temp.push(s.top());
        s.pop();
    }
    while (temp.size()>0){
        s.push(temp.top());  // taki stack ke elements dubara usme daal saku..
        temp.top();
    }
    cout<<endl;
}

int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);  
    st.push(5);
    st.push(6);

    // reversing stack st element using two extra stacks gt and rt
    // steps: empty st into gt...  empty gt into rt... empty rt into st again...
    // now st elements would have been reversed..
    stack <int> gt;
    stack <int> rt;

   // empty st into gt... 
    while (st.size()>0){
        gt.push(st.top());
        st.pop();
    }

    // empty gt into rt... 
    while (gt.size()>0){
        rt.push(gt.top());
        gt.pop();
    }
    // empty st into gt... 
    while (rt.size()>0){
        st.push(rt.top());
        rt.pop();
    }

    print(st);


}



