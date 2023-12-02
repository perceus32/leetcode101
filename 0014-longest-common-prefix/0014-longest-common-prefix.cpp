struct Node{
    Node* links[26];
    int count = 0;
    int end = 0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void incrementEnd(){
        end++;
    }
    int getEnd(){
        return end;
    }
    void incrementCount(){
        count++;
    }
    int getCount(){
        return count;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incrementCount();
        }
        node->incrementEnd();
    }

    string traverse(string word, int size){
        string ans = "";
        if(word.size()==0){return ans; }
        Node* node = root;
        node = node->get(word[0]);
        int max = node->getCount();
        if(max!=size){return ans;}
        ans+=word[0];
        for(int i=1; i<word.size(); i++){
            // cout<<max<<" ";
            node = node->get(word[i]);
            if(max==node->getCount()){
                ans+=word[i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
    Trie myTrie;
    for(auto it: strs){
        myTrie.insert(it);
    }
    ans = myTrie.traverse(strs[0], strs.size());
    return ans;
    }
};