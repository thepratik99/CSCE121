#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
	vector<string> words;
    for (string s; cin >> s && s != "quit"; )
       words.push_back(s);

    for (decltype(words.size()) i = 0; i < words.size(); ++i)
       cout << words.at(i) << endl;

    return 0;
}