/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */
#pragma once

#include "DataTypes.h"
#include <string>

namespace Project2::CheckSet {

// Ordinary Set Operations
Set complement(const Set& A, size_t universalSize = 10);
Set setUnion(const Set& A, const Set& B);
Set setIntersection(const Set& A, const Set& B);
Set setDifference(const Set& A, const Set& B);
Set symmetricDifference(const Set& A, const Set& B);

// Multiset Operations
Set multisetUnion(const Set& A, const Set& B);
Set multisetIntersection(const Set& A, const Set& B);
Set multisetDifference(const Set& A, const Set& B);
Set multisetSum(const Set& A, const Set& B);

// Display/Helpers
std::string runSetCheck(const Set& A, const Set& B, size_t universalSize = 10);
std::string runMultisetCheck(const Set& A, const Set& B);
} // namespace Project2::CheckSet
