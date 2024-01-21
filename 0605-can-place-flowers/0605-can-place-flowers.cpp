class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num = flowerbed.size();
        if(n==0) return true;
        if(num==1){
            if(flowerbed[0]==0) return true;
            else if(flowerbed[0]==1 && n==0) return true;
            else return false;
        }
        if(num==2){
            if((flowerbed[0]|flowerbed[1])==1){
                if(n==0) return true;
                else return false;
            }else{
                if(n==2) return false;
                else return true;
            }
        }
        if(num>=3){
            if(flowerbed[0]==0 && flowerbed[1]==0){
                n--;
                flowerbed[0]=1;
            }
            if(n==0) return true;
            if(flowerbed[num-1]==0 && flowerbed[num-2]==0){
                n--;
                flowerbed[num-1]=1;
            }
            if(n==0) return true;
        }
        for(int i=1; i<num-1; i++){
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]!=1){
                n--;
                flowerbed[i]=1;
            } 
            if(n==0){return true;}
        }
        return false;
    }
};