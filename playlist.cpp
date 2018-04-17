/*
 * 	  Implementation of a Playlist for music.
 * 
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 */

#include <iostream>
#include <string>

#include "playlist.h"
#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 */
void Playlist::processCommand() {
	string s,s1,s2;
	while(getline(cin,s))
	{
        string::size_type pos = s.find_first_of(" ");
        //cout << "after pos" << endl;
		s1 = s.substr(0, pos);
		s2 = s.substr(pos+1);
		//cout<<"\ns1 :"<<s1<<"\ns2 :"<<s2;
        if (s1 == "appendSong")
            dll.append(s2);
        else if (s1 == "removeSong")
			dll.remove(s2);
		else if (s1 == "playCurrent")
		{
            cout<<"\nplaying current: ";
            if(!dll.empty()) //check whether list is present before printing
            {
                const string s3= dll.getData();
                cout<<s3<<"\n";
            }
        }
		else if (s1 == "playReverse")
        {
            cout<<"\nplaying reverse: ";
            if(!dll.empty())
            {
                const string s3= dll.getData();
                cout<<"\n"<<s3<<"\n";
            }
            bool x=dll.prev();
            while(x==true)
            {
                const string s3= dll.getData();
                cout<<s3<<"\n";
                x=dll.prev();
            }
        }
        else if (s1 == "playForward")
        {
            cout<<"\nplaying forward: ";
            if(!dll.empty())
            {
                const string s3= dll.getData();
                cout<<"\n"<<s3<<"\n";
            }
            bool y=dll.next();
            while(y==true)
            {
               const string s3= dll.getData();
               cout<<s3<<"\n";
               y=dll.next();
            }
        }
        else if (s1 == "insertBefore")
            dll.insertBefore(s2);
        else if (s1 == "insertAfter")
            dll.insertAfter(s2);
        else if (s1 == "gotoSong")
        {
            dll.find(s2);
        }
		else if (s1 == "gotoLastSong")
			dll.end();
        else if (s1 == "gotoFirstSong")
			dll.begin();
        else if(s1=="nextSong")
            dll.next();
        else if(s1=="prevSong")
            dll.prev();
    }
}

/**
 * The Playlist main loop will process command lines until eof.
 */  
void Playlist::mainLoop() {
   while (!cin.eof()) processCommand();         // process all commands
}

/**
 * The main entry point for the program.
 */
int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}

