
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
			last = n;
			numSongs+=1;
			//cout<<"pushed at the end"
		}
	}

	Song* DLL::pop(){
		DNode *temp = last;
		Song *x = temp->song;
		if (numSongs==1){
			first = NULL;
			last = NULL;
		}
		else if (numSongs>1){
			last = last->prev;
			delete temp;
			last->next = NULL;
			numSongs--;
		}
		return x;
	}//does what you'd think

	int DLL::remove(string t){
		int count = 0;
		DNode *temp = first;
		while (temp->song->title!=t){
			temp = temp->next;
			count++;
		}
		if (count == numSongs){
			pop();
			return 0; //didn't know what to return an int for so I used it to distinguish btw pop() and remove()
		}
		else{
			cout << "Removing: "<< temp->song->title << ", " << temp->song->artist<<"............................."<<temp->song->min<<":"<<temp->song->sec;
			cout << endl;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			return 1;
		}
	}
	void DLL::makeRandom(){
	// randomizes the order of the list
	}
	void DLL::moveUp(string t){
		// moves song with title s up one in the playlist.
	}
			                        //If it is at the beginning of the list,
			                        //it will be moved to the end of the list.

	void DLL::moveDown(string t){
		//moves song with title s down one in the playlist.
	}
									//If it is at the end of the list, it will move to
									//beginning of the list.
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



