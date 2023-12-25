class Solution {
public:
    bool isAnagram(string s, string t) {
        // APPROACH 1
        /*
        if(s.size()!=t.size()){return false;}
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        // for(int i=0; i<s.size(); i++){
        //     if(s[i]!=t[i]){
        //         return false;
        //     }
        // }
        // return true;
        return s==t;
        */

        //APPROACH 2
        if(s.size()!=t.size()){return false;}
        unordered_map<char, int> freq;
        for(char ch : s){
            freq[ch] += 1;
        }
        for(char ch : t){
            if(freq.find(ch)==freq.end() || freq[ch]==0){
                return false;
            }
            freq[ch]--;
        }
        return true;
    }
};