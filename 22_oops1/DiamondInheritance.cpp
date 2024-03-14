#include <iostream>
using namespace std;

class parent{
public:
    parent(){  // constructor
        cout<<"parent class"<<endl;
    }
};

class child: public parent{
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

// base class has multiple parent classes having a common ancestor class...
// note: always follow camel case