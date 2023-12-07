class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0, i=0, count=0;
        while(i<s.size()){
            if(s[i]=='('){count++;}
            if(s[i]==')'){count--;}
            if(count==-1){ans++;count++;}
            i++;
        }
        ans+=count;
        return ans;
    }
};