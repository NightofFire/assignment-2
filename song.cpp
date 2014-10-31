/*******************************************************************************
Title          : cp395_hwk2.cpp
Author         : Cheng Pan
Created on     : September 22, 2014
Description    : Playlist manager. Create, modify, delete and view a playlist
saving the playlist to a text file
Purpose        : get use to using class , linked list, processing string data and
organizing large programs
Usage          : ./cp395_hwk2 file.csv
Build with     : g++ -o cp395_hwk2 cp395_hwk2.cpp song.cpp playlist.cpp
Modifications  :
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "song.h"
using namespace std;

/******************************************************************************/
/*                           Function Definitions                             */
/******************************************************************************/

/**
	Song() A default constructor for the Song class
*/
Song::Song()
{}
/**
	Song() A default destructor for the Song class
*/
Song::~Song()
{}
/**
	readSongList(argc, argv, ostream& error = cerr, ostream& out = cout)  list all the playlist with the number of songs each playlist have
*/
void Song::readSongList(int argc, char* argv[], ostream& error, ostream& out)
{
	ifstream input;
	if (argc > 1)					//if user entered a commandline argument
		input.open(argv[1]);		//open the file user entered
	else
		input.open("songs.csv");	//else, open the default file
	if (input.fail())				//Check if it can open the file or not
	{
		error << "Unable to open file. " << endl;
		error << "This program will now exit. " << endl;
		exit(0);
	}
	else
		error << "FILE OPENED SUCCESSFULLY" << endl;
	bool checkedHeadings = false;	//use to check the heading once during the loop
	string word;
	if (input.good())
	{
		while (getline(input, word))		//loop to get each line in the file
		{
			
			if (checkedHeadings == false)	//only check the heading once
			{
				if (word == "\"Name\"	\"Artist\"	\"Album\"	\"Genre\"	\"Size\"	\"Time\"	\"Year\"	\"Comments\"")
				{
				}
				else		//if heading is wrong, output error message and exit the program
				{
					error << "Headings are wrong or formatted incorrectly." << endl;
					error << "The heading fields are tab-separated and enclosed in double-quotes." << endl;
					error << "Example:"<<endl<<
						"\"name\"	\"Artist\"	\"Album\"	\"Genre\"	\"Size\"	\"Time\"	\"Year\"	\"Comments\" "<< endl;
					exit(0);
				}
				checkedHeadings = true;
			}
			else
			{
				int qPos = 0;							//store the quote position
				int findQuotes = word.find('\"', qPos);	//find the position of quotes
				int numQuotes = 0;						//count the # of quotes
				int counter = 0;						//to see which field to store into which vector
				while (findQuotes != string::npos)		//loop to find all the quotes
				{
					qPos = findQuotes + 1;
					findQuotes = word.find('\"', qPos);
					numQuotes++;
				}
				if (numQuotes != 16)					//2 quotes for each field. 8 fields, so it's 16 quotes total.
				{
					error << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
					error << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
					exit(0);
				}
				int numTab = 0;							//store the # of tabs
				int pos = 0;							//store the position of the tabs
				int found = word.find("	", pos);
				bool snameArtist = false;				//use to check the first two field of each line, sname and Artist.
				while (found != string::npos)
				{
					if (snameArtist == false)			//first two fields cannot be empty
					{
						int length = 0;
						string sname = word.substr(0, found);
						string temp;
						ss << sname;
						while (ss >> temp)				//stringstream to get the length of each substring
						{
							length += temp.length();
						}
						ss.clear();
						if (2 >= length || sname == "" || sname[0] != '\"' || sname[found - 1] != '\"')
						{
							error << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							error << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							exit(0);
						}
						name.push_back(sname);
						songDatabase.push_back(sname);
					}
					//used to get all the other fields
					pos=found+1;					//position of the previous + 1
					found = word.find("	", pos);	//new position of the next tab space
					int length = 0;
					string sname = word.substr(pos, found - pos);	//get the string between the quotes
					string temp;
					ss << sname;
					while (ss >> temp)								//stringstream to get the length of each substring
					{
						length += temp.length();
					}
					ss.clear();
					if (snameArtist == false)
					{
						if (2 >= length || sname == "" || sname[0] != '\"' || sname[found - pos - 1] != '\"')
						{
							error << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							error << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							exit(0);
						}
						snameArtist = true;
					}
					else if (found != string::npos)		//enter if not found
					{
						if (2 > length || sname[0] != '\"' || sname[found - pos - 1] != '\"')
						{
							error << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							error << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							exit(0);
						}
					}
					else
					{
						//there are only 7 tabs so it can only loop 7 times but there are 8 fields so comments field is left out
						//this is used to check the comment field and stores it
						int temp=0;
						sname = word.substr(pos);
						temp = word.find('\"', pos + 1);
						length = sname.length();
						if (temp == string::npos || length-1!=temp-pos)
						{
							error << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							error << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							exit(0);
						}
						if (2 > length || sname[0] != '\"' || sname[temp-pos] != '\"')
						{
							error << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							error << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							error << "No extra space should be allowed outside the field" << endl;
							exit(0);
						}
						comments.push_back(sname);
						
					}
					//store the fields in their vector by using the counter
					if (counter == 0)
					{
						artist.push_back(sname);
					}
					else if (counter == 1)
					{
						album.push_back(sname);
					}
					else if (counter == 2)
					{
						genre.push_back(sname);
					}
					else if (counter == 3)
					{
						size.push_back(sname);
					}
					else if (counter == 4)
					{
						time.push_back(sname);
					}
					else if (counter == 5)
					{
						year.push_back(sname);
					}
					songDatabase.push_back(sname);	//store everything inside the vector
					counter++;
					numTab++;
				}
				if (numTab != 7)					//if there're more than 7 tabs then it's wrong
				{
					error << "ERROR: Each line have to contains eight fields, corresponding to the headings." << endl;
					error << "Only the first two fields: name and Artist are mandatory on the line." << endl;
					exit(0);
				}
			}

		}
		input.clear();					//clear the inputfile
		input.seekg(65, ios::beg);		//goto beginning of the file
		input >> noskipws >> word;		//do not skip spaces
	}
}
/**
	getName()  return vector of song names
*/
vector<string> &Song::getName()		//return vector of all the song names
{
	return name;
}
/**
	getArtist()  return vector of artist names
*/
vector<string> &Song::getArtist()	//return vector of all the artist names
{
	return artist;
}
/**
	getAlbum()  return vector of album names
*/
vector<string> &Song::getAlbum()	//return vector of all the album names
{
	return album;
}
/**
	getGenre()  return vector of genres
*/
vector<string> &Song::getGenre()	//return vector of all the genres
{
	return genre;
}
/**
	getSize()  return vector of song size
*/
vector<string> &Song::getSize()		//return vector of all the size of the songs
{
	return size;
}
/**
	getTime()  return vector of song duration
*/
vector<string> &Song::getTime()		//return vector of all the time of the songs
{
	return time;
}
/**
	getYear()  return vector of the year song was produced in
*/
vector<string> &Song::getYear()		//return vector of all the year of the songs
{
	return year;
}
/**
	getComments()  return vector of song comments
*/
vector<string> &Song::getComments()	//return vector of all the comments of the songs
{
	return comments;
}
/**
	getSongDatabase()  return vector of the entire database
*/
vector<string> &Song::getSongDatabase()		//return vector of that contains all of the above
{
	return songDatabase;
}