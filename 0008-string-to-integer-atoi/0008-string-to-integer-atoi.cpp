class Solution {
public:
    int myAtoi(string s) {
        int index=0;
        double ans = 0;
        bool sign = false;  //false = positive
        while(!iswalnum(s[index])){
            // if(s[index]==' '){s.erase(s.begin()+index);}
            // else if(s[index]=='+'){s.erase(s.begin()+index);}
            // else if(s[index]=='-'){sign=true;s.erase(s.begin()+index);}
            // else{index++;}
            if(s[index]==' '){index++;}
            else if(s[index]=='+'){index++;break;}
            else if(s[index]=='-'){sign=true;index++;break;}
            else if(!isdigit(s[index])){return (int)ans;}
        }
        while(isdigit(s[index]) && s[index]!='\0'){
            ans*=10;
            ans+=s[index]-'0';
            index++;
        }
        if(sign){ans*=-1;}
        if(ans<=INT_MIN){ans=INT_MIN;}
        if(ans>=INT_MAX){ans=INT_MAX;}
        return (int)ans;
    }
};