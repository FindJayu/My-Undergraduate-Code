// Jack Carson
// CPSC 1070
// CoLab 5C
// 3 November 2021

#include <bits/stdc++.h>
#include "BlackjackRules.h"
#include "AnalyzeHand.h"
using namespace std;

/* Reassigns face values and adds to a counter, returns true if the counter is 21 or under */
bool BlackjackRules::isWon() {
    int handCount = 0;
    for (int i = 0; i < Hand.size(); i++) {
        if (Hand[i].getFace() > 9) {
            handCount += 10;
            continue;
        }
        if (Hand[i].getFace() <= 9) {
            handCount += Hand[i].getFace() + 1;
            continue;
        }
    }
    if (handCount > 21) {
        return false;
    } 
    return true;  
} 