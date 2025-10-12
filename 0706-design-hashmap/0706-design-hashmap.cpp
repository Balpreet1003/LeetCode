class MyHashMap {
    vector<int>custom_map;
public:
    MyHashMap() {
        custom_map.resize(1e6+1, -1);
    }
    
    void put(int key, int value) {
        custom_map[key]=value;
    }
    
    int get(int key) {
        return custom_map[key];
    }
    
    void remove(int key) {
        custom_map[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */