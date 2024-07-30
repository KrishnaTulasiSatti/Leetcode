#define TABLE_SIZE 50

typedef struct hashMap{
    int key;
    int value;
    struct hashMap* next;
}hashMap;

hashMap* hash_table[TABLE_SIZE];

unsigned int hash(int key) {
    if(key < 0) key*=-1;
    return key % TABLE_SIZE;
}

void init() {
    for(int i = 0 ; i < TABLE_SIZE ; i++) hash_table[i] = NULL;
}

void insert(hashMap* data) {
    int idx = hash(data->key);
    if(hash_table[idx] == NULL) hash_table[idx] = data;
    else {
        hashMap* temp = hash_table[idx];
        while(temp->next != NULL && temp->key != data->key) temp = temp->next;
        if(temp->key == data->key) temp->value++;
        else temp->next = data;
    }
}

int majorityElement(int* nums, int numsSize) {
    init();

    for(int i = 0 ; i < numsSize ; i++) {
        hashMap* data = (hashMap*)malloc(sizeof(hashMap));
        data->key = nums[i];
        data->value = 1;
        data->next = NULL;
        insert(data);
    }


    for(int i = 0 ; i < numsSize ; i++) {
        int idx = hash(nums[i]);
        hashMap* temp = hash_table[idx];
        while(temp != NULL && temp->key != nums[i]) temp = temp->next;
        if(temp->key == nums[i] && temp->value > numsSize/2) return temp->key;
    }
    return -1;
}