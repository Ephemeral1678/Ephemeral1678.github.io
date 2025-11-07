并查集代码模版
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 105;

struct Point {
    int x, y;
} points[MAXN];

int father[MAXN];
bool repaired[MAXN];
int n, d;

double distance(int i, int j) {
    int dx = points[i].x - points[j].x;
    int dy = points[i].y - points[j].y;
    return sqrt(dx * dx + dy * dy);
}


//寻找父集合
int findFather(int x) {
    if (x != father[x]) {
        father[x] = findFather(father[x]);
    }
    return father[x];
}
//合并集合
void unionSet(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) {
        father[fa] = fb;
    }
}

int main() {
    cin >> n >> d;
    
    //初始化定义，将所有节点的父集合定义为自己
    for (int i = 1; i <= n; i++) {
        cin >> points[i].x >> points[i].y;
        father[i] = i;
        repaired[i] = false;
    }
    
    string op;
    while (cin >> op) {
        if (op == "O") {
            int p;
            cin >> p;
            repaired[p] = true;
            
            for (int i = 1; i <= n; i++) {            
                if (i != p && repaired[i] && distance(i, p) <= d + 1e-8) {
                    unionSet(i, p);
                }
            }
        } else if (op == "S") {
            int p, q;
            cin >> p >> q;
            if (findFather(p) == findFather(q)) {
                cout << "SUCCESS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }
    
    return 0;
}
