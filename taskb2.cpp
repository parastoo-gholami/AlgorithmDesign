#include <iostream>
#include <cstring>
using namespace std;
const int N = 6;//change...andis
int final_path[N+1];
bool visited[N];
bool shouldnt[N];
int final_res = INT_MAX;


void copyToFinal(int curr_path[] , int l)
{
    for (int i=0; i<=l; i++)
        final_path[i] = curr_path[i];
    final_path[l+1] = curr_path[0];
}
//baraye mohasebe bound
int firstMin(int adj[N][N], int i)
{
    if(shouldnt[i] == false)
        return 0;
    int min = INT_MAX;
    for (int k=0; k<N; k++)
        if (adj[i][k]<min && adj[i][k] !=0 && shouldnt[k])
            min = adj[i][k];
    return min;
}

void TSPRec(int adj[N][N], int curr_bound, int curr_weight,int level, int curr_path[], int l, int start)
{

    //peymayesh takmil ast
    if (level==l+1)
    {
        //baresi tavanaE residn az ras akhr entekhabi b ras shoro
        if (adj[curr_path[level-1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + adj[curr_path[level-1]][curr_path[0]];
            //dr sorati k javab min bashd b onvan javab nahaE ta konon zakhire mishavad
            if (curr_res < final_res)
            {
                copyToFinal(curr_path , l);
                final_res = curr_res;
            }
        }
        return;
    }

    for (int i=0; i<N; i++)
    {
        // agar betavan az rase ghabli b en ras raft va ghablan peymayesh nashode bashd
        if (adj[curr_path[level-1]][i] != 0 && visited[i] == false)
        {
            int temp = curr_bound;
            //meghdar masafat ta enja
            curr_weight += adj[curr_path[level-1]][i];
            //km krdn meghdar pish farz ghabli , ezafe kardan meghdare dorost feli
            curr_bound = curr_bound - firstMin(adj, curr_path[level-1]) + adj[curr_path[level-1]][i];

            // min halat ta enja agar az min kamtr bashad ba hamin maghadir edame midahim
            if (curr_bound < final_res)
            {
                //masir in level moshkhas mishavad
                curr_path[level] = i;
                visited[i] = true;
                TSPRec(adj, curr_bound, curr_weight, level+1,curr_path, l, start);
            }

            // bound va weight b halate ghabli barmigardd
            curr_weight -= adj[curr_path[level-1]][i];
            curr_bound = temp;

            //visited tanzim mishavad :
            //1.hame ras ha peymayesh nashode farz shode
            //2.rashaE k ta level ghabl peymayesh shode ra peymayesh shode mikonim
            //3.anhae k nabayad peymayesh shavand ra peymayesh shode farz mikonim
            memset(visited, false, sizeof(visited));
            for (int j=0; j<=level-1; j++)
                visited[curr_path[j]] = true;
            for(int z = 0;z<N;z++)
            {
                if(shouldnt[z] == false)
                    visited[z]= true;
            }
        }
    }
}

//shoro ba ras start
void TSP(int adj[N][N], int start, int l)
{
    int curr_path[N+1];
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    for (int i=0; i<N; i++)
        curr_bound += (firstMin(adj, i));
    curr_path[0] = start;
    TSPRec(adj, curr_bound, 0, 1, curr_path, l, start);
}


void print(int l )
{
    cout<<"Minimum cost : "<<final_res<<endl;
    cout<<"Path Taken : ";
    for (int i=0; i<l+2; i++)
        cout<<char(final_path[i]+65)<<" ";
    cout<<endl;
}

int task_b_2()
{
    int n, num, m;
    cout<<"number of vertexes: ";
    cin>>n;
        cout<<"number of vertexes that must pass: ";
    cin>>num;
    char x,y;

    // hame ras ha peymayesh shode dr nzr migirim
    // farz mishavad az hich rasi nabayad gozar konim
    memset(visited, true, sizeof(visited));
    memset(shouldnt, false, sizeof(shouldnt));

    // tedad rashaE k  beyne ras 1 va khodash gharar migirand
    int l = num;

    //ras haE k bayad peymayesh shavand
    //1.hanoz peymayesh nashode dr nzr migirim: visited
    //2.bayad gozar konim: shouldnt

    for(int i = 1;i<=num;i++)
    {
        cout<<i<<": ";
        cin>>x;
        visited[x-65] = false;
        shouldnt[x-65]=true;
    }

    //gereftan maghadir matris havi tool yalha
    int adj[N][N]={0};
    cout<<"number of edges: ";

    cin>>num;
    cout<<"Enter all edges(A B 2)"<<endl;

    while(num--)
    {
        cin>>x>>y;
        cin>>m;
        adj[x-65][y-65] = m;
        adj[y-65][x-65] = m;
    }


    //noghte shoro va shouldnt true mishavad chon bayad peymayesh shavad
    cout<<"Enter start vertex: ";
    cin>>x;
    int start = x-65;
    shouldnt[start] = true;

    TSP(adj, start, l);
    print(l);

    return 0;
}


//10
//3 D E G
//23
//A B 3
//A F 9
//B C 2
//B E 9
//F E 8
//C D 2
//C G 9
//E G 7
//E I 9
//D H 20
//G I 5
//H J 9
//A D 6
//B D 4
//B F 9
//F C 16
//F J 18
//C E 8
//E D 11
//E J 10
//D G 9
//G H 4
//H I 1
//C


//6
//3 B E F
//10
//A B 5
//A C 5
//A E 2
//A F 4
//B D 1
//B F 4
//C E 6
//C D 2
//D E 4
//E F 1
//D
