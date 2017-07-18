// Final Project Milestone 2
// Error Message header file
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
#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <ostream>

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                  Class Error Message Declaration            //
    /////////////////////////////////////////////////////////////////
    class ErrorMessage {
    private:
        // data members
        char* message_;

        // member functions
        void set() { message_ = nullptr; }
        void set(const char* errorMessage);
    public:
        // constructors
        ErrorMessage() { set(); }
        ErrorMessage(const char* errorMessage);
        ErrorMessage(const ErrorMessage& em) = delete; // A deleted copy constructor to prevent an ErrorMessage object to be copied

        // destructor
        virtual ~ErrorMessage();    

        // operator overloading
        ErrorMessage& operator = (const ErrorMessage& em) = delete; // A deleted assignment operator overload to prevent an ErrorMessage object to be assigned to another
        ErrorMessage& operator = (const char* errorMessage);

        // functions
        void clear();
        bool isClear() const { return message_ == nullptr ? true : false; }
        void message(const char* value);
        const char* message() const { return message_; }

    };

    /////////////////////////////////////////////////////////////////
    //                        Helper Functions                     //
    /////////////////////////////////////////////////////////////////
    // ostream << ErrorMessage
    std::ostream& operator << (std::ostream& ostr, const ErrorMessage& errorMessage);
}

#endif // !SICT_ERRORMESSAGE_H__
