struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit, Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
private: Node* root;
public: 
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int checkMax(int x){
        Node* node = root;
        int max = 0;
        for(int i=31; i>=0; i--){
            int bit = (x>>i)&1;
            if(node->containsKey(1-bit)){
                max = max|(1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return max;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans(queries.size(), -1);
        Trie trie;
        vector<pair<int, pair<int, int>>> offlineQueries;
        for(int i=0; i<queries.size(); i++){
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        int index=0;
        for(int i=0; i<offlineQueries.size(); i++){
            int x=offlineQueries[i].second.first;
            int m=offlineQueries[i].first;
            int k=offlineQueries[i].second.second;
            while(index<nums.size() && nums[index]<=m){
                trie.insert(nums[index]);
                index++;
            }
            if(index==0){ans[k]=-1;}
            else ans[k]=trie.checkMax(x);
        }  
        return ans;
    }
};