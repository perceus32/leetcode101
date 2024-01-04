class Solution {
public:
    int findComplement(int num) {
        long long base = pow(2, (long long)(log(num)/log(2))+1);
        //cout<<base;
        return base-1-num;
    }
};