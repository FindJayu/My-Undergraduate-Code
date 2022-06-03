/*
 * Name: Jack Carson
 * Date Submitted: 3/5/2022
 * Lab Section: Section 002
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include "stringset.h"
#include <bits/stdc++.h>

Stringset::Stringset() : table(4), num_elems(0), size(4) {} // constructor

vector<list<string>> Stringset::getTable() const {
    return table;
}

int Stringset::getNumElems() const {
    return num_elems;
}

int Stringset::getSize() const {
    return size;
} // functions used to test Stringset functionality



unsigned int hashFunction(string & word, int tableSize) {
    unsigned int hashVal = 0;
    for (int i = 0; i < word.length(); i++ ) {
        hashVal = 37 * hashVal + word[i];
    }
    return hashVal % tableSize;
}  // helper hash function (from textbook pg. 195)


void Stringset::insert(string word) { 
    if (num_elems == size) { // if table is full
        Stringset temp;
        temp.size = size * 2; 
        temp.table = vector<list<string>>(temp.size); // create temp table & double size
        for (int i = 0; i < size; i++) {
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                temp.insert(*it); // insert all elements from old table into temp table
            }
        }
        table = temp.table; // set table to temp table
        size = temp.size; // set size to temp size
    }

    int index = hashFunction(word, size); // hash to an index
    if (table[index].empty()) {
        table[index].push_back(word);
        num_elems++; // add word to table at empty index
    }
    else {
        for (list<string>::iterator i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == word) {
                return;
            }
        }
        table[index].push_back(word);
        num_elems++;
    } // linear probe for collision resolution (look for word in table, if not found, add word to first empty index from start)
}


bool Stringset::find(string word) { 
    int index = hashFunction(word, size); // hash to an index
    if (table[index].empty()) {
        return false; // if table is empty, return false
    }
    else {
        for (list<string>::iterator i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == word) {
                return true;
            } // if word is found, return true
        }
        return false;
    }
}


void Stringset::remove(string word) { 
    int index = hashFunction(word, size); // hash to an index
    if (table[index].empty()) {
        return; // if table is empty, return
    }
    else {
        for (list<string>::iterator i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == word) {
                table[index].erase(i); // remove word from table
                num_elems--; // decrement num_elems
                return;
            }
        } 
    }
}