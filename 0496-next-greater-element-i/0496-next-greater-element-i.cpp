class Solution {
private:
    void printHash(unordered_map<int, int> hash){
        for(auto i: hash){
            cout<<i.first<<" "<<i.second;
        }
        cout<<endl;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // int n = nums2.size();
        // stack<int> s;
        // vector<int> nge(n, -1);
        // for(int i=n-1; i>=0; i--){
        //     while(!s.empty() && s.top()<=nums2[i]){
        //         s.pop();
        //     }
        //     if(!s.empty()) nge[i]=s.top();
        //     s.push(nums2[i]);
        // }
        // int m = nums1.size();
        // vector<int> res(m, -1);
        // for(int i=0; i<m; i++){
        //     int el = nums1[i];
        //     for(int j=0; j<n; j++){
        //         if(el==nums2[j]){
        //             res[i] = nge[j];
        //         }
        //     }
        // }
        // return res;

        unordered_map<int, int> hash;
        stack<int> s;
        int n1 = nums1.size(), n2=nums2.size();
        vector<int> res(n1, -1);

        for(int i:nums1){
            hash[i]=-1;
            // printHash(hash);
        }

        for(int i=n2-1; i>=0; i--){
            while(!s.empty() && s.top()<=nums2[i]){
                    s.pop();
                }
            if(!s.empty()){
                if(hash.find(nums2[i])!=hash.end()){
                    hash[nums2[i]] = s.top();
                }
            }
            s.push(nums2[i]);
            // printHash(hash);
        }

        for(int i=0; i<n1; i++){
            res[i] = hash[nums1[i]];
        }
        return res;
    }
};