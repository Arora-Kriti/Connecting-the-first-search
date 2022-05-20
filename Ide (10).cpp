////////////////////      Question 4   /////////////////////////////////


#include "bits/stdc++.h"
using namespace std;
bool vis[1000];
vector <int > adj [1000];
int main()
{
    int s;
    cin>>s;
    int flag=0;
    vector<int>p(1000); // this is for keeping record of parent of the current node
    int x,y;
    for(int i=0;i<1000;i++)
    {
        vis[i]=0;
        p[i]=-1;
    }
    
   
    int n,m;
    cin>>n>>m; 
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }
    queue <int>q;
    q.push(s);                // adds s to be the first element
    vis[s]=true;
    while(!q.empty()&&flag!=1)
    {
        int node=q.front();
        q.pop();
        vector<int>::iterator it;
        for( it=adj[node].begin();it!=adj[node].end();it++)  // in order to check the neighbours of the current node
        {
            if(!vis[*it])
            {   if(vis[*it]==0)
                vis[*it]=1;
                else
                cout<<"CYCLE";
                q.push(*it);
                if(p[*it]==-1)
                p[*it]=node;
                else{
                cout<<"CYCLE";
                    flag=1;
                            }
            }
        }
    }
    if(flag!=1)
    {
        cout<<"NOT A CYCLE";
        }
    return 0;
}
