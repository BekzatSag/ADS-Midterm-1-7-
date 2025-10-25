#include<iostream>
#include<vector>
using namespace std;

class Maxheap{
    public:
        vector<int> heap;

        void push(int x){
            if(heap.empty()) heap.push_back(x);
            else{
                heap.push_back(x);
                HeapifyUp(heap.size()-1);
            }
        }

        int pop(){
            if(heap.empty()) return -1;
            int top = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            HeapifyDown(0);
            return top;
        }
        int parent(int x){
            return (x - 1)/2;
        }

        int left_child(int x){
            return 2*x + 1;
        }

        int right_child(int x){
            return 2*x + 2;
        }

    private:
        void HeapifyUp(int x){
            while(x > 0){
                int parent = this->parent(x);
                if(heap[x] > heap[parent]) {
                    swap(heap[x], heap[parent]);
                    x = parent;
                }
                else break;
            }
        }

        void HeapifyDown(int x){
            while(true){
                int left = this->left_child(x);
                int right = this->right_child(x);
                int index = x;
                if(left < heap.size() && heap[left] > heap[index]) index = left;
                if(right < heap.size() && heap[right] > heap[index]) index = right;
                if(index!=x) {
                    swap(heap[index], heap[x]);
                    x = index;
                }
                else break;
            }
        }
};