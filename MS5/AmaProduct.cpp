// Final Project Milestone 5
// AmaProduct implementation file
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"
#include "ErrorMessage.h"
#include "AmaProduct.h"

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                        Member Functions                     //
    /////////////////////////////////////////////////////////////////

    // constructor
    AmaProduct::AmaProduct(const char fileTag) { fileTag_ = fileTag; }

    // unit
    const char* AmaProduct::unit() const { return unit_; }

    // unit overload
    void AmaProduct::unit(const char* value) {
        // copy the value to unit_ member
        strncpy(unit_, value, strnlen(value, 250) + 1);
    }

    // implementations from Streamable interface
    // store
    std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine) const {
        char del = ','; // delimeter

        if (file.is_open()) {
            // fileTag,sku,name,price,taxed,quantity,unit,quantity needed<New line>
            file << fileTag_ << del << sku() << del << name() << del << price() << del << taxed() << del << quantity() << del << unit() << del << qtyNeeded();

            // add a new line if true
            if (addNewLine)
                file << std::endl;
        }
        return file;
    }

    // load
    std::fstream& AmaProduct::load(std::fstream& file) {
        char buffer[250];
        char delimeter = ',';
        double doubleAux = 0;
        int intAux = 0;
        bool boolAux = false;


        // check if the file is opened
        if (file.is_open()) {
            // load sku
            file.getline(buffer, 250, delimeter);
            sku(buffer);
            buffer[0] = char(0); // clear the buffer variable

            // load name
            file.getline(buffer, 250, delimeter);
            name(buffer);
            buffer[0] = char(0); // clear the buffer variable

            // load price
            file >> doubleAux >> delimeter;
            price(doubleAux);

            // load taxed
            file >> boolAux >> delimeter;
            taxed(boolAux);

            // load quantity
            file >> intAux >> delimeter;
            quantity(intAux);

            // load unit
            file.getline(buffer, 250, delimeter);
            unit(buffer);
            buffer[0] = char(0); // clear the buffer variable

            // load quantity needed
            file >> intAux >> delimeter;
            qtyNeeded(intAux);
        }

        return file;

    }

    // write
    std::ostream& AmaProduct::write(std::ostream& ostr, bool linear) const {
        char bar = '|';

        if (!err_.isClear()) {
            ostr << err_;
        }
        else {
            if (linear) {
                // print in this format example:
                // 1234   |Box                 | 139.50|   1|kg        |   5|

                // sku
                ostr.setf(std::ios::left);
                ostr.width(MAX_SKU_LEN);
                ostr.fill(' ');
                ostr << sku() << bar;

                // name
                ostr.setf(std::ios::left);
                ostr.width(20);
                ostr.fill(' ');
                ostr << name() << bar;

                // cost
                ostr.setf(std::ios::right);
                ostr.setf(std::ios::fixed);
                ostr.precision(2);
                ostr.width(7);
                ostr.fill(' ');
                ostr << cost() << bar;
                ostr.unsetf(std::ios::right);
                ostr.unsetf(std::ios::fixed);

                // quantity
                ostr.setf(std::ios::right);
                ostr.width(4);
                ostr.fill(' ');
                ostr << quantity() << bar;
                ostr.unsetf(std::ios::right);
                
                // unit
                ostr.setf(std::ios::left);
                ostr.width(10);
                ostr.fill(' ');
                ostr << unit() << bar;
                ostr.unsetf(std::ios::left);

                // quantity needed
                ostr.setf(std::ios::right);
                ostr.width(4);
                ostr.fill(' ');
                ostr << qtyNeeded() << bar;
                ostr.unsetf(std::ios::right);
            }
            else {
                /* print in this format example:
                    Sku: 1234
                    Name: box
                    Price: 123.45
                    Price after tax: 139.50
                    Quantity On Hand: 1 kg
                    Quantity Needed: 5
                    NO NEW LINE
                */

                // sku
                ostr << "Sku: " << sku() << std::endl;
                // name
                ostr << "Name: " << name() << std::endl;
                // price
                ostr.setf(std::ios::fixed);
                ostr << "Price: " << price() << std::endl;
                // price after tax
                ostr << "Price after tax: ";
                taxed() ? ostr << cost() : ostr << "N/A";
                ostr << std::endl;
                ostr.unsetf(std::ios::fixed);
                // quantity and unit
                ostr << "Quantity On Hand: " << quantity() << " " << unit() << std::endl;
                // quantity needed
                ostr << "Quantity Needed: " << qtyNeeded();
            }
        }

        return ostr;
    }

    // read
    std::istream& AmaProduct::read(std::istream& istr) {
        /* receive data from user input as follows: 
            Sku: 1234<ENTER>
            Name: box<ENTER>
            Unit: kg<ENTER>
            Taxed? (y/n): y<ENTER>
            Price: 123.45<ENTER>
            Quantity On hand: 1<ENTER>
            Quantity Needed: 5<ENTER>
        */

        char skuTmp[250];
        char nameTmp[250];
        char unitTmp[250];
        char taxedTmp;
        double priceTmp = 0;
        int quantityTmp = 0;
        int qtyNeededTmp = 0;

        // clear the error
        err_.clear();
        

        // sku
        std::cout << "Sku: ";
        istr >> skuTmp;
        // name
        std::cout << "Name: ";
        istr >> nameTmp;
        // unit
        std::cout << "Unit: ";
        istr >> unitTmp;
        // taxed
        std::cout << "Taxed? (y/n): ";
        istr >> taxedTmp;

        if (taxedTmp != 'Y' && taxedTmp != 'y' && taxedTmp != 'N' && taxedTmp != 'n') {
            // set the error message
            err_.message("Only (Y)es or (N)o are acceptable");
            // force the istr to fail
            istr.setstate(std::ios::failbit);
        }
        else {
            // flush
            istr.clear();

            // price
            std::cout << "Price: ";
            istr >> priceTmp;

            if (istr.fail()) {
                // set the error message
                err_.message("Invalid Price Entry");
                // force the istr to fail
                istr.setstate(std::ios::failbit);
            }
            else {
                // flush
                istr.clear();

                // quantity on hand
                std::cout << "Quantity On hand: ";
                istr >> quantityTmp;

                if (istr.fail()) {
                    // set the error message
                    err_.message("Invalid Quantity Entry");
                    // force the istr to fail
                    istr.setstate(std::ios::failbit);
                }
                else {
                    istr.clear();

                    // quantity needed
                    std::cout << "Quantity Needed: ";
                    istr >> qtyNeededTmp;

                    if (istr.fail()) {
                        // set the error message
                        err_.message("Invalid Quantity Needed Entry");
                        // force the istr to fail
                        istr.setstate(std::ios::failbit);
                    }
                    else {
                        sku(skuTmp);
                        name(nameTmp);
                        unit(unitTmp);
                        taxedTmp == 'Y' || taxedTmp == 'y' ? taxed(true) : taxed(false);
                        price(priceTmp);
                        quantity(quantityTmp);
                        qtyNeeded(qtyNeededTmp);
                    }
                }
            }
        }
        return istr;
    }
}
