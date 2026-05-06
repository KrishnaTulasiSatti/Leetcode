struct TNode {
    TNode* array[26];
    bool flag;

    TNode() {
        for(int i = 0 ; i < 26 ; i++) array[i] = NULL;
        flag = false;
    }
};

class Trie {
public:

    TNode* root = new TNode();

    Trie() {   
        
    }
    
    void insert(string word) {
        
        TNode* temp = root;

        for(auto it : word) {
            

            if((temp->array)[it-'a'] == NULL) (temp->array)[it-'a'] = new TNode();

            temp = (temp->array)[it-'a'];
        }

        temp->flag = true;
    }
    
    bool search(string word) {
        
        TNode* temp = root;

        for(auto it : word) {
            if((temp->array)[it-'a'] == NULL) return false;
            temp = (temp->array)[it-'a'];
        }

        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        TNode* temp = root;

        for(auto it : prefix) {
            if((temp->array)[it-'a'] == NULL) return false;
            temp = (temp->array)[it-'a'];
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