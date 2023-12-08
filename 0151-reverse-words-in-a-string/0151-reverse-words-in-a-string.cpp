class Solution {
public:
    string reverseWords(string s) {
        int start, end, i=s.size()-1;
        string ans = "";
        while(i>-1){
            while(i>-1 && s[i]==' ' ){i--;}
            end = i;
            while(i>-1 && iswalnum(s[i]) ){
                i--;
            }
            start = i+1;
            if(end>=0){
                ans+=s.substr(start, end-start+1);
                ans+=" ";
            }
        }
        ans.pop_back();
        return ans;
    }
};