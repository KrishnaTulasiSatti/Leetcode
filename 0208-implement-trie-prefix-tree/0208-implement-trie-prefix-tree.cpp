class Node{
    private:
    Node* array[26];
    bool flag;
    public:
    Node() {
        for(int i = 0 ; i < 26 ; i++) array[i] = nullptr;
        flag = false;
    }

    bool contains(char ch) {
        return array[ch-'a'] != nullptr;
    }

    void put(char ch,Node* node) {
        array[ch-'a'] = node;
    }

    Node* getNext(char ch) {
        return array[ch-'a'];
    }

    void setFlag() {
        flag = true;
    }
    
    bool getFlag() {
        return flag;
    }
};



class Trie {
    Node* root = new Node();
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Node* temp = root;
        for(auto it : word) {
            if(!temp->contains(it)) {
                temp->put(it,new Node());
            }
            temp = temp->getNext(it);
        }
        temp->setFlag();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto it : word) {
            if(!temp->contains(it)) return false;
            temp = temp->getNext(it);
        }
        return temp->getFlag();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto it : prefix) {
            if(!temp->contains(it)) return false;
            temp = temp->getNext(it);
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