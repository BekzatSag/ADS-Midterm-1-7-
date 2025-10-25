#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>& v, int l, int r){
    int index_part = r;
    int j = l -1;
    for(int i = l; i < r; i++){
        if(v[index_part] >= v[i]) {
            j++;
            swap(v[i], v[j]);
        }
    }
    swap(v[index_part], v[j+1]);
    return j+1;
}
void quicksort(vector<int>& v, int l, int r){
    if(l < r){
        int index_part = partition(v, l, r);
        quicksort(v, l, index_part-1);
        quicksort(v, index_part+1, r);
    }
    
}

int main(){

}