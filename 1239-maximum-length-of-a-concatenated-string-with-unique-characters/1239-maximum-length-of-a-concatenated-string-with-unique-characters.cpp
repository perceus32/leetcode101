class Solution {
private:
    // int findHash(vector<string> &s){
    //     unordered_map<char, int> freq;
    //     int count = 0;
    //     for(auto i : s){
    //         for(auto c : i){
    //             freq[c]++;
    //             if(freq[c]>1){
    //                 return 0;
    //             }
    //             count++;
    //         }
    //     }
    //     return count;
    // }
    // void printV(vector<string> &v){
    //     int n = v.size();
    //     for(auto i : v){
    //         cout<<i;
    //     }
    //     // cout<<endl;
    // }
    // void findSubsets(vector<string> &arr, int ind, int n, vector<string> &s, int &count){
    //     if(ind==n){
    //         //printV(s);
    //         if(findHash(s)){
    //             // printV(s);
    //             //cout<<" "<<a<<endl;
    //             int a = findHash(s);
    //             count=max(count, a);
    //             }
    //         //v.push_back(s);
    //         return;
    //     }
    //     s.push_back(arr[ind]);
    //     findSubsets(arr, ind+1,n, s, count);
    //     s.pop_back();
    //     findSubsets(arr, ind+1, n, s, count);
    // }
    bool isUnique(string s){
        bitset<26> a;
        for(char c : s){
            a.set(c-'a');
        }
        int n = a.count();
        if(n<s.size()){return false;}
        return true;
    }
public:
    int maxLength(vector<string>& arr) {
        // int n = arr.size();
        // vector<string> s = {""};
        // vector<int> dp(n, -1);
        // int count = 0;
        // findSubsets(arr, 0, n, s, count);
        // return count;
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for(string s : arr){
                bitset<26> a;
                for(char c : s){
                    a.set(c-'a');
                }
                int n = a.count();
                if(n<s.size()){continue;}
            for(int i = dp.size()-1; i>=0; i--){
                bitset c = dp[i];
                if ((c & a).any()) continue;
                bitset<26> d = c|a;
                dp.push_back(d);
                res = max(res, (int)(d).count());
            }
        }
        return res;
    }
};