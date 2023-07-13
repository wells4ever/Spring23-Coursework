#include <iostream>
#include "C:\Users\a00573952\Downloads\LinkedList.h"

using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::endl;

struct Song
{
    string composerName;
    string songName;

    Song() {};
    Song(string composerName, string songName)
        :composerName(composerName),
        songName(songName)
    {
    }
    friend ostream& operator<<(ostream& output, const Song& s)
    {
        output << "Composer: " << s.composerName << "\tSong: " << s.songName;
        return output;
    }
    friend bool operator == (const Song& s1,const Song& s2 )
    {
        return (s1.composerName == s2.composerName || s1.songName == s2.songName);
    }
    
};

int main()
{
    LinkedList <Song> songs;

    songs.insertFirst(Song("Electric Callboy", "We Got the Moves"));
    songs.insertFirst(Song("Dexter and the Moonrocks", "Couch"));
    songs.insertFirst(Song("Grandson", "Blood in the Water"));

    cout << "First node info, using getNode -> info method: " << endl;
    cout << songs.getNode(0)->info.composerName << endl;
    cout << songs.getNode(0)->info.songName << endl;

    cout << "\nCurrent number of nodes: " << endl;
    cout << songs.length() << endl;

    cout << "\nCurrent List via 'print' method: " << endl;
    songs.print();

    Song song4("SmashMouth", "Allstar");
    songs.insertAfter(songs.getNode(2)->link, song4);

    cout << "\nCurrent List after insertAfter method: " << endl;
    songs.print();

    cout << "\nSearching for 'Allstar' by Smashmouth.." << endl;
    cout << std::boolalpha;
    cout << songs.search(song4);
    
   

    
}