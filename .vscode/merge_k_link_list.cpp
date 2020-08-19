/*功能：*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

using namespace std;





//k个有序链表合并成一个有序链表
int main() {
    int len = 0;
    vector<deque<int>> lists;
    int count = 0;
    while (cin >> len) {
        int tmp;
        lists.push_back(deque<int>());
        for (int i = 0; i < len; ++i) {
            cin >> tmp;
            lists[count].push_back(tmp);
        }
        ++count;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < count; ++i) {
        int tmp = lists[i].front();
        lists[i].pop_front();
        q.push(make_pair(tmp, i));
    }
    while(!q.empty()) {
        auto pr = q.top();
        q.pop();
        cout << pr.first << " ";
        int id = pr.second;
        if (!lists[id].empty()) {
            q.push(make_pair(lists[id].front(), id));
            lists[id].pop_front();
        }
    }
    cout << endl;
    return 0;
}

class A{
public:
    string s() const{
        return *_s;
    }

    // default ctor
    A() : _s(new string()){ }

    // string ctor
    A(string &str) : _s(new string(str)) {}

    // move ctor
    A(A &&a) {
        _s = a._s;
        a._s = nullptr;
    }

    // op = lvalue
    A& operator=(const A& a) {
        if (&a != this) {
            if (_s != nullptr) delete _s;
            _s = a._s;
        }
        return *this;
    }

    // op = rvalue
    A& operator=(A&& a) {
        if (&a != this) {
            if (_s != nullptr) delete _s;
            _s = a._s;
            a._s = nullptr;
        }
        return *this;
    }

    // dtor
    ~A() {
        if (_s != nullptr) delete _s;
    }

private:
    string *_s;

    // copy ctor
    A(const A&) {};
};


