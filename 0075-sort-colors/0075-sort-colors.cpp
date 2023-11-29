class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> zero, one, two;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                zero.push_back(0);
            }else if(nums[i]==1){
                one.push_back(1);
            }else if(nums[i]==2){
                two.push_back(2);
            }
        }
        nums.clear();
        nums.insert(nums.end(), zero.begin(), zero.end());
        nums.insert(nums.end(), one.begin(), one.end());
        nums.insert(nums.end(), two.begin(), two.end());
    }
};