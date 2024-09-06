class Solution {
public:
    vector <int> v; // to store groups
    int parent (int x){
        if (v[x] == -1) return x;
        return v[x] = parent(v[x]);
    }

    void Union(int a, int b){
        int pa = parent(a);
        int pb = parent(b);
        if (pa == pb) return;
        v[pa] = pb; // imp
    }



    int findCircleNum(vector<vector<int>>& M){
        int n = M.size();   // M-> matrix
        v = vector<int> (n,-1);   // initially assuming all to be self leader
            // good method to declare the vector globally and modifying it in the function...
        // form group of friends...
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (M[i][j]) Union(i,j);    // since 0 1 possible so M[i][j] > 0 will give 1..
            }
        }

        int count = 0;
        for (int i=0; i<n; i++){
            if (v[i] == -1) count++;
        }
        return count;
    }
};



/*
connected components problem based...
m1 ->using dsu finding number of connected compeonents: number of leader nodes is number of provinces.
dsu mai union find/parent function hi likhna hota hai mainly....

dsu mai index vector reprsentig the actual elements and values vector representing its parent...
if parent is -1 then the element is leader of that group...




m2 -> creating graph from the adjacency matrix then applying bfs ...number of different bfs is number of provinces
available....

*/


class Solution {
public:

    void dfs(vector <list<int> > &adj, vector<bool> &visited, int currNode){
       visited[currNode] = true;

       for (int neighbor : adj[currNode]){
            if (!visited[neighbor]){
                dfs(adj, visited, neighbor);
            }
       }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int rows = isConnected.size();
        int cols = isConnected[0].size();

        vector <bool> visited(rows, false);

        vector <list <int> > adj(rows);

        // creating graph..
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (isConnected[i][j] == 1){
                    // i se j ki taraf edge lagao...
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        // agar wo vertex abhi tak visited nahi hai to waha se dfs call karo....
        for (int i=0; i<rows; i++){
            if (!visited[i]){
                count++;
                dfs(adj, visited, i);
            }
        }

        return count;  
    }
};

/*
number of connected components 

create graph ... initiate dfs the number of times ...dfs is called will be ans.



*/


--------

class Solution {
public:

    void dfs( vector<vector<int> >& isConnected, vector <bool> &visited, int count, int i){
        visited[i] = true; // ye koi kaise bhul sakta hai..
        for (int j=0; j<isConnected[0].size(); j++){
            if (isConnected[i][j] == 1 && !visited[j]){
                dfs(isConnected, visited, count, j);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int rows = isConnected.size();
        int cols = isConnected[0].size();


        vector <bool> visited(rows, false);

        int count = 0;
        for (int i=0; i<rows; i++){
            if (!visited[i]){
                count++;
                dfs(isConnected, visited, count, i);
            }
        }

        return count;
    }
};


/*
without creating the adj graph ..isConnected wale se bhi to ho sakta hi hai...



*/

