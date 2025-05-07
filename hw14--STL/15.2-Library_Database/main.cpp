#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <vector>
using namespace std;
struct cmp {
	bool operator()(pair<string , string > pair1, pair<string, string> pair2) {
		if (pair1.second == pair2.second) {
			return pair1.first < pair2.first;
		}
		return pair1.second < pair2.second;
	}
};//??????????
int main() {
	string line;
	typedef pair<string, string> key;
	map<key,set<int>> data;//key:title,author
	while (getline(cin, line)) {
		string title,author;
		int edition;
		stringstream lineSS(line);
		string cmd;
		getline(lineSS, cmd, '\"');
		if (cmd == "Insert ") {
			getline(lineSS, title, '\"');
			getline(lineSS, author, '\"');
			getline(lineSS, author, '\"');
			lineSS >> edition;
			key pairTemp(title, author);
			if (data.count(pairTemp) == 1&&data[pairTemp].count(edition) == 1) {
				cout << "Datum already exist.\n";
				continue;
			}
			data[pairTemp].insert(edition);
			cout << "Insert "<<author<<"'s "<<title<<", Edition: "<<edition<<".\n";
		}
		else if (cmd == "Delete Edition ") {
			getline(lineSS, title, '\"');
			getline(lineSS, author, '\"');//blank
			getline(lineSS, author, '\"');
			lineSS >> edition;
			key pairTemp(title, author);
			if (data.count(pairTemp)==0||data[pairTemp].count(edition) == 0) {
				cout << "Datum doesn't exist.\n";
				continue;
			}
			data[pairTemp].erase(edition);
			cout << "Delete " << author << "'s "<<title<<", Edition: " << edition << ".\n";
		}
		else if (cmd == "Delete Book ") {
			getline(lineSS, title, '\"');
			getline(lineSS, author, '\"');//blank
			getline(lineSS, author, '\"');
			key pairTemp(title, author);
			if (data.count(pairTemp) == 0 ) {
				cout << "Book doesn't exist.\n";
				continue;
			}
			data.erase(pairTemp);//****
			cout << "Delete " << author << "'s "<<title<<"."<<endl;
		}
		else if (cmd == "Find Book ") {
			getline(lineSS, title, '\"');
			getline(lineSS, author, '\"');
			getline(lineSS, author, '\"');
			key pairTemp(title, author);
			if (data.count(pairTemp) == 0) {
				cout << "Book doesn't exist.\n";
				continue;
			}
			cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: editions ";
			set<int>::iterator p;
			for (p = data[pairTemp].begin(); p != data[pairTemp].end(); p++) {
				cout << *p << ", ";
			}
			puts("");
		}
		else if (cmd == "Find Author ") {
			getline(lineSS, author, '\"');
			vector<string> titles;
			map<key, set<int>>::iterator p;
			int count = 0;
			for (p = data.begin(); p != data.end(); p++) {
				if (p->first.second == author) {
					titles.push_back(p->first.first);
					count++;
				}
			}
			if (count == 0) {
				cout << "No book found.\n";
				continue;
			}

			cout << author << "'s Books: ";
			for (int i = 0; i < titles.size(); i++) {
				cout << titles[i] << " ";
			}
			puts("");
		}
		else if (cmd == "Sort by Title") {
			map<key, set<int>>::iterator pData;
			set<int>::iterator pEdition;
			for (pData = data.begin(); pData != data.end(); pData++) {
				cout << "Title: " << pData->first.first << "\tAuthor: "<<pData->first.second << "\tEdition: ";
				for (pEdition = pData->second.begin(); pEdition != pData->second.end(); pEdition++) {
					if (pEdition == pData->second.begin()) cout << *pEdition;
					else cout << ", " << *pEdition;
					
					}
				puts("");
			}
			
		}
		else if (cmd == "Sort by Author") {
			map<key, set<int>, cmp> data2(data.begin(), data.end());
			map<key, set<int>>::iterator p;
			set<int>::iterator pEdition;
			for (p = data2.begin(); p != data2.end(); p++) {
				cout << "Title: " << p->first.first << "\tAuthor: "<<p->first.second << "\tEdition: ";
				for (pEdition = p->second.begin(); pEdition != p->second.end(); pEdition++) {
					
					if (pEdition == p->second.begin()) cout << *pEdition;
					else cout << ",  " << *pEdition;
				}
				puts("");
			}
		}
		else {
			cout << "Unknown command" << endl;
		}
	}
    return 0;
}