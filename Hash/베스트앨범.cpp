#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

bool cmp(pair<string, pair<int, int>> t1, pair<string, pair<int, int>> t2)
{
	if (t1.first == t2.first)
	{
		return t1.second.second > t2.second.second;
	}

	return t1.first < t2.first;
}

bool cmp2(pair<string, int> t1, pair<string, int> t2)
{
	//if (t1.first == t2.first)
	//{
	//	return t1.second > t2.second;
	//}

	return t1.second > t2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	
	multimap<string, pair<int, int>> mmapGenres;
	map<string, int> mapGenres;

	for (int i = 0; i < genres.size(); i++)
	{
		mmapGenres.insert({ genres[i], make_pair(i, plays[i])});
	}

	vector<pair<string, pair<int,int>>> vecFinal(mmapGenres.begin(), mmapGenres.end());
	sort(vecFinal.begin(), vecFinal.end(), cmp);

	for (auto iter = mmapGenres.begin(); iter != mmapGenres.end(); iter++)
	{
		mapGenres[iter->first] += iter->second.second;
	}

	vector<pair<string, int>> vecFinal2(mapGenres.begin(), mapGenres.end());
	sort(vecFinal2.begin(), vecFinal2.end(), cmp2);

	for (int i = 0; i < vecFinal2.size(); i++)
	{		
		int nTwoCheck = 0;

		for (int j = 0; j < vecFinal.size(); j++)
		{
			if (vecFinal[j].first == vecFinal2[i].first)
			{
				if (nTwoCheck >= 2)
				{
					break;
				}

				nTwoCheck++;
				answer.push_back(vecFinal[j].second.first);
			}
		}
	}	

	return answer;
}

int main()
{
	vector<int> vecAnswer = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";	// 4, 1, 3, 0
	}

	return 0;
}