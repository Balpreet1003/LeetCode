class MyLinkedList {
    int size;
    ListNode* head;
    ListNode* tail;

public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size || index < 0) {
            return -1;
        }
        ListNode* node = head;
        while (index--) {
            node = node->next;
        }
        return node->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        if (size == 0) {
            tail = node;
        }
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return;
        
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        if (index == size) {
            addAtTail(val);
            return;
        }
        
        ListNode* node = head;
        while (--index) {
            node = node->next;
        }
        
        ListNode* temp = new ListNode(val);
        temp->next = node->next;
        node->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            if (size == 1) {
                tail = NULL;
            }
            size--;
            return;
        }
        
        ListNode* node = head;
        while (--index) {
            node = node->next;
        }
        
        ListNode* toDelete = node->next;
        node->next = node->next->next;
        
        if (toDelete == tail) {
            tail = node;
        }
        
        delete toDelete;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */