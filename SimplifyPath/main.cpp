/*
* Simplify Path
* Date: 2015/10/29
* Tag: stack, string
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		int len = path.length();
		if (len == 0) return "";
		vector<string> dirs;
		string tmp;
		path.push_back('/');
		for (int i = 0; i<len + 1; i++) {
			if (path[i] != '/') {
				tmp.push_back(path[i]);
				continue;
			}
			if (tmp.empty()) {
				if (dirs.empty() || dirs.back() != "/") dirs.push_back("/");
			}
			else {
				if (tmp == "..") {
					if (dirs.size() > 1) dirs.pop_back();
					if (dirs.size() > 1) dirs.pop_back();
				}
				else if (tmp != ".") {
					dirs.push_back(tmp);
					dirs.push_back("/");
				}
				tmp.clear();
			}
		}
		if (dirs.size() > 1) dirs.pop_back();
		ostringstream buf;
		for (string ss : dirs) buf << ss;
		return buf.str();
	}
};

int main()
{
	Solution s;
	cout << "/... is " << s.simplifyPath("/...") << endl;
	cout << "/a/./b/../../c/ is " << s.simplifyPath("/a/./b/../../c/") << endl;
	cout << "/../ is " << s.simplifyPath("/../") << endl;
	cout << "/home//foo/ is " << s.simplifyPath("/home//foo/") << endl;

	return 0;
}