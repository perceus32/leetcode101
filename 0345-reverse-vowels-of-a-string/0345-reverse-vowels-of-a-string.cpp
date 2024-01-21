class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> hash = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}, {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}};
        int n = s.size();
        int l = 0, r = n-1;
        while(l<r){
            while(l<r && hash[s[l]]==0){l++;}
            while(l<r && hash[s[r]]==0){r--;}
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};