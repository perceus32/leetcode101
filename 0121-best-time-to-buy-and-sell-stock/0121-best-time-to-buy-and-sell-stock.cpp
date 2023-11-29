class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=10000, maxp=0, current=0;
        while(current<prices.size()){
            if(prices[current]<min){
                min = prices[current];
            }
            if(prices[current]-min>maxp){
                maxp = prices[current]-min;
            }
            current++;
        }
        //APPROACH 2 - O(n^2) - TLE
        
        // for(int i=0; i<prices.size(); i++){
        //     for(int j=i+1; j<prices.size(); j++){
        //         profit = prices[j]-prices[i];
        //         if(profit<=0 || profit<maxp){
        //             continue;
        //         }else{
        //             if(profit>maxp){
        //                 maxp=profit;
        //             }
        //         }
        //     }
        // }
        return maxp;
    }
};