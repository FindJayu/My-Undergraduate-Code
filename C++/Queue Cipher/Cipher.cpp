// Jack Carson
// CPSC 1070
// Project 3
// 25 October 2021

#include <bits/stdc++.h>
#include "Queue.h"
#include "Cipher.h"
using namespace std;

/* Helper function printing the contents of the queue
based on the provided range */
void Cipher::getCipher() {
    cipher.printQueue(0, cipherSize); 
}

/* Sets the cipher, and the parity decode cipher based
on the parameters size of the cipher and the provided key.
The queue is cleared beforehand and the cipherSize is
reset to the input size to prevent unnecessary cipher keys */
void Cipher::setCipher(int size, int key[]) {
    cipher.clearQueue();
    if (size < 0) {
        cout << "Cipher size must be greater than 0." << endl;
        return;
    }
    cipherSize = size;

    for (int i = 0; i < cipherSize; i++) {
        cipher.enqueue(key[i]);
        decode.enqueue(key[i]);
    }
}

/* Encodes the parameter string by iterating each character in
the string, inputting spaces, and ignoring non alphabet characters.
The letters in the char array are then set to uppercase, and the
first element in the cipher queue is set to an integer value, and 
pushed into the back of the queue. The encoded string is then created
by using a caesar cipher algorithm with returns an additive 
character using the modulus operator to remain within int 65 - 97. */
string Cipher::encodeMessage(string s) {    
    int i = 0;
    string encodedMessage = ""; 

    while (i < s.length()) {
        if (s[i] == ' ') {
            encodedMessage += ' ';
            i++;
        } 
        if (s[i] < 'A' || s[i] > 'z') {
            i++;
            continue; 
        } else {
            int letter = toupper(s[i]);
            int shift = cipher.dequeue(i);
            cipher.enqueue(shift);
            encodedMessage += (letter + shift + 26) % 26 + 'A';
            i++;
        }
    }
    return encodedMessage;
}

/* Performs the same operation as the decodeMessage function, but
performs the reverse modulo operation to return back to the first
inputted char in uppercase, while allowing spaces and ignoring
non alphabet characters. The decode Queue object is used instead
of the cipher Queue so parity is maintained between cipher shifts */
string Cipher::decodeMessage(string s) {
    int i = 0;
    string decodedMessage = ""; 

    while (i < s.length()) {
        if (s[i] == ' ') {
            decodedMessage += ' ';
            i++;
        } 
        if (s[i] < 'A' || s[i] > 'z') {
            i++;
            continue; 
        } else {
            int letter = toupper(s[i]);
            int shift = decode.dequeue(i);
            decode.enqueue(shift);    
            decodedMessage += (letter - shift + 26) % 26 + 'A';
            i++;
        }
    }
    return decodedMessage;
}


