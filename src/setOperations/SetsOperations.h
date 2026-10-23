/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */
#pragma once

#include "../DataTypes.h"
#include <cstddef>
#include <string>

namespace Project2::CheckSet {

// For ordinary sets, every nonzero value means the element is present.
Set complement(const Set& A, size_t universalSize = 10);
Set setUnion(const Set& A, const Set& B);
Set setIntersection(const Set& A, const Set& B);
Set setDifference(const Set& A, const Set& B);
Set symmetricDifference(const Set& A, const Set& B);

// Multiset values are counts, so these operations preserve multiplicities.
Set multisetUnion(const Set& A, const Set& B);
Set multisetIntersection(const Set& A, const Set& B);
Set multisetDifference(const Set& A, const Set& B);
Set multisetSum(const Set& A, const Set& B);

// Fuzzy memberships are scaled from 0 (not a member) to UINT32_MAX (fully in).
Set fuzzyComplement(const Set& A);
Set fuzzyUnion(const Set& A, const Set& B);
Set fuzzyIntersection(const Set& A, const Set& B);
Set fuzzySum(const Set& A, const Set& B);

// Each check runs the matching operations and returns a formatted report.
std::string runSetCheck(const Set& A, const Set& B, size_t universalSize = 10);
std::string runMultisetCheck(const Set& A, const Set& B);
std::string runFuzzySetCheck(const Set& A, const Set& B);

} // namespace Project2::CheckSet
