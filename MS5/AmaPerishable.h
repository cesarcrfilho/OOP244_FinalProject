// Final Project Milestone 5
// AmaPerishable header file
//
// Version 1.0
// Date: July 19 2017
// Author: Cesar Rodrigues (cda-conceicao-rodrig)
// Seneca ID: 127381168
//
// Description:
// A class inherited from the “AMA_Product” that
// provides expiry date for Perishable items.
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__
#include <iostream>
#include "AmaProduct.h"
#include "Date.h"


namespace sict {
    /////////////////////////////////////////////////////////////////
    //              Class AmaPerishable Declaration                //
    /////////////////////////////////////////////////////////////////
    class AmaPerishable : public AmaProduct {
    private:
        Date expiry_;
    public:
        // default constructor
        AmaPerishable(const char fileTag = 'P');

        // getter
        const Date& expiry() const;
        // setter
        void expiry(const Date &value);

        // virtual method implementation
        std::fstream& store(std::fstream& file, bool addNewLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& ostr, bool linear) const;
        std::istream& read(std::istream& istr);
    };

}

#endif // !SICT_AMAPERISHABLE_H__
