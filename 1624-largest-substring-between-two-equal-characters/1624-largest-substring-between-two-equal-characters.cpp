class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        unordered_map<char, pair<int, int>> hash;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(hash.find(c)!=hash.end()){
                hash[c].second = i;
            }else{
                hash[c].first = i;
            }
        }
        for(auto i : hash){
            int diff = i.second.second - i.second.first - 1;
            ans = max(ans, diff);
        }
        return ans;
    }
};