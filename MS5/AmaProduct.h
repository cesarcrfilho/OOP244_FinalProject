// Final Project Milestone 5
// AmaProduct header file
//
// Version 1.0
// Date: July 19 2017
// Author: Cesar Rodrigues (cda-conceicao-rodrig)
// Seneca ID: 127381168
//
// Description:
// A class for non-perishable items that is inherited
// from the “Product” class and implements the requirements
// of the “Streamable” class (i.e. implements the pure virtual
// methods of the Streamable class)
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include "Product.h"
#include "ErrorMessage.h"
#include <iostream>
#include <fstream>

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                 Class AmaProduct Declaration                //
    /////////////////////////////////////////////////////////////////
    class AmaProduct : public Product {
    private:
        char fileTag_;
        char unit_[11];
    protected:
        ErrorMessage err_;
    public:
        // constructor
        AmaProduct(const char fileTag = 'N');

        // unit
        const char* unit()const;
        void unit(const char* value);

        // implementations from Streamable interface
        // store
        std::fstream& store(std::fstream& file, bool addNewLine = true) const;
        // load
        std::fstream& load(std::fstream& file);
        // write
        std::ostream& write(std::ostream& os, bool linear) const;
        // read
        std::istream& read(std::istream& istr);

    };
}

#endif // !SICT_AMAPRODUCT_H__