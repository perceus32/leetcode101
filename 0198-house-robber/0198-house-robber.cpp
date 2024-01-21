class Solution {
    // private: 
    // int rob(vector<int> &nums, int i, vector<int> &dp){
    //     if(i<0){return 0;}
    //     if(dp[i]!=-1){return dp[i];}
    //     dp[i] = max(nums[i]+rob(nums, i-2, dp), rob(nums, i-1, dp));
    //     return dp[i];
    // }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if(n==1){return nums[0];}
        dp[0] = nums[0]; 
        dp[1] = nums[1];
        if(n==2){return max(dp[1], dp[0]);}
        dp[2] = nums[2] + dp[0];
        for(int i=3; i<n; i++){
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }
        return max(dp[n-1], dp[n-2]);

        // int n = nums.size();
        // int first = 0, second = nums[0], third = second; 
        // // vector<int> dp(n+1, -1);
        // // dp[0] = 0; dp[1] = nums[0]; 
        // for(int i=2; i<=n; i++){
        //     // dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        //     third = max(first + nums[i-1], second);
        //     first = second;
        //     second = third;
        // }
        // return third;
    }
};