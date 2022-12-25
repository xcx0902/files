#include <bits/stdc++.h>
using namespace std;
 
struct folder {
    bool type; // 1: folder, 0: file
    string name, full;
    map<string, bool> has;
    map<string, folder*> child;
    folder* father;
} *root, *now, *p;
 
/*
 * @brief Init File System
 * @example initFS()
 */
void initFS() {
    root = new folder;
    root->type = 1;
    root->name = "";
    root->full = "/";
    root->father = NULL;
    now = root;
    p = NULL;
}
 
/*
 * @brief Cut a string with "/"
 * @example cut("/root/c++") -> ["root", "c++"]
 */
vector<string> cut(string s) {
    unsigned last = -1U;
    vector<string> ret;
    for (unsigned i = 0; i < s.size(); i++)
        if (s[i] == '/') {
//          cerr << "Found s[" << i << "] is '/'" << endl;
            if (last == -1U) goto setLast;
            ret.push_back(s.substr(last, i - last));
            setLast: last = i + 1;
        }
    // avoid string like "/root/c++/"
    if (last < s.size())
        ret.push_back(s.substr(last));
    return ret;
}
 
/*
 * @brief MaKe DIRectory
 * @example mkdir("/home/c++") or mkdir("c++")
 */
void mkdir(string s) {
    if (s[0] != '/') s = now->full + s;
    vector<string> sep = cut(s);
    p = root;
    bool flag = 0;
    for (string x: sep) {
        if (p->has[x]) { 
            if (p->child[x]->type) p = p->child[x];
            else {
                cout << "err" << endl;
                return;
            }
        } else {
            flag = 1;
            p->has[x] = 1;
            p->child[x] = new folder;
            p->child[x]->type = 1;
            p->child[x]->name = x;
            p->child[x]->full = p->full + x + "/";
            p->child[x]->father = p;
            p = p->child[x];
        }
    }
    if (flag == 0) cout << "err" << endl;
    else cout << "ok" << endl;
}
 
/*
 * @brief See all the file and directory below now folder
 * @example ls()
 */
void ls() {
    bool flag = 0;
    for (auto x: now->child) {
        flag = 1;
        if (x.second->type == 0) cout << "*";
        cout << x.first << " ";
    }
    if (!flag) cout << "EMPTY";
    cout << endl;
}
 
/*
 * @brief Choose Directory
 * @example cd("c++") or cd("../..") etc
 */
void cd(string s) {
    if (s[0] != '/') s = now->full + s;
    vector<string> sep = cut(s);
    p = root;
    try { 
        for (string x: sep) {
            if (x == ".") continue;
            else if (x == "..") p = p->father;
            else if (!p->has[x]) throw "err";
            else p = p->child[x];
            if (p == NULL) throw "err";
            if (p->type == 0) throw "err"; 
        }
        now = p;
    } catch (...) {
        cout << "err" << endl;
        return;
    }
    cout << "ok" << endl;
}
 
/*
 * @brief ReMove directory or file
 * @exapmle rm("c++") or rm("/home")
 */
void rm(string s) {
    string ori = (s[0] == '/'? "" : "/") + s;
    if (s[0] != '/') s = now->full + s;
    vector<string> sep = cut(s);
    p = root;
    try {
        vector<string> tmp = cut(ori);
        while (tmp.size() && *(--tmp.end()) == ".")
            tmp.pop_back();
        if (tmp.empty()) throw "err";
        for (string x: sep) {
            if (x == ".") continue;
            else if (x == "..") p = p->father;
            else if (!p->has[x]) throw "err";
            else p = p->child[x];
            if (p == NULL) throw "err"; 
        }
        folder *temp = p;
        p = p->father;
        p->has.erase(*(--sep.end()));
        p->child.erase(*(--sep.end()));
        delete temp;
    } catch (...) {
        cout << "err" << endl;
        return;
    }
    cout << "ok" << endl;
}
 
/*
 * @brief Create a file
 * @example touch("/etc/passwd")
 */
void touch(string s) {
    if (s[0] != '/') s = now->full + s;
    vector<string> sep = cut(s);
    p = root;
    for (string x: sep) {
        if (p->has[x]) { 
            if (p->child[x]->type) p = p->child[x];
            else {
                cout << "err" << endl;
                return;
            }
        } else {
            p->has[x] = 1;
            p->child[x] = new folder;
            p->child[x]->type = 1;
            p->child[x]->name = x;
            p->child[x]->full = p->full + x + "/";
            p->child[x]->father = p;
            p = p->child[x];
        }
    }
    p = p->father;
    p->child[*(--sep.end())]->type = 0;
    cout << "ok" << endl;
}
 
/*
 * @brief See now work directory
 * @example pwd()
 */
void pwd() {
    string tmp = now->full;
    if (tmp == "/") cout << tmp << endl;
    else cout << tmp.substr(0, tmp.size() - 1) << endl;
}
 
int main() {
    int n;
    cin >> n;
    initFS();
    while (n--) {
        string op;
        cin >> op;
        if (op == "mkdir") {
            string x;
            cin >> x;
            mkdir(x);
        } else if (op == "ls") {
            ls();
        } else if (op == "cd") {
            string x;
            cin >> x;
            cd(x);
        } else if (op == "rm") {
            string x;
            cin >> x;
            rm(x);
        } else if (op == "touch") {
            string x;
            cin >> x;
            touch(x);
        } else if (op == "pwd") {
            pwd();
        }
    }
    return 0;
}
