#include<iostream> 
#include<string>
#include<cstring>
#include<queue>
using namespace std;
const int nMax = 500;
struct Node
{
	char str1[100];
	char str2[100];
}cat[nMax], dog[nMax];
int cat_num, dog_num;
int map[nMax][nMax];
int useif[nMax];
int link[nMax];
int c, d, v;
queue<int> res;
int can(int t)
{
	for (int i = 0; i < dog_num; i++)
	{
		if (!useif[i] && map[t][i])
		{
			useif[i] = 1;
			if (link[i] == -1 || can(link[i]))
			{
				link[i] = t;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int T;
	cin >> T;
	
	while (T--)
	{
		memset(map, 0, sizeof(map));
		cat_num = dog_num = 0;
		cin >> c;
		cin >> d;
		cin >> v;
		for (int i = 0; i < v; i++)
		{
			string a;
			string b;
			cin >> a;
			cin >> b;
			if (a[0] == 'C')
			{
				strcpy(cat[cat_num].str1, a.c_str());
				strcpy(cat[cat_num].str2, b.c_str());
				cat_num++;
			}
			else
			{
				strcpy(dog[dog_num].str1, a.c_str());
				strcpy(dog[dog_num].str2, b.c_str());
				dog_num++;
			}
		}
		for (int i = 0; i < cat_num; i++) {
			for (int j = 0; j < dog_num; j++) {
				if (!strcmp(cat[i].str1, dog[j].str2) || !strcmp(cat[i].str2, dog[j].str1)) {
					map[i][j] = 1;
				}
			}
		}
			
		int ans = 0;
		memset(link, -1, sizeof(link));
		for (int i = 0; i < cat_num; i++)
		{
			memset(useif, 0, sizeof(useif));
			if (can(i)) {
				ans++;
			}
		}
		res.push(v-ans);
	}

	while (!res.empty())
	{
		int t = res.front();
		cout << t << endl;
		res.pop();
	}
	//system("pause");
	return 0;
}