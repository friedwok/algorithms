#include<iostream>

#define MAX_NODES 1024				/* максимальное количество узлов */
#define INFINITY 100000000			/* число, большее длины максимального пути */

int n, dist[MAX_NODES][MAX_NODES];		/* dist[i][j] - расстояние от i до j */

void shortest_path(int s, int t, int path[])
{
	enum condition { permanent, tentative };
	struct state_of_vertex {		/* рабочий путь */
		int predecessor;		/* предыдущий узел */
		int length;			/* расстояние от источника до узла */
		condition label;		/* состояние */
	} state[MAX_NODES];
	int i, k, min;
	struct state_of_vertex *p;
	for(p = state; p < &state[n]; p++) {	/* инициализация состояния */
		p->predecessor = -1;
		p->length = INFINITY;
		p->label = tentative;
	}
	state[t].length = 0;
	state[t].label = permanent;
	k = t;					/* k - начальный рабочий узел */
	do {					/* Есть ли лучший путь от k? */
		for (i = 0; i < n; i++)		/* У этого графа n узлов */
			if(dist[k][i] != 0 && state[i].label == tentative) {
				if(state[k].length + dist[k][i] < state[i].length) {
					state[i].predecessor = k;
					state[i].length = state[k].length + dist[k][i];
				}
			}
		/* Поиск узла, помеченного как предварительный с наименьшей меткой */
		k = 0;
		min = INFINITY;
		for(i = 0; i < n; i++)
			if(state[i].label == tentative && state[i].length < min) {
				min = state[i].length;
				k = i;
			}
		state[k].label = permanent;
	} while(k != s);
	/* Копирование пути в выходной массив */
	i = 0;
	k = s;
	do {
		path[i++] = k;
		k = state[k].predecessor;
		std::cout << "path " << i-1 << " = " << path[i-1] << std::endl;
	} while(k >= 0);
}

int main()
{
	int path_tmp[5];
	std::cout << "Введите число узлов в графе" << std::endl;
	std::cin >> n;
	std::cout << "n = " << n << std::endl;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			std::cout << "Введите расстояние от i до j, i и j - номера узлов" << std::endl;
			std::cout << "i = " << i << " j = " << j << std::endl;
			std::cin >> dist[i][j];
			dist[j][i] = dist[i][j];
		}
	}

	shortest_path(0, 4, path_tmp);
	return 0;
}
