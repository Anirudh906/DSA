class DListNode {
    public:
    int key, val, freq;
    DListNode *next, *prev;
    
    DListNode(int k ,int v){
        key = k;
        val = v;
        freq = 1;
        next = NULL;
        prev = NULL;
    }
};

class DLL {
    public:
     DListNode *head;
     int size;
    
     DLL(){
         size = 0;
         head = new DListNode(-1, -1);
         head -> next = head -> prev = head;
     }
    
    void prepend(DListNode *node){
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
        size++;
    }
    
    DListNode *pop(DListNode *node = NULL){
        if(size == 0) return NULL;
        if(node == NULL) node = head -> prev;
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        size--;
        return node;
    }
    
};

class LFUCache {
public:
    unordered_map<int, DListNode*> nodesList;
    unordered_map<int, DLL*> freqList;
    
    int cap, minFreq;
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    void updateFreq(DListNode * node){
        if(freqList.find(node -> freq) == freqList.end()){
            freqList[node -> freq] = new DLL();    
        } if(freqList.find(node->freq + 1) == freqList.end()){
            freqList[node->freq + 1] = new DLL();
        }
        freqList[node->freq] -> pop(node);
        if(minFreq == node->freq and freqList[node->freq]->size == 0){
            minFreq++;
        }
        node->freq++;
        freqList[node->freq] -> prepend(node);
    }
    int get(int key) {
        if(nodesList.find(key) == nodesList.end()){
            return -1;
        }
        updateFreq(nodesList[key]);
        return nodesList[key] -> val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(nodesList.find(key) != nodesList.end()){
            DListNode *node = nodesList[key];
            updateFreq(node);
            node->val = value;
        } else {
            if(nodesList.size() == cap){
                if(freqList.find(minFreq) == freqList.end()){
                    freqList[minFreq] = new DLL();
                }
                DListNode *tempDel = freqList[minFreq] -> pop();
                if(tempDel){
                    nodesList.erase(tempDel-> key);
                }
            }
            DListNode *newNode = new DListNode(key, value);
            nodesList[key] = newNode;
            if(freqList.find(1) == freqList.end()){
                freqList[1] = new DLL();
            }
            freqList[1] -> prepend(newNode);
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
class DListNode{
public:
    int key;
    int value;
    int freq;
    DListNode *prev, *next;
    
    DListNode(int k, int v){
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class DList{
public:
    DListNode* sentinel;
    int size;
    
    DList(){
        size = 0;
        sentinel = new DListNode(-1, -1);
        sentinel->prev = sentinel->next = sentinel;
    }
    
    void prepend(DListNode* node){
        node->next = sentinel->next;
        node->prev = sentinel;
        sentinel->next->prev = node;
        sentinel->next = node;
        ++size;
    }
    
    DListNode* pop(DListNode* node = nullptr){
        if(size == 0) return nullptr;
        if(node == nullptr) node = sentinel->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size;
        return node;
    }
};

class LFUCache {
public:
    unordered_map<int, DListNode*> nodes;
    unordered_map<int, DList*> freqs;
    int capacity;
    int min_freq;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
        min_freq = 0;
    }
    
    void _update(DListNode* node){
        if(freqs.find(node->freq) == freqs.end()){
            freqs[node->freq] = new DList();
        }
        if(freqs.find(node->freq+1) == freqs.end()){
            freqs[node->freq+1] = new DList();
        }
        freqs[node->freq]->pop(node);
        if(min_freq == node->freq && freqs[node->freq]->size == 0){
            ++min_freq;
        }
        
        ++node->freq;
        freqs[node->freq]->prepend(node);
    }
    
    int get(int key) {
        if(nodes.find(key) == nodes.end()){
            return -1;
        }
        
        DListNode* node = nodes[key];
        
        _update(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(nodes.find(key) != nodes.end()){
            DListNode* node = nodes[key];
            _update(node);
            node->value = value;
        }else{
            if(nodes.size() == capacity){
                if(freqs.find(min_freq) == freqs.end()){
                    freqs[min_freq] = new DList();
                }
                
                DListNode* node = freqs[min_freq]->pop();
                if(node){
                    nodes.erase(node->key);
                }
            }
            
            DListNode* node = new DListNode(key, value);
            nodes[key] = node;
            if(freqs.find(1) == freqs.end()) freqs[1] = new DList();
            freqs[1]->prepend(node);
            min_freq = 1;
        }
    }
};
*/