// Final Project Milestone 5
// AmaPerishable implementation file
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

#include <iostream>
#include "AmaPerishable.h"

namespace sict {
    // default constructor
    AmaPerishable::AmaPerishable(const char fileTag) : AmaProduct(fileTag) {

    }

    // getter
    const Date& AmaPerishable::expiry() const { return expiry_; }

    // setter
    void AmaPerishable::expiry(const Date& value) { expiry_ = value;  }

    // virtual method implementation
    
    // store
    std::fstream& AmaPerishable::store(std::fstream& file, bool addNewLine) const {
        char delimeter = ',';
        
        // check if the file is opened
        if (file.is_open()) {
            // calls parent function
            AmaProduct::store(file, false);
            
            // store in the following format (example):
            // P,1234,water,1.5,0,1,liter,5,2017/10/12<NEWLINE>
            file << delimeter << expiry();
            if (addNewLine)
                file << std::endl;
        }
        return file;
    }

    // load
    std::fstream& AmaPerishable::load(std::fstream& file) {
        Date tempDate;

        // check if the file is opened
        if (file.is_open()) {
            // calls parent function
            AmaProduct::load(file);

            file >> tempDate;
            file.ignore();

            expiry(tempDate);
        }
        return file;
    }

    // write
    std::ostream& AmaPerishable::write(std::ostream& ostr, bool linear) const {
        // calls parent function
        AmaProduct::write(ostr, linear);

        // check if there's no error
        if (err_.isClear() && !isEmpty()) {
            if (linear) {
                ostr << expiry();
            }
            else {
                ostr << std::endl;
                ostr << "Expiry date: " << expiry();
            }
        }
        return ostr;
    }

    // read
    std::istream& AmaPerishable::read(std::istream& istr) {
        
        //err_.clear();
        Date tempDate;
        // calls parent function
        AmaProduct::read(istr);

        // check for error messages
        if (err_.isClear()) {
            std::cout << "Expiry date (YYYY/MM/DD): ";
            istr >> tempDate;

            // get the appropriate message
            switch (tempDate.errCode()) {
            case CIN_FAILED:
                err_.message("Invalid Date Entry");
                istr.setstate(std::ios::failbit);
                break;
            case YEAR_ERROR:
                err_.message("Invalid Year in Date Entry");
                istr.setstate(std::ios::failbit);
                break;
            case MON_ERROR:
                err_.message("Invalid Month in Date Entry");
                istr.setstate(std::ios::failbit);
                break;
            case DAY_ERROR:
                err_.message("Invalid Day in Date Entry");
                istr.setstate(std::ios::failbit);
                break;
            default:
                break;
            }

            // if there's no Date error, set the value
            if (err_.isClear())
                expiry(tempDate);
        }
        return istr;
    }
}