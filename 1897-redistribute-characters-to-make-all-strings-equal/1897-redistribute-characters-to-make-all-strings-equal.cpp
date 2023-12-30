class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //TC: O(n*m + m)    //n strings * m distinct letters in each string
        //SC: O(m)          //m distinct letters in a string
        unordered_map<char, int> counter;
        int n = words.size();
        if(n==1){return true;}
        for(auto i : words){
            for(auto c : i){
                counter[c]++;
            }
        }
        for(auto i : counter){
            if(i.second%n!=0){
                // cout<<i.second<<endl<<i.first;
                return false;
            }
        }
        return true;
    }
};