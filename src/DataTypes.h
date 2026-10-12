/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

struct Set
{
    char setIdentifier{'A'};
    std::vector<int> contents{};

    size_t size() const { return contents.size(); }

    static size_t maxSize(const Set& A, const Set& B)
    {
        return std::max(A.contents.size(), B.contents.size());
    }
};
