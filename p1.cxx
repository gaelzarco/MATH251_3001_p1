// file   p1.cxx
// author Gael Zarco <gael.zarco@student.csn.edu>
// date   11-14-2025
// brief  This program demonstrates bitwise AND, OR, and XOR operations using a
//        simple bit-string data type.
// note   Created as part of Project 1 submission for MATH251

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

//------------------------------------------------------------------------------
// DATA TYPE(S)
//------------------------------------------------------------------------------
// Simple abstract data type to represent a bit string and includes bitwise
// operations
struct BitString {
    // CONSTRUCTOR(S)
    // Default BitString constructor
    explicit BitString(std::string data = "") noexcept : m_data(data) {}

    // OPERATOR(S)
    // Better syntax
    friend std::istream& operator>>(std::istream& is, BitString& bstr) {
        is >> bstr.m_data;
        return is;
    }       // operator>>

    // BITWISE OPERATION(S)
    // Returns bit string that is the result of AND operation
    std::string AND(BitString& other) {
        // Ensure data and other strings are equal size
        assert(m_data.size() == other.size());

        // Create result string with size equal to data and other size;
        // initialize values to 0
        std::string result(m_data.size(), '0');

        // Pointers to first bit of each string
        std::string::iterator data_p  = m_data.begin();
        std::string::iterator other_p = other.begin();

        // Iterate through range of all strings and ensure the current bit of
        // data and other is T;
        //
        // if yes -> assign 1 to result;
        // if not -> leave current result bit as 0.
        //
        // NOTE: In propositional logic, AND is T if both p = T & q = T
        for (std::string::iterator result_p = result.begin();
        result_p != result.end(); ++result_p, ++data_p, ++other_p) {
            // Check if current bit in data or current bit in other is T
            *result_p = (*data_p == '1' && *other_p == '1') ? '1' : '0';
        }

        // Return result of the AND operation
        return result;
    }       // AND

    // Returns bit string that is the result of OR operation
    std::string OR(BitString& other) {
        // Ensure data and other strings are equal size
        assert(m_data.size() == other.size());

        // Create result string with size equal to data and other size;
        // initialize values to 0
        std::string result(m_data.size(), '0');

        // Pointers to first bit of each string
        std::string::iterator data_p  = m_data.begin();
        std::string::iterator other_p = other.begin();

        // Iterate through range of all strings and ensure the current bit of
        // data or other is T;
        //
        // if yes -> assign 1 to result;
        // if not -> leave current result bit as 0.
        //
        // NOTE: In propositional logic, OR is T if p = T or q = T or both = T
        for (std::string::iterator result_p = result.begin();
        result_p != result.end(); ++result_p, ++data_p, ++other_p) {
            // Check if current bit in data or current bit in other is T
            *result_p = (*data_p == '1' || *other_p == '1') ? '1' : '0';
        }

        // Return result of the OR operation
        return result;
    }       // OR

    // Returns bit string that is the result of XOR operation
    std::string XOR(BitString& other) {
        // Ensure data and other strings are equal size
        assert(m_data.size() == other.size());

        // Create result string with size equal to data and other size;
        // initialize values to 0
        std::string result(m_data.size(), '0');

        // Pointers to first bits of each string
        std::string::iterator data_p  = m_data.begin();
        std::string::iterator other_p = other.begin();

        // Iterate through range of all strings and ensure the current bit of
        // data and other are not the same;
        //
        // if yes -> assign 1 to result;
        // if not -> leave current result bit as 0.
        //
        // NOTE: In propositional logic, XOR is T if p does not equal q
        for (std::string::iterator result_p = result.begin();
        result_p != result.end(); ++result_p, ++data_p, ++other_p) {
            // Check if current bit in data is equal to current bit in other
            *result_p = (*data_p != *other_p) ? '1' : '0';
        }

        // Return result of the XOR operation
        return result;
    }       // XOR

    // ACCESSOR OPERATION(S)
    // Returns size of BitString
    std::size_t size() noexcept { return m_data.size(); }
    // Returns beginning of BitString
    std::string::iterator begin() noexcept { return m_data.begin(); }
    // Returns end of BitString
    std::string::iterator end() noexcept { return m_data.end(); }

    // DATA MEMBER(S)
    std::string m_data;         // Holds actual bit string
};          // BitString

//------------------------------------------------------------------------------
// FUNCTION PROTOTYPE(S)
//------------------------------------------------------------------------------
// Gets user input for 2 separate BitStrings of equal length
void get_bstr(BitString& a, BitString& b);

//------------------------------------------------------------------------------
// PROGRAM ENTRY-POINT
//------------------------------------------------------------------------------
int main() {
    BitString a;        // BitString a
    BitString b;        // BitString b

    get_bstr(a, b);     // Get user input

    // Output results of each bitwise operation
    std::cout << std::setw(15) << "AND RESULT: " << a.AND(b) << '\n';
    std::cout << std::setw(15) << "OR RESULT: " << a.OR(b) << '\n';
    std::cout << std::setw(15) << "XOR RESULT: " << a.XOR(b) << '\n' << '\n';

    return 0;
}           // main

//------------------------------------------------------------------------------
// FUNCTION DEFINITION(S)
//------------------------------------------------------------------------------
void get_bstr(BitString& a, BitString& b) {
    std::cout << "ENTER BIT-STRING A: ";
    std::cin >> a;

    std::cout << "ENTER BIT-STRING B (MUST BE ";
    std::cout << a.size() << " BITS LONG): ";
    std::cin >> b;
    std::cout << '\n';

    // Ensure BitStrings are of equal length
    assert(a.size() == b.size());
}           // get_bstr

// EOF p1.cxx
