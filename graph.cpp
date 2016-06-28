/*
 * This is a free program to show working and implementation of a simple
 * Breadth First Search and Depth first search in CPP
 *
 * You are free to use it however as you want.
 *
 * Author doesnt hold responsibility to this code
 *
 * Author : Sidhin S Thomas
 * email: sidhin.thomas@gmail.com
 */

#include <iostream>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class graph{
    private:
    int v ;
    list<int> *adj ;
    public:
    graph(int n){
        v = n ;
        adj = new list<int>[n];
    }
    void addEdge(int a, int b);
    void printBFS(int n);
    void printDFS(int n);
};
void graph::addEdge(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void graph::printBFS(int n){
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[v] = false ;
    }
    queue<int> s;
    visited[n] = true ;
    s.push(n);
    list<int>::iterator i ;
    while(!s.empty()){
        int t = s.front();
        s.pop();
        cout << t << " ";
        for(i = adj[t].begin(); i!=adj[t].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                s.push(*i);
            }
        }
    }
}
void graph::printDFS(int n){
    bool *visited = new bool[v];
    for(int i=0; i<v; ++i)
        visited[i] = false ;
    stack<int> s ;
    s.push(n);
    visited[n] = true ;
    list<int>::iterator i;
    while(!s.empty()){
        n = s.top();
        s.pop();
        cout << n << " " ;
        for(i = adj[n].begin(); i!=adj[n].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true ;
                s.push(*i);
            }
        }
    }
}
int main(){
    graph g(10) ;
    int n ,a,b ;
    cin >> n ;
    while(n-->0){
        cin >> a >> b ;
        if(a<10 && b < 10){
            g.addEdge(a,b);
        }
        else{
            cout << "Out of bound";
            n++;
        }
    }
    cin >> a ;
    g.printBFS(a);
    cout << endl ;
    g.printDFS(a);
}