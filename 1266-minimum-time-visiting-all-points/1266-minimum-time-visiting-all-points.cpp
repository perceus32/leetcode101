class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        if(points.size()==0){return 0;}
        for(int i=0; i<points.size()-1; i++){
            vector<int> first = points[i];
            vector<int> second = points[i+1];
            int xdiff = abs(first[0]-second[0]);
            int ydiff = abs(first[1]-second[1]);
            ans += min(xdiff, ydiff) + abs(xdiff-ydiff);
        }
        return ans;
    }
};