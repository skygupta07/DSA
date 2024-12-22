
int solve(int row, int col, int n, vector<vector<int>>& points){
    if(row >= points.size()) return 0;

    int opt1 = -1;
    int opt2 = -1;
    int opt3 = -1;
    if(col != 0) opt1 = points[row][0] + solve(row+1, 0, n, points);
    if(col != 1) opt2 = points[row][1] + solve(row+1, 1, n, points);
    if(col != 2) opt3 = points[row][2] + solve(row+1, 2, n, points);
    
    return max(opt1, max(opt2, opt3));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{

    return solve(0, -1, n, points);
}

Ye sahi chal rha hai




int dp[100001][3];


int solve(int row, int col, int n, vector<vector<int>>& points){
    if(row >= points.size()) return 0;
    if(dp[row][col] != -1) return dp[row][col];
     
    int opt1 = -1;
    int opt2 = -1;
    int opt3 = -1;
    if(col != 0) opt1 = points[row][0] + solve(row+1, 0, n, points);
    if(col != 1) opt2 = points[row][1] + solve(row+1, 1, n, points);
    if(col != 2) opt3 = points[row][2] + solve(row+1, 2, n, points);
    
    return dp[row][col] = max(opt1, max(opt2, opt3));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    for(int i = 0; i <= 100001; i++){
        for(int j = 0; j <= 3; j++){
            dp[i][j] = -1;
        }
    }
    return solve(0, -1, n, points);
}