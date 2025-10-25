#include<iostream>

using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int x){
            val = x;
            next = nullptr;
        }
};

class Linkedlist{
    public:
        Node* head;
        Node* tail;
        Linkedlist(){
            head = nullptr;
            tail = nullptr;
        }

        void insert(int x){
            Node* temp = new Node(x);
            if(!head) {
                head = tail = temp;
                return;
            }
            tail->next = temp;
            tail = temp;
        }

        void pop(){
            if(!head) return;
            Node* temp = head;
            if(head == tail){
                delete head;
                tail = head = nullptr;
                return;
            }
            while(temp->next->next){
                temp=temp->next;
            }
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }

        Node* reverserec(Node* cur){
            if(!cur||!cur->next) return cur;
            Node* temp = reverserec(cur->next);
            cur->next->next = cur;
            cur->next = nullptr;
            return temp;
        }

        void remove(int pos){
            if(!head) return;
            Node* temp = head;
            if(pos==0) {
                if(head==tail){
                    delete head;
                    head = tail = nullptr;
                    return;
                }
                else {
                    head = head->next;
                    delete temp;
                    return;
                }   
            }
            
            for(int i = 0; i < pos - 1 && temp->next; i++){
                temp = temp->next;
            }
            if(!temp->next) return; 
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            if(temp2==tail) {
                tail = temp;
            }
            delete temp2;
        }

        void insert(int pos, int val){
            Node* temp = new Node(val);
            if(!head) {
                head = tail = temp;
                return;
            }
            if(pos==0){
                temp->next= head;
                head = temp;
                return;
            }
            Node* temp2 = head;
            int count = 0; 
            while(count < pos -1 && temp2->next){
                temp2 = temp2->next;
                count++;
            }
            Node* temp3 = temp2->next;
            temp2->next = temp;
            temp->next = temp3;
            if(!temp3) tail = temp;
        }
};
