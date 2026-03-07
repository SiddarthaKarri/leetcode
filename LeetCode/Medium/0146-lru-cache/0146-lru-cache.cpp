class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            key = _key;
            val=_val;
        }
};
class LRUCache {
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    void add(Node* n){
        Node* temp = head->next;
        n->next= temp;
        n->prev = head;
        head->next=n;
        temp->prev=n;
    }
    void del(Node* n){
        Node* delPrev = n->prev;
        Node* delNext = n->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key_) {
        if(mp.find(key_)!=mp.end()){
            Node* res = mp[key_];
            int resp = res->val;
            mp.erase(key_);
            del(res);
            add(res);
            mp[key_] = head->next;
            return resp;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_)!=mp.end()){
            Node * exis = mp[key_];
            mp.erase(key_);
            del(exis);
        }
        if(mp.size()==cap){
             mp.erase(tail->prev->key);
            del(tail->prev);
        }
        add(new Node(key_,value));
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */