#define TABLE_SIZE 10

typedef struct hashMap {
    char ch;
    struct hashMap* next;
}hashMap;

hashMap* hash_table[TABLE_SIZE];

unsigned int hash(char ch) {
    return (ch-'a') % TABLE_SIZE;
}
void init() {
    for(int i = 0 ; i < TABLE_SIZE ; i++) hash_table[i] = NULL;
}

void insert(hashMap* data) {
    int idx = hash(data->ch);
    if(hash_table[idx] == NULL) hash_table[idx] = data;
    else {
        hashMap* temp = hash_table[idx];
        while(temp->next != NULL && temp->ch != data->ch) temp = temp->next;
        temp->next = data;
    }

}

hashMap* hash_lookup(char ch) {
    unsigned int idx = hash(ch);
    hashMap* temp = hash_table[idx];
    while(temp != NULL && temp->ch != ch) temp = temp->next;
    if(temp == NULL) return NULL;
    return temp;
}

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    init();

    for(int i = 0 ; i < strlen(allowed) ; i++) {
        hashMap* data = (hashMap*)malloc(sizeof(hashMap));
        data->ch = allowed[i];
        data->next = NULL;
        insert(data);
    }
    
   
    int count = 0;
    for(int i = 0 ; i < wordsSize ; i++) {
        bool flag = true;
        int len = strlen(words[i]);
        for(int j = 0 ; j < len ; j++) {
           hashMap* temp = hash_lookup(words[i][j]);
           if(temp == NULL) {
            flag = false;
            break;
           }
        }
        if(flag == true) count++;
    }
    return count;
}