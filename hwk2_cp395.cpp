#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include <iomanip>
#include "song.h"
#include "playlist.h"
using namespace std;

int main(int argc, char* argv[])
{
	/*string testoo="ab";
	testoo.erase(testoo.end()-1,testoo.end());
	cout << testoo << endl;
	list<string> test1;
	test1.push_back("a");
	test1.push_back("b");
	test1.push_back("c");
	test1.push_back("d");
	test1.push_back("e");
	test1.push_back("f");
	list<string> test2;
	cout << "test 1 size = " << test1.size() << endl;
	cout << "test 2 size= " << test2.size() << endl;
	test2.splice(test2.begin(), test1);
	cout << "test 1 size = " << test1.size() << endl;
	cout << "test 2 size= " << test2.size() << endl;
	list<string>::iterator findIter = find(test2.begin(), test2.end(), "c");
	int test3 = distance(test2.begin(), findIter);
	cout << test3 << endl;
	cout << setw(5) << setfill('0') << 12 << endl;
	cout << "123456789012345678901234567890" << endl;
	cout << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;*/
	Song song;
	song.readSongList(argc, argv);
	Playlist playlist;
	playlist.help();
	//playlist.displayMenu();
	vector<string> name = song.getName();
	vector<string> artist = song.getArtist();
	vector<string> album = song.getAlbum();
	vector<string> genre = song.getGenre();
	vector<string> size = song.getSize();
	vector<string> time = song.getTime();
	vector<string> year = song.getYear();
	vector<string> comments = song.getComments();
	vector<string> songDatabase = song.getSongDatabase();
	cout << "artist size-"<<artist.size() << endl;
	string play;
	if (playlist.create())
	{
		playlist.modify(play, songDatabase, name, artist, album, time, year);
	}
	/*cout << "mod a playlist" << endl;
	getline(cin, play);
	playlist.modify(play, songDatabase, name, artist, album, time, year);
	cout << "mod a playlist" << endl;
	getline(cin, play);
	playlist.modify(play, songDatabase, name, artist, album, time, year);*/
	if (playlist.create())
	{
		playlist.modify(play, songDatabase, name, artist, album, time, year);
	}
	/*
	if (playlist.create())
	{
		playlist.modify(play, songDatabase, name, artist, album, time, year);
	}*/
	cout << "Delete a playlist" << endl;
	getline(cin, play);
	playlist.deletePlaylist(play);
	playlist.listPlaylist();
	playlist.view(songDatabase, name, artist, album, time, year);

	/*vector<string> vec2;
	vector<vector<string>> vec;
	vec.push_back({ "1", "2", "3" });
	cout << vec[0][2] << endl;
	vec.push_back({ "1", "2", "3","4" });
	cout << vec[1][3] << endl;
	cout << vec[0].size() << endl;
	list<string> li{ "the", "frogurt", "is", "also", "cursed" };
	list<string> li2{ "hey", "baby", "hello" };
	cout << *li.begin() << endl;
	cout << li.size() << endl;
	li.clear();
	cout << li.size() << endl;
	li2.splice(li2.end(), li);
	for (list<string>::iterator it = li2.begin(); it != li2.end(); it++)
	{
		cout << *it << endl;
	}
	cout << li2.size() << endl;
	vector<list<string>> hey;
	hey.push_back({ "1", "2", "3" });
	hey.push_back({ "1", "2", "3", "4" });
	cout << vec[1][3] << endl;*/
	list<string> list2[100];
	list<string>::iterator it;
	it = list2[0].begin();
	list2[0].push_back({ "hey"});
	list2[0].push_back("hey");
	list2[0].push_back("hey");
	cout << "size" << list2[0].size() << endl;
	for (it = list2[0].begin(); it != list2[0].end(); ++it)
	{
		cout << "list2" <<*it << endl; 
	}
	//list2.push_back({ "1", "2", "3", "4" });
	//list2.push_back({ "5", "6", "7", "8" });
	//cout << list2.size() << endl;
	//song.sayHello(cout,"hey");
	/*stringstream ss;
	string sstream;
	vector<string> name;
	vector<string> artist;
	vector<string> album;
	vector<string> genre;
	vector<string> size;
	vector<string> time;
	vector<string> year;
	vector<string> comments;
	vector<string> eightWord;
	cout << argv[0] << endl;
	cout << argc << endl;
	ifstream input;
	if (argc > 1)
		input.open(argv[1]);
	else
		input.open("songs.csv");
	if (input.fail())
	{
		cerr << "Unable to open file. " << endl;
		cerr << "This program will now exit. " << endl;
	}
	string word;
	if (input.good())
	{

	}
	else
	{
		cerr << "ERROR" << endl;
	}*/

	/*while (input.good())
	{
		if (word == "")
		{
			cerr << "ERROR" << endl;
		}
		input >> word;
		name.push_back(word);
		input >> word;
		artist.push_back(word);
		input >> word;
		album.push_back(word);
		input >> word;
		genre.push_back(word);
		input >> word;
		size.push_back(word);
		input >> word;
		time.push_back(word);
		input >> word;
		year.push_back(word);
		input >> word;
		comments.push_back(word);
	}*/
	/*for (int i = 0; i < name.size(); i++)
	{
		cout << name[i] << " " << artist[i] << " " << album[i] << " " << album[i] << " " << genre[i] << " " << size[i] << " " << time[i] << " " << comments[i]<< endl;
	}
	input.clear();
	input.seekg(0, ios::beg);

	getline(input, word);
	ss << word;
	while (ss >> sstream)
	{
		eightWord.push_back(sstream);
	}
	cout << eightWord.size() << endl;
	ss.clear();
	string d;
	ss << "hello";
	ss >> sstream;
	cout << sstream<< endl;
	//cout << word << endl;
	*/
	/*vector<string> a;
	a.push_back("");
	a.push_back("");
	a.push_back("");
	a.push_back("");
	a.push_back("");
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}*/
	return 0;
}