#include <iostream>
#include <fstream>
#define V 10
#define INF 0x3f3f3f3f
int adj[V][V]={{0}};
int shortestpathlength;

using namespace std;

class road
{
public:
    int from;
    int to;
    double distance;
};
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    int mn = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= mn)
            mn = dist[v], min_index = v;

    return min_index;
}

void dijkstra( int src, int dst)
{
    int dist[V];

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && adj[u][v] && dist[u] != INT_MAX
                    && dist[u] +adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }

    shortestpathlength=dist[dst];
}

void DFSUtil(int u, int d, bool visited[], int path[], int& path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then check
    if (u == d)
    {
        int pathlength = 0;
        for (int i = 0; i < path_index - 1; i++)
            pathlength += adj[ path[ i ] ][ path[ i + 1 ] ];
        if( pathlength == shortestpathlength )
        {
            cout << "*path : \n";
            for(int i=0; i < path_index - 1; i++)
                cout << "from: " << char(path[ i ] + 65) << " to: " << char( path[ i + 1 ] + 65 ) << "\n";
        }

    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        for (int i = 0; i < V; ++i)
            if ( adj[u][i] != 0 && !visited[i] )
                DFSUtil(i, d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

void DFS(int s, int d)
{
    bool visited[V];

    // Create an array to store paths
    int path[V];
    int path_index = 0;

    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(s, d, visited, path, path_index);
}
void info_from_user()
{
    int numberofroads;
    cout << "enter number of roads: "; cin >> numberofroads;
    for( int i = 0; i < numberofroads ; i ++ )
    {
        int from;
        int to;
        int distance;
        cout << "from: "; cin >> from;
        cout << "\nto: "; cin >> to;
        cout << "\ndistance: "; cin >> distance;
        cout << "\n";
        adj[from][to] = distance;
        adj[to][from] = distance;
    }
    int source;
    int destiny;
    cout<<"enter source: ";cin>>source;
    cout<<"\nenter destiny: "; cin>>destiny;
    dijkstra(0, destiny);
    cout<<"shortest path length : "<<shortestpathlength<<endl;
    DFS(source, destiny);
}

void info_from_file()
{
    ifstream inputFile;
    inputFile.open("testb1.txt", ios::in);
    if (!inputFile)
    {
        cerr << "some thing wrong during opening file!" << endl;
        exit(1);
    }
    int numberofroads;
    int from;
    int to;
    int distance;
    inputFile >> numberofroads;
    for (int i = 0; i < numberofroads; i++)
    {
        inputFile >> from;
        inputFile >> to;
        inputFile >> distance;
        adj[from][to] = distance;
        adj[to][from] = distance;
    }
    int source;
    int destiny;
    inputFile >> source;
    inputFile >> destiny;
    dijkstra(0, destiny);
    cout<<"shortest path length : "<<shortestpathlength<<endl;
    DFS(source, destiny);
}

void task_b_1()
{
    //info_from_user();
    info_from_file();
}

