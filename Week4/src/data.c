
/**
 * @file data.c
 * @brief Utility functions to convert integer to/from ascii
 *
 * Two helper functions to convert ascii string representation of
 * unsigned 32bit integer into binary (int32_t) and back again
 *
 * @author Anthony Turvey
 * @date July 3, 2017
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "data.h"
#include "memory.h"

/***********************************************************
 Global Variables
***********************************************************/

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t iData, uint8_t *pAscii, uint32_t uiBase) {

    char cSymbol[] =  {'0', '1', '2', '3',
                       '4', '5', '6', '7',
                       '8', '9', 'a', 'b',
                       'c', 'd', 'e', 'f' };

    uint8_t  uiDigitChar, uiDigitCount, *pTemp;
    uint32_t uiNumber;
    enum sign {POS, NEG} eSign;

    // error checking on the base
    if (( uiBase < 2 ) || ( uiBase > 16 )) {
        printf("%s: Error, base %d is out of range. Must be between 2 and 16.\n", __func__, uiBase);
        return 0;
    }

    // get the sign
    if ( iData >= 0 ) {
        eSign = POS;
        uiNumber = iData;
    }
    else { 
        eSign = NEG;
        uiNumber = -iData;
    }
    
    // put moveable pointer on string passed by user and reset digit count
    pTemp = pAscii;
    uiDigitCount = 0;

    // now start peeling off digits from low order to high
    while ( uiNumber != 0 ) {
        uiDigitChar = uiNumber % uiBase;
        // put this digit character at current position in string
        *pTemp = cSymbol[uiDigitChar];
        pTemp++;
        uiDigitCount++;
        // shift number down in order by base
        uiNumber = uiNumber / uiBase;
    }

    // now we need to consider sign character
    if ( eSign == NEG ) {
        *pTemp = '-';
        pTemp++;
        uiDigitCount++;
    }

    // finally terminate string with a null
    *pTemp = 0;

    // realize this string is in the reverse order so lets reverse it
    my_reverse(pAscii, uiDigitCount); 

    return (uiDigitCount);

}

int32_t my_atoi(uint8_t *pAscii, uint8_t uiDigits, uint32_t uiBase) {

    int32_t iNumber=0, iSign=1, iExp=1;
    uint8_t *pTemp, cTemp, i;
    uint8_t uiIndex;
    
    // set a moveable pointer on the user provided string
    pTemp = pAscii;
    uiIndex = uiDigits;

    // check for a sign
    if ( *pTemp == '-' ) {
        iSign = -1;
        pTemp++;
        uiIndex--;
    }
    else if ( *pTemp == '+' ) {
        iSign = +1;
        pTemp++;
        uiIndex--;
    }

    // now we're at digits, but prefer to process in reverse order
    my_reverse(pTemp, uiIndex);

    // start processing digits
    for (i=0; i<uiIndex; i++) {
        cTemp = *pTemp - '0';
        if ( cTemp > 9 ) cTemp -= 39;
        iNumber += iExp * cTemp;
        iExp *= uiBase;
        pTemp++;
    }

    // now the number should be formed, but need to fix the sign
    iNumber *= iSign;

    return (iNumber);
}


