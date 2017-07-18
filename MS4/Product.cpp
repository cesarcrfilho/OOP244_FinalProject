// Final Project Milestone 4
// Product implementation file
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

#include <cstring>
#include <iostream>
#include "Product.h"
#include "Streamable.h"
#include "general.h"
#define _CRT_SECURE_NO_WARNINGS

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                        Member Functions                     //
    /////////////////////////////////////////////////////////////////

	// setters
	void Product::sku(const char* sku) {
		if (sku != nullptr)
			strncpy(sku_, sku, MAX_SKU_LEN + 1);
	}

	void Product::name(const char* name) {
		if (name != nullptr) {
			name_ = new char[strnlen(name, 250) + 1];
			strncpy(name_, name, strnlen(name, 250) + 1);
		}
	}

	void Product::price(const double price) { price_ = price; }
	void Product::taxed(const bool taxed) { taxed_ = taxed; }
	void Product::quantity(const int quantity) { quantity_ = quantity; }
	void Product::qtyNeeded(const int qtyNeeded) { qtyNeeded_ = qtyNeeded; }

	// getters
	const char* Product::sku() const { return sku_; }
	const char* Product::name() const { return name_; }
	double Product::price() const { return price_; }
	bool Product::taxed() const { return taxed_; }
	int Product::quantity() const { return quantity_; }
	int Product::qtyNeeded() const { return qtyNeeded_; }
	
	// cost - price after tax if taxed
	double Product::cost() const {
		return (taxed_ ? price_ * (1 + TAX) : price_);
	}

	//isEmpty checks for safe empty state
	bool Product::isEmpty() const {
		return sku_[0] == char(0) ? true : false;
	}

    // constructors
    // default constructor
    Product::Product() {
        sku_[0] = char(0); // null terminator
        name_ = nullptr;
        price_  = 0;
        taxed_ = false;
        quantity_ = 0;
        qtyNeeded_ = 0;
    }

    // 5 parameter constructor
    Product::Product(const char* sku, const char* name, const bool taxed, const double price, const int qtyNeeded) {
        this->sku(sku);

        // allocate dynamic memory for the name
        name_ = new char[strnlen(name, 250) + 1];
        this->name(name);

		price_ = price;
		taxed_ = taxed;
		quantity_ = 0;
		qtyNeeded_ = qtyNeeded;
    }
    
    // copy constructor
    Product::Product(const Product& rhs) {
        sku(rhs.sku_);
        price_ = rhs.price_;
        taxed_ = rhs.taxed_;
        quantity_ = rhs.quantity_;
        qtyNeeded_ = rhs.qtyNeeded_;

        // allocate dynamic memory for the name
        if (rhs.name_ != nullptr) {
            name_ = new char[strnlen(rhs.name_, 250) + 1];
            name(rhs.name_);
        }
        else {
            name_ = nullptr;
        }
    }

	// operator overloading
    // assignment operator
    // Product = Product
    Product& Product::operator = (const Product& rhs) {
        if (this != &rhs) {
            sku(rhs.sku_);
            price_ = rhs.price_;
            taxed_ = rhs.taxed_;
            quantity_ = rhs.quantity_;
            qtyNeeded_ = rhs.qtyNeeded_;

            // deallocate previous memory
            delete[] name_;

            // allocate dynamic memory for the name
            if (rhs.name_ != nullptr) {
                name_ = new char[strnlen(rhs.name_, 250) + 1];
                name(rhs.name_);
            }
            else {
                name_ = nullptr;
            }
        }
        
        return *this;
    }

    // destructor
    Product::~Product() {
        delete[] name_;
    }

	// Product == char* - return true if sku_ is the same as char*
	bool Product::operator == (const char* rhs) const {
		return (strncmp(sku_, rhs, MAX_SKU_LEN + 1) == 0 ? true : false);
	}
	// Product += int
	int Product::operator += (const int rhs) {
		return quantity_ += rhs;
	}
	// Product -= int
	int Product::operator -= (const int rhs) {
		return quantity_ -= rhs;
	}

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////

    // operator overloading
    // double += Product
    double operator += (double& lhs, const Product& rhs) {
        // multiply the product cost (price * tax)
        // by the quantity at hand
        lhs += rhs.cost() * rhs.quantity();
        return lhs;
    }

	// ostream << Product
	std::ostream& operator << (std::ostream& ostr, const Product& product) {
		return product.write(ostr, true);
	}

	// istream >> Product
	std::istream& operator >> (std::istream& istr, Product& product) {
		return product.read(istr);
	}



}
