
/*

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <pair <int, pair<int,int>>, vector<pair <int, pair<int,int>>>, greater<pair <int, pair<int,int>>> > pq;  // min heap syntax 

        for(int i=0; i<matrix.size(); i++){
            pq.push({matrix[i][0], {i,0}});
        }
        pair <int, pair <int,int> > ans;
        while (k-- and not pq.empty()){
            ans = pq.top();
            pq.pop();
            int val = ans.first;
            int row = ans.second.first;
            int col = ans.second.second;
            if (col + 1 < matrix[row].size()){
                pq.push({matrix[row][col+1], {row,col+1}});
            }
        }
        return ans.first;

        
    }
};


*/