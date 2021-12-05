// Jack Carson
// CPSC 1070
// CoLab 5C
// 3 November 2021

#include <bits/stdc++.h>
#include "AnalyzeHand.h"
using namespace std;

/* Concatenates a string based on the calling object's vector elements*/
string AnalyzeHand::toString() {
    string str = "";
    str += "\t["; 
    for (int i = 0; i < Hand.size(); i++) {
        str += Hand[i].toString() += ", ";
    }
    str += "]\n";
    return str;
}

