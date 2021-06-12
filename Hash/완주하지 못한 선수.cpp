#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";

	unordered_map<string, int> hashParticipant;

	for (int i = 0; i < participant.size(); i++)
	{
		hashParticipant[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++)
	{
		hashParticipant[completion[i]]--;
	}

	for (int i = 0; i < participant.size(); i++)
	{
		if (hashParticipant[participant[i]] > 0)
		{
			answer = participant[i];
			break;
		}
	}

	return answer;
}

int main()
{
	cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << '\n';	// leo

	return 0;
}