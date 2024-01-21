class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<pair<int, int>> mul(n, {1, 1});
        // vector<int> res;
        // int left = 1, right = 1;
        // for(int i=1; i<n; i++){
        //     left*=nums[i-1];
        //     mul[i].first = left;
        // }
        // for(int i=n-2; i>=0; i--){
        //     right*=nums[i+1];
        //     mul[i].second = right;
        // }
        // for(int i=0; i<n; i++){
        //     res.push_back(mul[i].first*mul[i].second);
        // }
        // return res;
        int n = nums.size();
        vector<int> res;
        int left = 1, right = 1;
        for(int i=0; i<n; i++){
            if(i==0){res.push_back(left);}
            else{
                left*=nums[i-1];
                res.push_back(left);
            }
        }
        for(int i=n-1; i>=0; i--){
            if(i==n-1){res[i]*=right;}
            else{
                right*=nums[i+1];
                res[i]*=right;
            }
        }
        return res;
    }
};