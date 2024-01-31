class Solution {
public:
    int trap(vector<int>& height) {
        //  BRUTE FORCE
        // int n = height.size();
        // int leftmax=0, rightmax=0;
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     int j=i; 
        //     while(j>=0){
        //         leftmax = max(leftmax, height[j]);
        //         j--;
        //     }
        //     j=i;
        //     while(j<n){
        //         rightmax = max(rightmax, height[j]);
        //         j++;
        //     }
        //     ans += min(leftmax, rightmax) - height[i];
        //     leftmax=0; rightmax=0;
        // }
        // return ans;


        //  PREFIX SUM
        // int n = height.size(), ans=0;
        // vector<int> prefix(n, 0), suffix(n, 0);
        // prefix[0] = height[0]; suffix[n-1] = height[n-1];
        // for(int i=1; i<n; i++){
        //     prefix[i] = max(prefix[i-1], height[i]);
        // }
        // for(int i=n-2; i>=0; i--){
        //     suffix[i] = max(suffix[i+1], height[i]);
        // }
        // for(int i=0; i<n; i++){
        //     ans += (min(prefix[i], suffix[i]) - height[i]);
        // }
        // return ans;

        //TWO POINTER
        int n = height.size();
        int l=0, r=n-1, leftmax=0, rightmax=0, ans = 0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>leftmax){
                    leftmax = height[l];
                }else{
                    ans += leftmax-height[l];
                }
                l++;
            }else{
                if(height[r]>=rightmax){
                    rightmax = height[r];
                }else{
                    ans += rightmax-height[r];
                }
                r--;
            }
        }
        return ans;
    }
};