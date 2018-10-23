#include <iostream>
#include <queue> // очередь
using namespace std;

int main(){
	queue<int> Queue;
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
	Queue.push(0);//кладем в очередь первую вершину
	while (!Queue.empty()){   //пока очередь не пуста
		int node = Queue.front(); // извлекаем вершину
		Queue.pop();
		nodes[node] = 2; // отмечаем ее как посещенную
		for (int j = 0; j < 7; j++) { // проверяем для нее все смежные вершины
			if (matrix[node][j] == 1 && nodes[j] == 0) { // если вершина смежная и не обнаружена
				  Queue.push(j); // добавляем ее в очередь
				  nodes[j] = 1; // отмечаем вершину как обнаруженную 
			}
		 }
		cout << node + 1 << endl; // выводим номер вершины
	}
	cin.get();
	return 0;
}
