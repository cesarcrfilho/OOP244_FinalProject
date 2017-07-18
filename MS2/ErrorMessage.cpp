// Final Project Milestone 2
// Error Message implementation file
//
// Version 1.0
// Date: July 08 2017
// Author: Cesar Rodrigues (cda-conceicao-rodrig)
// Seneca ID: 127381168
//
// Description:
// The ErrorMessage class encapsulates an error message in a
// dynamic C-style string and also is used as a flag for the
// error state of other classes.
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "ErrorMessage.h"
#include <cstring>

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                        Member Functions                     //
    /////////////////////////////////////////////////////////////////
    
    // setter
    void ErrorMessage::set(const char* errorMessage) {
        message_ = nullptr;
        message(errorMessage);
    }

    // constructors
    // constructor - 1 parameter
    ErrorMessage::ErrorMessage(const char* errorMessage) {
        set(errorMessage);
    }

    // destructor
    ErrorMessage::~ErrorMessage() {
        delete[] message_;
    }

    // operator overloading
    ErrorMessage& ErrorMessage::operator = (const char* errorMessage) {
        // copy the errorMessage to message_
        message(errorMessage);
        return *this;
    }

    // functions
    // clear
    void ErrorMessage::clear() {
        delete[] message_;
        message_ = nullptr;
    }

    // message
    void ErrorMessage::message(const char* value) {
        // de-allocate memory
        clear();
        // allocate new memory
        message_ = new char[strlen(value) + 1];
        // copy the contents of value to the message_
        strncpy(message_, value, strlen(value) + 1);
    }

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////

    // ostream << ErrorMessage
    std::ostream& operator << (std::ostream& ostr, const ErrorMessage& errorMessage) {
        // if the message is not nullptr, print it
        if (!errorMessage.isClear())
            ostr << errorMessage.message();
        return ostr;
    }

}
