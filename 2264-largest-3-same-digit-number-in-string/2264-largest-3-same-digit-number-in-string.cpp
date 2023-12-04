class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int l, r, temp = -1, ind;
        for(int i=0; i<num.size()-2; i++){
            l = num[i];
            r = num[i+1];
            if(l==r){
                r = num[i+2];
                if(l==r){
                    temp = max(temp, l-'0');
                }
            }
        }
        ans = temp==-1?"":string(3, '0' + temp);
        return ans;
    }
};