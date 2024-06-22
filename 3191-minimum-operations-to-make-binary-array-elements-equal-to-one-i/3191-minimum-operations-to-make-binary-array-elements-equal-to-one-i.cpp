class Solution {
private: 
    void printV(vector<int> &nums){
        for(auto i : nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n-2; i++){
            if(nums[i]==0){
                // printV(nums);
                count++;
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
            }
        }
        if(nums[n-1]==0 || nums[n-2]==0){
            return -1;
        }
        return count;
    }
};