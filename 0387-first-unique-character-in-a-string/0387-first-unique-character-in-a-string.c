#define TABLE_SIZE 10
typedef struct hashMap{
    char ch;
    int value;
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
        if(temp->ch == data->ch) temp->value++;
        else temp->next = data;
    }
}

int firstUniqChar(char* s) {
    
    init(); // Initialise the hash table

    for(int i = 0 ; i < strlen(s) ; i++) {
        hashMap* data = (hashMap*)malloc(sizeof(hashMap));
        data->ch = s[i];
        data->value = 1;
        data->next = NULL;
        insert(data);
    }

    
    for(int i = 0 ; i < strlen(s) ; i++) {
        int idx = hash(s[i]);
        hashMap* temp = hash_table[idx];
        while(temp != NULL && temp->ch != s[i]) temp = temp->next;
        if(temp->ch == s[i] && temp->value == 1) return i;
    }
    return -1;
}