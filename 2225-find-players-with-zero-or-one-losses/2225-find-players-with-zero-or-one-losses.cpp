class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // long n = matches.size();
        // unordered_map<int, long> freq;
        // set<int> w;
        // set<int> l;
        // vector<int> one;
        // for(long i=0; i<n; i++){
        //     freq[matches[i][1]]++;
        //     w.insert(matches[i][0]);
        //     l.insert(matches[i][1]);
        // }
        // for(auto i : freq){
        //     if(i.second==1){one.push_back(i.first);}
        // }
        // vector<int> zero;
        // auto itr1 = w.begin();
        // auto itr2 = l.begin();
        // int a;
        // while(itr1!=w.end() && itr2!=l.end()){
        //     a = *itr1;
        //     int b = *itr2;
        //     if(a<b){zero.push_back(a); itr1++; continue;}
        //     if(a==b){itr1++; itr2++; continue;}
        //     if(a>b){itr2++;}
        // }
        // if(itr1!=w.end() && itr2==l.end()){
        //     while(itr1!=w.end()){ 
        //         zero.push_back(a);
        //         itr1++;
        //         a = *itr1;
        //     }
        // }
        // sort(begin(one), end(one));
        // vector<vector<int>> ans = {zero, one};
        // return ans;
        int n = matches.size();
        unordered_map<int, int> freq;
        vector<int> zero, one;
        set<int> temp;
        for(int i=0; i<n; i++){
            freq[matches[i][1]]++;
        }
        for(auto i : freq){
            if(i.second==1){one.push_back(i.first);}
        }
        for(int i=0; i<n; i++){
            if(!freq[matches[i][0]]){temp.insert(matches[i][0]);}
        }
        sort(begin(one), end(one));
        for(auto itr = temp.begin(); itr!=temp.end(); itr++){
            zero.push_back(*itr);
        }
        vector<vector<int>> ans = {zero, one};
        return ans;
    }
};