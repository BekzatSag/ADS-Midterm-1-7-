#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int x){
            val = x;
            left = right = nullptr;
        }
};

class BST{
    public:
        Node* root;
        BST(){
            root = nullptr;
        }

        void insert(int x){
            root = insert_rec(root, x);
        }

        Node* search(int x){
            return search_rec(root, x);
        }

        void remove(int x){
            root = remove_rec(root, x);
        }

        void inorder(Node* node){
            if(!node) return ;
            inorder(node->left);
            cout << node->val << endl;
            inorder(node->right);
        }

        void preorder(Node* node){
            if(!node) return;
            cout << node->val << endl;
            preorder(node->left);
            preorder(node->right);
        }

        void postorder(Node* node){
            if(!node) return;
            postorder(node->left);
            postorder(node->right);
            cout << node->val << endl;
        }

        int getsize(Node* node){
            if(!node) return 0;
            return 1 + getsize(node->left) + getsize(node->right);
        }

    private:
        Node* insert_rec(Node* node, int x){
            if(!node) return new Node(x);
            if(x > node->val) node->right = insert_rec(node->right, x);
            if(x < node->val) node->left = insert_rec(node->left, x);
            return node;
        }

        Node* search_rec(Node* node, int x){
            if(!node) return node;
            if(x > node->val) return search_rec(node->right, x);
            else if (x < node->val) return search_rec(node->left, x);
            else if (x==node->val) return node;
        }

        Node* minNode(Node* node){
            Node* temp = node;
            while(temp && temp->left){
                temp = temp->left;
            }
            return temp;
        }

        Node* remove_rec(Node* node, int val){
            if(!node) return node;
            if(val > node->val) node->right = remove_rec(node->right, val);
            else if(val < node->val) node->left = remove_rec(node->left, val);
            else {
                if(!node->left){
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                if(!node->right){
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }

                Node* min = minNode(node->right);
                node->val = min->val;
                node->right = remove_rec(node->right, min->val);
            }
            return node;
        }
};
int main(){

}