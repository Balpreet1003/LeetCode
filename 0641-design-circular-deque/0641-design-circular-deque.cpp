class MyCircularDeque {
public:
    int size;
    vector<int>a;
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(a.size()==size)return 0;
        a.insert(a.begin(),value);
        return 1;
    }
    
    bool insertLast(int value) {
        if(a.size()==size)return 0;
        a.push_back(value);
        return 1;
    }
    
    bool deleteFront() {
        if(a.size()==0)return 0;
        a.erase(a.begin());
        return 1;
    }
    
    bool deleteLast() {
        if(a.size()==0)return 0;
        a.pop_back();
        return 1;
    }
    
    int getFront() {
        if(a.size()==0)return -1;
        return a[0];
    }
    
    int getRear() {
        if(a.size()==0)return -1;
        return a[a.size()-1];
    }
    
    bool isEmpty() {
        return a.size()==0 ? 1:0;
    }
    
    bool isFull() {
        return a.size()==size ? 1:0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */