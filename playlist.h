#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

class Playlist{
private:
	list<string> tempList;
	list<string> playList;
	list<string> playListNames;
	list<int> playListSize;
	list<string>::iterator it;
	vector<string>::iterator vit;
	bool newPlayList;
public:
	Playlist();
	~Playlist();
	void displayMenu(ostream& out = cout);
	void listPlaylist(ostream& error = cerr, ostream& out = cout);
	void view(string, const vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, ostream& error = cerr, ostream& out = cout);
	bool create(string, ostream& error = cerr, ostream& out = cout);
	void modify(string, const vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, ostream& error = cerr, ostream& out = cout);
	void deletePlaylist(string, ostream& error = cerr, ostream& out = cout);
	void save(string, ofstream&, vector<string>&, ostream& error = cerr, ostream& out = cout);
	void help(ostream& out = cout);
};
#endif