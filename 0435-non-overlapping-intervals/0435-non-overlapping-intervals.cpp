class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int ans = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i-1][1]<=intervals[i][0]){continue;}
            if(intervals[i-1][1]>intervals[i][0]){
                ans++;
                if(intervals[i-1][1]>intervals[i][1]){
                    continue;
                }else{
                    intervals[i][1]=intervals[i-1][1];
                }
            }
        }
        return ans;
    }
};