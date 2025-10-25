#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& v, int l, int m, int r){
    int n1 = (m - l + 1);
    int n2 = (r - m);
    vector<int> left_v (n1);
    vector<int> right_v (n2);
    for(int i = 0; i < n1; i++){
        left_v[i] = v[i+l];
    }

    for(int i = 0; i < n2; i++){
        right_v[i] = v[m+1+i];
    }

    int i = 0; 
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(left_v[i] <= right_v[j]) {
            v[k] = left_v[i];
            i++;
        }
        else{
            v[k] = right_v[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        v[k] = left_v[i];
        k++;
        i++;
    }

    while(j < n2){
        v[k] = right_v[j];
        k++;
        j++;
    }
}
void mergesort(vector<int>& v, int l, int r){
    if(l < r){
        int mid = l + (r-l)/2;
        mergesort(v, l, mid);
        mergesort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
    
}