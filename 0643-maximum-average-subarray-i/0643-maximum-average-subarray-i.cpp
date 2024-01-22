class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -DBL_MAX, avg=0;
        int l=0, n=nums.size(), temp=0;

        while(temp<k){
            avg+=nums[temp];
            temp++;
        }

        res = avg;

        for(int i=1; i<=n-k; i++){
            avg-=nums[i-1];
            avg+=nums[i+k-1];
            res = max(res, avg);
        }
        // for(int i=0; i<=n-k; i++){
        //     temp = 0;
        //     avg = 0;
        //     while(temp<k){
        //         avg+=nums[i+temp];
        //         temp++;
        //     }
        //     avg/=k;
        //     cout<<avg<<endl;
        //     res = max(res, avg);
        // }
        return res/k;
    }
};