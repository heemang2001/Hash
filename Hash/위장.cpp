#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 1;
	unordered_map<string, int> hashClothes;

	for (int i = 0; i < clothes.size(); i++)
	{
		hashClothes[clothes[i][1]]++;
	}

	for (auto iter = hashClothes.begin(); iter != hashClothes.end(); iter++)
	{
		answer *= iter->second + 1; // +1�� ������ ���ϴ� ���
	}

	//test
	//for (auto elem : hashClothes)
	//{
	//	cout << "key : " << elem.first << " value : " << elem.second << endl;
	//}

	

	return answer - 1; // -1�� �ƹ��͵� ���������ʴ� ��츦 ����
}

int main()
{
	cout << solution({ {"yellowhat", "headgear"} ,{"bluesunglasses", "eyewear"},{"green_turban", "headgear"} }) << '\n';	// 5
	cout << solution({ {"crowmask", "face"} ,{"bluesunglasses", "face"},{"smoky_makeup", "face"} }) << '\n';				// 3

	return 0;
}