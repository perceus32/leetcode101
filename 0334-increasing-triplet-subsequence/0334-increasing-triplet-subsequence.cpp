class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> mx(n, 1);
        // for(int i=n-2; i>=0; i--){
        //     for(int j=i+1; j<n; j++){
        //         if(nums[j]>nums[i]){
        //             mx[i]=max(1+mx[j], mx[i]);
        //         }
        //     }
        //     // cout<<i<<" "<<mx[i]<<endl;
        //     if(mx[i]>=3){return true;}
        // }
        // return false;



        //APPROACH 2
        // int n = nums.size();
        // int mini = nums[0], maxi = nums[n-1];
        // vector<pair<int, int>> minmax(n, {mini, maxi});
        // for(int i=0; i<n; i++){
        //     if(nums[i]<mini){
        //         mini = nums[i];
        //     }
        //     minmax[i].first = mini;
        //     //cout<<minmax[i].first<<" ";
        // }
        // //cout<<endl;
        // for(int i=n-1; i>=0; i--){
        //     if(nums[i]>maxi){
        //         maxi = nums[i];
        //     }
        //     minmax[i].second = maxi;
        //     //cout<<minmax[i].second<<" ";
        // }
        // for(int i=0; i<n; i++){
        //     if(minmax[i].first!=nums[i] && minmax[i].second!=nums[i]){
        //         return true;
        //     }
        // }
        // return false;


        //APPROACH 3
        int m1 = INT_MAX, m2 = INT_MAX;
        int n = nums.size();
        for(int i : nums){
            if(i<=m1){
                m1 = i;
            }else if(i<=m2){
                m2 = i;
            }else{
                return true;
            }
        }
        return false;
    }
};