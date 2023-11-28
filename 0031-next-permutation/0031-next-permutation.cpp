class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = false;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
            for(int j=nums.size()-1; j>i; j--){
                if(nums[j]>nums[i]){
                    // cout<<nums[i];
                    // cout<<nums[j];
                    swap(nums[i], nums[j]);
                    flag = true;
                    break;
                }
            }
            }
            if(flag){
                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }
        if(!flag){
            sort(nums.begin(), nums.end());
        }
    }
};