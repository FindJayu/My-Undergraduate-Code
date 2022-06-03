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
int linearSearch(std::vector<T> data, T target) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == target) { // iterate the vector (linearly) and check if the target is equal to the data
            return i; // if it is, return the index
        }
    } 
    return -1; // if it isn't, return -1
}

template <class T>
int binarySearch(std::vector<T> data, T target) {
    if (target < data[0] || target > data[data.size() - 1]) {
        return -1;
    } // Return false if the target is less than the first element or greater than the last element (Assuming the vector is sorted)

    int start = 0;
    int end = data.size() - 1; // Set the start and end of the vector to the first and last element

    while (start <= end) {
        int mid = (start + end) / 2; // Set the midpoint to the start and end of the vector, then divide by 2

        if (data[mid] == target) { // If the midpoint is equal to the target, return the midpoint
            return mid; 
        } else if (data[mid] < target) { // If the midpoint is less than the target, set the start to the midpoint + 1 (Excluding the midpoint)
            start = mid + 1;
        } else { // If the midpoint is greater than the target, set the end to the midpoint - 1 (Excluding the midpoint)
            end = mid - 1;
        }
    }
    return -1; // If the target is not found, return -1
}
