class Solution {
public:
    void createSub(int index, vector<vector<int>> &res, vector<int> &sub, int n, vector<int> nums){
        if(index==n){res.push_back(sub); return;}
        sub.push_back(nums[index]);
        createSub(index+1, res, sub, n, nums);
        sub.pop_back();
        createSub(index+1, res, sub, n, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        createSub(0, res, sub, nums.size(), nums);
        return res;
    }
};