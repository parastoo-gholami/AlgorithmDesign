#include <iostream>
using namespace std;
int mn= INT_MAX;
int ans[1000];
struct Node
{
    int x, y;//khali
    int level = 0;
public:
    int mat[100][100]={{0}};
};
Node* newNode(int mat[100][100], int x, int y, int newX, int newY, int level)
{
    Node* node = new Node;
    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->level = level;
    node->x = newX;
    node->y = newY;

    return node;
}
//x1 x2 y1 y2 dr mahdode bashad, harekat ghabli ra tekrar nakonim, machin dar anha bashd
int isSafe(int x1, int x2, int y1, int y2, int n, int m, int mat[100][100], int level, int arr[100])
{
    if(x1>=0 && x1<n && x2>=0 && x2<n && y1>=0 && y1<m && y2>=0 && y2<m)
    {
        if(level!=0)
            return (mat[x1][y1] == mat[x2][y2])&& mat[x1][y1]!=arr[level-1];
        return (mat[x1][y1] == mat[x2][y2]);
    }
    return false;
}
//yek ja bodn makan khali
bool solved(int x , int y , int ansx , int ansy)
{
    return x==ansx && y == ansy;
}

void solve(Node* node, int ansx, int ansy, int n , int m, int arr[100])
{
    if(solved(node->x, node->y, ansx, ansy))
    {
        //dr sorati k harekat kamtri rokh dad ja b ja mikonim
        if(mn>node->level)
        {
            mn = node->level;
            for(int i =0;i<mn;i++)
            {
                ans[i] = arr[i];
            }
            return;
        }
    }


    //4 halat darim baraye ja b jaE har kodam omidbakhsh bod satr badi ra ejad va masir ra zakhire va farakhani mikonim
    if (isSafe (node->x + 1,node->x + 2, node->y, node->y, n , m, node->mat,node->level, arr))
    {
        Node* child = newNode(node->mat, node->x, node->y, node->x + 2,node->y , node->level + 1);
        arr[node->level]=node->mat[node->x+1][node->y];
        solve(child, ansx, ansy, n , m, arr);

    }
    if (isSafe (node->x, node->x, node->y - 1, node->y - 2, n , m , node->mat, node->level, arr))
    {
        Node* child = newNode(node->mat, node->x, node->y, node->x,node->y - 2 , node->level + 1);
        arr[node->level]=node->mat[node->x][node->y-1];
        solve(child, ansx, ansy, n , m, arr);

    }
    if (isSafe (node->x - 1,node->x - 2, node->y,node->y, n , m , node->mat, node->level, arr))
    {
        Node* child = newNode(node->mat, node->x, node->y, node->x - 2,node->y , node->level + 1);
        arr[node->level]=node->mat[node->x-1][node->y];
        solve(child, ansx, ansy, n , m, arr);

    }
    if (isSafe (node->x, node->x, node->y + 1,  node->y + 2, n , m ,node->mat, node->level, arr))
    {
        Node* child = newNode(node->mat, node->x, node->y, node->x ,node->y + 2 , node->level + 1);
        arr[node->level]=node->mat[node->x][node->y+1];
        solve(child, ansx, ansy, n , m, arr);
    }
}

void print()
{
    if(mn == INT_MAX)
        cout<<"impossible"<<endl;
    else {
        cout<<mn<<endl;

        for(int i =0;i<mn;i++)
            cout<<ans[i]<<" ";
    }

}

void task_a()
{
    int  vorodi1, vorodi2, num, n ,m;
    bool flag=true;
    cout<<"enter length and width: ";
    cin>>n>>m;
    Node* child = new Node;

    for(int i=1;i<(n*m)/2;i++)
    {
        cout<<i<<": ";
        cin>>vorodi1>>vorodi2;
        child->mat[((vorodi1-1)/m)][((vorodi1-1)%m)] = i;
        child->mat[((vorodi2-1)/m)][((vorodi2-1)%m)] = i;
    }
    cout<<"camera: ";
    cin>>num;//dorbin;
    child->mat[((num-1)/m)][((num-1)%m)] = -1;
    int arr[100];
    for(int i = 0;i<n&&flag;i++)
        for(int j = 0;j<m&&flag;j++)
            if(child->mat[i][j] == 0)
            {
                child->x = i;
                child->y = j;
                flag =false;
            }
    cout<<"answer must be at: ";
    cin>> num;
    solve(child, (num-1)/m, (num-1)%m, n, m, arr);
    print();
}
//8 8
//1 2
//3 11
//4 12
//5 6
//7 8
//14 22
//15 23
//16 24
//17 25
//20 21
//26 27
//30 31
//32 40
//28 36
//29 37
//33 34
//38 39
//41 42
//35 43
//47 48
//44 52
//45 53
//50 51
//49 57
//54 62
//55 63
//56 64
//58 59
//60 61
//9 10
//18 19
//13
//14
