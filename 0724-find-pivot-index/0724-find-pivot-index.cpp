class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0), leftSum=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            rightSum-=nums[i];
            //cout<<rightSum<<" "<<leftSum<<endl;
            if(leftSum==rightSum){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};