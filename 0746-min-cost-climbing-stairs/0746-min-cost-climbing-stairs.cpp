class Solution {
public:
    int minCost(vector<int> &cost, vector<int> &dp, int i){
        // if(i<0){return 0;}
        if(i==0 || i==1){return cost[i];}
        if(dp[i]!=0){return dp[i];}
        dp[i] = cost[i] + min(minCost(cost, dp, i-1), minCost(cost, dp, i-2));     //returns the cost to reach and proceed from ith step
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //APPROACH 1 - TC: O(n) ; SC:O(n)
        /*
        int n = cost.size();
        vector<int> dp(n, 0);

        dp[n-1] = cost[n-1]; 
        dp[n-2] = cost[n-2];

        for(int i = n-2; i>=0; i--){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
         return min(dp[0], dp[1]);
        */ 

         //APPROACH 2 - TC: O(2^n) SC: O(n)
         /*
         int n = cost.size();
         return min(minCost(cost, n-1), minCost(cost, n-2));           //objective is to reach n-1 or n-2 step
         */

         //APPROACH 3 - TC : O(n) ; SC : O(n)
         /*
         int n = cost.size();
         vector<int> dp(n, 0);
         return min(minCost(cost, dp, n-1), minCost(cost, dp, n-2));
         */

         //APPROACH 4 - TC: O(n) ; SC: O(n)
         /*
         int n = cost.size();
         vector<int> dp(n, 0);
         for(int i = 0; i<n; i++){
             if(i<2){ dp[i] = cost[i];}
             else{dp[i] = cost[i] + min(dp[i-1], dp[i-2]);}
         }
         return min(dp[n-1], dp[n-2]);
         */

         //APPROACH 5 : TC: O(n) ; SC: O(1)
        
         int n = cost.size();
         int first = cost[0];
         int second = cost[1];
         if(n==2){return min(first,second);}
         for(int i = 2; i<n; i++){
             int curr = cost[i] + min(first, second);
             first = second;
             second = curr;
         }
         return min(first, second);
         
    }
};