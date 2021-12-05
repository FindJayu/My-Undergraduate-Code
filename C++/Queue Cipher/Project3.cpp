// Jack Carson
// CPSC 1070
// Project 3
// 25 October 2021

#include <bits/stdc++.h>
#include "Queue.h"
#include "Cipher.h"
using namespace std;

/* Driver function displaying the queue with a key sized 100
along with a messy string and the original, encoded, and decoded messages
:)  */
int main() { 
    Cipher a; 
    int c[100] = {99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};

    a.setCipher(100, c); 

    string test = " dis. is? a: test! of- encryption! powerszzz,";
    string encoded = a.encodeMessage(test);
    string decoded = a.decodeMessage(encoded);

    cout << "Original message: " << test << endl; 
    cout << "Encoded message: " << encoded << endl;
    cout << "Decoded message: " << decoded << endl;
}