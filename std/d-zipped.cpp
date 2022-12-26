#include <bits/stdc++.h>
using namespace std;
struct folder {
    bool type;
    string name, full;
    map<string, bool> has;
    map<string, folder*> child;
    folder* father;
} *root, *now, *p;
void initFS() { root = new folder, root->type = 1, root->name = "", root->full = "/", root->father = NULL, now = root, p = NULL; }
vector<string> cut(string s) {
    unsigned last = -1U;
    vector<string> ret;
    for (unsigned i = 0; i < s.size(); i++) if (s[i] == '/') {
        if (last == -1U) goto setLast;
        ret.push_back(s.substr(last, i - last));
        setLast: last = i + 1;
    }
    if (last < s.size()) ret.push_back(s.substr(last));
    return ret;
}
void mkdir(string s) {
    if (s[0] != '/') s = now->full + s;
    vector<string> sep = cut(s);
    p = root;
    bool flag = 0;
    for (string x: sep) {
        if (x == ".") continue;
        else if (x == "..") { if (p == root) { cout << "err" << endl; return; } p = p->father; }
        else if (p->has[x]) { if (p->child[x]->type) p = p->child[x]; else { cout << "err" << endl; return; } }
        else { flag = 1, p->has[x] = 1, p->child[x] = new folder, p->child[x]->type = 1, p->child[x]->name = x, p->child[x]->full = p->full + x + "/", p->child[x]->father = p, p = p->child[x]; }
    }
    if (flag == 0) cout << "err" << endl;
    else cout << "ok" << endl;
}
void ls() {
    bool flag = 0;
    for (auto x: now->child) { flag = 1; if (x.second->type == 0) cout << "*"; cout << x.first << " "; }
    if (!flag) cout << "EMPTY"; cout << endl;
}
void cd(string s) {
    if (s[0] != '/') s = now->full + s;
    vector<string> sep = cut(s);
    p = root;
    try { 
        for (string x: sep) { if (x == ".") continue; else if (x == "..") p = p->father; else if (!p->has[x]) throw "err"; else p = p->child[x]; if (p == NULL) throw "err"; if (p->type == 0) throw "err"; }
        now = p;
    } catch (...) { cout << "err" << endl; return; }
    cout << "ok" << endl;
}
void rm(string s) {
    string ori = (s[0] == '/'? "" : "/") + s;
    if (s[0] != '/') s = now->full + s;
    vector<string> sep = cut(s);
    vector<string> tmp = cut(now->full);
    p = root;
    try {
        for (string x: sep) { if (x == ".") continue; else if (x == "..") p = p->father; else if (!p->has[x]) throw "err"; else p = p->child[x]; if (p == NULL) throw "err";  }
        folder *temp = p;
        vector<string> pos = cut(temp->full);
        if (pos.size() <= tmp.size()) { bool flag = 1; for (int i = 0; i < pos.size(); i++) if (pos[i] != tmp[i]) { flag = 0; break; } if (flag) throw "err"; }
        p = p->father; p->has.erase(*(--sep.end())); p->child.erase(*(--sep.end())); delete temp;
    } catch (...) { cout << "err" << endl; return; }
    cout << "ok" << endl;
}
void touch(string s) {
    if (s[0] != '/') s = now->full + s;
    vector<string> sep = cut(s);
    p = root;
    for (string x: sep) {
        if (x == ".") continue;
        else if (x == "..") { if (p == root) { cout << "err" << endl; return; } p = p->father; }
        else if (p->has[x]) { if (p->child[x]->type) p = p->child[x]; else { cout << "err" << endl; return; } }
        else { p->has[x] = 1; p->child[x] = new folder; p->child[x]->type = 1; p->child[x]->name = x; p->child[x]->full = p->full + x + "/"; p->child[x]->father = p; p = p->child[x]; }
    }
    p = p->father; p->child[*(--sep.end())]->type = 0; cout << "ok" << endl;
}
void pwd() { string tmp = now->full; if (tmp == "/") cout << tmp << endl; else cout << tmp.substr(0, tmp.size() - 1) << endl; }
int main() {
    int n; cin >> n; initFS();
    while (n--) {
        string op;
        cin >> op;
        if (op == "mkdir") { string x; cin >> x; mkdir(x); }
        else if (op == "ls") ls();
        else if (op == "cd") { string x; cin >> x; cd(x); }
        else if (op == "rm") { string x; cin >> x; rm(x); }
        else if (op == "touch") { string x; cin >> x; touch(x); }
        else if (op == "pwd") pwd();
    }
    return 0;
}
