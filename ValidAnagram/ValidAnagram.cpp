/*
* Valid Anagram
* Date: 2015/11/4
* Tag: Hash table, sort
* Difficulty: Easy
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isAnagram(string s, string t) 
	{
		int items[26] = { 0 };
		for (int i = 0; i < s.length(); ++i)
		{
			++items[s[i] - 'a'];
			--items[s[i] - 'a'];
		}

		for (int i = 0; i < 26; ++i)
		{
			if (items[i] != 0)
				return false;
		}

		return true;
	}
};

int main()
{
	Solution solu;
	string s = "anagram";
	string t = "nagaram";
	cout << "valid anagram: " << solu.isAnagram(s, t) << endl;
	return 0;
}