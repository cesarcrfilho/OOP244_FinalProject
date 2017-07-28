// Final Project Milestone 1
// general header file
//
// Version 1.0
// Date: July 04 2017
// Author: Cesar Rodrigues (cda-conceicao-rodrig)
// Seneca ID: 127381168
//
// Description:
// The general header holds the general defined values
// for the project
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_GENERAL_H__
#define SICT_GENERAL_H__

namespace sict {

    /////////////////////////////////////////////////////////////////
    //                     Constant Definition                     //
    /////////////////////////////////////////////////////////////////

    // The tax value for the NFI items
    const double TAX = 0.13;
    // The maximum size of a SKU
    const int MAX_SKU_LEN = 7;
    // Product lines to display before each pause
    const int DISPLAY_LINES = 10; 
    
    // The min and max for year to be used for date validation
    const int MIN_YEAR = 2000; 
    const int MAX_YEAR = 2030; 
    
    // The maximum number of records in the data file.
    const int MAX_NO_RECS = 2000;

}

#endif // SICT_GENERAL_H__