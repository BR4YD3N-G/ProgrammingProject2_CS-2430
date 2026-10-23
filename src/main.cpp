/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#include "DataTypes.h"
#include "setOperations/SetsOperations.h"
#include <iostream>
#include <limits>

using namespace Project2;

int main()
{
    std::cout << "--- Sets & Multisets Engine ---\n";

    // These ordinary-set examples use ten positions for the universe e0 through e9.

    // This pair overlaps, so the output shows both shared and unshared elements.
    Set A1{1, 1, 1, 0, 1, 0, 1, 0, 0, 0};
    Set B1{0, 0, 1, 1, 1, 1, 0, 1, 0, 0};

    std::cout << "--- TEST CASE 1 (Overlapping Sets) ---\n";
    std::cout << CheckSet::runSetCheck(A1, B1, 10) << "\n";

    // There are no shared elements in this pair, so its intersection is empty.
    Set A2{1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    Set B2{0, 0, 0, 0, 0, 0, 0, 0, 1, 1};

    std::cout << "--- TEST CASE 2 (Disjoint Sets) ---\n";
    std::cout << CheckSet::runSetCheck(A2, B2, 10) << "\n";

    // Every element in A3 also appears in B3, making A3 a subset of B3.
    Set A3{0, 1, 0, 1, 0, 1, 0, 0, 0, 0};
    Set B3{0, 1, 1, 1, 1, 1, 0, 0, 0, 0};

    std::cout << "--- TEST CASE 3 (Subset Relationship) ---\n";
    std::cout << CheckSet::runSetCheck(A3, B3, 10) << "\n";

    // These values are occurrence counts, not just present-or-absent flags.

    Set mA{3, 2, 0, 1, 0, 4, 0, 0, 0, 0};
    Set mB{1, 4, 2, 3, 0, 0, 0, 0, 0, 0};

    std::cout << "--- MULTISET TEST CASE ---\n";
    std::cout << CheckSet::runMultisetCheck(mA, mB) << "\n";

    std::cout << "--- All Check Runs Complete ---\n";

    // Fuzzy values use the full uint32_t range: zero is out and max is fully in.
    // The report converts these scaled values to decimals between zero and one.

    constexpr uint32_t membershipMax = std::numeric_limits<uint32_t>::max();
    Set fA{membershipMax / 4,
           membershipMax / 2,
           3 * (membershipMax / 4),
           membershipMax,
           0,
           0,
           0,
           0,
           0,
           0};
    Set fB{membershipMax / 2,
           membershipMax / 4,
           membershipMax / 2,
           3 * (membershipMax / 4),
           membershipMax,
           0,
           0,
           0,
           0,
           0};

    std::cout << "--- FUZZY TEST CASE ---\n";
    std::cout << CheckSet::runFuzzySetCheck(fA, fB) << "\n";

    std::cout << "--- All Check Runs Complete ---\n";

    return 0;
}
