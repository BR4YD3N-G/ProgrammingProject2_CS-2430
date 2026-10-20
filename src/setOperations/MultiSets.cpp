/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#include "RepresentationHelper.h"
#include "SetsOperations.h"
#include <sstream>

namespace Project2::CheckSet {

Set multisetUnion(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result = Set(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = std::max(valA, valB);
    }
    return result;
}

Set multisetIntersection(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = std::min(valA, valB);
    }
    return result;
}

Set multisetDifference(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = valA > valB ? valA - valB : 0;
    }
    return result;
}

Set multisetSum(const Set& A, const Set& B)
{
    const size_t size = Set::maxSize(A, B);
    Set result(std::vector<uint32_t>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        const uint32_t valA = (i < A.contents.size()) ? A.contents[i] : 0;
        const uint32_t valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = valA + valB;
    }
    return result;
}

std::string runMultisetCheck(const Set& A, const Set& B)
{
    std::ostringstream printOut;
    printOut << "========================================\n";
    printOut << "     Multiset (Bag) Operations\n";
    printOut << "========================================\n";
    printOut << "Multiset A Counts: " << helper::toBitString(A.contents) << " -> "
             << helper::toMultisetListing(A.contents) << "\n";
    printOut << "Multiset B Counts: " << helper::toBitString(B.contents) << " -> "
             << helper::toMultisetListing(B.contents) << "\n\n";

    const Set mUn = multisetUnion(A, B);
    const Set mInter = multisetIntersection(A, B);
    const Set mDiffAB = multisetDifference(A, B);
    const Set mDiffBA = multisetDifference(B, A);
    const Set mSum = multisetSum(A, B);

    printOut << "Multiset Union (A u B):        " << helper::toBitString(mUn.contents) << " -> "
             << helper::toMultisetListing(mUn.contents) << "\n";
    printOut << "Multiset Intersection (A n B): " << helper::toBitString(mInter.contents) << " -> "
             << helper::toMultisetListing(mInter.contents) << "\n";
    printOut << "Multiset Difference (A - B):   " << helper::toBitString(mDiffAB.contents) << " -> "
             << helper::toMultisetListing(mDiffAB.contents) << "\n";
    printOut << "Multiset Difference (B - A):   " << helper::toBitString(mDiffBA.contents) << " -> "
             << helper::toMultisetListing(mDiffBA.contents) << "\n";
    printOut << "Multiset Sum (A (+) B):        " << helper::toBitString(mSum.contents) << " -> "
             << helper::toMultisetListing(mSum.contents) << "\n";

    return printOut.str();
}

} // namespace Project2::CheckSet
