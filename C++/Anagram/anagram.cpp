/*
 * Name: Jack Carson
 * Date Submitted:
 * Assignment Name: Single-Word Anagram Finder
 */

#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);
vector<string> anagram(string word, vector<string> wordlist);

int main() {
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words = loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++) {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename) {
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if (inFile.is_open()) {
        while (getline(inFile,word)) {
            if (word.length() > 0) {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

// Function finding anagrams
vector<string> anagram(string word, vector<string> wordlist) {
    vector<string> anagrams; // vector of strings containing anagrams
    unordered_map<char, int> letterCounts; // map of letter counts (key: letter, value: count)

    for (int i = 0; i < word.length(); i++) {
        letterCounts[word[i]]++; // Determine the number of times each letter occurs in the word
    }
    for (int i = 0; i < wordlist.size(); i++) {
        unordered_map<char, int> tempCounts; // map of letter counts (key: letter, value: count)
        for (int j = 0; j < wordlist[i].length(); j++) {
            tempCounts[wordlist[i][j]]++; // Determine the number of times each letter occurs in the nth word
        }
        if (tempCounts == letterCounts) { // If the letter counts are the same, the words are anagrams
            anagrams.push_back(wordlist[i]); // Add the nth word to the vector of anagrams
        }
    }
    return anagrams; // Return the vector of anagrams
}
