// Final Project Milestone 1
// Date implementation file
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
#include <iostream>
#include "Date.h"
#include "general.h"

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                        Member Functions                     //
    /////////////////////////////////////////////////////////////////
    
    // Value
    int Date::value()const {
        return year_ * 372 + mon_ * 31 + day_;
    }

    // set - no parameters
    void Date::set() {
        year_ = 0;
        mon_ = 0;
        day_ = 0;
        errCode(NO_ERROR);
    }

    // set - 3 parameters
    void Date::set(int year, int month, int day) {
        year_ = year;
        mon_ = month;
        day_ = day;
        errCode(NO_ERROR);
    }

    // constructors
    // default constructor
    Date::Date() {
        set();
    }

    // constructor - 3 parameters
    Date::Date(int year, int month, int day) {
        set(year, month, day);
    }

    // mdays
    int Date::mdays(int month) const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
        mon--;
        return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
    }

    // IO member functions
    std::istream& Date::read(std::istream& istr) {
        // variables to hold the input values
        int year, month, day;
        char delimeter;

        // input the date separeted by a delimeter char
        istr >> year >> delimeter >> month >> delimeter >> day;
        
        // check if istr failed
        if (istr.fail())
            readErrorCode_ = CIN_FAILED;
        else {
            // sets the values from input
            set(year, month, day);

            // check if the year is valid
            if (year < MIN_YEAR || year > MAX_YEAR)
                errCode(YEAR_ERROR);
            // check if the month is valid
            else if (month < 1 || month > 12)
                errCode(MON_ERROR);
            // check if the day is valid
            else if (day < 1 || day > mdays(month))
                errCode(DAY_ERROR);
        }
                    
        return istr;
    }

    std::ostream& Date::write(std::ostream& ostr) const {
        // writes YYYY/
        ostr << year_ << '/';
        // sets the format for MM/DD
        ostr.width(2);
        ostr.fill('0');
        // writes MM/DD
        ostr << mon_ << '/';
        ostr.width(2);
        ostr.fill('0');
        ostr << day_;
        return ostr;
    }

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////

    // ostream << Date
    std::ostream& operator << (std::ostream& ostr, const Date& date) {
        date.write(ostr);
        return ostr;
    }
    // istream >> Date
    std::istream& operator >> (std::istream& istr, Date& date) {
        date.read(istr);
        return istr;
    }


}
