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
	/******************************************************************************/
	/*                           Function Prototypes                              */
	/******************************************************************************/
	Playlist();		//default constructor
	~Playlist();	//default destructor
	/**
	*  displayMenu(ostream& out = cout)  display the main menu
	*  @param    ostream	&out	[out]	default to cout, output stream
	*  @return   void
	*/
	void displayMenu(ostream& out = cout);
	/**
	*  listPlaylist(ostream& error = cerr, ostream& out = cout)  list all the playlist with the number of songs each playlist have
	*  @param    ostream	&out		[out]	default to cout, output stream
	*  @param    ostream	&error		[out]	default to cerr, output stream
	*  @return   void
	*/
	void listPlaylist(ostream& error = cerr, ostream& out = cout);
	/**
	*  view(arg1, songDatabase, name, artist, album, time, year, ostream& error = cerr, ostream& out = cout)  display all the songs with their descriptions
	*  @param    string			arg1			[in/]   playlist name
	*  @param    vector<string>	&songDatabase	[in/]   vector with all the database
	*  @param    vector<string>	&name			[in/]   vector of song names
	*  @param    vector<string>	&artist			[in/]   vector of artist names
	*  @param    vector<string>	&album			[in/]   vector of album names
	*  @param    vector<string>	&time			[in/]   vector of the song durations
	*  @param    vector<string>	&year			[in/]   vector of when the song is made
	*  @param    ostream		&out			[out]	default to cout, output stream
	*  @param    ostream		&error			[out]	default to cerr, output stream
	*  @return   void
	*/
	void view(string, const vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, ostream& error = cerr, ostream& out = cout);
	/**
	*  create(arg1, ostream& error = cerr, ostream& out = cout)  create a new playlist
	*  @param    string		arg1		[in/]   playlist name
	*  @param    ostream	&out		[out]	default to cout, output stream
	*  @param    ostream	&error		[out]	default to cerr, output stream
	*  @return   void
	*/
	bool create(string, ostream& error = cerr, ostream& out = cout);
	/**
	*  modify(arg1, songDatabase, name, artist, album, time, year, ostream& error = cerr, ostream& out = cout)  modify an existing playlist
	*  @param    string			arg1			[in/]   playlist name
	*  @param    vector<string>	&songDatabase	[in/]   vector with all the database
	*  @param    vector<string>	&name			[in/]   vector of song names
	*  @param    vector<string>	&artist			[in/]   vector of artist names
	*  @param    vector<string>	&album			[in/]   vector of album names
	*  @param    vector<string>	&time			[in/]   vector of the song durations
	*  @param    vector<string>	&year			[in/]   vector of when the song is made
	*  @param    ostream		&out			[out]	default to cout, output stream
	*  @param    ostream		&error			[out]	default to cerr, output stream
	*  @return   void
	*/
	void modify(string, const vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, ostream& error = cerr, ostream& out = cout);
	/**
	*  deletePlaylist(arg1, ostream& error = cerr, ostream& out = cout)  delete an existing playlist
	*  @param    string		arg1		[in/]   playlist name
	*  @param    ostream	&out		[out]	default to cout, output stream
	*  @param    ostream	&error		[out]	default to cerr, output stream
	*  @return   void
	*/
	void deletePlaylist(string, ostream& error = cerr, ostream& out = cout);
	/**
	*  save(arg1, myfile ,ostream& error = cerr, ostream& out = cout)  create a new playlist
	*  @param    string		arg1		[in/]   playlist name
	*  @param    ofstream	myfile		[out]   fileoutput stream
	*  @param    ostream	&out		[out]	default to cout, output stream
	*  @param    ostream	&error		[out]	default to cerr, output stream
	*  @return   void
	*/
	void save(string, ofstream&, vector<string>&, ostream& error = cerr, ostream& out = cout);
	/**
	*  help(ostream& out = cout)			display the help menu
	*  @param    ostream	&out	[out]	default to cout, output stream
	*  @return   void
	*/
	void help(ostream& out = cout);
};
#endif