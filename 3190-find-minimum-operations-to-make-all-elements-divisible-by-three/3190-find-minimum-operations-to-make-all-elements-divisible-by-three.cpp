class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for(auto i : nums){
            if(i%3==1 || i%3==2){
                res++;
            }
        }
        return res;
    }
};