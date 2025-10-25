class Node{
    public:
        int val;
        Node* next;
        Node* prev;
        Node(int x){
            val = x;
            next = nullptr;
            prev = nullptr;
        }
};

class Dlinkedlist{
    public:
        Node* head;
        Node* tail;
        Dlinkedlist(){
            head = tail = nullptr;
        }

        void insert(int x){
            Node* newNode = new Node(x);
            if(!head) {
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void pop(){
            if(!head) return;
            if(head==tail){
                delete tail;
                head=tail = nullptr;
                return;
            }
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }

        Node* reverse(Node* cur){
            Node* temp3 = nullptr;
            Node* temp = cur;
            if(!cur || !cur->next) return cur;
            while(temp){
                Node* temp2 = temp->next;
                temp->next= temp->prev;
                temp->prev = temp2;

                temp3 = temp;
                temp = temp->prev;
            }
            return temp3;
        }

        void insert(int pos, int val){
            Node* newNode = new Node(val);
            if(!head) {
                head = tail = newNode;
                return;
            }
            if (pos==0){
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
                return;
            }
            int count = 0;
            Node* temp = head;
            while(count < pos -1 && temp->next){
                temp = temp->next;
                count++;
            }
            Node* temp2 = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            newNode->next = temp2;
            if(temp2==nullptr) tail = newNode;
            else temp2->prev= newNode;
        }
    void remove(int pos){
        if(!head) return;
        Node* temp = head;
        if(pos==0){
            if(head==tail){
                delete head;
                head=tail=nullptr;
            }
            else{
                Node* nodeDelete = head;
                head = head->next;
                head->prev = nullptr;
                delete nodeDelete;
                return;
            }
        }
        int count = 0;
        while( count < pos -1 && temp->next){
            temp = temp->next;
            count++;
        }
        if(!temp->next) return;
        Node* deleteNode = temp->next;
        Node* nodeAfter = deleteNode->next;

        temp->next = nodeAfter;
        

        if(nodeAfter){
            nodeAfter->prev = temp;
        }

        if(tail==deleteNode) {
            tail = temp;
        }
        delete deleteNode;
    }
};