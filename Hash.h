/*******************************************************************
 Raul Garcia
 CPSC 131
 Homwork 3: Hashing Problem
 Date Due: Oct. 28, 2015
 Visual Studios 2012
 Hash Function that operates on the following strings that returns 
 the fewest collisions using the dictionary.txt file.
*******************************************************************/

#ifndef Hash_h
#define Hash_h

#include <iostream>
#include <string>

using namespace std;

struct Item
{
    string key;
    Item * next;
};


class LinkedList
{
private:
    
    Item * head;
    int length;
    
public:
    LinkedList();
    void insertItem( Item * newItem );
    Item * getItem( string itemKey );
    int getLength();
    void printList();
    
    ~LinkedList();
};

class HashTable
{
private:
    LinkedList * array;
    int length;
    int hash( string itemKey );
    
public:
    
    HashTable( int tableLength = 151 );
    void insertItem( Item * newItem );
    
    Item * getItemByKey( string itemKey );
    
    void printTable();
    void printCollisions();
    
    ~HashTable();
};

#endif /*Hash.h*/

