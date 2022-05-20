///////////////////////    Question 2 ///////////////////////////
#include "bits/stdc++.h"
using namespace std;

bool vis[1000];
vector <int > adj [1000];
int main()
{
    vector<int>d(1000); // this is for keeping record of distance between current node and source vertex
    int x,y;
    for(int i=0;i<1000;i++)
    {
        vis[i]=0;
    }
    int s,ss;  //s is the source vertex and ss is the node whose distance from the source vertex is to be measured
    
    cin>> s>> ss;
    int n,m;
    cin>>n>>m; 
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }
    queue <int>q;
    q.push(s);    // adds s to be the first element
    vis[s]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        vector<int>::iterator it;
        for( it=adj[node].begin();it!=adj[node].end();it++)  // in order to check the neighbours of the current node
        {
            if(!vis[*it])
            {
                vis[*it]=1;
                q.push(*it);
                d[*it]=d[node]+1;
                if(ss==*it) // if the cuurent node is the one which is to be found 
                cout<<d[*it];
            }
        }
    }
    return 0;
}
