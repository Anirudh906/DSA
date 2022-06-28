class Node { 
    public:
	int key; 
	int value; 
	Node *prev; 
	Node *next; 

	
	Node(int k, int v) 
	{ 
		key = k; 
		value = v;
		prev=NULL;next=NULL;
	} 
}; 



class LRUCache {
public:
    unordered_map<int, Node *> mp;
    int cap, count;
    Node *head, *tail;
    
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head -> next = tail;
        tail -> prev = head;
        head -> prev = NULL;
        tail -> next = NULL;
        count = 0;
    }
    
    void deleteNode(Node *temp){
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
    }
    void addToHead(Node * temp){
        temp -> next = head -> next;
        temp -> prev = head;
        temp -> next -> prev = temp;
        head -> next = temp;
    }
    int get(int key) {
       if(mp.find(key) != mp.end()){
           Node * t = mp[key];
           int res = t -> value;
           deleteNode(t);
           addToHead(t);
           return res;
       }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node * t= mp[key];
            t -> value = value;
            deleteNode(t);
            addToHead(t);
        }
        else{
            Node *node = new Node(key, value); 
			mp[key]= node; 
			if (count < cap) { 
				count++; 
				addToHead(node); 
			} 
			else { 
				mp.erase(tail->prev->key); 
				deleteNode(tail->prev); 
				addToHead(node); 
			} 
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */