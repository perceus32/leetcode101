class Solution {
public:
    static bool cmp(string l, string r){
        return l.size()<r.size();
    }
    string longestPalindrome(string s) {
        vector<string> ans;     //to store all the palindromes
        bool flag = false;
        int end; string res;
        if(s.size()==1){
            return s;
        }
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
                    if(!flag){
                        ans.push_back(s.substr(i, end-i+1));
                    }else{
                        l=i;
                        flag = false;
                        r = end-1;
                    }
                }
            }
        }
        //cout<<ans[0];
        sort(ans.begin(), ans.end(), cmp);
        if(ans.size()){res = ans[ans.size()-1];}
        else{res=s[0];}
        return res;
    }
};