class Solution {
private: 
    vector<int> findMinimum(vector<int> &nums){
        int n = nums.size();
        stack<int> sl, sr;
        vector<int> l(n), r(n);
        for(int i=0; i<n; i++){
            while(!sl.empty() && nums[sl.top()]>=nums[i]){
                sl.pop();
            }
            l[i] = sl.empty()?i+1:i-sl.top();
            sl.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!sr.empty() && nums[sr.top()]>nums[i]){
                sr.pop();
            }
            r[i] = sr.empty()?n-i:sr.top()-i;
            sr.push(i);
        }
        for(int i=0; i<n; i++){
            l[i] *= r[i];
        }
        return l;
    }
    vector<int> findMaximum(vector<int> &nums){
        int n = nums.size();
        stack<int> sl, sr;
        vector<int> l(n), r(n);
        for(int i=0; i<n; i++){
            while(!sl.empty() && nums[sl.top()]<=nums[i]){
                sl.pop();
            }
            l[i] = sl.empty()?i+1:i-sl.top();
            sl.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!sr.empty() && nums[sr.top()]<nums[i]){
                sr.pop();
            }
            r[i] = sr.empty()?n-i:sr.top()-i;
            sr.push(i);
        }
        for(int i=0; i<n; i++){
            l[i] *= r[i];
        }
        return l;
    }
    void printV(vector<int> nums){
        int n = nums.size();
        for(int i=0; i<n; i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        vector<int> mini = findMinimum(nums);
        vector<int> maxi = findMaximum(nums);
        // printV(mini);
        // printV(maxi);
        for(int i= 0; i<n; i++){
            res = res + (long)(maxi[i] - mini[i])*nums[i];
        }
        return res;
    }
};