/*
 * Name: Jack Carson
 * Date Submitted: 3/5/2022
 * Lab Section: Section 002
 * Assignment Name: Spell Checker Using a Hash Table
 */
 
#include "stringset.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

 
void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(Stringset& words, string word);
 
int main() {
    Stringset wordlist;
    testStringset(wordlist);
    return 0;
} // main and main function definitions

 
void testStringset(Stringset& words) {
    string choice;
    string word;
    do {
        cout << "I: insert word" << endl;
        cout << "F: find word" << endl;
        cout << "R: remove word" << endl;
        cout << "P: print words in stringset" << endl;
        cout << "Q: quit" << endl;
        cin >> choice;
        switch (choice[0]) {
            case 'I':
            case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
            case 'F':
            case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word)) {
                    cout << word << " in stringset" << endl;
                }
                else {
                    cout << word << " not in stringset" << endl;
                }
                break;
            case 'R':
            case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
            case 'P':
            case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i) {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos) {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
        }
    } while (choice[0] != 'Q' && choice[0] != 'q');
}
 
 
void loadStringset(Stringset& words, string filename) {
    fstream in(filename); // open filename argument for input
    if (!in) {
        cout << "Unable to open file " << filename << endl;
        return; // exit if file == false
    }
    string word;
    while (in >> word) { // read in words from file using insert()
        words.insert(word);
    }
    in.close(); // close file
}


vector<string> spellcheck(Stringset& words, string word) {
    vector<string> suggestions; // vector to hold suggestions
    int wordLength = word.length(); // set the length of the word (No words != length)
    for (int i = 0; i < wordLength; ++i) {
        string temp = word; // create a temp holding the word for comparison
        for (int j = 0; j < 26; ++j) {
            temp[i] = 'a' + j; // change the letter at index i to a-z
            if (words.find(temp)) { // if the word is in the stringset
                if (temp != word) { 
                    suggestions.push_back(temp); // add the word to the suggestions vector
                }
            }
        }
    }
    return suggestions;
} 