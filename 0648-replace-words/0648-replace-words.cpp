class Node{
    private:
    Node* array[26];
    bool flag;

    public:
    Node() {
        for(int i = 0 ; i< 26 ; i++) {
            array[i] = nullptr;
        }
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
class Trie{
    private:
    Node* root = new Node();
    public:
    void insert(string &word) {
        Node* temp = root;
        for(auto it : word) {
            if(!temp->contains(it)) {
                temp->put(it,new Node());
            }
            temp = temp->getNext(it);
        }
        temp->setFlag();
    }

    string search(string &word) {
        Node* temp = root;
        string ans = "";
        for(auto it : word) {
            if(!temp->contains(it)) return word;
            ans+=it;
            temp = temp->getNext(it);
            if(temp->getFlag()) return ans;
        }
        return ans;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto it : dictionary) {
            trie.insert(it);
        }
        string ans = "";
        string word = "";
        for(int i = 0 ; i < sentence.size() ; i++) {
            if(sentence[i] == ' ') {
                ans+=trie.search(word);
                ans+=" ";
                word = "";
            }
            else{
                word+=sentence[i];
            }
        }
        ans+=trie.search(word);
        return ans;
    }
};