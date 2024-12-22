/*

Given an array of intervals intervals where intervals[i] = [starti, endi],
 return the minimum number of intervals you need to remove 
to make the rest of the intervals non-overlapping.


bool cmp(vector <int> &a, vector <int> &b){
    return a[1]<b[1];   // sort in asc order on basis of end time ...
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int ans = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime = intervals[0][1];  // initially value daali..
        for (int i=1; i<intervals.size(); i++){
            if (intervals[i][0] < lastEndTime){
                ans++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }   
        return ans; 
    }
};


*/

/*

agar do interval overlap kar rahe hai to...wo interval pick karo jo jaldi khatam ho raha hai..
lowest hanging apple algorithm pehle ussey hi tod lo...

*/