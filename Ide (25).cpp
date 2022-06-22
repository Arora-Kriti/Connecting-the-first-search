//// Ques 1 of Assignment 4
#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int source, destination, weight;
};
struct Graph {
	int V, E;
	struct Edge* edge;
};
struct Graph* tst(int V, int E)
{
	   struct Graph* graph = new Graph;
	graph->V = V;
	         graph->E = E;
	  graph->edge = new Edge[graph->E];
	return graph;
}
         bool func(struct Graph* graph,int source)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[source] = 0;
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].source;
			int v = graph->edge[j].destination;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].source;
		int v = graph->edge[i].destination;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			return true;
	}

	return false;
}
int main()
{	int n,m;
	cin>>n>>m;
	struct Graph* graph = tst(n,m);
for(int i=0;i<m;i++)
{
   cin>> graph->edge[i].source ;
cin>>	graph->edge[i].destination ;
cin>>	graph->edge[i].weight;
}
	
	if (func(graph, 0))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
