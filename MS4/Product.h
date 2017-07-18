// Final Project Milestone 4
// Product header file
//
// Version 1.0
// Date: July 12 2017
// Author: Cesar Rodrigues (cda-conceicao-rodrig)
// Seneca ID: 127381168
//
// Description:
// A class inherited from Streamable, containing general
// information about an item, like the name,
// Stock Keeping Unit (SKU), price etc.
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_PRODUCT_H__
#define SICT_PRODUCT_H__
#include <cstring>
#include <iostream>
#include "Streamable.h"
#include "general.h"
#define _CRT_SECURE_NO_WARNINGS


namespace sict {

    /////////////////////////////////////////////////////////////////
    //                    Class Product Declaration                //
    /////////////////////////////////////////////////////////////////
    class Product : public Streamable {
    private:
        bool flag_; // controls safe empty state
        char sku_[MAX_SKU_LEN + 1];
        char* name_;
        double price_;
        bool taxed_;
        int quantity_;
        int qtyNeeded_;
    public:
        // constructors
        Product();
        Product(const char* sku, const char* name, const bool taxed = true, const double price = 0, const int quantity = 0);
        // copy constructor
        Product(const Product& rhs);

        // destructor
        virtual ~Product();

        // setters
		void sku(const char* sku);
		void name(const char* name);
		void price(const double price);
		void taxed(const bool taxed);
		void quantity(const int quantity);
		void qtyNeeded(const int qtyNeeded);

        // getters
		const char* sku() const;
		const char* name() const;
		double price() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
        // cost - price after tax if taxed
		double cost() const;

        //isEmpty checks for safe empty state
		bool isEmpty() const;

        // operator overloading
        // Product = Product
        Product& operator = (const Product& rhs);
        // Product == char* - return true if sku_ is the same as char*
		bool operator == (const char* rhs) const;
        // Product += int
		int operator += (const int rhs);
        // Product -= int
		int operator -= (const int rhs);

    };

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////

    // operator overloading
    // double += Product
    double operator += (double& lhs, const Product& rhs);
	// ostream << Product
	std::ostream& operator << (std::ostream& ostr, const Product& product);
	// istream >> Product
	std::istream& operator >> (std::istream& istr, Product& product);

}

#endif // !SICT_PRODUCT_H__