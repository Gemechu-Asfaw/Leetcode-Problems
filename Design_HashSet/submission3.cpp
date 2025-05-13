class MyHashSet {
public:
    vector<list<int>> arr;
    int size;

    MyHashSet() {
        size = 500;
        arr.resize(size);
    }

    int hash(int key){
        return key%size;
    }

    list<int> :: iterator search(int key){
        int index = hash(key);
        list<int> :: iterator it = find(arr[index].begin(), arr[index].end(), key);
        return it;
    }
    
    void add(int key) {
        remove(key);
        int index = hash(key);
        arr[index].push_back(key);
    }
    
    void remove(int key) {
        
        if (!contains(key)){
            return;
        }

        int index = hash(key);
        list<int> :: iterator it = search(key);
        arr[index].erase(it);
    }
    
    bool contains(int key) {
        
        int index = hash(key);
        list<int> :: iterator it = search(key);
        if (it != arr[index].end()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */