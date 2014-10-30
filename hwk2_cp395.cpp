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
	Song song;
	song.readSongList(argc, argv);
	Playlist playlist;
	vector<string> name = song.getName();
	vector<string> artist = song.getArtist();
	vector<string> album = song.getAlbum();
	vector<string> genre = song.getGenre();
	vector<string> size = song.getSize();
	vector<string> time = song.getTime();
	vector<string> year = song.getYear();
	vector<string> comments = song.getComments();
	vector<string> songDatabase = song.getSongDatabase();
	playlist.displayMenu();
	bool quit = false;
	string play;
	while (!quit)
	{
		string choice;
		string command;
		string arg1;
		int iarg1 = 0;
		getline(cin, choice);
		if (choice[0] == NULL || choice[0] == ' ' || choice[0] == '	')
		{
			cerr << "error" << endl;
			continue;
		}
		int pos = 0;
		int counter = 0;
		int found = choice.find(" ", pos);
		if (found == string::npos)
		{
			command = choice.substr(pos);
		}
		while (found != string::npos)
		{
			found = choice.find(" ", pos);
			//out << found << endl;
			if (counter == 0)
			{
				command = choice.substr(pos, found);
			}
			else if (counter == 1)
			{
				arg1 = choice.substr(pos, found - pos);
			}
			else
			{
				break;
			}
			pos = found + 1;
			counter++;
			//out << counter << endl;
		}
		if (command == "L" || command == "l")
		{
			playlist.listPlaylist();
		}
		else if (command == "V" || command == "v")
		{
			//getline(cin, play);
			playlist.view(arg1, songDatabase, name, artist, album, time, year);
		}
		else if (command == "C" || command == "c")
		{
			if (playlist.create(arg1))
			{
				playlist.modify(play, songDatabase, name, artist, album, time, year);
			}
		}
		else if (command == "M" || command == "m")
		{
			cout << "Enter the playlist you want to modify" << endl;
			playlist.modify(arg1, songDatabase, name, artist, album, time, year);
		}
		else if (command == "D" || command == "d")
		{
			playlist.deletePlaylist(arg1);
		}
		else if (command == "S" || command == "s")
		{
			ofstream myFile;
			playlist.save(arg1, myFile, name);
		}
		else if (command == "H" || command == "h")
		{
			playlist.help();
		}
		else if (command == "Q" || command == "q")
		{
			quit = true;
			exit(1);
		}
		else
		{
			cerr << "Invalid input" << endl;
		}
		playlist.displayMenu();
	}
	/*
	playlist.help();
	//playlist.displayMenu();
	cout << "artist size-"<<artist.size() << endl;
	if (playlist.create())
	{
		playlist.modify(play, songDatabase, name, artist, album, time, year);
	}
	cout << "mod a playlist" << endl;
	getline(cin, play);
	playlist.modify(play, songDatabase, name, artist, album, time, year);
	cout << "mod a playlist" << endl;
	getline(cin, play);
	playlist.modify(play, songDatabase, name, artist, album, time, year);
	if (playlist.create())
	{
		playlist.modify(play, songDatabase, name, artist, album, time, year);
	}
	/*
	if (playlist.create())
	{
		playlist.modify(play, songDatabase, name, artist, album, time, year);
	}
	//cout << "Delete a playlist" << endl;
	//getline(cin, play);
	//playlist.deletePlaylist(play);
	playlist.listPlaylist();
	playlist.view(songDatabase, name, artist, album, time, year);
	cout << "Enter a the filename to save to" << endl;
	while (getline(cin, play))
	{
		if (play.length() == 0)
		{
			error << "file name cannot be empty" << endl;
			continue;
		}
		else if (play.find(".txt") == string::npos)
		{
			error << "The file extension has to be \".txt\"" << endl;
			continue;
		}
		break;
	}
	playlist.save(play, myFile, name);
	*/


	return 0;
}