#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<list>

using namespace std;

int main(){
// vector
vector<int> v;
v.push_back(7); //push element
v.pop_back();

v.push_back(5);
cout << v.front() << endl;
cout << v.back() << endl;

v.insert(v.begin() + 1, 7);
cout << v[1] << endl;

v.clear();

v.size();

v.push_back(2);
v.push_back(2);
v.push_back(2);
cout << count(v.begin(), v.end(), 2) << endl;

find(v.begin(), v.end(), 5); //return iterator

v.erase(v.begin(), v.begin()+1);

for(vector<int>::iterator it = v.begin();  it != v.end(); it++){
    cout << *it << endl;
}

// stack

stack<int> s;

s.push(9);
s.pop();
s.push(1);
s.top();
s.empty();
s.size();


// queue

queue<int> q;
q.push(8);
q.front();
q.back();
q.pop();
q.empty();
q.size();

// deque

deque<int> dq;

dq.push_back(8);
dq.push_front(9);
dq.pop_front();
dq.pop_back();
dq.size();
dq.empty();
dq.push_back(0);
dq.push_front(9);

for(deque<int>::iterator it = dq.begin(); it!=dq.end(); it++){
    cout << *it << endl;
}

dq.clear();
dq.insert(dq.begin(), 9);
dq.erase(dq.begin(), dq.begin()+1);
count(dq.begin(), dq.end(), 7);


// map

map<string, int> m;

m["Jo"] = 46;
m.insert({"Bo", 98});
m.erase("Jo");
m.clear();
m.size();
m.empty();
m.find("Bo"); //iterator
m.count("Bo");
for(map<string, int>::iterator it = m.begin(); it!=m.end(); it++){
    cout << it->first << " " << it->second<< endl;
}



// set
set<int> se;
se.insert(3);
se.empty();
se.clear();
se.erase(3);
se.size();
se.insert(9);

for(set<int>::iterator it = se.begin(); it!=se.end(); it++){
    cout << *it << endl;
}

count(se.begin(), se.end(), 8);


//list

list<int> l;
l.push_back(8);
l.push_front(7);
l.front();
l.back();
l.pop_back();
l.pop_front();
l.size();
l.empty();
l.clear();
l.begin();
l.end();
l.push_back(8);
l.insert(l.begin(), 9);
l.remove(8);
l.sort();
l.reverse();
l.begin();


// algorithms

//find(it, it, element)
//count(it, it, element)
//count_if(it, it, function)
//fill(it, it, value)
//unique(it, it)
//rotate(it_begin, it_new_begin, it_last)
//next_permutation(it, it)
//prev_permutation(it, it)
//generate(it, it, gen_function)
}