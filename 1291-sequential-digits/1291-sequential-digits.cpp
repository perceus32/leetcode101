class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res, ans;
        string s = to_string(high);
        int len = s.size();
        int l = 0, r = 0;
        while(l<len){
            r=l;
            string temp = s;
            // cout<<temp<<" ";
            while(r<len-1){
                temp[r+1] = temp[r] + 1;
                r++;
            }
            int tmp = stoi(temp);
            // cout<<tmp<<endl;
            if(tmp<=high && tmp>=low){
                res.push_back(tmp);
            }
            if(s[l]!='1'){
                s[l] = s[l] - 1;
            }else{
                s[l] = s[l] - 1;
                l++;
                s[l] = '8';
            }
        }
        set<int> st;
        for(auto i : res){
            st.insert(i);
        }
        auto it = st.begin();
        for(; it!=st.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};