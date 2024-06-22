class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        // for(int i=0; i<n; i++){
        //     if(nums[i]==0){       
        //         int ones = 0, zeros = 0;
        //         for(int j=i+1; j<n; j++){
        //             if(nums[j]==1){ones++;}
        //             else{zeros++;}
        //         }
        //         int k = i;
        //         if(ones>zeros){
        //             nums[k]=1-nums[k];
        //             count+=2;
        //         }else{
        //             while(k!=n){nums[k]=1-nums[k]; k++;}
        //             count++;
        //         }
        //     }
        // }
        for(int i=0; i<n; i++){
            if(count%2==0){
                if(nums[i]==0){
                    count++;
                }
            }else{
                if(nums[i]==1){
                    count++;
                }
            }
        }
        return count;
    }
};