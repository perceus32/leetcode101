class Solution {
    private: 
    void pushDigits(vector<char> &chars, int count){
        if(count==1){ return;}
        string c = to_string(count);
        int n = c.size();
        for(int i=0; i<n; i++){
            chars.push_back(c[i]);
        }
    }
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, count = 0, ans = 0;
        while(i<n){
            char c = chars[i++];
            chars.push_back(c);
            count++;
            while(i<n && chars[i]==c){
                count++;
                i++;
            }
            pushDigits(chars, count);
            count = 0;
        }
        chars.erase(chars.begin(), chars.begin()+n);
        return chars.size();
    }
};