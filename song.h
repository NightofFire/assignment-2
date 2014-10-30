#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Song{
private:
	stringstream ss;
	string sstream;
	vector<string> name;
	vector<string> artist;
	vector<string> album;
	vector<string> genre;
	vector<string> size;
	vector<string> time;
	vector<string> year;
	vector<string> comments;
	//vector<string> eightWord;
	vector<string> songDatabase;
public:
	Song();
	~Song();
	void print(ostream& stream,string text);
	void readSongList(int argc, char* argv[], ostream& error = cout, ostream& out = cout);
	vector<string> &getName();
	vector<string> &getArtist();
	vector<string> &getAlbum();
	vector<string> &getGenre();
	vector<string> &getSize();
	vector<string> &getTime();
	vector<string> &getYear();
	vector<string> &getComments();
	vector<string> &getSongDatabase();
};
#endif