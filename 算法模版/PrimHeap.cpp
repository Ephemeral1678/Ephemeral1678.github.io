#include<queue>
#include<unordered_map>
using namespace std;

#define maxn 101
#define inf 10001
#define ll long long

struct Dist {
	int v;
	int w;
	Dist(int vv, int ww) :v(vv), w(ww) {}
	bool operator < (const Dist& other) const {
		return w > other.w;
	}
};

typedef priority_queue<Dist> Heap;
typedef unordered_map<string, int> Hash;

void addEdge(vector<Dist>* edges, int u, int v, int w) {
	edges[u].push_back(Dist(v, w));
}

void PrimInit(int n, bool* visited, int* dist, Heap& heap) {
	for (int i = 0; i < n; ++i) {
		visited[i] = false;
		dist[i] = inf;
	}
	dist[0] = 0;
	heap.push(Dist(0, dist[0]));
}

int PrimFindMin(Heap &heap) {
	Dist s = heap.top();
	heap.pop();
	return s.v;
}

string findInHash(int n, Hash h) {
	for (auto it : h) {
		if (it.second == n) return it.first;
	}
	
}

void PrimUpdate(int u, int n, bool *visited, vector<Dist> *edges, int *dist, Heap &heap, Hash h) {
	if (visited[u]) {
		return ;
	}
	visited[u] = true;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].v;
		if (visited[v]) continue;
		int w = edges[u][i].w;
		if (w < dist[v]) {
			dist[v] = w;
			heap.push(Dist(v, dist[v]));
			string s1 = findInHash(u, h);
			string s2 = findInHash(v, h);
			cout << s1 << " " << s2 << w << endl;
		}
	}
}

void PrimHeap(int n, vector<Dist> *edges, int *dist, Hash h) {
	Heap heap;
	bool visited[maxn];
	PrimInit(n, visited, dist, heap);
	while (!heap.empty()) {
		int u = PrimFindMin(heap);
		PrimUpdate(u, n, visited, edges, dist, heap, h);
	}
}
