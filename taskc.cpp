#include <iostream>
#include <vector>

using namespace std;

class disjoint_set_union
{
    int* parent;
    int* rank;

public:
    disjoint_set_union(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unionn(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

/*class road
{
public:
    int from;
    int to;
    double distance;
};*/

void sort( road *ps, int n )
{
    for( int i = 0 ; i < n ; i ++ )
    {
        for(int j = 0 ; j < n - i - 1 ; j ++ )
        {
            if( ps[j].distance > ps[j+1].distance )
            {
                road temp = ps[j];
                ps[j] = ps[j+1];
                ps[j+1] = temp;
            }
        }
    }
}

void kruskals_mst(road roads[], int n_p, int n_r)
{
    sort( roads, n_r );
    disjoint_set_union s(n_p);
    vector<road> graph;
    double shortestpathlength = 0;
    for (int i=0; int(graph.size()) != n_p-1 && i < n_r; i++)
    {
        if (s.find(roads[i].from) != s.find(roads[i].to))
        {
            s.unionn(roads[i].from, roads[i].to);
            graph.push_back(roads[i]);
            shortestpathlength += roads[i].distance;
        }
    }
    cout<<"Road length required for reconstruction: "<<shortestpathlength<<endl;
    for(int i=0; i<int(graph.size()); i++)
    {
        cout<<"from: "<< char(graph[i].from + 65) << " to: " << char(graph[i].to + 65 ) << " \n ";
    }
    cout<<endl;
}
void InfoFromUser()
{
    int numberofroads;
    cout << "enter number of roads: "; cin >> numberofroads;
    int numberofplaces;
    cout << "enter number of places: "; cin >> numberofplaces;
    road roads[numberofroads];

    for( int i = 0; i < numberofroads ; i ++ )
    {
        cout << "from: "; cin >> roads[i].from;
        cout << "\nto: "; cin >> roads[i].to;
        cout << "\ndistance: "; cin >> roads[i].distance;
        cout << "\n";
    }

    kruskals_mst(roads, numberofplaces, numberofroads);
}
void infoFromFile()
{
    ifstream inputFile;
    inputFile.open("test3.txt", ios::in);
    if (!inputFile)
    {
        cerr << "some thing wrong during opening file!" << endl;
        exit(1);
    }
    int numberofroads;
    inputFile >> numberofroads;
    road roads[numberofroads];
    for (int i = 0; i < numberofroads; i++)
    {
        inputFile >> roads[i].from;
        inputFile >> roads[i].to;
        inputFile >> roads[i].distance;
    }
    int numberofplaces;
    inputFile >> numberofplaces;

    kruskals_mst(roads, numberofplaces, numberofroads);
}
void task_c()
{
    //InfoFromUser();
    infoFromFile();
}

