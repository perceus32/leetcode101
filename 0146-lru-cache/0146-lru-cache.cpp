class LRUCache {
private:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int size;
    unordered_map<int, Node*> hash;

public:
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }
    void delnode(Node* node){
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key) {
        if(hash.find(key)!=hash.end()){
            Node* node = hash[key];
            int value = node->val;
            delnode(node);
            addnode(node);
            hash[key] = head->next;
            return value;
        }
        return -1;
    }
    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            Node* node = hash[key];
            hash.erase(key);
            delnode(node);
        }
        if(size==hash.size()){
            hash.erase(tail->prev->key);
            delnode(tail->prev);
        }
        Node* node = new Node(key, value);
        addnode(node);
        hash[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */