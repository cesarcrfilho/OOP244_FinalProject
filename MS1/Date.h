// Final Project Milestone 1
// Date header file
//
// Version 1.0
// Date: July 04 2017
// Author: Cesar Rodrigues (cda-conceicao-rodrig)
// Seneca ID: 127381168
//
// Description:
// The Date class encapsulates a date value in three integers for year,
// month and day, and is readable by istreams and printable by ostream
// using the following format for both reading and writing: YYYY/MM/DD
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>
#include "general.h"

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                     Error Handling Constants                //
    /////////////////////////////////////////////////////////////////
    const int NO_ERROR = 0; // No error the date is valid
    const int CIN_FAILED = 1; // istream failed when entering information
    const int YEAR_ERROR = 2;  // Year value is invalid
    const int MON_ERROR = 3; // Month value is invalid
    const int DAY_ERROR = 4; // Day value is invalid


    /////////////////////////////////////////////////////////////////
    //                      Class Date Declaration                 //
    /////////////////////////////////////////////////////////////////
    class Date {
    private:
        // data members
        int year_; // four digit integer between MIN_YEAR and MAX_YEAR
        int mon_; // between 1 to 12
        int day_; // day of the month
        int readErrorCode_; // holds an error code (const values in this file)

        // member functions
        int value() const;
        void errCode(int errorCode) { readErrorCode_ = errorCode; }
        void set();
        void set(int year, int month, int day);

    public:
        // constructors
        Date();
        Date(int year, int month, int day);

        // operator overloading
        bool operator == (const Date& D)const { return this->value() == D.value(); }
        bool operator != (const Date& D)const { return this->value() != D.value(); }
        bool operator < (const Date& D)const { return this->value() < D.value(); }
        bool operator > (const Date& D)const { return this->value() > D.value(); }
        bool operator <= (const Date& D)const { return this->value() <= D.value(); }
        bool operator >= (const Date& D)const { return this->value() >= D.value(); }

        // mdays
        // returns the number of days in a month
        int mdays(int month) const;

        // accessors
        int errCode() const { return readErrorCode_; }
        bool bad() const { return readErrorCode_ != NO_ERROR ? true : false; }

        // IO member functions
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
    };

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////
    // ostream << Date
    std::ostream& operator << (std::ostream& ostr, const Date& date);

    // istream >> Date
    std::istream& operator >> (std::istream& istr, Date& date);

}

#endif // SICT_DATE_H__