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
	vector<string> name;		//vector to store all the song in the name field
	vector<string> artist;		//vector to store all the song in the artist field
	vector<string> album;		//vector to store all the song in the album field
	vector<string> genre;		//vector to store all the song in the genre field
	vector<string> size;		//vector to store all the song in the size field
	vector<string> time;		//vector to store all the song in the time field
	vector<string> year;		//vector to store all the song in the year field
	vector<string> comments;	//vector to store all the song in the comments field
	vector<string> songDatabase;//vector to store all the song in the songDatabase field
public:
	/******************************************************************************/
	/*                           Function Prototypes                              */
	/******************************************************************************/
	Song();		//default constructor
	~Song();	//default destructor
	/**
	*  readSongList(argc, argv, ostream& error = cerr, ostream& out = cout)  list all the playlist with the number of songs each playlist have
	*  @param    int		argc		[in]	number of command line arguments
	*  @param    char		*argv[]		[in]	command line arguments
	*  @param    ostream	&out		[out]	default to cout, output stream
	*  @param    ostream	&error		[out]	default to cerr, output stream
	*  @return   void
	*/
	void readSongList(int argc, char* argv[], ostream& error = cout, ostream& out = cout);
	/**
	*  getName()  return vector of song names
	*  @return   vector<string>
	*/
	vector<string> &getName();
	/**
	*  getArtist()  return vector of artist names
	*  @return   vector<string>
	*/
	vector<string> &getArtist();
	/**
	*  getAlbum()  return vector of album names
	*  @return   vector<string>
	*/
	vector<string> &getAlbum();
	/**
	*  getGenre()  return vector of genres
	*  @return   vector<string>
	*/
	vector<string> &getGenre();
	/**
	*  getSize()  return vector of song size
	*  @return   vector<string>
	*/
	vector<string> &getSize();
	/**
	*  getTime()  return vector of song duration
	*  @return   vector<string>
	*/
	vector<string> &getTime();
	/**
	*  getYear()  return vector of the year song was produced in
	*  @return   vector<string>
	*/
	vector<string> &getYear();
	/**
	*  getComments()  return vector of song comments
	*  @return   vector<string>
	*/
	vector<string> &getComments();
	/**
	*  getSongDatabase()  return vector of the entire database
	*  @return   vector<string>
	*/
	vector<string> &getSongDatabase();
};
#endif