class MyLinkedList {
private:
    struct node{
        int val;
        node *next;
    };
    node *head;
    node *tail;
    int size;
public:                                                                                                                                                                          
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int get(int index) {
        if(index >= size|| index < 0) 
            return -1;
        node *cur = new node;
        cur = head;
        for(int i = 0;i<index;++i){
            cur = cur->next;
        }
        
        return cur->val;
        
    }
    void addAtHead(int val) {
        node *temp = new node();
        temp->val = val;
        temp->next = head;
        head = temp;
        if(size==0) tail = temp;
        ++size;
    }
    void addAtTail(int val) {
        node *temp = new node();
        temp->val = val;
        if(size==0) {
            tail = temp;
            head = temp;
        }
        tail->next = temp;
        tail = temp;
        ++size;
    }
    void addAtIndex(int index, int val) {
        if(index>size || index < 0) return;
        else if(index == 0) {
            addAtHead(val);
            return;
        }
        else if(index == size) {
            addAtTail(val);
            return;
        }
        node *cur = new node();
        cur = head;
        for(int i = 0;i<index-1;++i){
            cur = cur->next;
        }
        node *temp = new node();
        temp->val = val;
        temp->next = cur->next;
        cur->next = temp;
        ++size;
    }
    void deleteAtIndex(int index) {
        if(index>=size || index < 0) return;
        else if(index == 0){
            head = head->next;
            --size;
            return;
        } 
        node *cur = new node();
        cur = head;
        for(int i = 0;i<index-1;++i){
            cur = cur->next;
        }
        cur->next= cur->next->next;
        if(index == size-1) tail = cur;
        --size;
    }
};

