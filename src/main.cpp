/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#include "CheckSet.h"
#include "DataTypes.h"
#include <iostream>

using namespace Project2;

int main()
{
    std::cout << "--- Sets & Multisets Engine ---\n";

    // Ordinary Sets (Universal Set size n = 10)

    // --- Overlapping Sets ---
    Set A1{1, 1, 1, 0, 1, 0, 1, 0, 0, 0};
    Set B1{0, 0, 1, 1, 1, 1, 0, 1, 0, 0};

    std::cout << "--- TEST CASE 1 (Overlapping Sets) ---\n";
    std::cout << CheckSet::runSetCheck(A1, B1, 10) << "\n";

    // --- Disjoint Sets ---
    Set A2{1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    Set B2{0, 0, 0, 0, 0, 0, 0, 0, 1, 1};

    std::cout << "--- TEST CASE 2 (Disjoint Sets) ---\n";
    std::cout << CheckSet::runSetCheck(A2, B2, 10) << "\n";

    // --- Relationship (A c B) ---
    Set A3{0, 1, 0, 1, 0, 1, 0, 0, 0, 0};
    Set B3{0, 1, 1, 1, 1, 1, 0, 0, 0, 0};

    std::cout << "--- TEST CASE 3 (Subset Relationship) ---\n";
    std::cout << CheckSet::runSetCheck(A3, B3, 10) << "\n";

    // Multisets / Bags

    Set mA{3, 2, 0, 1, 0, 4, 0, 0, 0, 0};
    Set mB{1, 4, 2, 3, 0, 0, 0, 0, 0, 0};

    std::cout << "--- MULTISET TEST CASE ---\n";
    std::cout << CheckSet::runMultisetCheck(mA, mB) << "\n";

    std::cout << "--- All Check Runs Complete ---\n";

    return 0;
}
