class Solution {
public:
    string largestPalindromic(string num) {
        // map<int, int> hash;
        // long long ans = 0;
        // for(auto c : num){
        //     hash[(int)c]++;
        // }
        // for(auto i : hash){
        //     cout<<i.first<<" ";
        // }
        // for(auto i : hash){
        //     if(i.second>1){
        //         int q = i.second/2;
        //         while(q){
        //             ans*=10;
        //             ans+=i.first;
        //             q--;
        //         }
        //     }
        // }
        // string res = to_string(ans);
        // string temp = res;
        // reverse(temp.begin(), temp.end());
        // res += temp;
        // return res;
        vector<int> freq(10, 0);
        string front, back;
        for(auto c : num){
            freq[c-'0']++;
        }
        for(int i=9; i>=0; i--){
            if(!i && front.empty()){break;}
            while(freq[i]>1){
                front+=i+'0';
                back+=i+'0';
                freq[i]-=2;
            }
        }
        for(int i=9; i>=0; i--){
            if(freq[i]){
                front+=i+'0';
                break;
            }
        }
        reverse(back.begin(), back.end());
        front+=back;
        return front;
    }
};