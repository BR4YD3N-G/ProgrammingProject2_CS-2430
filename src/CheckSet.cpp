/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#include "CheckSet.h"
#include <sstream>
#include <vector>

namespace Project2::CheckSet {

// Helpers
static std::string toBitString(const std::vector<uint32_t>& contents)
{
    std::string s = "[";
    for (size_t i = 0; i < contents.size(); ++i) {
        s += std::to_string(contents[i]);
        if (i + 1 < contents.size()) {
            s += ", ";
        }
    }
    s += "]";
    return s;
}

static std::string toElementListing(const std::vector<uint32_t>& contents)
{
    std::string s = "{";
    bool first = true;
    for (size_t i = 0; i < contents.size(); ++i) {
        if (contents[i] != 0) {
            if (!first) {
                s += ", ";
            }
            s += "e" + std::to_string(i);
            first = false;
        }
    }
    s += "}";
    return first ? "∅" : s;
}

static std::string toMultisetListing(const std::vector<uint32_t>& contents)
{
    std::string s = "{";
    bool first = true;
    for (size_t i = 0; i < contents.size(); ++i) {
        if (contents[i] > 0) {
            if (!first) {
                s += ", ";
            }
            s += std::to_string(contents[i]) + "·e" + std::to_string(i);
            first = false;
        }
    }
    s += "}";
    return first ? "∅" : s;
}

// Implementation
Set complement(const Set& A, size_t universalSize)
{
    Set result = {std::vector<uint32_t>(universalSize, 0)};
    for (size_t i = 0; i < universalSize; ++i) {
        int val = (i < A.contents.size()) ? A.contents[i] : 0;
        result.contents[i] = !val;
    }
    return result;
}

Set setUnion(const Set& A, const Set& B)
{
    size_t size = Set::maxSize(A, B);
    Set result = {std::vector<uint32_t>(size, 0)};
    for (size_t i = 0; i < size; ++i) {
        int valA = (i < A.size()) ? A.contents[i] : 0;
        int valB = (i < B.size()) ? B.contents[i] : 0;
        result.contents[i] = (valA || valB) ? 1 : 0;
    }
    return result;
}

Set setIntersection(const Set& A, const Set& B)
{
    size_t size = Set::maxSize(A, B);
    Set result = {std::vector<uint32_t>(size, 0)};
    for (size_t i = 0; i < size; ++i) {
        int valA = (i < A.contents.size()) ? A.contents[i] : 0;
        int valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = (valA && valB) ? 1 : 0;
    }
    return result;
}

Set setDifference(const Set& A, const Set& B)
{
    size_t size = Set::maxSize(A, B);
    Set result{std::vector<uint32_t>(size, 0)};
    for (size_t i = 0; i < size; ++i) {
        int valA = (i < A.contents.size()) ? A.contents[i] : 0;
        int valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = (valA && !valB) ? 1 : 0;
    }
    return result;
}

Set symmetricDifference(const Set& A, const Set& B)
{
    size_t size = Set::maxSize(A, B);
    Set result{std::vector<uint32_t>(size, 0)};
    for (size_t i = 0; i < size; ++i) {
        int valA = (i < A.contents.size()) ? A.contents[i] : 0;
        int valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = (valA ^ valB) ? 1 : 0;
    }
    return result;
}

std::string runSetCheck(const Set& A, const Set& B, size_t universalSize)
{
    std::ostringstream out;
    out << "========================================\n";
    out << "     Ordinary Set Operations (n = " << universalSize << ")\n";
    out << "========================================\n";
    out << "Set A Bit Array: " << toBitString(A.contents) << " -> " << toElementListing(A.contents)
        << "\n";
    out << "Set B Bit Array: " << toBitString(B.contents) << " -> " << toElementListing(B.contents)
        << "\n\n";

    Set notA = complement(A, universalSize);
    Set un = setUnion(A, B);
    Set inter = setIntersection(A, B);
    Set diff = setDifference(A, B);
    Set sym = symmetricDifference(A, B);

    out << "NOT(A):        " << toBitString(notA.contents) << " -> "
        << toElementListing(notA.contents) << "\n";
    out << "A U B:         " << toBitString(un.contents) << " -> " << toElementListing(un.contents)
        << "\n";
    out << "A n B:         " << toBitString(inter.contents) << " -> "
        << toElementListing(inter.contents) << "\n";
    out << "A - B:         " << toBitString(diff.contents) << " -> "
        << toElementListing(diff.contents) << "\n";
    out << "A (+) B:       " << toBitString(sym.contents) << " -> "
        << toElementListing(sym.contents) << "\n";

    return out.str();
}

Set multisetUnion(const Set& A, const Set& B)
{
    size_t size = Set::maxSize(A, B);
    Set result{std::vector<uint32_t>(size, 0)};
    for (size_t i = 0; i < size; ++i) {
        int valA = (i < A.contents.size()) ? A.contents[i] : 0;
        int valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = std::max(valA, valB);
    }
    return result;
}

Set multisetIntersection(const Set& A, const Set& B)
{
    size_t size = Set::maxSize(A, B);
    Set result{std::vector<uint32_t>(size, 0)};
    for (size_t i = 0; i < size; ++i) {
        int valA = (i < A.contents.size()) ? A.contents[i] : 0;
        int valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = std::min(valA, valB);
    }
    return result;
}

Set multisetDifference(const Set& A, const Set& B)
{
    size_t size = Set::maxSize(A, B);
    Set result{std::vector<uint32_t>(size, 0)};
    for (size_t i = 0; i < size; ++i) {
        int valA = (i < A.contents.size()) ? A.contents[i] : 0;
        int valB = (i < B.contents.size()) ? B.contents[i] : 0;
        result.contents[i] = std::max(0, valA - valB);
    }
    return result;
}

Set multisetSum(const Set& A, const Set& B)
{
    size_t size = Set::maxSize(A, B);
    Set result{std::vector<uint32_t>(size, 0)};
    for (size_t i = 0; i < size; ++i) {
        int valA = (i < A.contents.size()) ? A.contents[i] : 0;
        int valB = (i < B.contents.size()) ? B.contents[i] : 0;
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
    printOut << "Multiset A Counts: " << toBitString(A.contents) << " -> "
             << toMultisetListing(A.contents) << "\n";
    printOut << "Multiset B Counts: " << toBitString(B.contents) << " -> "
             << toMultisetListing(B.contents) << "\n\n";

    Set mUn = multisetUnion(A, B);
    Set mInter = multisetIntersection(A, B);
    Set mDiffAB = multisetDifference(A, B);
    Set mDiffBA = multisetDifference(B, A);
    Set mSum = multisetSum(A, B);

    printOut << "Multiset Union (A u B):        " << toBitString(mUn.contents) << " -> "
             << toMultisetListing(mUn.contents) << "\n";
    printOut << "Multiset Intersection (A n B): " << toBitString(mInter.contents) << " -> "
             << toMultisetListing(mInter.contents) << "\n";
    printOut << "Multiset Difference (A - B):   " << toBitString(mDiffAB.contents) << " -> "
             << toMultisetListing(mDiffAB.contents) << "\n";
    printOut << "Multiset Difference (B - A):   " << toBitString(mDiffBA.contents) << " -> "
             << toMultisetListing(mDiffBA.contents) << "\n";
    printOut << "Multiset Sum (A (+) B):        " << toBitString(mSum.contents) << " -> "
             << toMultisetListing(mSum.contents) << "\n";

    return printOut.str();
}
} // namespace Project2::CheckSet
