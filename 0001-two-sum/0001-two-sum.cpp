class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //SC: O(N)
        //TC: O(N)
        unordered_map<int, int> hash;
        vector<int> ans(2, 0);
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(hash.find(diff)!=hash.end()){
                ans[0] = i;
                ans[1] = hash[diff];
                return ans;
            }
            hash[nums[i]] = i;
        }
        return ans;
    }
};