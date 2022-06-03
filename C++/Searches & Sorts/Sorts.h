/*
 * Name: Jack Carson
 * Date Submitted: 2/18/22
 * Lab Section: Section 002
 * Assignment Name: Lab 4: Searches & Sorts
 */

#pragma once
#include <vector>
#include <bits/stdc++.h>

template <class T>
std::vector<T> mergeLists(std::vector<T> sorted, std::vector<T> lst1, std::vector<T> lst2) { // Helper function for mergeSort
    int sortedCount = 0;
    int lst1Count = 0;
    int lst2Count = 0; // Counter to the front index of each vector
    
    while (sortedCount < sorted.size() && lst1Count < lst1.size() && lst2Count < lst2.size()) { // While the sorted vector is not full and lst1 and lst2 are not empty
        if (lst1[lst1Count] < lst2[lst2Count]) {
            sorted[sortedCount] = lst1[lst1Count];
            lst1Count++; 
        } else {
            sorted[sortedCount] = lst2[lst2Count];
            lst2Count++; 
        } // Compare the first element of lst1 and lst2, and add the smaller one to the sorted vector, and increment
        sortedCount++; // Increment the sorted vector counter
    }
    
    // The following while loops add the remaining elements of lst1 and lst2 to the sorted vector

    while (sortedCount < sorted.size() && lst1Count < lst1.size()) { // While the sorted vector is not full and lst1 is not empty
        sorted[sortedCount] = lst1[lst1Count];
        sortedCount++;
        lst1Count++;
    } // Add the rest of lst1 to the sorted vector
    
    while (sortedCount < sorted.size() && lst2Count < lst2.size()) { // While the sorted vector is not full and lst2 is not empty
        sorted[sortedCount] = lst2[lst2Count];
        sortedCount++;
        lst2Count++;
    } // Add the rest of lst2 to the sorted vector 

    return sorted;
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst) {
    int size = lst.size();
    int middle = size / 2;
    std::vector<T> sorted(size); // Create indexes for the size and middle, along with a sorted vector to be returned
    
    if (lst.size() <= 1) { // Base Case
        return lst;
    } else {

    std::vector<T> lst1(lst.begin(), lst.begin() + middle);
    std::vector<T> lst2(lst.begin() + middle, lst.end()); // Split the vector along the middle index

    lst1 = mergeSort(lst1);
    lst2 = mergeSort(lst2); // Recursively call mergeSort on the two halves of the vector, splitting the vector in half until the base case is reached
    sorted = mergeLists(lst, lst1, lst2); // Merge the two sorted vectors together
    }
    return sorted;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst) {
    if (lst.size() <= 1) { // Base Case
        return lst;
    } else {

        int pivot = rand() % lst.size(); // Set the pivot to a random index in the vector
        T pivotValue = lst[pivot]; // Set the pivot value to the value at the pivot index
        lst.erase(lst.begin() + pivot); // Remove the pivot from the vector

        std::vector<T> less;
        std::vector<T> greater;

        for (int i = 0; i < lst.size(); i++) {
            if (lst[i] < pivotValue) {
                less.push_back(lst[i]);
            } else {
                greater.push_back(lst[i]);
            } // Compare each element in the vector to the pivot value, and add to the less or greater vectors
        }

        std::vector<T> sortedLess = quickSort(less);
        std::vector<T> sortedGreater = quickSort(greater); // Recursively call quickSort on the less and greater vectors

        sortedLess.push_back(pivotValue); // Add the pivot value to the sorted less vector
        sortedLess.insert(sortedLess.end(), sortedGreater.begin(), sortedGreater.end()); // Add the sorted greater vector to the sorted less vector
        return sortedLess;
    }
}
