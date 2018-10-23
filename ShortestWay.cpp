#include <stack>
using namespace std;

struct Edge { //ребро
  int begin;
  int end;
};

int main(){
	queue<int> Queue;
	stack<Edge> Edges;
	int req;
	Edge e;
	int matrix[7][7] = {{0, 0, 0, 1, 0, 0, 1},
						{0, 0, 0, 0, 1, 1, 0},
						{0, 0, 0, 0, 0, 1, 1},
						{1, 0, 0, 0, 1, 0, 0},
						{0, 1, 0, 1, 0, 0, 0},
						{0, 1, 1, 0, 0, 0, 0},
						{1, 0, 1, 0, 0, 0, 0}};
	int nodes[7]; // вершины графа
	for (int i = 0; i < 7; i++)
    nodes[i] = 0; // исходно все вершины равны 0
	cout << "N = "; 
	cin >> req; req--;
	Queue.push(0);//кладем в очередь первую вершину

	 while (!Queue.empty()){
		int node = Queue.front(); // извлекаем вершину
		Queue.pop();
		nodes[node] = 2; // отмечаем ее как посещенную
		for (int j = 0; j < 7; j++){
			if (matrix[node][j] == 1 && nodes[j] == 0){ // если вершина смежная и не обнаружена
				Queue.push(j); // добавляем ее в очередь
				nodes[j] = 1; // отмечаем вершину как обнаруженную
				e.begin = node; e.end = j;
				Edges.push(e);
				if (node == req) break;
			}
		}
		cout << node + 1 << endl; // выводим номер вершины
	}
	cout << "Way to node  " << req + 1 << endl;
	cout << req + 1;
	while (!Edges.empty()) {
		e = Edges.top();
		Edges.pop();
		if (e.end == req) {
			req = e.begin;
			cout << " <- " << req + 1;
		}
	}
  cin.get(); cin.get();
  return 0;
}
