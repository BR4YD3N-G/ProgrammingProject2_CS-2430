/*
 *    Team name: Coding Cadets
 *    Team members: [Brayden Graham, Todd Dharni, Thaddeus Schelp]
 *    Course and section: CS 2430-002
 *    Project name: Programming Project 2 – Fall 2026
 *    Primary author: Brayden Graham
 */

#pragma once

#include <algorithm>
#include <initializer_list>
#include <vector>

struct Set
{
    // The value at each index describes the matching element e0, e1, e2, and so on.
    // Ordinary sets use 0/1, multisets use counts, and fuzzy sets use scaled memberships.
    std::vector<uint32_t> contents{};

    // This lets the examples build a set directly from a list of values.
    Set(const std::initializer_list<uint32_t> list) : contents(list) {}

    // Operations use this constructor when they have built the result vector.
    explicit Set(std::vector<uint32_t>&& vec) : contents(std::move(vec)) {}

    // The number of vector positions is the number of represented elements.
    [[nodiscard]] uint32_t size() const { return contents.size(); }

    // Binary operations use the longer input so trailing elements are not dropped.
    static uint32_t maxSize(const Set& A, const Set& B)
    {
        return std::max(A.contents.size(), B.contents.size());
    }
};
