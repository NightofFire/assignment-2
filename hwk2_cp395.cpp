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
	Playlist playlist;

	//Read the default file or read the file user entered on the commandline
	song.readSongList(argc, argv);

	//store the database in main function so it can be passed to another class's function parameter
	vector<string> name = song.getName();
	vector<string> artist = song.getArtist();
	vector<string> album = song.getAlbum();
	vector<string> genre = song.getGenre();
	vector<string> size = song.getSize();
	vector<string> time = song.getTime();
	vector<string> year = song.getYear();
	vector<string> comments = song.getComments();
	vector<string> songDatabase = song.getSongDatabase();	//stores all the tags together
	//display the menu
	playlist.displayMenu();
	bool quit = false;
	string play;		//stores the userinput
	while (!quit)
	{
		string choice;	//stores the entire line of user input
		string command;	//stores the first letter. The command: L, V, C and etc.
		string arg1;	//stores the argument. Playlistnames, filenames and etc.
		getline(cin, choice);	//userinput
		//check if the first letter is empty or not.
		//If it's empty, skip the rest of the loop and do the input again.
		if (choice[0] == NULL || choice[0] == ' ' || choice[0] == '	')
		{
			cerr << "error" << endl;
			continue;
		}
		int pos = 0;						//position
		int counter = 0;					//counter
		int found = choice.find(" ", pos);	//stores the postion where there is a space
		if (found == string::npos)			//check if there's no space
		{
			command = choice.substr(pos);	//get the first letter
		}
		while (found != string::npos)		//loop until it can't find anymore spaces
		{
			found = choice.find(" ", pos);
			if (counter == 0)
			{								//get the first letter
				command = choice.substr(pos, found);
			}
			else if (counter == 1)
			{								//get the rest of the line
				arg1 = choice.substr(pos);
			}
			else
			{
				break;
			}
			pos = found + 1;
			counter++;
		}
		if (command == "L" || command == "l")
		{											//enters if user entered L/l as the first letter
			playlist.listPlaylist();
		}
		else if (command == "V" || command == "v")
		{											//enters if user entered V/v as the first letter
			playlist.view(arg1, songDatabase, name, artist, album, time, year);
		}
		else if (command == "C" || command == "c")
		{											//enters if user entered C/c as the first letter
			if (playlist.create(arg1) && counter >= 1)
			{										//If new playlist is not a duplicate and there's more than 1 argument
				//Enter modify mode with the new playlist
				playlist.modify(arg1, songDatabase, name, artist, album, time, year);
			}
			else									//If user didn't enter a second arugment in the input
			{
				cerr << "Playlist needs a name" << endl;
			}
		}
		else if (command == "M" || command == "m")
		{											//enters if user entered M/m as the first letter
			if (counter >= 1)						//If there's more than 1 argument
			{
				playlist.modify(arg1, songDatabase, name, artist, album, time, year);
			}
			else
			{
				cerr << "Playlist needs a name" << endl;
			}
		}
		else if (command == "D" || command == "d")
		{											//enters if user entered D/d as the first letter
			playlist.deletePlaylist(arg1);
		}
		else if (command == "S" || command == "s")
		{											//enters if user entered S/s as the first letter
			if (arg1.find(".txt") != string::npos)
			{
				ofstream myFile;						//pass myFile to function as reference
				playlist.save(arg1, myFile, name);
			}
			else if (arg1.length() == 0)
			{
				cerr << "The file name cannot be empty" << endl;
			}
			else
			{
				cerr << "The file need to have the extension .txt" << endl;
			}
		}
		else if (command == "H" || command == "h")
		{											//enters if user entered H/h as the first letter
			playlist.help();						//Explains what each function does
		}
		else if (command == "Q" || command == "q")
		{											//If user entered Q/q, exit the program
			quit = true;
			exit(1);
		}
		else
		{
			cerr << "Invalid input" << endl;
		}
		playlist.displayMenu();						//display the menu
	}

	return 0;
}