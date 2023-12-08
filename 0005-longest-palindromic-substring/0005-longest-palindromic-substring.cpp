class Solution {
private: 
    bool solve(vector<vector<bool>> &dp, int i, int j, string &s){
        if(i == j){
            return dp[i][j] = true;
        }
        if(j-i == 1){
            if(s[i]==s[j]){
                return dp[i][j]=true;
            }else{
                return dp[i][j]=false;
            }
        }
        if(s[i]==s[j] && dp[i+1][j-1]==true){
            return dp[i][j]=true;
        }else{
            return dp[i][j]=false;
        }
    }
public:
    // bool check(string &s, int l, int r){
        
    //     while(l<r){
    //         if(s[l]!=s[r]){
    //             return false;
    //         }
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, max = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; i<n && j<n; i++, j++){
                solve(dp, i, j, s);
                if(dp[i][j]==true){
                    if(j-i+1>max){
                        start = i;
                        max = j-i+1;
                    }
                }
            }
        }
        return s.substr(start, max);

        // bool flag = false;
        // int end, max = 1, imax = 0;
        // for(int i=0; i<s.size(); i++){
        //     int l=i;
        //     for(int j=s.size()-1; j>=0; j--){
        //         int r = j;
        //         if(s[l]!=s[j]){
        //             r--;
        //         }else{
        //             if(check(s, l, r) && r-l+1>max){
        //                 max = r-l+1;
        //                 imax = i;
        //             }
        //         }
        //     }
        // }
        // return s.substr(imax, max);
    }
};