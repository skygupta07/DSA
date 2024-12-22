#include <iostream>
using namespace std;

class parent{
public:
    parent(){  // constructor
        cout<<"parent class"<<endl;
    }
};

class child: public parent{ // class child : (jo ki  inherit kar raha hai) publicly parent class ko
public:

    child(){
        cout<<"child class"<<endl;
    }

};

class grandChild: public child{
public:
    grandChild(){  // grandChild ka constructor
        cout<<"grandchild class "<<endl;
    }
};

int main(){
    grandChild g1;

}


// ab jab bhi grandchild ko call lagegi to 
        //    parent -> child -> grandchild wala function invoke hoga...
// base class has multiple parent classes having a common ancestor class...
// note: always follow camel case