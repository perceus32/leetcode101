class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // int ans = 0, j=0;
        // sort(g.begin(), g.end());
        // sort(s.begin(), s.end());
        // for(int i = 0;i<s.size(); i++){
        //     while(j<g.size()){
        //         if(s[i]<g[j]){break;}
        //         else{
        //             j++;
        //             ans++;
        //             break;
        //         }
        //     }
        // }
        // return ans;
        int n1 = g.size();
        int n2 = s.size();
        int l1=0, l2=0, ans=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(l1<n1 && l2<n2){
            if(s[l2]>=g[l1]){
                ans++;
                l2++;
                l1++;
                continue;
            }else{
                l2++;
                continue;
            }
        }
        return ans;
    }
};