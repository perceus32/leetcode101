class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> l;
        for(int i=0; i<s.size(); i++){
            if(!m.count(s[i]) && !l.count(t[i])){
                m.insert(make_pair(s[i], t[i]));
                l.insert(t[i]);
            }else{
                if(m[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};