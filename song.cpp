#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "song.h"
using namespace std;

Song::Song()
{}
Song::~Song()
{}
void Song::print(ostream& stream,string text)
{
	stream << text;
	return;
}
void Song::readSongList(int argc, char* argv[])
{
	print(cerr, "hey \n");
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
	else
		cerr << "FILE OPENED SUCCESSFULLY" << endl;
	bool checkedHeadings = false;
	string word;
	//string heading; 
	if (input.good())
	{
		while (getline(input, word))
		{
			
			if (checkedHeadings == false)
			{
				//ss.str(word);
				//heading = ss.str();
				//cout << words << endl;
				if (word == "\"Name\"	\"Artist\"	\"Album\"	\"Genre\"	\"Size\"	\"Time\"	\"Year\"	\"Comments\"")
					//	"\"sname\"	\"Artist\"	\"Album\"	\"Genre\"	\"Size\"	\"Time\"	\"Year\"	\"Comments\""
				{
					cerr << "TRUE" << endl;
				}
				else
				{
					cerr << "Headings are wrong or formatted incorrectly." << endl;
					cerr << "The heading fields are tab-separated and enclosed in double-quotes." << endl;
					cerr << "Example:"<<endl<<
						"\"name\"	\"Artist\"	\"Album\"	\"Genre\"	\"Size\"	\"Time\"	\"Year\"	\"Comments\" "<< endl;
					exit(1);
				}
				/*ss << word;
				while (ss >> sstream)
				{

				}*/
				//cout << sstream << endl;
				checkedHeadings = true;
				ss.clear();
			}
			else
			{
				int qPos = 0;
				int findQuotes = word.find('\"', qPos);
				int numQuotes = 0;
				int counter = 0;
				while (findQuotes != string::npos)
				{
					qPos = findQuotes + 1;
					findQuotes = word.find('\"', qPos);
					numQuotes++;
				}
				if (numQuotes != 16)
				{
					cerr << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
					cerr << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
					exit(1);
				}
				//cout << numQuotes << endl;
				int numTab = 0;
				int pos = 0;
				int found = word.find("	", pos);
				bool snameArtist = false;		//use to check the first two field of each line, sname and Artist.
				while (found != string::npos)
				{
					
					//cout << found << " ";
					if (snameArtist == false)
					{
						int length = 0;
						string sname = word.substr(0, found);
						string temp;
						ss << sname;
						while (ss >> temp)
						{
							length += temp.length();
							//cout << length << endl;
						}
						ss.clear();
						//cout << word.substr(0, found) << "dsa-";
						//cout << length << endl;
						if (2 >= length || sname == "" || sname[0] != '\"' || sname[found - 1] != '\"')
						{
							cerr << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							cerr << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							exit(1);
						}
						name.push_back(sname);
						songDatabase.push_back(sname);
						/*if (sname.length()sname != "\"\"" && sname!= "")
						{
							//cout << "true" << endl;
						}
						else{
							cout << sname.length() << endl;
							cout << "false" << endl;
						}*/
					}
					pos=found+1;
					found = word.find("	", pos);
					int length = 0;
					string sname = word.substr(pos, found - pos);
					//cout << sname << "-";
					string temp;
					ss << sname;
					while (ss >> temp)
					{
						length += temp.length();
						//cout << length << endl;
					}
					ss.clear();
					if (snameArtist == false)
					{
						//cout << length << endl;
						if (2 >= length || sname == "" || sname[0] != '\"' || sname[found - pos - 1] != '\"')
						{
							cerr << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							cerr << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							exit(1);
						}
						//cout << word.substr(pos, found-pos) << "dsa" << endl;
						snameArtist = true;
					}
					else if (found != string::npos)
					{
						//cout << found << "," << pos << "," << found - pos - 1 << endl;
						if (2 > length || sname[0] != '\"' || sname[found - pos - 1] != '\"')
						{
							cerr << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							cerr << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							exit(1);
						}
					}
					else
					{
						int temp=0;
						sname = word.substr(pos);
						temp = word.find('\"', pos + 1);
						length = sname.length();
						//cout << length-1 << "-" << temp - pos << endl;
						if (temp == string::npos || length-1!=temp-pos)
						{
							cerr << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							cerr << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							exit(1);
						}
						//cout << length << "-" << sname[0] << "-" << sname[temp - pos] << endl;
						if (2 > length || sname[0] != '\"' || sname[temp-pos] != '\"')
						{
							cerr << "The name field cannot be a blank field.The field also needs to be in quotes." << endl;
							cerr << "A blank field is indicated by an empty set of quotes (not even white spaces should be allowed)." << endl;
							cerr << "No extra space should be allowed outside the field" << endl;
							exit(1);
						}
						comments.push_back(sname);
						
					}
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
					songDatabase.push_back(sname);
					counter++;
					numTab++;
				}
				//cout << numQuotes << endl;
				if (numTab != 7)
				{
					cerr << "ERROR: Each line have to contains eight fields, corresponding to the headings." << endl;
					cerr << "Only the first two fields: name and Artist are mandatory on the line." << endl;
					exit(1);
				}
				//cout << endl;
				//cout << n << endl;

				/*ss << word;
				while (ss >> sstream)
				{
					eightWord.push_back(sstream);
				}
				cout << eightWord.size()<<" ";*/
				/*if (eightWord.size() != 8)
				{
					cerr << "ERROR" << endl;
				}
				eightWord.clear();
				ss.clear();*/
			}

		}
		input.clear();
		input.seekg(65, ios::beg);
		//getline(input, word);
		input >> noskipws >> word;
		//cout << word << endl;
		/*for (int i = 0; i < songDatabase.size(); i++)
		{
			cout << songDatabase[i] << " ";
			if (i != 0 && i % 7 == 0)
			{
				cout << i;
				cout << endl;
			}

		}*/
		//cout << songDatabase.size() << endl;
		cout << songDatabase[8] << endl;
		cout << time[0] << endl;
	}
}
vector<string> &Song::getName()
{
	return name;
}
vector<string> &Song::getArtist()
{
	return artist;
}
vector<string> &Song::getAlbum()
{
	return album;
}
vector<string> &Song::getGenre()
{
	return genre;
}
vector<string> &Song::getSize()
{
	return size;
}
vector<string> &Song::getTime()
{
	return time;
}
vector<string> &Song::getYear()
{
	return year;
}
vector<string> &Song::getComments()
{
	return comments;
}
vector<string> &Song::getSongDatabase()
{
	return songDatabase;
}