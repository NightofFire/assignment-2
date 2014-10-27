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
void Playlist::displayMenu()
{
	cout << "[L/l]	    		List the names of all playlists" << endl;
	cout << "[V/v]	<playlist>	View a playlist" << endl;
	cout << "[C/c]	<playlist>	Create a new playlist ..." << endl;
	cout << "[M/m]	<playlist>	Modify a playlist ..." << endl;
	cout << "[D/d]	<playlist>	Delete an existing playlist" << endl;
	cout << "[S/s]	<filename>	Save all playlist" << endl;
	cout << "[H/h]	Help" << endl;
	cout << "[Q/q]	Exit." << endl;
	/*bool quit = false;
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
			//cout << found << endl;
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
			//cout << counter << endl;
		}
		if (command == "L" || command == "l")
		{
		}
		else if (command == "V" || command == "v")
		{
		}
		else if (command == "C" || command == "c")
		{
		}
		else if (command == "M" || command == "m")
		{
		}
		else if (command == "D" || command == "d")
		{
		}
		else if (command == "S" || command == "s")
		{
		}
		else if (command == "H" || command == "h")
		{
		}
		else if (command == "Q" || command == "q")
		{
			quit = true;
			exit(1);
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}*/
}
void Playlist::listPlaylist()
{
	if (playListNames.size() != 0)
	{
		it = playListNames.begin();
		list<int>::iterator it2;
		it2 = playListSize.begin();
		for (it; it != playListNames.end(); it++)
		{
			cout << "Playlist " << *it << " has " << *it2-1 << " songs" << endl;
			it2++;
		}
	}
}
void Playlist::view(const vector<string>& vdataBase, vector<string>& vname, vector<string>& vartist, vector<string>& valbum, vector<string>& vtime, vector<string>& vyear)
{
	if (playListNames.size() != 0)
	{
		string choice;
		string command;
		string arg1;
		string arg2;
		int iarg1 = 0;
		int iarg2 = 0;
		getline(cin, choice);
		if (choice[0] == NULL || choice[0] == ' ' || choice[0] == '	')
		{
			cerr << "error" << endl;
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
			//cout << found << endl;
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
			//cout << counter << endl;
		}
		it = playList.begin();
		list<string>::iterator it2;
		list<string>::iterator it3;
		cout << arg1 << endl;
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
		//cout << "test " << playListPos << endl;
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
				//cout << minutes << endl;
				int seconds = time % 60;
				//cout << setw(2) << setfill('0') << minutes << endl;

				//cout << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
				cout << setw(5) << setfill(' ') << right << pos + 1 << " ";
				cout << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
				cout << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
				cout << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
				cout << setw(2) << right << setfill('0') << minutes;
				cout << ":";
				cout << setw(2) << right << setfill('0') << seconds << " ";
				cout << setw(4) << setfill(' ') << year << endl;
				//cout << setw(5) << right << i + 1 << setw(20) << left << artist << setw(30) << left << name << setw(10) << left << album
				//<< setw(2) << setfill('0') << minute / 60 << setw(2) << setfill('0') << minute % 60 << year << endl;
			}
		}
	}
	//displayMenu();
}
bool Playlist::create()
{
	string play;
	cout << "Create a playlist" << endl;
	getline(cin, play);
	it = find(playList.begin(), playList.end(), play);
	if (it != playList.end() && playList.size() != 0)
	{
		cerr << "A playlist with the name " << play << " already exist." << endl;
		displayMenu();
		return false;
	}
	else
	{
		tempList.push_front(play);
		//tempList.push_back("end");
		newPlayList = true;
		return true;
	}
}
void Playlist::modify(const vector<string>& vdataBase, vector<string>& vname, vector<string>& vartist, vector<string>& valbum, vector<string>& vtime,vector<string>& vyear)
{
	bool quit = false;
	while (!quit)
	{
		cout << "[L/l]	<first> <last>	List all songs from database from first to last" << endl;
		cout << "[A/a]	<artist_key>	List all songs whose artist contain artist_key as a substring" << endl;
		cout << "[T/t]	<title_key> 	List all songs whose title contains title_key as a substring" << endl;
		cout << "Insert	<songid> <pos>	Insert the songid into playlist at position <pos>" << endl;
		cout << "Delete	<songid>    	Delete songid from playlist" << endl;
		cout << "Show	    	       	Display the songs in the playlist" << endl;
		cout << "Back	    	    	Return to the top-level menu." << endl;

		string choice;
		string command;
		string arg1;
		string arg2;
		int iarg1 = 0;
		int iarg2 = 0;
		getline(cin, choice);
		if (choice[0] == NULL || choice[0]==' ' || choice[0]=='	')
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
			//cout << found << endl;
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
			//cout << counter << endl;
		}
		cout << counter << endl;
		cout <<"-"<< command <<"-"<< endl;
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
			cout << iarg1 << "-" << iarg2 << endl;
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
				//cout << minutes << endl;
				int seconds = time % 60;
				//cout << setw(2) << setfill('0') << minutes << endl;

				//cout << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
				cout << setw(5) << setfill(' ') << right << pos + 1 << " ";
				cout << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
				cout << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
				cout << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
				cout << setw(2) << right << setfill('0') << minutes;
				cout << ":";
				cout << setw(2) << right << setfill('0') << seconds << " ";
				cout << setw(4) << setfill(' ') << year << endl;
				//cout << setw(5) << right << i + 1 << setw(20) << left << artist << setw(30) << left << name << setw(10) << left << album
				//<< setw(2) << setfill('0') << minute / 60 << setw(2) << setfill('0') << minute % 60 << year << endl;
			}
		}
		else if (command == "A" || command == "a")
		{
			cout << vartist.size() << endl;
			if (arg1 == "" || arg1 == " " || arg1 == "	")
			{
				cerr << "Invalid artist key" << endl;
				cout << arg1 << endl;
				continue;
			}
			for (int i = 0; i < vartist.size(); i++)
			{
				string str=vartist[i];
				if(str.find(arg1)!=string::npos)
				{
					string artist=vartist[i];
					string name=vname[i];
					string album=valbum[i];
					string timE=vtime[i];
					string year=vyear[i];
					int time=0;
					artist.erase(artist.begin(), artist.begin()+1);
					artist.erase(artist.end() - 1, artist.end());
					name.erase(name.begin(), name.begin() + 1);
					name.erase(name.end() - 1, name.end());
					album.erase(album.begin(), album.begin() + 1);
					album.erase(album.end() - 1, album.end());
					timE.erase(timE.begin(), timE.begin() + 1);
					timE.erase(timE.end() - 1, timE.end());
					year.erase(year.begin(), year.begin() + 1);
					year.erase(year.end() - 1, year.end());
					if(timE!="" || timE!=" " || timE!="	")
					{
						istringstream(timE) >> time;
					}
					int minutes = time / 60;
					//cout << minutes << endl;
					int seconds = time % 60;
					//cout << setw(2) << setfill('0') << minutes << endl;
						
				//cout << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
					cout << setw(5) << setfill(' ') << right << i + 1 << " ";
					cout << setw(20) << setfill(' ') << left << artist.substr(0,20) << " ";
					cout << setw(30) << setfill(' ') << left << name.substr(0,30) << " ";
					cout << setw(10) << setfill(' ') << left << album.substr(0,10) << " ";
					cout << setw(2) << right << setfill('0') << minutes;
					cout << ":";
					cout << setw(2) << right << setfill('0') << seconds << " ";
					cout << setw(4) << setfill(' ') << year << endl;
				}
			}
			//cout << "A" << endl;
		}
		else if (command == "T" || command == "t")
		{
			if (arg1 == "" || arg1 == " " || arg1 == "	")
			{
				cerr << "Invalid title key" << endl;
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
					//cout << minutes << endl;
					int seconds = time % 60;
					//cout << setw(2) << setfill('0') << minutes << endl;

					//cout << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
					cout << setw(5) << setfill(' ') << right << i + 1 << " ";
					cout << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
					cout << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
					cout << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
					cout << setw(2) << right << setfill('0') << minutes;
					cout << ":";
					cout << setw(2) << right << setfill('0') << seconds << " ";
					cout << setw(4) << setfill(' ') << year << endl;
				}
			}
			cout << "T" << endl;
		}
		else if (command == "Insert")
		{
			istringstream(arg1) >> iarg1;
			istringstream(arg2) >> iarg2;
			it = tempList.begin();
			if (iarg1<=vname.size() && iarg1>0 && iarg2>=1 && iarg2<=tempList.size()+1)
			{
				for (int i = 0; i < iarg2; i++)
				{
					it++;
				}
				tempList.insert(it, vname[iarg1-1]);
				cout << *tempList.begin() << endl;
			}
			else
			{
				cerr << "Invalid songid or pos" << endl;
			}
		}
		else if (command == "Delete")
		{
			istringstream(arg1) >> iarg1;
			if (iarg1 <= vname.size() && iarg1 > 0)
			{
				tempList.remove(vname[iarg1 - 1]);
				cout << tempList.size() << endl;
				cout << *tempList.begin() << endl;
				cout << "success" << endl;
			}
		}
		else if (command == "Show")
		{
			for (it = tempList.begin(); it!=tempList.end(); ++it)
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
						//cout << minutes << endl;
						int seconds = time % 60;
						//cout << setw(2) << setfill('0') << minutes << endl;

						//cout << setw(2) << setfill('0') << 173 / 60 << ":" << setw(2) << 173 % 60 << endl;
						cout << setw(5) << setfill(' ') << right << pos + 1 << " ";
						cout << setw(20) << setfill(' ') << left << artist.substr(0, 20) << " ";
						cout << setw(30) << setfill(' ') << left << name.substr(0, 30) << " ";
						cout << setw(10) << setfill(' ') << left << album.substr(0, 10) << " ";
						cout << setw(2) << right << setfill('0') << minutes;
						cout << ":";
						cout << setw(2) << right << setfill('0') << seconds << " ";
						cout << setw(4) << setfill(' ') << year << endl;
						//cout << setw(5) << right << i + 1 << setw(20) << left << artist << setw(30) << left << name << setw(10) << left << album
						//<< setw(2) << setfill('0') << minute / 60 << setw(2) << setfill('0') << minute % 60 << year << endl;
					}
				}
			}
		}
		else if (command == "Back")
		{
			if (newPlayList)
			{
				cout << "playlist1-" << *tempList.begin() << "-" << endl;
				for (it = tempList.begin(); it != tempList.end(); it++)
				{
					playList.push_back(*it);
					//cout << *it << endl;
				}
				playListNames.push_back(*tempList.begin());
				playListSize.push_back(tempList.size());
				tempList.clear();
				//cout << "heyyyy" << endl;
			}
			quit = true;
			//cout << quit <<"ds"<< endl;
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}
}