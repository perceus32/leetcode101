class Solution {
public:
    bool check(int l, int r, string &s){
        if(l>r){
            return true;
        }
        if(s[l]!=s[r]){
            return false;
        }
        return check(l+1, r-1, s);
    }
    bool isPalindrome(string s) {
        // for(int i=0; i<s.size(); i++){
        //     if(s[i]>=65 && s[i] <= 90){
        //         s[i]+=32;
        //     }
        // }
        for(int i=0; i<s.size(); i++){
            s[i]=tolower(s[i]);
        }
        int i=0;
        while(s[i]!='\0'){
            if(!iswalnum(s[i])){
                s.erase(s.begin()+i);
            }else{
                i++;
            }
        }
        cout<<s;
        int l=s.size();
        return check(0, l-1, s);
    }
};