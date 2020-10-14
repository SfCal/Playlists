#include "DNode.hpp"
#include "Song.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
#include <random>
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
        //cout<<"pushed at the end";
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
        last = temp->prev;
        numSongs--;
    }
    return x;
}

int DLL::remove(string t){
    int i = 0;
    int count;
    DNode *temp;
    for (temp=first; temp!=NULL; temp=temp->next, i++){
        if (temp->song->title==t){
            if (temp->prev==NULL){
                //cout << "first song" << endl;
                temp->next->prev = NULL;
                first = temp->next;
                count = i;
            }
            else if (temp->next==NULL){
                //cout << "pop called"<<endl;
                pop();
                count = i;
            }
            else{
                //cout << "middle song"<<endl;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                count = i;
            }
            cout << "Removing: "<< temp->song->title << ", " << temp->song->artist<<"............................."<<temp->song->min<<":"<<temp->song->sec;
            cout << endl;
            delete temp;
        }
    }
    //cout << count<< endl;
    return count;
}

void DLL::makeRandom(){
    DNode *temp;
    int random_number;
    int i;
    for (temp=first; temp!=NULL; temp=temp->next){
        random_number = rand()%10;
        //cout << random_number;
        if (random_number<5){
            for (i=0; i<random_number; i++){
                moveDown(temp->song->title);
            }
        }
        else if (random_number>=5){
            for (i=0; i<random_number; i++){
                moveUp(temp->song->title);
            }
        }
    }
}
void DLL::moveUp(string t){
    DNode *temp;
    int count = 0;//makes sure the target title isn't recognized twice within the for loop
    for (temp=first; temp!=NULL; temp=temp->next){
        if (temp->song->title==t){
            if (temp->prev==NULL){
                string temp_t = temp->song->title;
                string temp_a = temp->song->artist;
                int temp_min = temp->song->min;
                int temp_sec = temp->song->sec;
                remove(temp->song->title);
                push(temp_t, temp_a, temp_min, temp_sec);
                /*cout << "first song"<<endl;
                string secondTitle = temp->next->song->title;
                string secondArtist = temp->next->song->artist;
                int secondMin = temp->next->song->min;
                int secondSec = temp->next->song->sec;
                last->song->title = temp->song->title;
                last->song->artist = temp->song->artist;
                last->song->min = temp->song->min;
                last->song->sec = temp->song->sec;
                temp->song->title = secondTitle;
                temp->song->artist = secondArtist;
                temp->song->min = secondMin;
                temp->song->sec = secondSec;
                count++;*/

            }
            else if (count==0){
                //cout << "middle song"<<endl;
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
                string temp_t = temp->song->title;
                string temp_a = temp->song->artist;
                int temp_min = temp->song->min;
                int temp_sec = temp->song->sec;
                remove(temp->song->title);
                DNode *n = new DNode(temp_t,temp_a,temp_min,temp_sec);
                n->next = first;
                n->prev = NULL;

                first->prev = n;
                first = n;
                numSongs+=1;
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
    DNode *temp;
    for (temp=first; temp!=NULL; temp=temp->next){
        *tm+=temp->song->min;
        *ts+=temp->song->sec;
    }
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
    DNode *temp;
    for (temp=first; temp!=NULL; temp=temp->next){
        //cout << "deleting: "<<temp->song->title<<endl;
        delete temp;
    }
}



