///             ASSIGNMENT 3 QUESTION 2

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N= 10e5;
 int parent[N];
int RANK[100];
int x=1;
void make_set(int v) { //making set
    parent[v] = v; 
    RANK[v] = 0;
}

int find_set(int v) { // finding a particular value in the set
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) { // taking usnion of the sets by rank
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
       if (RANK[a] < RANK[b])
            swap(a, b);
        parent[b] = a;
        if(RANK[a]==RANK[b])
       RANK[a] = RANK[a]+ 1;
    }
}


int main() {
    char c;
    int x,n,m,prev,cur,ans,ans1,x1,flag=0;
	// your code goes here
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
        /*cin>>c;
cout<<c<<" ";*/
        cin>>c;
//cout<<c<< " ";
        if(c=='u')
        {
            /*cin>>c;
cout<<c<< " ";*/cin>>c;
//cout<<c<< " ";
cin>>c;
//cout<<c<< " ";
cin>>c;
//cout<<c<< " ";
cin>>c;
//cout<<c<< " ";
            
            cin>>cur;

            //cout<<cur<<"*";
                                 make_set(cur);
            cin>>x;
           // cout<<x<<"*";
                     make_set(x);
                     if(flag==1)
            union_sets(prev, cur);
                     flag=1;
                     prev=cur;

        }
        if(c=='g')
        {
            cin>>c>>c;
            cin>>x;

            cin>>x1;
             //ans1= find_set(x1);
            if(x!=0&&x1!=0)
            {if ( find_set(x1)==0 || find_set(x)==0) // if the value is not found it gives the ans zero
     cout<<"NO"<<endl;
     else
     cout<<"YES"<<endl;}
            
        //cases when if the value to be found is itself zero
        else if(x==0&&x1!=0) 
            {if ( find_set(x1)!=0 && find_set(x)==0) 
     cout<<"YES"<<endl;
     else
     cout<<"NO"<<endl;
            
        }
        
        else if(x1==0&&x!=0)
            {if ( find_set(x)!=0 && find_set(x1)==0) 
     cout<<"YES"<<endl;
     else
     cout<<"NO"<<endl;
            
        }
        
        else if(x==0&&x1==0)
            {if ( find_set(x1)==0 && find_set(x)==0) 
     cout<<"YES"<<endl;
     else
     cout<<"NO"<<endl;
            
        }
	}
	}
	return 0;
}
