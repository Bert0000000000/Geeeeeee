#include<iostream>
#include<queue>
#include<string>
using namespace std;

int N, M;//kuan = x   chang = y
int a[1000][1000];
int f(int x, int y);
int dir_x[] = { 0, 1, 0, -1 };
int dir_y[] = { 1, 0, -1, 0 };
int cur_x;
int cur_y;
int length = 0;
struct Node
{
	int x;
	int y;
};
int main(void)
{
	//int kuan = 0, chang = 0;
	int onecount = 0;
	int othercount = 0;
	cin >> N;
	cin >> M;
	//vector<int[]> list = new vector < int[] >() ;
	int i = 0;

	for (i = 0; i < N; i++)
	{
		//char *str = (char *)malloc(sizeof(char)*M);
		string str;
		cin >> str;
		////cout << str << endl;
		for (int j = 0; j < M; j++)
		{
			int temp = str[j] - '0';
			a[i][j] = temp;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//cout << a[i][j];
		}
		//cout << endl;
	}
	//cout << endl;

	for (i = 0; i < N; i++){
		length += f(i, 0);
	}
	for (i = 0; i < N; i++){
		length += f(i, M - 1);
	}
	for (i = 0; i < M; i++){
		length += f(0, i);
	}
	for (i = 0; i <M; i++){
		length += f(N - 1, i);
	}
	cout << length << endl;
	return 0;
}

int f(int x, int y)
{

	int l = 0;
	Node now;
	if (a[x][y] == 1){
		return 1;
	}
	if (a[x][y] == 2){
		return 0;
	}
	queue<Node> q;
	Node node;
	node.x = x;
	node.y = y;
	a[x][y] = 2;
	//cout<<"HHH"<<x<<" "<<y<<endl;
	q.push(node);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			cur_x = now.x + dir_x[i];
			cur_y = now.y + dir_y[i];
			if ((cur_x >= 0) && (cur_x<N) && (cur_y >= 0) && (cur_y<M))
			{
				if (a[cur_x][cur_y] == 1 || a[cur_x][cur_y] == 3)
				{
					//cout<<cur_x<<" "<<cur_y<<endl;
					l++;
				}
				if (a[cur_x][cur_y] == 0)
				{
					Node tem;
					tem.x = cur_x;
					tem.y = cur_y;
					a[cur_x][cur_y] = 2;
					q.push(tem);
				}
			}
		}
	}
	//	//cout<<endl;
	/*	for (int i = 0; i < N;i++)
	{
	for (int j = 0; j < M;j++)
	{
	//cout << a[i][j];
	}
	//cout << endl;
	}
	*/
	//	//cout << endl;

	//	//cout<<l<<endl;
	return l;

}
