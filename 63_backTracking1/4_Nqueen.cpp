#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > grid;     // to mark the queen state...
vector<vector <string> > result;

// we are placing queens row wise from top to bottom -> so we will check column attack, left and right diagonal attack..
bool canPlaceQueeen(int row , int col, int n){
    // column check --> usi column mai upar kahi queen nahi bethi honi chahiye...
    for (int i = row - 1; i>=0; i--){
        if (grid[i][col] == 'Q'){ // we are attacked
            return false;
        }
    }
    // left diagonal check
    for (int i=row-1 , j=col-1; i>=0 and j>=0; i-- , j--){ // dur dur tak left diagonal mai
                                                        // nahi honi chahiye queen
        if (grid[row][col]=='Q'){ // we are attacked
            return false;
        }
    }

    // right diagonal check
    for (int i = row-1, j = col+1 ; i>=0 and j<n; i-- , j++){ 
        // yes j<n  and j++ because will reach upper rightmost end..
        if (grid[i][j] == 'Q'){ // we are attacked
            return false;
        }
    }
    return true; // no attack found...
}

void f(int row, int n){ // starting row and no. of queens placed
    if (row == n){ // base case -> when you place the last queen in last row
        // we got one possible answer, print grid...
        vector <string> temp;
        for (int i = 0; i < n; i++){
            string res = "";
            for (int j = 0; j < n; j++){
                res += grid[i][j];
            }
            // grid mai row ko push kiya...
            temp.push_back(res);
        }
        // pure grid ko push kiya
        result.push_back(temp);     // 2d vector string mai...ek ek karke 1D string put ki..

    }


    for (int col=0; col<n; col++){
        if (canPlaceQueeen(row, col, n)){
            grid[row][col] = 'Q'; // work -> current row column par queen bithao....
            f(row + 1, n);      // fn call  -> chalo bhai chalo aage badho aur try karo..
            grid[row][col] = '.';   // revert back step(baktrack) 
        }
    }

}

vector<vector <string> > nqueen(int n){
    grid.clear();   // khakar v of v
    result.clear(); // khakar v of v
    grid.resize(n, vector<char> (n, '.'));

    // starting row and no. of queens to be placed
    f(0,n);
    return result;
}




int main(){
    nqueen(4);
    return 0;
}



/* evey row must have only one queen
we need to check only upper column and upper diagonal only...since started placing queen from upper row
dur dur tak puri left diagonal mai nahi hona chahiye wo queen...
agar koi dusri queen attack kar rahi hai to return false

initialis,ation ; cond,ition; incre,ment


*/





/* backtracking 2 aspects: 
1. prone the call that does not lead to a valid answer
2. If you change the state revert it as well...  */

// 3. backtracking me recursive call ke pehle kucch changes then fn call ke baad revert changes