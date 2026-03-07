class LFUCache {
    struct Node{
        int key,val,cnt=1;
        Node* prev,*next;
        Node(int k,int v): key(k),val(v),prev(nullptr),next(nullptr){
            cnt=1;
        }
    };
    struct List{
        int size;
        Node *head,*tail;
        List() {
            head = new Node(0, 0); 
            tail = new Node(0,0); 
            head->next = tail;
            tail->prev = head; 
            size = 0;
        }
        void addFront(Node *node) {
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++; 
        }
        void removeNode(Node* delnode) {
            Node* prevNode = delnode->prev;
            Node* nextNode = delnode->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            size--; 
        }
    };
private:
    map<int, Node*> keyNode; 
    map<int, List*> fq; 
    int cap,mini,curr; 
public:
    LFUCache(int capacity) {
        cap=capacity;
        mini=0;
        curr=0;
    }
    void updatefq(Node *node) {
        keyNode.erase(node->key); 
        fq[node->cnt]->removeNode(node); 
        if(node->cnt == mini && 
            fq[node->cnt]->size == 0) {
            mini++; 
        }
        List* nextHigherFreqList = new List();
        if(fq.find(node->cnt + 1) != 
            fq.end()) {
            nextHigherFreqList = fq[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addFront(node); 
        fq[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->val;
            updatefq(node); 
            return val; 
        }
        return -1; 
    }
   
    void put(int key, int value) {
        if (cap == 0)
            return;
            if(keyNode.find(key) != keyNode.end()) {
                Node* node = keyNode[key]; 
                node->val = value; 
                updatefq(node); 
        }else {
            if(curr == cap) {
                List* list = fq[mini]; 
                keyNode.erase(list->tail->prev->key); 
                fq[mini]->removeNode(list->tail->prev);
                curr--; 
            }
            curr++; 
            mini = 1;
            List* listFreq = new List(); 
            if(fq.find(mini) != 
                fq.end()) {
                listFreq = fq[mini]; 
            }
            Node* node = new Node(key, value); 
            listFreq->addFront(node);
            keyNode[key] = node; 
            fq[mini] = listFreq; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */