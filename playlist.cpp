/*******************************************************************************
Title          : cp395_hwk2.cpp
Author         : Cheng Pan
Created on     : October 22, 2014
Description    : Playlist manager. Create, modify, delete and view a playlist
saving the playlist to a text file
Purpose        : get use to using class , linked list, processing string data and
organizing large programs
Usage          : ./cp395_hwk2 file.csv
				 or ./cp395_hwk2 file.txt
Build with     : g++ -o cp395_hwk2 cp395_hwk2.cpp song.cpp playlist.cpp
Modifications  :
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "playlist.h"
using namespace std;

/******************************************************************************/
/*                           Function Definitions                             */
/******************************************************************************/

/**
	Playlist() A default constructor for the Playlist class
*/
Playlist::Playlist()
{}
/**
	~Playlist() A default constructor for the Playlist class
*/
Playlist::~Playlist()
{}
/**
	displayMenu(ostream& out)  display the main menu
*/
void Playlist::displayMenu(ostream& out)
{
	out << "[L/l]	    		List the names of all playlists" << endl;
	out << "[V/v]	<playlist>	View a playlist" << endl;
	out << "[C/c]	<playlist>	Create a new playlist ..." << endl;
	out << "[M/m]	<playlist>	Modify a playlist ..." << endl;
	out << "[D/d]	<playlist>	Delete an existing playlist" << endl;
	out << "[S/s]	<filename>	Save all playlist" << endl;
	out << "[H/h]	Help" << endl;
	out << "[Q/q]	Exit." << endl;
}
/**
	listPlaylist(ostream& error, ostream& out)  display all the playlist with their # of songs
*/
void Playlist::listPlaylist(ostream& error, ostream& out)
{
	if (playListNames.size() != 0)		//list all the playlists with their # of songs
	{
		it = playListNames.begin();
		list<int>::iterator it2;
		it2 = playListSize.begin();
		for (it; it != playListNames.end(); it++)
		{
			out << "Playlist " << *it << " has " << *it2-1 << " songs" << endl;
			it2++;
		}
	}
	else
	{
		error << "NO PLAYLIST" << endl;
	}
}
/**
	view(arg1, songDatabase, name, artist, album, time, year)  display all the songs with their descriptions
*/
void Playlist::view(string play, const vector<string>& vdataBase, vector<string>& vname, vector<string>& vartist, 
					vector<string>& valbum, vector<string>& vtime, vector<string>& vyear, ostream& error, ostream& out)
{
	string arg1 = play;
	if (find(playList.begin(), playList.end(), arg1) != playList.end())	//check if the playlist exist or not
	{	
		//iterators
		it = playList.begin();
		list<string>::iterator it2;
		list<string>::iterator it3;
		it2 = find(it, playList.end(), arg1);	//get the position of the playlist name in the list playList
		it3 = playListNames.begin();
		int playListPos = 0;
		for (int i = 0; i < playListNames.size(); ++i)
		{										//loop until it finds the playlist name position and store it in playListpos
			if (arg1 == *it3)
			{
				playListPos = i;
				break;
			}
			it3++;
		}
		list<string>::iterator it4;
		list<int>::iterator it5;
		it4 = it2;
		it5 = playListSize.begin();
		advance(it5, playListPos);				//increment the iterator by playListPos
		advance(it4, *it5);						//increment the iterator by pointer value of it5
		for (it2; it2 != it4; it2++)			//loop to display the songs and their descriptions
		{										//find the song in the vector and use the position in the vector for other fields
			vit = find(vname.begin(), vname.end(), *it2);
			if (vit != vname.end())
			{
				int pos = vit - vname.begin();
				string artist = vartist[pos];
				string name = vname[pos];
				string album = valbum[pos];
				string timE = vtime[pos];
				string year = vyear[pos];
				int time = 0;
				//erase the quotes when displaying
				artist.erase(artist.begin(), artist.begin() + 1);
				artist.erase(artist.end() - 1, artist.end());
				name.erase(name.begin(), name.begin() + 1);
				name.erase(name.end() - 1, name.end());
				album.erase(album.begin(), album.begin() + 1);
				album.erase(album.end() - 1, album.end());
				timE.erase(timE.begin(), timE.begin() + 1);
				timE.erase(timE.end() - 1, timE.end());
				year.erase(year.begin(), year.begin() + 1);
				year.erase(year.end() - 1, year.end());
				//check if time is empty or not. If it's not empty then convert it to int
				if (timE != "" || timE != " " || timE != "	")
				{
					istringstream(timE) >> time;
				}
				int minutes = time / 60;		//convert seconds to minutes
				int seconds = time % 60;		//get the remaining seconds
				//display everything
				out << setw(5) << setfill(' ') << right << pos + 1 << " ";
				out << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
				out << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
				out << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
				out << setw(2) << right << setfill('0') << minutes;
				out << ":";
				out << setw(2) << right << setfill('0') << seconds << " ";
				out << setw(4) << setfill(' ') << year << endl;
		
			}
		}
	}
	else
	{
		error << "INVALID PLAYLIST" << endl;
	}

}
/**
	create(arg1, ostream& error, ostream& out)  create a new playlist
*/
bool Playlist::create(string play, ostream& error, ostream& out)
{
	string playName = play;
	//check if playlist already exist or not
	it = find(playList.begin(), playList.end(), playName);
	if (it != playList.end() && playList.size() != 0)
	{	//if there's already a playlist with the same name, display error message
		error << "A playlist with the name " << playName << " already exist." << endl;
		return false;
	}
	else
	{	//if there's no playlist with the same name, create new playlist 
		tempList.push_front(playName);
		newPlayList = true;
		return true;
	}
}
/**
	modify(arg1, songDatabase, name, artist, album, time, year)  modify an existing playlist
*/
void Playlist::modify(string plays, const vector<string>& vdataBase, vector<string>& vname, vector<string>& vartist, 
					  vector<string>& valbum, vector<string>& vtime, vector<string>& vyear, ostream& error, ostream& out)
{
	if (find(playListNames.begin(), playListNames.end(), plays) == playListNames.end() && find(tempList.begin(),tempList.end(),plays) == tempList.end())
	{	
		//display error if playlist does not exist
		error << "Playlist does not exist" << endl;
	}
	else
	{
		bool quit = false;
		string playName = plays;
		while (!quit)
		{	
			//display the menu
			out << "[L/l]	<first> <last>	List all songs from database from first to last" << endl;
			out << "[A/a]	<artist_key>	List all songs whose artist contain artist_key as a substring" << endl;
			out << "[T/t]	<title_key> 	List all songs whose title contains title_key as a substring" << endl;
			out << "Insert	<songid> <pos>	Insert the songid into playlist at position <pos>" << endl;
			out << "Delete	<songid>    	Delete songid from playlist" << endl;
			out << "Show	    	       	Display the songs in the playlist" << endl;
			out << "Back	    	    	Return to the top-level menu." << endl;

			if (find(playListNames.begin(), playListNames.end(), playName) != playListNames.end() && !newPlayList)
			{	
				//iterators
				//similar as above in view() function
				list<string>::iterator it2;
				list<string>::iterator it3;
				it2 = find(playList.begin(), playList.end(), playName);		//store the position of playlist name
				it3 = playListNames.begin();
				int disT = distance(playList.begin(), it2);					//store the distance from the beginning to the position found
				int playListPos = 0;
				for (int i = 0; i < playListNames.size(); ++i)				//loop to get the position in int type of playlist name
				{
					if (playName == *it3)
					{
						playListPos = i;
						break;
					}
					it3++;
				}
				list<string>::iterator it4;
				list<int>::iterator it5;
				it4 = it2;
				it5 = playListSize.begin();
				advance(it5, playListPos);
				advance(it4, *it5);
				for (it2; it2 != it4; it2++)		//push back the newly modified playlist back to the playList list
				{
					tempList.push_back(*it2);
				}
				//delete the old version of current playlist
				//find the position of the old playList and then delete the elements in that position by using the value in playListSize
				it = find(playListNames.begin(), playListNames.end(), playName);
				disT = distance(playListNames.begin(), it);
				playListNames.erase(it);
				list<int>::iterator it6;
				it6 = playListSize.begin();
				advance(it6, disT);
				int sizeT = *it6;
				playListSize.erase(it6);
				list<string>::iterator it7;
				list<string>::iterator it8;
				it7 = find(playList.begin(), playList.end(), playName);
				it8 = it7;
				advance(it8, sizeT);
				while (it7 != it8)
				{
					it7 = playList.erase(it7);
				}
			}
			//similar to the one used for the main menu
			//use substring to get all the arguments
			string choice;
			string command;
			string arg1;
			string arg2;
			int iarg1 = 0;
			int iarg2 = 0;
			getline(cin, choice);
			//first letter cannot be empty
			if (choice[0] == 0 || choice[0] == ' ' || choice[0] == '	')
			{
				error << "command cannot be empty" << endl;
				continue;
			}
			int pos = 0;							//stores position
			int counter = 0;						//stores the counter
			int found = choice.find(" ", pos);		//get the position of the space and store in found
			if (found == string::npos)				//if there's no space
			{
				command = choice.substr(pos);		//get all the substring
			}
			while (found != string::npos)
			{
				found = choice.find(" ", pos);
				if (counter == 0)
				{
					command = choice.substr(pos, found);		//get the first word
				}
				else if (counter == 1)
				{
					arg1 = choice.substr(pos, found - pos);		//get the first argument
				}
				else if (counter == 2)
				{
					arg2 = choice.substr(pos);					//get the second argument
				}
				else
				{
					break;
				}
				pos = found + 1;
				counter++;
			}
			if (command == "L" || command == "l")				//if user entered L/l for the first word
			{
				istringstream(arg1) >> iarg1;					//convert to int type
				istringstream(arg2) >> iarg2;					
				if (iarg1 < 1)									//iarg1 cannot be less than 1
				{
					iarg1 = 1;
				}
				if (iarg2 > vname.size())						//iarg2 cannot be bigger than total # of songs
				{
					iarg2 = vname.size();
				}
				for (iarg1; iarg1 <= iarg2; iarg1++)			//display the songs with their descriptions
				{
					int pos = iarg1 - 1;
					string artist = vartist[pos];
					string name = vname[pos];
					string album = valbum[pos];
					string timE = vtime[pos];
					string year = vyear[pos];
					int time = 0;
					//erase the quotes
					artist.erase(artist.begin(), artist.begin() + 1);
					artist.erase(artist.end() - 1, artist.end());
					name.erase(name.begin(), name.begin() + 1);
					name.erase(name.end() - 1, name.end());
					album.erase(album.begin(), album.begin() + 1);
					album.erase(album.end() - 1, album.end());
					timE.erase(timE.begin(), timE.begin() + 1);
					timE.erase(timE.end() - 1, timE.end());
					year.erase(year.begin(), year.begin() + 1);
					year.erase(year.end() - 1, year.end());
					if (timE != "" || timE != " " || timE != "	")			//convert time to int
					{
						istringstream(timE) >> time;
					}
					int minutes = time / 60;					//minutes
					int seconds = time % 60;					//remaining seconds

					out << setw(5) << setfill(' ') << right << pos + 1 << " ";
					out << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
					out << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
					out << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
					out << setw(2) << right << setfill('0') << minutes;
					out << ":";
					out << setw(2) << right << setfill('0') << seconds << " ";
					out << setw(4) << setfill(' ') << year << endl;
				}
			}
			else if (command == "A" || command == "a")			//command to display all the songs with the artist_key in them
			{
				out << vartist.size() << endl;
				if (arg1 == "" || arg1 == " " || arg1 == "	")	//check if the argument is empty
				{
					error << "Invalid artist key" << endl;		//display error if empty
					continue;
				}

				//display all the songs with the artist_key with their descriptions
				for (int i = 0; i < vartist.size(); i++)
				{
					string str = vartist[i];
					if (str.find(arg1) != string::npos)
					{
						string artist = vartist[i];
						string name = vname[i];
						string album = valbum[i];
						string timE = vtime[i];
						string year = vyear[i];
						int time = 0;
						//remove the quotes
						artist.erase(artist.begin(), artist.begin() + 1);
						artist.erase(artist.end() - 1, artist.end());
						name.erase(name.begin(), name.begin() + 1);
						name.erase(name.end() - 1, name.end());
						album.erase(album.begin(), album.begin() + 1);
						album.erase(album.end() - 1, album.end());
						timE.erase(timE.begin(), timE.begin() + 1);
						timE.erase(timE.end() - 1, timE.end());
						year.erase(year.begin(), year.begin() + 1);
						year.erase(year.end() - 1, year.end());
						if (timE != "" || timE != " " || timE != "	")
						{
							istringstream(timE) >> time;
						}
						int minutes = time / 60;		//minutes
						int seconds = time % 60;		//remaining seconds

						out << setw(5) << setfill(' ') << right << i + 1 << " ";
						out << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
						out << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
						out << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
						out << setw(2) << right << setfill('0') << minutes;
						out << ":";
						out << setw(2) << right << setfill('0') << seconds << " ";
						out << setw(4) << setfill(' ') << year << endl;
					}
				}
			}
			else if (command == "T" || command == "t")			//command to display all the songs with the title_key
			{
				if (arg1 == "" || arg1 == " " || arg1 == "	")	//check if argument 1 is empty or not
				{
					error << "Invalid title key" << endl;		//display error if empty
					continue;
				}
				for (int i = 0; i < vname.size(); i++)			//loop to display all the songs with the title_key with their descriptions
				{
					string str = vname[i];
					if (str.find(arg1) != string::npos)
					{
						string artist = vartist[i];
						string name = vname[i];
						string album = valbum[i];
						string timE = vtime[i];
						string year = vyear[i];
						int time = 0;
						//remove quotes
						artist.erase(artist.begin(), artist.begin() + 1);
						artist.erase(artist.end() - 1, artist.end());
						name.erase(name.begin(), name.begin() + 1);
						name.erase(name.end() - 1, name.end());
						album.erase(album.begin(), album.begin() + 1);
						album.erase(album.end() - 1, album.end());
						timE.erase(timE.begin(), timE.begin() + 1);
						timE.erase(timE.end() - 1, timE.end());
						year.erase(year.begin(), year.begin() + 1);
						year.erase(year.end() - 1, year.end());
						if (timE != "" || timE != " " || timE != "	")		//conver to int type
						{
							istringstream(timE) >> time;
						}
						int minutes = time / 60;
						int seconds = time % 60;

						out << setw(5) << setfill(' ') << right << i + 1 << " ";
						out << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
						out << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
						out << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
						out << setw(2) << right << setfill('0') << minutes;
						out << ":";
						out << setw(2) << right << setfill('0') << seconds << " ";
						out << setw(4) << setfill(' ') << year << endl;
					}
				}
				out << "T" << endl;
			}
			else if (command == "Insert")			//command to insert song into playlist
			{
				istringstream(arg1) >> iarg1;		//convert to int type
				istringstream(arg2) >> iarg2;		
				it = tempList.begin();
													//check if valid position and valid song index
				if (iarg1 <= vname.size() && iarg1 > 0 && iarg2 >= 1 && iarg2 <= tempList.size() + 1)
				{
					for (int i = 0; i < iarg2; i++)	//loop to go to the position to insert
					{
						it++;
					}
					tempList.insert(it, vname[iarg1 - 1]);
				}
				else
				{
					error << "Invalid songid or pos" << endl;
				}
			}
			else if (command == "Delete")			//command to delete song from the playlist
			{
				istringstream(arg1) >> iarg1;		//convert to int type
													//check if the position and index is valid
				if (iarg1 <= vname.size() && iarg1 > 0)
				{									//if it is valid, remove all the occurrence of song in the playlist
					tempList.remove(vname[iarg1 - 1]);
				}
			}
			else if (command == "Show")				//command to display the current playlist
			{
													//loop for each song in the playlist and display their descriptions
				for (it = tempList.begin(); it != tempList.end(); ++it)	
				{
					if (it != tempList.end())
					{
						vit = find(vname.begin(), vname.end(), *it);
						if (vit != vname.end())
						{
							int pos = vit - vname.begin();
							string artist = vartist[pos];
							string name = vname[pos];
							string album = valbum[pos];
							string timE = vtime[pos];
							string year = vyear[pos];
							int time = 0;
							//remove quotes
							artist.erase(artist.begin(), artist.begin() + 1);
							artist.erase(artist.end() - 1, artist.end());
							name.erase(name.begin(), name.begin() + 1);
							name.erase(name.end() - 1, name.end());
							album.erase(album.begin(), album.begin() + 1);
							album.erase(album.end() - 1, album.end());
							timE.erase(timE.begin(), timE.begin() + 1);
							timE.erase(timE.end() - 1, timE.end());
							year.erase(year.begin(), year.begin() + 1);
							year.erase(year.end() - 1, year.end());
							if (timE != "" || timE != " " || timE != "	")		//check if empty
							{													//if not empty, convert to int type
								istringstream(timE) >> time;
							}
							int minutes = time / 60;
							int seconds = time % 60;

							out << setw(5) << setfill(' ') << right << pos + 1 << " ";
							out << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
							out << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
							out << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
							out << setw(2) << right << setfill('0') << minutes;
							out << ":";
							out << setw(2) << right << setfill('0') << seconds << " ";
							out << setw(4) << setfill(' ') << year << endl;

						}
					}
				}
			}
			else if (command == "Back")					//command to go back to the main menu
			{
														//store the playlist in tempList to the main playlist list
				if (newPlayList)
				{
					for (it = tempList.begin(); it != tempList.end(); it++)
					{
						playList.push_back(*it);
					}
					playListNames.push_back(*tempList.begin());
					playListSize.push_back(tempList.size());
					tempList.clear();
					newPlayList = false;
				}
				else
				{
					for (it = tempList.begin(); it != tempList.end(); it++)
					{
						playList.push_back(*it);
					}
					playListNames.push_back(*tempList.begin());
					playListSize.push_back(tempList.size());
					for (it = playList.begin(); it != playList.end(); it++)
					{
					}
					tempList.clear();
				}
				quit = true;
			}
			else
			{
				out << "Invalid input" << endl;
			}
		}
	}
}
/**
	deletePlaylist(arg1, ostream& error, ostream& out)  delete an existing playlist
*/
void Playlist::deletePlaylist(string play, ostream& error, ostream& out)		//commmand to delete playlist
{
	//similar to modifying playlist
	string playName = play;
	if (find(playListNames.begin(), playListNames.end(), playName) != playListNames.end())
	{																			//if playlist exist
		it = find(playListNames.begin(), playListNames.end(), playName);		//get the position of the playlistname
		int disT = distance(playListNames.begin(), it);							//get the distance from begin to found
		playListNames.erase(it);												//erase playlistname
		list<int>::iterator it2;
		it2 = playListSize.begin();
		advance(it2, disT);
		int sizeT = *it2;
		playListSize.erase(it2);												
		list<string>::iterator it3;
		list<string>::iterator it4;
		it3 = find(playList.begin(), playList.end(), playName);
		it4 = it3;
		advance(it4, sizeT);
		while (it3 != it4)			//loop to delete the element at the same position
		{
			it3 = playList.erase(it3);
		}
		displayMenu();
	}
	else
	{
		error << "ERROR : PLAYLIST DOES NOT EXIST" << endl;
	}
}
/**
	save(arg1, myFile, name, ostream& error, ostream& out)  save all the playlist to a text file
*/
void Playlist::save(string txt, ofstream &fileOut, vector<string> &vname, ostream& error, ostream& out)
{
	//function to save all the playlist to a text file

	//if there's no playlist then display error message
	if (playListNames.size() == 0)
	{
		error << "There are no playlist to save" << endl;
		fileOut.close();
	}
	else
	{
		//output to the textfile the user entered
		string outPut = txt;
		fileOut.open(outPut.c_str());
		list<int>::iterator it2;
		list<string>::iterator it3;
		it = playListNames.begin();
		it2 = playListSize.begin();
		it3 = playList.begin();
		int size = *it2;				//size of the playlist to output before returning a new line and starting another playlist
		for (it; it != playListNames.end(); it++)
		{
			for (int i = 0; i < *it2; i++)
			{
				if (0 == i)
				{
					fileOut << *it << "	" << *it2 - 1 << ": ";
					it3++;
					continue;
				}
				vit = find(vname.begin(), vname.end(), *it3);
				int pos = vit - vname.begin() + 1;
				if (size - 1 == i)
				{
					fileOut << pos << endl;
				}
				else
				{
					fileOut << pos << " ";
				}
				it3++;
			}
			it2++;
		}
		fileOut.close();		//close the file
	}

}
/**
	help(ostream& out)  display the help menu
*/
void Playlist::help(ostream& out)			//explains what each command does
{
	out << "[L/l]			Display each playlist with the number of songs in that playlist on the terminal." << endl;
	out << "[V/v] <playlist>	Display the songs in the <playlist> with tags on the terminal" << endl;
	out << "[C/c] <playlist>	Create a new playlist using <playlist>" << endl;
	out << "[M/c] <playlist>	Modify a playlist" << endl;
	out << "[D/d] <playlist>	Delete an existing playlist" << endl;
	out << "[S/s] <filename>	Save all playlist into a textfile" << endl;
	out << "[H/h]			Show the help menu" << endl;
	out << "[Q/q]			Exit the program" << endl; 
	out << endl;
}