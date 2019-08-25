#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

string toMin(string);

int main() {
	map<string, int> repeats;
	vector<string> words;
	string str, lsort;
    while (cin >> str && str[0] != '#') {
        words.push_back(str);
		lsort = toMin(str);
        if (!repeats.count(lsort)) repeats[lsort] = 1;
		else repeats[lsort]++;
    }
	sort(words.begin(), words.end());

    for (int i = 0; i < words.size(); i++)
        if (repeats[toMin(words[i])] == 1)
            cout << words[i] << endl;
			
	return EXIT_SUCCESS;
}

string toMin(string str){
	string temp = str;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	sort(temp.begin(), temp.end());
	return temp;
}