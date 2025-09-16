class Node {
public:
    int key;
    int val;

    Node* prev;
    Node* next;

    Node(int k,int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>m;
    int size;
    
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        size = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(m.find(key) == m.end()) return -1;

        // Remove from that position and insert at front

        Node* oldNode = m[key];

        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;

        oldNode->next = head->next;
        head->next->prev = oldNode;
        head->next = oldNode;
        oldNode->prev = head;

        return m[key]->val;
    }
    
    void put(int key, int value) {
        
    // if already present in DLL then delete from that position place it after head and update value
        if(m.find(key) != m.end()) {

            m[key]->val = value;
            
            Node* oldNode = m[key];

            oldNode->prev->next = oldNode->next;
            oldNode->next->prev = oldNode->prev;

            oldNode->next = head->next;
            head->next->prev = oldNode;
            head->next = oldNode;
            oldNode->prev= head;
            
        }
        else if(size == 0) {
            // delete the last node and insert new node after head;

            Node* lastNode = tail->prev;
            
            m.erase(lastNode->key);

            lastNode->prev->next = tail;
            tail->prev = lastNode->prev;

            Node* newNode = new Node(key,value);

            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            newNode->prev = head;

            m[key] = newNode;

        }
        else {
            Node* newNode = new Node(key,value);

            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            newNode->prev = head;


            m[key] = newNode;
            size--;
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */