#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book)
{
	bool answer = true;
	unordered_map<string, int> hashPhone;

	for (int i = 0; i < phone_book.size(); i++)
	{
		hashPhone.insert({ phone_book[i], 1 });
	}

	for (int i = 0; i < phone_book.size(); i++)
	{
		string sTemp = phone_book[i];
		string sTemp2 = "";

		for (int j = 0; j < sTemp.size() - 1; j++)
		{
			sTemp2 += sTemp[j];

			if (hashPhone[sTemp2] == 1)
			{
				return false;
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution({ "119", "97674223", "1195524421" }) << '\n';   // false
	cout << solution({ "123","456","789" }) << '\n';				 // true
	cout << solution({ "12","123","1235","567","88" }) << '\n';		 // false

	return 0;
}