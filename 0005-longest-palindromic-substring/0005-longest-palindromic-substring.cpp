class Solution {
public:
    string longestPalindrome(string s) {
        bool flag = false;
        int end, max = 1, imax = 0;
        for(int i=0; i<s.size(); i++){
            int l=i, r = s.size()-1;
            while(l<r){
                if(s[l]!=s[r]){
                    r--;
                }else{
                    end = r;
                    while(l<r){
                        l++;
                        r--;
                        if(s[l]!=s[r]){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag && end-i+1>max){
                        max = end-i+1;
                        imax = i;
                    }else{
                        //reset condition if not palindrome
                        l=i;
                        flag = false;
                        r = end-1;
                    }
                }
            }
        }
        return s.substr(imax, max);
    }
};