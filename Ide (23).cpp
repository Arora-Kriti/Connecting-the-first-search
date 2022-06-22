///Question 2
#include <bits/stdc++.h>
using namespace std;


struct edges {
	int source, destination, weight;
};


struct Graph {
	int V, E;

	struct edges* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new edges[graph->E];
	return graph;
}


bool call(struct Graph* graph,
						int source, int n)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[source] = 0;
    
    int u = graph->edge[0].source;
    dist[u]=0;
	for (int i = 0; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].source;
			int v = graph->edge[j].destination;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight <= dist[v]){
				dist[v] = dist[u] + weight;
            }
		}
	}
    int c=0;
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].source;
			int v = graph->edge[j].destination;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight == dist[v]&& v==n){
				c++;
            //}
		}
	}
    int min=INT_MAX;
    int max=-INT_MAX;
    int prev=graph->edge[0].source;
    int end =graph->edge[n].source;
    int org=prev;
    int curr,count=0;
    for (int i = 0; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].source;
			int v = graph->edge[j].destination;
			int weight = graph->edge[j].weight;
            curr=u;

			if (dist[u] != INT_MAX && dist[u] + weight <= dist[v]){
                     
                     if(v==n)
                     {
                        if(count<min&&count!=0)
                        min=count;
                        if(count>max)
                        max=count;
                     }
                    if(curr==org)
                      count=0;
				count++;

            }
		}
	}
    cout<< dist[n]<<" "<<c<<" "<<min<<" "<<max;
    
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].source;
		int v = graph->edge[i].destination;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
			return true;
        }
	}

	return false;
}

int main()
{
	int n ;
	int m ; 
    cin>>n>>m;
	struct Graph* graph = createGraph(n,m);
      for(int i=0;i<m;i++){
        
	cin>>graph->edge[i].source ;
	cin>>graph->edge[i].destination;
	cin>>graph->edge[i].weight;
      }
		call(graph, 0,n);
		

	return 0;
}
