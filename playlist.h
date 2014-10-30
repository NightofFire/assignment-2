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
	void displayMenu();
	void listPlaylist();
	void view(const vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&);
	bool create();
	void modify(string, const vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&);
	void deletePlaylist(string);
	void save(string, ofstream&);
	void help();
};
#endif