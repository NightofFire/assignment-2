#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "playlist.h"
using namespace std;

Playlist::Playlist()
{}
Playlist::~Playlist()
{}
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
void Playlist::listPlaylist(ostream& error, ostream& out)
{
	if (playListNames.size() != 0)
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
void Playlist::view(string play, const vector<string>& vdataBase, vector<string>& vname, vector<string>& vartist, vector<string>& valbum, vector<string>& vtime, vector<string>& vyear, ostream& error, ostream& out)
{
	/*if (playListNames.size() != 0)
	{
		string choice;
		string command;
		string arg1;
		int iarg1 = 0;
		getline(cin, choice);
		if (choice[0] == NULL || choice[0] == ' ' || choice[0] == '	')
		{
			error << "error" << endl;
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
				arg1 = choice.substr(pos);
			}
			else
			{
				break;
			}
			pos = found + 1;
			counter++;
			//out << counter << endl;
		}
		if (command == "View")
		{*/
	string arg1 = play;
	if (find(playList.begin(), playList.end(), arg1) != playList.end())
	{
		it = playList.begin();
		list<string>::iterator it2;
		list<string>::iterator it3;
		//out << arg1 << endl;
		it2 = find(it, playList.end(), arg1);
		it3 = playListNames.begin();
		int playListPos = 0;
		for (int i = 0; i < playListNames.size(); ++i)
		{
			if (arg1 == *it3)
			{
				playListPos = i;
				break;
			}
			it3++;
		}
		//out << "test " << playListPos << endl;
		list<string>::iterator it4;
		list<int>::iterator it5;
		it4 = it2;
		it5 = playListSize.begin();
		advance(it5, playListPos);
		advance(it4, *it5);
		for (it2; it2 != it4; it2++)
		{
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
				int minutes = time / 60;
				//out << minutes << endl;
				int seconds = time % 60;
				//out << setw(2) << setfill('0') << minutes << endl;

				//out << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
				out << setw(5) << setfill(' ') << right << pos + 1 << " ";
				out << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
				out << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
				out << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
				out << setw(2) << right << setfill('0') << minutes;
				out << ":";
				out << setw(2) << right << setfill('0') << seconds << " ";
				out << setw(4) << setfill(' ') << year << endl;
				//out << setw(5) << right << i + 1 << setw(20) << left << artist << setw(30) << left << name << setw(10) << left << album
				//<< setw(2) << setfill('0') << minute / 60 << setw(2) << setfill('0') << minute % 60 << year << endl;
			}
		}
	}
	else
	{
		error << "INVALID PLAYLIST" << endl;
	}

}
bool Playlist::create(string play, ostream& error, ostream& out)
{
	string playName = play;
	it = find(playList.begin(), playList.end(), playName);
	if (it != playList.end() && playList.size() != 0)
	{
		error << "A playlist with the name " << playName << " already exist." << endl;
		displayMenu();
		return false;
	}
	else
	{
		tempList.push_front(playName);
		//tempList.push_back("end");
		newPlayList = true;
		return true;
	}
}
void Playlist::modify(string plays, const vector<string>& vdataBase, vector<string>& vname, vector<string>& vartist, vector<string>& valbum, vector<string>& vtime, vector<string>& vyear, ostream& error, ostream& out)
{
	if (find(playListNames.begin(), playListNames.end(), plays) == playListNames.end())
	{
		error << "Invalid playlist" << endl;
	}
	else
	{
		bool quit = false;
		string playName = plays;
		while (!quit)
		{
			out << "[L/l]	<first> <last>	List all songs from database from first to last" << endl;
			out << "[A/a]	<artist_key>	List all songs whose artist contain artist_key as a substring" << endl;
			out << "[T/t]	<title_key> 	List all songs whose title contains title_key as a substring" << endl;
			out << "Insert	<songid> <pos>	Insert the songid into playlist at position <pos>" << endl;
			out << "Delete	<songid>    	Delete songid from playlist" << endl;
			out << "Show	    	       	Display the songs in the playlist" << endl;
			out << "Back	    	    	Return to the top-level menu." << endl;

			if (find(playListNames.begin(), playListNames.end(), playName) != playListNames.end() && !newPlayList)
			{
				list<string>::iterator it2;
				list<string>::iterator it3;
				//out << arg1 << endl;
				it2 = find(playList.begin(), playList.end(), playName);
				it3 = playListNames.begin();
				int disT = distance(playList.begin(), it2);
				int playListPos = 0;
				for (int i = 0; i < playListNames.size(); ++i)
				{
					if (playName == *it3)
					{
						playListPos = i;
						break;
					}
					it3++;
				}
				//out << "test " << playListPos << endl;
				list<string>::iterator it4;
				list<int>::iterator it5;
				it4 = it2;
				it5 = playListSize.begin();
				advance(it5, playListPos);
				advance(it4, *it5);
				for (it2; it2 != it4; it2++)
				{
					tempList.push_back(*it2);
					out << *it2 << endl;
				}
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
			string choice;
			string command;
			string arg1;
			string arg2;
			int iarg1 = 0;
			int iarg2 = 0;
			getline(cin, choice);
			if (choice[0] == NULL || choice[0] == ' ' || choice[0] == '	')
			{
				error << "error" << endl;
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
				else if (counter == 2)
				{
					arg2 = choice.substr(pos);
				}
				else
				{
					break;
				}
				pos = found + 1;
				counter++;
				//out << counter << endl;
			}
			out << counter << endl;
			out << "-" << command << "-" << endl;
			//cin >> command >> arg1 >> arg2;
			if (command == "L" || command == "l")
			{
				istringstream(arg1) >> iarg1;
				istringstream(arg2) >> iarg2;
				if (iarg1 < 1)
				{
					iarg1 = 1;
				}
				if (iarg2 > vname.size())
				{
					iarg2 = vname.size();
				}
				out << iarg1 << "-" << iarg2 << endl;
				for (iarg1; iarg1 <= iarg2; iarg1++)
				{
					int pos = iarg1 - 1;
					string artist = vartist[pos];
					string name = vname[pos];
					string album = valbum[pos];
					string timE = vtime[pos];
					string year = vyear[pos];
					int time = 0;
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
					int minutes = time / 60;
					//out << minutes << endl;
					int seconds = time % 60;
					//out << setw(2) << setfill('0') << minutes << endl;

					//out << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
					out << setw(5) << setfill(' ') << right << pos + 1 << " ";
					out << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
					out << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
					out << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
					out << setw(2) << right << setfill('0') << minutes;
					out << ":";
					out << setw(2) << right << setfill('0') << seconds << " ";
					out << setw(4) << setfill(' ') << year << endl;
					//out << setw(5) << right << i + 1 << setw(20) << left << artist << setw(30) << left << name << setw(10) << left << album
					//<< setw(2) << setfill('0') << minute / 60 << setw(2) << setfill('0') << minute % 60 << year << endl;
				}
			}
			else if (command == "A" || command == "a")
			{
				out << vartist.size() << endl;
				if (arg1 == "" || arg1 == " " || arg1 == "	")
				{
					error << "Invalid artist key" << endl;
					out << arg1 << endl;
					continue;
				}
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
						int minutes = time / 60;
						//out << minutes << endl;
						int seconds = time % 60;
						//out << setw(2) << setfill('0') << minutes << endl;

						//out << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
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
				//out << "A" << endl;
			}
			else if (command == "T" || command == "t")
			{
				if (arg1 == "" || arg1 == " " || arg1 == "	")
				{
					error << "Invalid title key" << endl;
					continue;
				}
				for (int i = 0; i < vname.size(); i++)
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
						int minutes = time / 60;
						//out << minutes << endl;
						int seconds = time % 60;
						//out << setw(2) << setfill('0') << minutes << endl;

						//out << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
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
			else if (command == "Insert")
			{
				istringstream(arg1) >> iarg1;
				istringstream(arg2) >> iarg2;
				it = tempList.begin();
				if (iarg1 <= vname.size() && iarg1 > 0 && iarg2 >= 1 && iarg2 <= tempList.size() + 1)
				{
					for (int i = 0; i < iarg2; i++)
					{
						it++;
					}
					tempList.insert(it, vname[iarg1 - 1]);
					out << *tempList.begin() << endl;
				}
				else
				{
					error << "Invalid songid or pos" << endl;
				}
			}
			else if (command == "Delete")
			{
				istringstream(arg1) >> iarg1;
				if (iarg1 <= vname.size() && iarg1 > 0)
				{
					tempList.remove(vname[iarg1 - 1]);
					out << tempList.size() << endl;
					out << *tempList.begin() << endl;
					out << "success" << endl;
				}
			}
			else if (command == "Show")
			{
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
							int minutes = time / 60;
							//out << minutes << endl;
							int seconds = time % 60;
							//out << setw(2) << setfill('0') << minutes << endl;

							//out << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
							out << setw(5) << setfill(' ') << right << pos + 1 << " ";
							out << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
							out << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
							out << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
							out << setw(2) << right << setfill('0') << minutes;
							out << ":";
							out << setw(2) << right << setfill('0') << seconds << " ";
							out << setw(4) << setfill(' ') << year << endl;
							//out << setw(5) << right << i + 1 << setw(20) << left << artist << setw(30) << left << name << setw(10) << left << album
							//<< setw(2) << setfill('0') << minute / 60 << setw(2) << setfill('0') << minute % 60 << year << endl;
						}
					}
				}
			}
			else if (command == "Back")
			{
				if (newPlayList)
				{
					//out << "playlist1-" << *tempList.begin() << "-" << endl;
					for (it = tempList.begin(); it != tempList.end(); it++)
					{
						playList.push_back(*it);
						//out << *it << endl;
					}
					playListNames.push_back(*tempList.begin());
					playListSize.push_back(tempList.size());
					tempList.clear();
					newPlayList = false;
					//out << "heyyyy" << endl;
				}
				else
				{
					for (it = tempList.begin(); it != tempList.end(); it++)
					{
						playList.push_back(*it);
						//out << *it << endl;
						//out << *it << endl;
					}
					playListNames.push_back(*tempList.begin());
					//out << "size "<< tempList.size() << endl;
					playListSize.push_back(tempList.size());
					for (it = playList.begin(); it != playList.end(); it++)
					{
						//out << "playlist : "<< *it << endl;
						//out << *it << endl;
					}
					tempList.clear();
				}
				quit = true;
				//out << quit <<"ds"<< endl;
			}
			else
			{
				out << "Invalid input" << endl;
			}
		}
	}
}
void Playlist::deletePlaylist(string play, ostream& error, ostream& out)
{
	string playName = play;
	if (find(playListNames.begin(), playListNames.end(), playName) != playListNames.end())
	{
		it = find(playListNames.begin(), playListNames.end(), playName);
		int disT = distance(playListNames.begin(), it);
		playListNames.erase(it);
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
		while (it3 != it4)
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
void Playlist::save(string txt, ofstream &fileOut, vector<string> &vname, ostream& error, ostream& out)
{
	if (playListNames.size() == 0)
	{
		error << "There are no playlist to save" << endl;

	}
	else
	{
		string outPut = txt;
		fileOut.open(outPut);
		list<int>::iterator it2;
		list<string>::iterator it3;
		it = playListNames.begin();
		it2 = playListSize.begin();
		it3 = playList.begin();
		int size = *it2;
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
		fileOut.close();
	}

}
void Playlist::help(ostream& out)
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