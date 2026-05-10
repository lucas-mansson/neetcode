class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }
};

class LinkedList {
public: 
    ListNode* head;
    int size;

    LinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if(index >= size) {
            return -1;
        }
        ListNode* curr = head;
        int i = 0;
        while(i < index){
            curr = curr->next;
            i++;
        }
        return curr->val;
    }

    void insertHead(int val) {
        ListNode* newHead = new ListNode(val);
        if(size > 0) {
            newHead->next = head;
        }
        head = newHead;
        size++;
    }
    
    void insertTail(int val) {
        ListNode* newTail = new ListNode(val);
        if(size == 0){
            head = newTail;
        } else {
            int i = 0;
            ListNode* curr = head;
            while(i < size-1) {
                curr = curr->next;
                i++;
            }
            curr->next = newTail;
        }
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        if (index == 0) {
            if(size == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
        } else {
            ListNode* curr = head;
            int i = 0;
            while(curr->next != nullptr && i < index-1) {
                curr = curr->next;
                i++;
            }
            curr->next = curr->next->next;
        }
        
        size--;
        return true;    
    }

    vector<int> getValues() {
        std::vector<int> res = std::vector<int>();
        int i = 0;
        ListNode* curr = head;
        while(i < size) {
            res.push_back(get(i));
            curr = curr->next;
            i++;
        }
        return res;
    }
};
