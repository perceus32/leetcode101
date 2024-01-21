class Solution {
private:
    // static bool cmp(string a, string b){
    //     return a.size()<b.size();
    // }
    bool checkIfPrefix(string s, string prefix){
        int n = prefix.size();
        int i;
        for(i=0; i<s.size(); i+=n){
            if(s.substr(i, n)!=prefix){
                return false;
            }
        }
        //cout<<i<<endl;
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        // vector<string> strings = {str1, str2};
        // sort(strings.begin(), strings.end(), cmp);
        // string s1 = strings[0];   
        // string s2 = strings[1];
        // int i=s1.size()-1;
        // string prefix = s1;
        // while(i>=0){
        //     cout<<prefix<<endl;
        //     if(checkIfPrefix(s2, prefix) && checkIfPrefix(s1, prefix)){   
        //         return prefix;
        //     }
        //     prefix.erase(prefix.size()-1);
        //     i--;
        // }
        // return "";
         //return (str1+str2==str2+str1)?str1.substr(0, gcd(str1.size(), str2.size())):"";
         string gcd = str1.length()<str2.length()?str1:str2;
         while(true){
            if(checkIfPrefix(str1, gcd) && checkIfPrefix(str2, gcd)){
                return gcd; 
            }
            gcd.pop_back();
            if(gcd.length()==0){return "";}
         }
         return "";
    }
};