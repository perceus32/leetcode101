class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> str;
        for(auto c: s){
            str.push(c);
        }
        s.clear();
        while(!str.empty()){
            s.push_back(str.top());
            str.pop();
        }
    }
};