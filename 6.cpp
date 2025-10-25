#include<iostream>
#include<vector>
using namespace std;

int Binarysearch(vector<int> &v, int val){
    int l = 0;
    int r = v.size() - 1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(v[mid] > val) r = mid -1;
        else if (v[mid] < val) l = mid + 1;
        else return mid;
    }
    return -1;
}


int lowerbound(vector<int> &v, int val){
    int l = 0;
    int r = v.size();
    while(l<r){
        int mid = l + (r-l)/2;
        if(v[mid] >= val) r = mid;
        else l = mid + 1;
    }
    return l;
}


int upperrbound(vector<int> &v, int val){
    int l = 0;
    int r = v.size();
    while(l<r){
        int mid = l + (r-l)/2;
        if(v[mid] > val) r = mid;
        else l = mid + 1;
    }
    return l;
}


int firstoccurance(vector<int> &v, int val){
    int l = 0;
    int r = v.size() - 1;
    int index = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(v[mid] > val) r = mid -1;
        else if (v[mid] < val) l = mid + 1;
        else {
            index = mid;
            r = mid -1;
        }
    }
    return index;
}


int lastoccurance(vector<int> &v, int val){
    int l = 0;
    int r = v.size() - 1;
    int index = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(v[mid] > val) r = mid -1;
        else if (v[mid] < val) l = mid + 1;
        else {
            index = mid;
            l = mid + 1;
        }
    }
    return index;
}


// using xor
int unique_element(vector<int> &v){
    if(v.empty()) return -1;
    int ans = v[0];
    for(int i = 1; i < v.size(); i++){
        ans^=v[i];
    }
    return ans;
}