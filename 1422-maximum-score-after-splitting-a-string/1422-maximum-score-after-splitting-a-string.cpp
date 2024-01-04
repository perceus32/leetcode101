class Solution {
public:
    int maxScore(string s) {
        int maxs = 0;
        int right = count(s.begin(), s.end(), '1');
        int left = 0;

        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='0'){left++;}
            if(s[i]=='1'){right--;}
            maxs = max(maxs, left+right);
        }

        return maxs;
    }
};