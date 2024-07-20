#include<iostream>
#include<vector>
using namespace std;

class Maxheap{
private:    // upheapify ko private rakha...
    // data members are kept private

    vector <int> hp;  // heap ko array/vector se represent karne ki trick..
    // if parent is at ith index then leftchild(lc) is at 2i+1 position..(zero based indexing)

    // member fn of the class Maxheap
    void upheapify(int ci){ // ci = child index // yaha pe 
    // chuki aap class bana rahe ho wo bhi bilkul hi alag tab to aap yaha member fns decalre 
    // kar lo...
        while(ci>0){
            int pi = (ci - 1)/2;
            if (hp[pi]<hp[ci]){
                swap(hp[pi],hp[ci]);
                ci = pi;    // for next iteration                
            }
            else break;
        }
    }
public:
    // member fns are kept public

    void push(int element){
        hp.push_back(element);  // vector me simply last me element push back kar diya then upheapify call kar diya
        upheapify(hp.size()-1);  // last element added index i.e. the last index  = arr.size()-1
    }

    int peek(){ // when we peek into the heap we see the topmost element i.e. the greatest element
        if (empty()) return INT_MIN;
        else return hp[0];
    }

    bool empty(){
        return hp.size()==0;
    }

    void display(){
        cout<<"[";
        for (int i=0; i<hp.size(); i++){
            cout<<hp[i]<<" ";
        }
        cout<<"]"<<endl;
    }

    void downheapify(int idx){
        while(idx<hp.size()){  //since repeatedly we need to do work
            int lc = 2*idx+1;
            int rc = 2*idx+2;
            if (lc>=hp.size()) break;   // it is possible ki heap me left child ho but
            // right child na ho isliye left child pe hi condition impose kari

            int maxElIdx = idx;   //initially assuming root(at idx index) to be max of three 
            if (hp[lc]>hp[maxElIdx]){
                maxElIdx = lc;
            }
            if (rc<hp.size() && hp[rc]>hp[maxElIdx]){   // jo bhi winner aaya ussey comparison hua..
                maxElIdx = rc;
            }
            if (maxElIdx != idx){ //means root node is not the maximum node
                swap(hp[idx],hp[maxElIdx]);
                idx=maxElIdx; //for next (iteration) IMP-> jisne bhi maxElIdx diya tha wahi
                // aage bhi paar lageyga...
            } 
            else break;  // if root node is the max node then break
        }   
        // left child right child aur current index mai se max nikal ke dekha agar wo
        // idx wala hi element nahi hai to swap kar diya...
    }

    void pop(){
        //this fn removes the highest priority element
        if (empty()) return;
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();  // vector ka first element to gayo..karan arjun
        if (!empty()){
            downheapify(0); // since culript node initially will be at the zeroth index
        }
    }
    
};

int main(){
    Maxheap hp;  // first line: classKaNaam objectName 
                    // creating an object for the class
    hp.push(200);   
    hp.push(100);
    hp.push(75);
    hp.push(15);    // member fn isliye dot operator ka use kiya..
    hp.push(10);
    hp.push(20);
    hp.push(50);
    hp.display();
    hp.pop();
    hp.display();  
// 200 100 75 15 10 20 50 
// 200 then 200 ka left child 100 then 200 ka right child 100 ....and so on...

    hp.pop();
    hp.display();

}

// to convert array to max heap simply sort the array in descending order
// agar kisi class mai koi constructor nahi likha to wo apne aap default constructor
// se samajh leta hai...
// jiska naam hi hai variable to wo to change hoga hi na...


/*
The ceiling (chhat) value of 3.1 is 4, and the floor value of 3.1 is 3.

Ceiling value (ceil): The smallest integer greater than or equal to 3.1, which is 4.
Floor value (jammen -> bydefault) (floor): The largest integer less than or equal to 3.1, which is 3.


*/