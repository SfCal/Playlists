#include "DNode.hpp"
#include "Song.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;
#include <string>

DNode::DNode(){
    prev = NULL;
    next = NULL;
    song = new Song();
}

DNode::DNode(string s, string a, int lenmin, int lensec){
    prev = NULL;
    next = NULL;
    song = new Song(s,a,lenmin,lensec);
}
