#include<iostream>
#include<vector>
using namespace std;

class Maxheap{
public:

    vector <int> hp;  // heap ko array/vector se represent karne ki trick..
    // if parent is at ith index then leftchild(lc) is at 2i+1 position..(zero based indexing)
    //mental model me heap ka rakho but implement to array ya vector se hi hoga
    // hum array array bolte hai but implement to vector se hi karte hai at the end..

    void upheapify(int ci){ // ci = child index
        while(ci>0){

            int pi = (ci - 1)/2;

            if (hp[pi] < hp[ci]){
                swap(hp[pi],hp[ci]);
                ci = pi;    // for next iteration-> imp to update child index
            }

            else break; // kyuki agar pehle hi stage mai koi changes nahi ho rahe hai 
            // to baad mai bhi nahi honge...
        }

    }

    void push(int element){
        hp.push_back(element);
        upheapify(hp.size()-1);  // last element added index i.e. the last index..culprit. 
        // obviously wo push_back hoke bhi last mai hi add hua hoga...
    }

    int peek(){ // when we peek into the heap we see the topmost element i.e. the greatest element
        if (empty()) return INT_MIN;  
        else return hp[0];
    }

    bool empty(){
        return (hp.size()==0);  // if hp.size()== 0 will be true then it will return true
    }

    void display(){
        cout<<"[";
        for (int i=0; i<hp.size(); i++){
            cout<<hp[i]<<" ";
        }
        cout<<"]"<<endl;
    }

    void downheapify(int idx){

        while(idx < hp.size()){

            int lc = 2*idx+1;
            int rc = 2*idx+2;

            // kyuki aisa ho sakta hai ki left child ho magar right child na ho..
            if (lc >= hp.size()) break;

            int maxEl = idx;
            if (hp[lc] > hp[maxEl]){
                maxEl = lc; // maxElementIdx   === maxEl
            }

            if (rc < hp.size() && hp[rc] > hp[maxEl]){
                maxEl = rc;
            }

            if (maxEl != idx){ //means root node is not the maximum node
                swap(hp[idx], hp[maxEl]);
                idx=maxEl; //for next iteration
            }

            else break;
        }
    }

    void pop(){
        //removes the highest priority element
        if (empty()) return;

        swap( hp[0] , hp[hp.size()-1] );    // pehle swap to karo

        hp.pop_back(); // imp

        if (!empty()){
            downheapify(0); //since sabse upar hi hoga wo added element ab ussey 
            // uski correct position tak downheapify karo...
        }

    }

    // Maxheap(vector<int> v){ //constructor    // method1
    //     hp=v;
    //     for (int i=1; i<hp.size(); i++){  //here T.c. =  O(nlogn)
    //         upheapify(i);
    //     }
    // }

    Maxheap(vector <int> &v){ //constructor -> vector input lega aur maxheap tayar karke de dega..
        hp=v;       //imp -> meri fn ki definition wale vector se to equate karega hi na..                
        
        int n = hp.size();
        
        for (int i=n/2; i>=0; i--){ 
            downheapify(i);
        }   // t.c. = O(n)  // heap banana hi efficient kar diya ...
    
    }

    // agar constructor mai koi member fn use ho raha hai to phir aap constructor ko 
    // baad mai hi likh lena...

    // ways to create a maxheap-> 1. push element one by one and call upheapify fn for them simultaneously
    // 2. take vector as input, iterate over each element and upheapify it  // O(nlogn) 
    //  each element takes logn and in worst case all n elements needed to upheapify
    // 3. take vector as input, but call the downheapify fn for nodes other than leaf nodes(population dominant species) 
    // yaani ki upar waale nodes ko neeche le aao wo jyada better option hai..
    
};


int main(){

    int arr[]={9,6,1,19,3,2,8,12,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    vector<int>v(arr,arr+n);  //copying array to vector..
    
    Maxheap hp(v);  
    hp.display();  // member fn hai isliye dot operator used...
    hp.push(10);
    hp.display();

}

// convert array to heap but don't create/use a new array for this..
// method1 -> at any point of time maintain a region of the array which is a valid heap
// [0,i]

/*

hala ki saari data structures lagbhag apne stl dete hai but unki deep understanding ke liye
hum log uske working pattern ko analyse karke uski user defined class likhte hai....

-> all sorted array(desc) will be a max heap but all max heap will not be a sorted array...

*/