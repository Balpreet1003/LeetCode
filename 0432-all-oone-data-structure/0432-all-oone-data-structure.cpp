class AllOne {
    struct ListNode {
        int count;
        unordered_set<string> keys;
        ListNode* prev;
        ListNode* next;
        ListNode(int cnt) : count(cnt), prev(nullptr), next(nullptr) {}
    };
    
    unordered_map<string, ListNode*> keyNodeMap; // Maps keys to their corresponding node
    ListNode* head; // Dummy head node of doubly linked list
    ListNode* tail; // Dummy tail node of doubly linked list
    
public:
    AllOne() {
        head = new ListNode(0); // Head with dummy count
        tail = new ListNode(0); // Tail with dummy count
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (keyNodeMap.find(key) == keyNodeMap.end()) {
            // Key does not exist, add to the node with count 1
            if (head->next->count != 1) {
                addNodeAfter(head, new ListNode(1));
            }
            head->next->keys.insert(key);
            keyNodeMap[key] = head->next;
        } else {
            // Key exists, move to the next count node
            ListNode* node = keyNodeMap[key];
            int newCount = node->count + 1;
            if (node->next->count != newCount) {
                addNodeAfter(node, new ListNode(newCount));
            }
            node->next->keys.insert(key);
            keyNodeMap[key] = node->next;
            removeKeyFromNode(node, key);
        }
    }
    
    void dec(string key) {
        if (keyNodeMap.find(key) == keyNodeMap.end()) return;
        ListNode* node = keyNodeMap[key];
        if (node->count == 1) {
            // If the count is 1, remove the key completely
            removeKeyFromNode(node, key);
            keyNodeMap.erase(key);
        } else {
            // Move key to the previous count node
            int newCount = node->count - 1;
            if (node->prev->count != newCount) {
                addNodeAfter(node->prev, new ListNode(newCount));
            }
            node->prev->keys.insert(key);
            keyNodeMap[key] = node->prev;
            removeKeyFromNode(node, key);
        }
    }
    
    string getMaxKey() {
        if (tail->prev == head) return ""; // No keys
        return *(tail->prev->keys.begin()); // Get a key with the maximum count
    }
    
    string getMinKey() {
        if (head->next == tail) return ""; // No keys
        return *(head->next->keys.begin()); // Get a key with the minimum count
    }
    
private:
    // Adds a new node after a given node
    void addNodeAfter(ListNode* node, ListNode* newNode) {
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
    }
    
    // Removes a key from the node and deletes the node if it's empty
    void removeKeyFromNode(ListNode* node, string key) {
        node->keys.erase(key);
        if (node->keys.empty()) {
            removeNode(node);
        }
    }
    
    // Removes a node from the doubly linked list
    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
};