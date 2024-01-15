class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int i=0, fives=0, tens=0, n=bills.size();
        while(i<n){
            if(bills[i]==5){fives++; i++; continue;}
            if(bills[i]==10){
                if(fives>0){
                    fives--;
                    tens++;
                    i++;
                    continue;
                }else{
                    return false;
                }
            }
            if(bills[i]==20){
                if(tens>0 && fives>0){
                    fives--;
                    tens--;
                    i++;
                    continue;
                }else if(fives>2){
                    fives-=3;
                    i++;
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};