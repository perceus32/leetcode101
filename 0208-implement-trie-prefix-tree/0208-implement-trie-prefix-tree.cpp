struct Node{
    Node* links[26];
    bool flag;

    bool containsReferenceNode(char ch){
        return links[ch-'a']!=NULL;
    }
    void createReferenceNode(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* getReferenceNode(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
private: Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i =0;i<word.size();i++){
            if(!node->containsReferenceNode(word[i])){
                node->createReferenceNode(word[i], new Node());
            }
            node = node->getReferenceNode(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size();i++){
            if(node->containsReferenceNode(word[i])){
                node=node->getReferenceNode(word[i]);
            }else{
                return false;
            }
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->containsReferenceNode(prefix[i])){
                return false;
            }
            node=node->getReferenceNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */