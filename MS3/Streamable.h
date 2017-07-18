// Final Project Milestone 3
// Streamable header file
//
// Version 1.0
// Date: July 11 2017
// Author: Cesar Rodrigues (cda-conceicao-rodrig)
// Seneca ID: 127381168
//
// Description:
// The Streamable class is provided to enforce inherited
// classes to implement functions to work with
// fstream and iostream objects.
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__
#include <iostream>
#include <fstream>

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                  Class Streamable Declaration               //
    /////////////////////////////////////////////////////////////////
    class Streamable {
    public:
        // member functions
        virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const = 0;
        virtual std::fstream& load(std::fstream& file) = 0;
        virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
    };

}

#endif // !SICT_STREAMABLE_H__
