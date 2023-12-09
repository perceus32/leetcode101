class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0, l=0, r;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){count++;}
            if(s[i]==')'){count--;}
            if(count==0){
                s.erase(s.begin()+l);
                r=i-1;
                s.erase(s.begin()+r);
                i-=2;
                l=i+1;
            }
        }
        return s;
    }
};