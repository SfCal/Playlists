
#include "DNode.hpp"
#include "Song.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode(t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}

	void DLL::push(string t, string a, int m, int s){
		if (numSongs == 0){
			first = new DNode(t,a,m,s);
			last = first;
			numSongs+=1;
			//cout<<"added first"
		}
		else if (numSongs>=1){
			DNode *n = new DNode(t,a,m,s);
			n->next = NULL;
		    last->next = n;
		    n->prev = last;
			last = n;
			numSongs+=1;
			//cout<<"pushed at the end"
		}
	}

	Song* DLL::pop(){
		DNode *temp = last;
		Song *x = temp->song;
		if (temp->prev==NULL){
			first = NULL;
			last = NULL;
		}
		else{
			temp->prev->next = NULL;
			numSongs--;
		}
		return x;
	}//does what you'd think

	int DLL::remove(string t){
		int count = 0;
		DNode *temp;
		for (temp=first; temp!=NULL; temp=temp->next, count++){
			if (temp->song->title==t){
				if (temp->prev==NULL){
					//cout << "first song" << endl;
					first = temp->next;
				}
				else if (temp->next==NULL){
					//cout << "pop called"<<endl;
				    pop();
				}
				else{
					//cout << "middle song"<<endl;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}
				cout << "Removing: "<< temp->song->title << ", " << temp->song->artist<<"............................."<<temp->song->min<<":"<<temp->song->sec;
				cout << endl;
				delete temp;
			}
		}
			return count;
	}

	void DLL::makeRandom(){
	// randomizes the order of the list
	}
	void DLL::moveUp(string t){
		DNode *temp;
		int count = 0;//makes sure the target title isn't recognized twice within the for loop
		for (temp=first; temp!=NULL; temp=temp->next){
			if (temp->song->title==t){
				if (temp->prev==NULL){
					cout << "first song"<<endl;
					string lastTitle = last->song->title;
					string lastArtist = last->song->artist;
					int lastMin = last->song->min;
					int lastSec = last->song->sec;
					last->song->title = temp->song->title;
					last->song->artist = temp->song->artist;
					last->song->min = temp->song->min;
					last->song->sec = temp->song->sec;
					temp->song->title = lastTitle;
					temp->song->artist = lastArtist;
					temp->song->min = lastMin;
					temp->song->sec = lastSec;
					count++;

				}
				else if (count==0){
					cout << "middle song"<<endl;
					string prevTitle = temp->prev->song->title;
					string prevArtist = temp->prev->song->artist;
					int prevMin = temp->prev->song->min;
					int prevSec = temp->prev->song->sec;
					temp->prev->song->title = temp->song->title;
					temp->prev->song->artist = temp->song->artist;
					temp->prev->song->min = temp->song->min;
					temp->prev->song->sec = temp->song->sec;
					temp->song->title = prevTitle;
					temp->song->artist = prevArtist;
					temp->song->min = prevMin;
					temp->song->sec = prevSec;
				}
			}
		}
	}

	void DLL::moveDown(string t){
		DNode *temp;
		int count = 0;
		for (temp=first; temp!=NULL; temp=temp->next){
			if (temp->song->title==t){
				if (temp->next==NULL){
					//cout << "last song"<<endl;
					string firstTitle = first->song->title;
					string firstArtist = first->song->artist;
					int firstMin = first->song->min;
					int firstSec = first->song->sec;
					first->song->title = temp->song->title;
					first->song->artist = temp->song->artist;
					first->song->min = temp->song->min;
					first->song->sec = temp->song->sec;
					temp->song->title = firstTitle;
					temp->song->artist = firstArtist;
					temp->song->min = firstMin;
					temp->song->sec = firstSec;
				}
				else if(count==0){
					//cout << "middle song"<<endl;
					string nextTitle = temp->next->song->title;
					string nextArtist = temp->next->song->artist;
					int nextMin = temp->next->song->min;
					int nextSec = temp->next->song->sec;
					temp->next->song->title = temp->song->title;
					temp->next->song->artist = temp->song->artist;
					temp->next->song->min = temp->song->min;
					temp->next->song->sec = temp->song->sec;
					temp->song->title = nextTitle;
					temp->song->artist = nextArtist;
					temp->song->min = nextMin;
					temp->song->sec = nextSec;
					count++;
				}
			}
		}
	}
	void DLL::listDuration(int *tm, int *ts){
		// gets the total list duration in minutes (passed in as pointers)
		// and seconds (again, passed in as pointers)
	}

	void DLL::printList(){
		DNode *temp = first;
		while (temp->next!=NULL){
			temp->song->printSong();
			temp = temp->next;
		}
		temp->song->printSong();
	}

	DLL::~DLL(){
	}



