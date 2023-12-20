class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int counter = 2;
        sort(prices.begin(), prices.end());
        while(counter){
            money-=prices[2-counter];
            counter--;
        }
        if(money<0){
            money+=prices[0]+prices[1];
        }

        // int smallest = 101, secondSmallest = 101;
        // for(int i=0; i<prices.size(); i++){
        //     if(prices[i]<smallest){
        //         secondSmallest = smallest;
        //         smallest = prices[i];
        //     }else if(prices[i]<secondSmallest){
        //         secondSmallest = prices[i];
        //     }
        // }
        // int ans = smallest+secondSmallest;
        // if(ans<money || ans==money){
        //     money-=ans;
        // }
        return money;
    }
};