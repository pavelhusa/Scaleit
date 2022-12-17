/* ------------------------------------------------------------
name: "scaleIt", "FaustDSP"
version: "2.52.3"
Code generated with Faust 2.52.7 (https://faust.grame.fr)
Compilation options: -a /usr/local/share/faust/max-msp/max-msp64.cpp -lang cpp -i -cn scaleIt -es 1 -mcd 16 -uim -double -ftz 0
------------------------------------------------------------ */

#ifndef  __scaleIt_H__
#define  __scaleIt_H__

/************************************************************************
 
 IMPORTANT NOTE : this file contains two clearly delimited sections :
 the ARCHITECTURE section (in two parts) and the USER section. Each section
 is governed by its own copyright and license. Please check individually
 each section for license and copyright information.
 *************************************************************************/

/******************* BEGIN max-msp64.cpp ****************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2004-2020 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either version 3
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 MAX MSP SDK : in order to compile a MaxMSP external with this
 architecture file you will need the official MaxMSP SDK from
 cycling'74. Please check the corresponding license.
 
 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifdef WIN32
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

// FAUSTFLOAT is setup by faust2max6

#ifndef DOWN_SAMPLING
#define DOWN_SAMPLING 0
#endif
#ifndef UP_SAMPLING
#define UP_SAMPLING 0
#endif
#ifndef FILTER_TYPE
#define FILTER_TYPE 0
#endif

/************************** BEGIN UI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __UI_H__
#define __UI_H__

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***************************************************************************/

#ifndef __export__
#define __export__

#define FAUSTVERSION "2.52.7"

// Use FAUST_API for code that is part of the external API but is also compiled in faust and libfaust
// Use LIBFAUST_API for code that is compiled in faust and libfaust

#ifdef _WIN32
    #pragma warning (disable: 4251)
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #elif FAUST_LIB
        #define FAUST_API __declspec(dllexport)
        #define LIBFAUST_API __declspec(dllexport)
    #else
        #define FAUST_API
        #define LIBFAUST_API 
    #endif
#else
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #else
        #define FAUST_API __attribute__((visibility("default")))
        #define LIBFAUST_API __attribute__((visibility("default")))
    #endif
#endif

#endif

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

template <typename REAL>
struct FAUST_API UIReal {
    
    UIReal() {}
    virtual ~UIReal() {}
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // -- active widgets
    
    virtual void addButton(const char* label, REAL* zone) = 0;
    virtual void addCheckButton(const char* label, REAL* zone) = 0;
    virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
    
    // -- metadata declarations
    
    virtual void declare(REAL* /*zone*/, const char* /*key*/, const char* /*val*/) {}

    // To be used by LLVM client
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
};

struct FAUST_API UI : public UIReal<FAUSTFLOAT> {
    UI() {}
    virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN SimpleParser.h *********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdio.h> // We use the lighter fprintf code
#include <ctype.h>
#include <assert.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

struct itemInfo {
    std::string type;
    std::string label;
    std::string shortname;
    std::string address;
    std::string url;
    int index;
    double init;
    double fmin;
    double fmax;
    double step;
    std::vector<std::pair<std::string, std::string> > meta;
    
    itemInfo():index(0), init(0.), fmin(0.), fmax(0.), step(0.)
    {}
};

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    fprintf(stderr, "Parse error : %s here : %s\n", errmsg, p);
    return true;
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
static void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
static bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
static bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] or [s]d[.dddd][E|e][s][dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
static bool parseDouble(const char*& p, double& x)
{
    double sign = 1.0;     // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part
    double expsign = 1.0;  // sign of the E|e part
    double expcoef = 0.0;  // multiplication factor of E|e part
    
    bool valid = false;    // true if the number contains at least one digit
    
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    
    // Sign
    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    
    // Integral part
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    
    // Possible decimal part
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    
    // Possible E|e part
    if (parseChar(p, 'E') || parseChar(p, 'e')) {
        if (parseChar(p, '+')) {
            expsign = 1.0;
        } else if (parseChar(p, '-')) {
            expsign = -1.0;
        }
        while (isdigit(*p)) {
            expcoef = expcoef*10 + (*p - '0');
            p++;
        }
    }
    
    if (valid)  {
        x = (sign*(ipart + dpart/dcoef)) * std::pow(10.0, expcoef*expsign);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseString(const char*& p, char quote, std::string& s)
{
    std::string str;
    skipBlank(p);
    
    const char* saved = p;  // to restore position if we fail
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseSQString(const char*& p, std::string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseDQString(const char*& p, std::string& s)
{
    return parseString(p, '"', s);
}

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
static bool parseMenuItem(const char*& p, std::string& name, double& value)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

static bool parseMenuItem2(const char*& p, std::string& name)
{
    const char* saved = p;  // to restore position if we fail
    // single quoted
    if (parseSQString(p, name)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values)
{
    std::vector<std::string> tmpnames;
    std::vector<double> tmpvalues;
    const char* saved = p; // to restore position if we fail

    if (parseChar(p, '{')) {
        do {
            std::string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug)
{
    std::vector<std::string> tmpnames;
    const char* saved = p;  // to restore position if we fail
    
    if (parseChar(p, '{')) {
        do {
            std::string n;
            if (parseMenuItem2(p, n)) {
                tmpnames.push_back(n);
            } else {
                goto error;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            return true;
        }
    }
    
error:
    if (debug) { fprintf(stderr, "parseMenuList2 : (%s) is not a valid list !\n", p); }
    p = saved;
    return false;
}

/// ---------------------------------------------------------------------
// Parse list of strings
/// ---------------------------------------------------------------------
static bool parseList(const char*& p, std::vector<std::string>& items)
{
    const char* saved = p;  // to restore position if we fail
    if (parseChar(p, '[')) {
        do {
            std::string item;
            if (!parseDQString(p, item)) {
                p = saved;
                return false;
            }
            items.push_back(item);
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    const char* saved = p; // to restore position if we fail
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    const char* saved = p; // to restore position if we fail
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
/// ---------------------------------------------------------------------
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, double& dbl, std::map<std::string, std::string>& metadatas, std::vector<std::string>& items)
{
    const char* saved = p; // to restore position if we fail
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && (parseDQString(p, value) || parseList(p, items) || parseDouble(p, dbl));
        }
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
/// ---------------------------------------------------------------------
static bool parseUI(const char*& p, std::vector<itemInfo>& uiItems, int& numItems)
{
    const char* saved = p; // to restore position if we fail
    if (parseChar(p, '{')) {
   
        std::string label;
        std::string value;
        double dbl = 0;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo item;
                        item.type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].label = value;
                    }
                }
                
                else if (label == "shortname") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].shortname = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].address = value;
                    }
                }
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].url = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].index = int(dbl);
                    }
                }
                
                else if (label == "meta") {
                    if (!parseItemMetaData(p, uiItems[numItems].meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].init = dbl;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].fmin = dbl;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].fmax = dbl;
                    }
                }
                
                else if (label == "step") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].step = dbl;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do {
                            if (!parseUI(p, uiItems, numItems)) {
                                p = saved;
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo item;
                            item.type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
            
                } else {
                    fprintf(stderr, "Parse error unknown : %s \n", label.c_str());
                    assert(false);
                }
            } else {
                p = saved;
                return false;
            }
            
        } while (tryChar(p, ','));
    
        return parseChar(p, '}');
    } else {
        return true; // "items": [] is valid
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
/// ---------------------------------------------------------------------
static bool parseJson(const char*& p,
                      std::map<std::string, std::pair<std::string, double> >& metaDatas0,
                      std::map<std::string, std::string>& metaDatas1,
                      std::map<std::string, std::vector<std::string> >& metaDatas2,
                      std::vector<itemInfo>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        double dbl = 0;
        std::vector<std::string> items;
        if (parseGlobalMetaData(p, key, value, dbl, metaDatas1, items)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                if (items.size() > 0) {
                    metaDatas2[key] = items;
                    items.clear();
                } else if (value != "") {
                    metaDatas0[key].first = value;
                } else {
                    metaDatas0[key].second = dbl;
                }
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H
/**************************  END  SimpleParser.h **************************/
/************************** BEGIN PathBuilder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __PathBuilder__
#define __PathBuilder__

#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <regex>


/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class FAUST_API PathBuilder {

    protected:
    
        std::vector<std::string> fControlsLevel;
        std::vector<std::string> fFullPaths;
        std::map<std::string, std::string> fFull2Short;  // filled by computeShortNames()
    
        /**
         * @brief check if a character is acceptable for an ID
         *
         * @param c
         * @return true is the character is acceptable for an ID
         */
        bool isIDChar(char c) const
        {
            return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
        }
    
        /**
         * @brief remove all "/0x00" parts
         *
         * @param src
         * @return modified string
         */
        std::string remove0x00(const std::string& src) const
        {
            return std::regex_replace(src, std::regex("/0x00"), "");
        }
    
        /**
         * @brief replace all non ID char with '_' (one '_' may replace several non ID char)
         *
         * @param src
         * @return modified string
         */
        std::string str2ID(const std::string& src) const
        {
            std::string dst;
            bool need_underscore = false;
            for (char c : src) {
                if (isIDChar(c) || (c == '/')) {
                    if (need_underscore) {
                        dst.push_back('_');
                        need_underscore = false;
                    }
                    dst.push_back(c);
                } else {
                    need_underscore = true;
                }
            }
            return dst;
        }
    
        /**
         * @brief Keep only the last n slash-parts
         *
         * @param src
         * @param n : 1 indicates the last slash-part
         * @return modified string
         */
        std::string cut(const std::string& src, int n) const
        {
            std::string rdst;
            for (int i = int(src.length())-1; i >= 0; i--) {
                char c = src[i];
                if (c != '/') {
                    rdst.push_back(c);
                } else if (n == 1) {
                    std::string dst;
                    for (int j = int(rdst.length())-1; j >= 0; j--) {
                        dst.push_back(rdst[j]);
                    }
                    return dst;
                } else {
                    n--;
                    rdst.push_back(c);
                }
            }
            return src;
        }
    
        void addFullPath(const std::string& label) { fFullPaths.push_back(buildPath(label)); }
    
        /**
         * @brief Compute the mapping between full path and short names
         */
        void computeShortNames()
        {
            std::vector<std::string>           uniquePaths;  // all full paths transformed but made unique with a prefix
            std::map<std::string, std::string> unique2full;  // all full paths transformed but made unique with a prefix
            char num_buffer[16];
            int pnum = 0;
        
            for (const auto& s : fFullPaths) {
                sprintf(num_buffer, "%d", pnum++);
                std::string u = "/P" + std::string(num_buffer) + str2ID(remove0x00(s));
                uniquePaths.push_back(u);
                unique2full[u] = s;  // remember the full path associated to a unique path
            }
        
            std::map<std::string, int> uniquePath2level;                // map path to level
            for (const auto& s : uniquePaths) uniquePath2level[s] = 1;   // we init all levels to 1
            bool have_collisions = true;
        
            while (have_collisions) {
                // compute collision list
                std::set<std::string>              collisionSet;
                std::map<std::string, std::string> short2full;
                have_collisions = false;
                for (const auto& it : uniquePath2level) {
                    std::string u = it.first;
                    int n = it.second;
                    std::string shortName = cut(u, n);
                    auto p = short2full.find(shortName);
                    if (p == short2full.end()) {
                        // no collision
                        short2full[shortName] = u;
                    } else {
                        // we have a collision, add the two paths to the collision set
                        have_collisions = true;
                        collisionSet.insert(u);
                        collisionSet.insert(p->second);
                    }
                }
                for (const auto& s : collisionSet) uniquePath2level[s]++;  // increase level of colliding path
            }
        
            for (const auto& it : uniquePath2level) {
                std::string u = it.first;
                int n = it.second;
                std::string shortName = replaceCharList(cut(u, n), {'/'}, '_');
                fFull2Short[unique2full[u]] = shortName;
            }
        }
    
        std::string replaceCharList(const std::string& str, const std::vector<char>& ch1, char ch2)
        {
            auto beg = ch1.begin();
            auto end = ch1.end();
            std::string res = str;
            for (size_t i = 0; i < str.length(); ++i) {
                if (std::find(beg, end, str[i]) != end) res[i] = ch2;
            }
            return res;
        }
     
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        // Return true for the first level of groups
        bool pushLabel(const std::string& label) { fControlsLevel.push_back(label); return fControlsLevel.size() == 1;}
    
        // Return true for the last level of groups
        bool popLabel() { fControlsLevel.pop_back(); return fControlsLevel.size() == 0; }
    
        std::string buildPath(const std::string& label)
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res = res + fControlsLevel[i] + "/";
            }
            res += label;
            return replaceCharList(res, {' ', '#', '*', ',', '?', '[', ']', '{', '}', '(', ')'}, '_');
        }
    
};

#endif  // __PathBuilder__
/**************************  END  PathBuilder.h **************************/
/************************** BEGIN dsp-combiner.h **************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <string>
#include <assert.h>
#include <sstream>

/************************** BEGIN dsp.h ********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API UI;
struct FAUST_API Meta;

/**
 * DSP memory manager.
 */

struct FAUST_API dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    /**
     * Inform the Memory Manager with the number of expected memory zones.
     * @param count - the number of expected memory zones
     */
    virtual void begin(size_t /*count*/) {}
    
    /**
     * Give the Memory Manager information on a given memory zone.
     * @param size - the size in bytes of the memory zone
     * @param reads - the number of Read access to the zone used to compute one frame
     * @param writes - the number of Write access to the zone used to compute one frame
     */
    virtual void info(size_t /*size*/, size_t /*reads*/, size_t /*writes*/) {}

    /**
     * Inform the Memory Manager that all memory zones have been described,
     * to possibly start a 'compute the best allocation strategy' step.
     */
    virtual void end() {}
    
    /**
     * Allocate a memory zone.
     * @param size - the memory zone size in bytes
     */
    virtual void* allocate(size_t size) = 0;
    
    /**
     * Destroy a memory zone.
     * @param ptr - the memory zone pointer to be deallocated
     */
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class FAUST_API dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'openTabBox', 'addButton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Return the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceInit(int sample_rate) = 0;
    
        /**
         * Init instance constant state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (like delay lines...) but keep the control parameter values */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class FAUST_API decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = nullptr):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int sample_rate) { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { fDSP->instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class, used with LLVM and Interpreter backends
 * to create DSP instances from a compiled DSP program.
 */

class FAUST_API dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

// Denormal handling

#if defined (__SSE__)
#include <xmmintrin.h>
#endif

class FAUST_API ScopedNoDenormals {
    
    private:
    
        intptr_t fpsr = 0;
        
        void setFpStatusRegister(intptr_t fpsr_aux) noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("msr fpcr, %0" : : "ri" (fpsr_aux));
        #elif defined (__SSE__)
            // The volatile keyword here is needed to workaround a bug in AppleClang 13.0
            // which aggressively optimises away the variable otherwise
            volatile uint32_t fpsr_w = static_cast<uint32_t>(fpsr_aux);
            _mm_setcsr(fpsr_w);
        #endif
        }
        
        void getFpStatusRegister() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("mrs %0, fpcr" : "=r" (fpsr));
        #elif defined (__SSE__)
            fpsr = static_cast<intptr_t>(_mm_getcsr());
        #endif
        }
    
    public:
    
        ScopedNoDenormals() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            intptr_t mask = (1 << 24 /* FZ */);
        #elif defined (__SSE__)
        #if defined (__SSE2__)
            intptr_t mask = 0x8040;
        #else
            intptr_t mask = 0x8000;
        #endif
        #else
            intptr_t mask = 0x0000;
        #endif
            getFpStatusRegister();
            setFpStatusRegister(fpsr | mask);
        }
        
        ~ScopedNoDenormals() noexcept
        {
            setFpStatusRegister(fpsr);
        }

};

#define AVOIDDENORMALS ScopedNoDenormals ftz_scope;

#endif

/************************** END dsp.h **************************/

// Base class and common code for binary combiners

enum Layout { kVerticalGroup, kHorizontalGroup, kTabGroup };

class dsp_binary_combiner : public dsp {

    protected:

        dsp* fDSP1;
        dsp* fDSP2;
        int fBufferSize;
        Layout fLayout;
        std::string fLabel;

        void buildUserInterfaceAux(UI* ui_interface)
        {
            switch (fLayout) {
                case kHorizontalGroup:
                    ui_interface->openHorizontalBox(fLabel.c_str());
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kVerticalGroup:
                    ui_interface->openVerticalBox(fLabel.c_str());
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kTabGroup:
                    ui_interface->openTabBox(fLabel.c_str());
                    ui_interface->openVerticalBox("DSP1");
                    fDSP1->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP2");
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->closeBox();
                    break;
            }
        }

        FAUSTFLOAT** allocateChannels(int num)
        {
            FAUSTFLOAT** channels = new FAUSTFLOAT*[num];
            for (int chan = 0; chan < num; chan++) {
                channels[chan] = new FAUSTFLOAT[fBufferSize];
                memset(channels[chan], 0, sizeof(FAUSTFLOAT) * fBufferSize);
            }
            return channels;
        }

        void deleteChannels(FAUSTFLOAT** channels, int num)
        {
            for (int chan = 0; chan < num; chan++) {
                delete [] channels[chan];
            }
            delete [] channels;
        }

     public:

        dsp_binary_combiner(dsp* dsp1, dsp* dsp2, int buffer_size, Layout layout, const std::string& label)
        :fDSP1(dsp1), fDSP2(dsp2), fBufferSize(buffer_size), fLayout(layout), fLabel(label)
        {}

        virtual ~dsp_binary_combiner()
        {
            delete fDSP1;
            delete fDSP2;
        }

        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
        virtual void init(int sample_rate)
        {
            fDSP1->init(sample_rate);
            fDSP2->init(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            fDSP1->instanceInit(sample_rate);
            fDSP2->instanceInit(sample_rate);
        }
        virtual void instanceConstants(int sample_rate)
        {
            fDSP1->instanceConstants(sample_rate);
            fDSP2->instanceConstants(sample_rate);
        }

        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }

        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }

};

// Combine two 'compatible' DSP in sequence

class dsp_sequencer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;

    public:

        dsp_sequencer(dsp* dsp1, dsp* dsp2,
                      int buffer_size = 4096,
                      Layout layout = Layout::kTabGroup,
                      const std::string& label = "Sequencer")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
        }

        virtual ~dsp_sequencer()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);
            fDSP2->compute(count, fDSP1Outputs, outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_parallelizer(dsp* dsp1, dsp* dsp2,
                     int buffer_size = 4096,
                     Layout layout = Layout::kTabGroup,
                     const std::string& label = "Parallelizer")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fDSP2Outputs = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }

        virtual ~dsp_parallelizer()
        {
            delete [] fDSP2Inputs;
            delete [] fDSP2Outputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);

            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fDSP2Inputs[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fDSP2Outputs[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }

            fDSP2->compute(count, fDSP2Inputs, fDSP2Outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two 'compatible' DSP in splitter

class dsp_splitter : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

    public:

        dsp_splitter(dsp* dsp1, dsp* dsp2,
                     int buffer_size = 4096,
                     Layout layout = Layout::kTabGroup,
                     const std::string& label = "Splitter")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_splitter()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual dsp* clone()
        {
            return new dsp_splitter(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);

            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                 fDSP2Inputs[chan] = fDSP1Outputs[chan % fDSP1->getNumOutputs()];
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in merger

class dsp_merger : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

        void mix(int count, FAUSTFLOAT* dst, FAUSTFLOAT* src)
        {
            for (int frame = 0; frame < count; frame++) {
                dst[frame] += src[frame];
            }
        }

    public:

        dsp_merger(dsp* dsp1, dsp* dsp2,
                   int buffer_size = 4096,
                   Layout layout = Layout::kTabGroup,
                   const std::string& label = "Merger")
        :dsp_binary_combiner(dsp1, dsp2, buffer_size, layout, label)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs());
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_merger()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual dsp* clone()
        {
            return new dsp_merger(fDSP1->clone(), fDSP2->clone(), fBufferSize, fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, fDSP1Inputs, fDSP1Outputs);

            memset(fDSP2Inputs, 0, sizeof(FAUSTFLOAT*) * fDSP2->getNumInputs());

            for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                int mchan = chan % fDSP2->getNumInputs();
                if (fDSP2Inputs[mchan]) {
                    mix(count, fDSP2Inputs[mchan], fDSP1Outputs[chan]);
                } else {
                    fDSP2Inputs[mchan] = fDSP1Outputs[chan];
                }
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in a recursive way

class dsp_recursiver : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_recursiver(dsp* dsp1, dsp* dsp2,
                       Layout layout = Layout::kTabGroup,
                       const std::string& label = "Recursiver")
        :dsp_binary_combiner(dsp1, dsp2, 1, layout, label)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs());
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs());
            fDSP2Inputs = allocateChannels(fDSP2->getNumInputs());
            fDSP2Outputs = allocateChannels(fDSP2->getNumOutputs());
        }

        virtual ~dsp_recursiver()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            deleteChannels(fDSP2Inputs, fDSP2->getNumInputs());
            deleteChannels(fDSP2Outputs, fDSP2->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() - fDSP2->getNumOutputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface);
        }

        virtual dsp* clone()
        {
            return new dsp_recursiver(fDSP1->clone(), fDSP2->clone(), fLayout, fLabel);
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int frame = 0; (frame < count); frame++) {

                for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan][0] = fDSP2Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP1->getNumInputs() - fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan + fDSP2->getNumOutputs()][0] = inputs[chan][frame];
                }

                fDSP1->compute(1, fDSP1Inputs, fDSP1Outputs);

                for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                    outputs[chan][frame] = fDSP1Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                    fDSP2Inputs[chan][0] = fDSP1Outputs[chan][0];
                }

                fDSP2->compute(1, fDSP2Inputs, fDSP2Outputs);
            }
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

/*
 Crossfade between two DSP.
 When fCrossfade = 1, the first DSP only is computed, when fCrossfade = 0,
 the second DSP only is computed, otherwise both DSPs are computed and mixed.
*/

class dsp_crossfader: public dsp_binary_combiner {

    private:
    
        FAUSTFLOAT fCrossfade;
        FAUSTFLOAT** fDSPOutputs1;
        FAUSTFLOAT** fDSPOutputs2;
    
    public:
    
        dsp_crossfader(dsp* dsp1, dsp* dsp2,
                       Layout layout = Layout::kTabGroup,
                       const std::string& label = "Crossfade")
        :dsp_binary_combiner(dsp1, dsp2, 4096, layout, label),fCrossfade(FAUSTFLOAT(0.5))
        {
            fDSPOutputs1 = allocateChannels(fDSP1->getNumOutputs());
            fDSPOutputs2 = allocateChannels(fDSP1->getNumOutputs());
        }
    
        virtual ~dsp_crossfader()
        {
            deleteChannels(fDSPOutputs1, fDSP1->getNumInputs());
            deleteChannels(fDSPOutputs2, fDSP1->getNumOutputs());
        }
    
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs(); }

        void buildUserInterface(UI* ui_interface)
        {
            switch (fLayout) {
                case kHorizontalGroup:
                    ui_interface->openHorizontalBox(fLabel.c_str());
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kVerticalGroup:
                    ui_interface->openVerticalBox(fLabel.c_str());
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    fDSP1->buildUserInterface(ui_interface);
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    break;
                case kTabGroup:
                    ui_interface->openTabBox(fLabel.c_str());
                    ui_interface->openVerticalBox("Crossfade");
                    ui_interface->addHorizontalSlider("Crossfade", &fCrossfade, FAUSTFLOAT(0.5), FAUSTFLOAT(0), FAUSTFLOAT(1), FAUSTFLOAT(0.01));
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP1");
                    fDSP1->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->openVerticalBox("DSP2");
                    fDSP2->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                    ui_interface->closeBox();
                    break;
            }
        }
    
        virtual dsp* clone()
        {
            return new dsp_crossfader(fDSP1->clone(), fDSP2->clone(), fLayout, fLabel);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            if (fCrossfade == FAUSTFLOAT(1)) {
                fDSP1->compute(count, inputs, outputs);
            } else if (fCrossfade == FAUSTFLOAT(0)) {
                fDSP2->compute(count, inputs, outputs);
            } else {
                // Compute each effect
                fDSP1->compute(count, inputs, fDSPOutputs1);
                fDSP2->compute(count, inputs, fDSPOutputs2);
                // Mix between the two effects
                FAUSTFLOAT gain1 = fCrossfade;
                FAUSTFLOAT gain2 = FAUSTFLOAT(1) - gain1;
                for (int frame = 0; (frame < count); frame++) {
                    for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                        outputs[chan][frame] = fDSPOutputs1[chan][frame] * gain1 + fDSPOutputs2[chan][frame] * gain2;
                    }
                }
            }
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#ifndef __dsp_algebra_api__
#define __dsp_algebra_api__

// DSP algebra API
/*
 Each operation takes two DSP and a optional Layout and Label parameters, returns the combined DSPs, or null if failure with an error message.
 */

static dsp* createDSPSequencer(dsp* dsp1, dsp* dsp2,
                               std::string& error,
                               Layout layout = Layout::kTabGroup,
                               const std::string& label = "Sequencer")
{
    if (dsp1->getNumOutputs() != dsp2->getNumInputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_sequencer : the number of outputs ("
                  << dsp1->getNumOutputs() << ") of A "
                  << "must be equal to the number of inputs (" << dsp2->getNumInputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    }
}

static dsp* createDSPParallelizer(dsp* dsp1, dsp* dsp2,
                                  std::string& error,
                                  Layout layout = Layout::kTabGroup,
                                  const std::string& label = "Parallelizer")
{
    return new dsp_parallelizer(dsp1, dsp2, 4096, layout, label);
}

static dsp* createDSPSplitter(dsp* dsp1, dsp* dsp2, std::string& error, Layout layout = Layout::kTabGroup, const std::string& label = "Splitter")
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_splitter : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_splitter : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() % dsp1->getNumOutputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_splitter : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a divisor of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    } else {
        return new dsp_splitter(dsp1, dsp2, 4096, layout, label);
    }
}

static dsp* createDSPMerger(dsp* dsp1, dsp* dsp2,
                            std::string& error,
                            Layout layout = Layout::kTabGroup,
                            const std::string& label = "Merger")
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_merger : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_merger : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp1->getNumOutputs() % dsp2->getNumInputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_merger : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a multiple of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2, 4096, layout, label);
    } else {
        return new dsp_merger(dsp1, dsp2, 4096, layout, label);
    }
}

static dsp* createDSPRecursiver(dsp* dsp1, dsp* dsp2,
                                std::string& error,
                                Layout layout = Layout::kTabGroup,
                                const std::string& label = "Recursiver")
{
    if ((dsp2->getNumInputs() > dsp1->getNumOutputs()) || (dsp2->getNumOutputs() > dsp1->getNumInputs())) {
        std::stringstream error_aux;
        error_aux << "Connection error in : dsp_recursiver" << std::endl;
        if (dsp2->getNumInputs() > dsp1->getNumOutputs()) {
            error_aux << "The number of outputs " << dsp1->getNumOutputs()
                      << " of the first expression should be greater or equal to the number of inputs ("
                      << dsp2->getNumInputs()
                      << ") of the second expression" << std::endl;
        }
        if (dsp2->getNumOutputs() > dsp1->getNumInputs()) {
            error_aux << "The number of inputs " << dsp1->getNumInputs()
                      << " of the first expression should be greater or equal to the number of outputs ("
                      << dsp2->getNumOutputs()
                      << ") of the second expression" << std::endl;
        }
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_recursiver(dsp1, dsp2, layout, label);
    }
}

static dsp* createDSPCrossfader(dsp* dsp1, dsp* dsp2,
                                 std::string& error,
                                 Layout layout = Layout::kTabGroup,
                                 const std::string& label = "Crossfade")
{
    if (dsp1->getNumInputs() != dsp2->getNumInputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_crossfader : the number of inputs ("
        << dsp1->getNumInputs() << ") of A "
        << "must be equal to the number of inputs (" << dsp2->getNumInputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp1->getNumOutputs() != dsp2->getNumOutputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_crossfader : the number of outputs ("
        << dsp1->getNumOutputs() << ") of A "
        << "must be equal to the number of outputs (" << dsp2->getNumOutputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_crossfader(dsp1, dsp2, layout, label);
    }
}

#endif

#endif
/************************** END dsp-combiner.h **************************/
/************************** BEGIN dsp-adapter.h *************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_adapter__
#define __dsp_adapter__

#ifndef _WIN32
#include <alloca.h>
#endif
#include <string.h>
#include <cmath>
#include <assert.h>
#include <stdio.h>


// Adapts a DSP for a different number of inputs/outputs
class dsp_adapter : public decorator_dsp {
    
    private:
    
        FAUSTFLOAT** fAdaptedInputs;
        FAUSTFLOAT** fAdaptedOutputs;
        int fHWInputs;
        int fHWOutputs;
        int fBufferSize;
    
        void adaptBuffers(FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int i = 0; i < fHWInputs; i++) {
                fAdaptedInputs[i] = inputs[i];
            }
            for (int i = 0; i < fHWOutputs; i++) {
                fAdaptedOutputs[i] = outputs[i];
            }
        }
    
    public:
    
        dsp_adapter(dsp* dsp, int hw_inputs, int hw_outputs, int buffer_size):decorator_dsp(dsp)
        {
            fHWInputs = hw_inputs;
            fHWOutputs = hw_outputs;
            fBufferSize = buffer_size;
            
            fAdaptedInputs = new FAUSTFLOAT*[dsp->getNumInputs()];
            for (int i = 0; i < dsp->getNumInputs() - fHWInputs; i++) {
                fAdaptedInputs[i + fHWInputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedInputs[i + fHWInputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
            
            fAdaptedOutputs = new FAUSTFLOAT*[dsp->getNumOutputs()];
            for (int i = 0; i < dsp->getNumOutputs() - fHWOutputs; i++) {
                fAdaptedOutputs[i + fHWOutputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedOutputs[i + fHWOutputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
        }
    
        virtual ~dsp_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs() - fHWInputs; i++) {
                delete [] fAdaptedInputs[i + fHWInputs];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs() - fHWOutputs; i++) {
                delete [] fAdaptedOutputs[i + fHWOutputs];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual int getNumInputs() { return fHWInputs; }
        virtual int getNumOutputs() { return fHWOutputs; }
    
        virtual dsp_adapter* clone() { return new dsp_adapter(fDSP->clone(), fHWInputs, fHWOutputs, fBufferSize); }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(date_usec, count, fAdaptedInputs, fAdaptedOutputs);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(count, fAdaptedInputs, fAdaptedOutputs);
        }
};

// Adapts a DSP for a different sample size
template <typename REAL_INT, typename REAL_EXT>
class dsp_sample_adapter : public decorator_dsp {
    
    private:
    
        REAL_INT** fAdaptedInputs;
        REAL_INT** fAdaptedOutputs;
    
        void adaptInputBuffers(int count, FAUSTFLOAT** inputs)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    fAdaptedInputs[chan][frame] = REAL_INT(reinterpret_cast<REAL_EXT**>(inputs)[chan][frame]);
                }
            }
        }
    
        void adaptOutputsBuffers(int count, FAUSTFLOAT** outputs)
        {
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    reinterpret_cast<REAL_EXT**>(outputs)[chan][frame] = REAL_EXT(fAdaptedOutputs[chan][frame]);
                }
            }
        }
    
    public:
    
        dsp_sample_adapter(dsp* dsp):decorator_dsp(dsp)
        {
            fAdaptedInputs = new REAL_INT*[dsp->getNumInputs()];
            for (int i = 0; i < dsp->getNumInputs(); i++) {
                fAdaptedInputs[i] = new REAL_INT[4096];
            }
            
            fAdaptedOutputs = new REAL_INT*[dsp->getNumOutputs()];
            for (int i = 0; i < dsp->getNumOutputs(); i++) {
                fAdaptedOutputs[i] = new REAL_INT[4096];
            }
        }
    
        virtual ~dsp_sample_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                delete [] fAdaptedInputs[i];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                delete [] fAdaptedOutputs[i];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual dsp_sample_adapter* clone() { return new dsp_sample_adapter(fDSP->clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= 4096);
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses REAL_INT
            fDSP->compute(count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= 4096);
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses REAL_INT
            fDSP->compute(date_usec, count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
};

// Template used to specialize double parameters expressed as NUM/DENOM
template <int NUM, int DENOM>
struct Double {
    static constexpr double value() { return double(NUM)/double(DENOM); }
};

// Base class for filters
template <class fVslider0, int fVslider1>
struct Filter {
    inline int getFactor() { return fVslider1; }
};

// Identity filter: copy input to output
template <class fVslider0, int fVslider1>
struct Identity : public Filter<fVslider0, fVslider1> {
    inline int getFactor() { return fVslider1; }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        memcpy(output0, input0, count * sizeof(FAUSTFLOAT));
    }
};

// Generated with process = fi.lowpass(3, ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass3 : public Filter<fVslider0, fVslider1> {
    
    REAL fVec0[2];
    REAL fRec1[2];
    REAL fRec0[3];
    
    inline REAL LowPass3_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass3()
    {
        for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
            fVec0[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fRec1[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 1.0000000000000002) / fSlow0) + 1.0));
        REAL fSlow3 = (1.0 / (fSlow1 + 1.0));
        REAL fSlow4 = (1.0 - fSlow1);
        REAL fSlow5 = (((fSlow1 + -1.0000000000000002) / fSlow0) + 1.0);
        REAL fSlow6 = (2.0 * (1.0 - (1.0 / LowPass3_faustpower2_f(fSlow0))));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            REAL fTemp0 = REAL(input0[i]);
            fVec0[0] = fTemp0;
            fRec1[0] = (0.0 - (fSlow3 * ((fSlow4 * fRec1[1]) - (fTemp0 + fVec0[1]))));
            fRec0[0] = (fRec1[0] - (fSlow2 * ((fSlow5 * fRec0[2]) + (fSlow6 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (fRec0[2] + (fRec0[0] + (2.0 * fRec0[1])))));
            fVec0[1] = fVec0[0];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass(4, ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass4 : public Filter<fVslider0, fVslider1> {
    
    REAL fRec1[3];
    REAL fRec0[3];
    
    inline REAL LowPass4_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass4()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec1[l0] = 0.0f;
        }
        for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
            fRec0[l1] = 0.0f;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 0.76536686473017945) / fSlow0) + 1.0));
        REAL fSlow3 = (1.0 / (((fSlow1 + 1.8477590650225735) / fSlow0) + 1.0));
        REAL fSlow4 = (((fSlow1 + -1.8477590650225735) / fSlow0) + 1.0);
        REAL fSlow5 = (2.0 * (1.0 - (1.0 / LowPass4_faustpower2_f(fSlow0))));
        REAL fSlow6 = (((fSlow1 + -0.76536686473017945) / fSlow0) + 1.0);
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec1[0] = (REAL(input0[i]) - (fSlow3 * ((fSlow4 * fRec1[2]) + (fSlow5 * fRec1[1]))));
            fRec0[0] = ((fSlow3 * (fRec1[2] + (fRec1[0] + (2.0 * fRec1[1])))) - (fSlow2 * ((fSlow6 * fRec0[2]) + (fSlow5 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (fRec0[2] + (fRec0[0] + (2.0 * fRec0[1])))));
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass3e(ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass3e : public Filter<fVslider0, fVslider1> {
    
    REAL fRec1[3];
    REAL fVec0[2];
    REAL fRec0[2];
    
    inline REAL LowPass3e_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass3e()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec1[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fVec0[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (fSlow1 + 0.82244590899881598));
        REAL fSlow3 = (0.82244590899881598 - fSlow1);
        REAL fSlow4 = (1.0 / (((fSlow1 + 0.80263676416103003) / fSlow0) + 1.4122708937742039));
        REAL fSlow5 = LowPass3e_faustpower2_f(fSlow0);
        REAL fSlow6 = (0.019809144837788999 / fSlow5);
        REAL fSlow7 = (fSlow6 + 1.1615164189826961);
        REAL fSlow8 = (((fSlow1 + -0.80263676416103003) / fSlow0) + 1.4122708937742039);
        REAL fSlow9 = (2.0 * (1.4122708937742039 - (1.0 / fSlow5)));
        REAL fSlow10 = (2.0 * (1.1615164189826961 - fSlow6));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec1[0] = (REAL(input0[i]) - (fSlow4 * ((fSlow8 * fRec1[2]) + (fSlow9 * fRec1[1]))));
            REAL fTemp0 = (fSlow4 * (((fSlow7 * fRec1[0]) + (fSlow10 * fRec1[1])) + (fSlow7 * fRec1[2])));
            fVec0[0] = fTemp0;
            fRec0[0] = (0.0 - (fSlow2 * ((fSlow3 * fRec0[1]) - (fTemp0 + fVec0[1]))));
            output0[i] = FAUSTFLOAT(fRec0[0]);
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fVec0[1] = fVec0[0];
            fRec0[1] = fRec0[0];
        }
    }
};

// Generated with process = fi.lowpass6e(ma.SR*hslider("FCFactor", 0.4, 0.4, 0.5, 0.01)/hslider("Factor", 2, 2, 8, 1));
template <class fVslider0, int fVslider1, typename REAL>
struct LowPass6e : public Filter<fVslider0, fVslider1> {
    
    REAL fRec2[3];
    REAL fRec1[3];
    REAL fRec0[3];
    
    inline REAL LowPass6e_faustpower2_f(REAL value)
    {
        return (value * value);
    }
    
    LowPass6e()
    {
        for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
            fRec2[l0] = 0.0;
        }
        for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
            fRec1[l1] = 0.0;
        }
        for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
            fRec0[l2] = 0.0;
        }
    }
    
    inline void compute(int count, FAUSTFLOAT* input0, FAUSTFLOAT* output0)
    {
        // Computed at template specialization time
        REAL fSlow0 = std::tan((3.1415926535897931 * (REAL(fVslider0::value()) / REAL(fVslider1))));
        REAL fSlow1 = (1.0 / fSlow0);
        REAL fSlow2 = (1.0 / (((fSlow1 + 0.16840487111358901) / fSlow0) + 1.0693584077073119));
        REAL fSlow3 = LowPass6e_faustpower2_f(fSlow0);
        REAL fSlow4 = (1.0 / fSlow3);
        REAL fSlow5 = (fSlow4 + 53.536152954556727);
        REAL fSlow6 = (1.0 / (((fSlow1 + 0.51247864188914105) / fSlow0) + 0.68962136448467504));
        REAL fSlow7 = (fSlow4 + 7.6217312988706034);
        REAL fSlow8 = (1.0 / (((fSlow1 + 0.78241304682164503) / fSlow0) + 0.24529150870616001));
        REAL fSlow9 = (9.9999997054999994e-05 / fSlow3);
        REAL fSlow10 = (fSlow9 + 0.00043322720055500002);
        REAL fSlow11 = (((fSlow1 + -0.78241304682164503) / fSlow0) + 0.24529150870616001);
        REAL fSlow12 = (2.0 * (0.24529150870616001 - fSlow4));
        REAL fSlow13 = (2.0 * (0.00043322720055500002 - fSlow9));
        REAL fSlow14 = (((fSlow1 + -0.51247864188914105) / fSlow0) + 0.68962136448467504);
        REAL fSlow15 = (2.0 * (0.68962136448467504 - fSlow4));
        REAL fSlow16 = (2.0 * (7.6217312988706034 - fSlow4));
        REAL fSlow17 = (((fSlow1 + -0.16840487111358901) / fSlow0) + 1.0693584077073119);
        REAL fSlow18 = (2.0 * (1.0693584077073119 - fSlow4));
        REAL fSlow19 = (2.0 * (53.536152954556727 - fSlow4));
        // Computed at runtime
        for (int i = 0; (i < count); i = (i + 1)) {
            fRec2[0] = (REAL(input0[i]) - (fSlow8 * ((fSlow11 * fRec2[2]) + (fSlow12 * fRec2[1]))));
            fRec1[0] = ((fSlow8 * (((fSlow10 * fRec2[0]) + (fSlow13 * fRec2[1])) + (fSlow10 * fRec2[2]))) - (fSlow6 * ((fSlow14 * fRec1[2]) + (fSlow15 * fRec1[1]))));
            fRec0[0] = ((fSlow6 * (((fSlow7 * fRec1[0]) + (fSlow16 * fRec1[1])) + (fSlow7 * fRec1[2]))) - (fSlow2 * ((fSlow17 * fRec0[2]) + (fSlow18 * fRec0[1]))));
            output0[i] = FAUSTFLOAT((fSlow2 * (((fSlow5 * fRec0[0]) + (fSlow19 * fRec0[1])) + (fSlow5 * fRec0[2]))));
            fRec2[2] = fRec2[1];
            fRec2[1] = fRec2[0];
            fRec1[2] = fRec1[1];
            fRec1[1] = fRec1[0];
            fRec0[2] = fRec0[1];
            fRec0[1] = fRec0[0];
        }
    }
};

// A "si.bus(N)" like hard-coded class
struct dsp_bus : public dsp {
    
    int fChannels;
    int fSampleRate;
    
    dsp_bus(int channels):fChannels(channels), fSampleRate(-1)
    {}
    
    virtual int getNumInputs() { return fChannels; }
    virtual int getNumOutputs() { return fChannels; }
    
    virtual int getSampleRate() { return fSampleRate; }
    
    virtual void buildUserInterface(UI* ui_interface) {}
    virtual void init(int sample_rate)
    {
        //classInit(sample_rate);
        instanceInit(sample_rate);
    }
    
    virtual void instanceInit(int sample_rate)
    {
        fSampleRate = sample_rate;
        instanceConstants(sample_rate);
        instanceResetUserInterface();
        instanceClear();
    }
    
    virtual void instanceConstants(int sample_rate) {}
    virtual void instanceResetUserInterface() {}
    virtual void instanceClear() {}
    
    virtual dsp* clone() { return new dsp_bus(fChannels); }
    
    virtual void metadata(Meta* m) {}
    
    virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        for (int chan = 0; chan < fChannels; chan++) {
            memcpy(outputs[chan], inputs[chan], sizeof(FAUSTFLOAT) * count);
        }
    }
    
    virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        compute(count, inputs, outputs);
    }
    
};

// Base class for sample-rate adapter
template <typename FILTER>
class sr_sampler : public decorator_dsp {
    
    protected:
    
        std::vector<FILTER> fInputLowPass;
        std::vector<FILTER> fOutputLowPass;
    
        inline int getFactor() { return this->fOutputLowPass[0].getFactor(); }
    
    public:
    
        sr_sampler(dsp* dsp):decorator_dsp(dsp)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                fInputLowPass.push_back(FILTER());
            }
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                fOutputLowPass.push_back(FILTER());
            }
        }
};

// Down sample-rate adapter
template <typename FILTER>
class dsp_down_sampler : public sr_sampler<FILTER> {
    
    public:
    
        dsp_down_sampler(dsp* dsp):sr_sampler<FILTER>(dsp)
        {}
    
        virtual void init(int sample_rate)
        {
            this->fDSP->init(sample_rate / this->getFactor());
        }
    
        virtual void instanceInit(int sample_rate)
        {
            this->fDSP->instanceInit(sample_rate / this->getFactor());
        }
    
        virtual void instanceConstants(int sample_rate)
        {
            this->fDSP->instanceConstants(sample_rate / this->getFactor());
        }
    
        virtual dsp_down_sampler* clone() { return new dsp_down_sampler(decorator_dsp::clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            int real_count = count / this->getFactor();
            
            // Adapt inputs
            FAUSTFLOAT** fInputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumInputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < this->fDSP->getNumInputs(); chan++) {
                // Lowpass filtering in place on 'inputs'
                this->fInputLowPass[chan].compute(count, inputs[chan], inputs[chan]);
                // Allocate fInputs with 'real_count' frames
                fInputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
                // Decimate
                for (int frame = 0; frame < real_count; frame++) {
                    fInputs[chan][frame] = inputs[chan][frame * this->getFactor()];
                }
            }
            
            // Allocate fOutputs with 'real_count' frames
            FAUSTFLOAT** fOutputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumOutputs() * sizeof(FAUSTFLOAT*));
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                fOutputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
            }
            
            // Compute at lower rate
            this->fDSP->compute(real_count, fInputs, fOutputs);
            
            // Adapt outputs
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                // Puts zeros
                memset(outputs[chan], 0, sizeof(FAUSTFLOAT) * count);
                for (int frame = 0; frame < real_count; frame++) {
                    // Copy one sample every 'DownFactor'
                    // Apply volume
                    //outputs[chan][frame * this->getFactor()] = fOutputs[chan][frame] * this->getFactor();
                    outputs[chan][frame * this->getFactor()] = fOutputs[chan][frame];
                }
                // Lowpass filtering in place on 'outputs'
                this->fOutputLowPass[chan].compute(count, outputs[chan], outputs[chan]);
            }
        }
    
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Up sample-rate adapter
template <typename FILTER>
class dsp_up_sampler : public sr_sampler<FILTER> {
    
    public:
    
        dsp_up_sampler(dsp* dsp):sr_sampler<FILTER>(dsp)
        {}
    
        virtual void init(int sample_rate)
        {
            this->fDSP->init(sample_rate * this->getFactor());
        }
    
        virtual void instanceInit(int sample_rate)
        {
            this->fDSP->instanceInit(sample_rate * this->getFactor());
        }
    
        virtual void instanceConstants(int sample_rate)
        {
            this->fDSP->instanceConstants(sample_rate * this->getFactor());
        }
    
        virtual dsp_up_sampler* clone() { return new dsp_up_sampler(decorator_dsp::clone()); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            int real_count = count * this->getFactor();
            
            // Adapt inputs
            FAUSTFLOAT** fInputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumInputs() * sizeof(FAUSTFLOAT*));
            
            for (int chan = 0; chan < this->fDSP->getNumInputs(); chan++) {
                // Allocate fInputs with 'real_count' frames
                fInputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
                // Puts zeros
                memset(fInputs[chan], 0, sizeof(FAUSTFLOAT) * real_count);
                for (int frame = 0; frame < count; frame++) {
                    // Copy one sample every 'UpFactor'
                    fInputs[chan][frame * this->getFactor()] = inputs[chan][frame];
                }
                // Lowpass filtering in place on 'fInputs'
                this->fInputLowPass[chan].compute(real_count, fInputs[chan], fInputs[chan]);
            }
            
            // Allocate fOutputs with 'real_count' frames
            FAUSTFLOAT** fOutputs = (FAUSTFLOAT**)alloca(this->fDSP->getNumOutputs() * sizeof(FAUSTFLOAT*));
            
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                fOutputs[chan] = (FAUSTFLOAT*)alloca(sizeof(FAUSTFLOAT) * real_count);
            }
            
            // Compute at upper rate
            this->fDSP->compute(real_count, fInputs, fOutputs);
            
            // Adapt outputs
            for (int chan = 0; chan < this->fDSP->getNumOutputs(); chan++) {
                // Lowpass filtering in place on 'fOutputs'
                this->fOutputLowPass[chan].compute(real_count, fOutputs[chan], fOutputs[chan]);
                // Decimate
                for (int frame = 0; frame < count; frame++) {
                    // Apply volume
                    //outputs[chan][frame] = fOutputs[chan][frame * this->getFactor()] * this->getFactor();
                    outputs[chan][frame] = fOutputs[chan][frame * this->getFactor()];
                }
            }
        }
    
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Create a UP/DS + Filter adapted DSP
template <typename REAL>
dsp* createSRAdapter(dsp* DSP, int ds = 0, int us = 0, int filter = 0)
{
    if (ds > 0) {
        switch (filter) {
            case 0:
                if (ds == 2) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 2>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 3>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 4>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 8>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 16>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<Identity<Double<1,1>, 32>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 1:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass3<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 2:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass4<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 3:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass3e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 4:
                if (ds == 2) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 2, REAL>>(DSP);
                } else if (ds == 3) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 3, REAL>>(DSP);
                } else if (ds == 4) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 4, REAL>>(DSP);
                } else if (ds == 8) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 8, REAL>>(DSP);
                } else if (ds == 16) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 16, REAL>>(DSP);
                } else if (ds == 32) {
                    return new dsp_down_sampler<LowPass6e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : ds factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            default:
                fprintf(stderr, "ERROR : filter type must be in [0..4] range\n");
                assert(false);
                return nullptr;
        }
    } else if (us > 0) {
        
        switch (filter) {
            case 0:
                if (us == 2) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 2>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 3>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 4>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 8>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 16>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<Identity<Double<1,1>, 32>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 1:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass3<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 2:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass4<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 3:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass3e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            case 4:
                if (us == 2) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 2, REAL>>(DSP);
                } else if (us == 3) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 3, REAL>>(DSP);
                } else if (us == 4) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 4, REAL>>(DSP);
                } else if (us == 8) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 8, REAL>>(DSP);
                } else if (us == 16) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 16, REAL>>(DSP);
                } else if (us == 32) {
                    return new dsp_up_sampler<LowPass6e<Double<45,100>, 32, REAL>>(DSP);
                } else {
                    fprintf(stderr, "ERROR : us factor type must be in [2..32] range\n");
                    assert(false);
                    return nullptr;
                }
            default:
                fprintf(stderr, "ERROR : filter type must be in [0..4] range\n");
                assert(false);
                return nullptr;
        }
    } else {
        return DSP;
    }
}
    
#endif
/************************** END dsp-adapter.h **************************/
/************************** BEGIN misc.h *******************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
***************************************************************************/

#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <string>

/************************** BEGIN meta.h *******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__


/**
 The base class of Meta handler to be used in dsp::metadata(Meta* m) method to retrieve (key, value) metadata.
 */
struct FAUST_API Meta {
    virtual ~Meta() {}
    virtual void declare(const char* key, const char* value) = 0;
};

#endif
/**************************  END  meta.h **************************/

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

static int lsr(int x, int n) { return int(((unsigned int)x) >> n); }

static int int2pow2(int x) { int r = 0; while ((1<<r) < x) r++; return r; }

static long lopt(char* argv[], const char* name, long def)
{
    for (int i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
    return def;
}

static long lopt1(int argc, char* argv[], const char* longname, const char* shortname, long def)
{
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i-1], shortname) == 0 || strcmp(argv[i-1], longname) == 0) {
            return atoi(argv[i]);
        }
    }
    return def;
}

static const char* lopts(char* argv[], const char* name, const char* def)
{
    for (int i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
    return def;
}

static const char* lopts1(int argc, char* argv[], const char* longname, const char* shortname, const char* def)
{
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i-1], shortname) == 0 || strcmp(argv[i-1], longname) == 0) {
            return argv[i];
        }
    }
    return def;
}

static bool isopt(char* argv[], const char* name)
{
    for (int i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
    return false;
}

static std::string pathToContent(const std::string& path)
{
    std::ifstream file(path.c_str(), std::ifstream::binary);
    
    file.seekg(0, file.end);
    int size = int(file.tellg());
    file.seekg(0, file.beg);
    
    // And allocate buffer to that a single line can be read...
    char* buffer = new char[size + 1];
    file.read(buffer, size);
    
    // Terminate the string
    buffer[size] = 0;
    std::string result = buffer;
    file.close();
    delete [] buffer;
    return result;
}

#endif

/**************************  END  misc.h **************************/
/************************** BEGIN SaveUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef FAUST_SAVEUI_H
#define FAUST_SAVEUI_H

/************************** BEGIN DecoratorUI.h **************************
 FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class FAUST_API GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class FAUST_API DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

// Defined here to simplify header #include inclusion 
class FAUST_API SoundUIInterface : public GenericUI {};

#endif
/**************************  END  DecoratorUI.h **************************/

// Base class to handle controllers state save/load

class SaveUI : public GenericUI {

    protected:
    
        struct SavedZone {
            FAUSTFLOAT* fZone;
            FAUSTFLOAT fCurrent;
            FAUSTFLOAT fInit;
            
            SavedZone():fZone(nullptr), fCurrent(FAUSTFLOAT(0)), fInit(FAUSTFLOAT(0))
            {}
            SavedZone(FAUSTFLOAT* zone, FAUSTFLOAT current, FAUSTFLOAT init)
            :fZone(zone), fCurrent(current), fInit(init)
            {
                *fZone = current;
            }
            ~SavedZone()
            {}
        };
        
        std::map<std::string, SavedZone> fName2Zone;
    
        virtual void addItem(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init) = 0;
    
    public:
    
        SaveUI() {}
        virtual ~SaveUI() {}
    
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addItem(label, zone, FAUSTFLOAT(0));
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addItem(label, zone, FAUSTFLOAT(0));
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addItem(label, zone, init);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addItem(label, zone, init);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addItem(label, zone, init);
        }

        void reset()
        {
            for (const auto& it : fName2Zone) {
                *it.second.fZone = it.second.fInit;
            }
        }
        
        void display()
        {
            for (const auto& it : fName2Zone) {
                std::cout << "SaveUI::display path = " << it.first << " value = " << *it.second.fZone << std::endl;
            }
        }
        
        void save()
        {
            for (auto& it : fName2Zone) {
                it.second.fCurrent = *it.second.fZone;
            }
        }
};

/*
 Save/load current value using the label, reset to init value
 */

class SaveLabelUI : public SaveUI {
    
    protected:
    
        void addItem(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init)
        {
            if (fName2Zone.find(label) != fName2Zone.end()) {
                FAUSTFLOAT current = fName2Zone[label].fCurrent;
                fName2Zone[label] = SavedZone(zone, current, init);
            } else {
                fName2Zone[label] = SavedZone(zone, init, init);
            }
        }
        
    public:
        
        SaveLabelUI() : SaveUI() {}
        virtual ~SaveLabelUI() {}        
   
};

/*
 Save/load current value using the complete path, reset to init value
*/

class SavePathUI : public SaveUI, public PathBuilder {
    
    protected:
    
        void openTabBox(const char* label) { pushLabel(label); }
        void openHorizontalBox(const char* label) { pushLabel(label);; }
        void openVerticalBox(const char* label) { pushLabel(label); }
        void closeBox() { popLabel(); };
    
        void addItem(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init)
        {
            std::string path = buildPath(label);
            if (fName2Zone.find(path) != fName2Zone.end()) {
                FAUSTFLOAT current = fName2Zone[path].fCurrent;
                fName2Zone[path] = SavedZone(zone, current, init);
            } else {
                fName2Zone[path] = SavedZone(zone, init, init);
            }
        }
   
    public:

        SavePathUI(): SaveUI() {}
        virtual ~SavePathUI() {}

};

#endif

/**************************  END  SaveUI.h **************************/

// Always included
/************************** BEGIN OSCUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *********************************************************************/

#ifndef __OSCUI__
#define __OSCUI__

#include <vector>
#include <string>

/*

  Faust Project

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __OSCControler__
#define __OSCControler__

#include <string>
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustFactory__
#define __FaustFactory__

#include <stack>
#include <string>
#include <sstream>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustNode__
#define __FaustNode__

#include <string>
#include <vector>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageDriven__
#define __MessageDriven__

#include <string>
#include <vector>

/*

  Copyright (C) 2010  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageProcessor__
#define __MessageProcessor__

namespace oscfaust
{

class Message;
//--------------------------------------------------------------------------
/*!
	\brief an abstract class for objects able to process OSC messages	
*/
class MessageProcessor
{
	public:
		virtual		~MessageProcessor() {}
		virtual void processMessage( const Message* msg ) = 0;
};

} // end namespoace

#endif
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __smartpointer__
#define __smartpointer__

#include <cassert>

namespace oscfaust
{

/*!
\brief the base class for smart pointers implementation

	Any object that want to support smart pointers should
	inherit from the smartable class which provides reference counting
	and automatic delete when the reference count drops to zero.
*/
class smartable {
	private:
		unsigned 	refCount;		
	public:
		//! gives the reference count of the object
		unsigned refs() const         { return refCount; }
		//! addReference increments the ref count and checks for refCount overflow
		void addReference()           { refCount++; assert(refCount != 0); }
		//! removeReference delete the object when refCount is zero		
		void removeReference()		  { if (--refCount == 0) delete this; }
		
	protected:
		smartable() : refCount(0) {}
		smartable(const smartable&): refCount(0) {}
		//! destructor checks for non-zero refCount
		virtual ~smartable()    
        { 
            /* 
                See "Static SFaustNode create (const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui)" comment.
                assert (refCount == 0); 
            */
        }
		smartable& operator=(const smartable&) { return *this; }
};

/*!
\brief the smart pointer implementation

	A smart pointer is in charge of maintaining the objects reference count 
	by the way of pointers operators overloading. It supports class 
	inheritance and conversion whenever possible.
\n	Instances of the SMARTP class are supposed to use \e smartable types (or at least
	objects that implements the \e addReference and \e removeReference
	methods in a consistent way).
*/
template<class T> class SMARTP {
	private:
		//! the actual pointer to the class
		T* fSmartPtr;

	public:
		//! an empty constructor - points to null
		SMARTP()	: fSmartPtr(0) {}
		//! build a smart pointer from a class pointer
		SMARTP(T* rawptr) : fSmartPtr(rawptr)              { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from an convertible class reference
		template<class T2> 
		SMARTP(const SMARTP<T2>& ptr) : fSmartPtr((T*)ptr) { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from another smart pointer reference
		SMARTP(const SMARTP& ptr) : fSmartPtr((T*)ptr)     { if (fSmartPtr) fSmartPtr->addReference(); }

		//! the smart pointer destructor: simply removes one reference count
		~SMARTP()  { if (fSmartPtr) fSmartPtr->removeReference(); }
		
		//! cast operator to retrieve the actual class pointer
		operator T*() const  { return fSmartPtr;	}

		//! '*' operator to access the actual class pointer
		T& operator*() const {
			// checks for null dereference
			assert (fSmartPtr != 0);
			return *fSmartPtr;
		}

		//! operator -> overloading to access the actual class pointer
		T* operator->() const	{ 
			// checks for null dereference
			assert (fSmartPtr != 0);
			return fSmartPtr;
		}

		//! operator = that moves the actual class pointer
		template <class T2>
		SMARTP& operator=(T2 p1_)	{ *this=(T*)p1_; return *this; }

		//! operator = that moves the actual class pointer
		SMARTP& operator=(T* p_)	{
			// check first that pointers differ
			if (fSmartPtr != p_) {
				// increments the ref count of the new pointer if not null
				if (p_ != 0) p_->addReference();
				// decrements the ref count of the old pointer if not null
				if (fSmartPtr != 0) fSmartPtr->removeReference();
				// and finally stores the new actual pointer
				fSmartPtr = p_;
			}
			return *this;
		}
		//! operator < to support SMARTP map with Visual C++
		bool operator<(const SMARTP<T>& p_)	const			  { return fSmartPtr < ((T *) p_); }
		//! operator = to support inherited class reference
		SMARTP& operator=(const SMARTP<T>& p_)                { return operator=((T *) p_); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(T2* p_)               { return operator=(dynamic_cast<T*>(p_)); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(const SMARTP<T2>& p_) { return operator=(dynamic_cast<T*>(p_)); }
};

}

#endif

namespace oscfaust
{

class Message;
class OSCRegexp;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a base class for objects accepting OSC messages
	
	Message driven objects are hierarchically organized in a tree.
	They provides the necessary to dispatch an OSC message to its destination
	node, according to the message OSC address. 
	
	The principle of the dispatch is the following:
	- first the processMessage() method should be called on the top level node
	- next processMessage call propose 
*/
class MessageDriven : public MessageProcessor, public smartable
{
	std::string						fName;			///< the node name
	std::string						fOSCPrefix;		///< the node OSC address prefix (OSCAddress = fOSCPrefix + '/' + fName)
	std::vector<SMessageDriven>		fSubNodes;		///< the subnodes of the current node

	protected:
				 MessageDriven(const char *name, const char *oscprefix) : fName (name), fOSCPrefix(oscprefix) {}
		virtual ~MessageDriven() {}

	public:
		static SMessageDriven create(const char* name, const char *oscprefix)	{ return new MessageDriven(name, oscprefix); }

		/*!
			\brief OSC message processing method.
			\param msg the osc message to be processed
			The method should be called on the top level node.
		*/
		virtual void	processMessage(const Message* msg);

		/*!
			\brief propose an OSc message at a given hierarchy level.
			\param msg the osc message currently processed
			\param regexp a regular expression based on the osc address head
			\param addrTail the osc address tail
			
			The method first tries to match the regular expression with the object name. 
			When it matches:
			- it calls \c accept when \c addrTail is empty 
			- or it \c propose the message to its subnodes when \c addrTail is not empty. 
			  In this case a new \c regexp is computed with the head of \c addrTail and a new \c addrTail as well.
		*/
		virtual void	propose(const Message* msg, const OSCRegexp* regexp, const std::string& addrTail);

		/*!
			\brief accept an OSC message. 
			\param msg the osc message currently processed
			\return true when the message is processed by the node
			
			The method is called only for the destination nodes. The real message acceptance is the node 
			responsability and may depend on the message content.
		*/
		virtual bool	accept(const Message* msg);

		/*!
			\brief handler for the \c 'get' message
			\param ipdest the output message destination IP
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get(unsigned long ipdest) const;

		/*!
			\brief handler for the \c 'get' 'attribute' message
			\param ipdest the output message destination IP
			\param what the requested attribute
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get(unsigned long ipdest, const std::string& what) const {}

		void			add(SMessageDriven node)	{ fSubNodes.push_back (node); }
		const char*		getName() const				{ return fName.c_str(); }
		std::string		getOSCAddress() const;
		int				size() const				{ return (int)fSubNodes.size (); }
		
		const std::string&	name() const			{ return fName; }
		SMessageDriven	subnode(int i)              { return fSubNodes[i]; }
};

} // end namespoace

#endif
/*

  Copyright (C) 2011  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/


#ifndef __Message__
#define __Message__

#include <string>
#include <vector>

namespace oscfaust
{

class OSCStream;
template <typename T> class MsgParam;
class baseparam;
typedef SMARTP<baseparam>	Sbaseparam;

//--------------------------------------------------------------------------
/*!
	\brief base class of a message parameters
*/
class baseparam : public smartable
{
	public:
		virtual ~baseparam() {}

		/*!
		 \brief utility for parameter type checking
		*/
		template<typename X> bool isType() const { return dynamic_cast<const MsgParam<X>*> (this) != 0; }
		/*!
		 \brief utility for parameter convertion
		 \param errvalue the returned value when no conversion applies
		 \return the parameter value when the type matches
		*/
		template<typename X> X	value(X errvalue) const 
			{ const MsgParam<X>* o = dynamic_cast<const MsgParam<X>*> (this); return o ? o->getValue() : errvalue; }
		/*!
		 \brief utility for parameter comparison
		*/
		template<typename X> bool	equal(const baseparam& p) const 
			{ 
				const MsgParam<X>* a = dynamic_cast<const MsgParam<X>*> (this); 
				const MsgParam<X>* b = dynamic_cast<const MsgParam<X>*> (&p);
				return a && b && (a->getValue() == b->getValue());
			}
		/*!
		 \brief utility for parameter comparison
		*/
		bool operator==(const baseparam& p) const 
			{ 
				return equal<float>(p) || equal<int>(p) || equal<std::string>(p);
			}
		bool operator!=(const baseparam& p) const
			{ 
				return !equal<float>(p) && !equal<int>(p) && !equal<std::string>(p);
			}
			
		virtual SMARTP<baseparam> copy() const = 0;
};

//--------------------------------------------------------------------------
/*!
	\brief template for a message parameter
*/
template <typename T> class MsgParam : public baseparam
{
	T fParam;
	public:
				 MsgParam(T val) : fParam(val)	{}
		virtual ~MsgParam() {}
		
		T getValue() const { return fParam; }
		
		virtual Sbaseparam copy() const { return new MsgParam<T>(fParam); }
};

//--------------------------------------------------------------------------
/*!
	\brief a message description
	
	A message is composed of an address (actually an OSC address),
	a message string that may be viewed as a method name
	and a list of message parameters.
*/
class Message
{
    public:
        typedef SMARTP<baseparam>		argPtr;		///< a message argument ptr type
        typedef std::vector<argPtr>		argslist;	///< args list type

    private:
        unsigned long	fSrcIP;			///< the message source IP number
        std::string	fAddress;			///< the message osc destination address
        std::string	fAlias;             ///< the message alias osc destination address
        argslist	fArguments;			///< the message arguments

    public:
            /*!
                \brief an empty message constructor
            */
             Message() {}
            /*!
                \brief a message constructor
                \param address the message destination address
            */
            Message(const std::string& address) : fAddress(address), fAlias("") {}
             
            Message(const std::string& address, const std::string& alias) : fAddress(address), fAlias(alias) {}
            /*!
                \brief a message constructor
                \param address the message destination address
                \param args the message parameters
            */
            Message(const std::string& address, const argslist& args) 
                : fAddress(address), fArguments(args) {}
            /*!
                \brief a message constructor
                \param msg a message
            */
             Message(const Message& msg);
    virtual ~Message() {} //{ freed++; std::cout << "running messages: " << (allocated - freed) << std::endl; }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    template <typename T> void add(T val)	{ fArguments.push_back(new MsgParam<T>(val)); }
    /*!
        \brief adds a float parameter to the message
        \param val the parameter value
    */
    void	add(float val)					{ add<float>(val); }
    
    /*!
     \brief adds a double parameter to the message
     \param val the parameter value
     */
    void	add(double val)					{ add<double>(val); }
    
    /*!
        \brief adds an int parameter to the message
        \param val the parameter value
    */
    void	add(int val)					{ add<int>(val); }
    
    /*!
        \brief adds a string parameter to the message
        \param val the parameter value
    */
    void	add(const std::string& val)		{ add<std::string>(val); }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    void	add(argPtr val)                 { fArguments.push_back( val ); }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setSrcIP(unsigned long addr)		{ fSrcIP = addr; }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setAddress(const std::string& addr)		{ fAddress = addr; }
    /*!
        \brief print the message
        \param out the output stream
    */
    void				print(std::ostream& out) const;
    /*!
        \brief send the message to OSC
        \param out the OSC output stream
    */
    void				print(OSCStream& out) const;
    /*!
        \brief print message arguments
        \param out the OSC output stream
    */
    void				printArgs(OSCStream& out) const;

    /// \brief gives the message address
    const std::string&	address() const		{ return fAddress; }
    /// \brief gives the message alias
    const std::string&	alias() const		{ return fAlias; }
    /// \brief gives the message parameters list
    const argslist&		params() const		{ return fArguments; }
    /// \brief gives the message parameters list
    argslist&			params()			{ return fArguments; }
    /// \brief gives the message source IP 
    unsigned long		src() const			{ return fSrcIP; }
    /// \brief gives the message parameters count
    int					size() const		{ return (int)fArguments.size(); }

    bool operator == (const Message& other) const;	

    /*!
        \brief gives a message float parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, float& val) const		{ val = params()[i]->value<float>(val); return params()[i]->isType<float>(); }
    
    /*!
     \brief gives a message double parameter
     \param i the parameter index (0 <= i < size())
     \param val on output: the parameter value when the parameter type matches
     \return false when types don't match
     */
    bool	param(int i, double& val) const		{ val = params()[i]->value<double>(val); return params()[i]->isType<double>(); }
    
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, unsigned int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
        \note a boolean value is handled as integer
    */
    bool	param(int i, bool& val) const		{ int ival = 0; ival = params()[i]->value<int>(ival); val = ival!=0; return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, long int& val) const	{ val = long(params()[i]->value<int>(val)); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message string parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, std::string& val) const { val = params()[i]->value<std::string>(val); return params()[i]->isType<std::string>(); }
};


} // end namespoace

#endif
/************************** BEGIN GUI.h **********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <assert.h>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/************************** BEGIN ValueConverter.h ********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
 ValueConverter.h
 (GRAME, Copyright 2015-2019)
 
 Set of conversion objects used to map user interface values (for example a gui slider
 delivering values between 0 and 1) to faust values (for example a vslider between
 20 and 20000) using a log scale.
 
 -- Utilities
 
 Range(lo,hi) : clip a value x between lo and hi
 Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
 Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2
 
 -- Value Converters
 
 ValueConverter::ui2faust(x)
 ValueConverter::faust2ui(x)
 
 -- ValueConverters used for sliders depending of the scale
 
 LinearValueConverter(umin, umax, fmin, fmax)
 LinearValueConverter2(lo, mi, hi, v1, vm, v2) using 2 segments
 LogValueConverter(umin, umax, fmin, fmax)
 ExpValueConverter(umin, umax, fmin, fmax)
 
 -- ValueConverters used for accelerometers based on 3 points
 
 AccUpConverter(amin, amid, amax, fmin, fmid, fmax)        -- curve 0
 AccDownConverter(amin, amid, amax, fmin, fmid, fmax)      -- curve 1
 AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)    -- curve 2
 AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)    -- curve 3
 
 -- lists of ZoneControl are used to implement accelerometers metadata for each axes
 
 ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter
 
 -- ZoneReader are used to implement screencolor metadata
 
 ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>


//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef           with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef              with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class FAUST_API Interpolator {
    
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class FAUST_API Interpolator3pt {

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class FAUST_API ValueConverter {

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) { return x; };
        virtual double faust2ui(double x) { return x; };
};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class FAUST_API UpdatableValueConverter : public ValueConverter {
    
    protected:
        
        bool fActive;
        
    public:
        
        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}
        
        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;
        
        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }
    
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LinearValueConverter : public ValueConverter {
    
    private:
        
        Interpolator fUI2F;
        Interpolator fF2UI;
        
    public:
        
        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}
        
        LinearValueConverter() : fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) { return fUI2F(x); }
        virtual double faust2ui(double x) { return fF2UI(x); }
    
};

//--------------------------------------------------------------------------------------
// Two segments linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LinearValueConverter2 : public UpdatableValueConverter {
    
    private:
    
        Interpolator3pt fUI2F;
        Interpolator3pt fF2UI;
        
    public:
    
        LinearValueConverter2(double amin, double amid, double amax, double min, double init, double max) :
            fUI2F(amin, amid, amax, min, init, max), fF2UI(min, init, max, amin, amid, amax)
        {}
        
        LinearValueConverter2() : fUI2F(0.,0.,0.,0.,0.,0.), fF2UI(0.,0.,0.,0.,0.,0.)
        {}
    
        virtual double ui2faust(double x) { return fUI2F(x); }
        virtual double faust2ui(double x) { return fF2UI(x); }
    
        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max)
        {
            fUI2F = Interpolator3pt(amin, amid, amax, min, init, max);
            fF2UI = Interpolator3pt(min, init, max, amin, amid, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fUI2F.getMappingValues(amin, amid, amax);
        }
    
};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API LogValueConverter : public LinearValueConverter {

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, std::log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) { return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class FAUST_API ExpValueConverter : public LinearValueConverter {

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, std::min<double>(DBL_MAX, std::exp(fmin)), std::min<double>(DBL_MAX, std::exp(fmax)))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::min<double>(DBL_MAX, std::exp(x))); }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class FAUST_API AccUpConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmin, fmid, fmax);
            fF2A = Interpolator3pt(fmin, fmid, fmax, amin, amid, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class FAUST_API AccDownConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmax, fmid, fmin);
            fF2A = Interpolator3pt(fmin, fmid, fmax, amax, amid, amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class FAUST_API AccUpDownConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotonic function
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmin, fmax, fmin);
            fF2A = Interpolator(fmin, fmax, amin, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class FAUST_API AccDownUpConverter : public UpdatableValueConverter {

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotonic function
        {}

        virtual double ui2faust(double x) { return fA2F(x); }
        virtual double faust2ui(double x) { return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin, amid, amax, fmax, fmin, fmax);
            fF2A = Interpolator(fmin, fmax, amin, amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class FAUST_API ZoneControl {

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) const {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class FAUST_API ConverterZoneControl : public ZoneControl {

    protected:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* converter) : ZoneControl(zone), fValueConverter(converter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        virtual void update(double v) const { *fZone = FAUSTFLOAT(fValueConverter->ui2faust(v)); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class FAUST_API CurveZoneControl : public ZoneControl {

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            for (const auto& it : fValueConverters) { delete it; }
        }
        void update(double v) const { if (fValueConverters[fCurve]->getActive()) *fZone = FAUSTFLOAT(fValueConverters[fCurve]->ui2faust(v)); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            for (const auto& it : fValueConverters) { it->setActive(on_off); }
        }

        int getCurve() { return fCurve; }
};

class FAUST_API ZoneReader {

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            return (fZone != nullptr) ? int(fInterpolator(*fZone)) : 127;
        }

};

#endif
/**************************  END  ValueConverter.h **************************/
/************************** BEGIN MetaDataUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef MetaData_UI_H
#define MetaData_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <map>
#include <set>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h> // We use the lighter fprintf code


static bool startWith(const std::string& str, const std::string& prefix)
{
    return (str.substr(0, prefix.size()) == prefix);
}

/**
 * Convert a dB value into a scale between 0 and 1 (following IEC standard ?)
 */
static FAUSTFLOAT dB2Scale(FAUSTFLOAT dB)
{
    FAUSTFLOAT scale = FAUSTFLOAT(1.0);
    
    /*if (dB < -70.0f)
     scale = 0.0f;
     else*/
    if (dB < FAUSTFLOAT(-60.0))
        scale = (dB + FAUSTFLOAT(70.0)) * FAUSTFLOAT(0.0025);
    else if (dB < FAUSTFLOAT(-50.0))
        scale = (dB + FAUSTFLOAT(60.0)) * FAUSTFLOAT(0.005) + FAUSTFLOAT(0.025);
    else if (dB < FAUSTFLOAT(-40.0))
        scale = (dB + FAUSTFLOAT(50.0)) * FAUSTFLOAT(0.0075) + FAUSTFLOAT(0.075);
    else if (dB < FAUSTFLOAT(-30.0))
        scale = (dB + FAUSTFLOAT(40.0)) * FAUSTFLOAT(0.015) + FAUSTFLOAT(0.15);
    else if (dB < FAUSTFLOAT(-20.0))
        scale = (dB + FAUSTFLOAT(30.0)) * FAUSTFLOAT(0.02) + FAUSTFLOAT(0.3);
    else if (dB < FAUSTFLOAT(-0.001) || dB > FAUSTFLOAT(0.001))  /* if (dB < 0.0) */
        scale = (dB + FAUSTFLOAT(20.0)) * FAUSTFLOAT(0.025) + FAUSTFLOAT(0.5);
    
    return scale;
}

/*******************************************************************************
 * MetaDataUI : Common class for MetaData handling
 ******************************************************************************/

//============================= BEGIN GROUP LABEL METADATA===========================
// Unlike widget's label, metadata inside group's label are not extracted directly by
// the Faust compiler. Therefore they must be extracted within the architecture file
//-----------------------------------------------------------------------------------

class MetaDataUI {
    
    protected:
        
        std::string                         fGroupTooltip;
        std::map<FAUSTFLOAT*, FAUSTFLOAT>   fGuiSize;            // map widget zone with widget size coef
        std::map<FAUSTFLOAT*, std::string>  fTooltip;            // map widget zone with tooltip strings
        std::map<FAUSTFLOAT*, std::string>  fUnit;               // map widget zone to unit string (i.e. "dB")
        std::map<FAUSTFLOAT*, std::string>  fRadioDescription;   // map zone to {'low':440; ...; 'hi':1000.0}
        std::map<FAUSTFLOAT*, std::string>  fMenuDescription;    // map zone to {'low':440; ...; 'hi':1000.0}
        std::set<FAUSTFLOAT*>               fKnobSet;            // set of widget zone to be knobs
        std::set<FAUSTFLOAT*>               fLedSet;             // set of widget zone to be LEDs
        std::set<FAUSTFLOAT*>               fNumSet;             // set of widget zone to be numerical bargraphs
        std::set<FAUSTFLOAT*>               fLogSet;             // set of widget zone having a log UI scale
        std::set<FAUSTFLOAT*>               fExpSet;             // set of widget zone having an exp UI scale
        std::set<FAUSTFLOAT*>               fHiddenSet;          // set of hidden widget zone
        
        void clearMetadata()
        {
            fGuiSize.clear();
            fTooltip.clear();
            fUnit.clear();
            fRadioDescription.clear();
            fMenuDescription.clear();
            fKnobSet.clear();
            fLedSet.clear();
            fNumSet.clear();
            fLogSet.clear();
            fExpSet.clear();
            fHiddenSet.clear();
            fGroupTooltip = "";
        }
        
        /**
         * rmWhiteSpaces(): Remove the leading and trailing white spaces of a string
         * (but not those in the middle of the string)
         */
        static std::string rmWhiteSpaces(const std::string& s)
        {
            size_t i = s.find_first_not_of(" \t");
            size_t j = s.find_last_not_of(" \t");
            if ((i != std::string::npos) && (j != std::string::npos)) {
                return s.substr(i, 1+j-i);
            } else {
                return "";
            }
        }
        
        /**
         * Format tooltip string by replacing some white spaces by
         * return characters so that line width doesn't exceed n.
         * Limitation : long words exceeding n are not cut.
         */
        std::string formatTooltip(int n, const std::string& tt)
        {
            std::string ss = tt;  // ss string we are going to format
            int lws = 0;          // last white space encountered
            int lri = 0;          // last return inserted
            for (int i = 0; i < (int)tt.size(); i++) {
                if (tt[i] == ' ') lws = i;
                if (((i-lri) >= n) && (lws > lri)) {
                    // insert return here
                    ss[lws] = '\n';
                    lri = lws;
                }
            }
            return ss;
        }
        
    public:
        
        virtual ~MetaDataUI()
        {}
        
        enum Scale {
            kLin,
            kLog,
            kExp
        };
        
        Scale getScale(FAUSTFLOAT* zone)
        {
            if (fLogSet.count(zone) > 0) return kLog;
            if (fExpSet.count(zone) > 0) return kExp;
            return kLin;
        }
        
        bool isKnob(FAUSTFLOAT* zone)
        {
            return fKnobSet.count(zone) > 0;
        }
        
        bool isRadio(FAUSTFLOAT* zone)
        {
            return fRadioDescription.count(zone) > 0;
        }
        
        bool isMenu(FAUSTFLOAT* zone)
        {
            return fMenuDescription.count(zone) > 0;
        }
        
        bool isLed(FAUSTFLOAT* zone)
        {
            return fLedSet.count(zone) > 0;
        }
        
        bool isNumerical(FAUSTFLOAT* zone)
        {
            return fNumSet.count(zone) > 0;
        }
        
        bool isHidden(FAUSTFLOAT* zone)
        {
            return fHiddenSet.count(zone) > 0;
        }
        
        /**
         * Extracts metadata from a label : 'vol [unit: dB]' -> 'vol' + metadata(unit=dB)
         */
        static void extractMetadata(const std::string& fulllabel, std::string& label, std::map<std::string, std::string>& metadata)
        {
            enum {kLabel, kEscape1, kEscape2, kEscape3, kKey, kValue};
            int state = kLabel; int deep = 0;
            std::string key, value;
            
            for (unsigned int i = 0; i < fulllabel.size(); i++) {
                char c = fulllabel[i];
                switch (state) {
                    case kLabel :
                        assert(deep == 0);
                        switch (c) {
                            case '\\' : state = kEscape1; break;
                            case '[' : state = kKey; deep++; break;
                            default : label += c;
                        }
                        break;
                        
                    case kEscape1:
                        label += c;
                        state = kLabel;
                        break;
                        
                    case kEscape2:
                        key += c;
                        state = kKey;
                        break;
                        
                    case kEscape3:
                        value += c;
                        state = kValue;
                        break;
                        
                    case kKey:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape2;
                                break;
                                
                            case '[':
                                deep++;
                                key += c;
                                break;
                                
                            case ':':
                                if (deep == 1) {
                                    state = kValue;
                                } else {
                                    key += c;
                                }
                                break;
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = "";
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    key += c;
                                }
                                break;
                            default : key += c;
                        }
                        break;
                        
                    case kValue:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape3;
                                break;
                                
                            case '[':
                                deep++;
                                value += c;
                                break;
                                
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = rmWhiteSpaces(value);
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    value += c;
                                }
                                break;
                            default : value += c;
                        }
                        break;
                        
                    default:
                        fprintf(stderr, "ERROR unrecognized state %d\n", state);
                }
            }
            label = rmWhiteSpaces(label);
        }
        
        /**
         * Analyses the widget zone metadata declarations and takes appropriate actions.
         */
        void declare(FAUSTFLOAT* zone, const char* key, const char* value)
        {
            if (zone == 0) {
                // special zone 0 means group metadata
                if (strcmp(key, "tooltip") == 0) {
                    // only group tooltip are currently implemented
                    fGroupTooltip = formatTooltip(30, value);
                } else if (strcmp(key, "hidden") == 0) {
                    fHiddenSet.insert(zone);
                }
            } else {
                if (strcmp(key, "size") == 0) {
                    fGuiSize[zone] = atof(value);
                }
                else if (strcmp(key, "tooltip") == 0) {
                    fTooltip[zone] = formatTooltip(30, value);
                }
                else if (strcmp(key, "unit") == 0) {
                    fUnit[zone] = value;
                }
                else if (strcmp(key, "hidden") == 0) {
                    fHiddenSet.insert(zone);
                }
                else if (strcmp(key, "scale") == 0) {
                    if (strcmp(value, "log") == 0) {
                        fLogSet.insert(zone);
                    } else if (strcmp(value, "exp") == 0) {
                        fExpSet.insert(zone);
                    }
                }
                else if (strcmp(key, "style") == 0) {
                    if (strcmp(value, "knob") == 0) {
                        fKnobSet.insert(zone);
                    } else if (strcmp(value, "led") == 0) {
                        fLedSet.insert(zone);
                    } else if (strcmp(value, "numerical") == 0) {
                        fNumSet.insert(zone);
                    } else {
                        const char* p = value;
                        if (parseWord(p, "radio")) {
                            fRadioDescription[zone] = std::string(p);
                        } else if (parseWord(p, "menu")) {
                            fMenuDescription[zone] = std::string(p);
                        }
                    }
                }
            }
        }
    
};

#endif
/**************************  END  MetaDataUI.h **************************/
/************************** BEGIN ring-buffer.h **************************/
/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
# pragma warning (disable: 4334)
#else
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

static ringbuffer_t *ringbuffer_create(size_t sz);
static void ringbuffer_free(ringbuffer_t *rb);
static void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
static void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
static size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
static size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
static void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_read_space(const ringbuffer_t *rb);
static int ringbuffer_mlock(ringbuffer_t *rb);
static void ringbuffer_reset(ringbuffer_t *rb);
static void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
static size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
static void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

static ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

static void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

static int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

static size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

static size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

static size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

static void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

static void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__
/**************************  END  ring-buffer.h **************************/

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
class GUI;
struct clist;

typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

/**
 * Base class for uiTypedItem: memory zones that can be grouped and synchronized, using an internal cache.
 */
struct uiItemBase
{
    
    uiItemBase(GUI* ui, FAUSTFLOAT* zone)
    {
        assert(ui);
        assert(zone);
    }
    
    virtual ~uiItemBase()
    {}
    
    /**
     * This method will be called when the value changes externally,
     * and will signal the new value to all linked uItem
     * when the value is different from the cached one.
     *
     * @param v - the new value
     */
    virtual void modifyZone(FAUSTFLOAT v) = 0;
    
    /**
     * This method will be called when the value changes externally,
     * and will signal the new value to all linked uItem
     * when the value is different from the cached one.
     *
     * @param date - the timestamp of the received value in usec
     * @param v - the new value
     */
    virtual void modifyZone(double date, FAUSTFLOAT v) {}
    
    /**
     * This method is called by the synchronisation mecanism and is expected
     * to 'reflect' the new value, by changing the Widget layout for instance,
     * or sending a message (OSC, MIDI...)
     */
    virtual void reflectZone() = 0;
    
    /**
     * Return the cached value.
     *
     * @return - the cached value
     */
    virtual double cache() = 0;
    
};

// Declared as 'static' to avoid code duplication at link time
static void deleteClist(clist* cl);

/**
 * A list containing all groupe uiItemBase objects.
 */
struct clist : public std::list<uiItemBase*>
{
    
    virtual ~clist()
    {
        deleteClist(this);
    }
        
};

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data);

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
    
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            for (const auto& it : fZoneMap) {
                delete it.second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItemBase* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }
    
        void updateZone(FAUSTFLOAT* z)
        {
            FAUSTFLOAT v = *z;
            clist* cl = fZoneMap[z];
            for (const auto& c : *cl) {
                if (c->cache() != v) c->reflectZone();
            }
        }
    
        void updateAllZones()
        {
            for (const auto& m : fZoneMap) {
                updateZone(m.first);
            }
        }
    
        static void updateAllGuis()
        {
            for (const auto& g : fGuiList) {
                g->updateAllZones();
            }
        }
    
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data)
        {
            createUiCallbackItem(this, zone, foo, data);
        }

        // Start event or message processing
        virtual bool run() { return false; };
        // Stop event or message processing
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition.
 */
template <typename REAL>
class uiTypedItemReal : public uiItemBase
{
    protected:
        
        GUI* fGUI;
        REAL* fZone;
        REAL fCache;
        
        uiTypedItemReal(GUI* ui, REAL* zone):uiItemBase(ui, static_cast<FAUSTFLOAT*>(zone)),
        fGUI(ui), fZone(zone), fCache(REAL(-123456.654321))
        {
            ui->registerZone(zone, this);
        }
        
    public:
        
        virtual ~uiTypedItemReal()
        {}
    
        void modifyZone(REAL v)
        {
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
    
        double cache() { return fCache; }
    
};

class uiItem : public uiTypedItemReal<FAUSTFLOAT> {
    
    protected:
    
        uiItem(GUI* ui, FAUSTFLOAT* zone):uiTypedItemReal<FAUSTFLOAT>(ui, zone)
        {}

    public:

        virtual ~uiItem() 
        {}

		void modifyZone(FAUSTFLOAT v)
		{
			fCache = v;
			if (*fZone != v) {
				*fZone = v;
				fGUI->updateZone(fZone);
			}
		}

};

/**
 * Base class for items with a value converter.
 */
struct uiConverter {
    
    ValueConverter* fConverter;
    
    uiConverter(MetaDataUI::Scale scale, FAUSTFLOAT umin, FAUSTFLOAT umax, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        // Select appropriate converter according to scale mode
        if (scale == MetaDataUI::kLog) {
            fConverter = new LogValueConverter(umin, umax, fmin, fmax);
        } else if (scale == MetaDataUI::kExp) {
            fConverter = new ExpValueConverter(umin, umax, fmin, fmax);
        } else {
            fConverter = new LinearValueConverter(umin, umax, fmin, fmax);
        }
    }
    
    virtual ~uiConverter()
    {
        delete fConverter;
    }
};

/**
 * User Interface item owned (and so deleted) by external code.
 */
class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item.
 */
class uiCallbackItem : public uiItem {
    
    protected:
    
        uiCallback fCallback;
        void* fData;
    
    public:
    
        uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
        : uiItem(ui, zone), fCallback(foo), fData(data) {}
        
        virtual void reflectZone() 
        {		
            FAUSTFLOAT v = *fZone;
            fCache = v; 
            fCallback(v, fData);	
        }
};

/**
 *  For timestamped control.
 */
struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

/**
 * Base class for timed items.
 */
class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
    
        using uiItem::modifyZone;
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                fprintf(stderr, "ringbuffer_write error DatedControl\n");
            }
        }
    
};

/**
 * Allows to group a set of zones.
 */
class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            for (const auto& it : fZoneMap) {
                *it = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

// Cannot be defined as method in the classes.

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
{
    new uiCallbackItem(ui, zone, foo, data);
}

static void deleteClist(clist* cl)
{
    for (const auto& it : *cl) {
        // This specific code is only used in JUCE context. TODO: use proper 'shared_ptr' based memory management.
    #if defined(JUCE_32BIT) || defined(JUCE_64BIT)
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(it);
        // owned items are deleted by external code
        if (!owned) {
            delete it;
        }
    #else
        delete it;
    #endif
    }
}

#endif
/**************************  END  GUI.h **************************/
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __RootNode__
#define __RootNode__

#include <map>
#include <string>
#include <vector>

/************************** BEGIN JSONUI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>


/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 *
 * Since 'shortname' can only be computed when all paths have been created,
 * the fAllUI vector is progressively filled with partially built UI items,
 * which are finally created in the JSON(...) method.
 ******************************************************************************/

typedef std::vector<std::tuple<std::string, int, int, int, int, int>> MemoryLayoutType;
typedef std::map<std::string, int> PathTableType;

template <typename REAL>
class FAUST_API JSONUIReal : public PathBuilder, public Meta, public UIReal<REAL> {

    protected:
    
        std::stringstream fUI;
        std::vector<std::string> fAllUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;           // Compiler version
        std::string fCompileOptions;    // Compilation options
        std::vector<std::string> fLibraryList;
        std::vector<std::string> fIncludePathnames;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fJSON;
        int fDSPSize;                   // In bytes
        PathTableType fPathTable;
        MemoryLayoutType fMemoryLayout;
        bool fExtended;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs, fSRIndex;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        std::string flatten(const std::string& src)
        {
            std::string dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    default:
                        dst += src[i];
                        break;
                }
            }
            return dst;
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        int getAddressIndex(const std::string& path)
        {
            return (fPathTable.find(path) != fPathTable.end()) ? fPathTable[path] : -1;
        }
      
     public:
     
        JSONUIReal(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const PathTableType& path_table,
                  MemoryLayoutType memory_layout)
        {
            init(name, filename, inputs, outputs, sr_index, sha_key, dsp_code, version, compile_options, library_list, include_pathnames, size, path_table, memory_layout);
        }

        JSONUIReal(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }

        JSONUIReal(int inputs, int outputs)
        {
            init("", "", inputs, outputs, -1, "", "","", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }
        
        JSONUIReal()
        {
            init("", "", -1, -1, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, PathTableType(), MemoryLayoutType());
        }
 
        virtual ~JSONUIReal() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        void setSRIndex(int sr_index) { fSRIndex = sr_index; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const PathTableType& path_table,
                  MemoryLayoutType memory_layout,
                  bool extended = false)
        {
            fTab = 1;
            fExtended = extended;
            if (fExtended) {
                fUI << std::setprecision(std::numeric_limits<REAL>::max_digits10);
                fMeta << std::setprecision(std::numeric_limits<REAL>::max_digits10);
            }
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fSRIndex = sr_index;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fCompileOptions = compile_options;
            fLibraryList = library_list;
            fIncludePathnames = include_pathnames;
            fMemoryLayout = memory_layout;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            pushLabel(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
            }
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
        
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
        
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab, false);
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
         
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
        
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"init\": " << init << ",";
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max << ",";
            tab(fTab, fUI); fUI << "\"step\": " << step;
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
         
            // Generate 'shortname' entry
            tab(fTab, fUI); fUI << "\"shortname\": \"";
        
            // Add fUI section
            fAllUI.push_back(fUI.str());
            fUI.str("");
            
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max;
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fPathTable.size() > 0) ? "," : "");
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path);
            }
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            if (fJSON.empty()) {
                fTab = 0;
                std::stringstream JSON;
                if (fExtended) {
                    JSON << std::setprecision(std::numeric_limits<REAL>::max_digits10);
                }
                JSON << "{";
                fTab += 1;
                tab(fTab, JSON); JSON << "\"name\": \"" << fName << "\",";
                tab(fTab, JSON); JSON << "\"filename\": \"" << fFileName << "\",";
                if (fVersion != "") { tab(fTab, JSON); JSON << "\"version\": \"" << fVersion << "\","; }
                if (fCompileOptions != "") { tab(fTab, JSON); JSON << "\"compile_options\": \"" <<  fCompileOptions << "\","; }
                if (fLibraryList.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"library_list\": [";
                    for (size_t i = 0; i < fLibraryList.size(); i++) {
                        JSON << "\"" << fLibraryList[i] << "\"";
                        if (i < (fLibraryList.size() - 1)) JSON << ",";
                    }
                    JSON << "],";
                }
                if (fIncludePathnames.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"include_pathnames\": [";
                    for (size_t i = 0; i < fIncludePathnames.size(); i++) {
                        JSON << "\"" << fIncludePathnames[i] << "\"";
                        if (i < (fIncludePathnames.size() - 1)) JSON << ",";
                    }
                    JSON << "],";
                }
                if (fMemoryLayout.size() > 0) {
                    tab(fTab, JSON);
                    JSON << "\"memory_layout\": [";
                    for (size_t i = 0; i < fMemoryLayout.size(); i++) {
                        // DSP or field name, type, size, sizeBytes, reads, writes
                        std::tuple<std::string, int, int, int, int, int> item = fMemoryLayout[i];
                        tab(fTab + 1, JSON);
                        JSON << "{\"size\": " << std::get<3>(item) << ", ";
                        JSON << "\"reads\": " << std::get<4>(item) << ", ";
                        JSON << "\"writes\": " << std::get<5>(item) << "}";
                        if (i < (fMemoryLayout.size() - 1)) JSON << ",";
                    }
                    tab(fTab, JSON);
                    JSON << "],";
                }
                if (fDSPSize != -1) { tab(fTab, JSON); JSON << "\"size\": " << fDSPSize << ","; }
                if (fSHAKey != "") { tab(fTab, JSON); JSON << "\"sha_key\": \"" << fSHAKey << "\","; }
                if (fExpandedCode != "") { tab(fTab, JSON); JSON << "\"code\": \"" << fExpandedCode << "\","; }
                tab(fTab, JSON); JSON << "\"inputs\": " << fInputs << ",";
                tab(fTab, JSON); JSON << "\"outputs\": " << fOutputs << ",";
                if (fSRIndex != -1) { tab(fTab, JSON); JSON << "\"sr_index\": " << fSRIndex << ","; }
                tab(fTab, fMeta); fMeta << "],";
              
                // Add last UI section
                fAllUI.push_back(fUI.str());
                // Finalize UI generation
                fUI.str("");
                // Add N-1 sections
                for (size_t i = 0; i < fAllUI.size()-1; i++) {
                    fUI << fAllUI[i] << fFull2Short[fFullPaths[i]] << "\",";
                }
                // And the last one
                fUI << fAllUI[fAllUI.size()-1];
                // Terminates the UI section
                tab(fTab, fUI); fUI << "]";
            
                fTab -= 1;
                if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                    JSON << fMeta.str() << fUI.str();
                } else {
                    JSON << fUI.str();
                }
                
                tab(fTab, JSON); JSON << "}";
                
                // Keep result in fJSON
                fJSON = JSON.str();
            }
            return (flat) ? flatten(fJSON) : fJSON;
        }
    
};

// Externally available class using FAUSTFLOAT

struct FAUST_API JSONUI : public JSONUIReal<FAUSTFLOAT>, public UI {
    
    JSONUI(const std::string& name,
           const std::string& filename,
           int inputs,
           int outputs,
           int sr_index,
           const std::string& sha_key,
           const std::string& dsp_code,
           const std::string& version,
           const std::string& compile_options,
           const std::vector<std::string>& library_list,
           const std::vector<std::string>& include_pathnames,
           int size,
           const PathTableType& path_table,
           MemoryLayoutType memory_layout):
    JSONUIReal<FAUSTFLOAT>(name, filename,
                          inputs, outputs,
                          sr_index,
                          sha_key, dsp_code,
                          version, compile_options,
                          library_list, include_pathnames,
                          size, path_table, memory_layout)
    {}
    
    JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
    JSONUIReal<FAUSTFLOAT>(name, filename, inputs, outputs)
    {}
    
    JSONUI(int inputs, int outputs):JSONUIReal<FAUSTFLOAT>(inputs, outputs)
    {}
    
    JSONUI():JSONUIReal<FAUSTFLOAT>()
    {}

    virtual void openTabBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openTabBox(label);
    }
    virtual void openHorizontalBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openHorizontalBox(label);
    }
    virtual void openVerticalBox(const char* label)
    {
        JSONUIReal<FAUSTFLOAT>::openVerticalBox(label);
    }
    virtual void closeBox()
    {
        JSONUIReal<FAUSTFLOAT>::closeBox();
    }
    
    // -- active widgets
    
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    {
        JSONUIReal<FAUSTFLOAT>::addButton(label, zone);
    }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        JSONUIReal<FAUSTFLOAT>::addCheckButton(label, zone);
    }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addVerticalSlider(label, zone, init, min, max, step);
    }
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addHorizontalSlider(label, zone, init, min, max, step);
    }
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        JSONUIReal<FAUSTFLOAT>::addNumEntry(label, zone, init, min, max, step);
    }
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        JSONUIReal<FAUSTFLOAT>::addHorizontalBargraph(label, zone, min, max);
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        JSONUIReal<FAUSTFLOAT>::addVerticalBargraph(label, zone, min, max);
    }
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone)
    {
        JSONUIReal<FAUSTFLOAT>::addSoundfile(label, filename, sf_zone);
    }
    
    // -- metadata declarations
    
    virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
    {
        JSONUIReal<FAUSTFLOAT>::declare(zone, key, val);
    }

    virtual void declare(const char* key, const char* val)
    {
        JSONUIReal<FAUSTFLOAT>::declare(key, val);
    }

    virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/**************************  END  JSONUI.h **************************/

namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;

/**
 * an alias target includes a map to rescale input values to output values
 * and a target osc address. The input values can be given in reversed order
 * to reverse the control
 */
struct aliastarget
{
	double      fMinIn;
	double      fMaxIn;
	double      fMinOut;
	double      fMaxOut;
	std::string fTarget;	// the real osc address

	aliastarget(const char* address, double imin, double imax, double omin, double omax)
		: fMinIn(imin), fMaxIn(imax), fMinOut(omin), fMaxOut(omax), fTarget(address) {}

	aliastarget(const aliastarget& t)
		: fMinIn(t.fMinIn), fMaxIn(t.fMaxIn), fMinOut(t.fMinOut), fMaxOut(t.fMaxOut), fTarget(t.fTarget) {}

	double scale(double x) const 
    {
        if (fMinIn < fMaxIn) {
            // increasing control
            double z = (x < fMinIn) ? fMinIn : (x > fMaxIn) ? fMaxIn : x;
            return fMinOut + (z-fMinIn)*(fMaxOut-fMinOut)/(fMaxIn-fMinIn);
            
        } else if (fMinIn > fMaxIn) {
            // reversed control
            double z = (x < fMaxIn) ? fMaxIn : (x > fMinIn) ? fMinIn : x;
            return fMinOut + (fMinIn-z)*(fMaxOut-fMinOut)/(fMinIn-fMaxIn);
            
        } else {
            // no control !
            return (fMinOut+fMaxOut)/2.0f;
        }
    }
    
    double invscale(double x) const
    {
        if (fMinOut < fMaxOut) {
            // increasing control
            double z = (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x;
            return fMinIn + (z-fMinOut)*(fMaxIn-fMinIn)/(fMaxOut-fMinOut);
            
        } else if (fMinOut > fMaxOut) {
            // reversed control
            double z = (x < fMaxOut) ? fMaxOut : (x > fMinOut) ? fMinOut : x;
            return fMinIn + (fMinOut-z)*(fMaxIn-fMinIn)/(fMinOut-fMaxOut);
            
        } else {
            // no control !
            return (fMinIn+fMaxIn)/2.0f;
        }
    }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust root node

	A Faust root node handles the \c 'hello' message and provides support
	for incoming osc signal data. 
*/
class RootNode : public MessageDriven
{

    private:
        int *fUPDIn, *fUDPOut, *fUDPErr;    // the osc port numbers (required by the hello method)
        OSCIO* fIO;                         // an OSC IO controler
        JSONUI* fJSON;

        typedef std::map<std::string, std::vector<aliastarget> > TAliasMap;
        TAliasMap fAliases;

        template <typename T>
        void processAliasAux(const std::string& address, T val);
        void processAlias(const std::string& address, float val);
        void processAlias(const std::string& address, double val);
    
        void eraseAliases(const std::string& target);
        void eraseAlias(const std::string& target, const std::string& alias);
        bool aliasError(const Message* msg);

    protected:
        RootNode(const char *name, JSONUI* json, OSCIO* io = NULL) : MessageDriven(name, ""), fUPDIn(0), fUDPOut(0), fUDPErr(0), fIO(io), fJSON(json) {}
        virtual ~RootNode() {}

    public:
        static SRootNode create(const char* name, JSONUI* json, OSCIO* io = NULL) { return new RootNode(name, json, io); }

        virtual void processMessage(const Message* msg);
        virtual bool accept(const Message* msg);
        virtual void get(unsigned long ipdest) const;
        virtual void get(unsigned long ipdest, const std::string& what) const;

        template <typename T>
        bool aliasMsgAux(const Message* msg, T omin, T omax);
        bool aliasMsg(const Message* msg, double omin, double omax);
        bool aliasMsg(const Message* msg, float omin, float omax);
    
        template <typename T>
        void addAliasAux(const char* alias, const char* address, T imin, T imax, T omin, T omax);
        void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
        void addAlias(const char* alias, const char* address, double imin, double imax, double omin, double omax);
    
        bool acceptSignal(const Message* msg);      ///< handler for signal data
        void hello(unsigned long ipdest) const;     ///< handler for the 'hello' message
        void setPorts(int* in, int* out, int* err);

        std::vector<std::pair<std::string, double> > getAliases(const std::string& address, double value);
};

} // end namespoace

#endif

namespace oscfaust
{

/**
 * map (rescale) input values to output values
 */
template <typename C> struct mapping
{
	const C fMinOut;
	const C fMaxOut;
	mapping(C omin, C omax) : fMinOut(omin), fMaxOut(omax) {}
	C clip (C x) { return (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x; }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust node is a terminal node and represents a faust parameter controler
*/
template <typename C> class FaustNode : public MessageDriven, public uiTypedItemReal<C>
{
	mapping<C>	fMapping;
    RootNode*   fRoot;
    bool        fInput;  // true for input nodes (slider, button...)
	
	//---------------------------------------------------------------------
	// Warning !!!
	// The cast (C*)fZone is necessary because the real size allocated is
	// only known at execution time. When the library is compiled, fZone is
	// uniquely defined by FAUSTFLOAT.
	//---------------------------------------------------------------------
	bool store(C val) { *(C*)this->fZone = fMapping.clip(val); return true; }
	void sendOSC() const;

	protected:
		FaustNode(RootNode* root, const char *name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input) 
			: MessageDriven(name, prefix), uiTypedItemReal<C>(ui, zone), fMapping(min, max), fRoot(root), fInput(input)
			{
                if (initZone) {
                    *zone = init; 
                }
            }
			
		virtual ~FaustNode() {}

	public:
		typedef SMARTP<FaustNode<C> > SFaustNode;
		static SFaustNode create(RootNode* root, const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input)	
        { 
            SFaustNode node = new FaustNode(root, name, zone, init, min, max, prefix, ui, initZone, input); 
            /*
                Since FaustNode is a subclass of uiItem, the pointer will also be kept in the GUI class, and it's desallocation will be done there.
                So we don't want to have smartpointer logic desallocate it and we increment the refcount.
            */
            node->addReference();
            return node; 
        }
    
		bool accept(const Message* msg);
		void get(unsigned long ipdest) const;		///< handler for the 'get' message
		virtual void reflectZone() { sendOSC(); this->fCache = *this->fZone; }
};

} // end namespace

#endif

class GUI;
namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a factory to build a OSC UI hierarchy
	
	Actually, makes use of a stack to build the UI hierarchy.
	It includes a pointer to a OSCIO controler, but just to give it to the root node.
*/
class FaustFactory
{
    std::stack<SMessageDriven>  fNodes;		///< maintains the current hierarchy level
    SRootNode  fRoot;   ///< keep track of the root node
    OSCIO*     fIO;     ///< hack to support audio IO via OSC, actually the field is given to the root node
    GUI*       fGUI;    ///< a GUI pointer to support updateAllGuis(), required for bi-directionnal OSC
    JSONUI*    fJSON;
    
    private:
        std::string addressFirst(const std::string& address) const;
        std::string addressTail(const std::string& address) const;
        
    public:
        FaustFactory(GUI* ui, JSONUI* json, OSCIO * io = NULL);
        virtual ~FaustFactory();
        
        template <typename C> void addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input);
        template <typename C> void addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label);
        
        void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
        void addAlias(const char* alias, const char* address, double imin, double imax, double omin, double omax);
        void opengroup(const char* label);
        void closegroup();
        
        SRootNode root() const; 
};

/**
 * Add a node to the OSC UI tree in the current group at the top of the stack 
 */
template <typename C> void FaustFactory::addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input) 
{
	SMessageDriven top;
	if (fNodes.size()) top = fNodes.top();
	if (top) {
		std::string prefix = top->getOSCAddress();
		top->add(FaustNode<C>::create(root(), label, zone, init, min, max, prefix.c_str(), fGUI, initZone, input));
	}
}

/**
 * Add an alias (actually stored and handled at root node level
 */
template <typename C> void FaustFactory::addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label)
{
	std::istringstream 	ss(fullpath);
	std::string 		realpath; 
 
	ss >> realpath >> imin >> imax;
	SMessageDriven top = fNodes.top();
	if (top) {
		std::string target = top->getOSCAddress() + "/" + label;
		addAlias(realpath.c_str(), target.c_str(), C(imin), C(imax), C(min), C(max));
	}
}

} // end namespoace

#endif

class GUI;

typedef void (*ErrorCallback)(void*);  

namespace oscfaust
{

class OSCIO;
class OSCSetup;
class OSCRegexp;
    
//--------------------------------------------------------------------------
/*!
	\brief the main Faust OSC Lib API
	
	The OSCControler is essentially a glue between the memory representation (in charge of the FaustFactory),
	and the network services (in charge of OSCSetup).
*/
class OSCControler
{
	int fUDPPort,   fUDPOut, fUPDErr;	// the udp ports numbers
	std::string     fDestAddress;		// the osc messages destination address, used at initialization only
										// to collect the address from the command line
	std::string     fBindAddress;		// when non empty, the address used to bind the socket for listening
	OSCSetup*		fOsc;				// the network manager (handles the udp sockets)
	OSCIO*			fIO;				// hack for OSC IO support (actually only relayed to the factory)
	FaustFactory*	fFactory;			// a factory to build the memory representation

    bool            fInit;
    
	public:
		/*
			base udp port is chosen in an unassigned range from IANA PORT NUMBERS (last updated 2011-01-24)
			see at http://www.iana.org/assignments/port-numbers
			5507-5552  Unassigned
		*/
		enum { kUDPBasePort = 5510 };
            
        OSCControler(int argc, char* argv[], GUI* ui, JSONUI* json, OSCIO* io = NULL, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true);

        virtual ~OSCControler();
	
		//--------------------------------------------------------------------------
		// addnode, opengroup and closegroup are simply relayed to the factory
		//--------------------------------------------------------------------------
		// Add a node in the current group (top of the group stack)
		template <typename T> void addnode(const char* label, T* zone, T init, T min, T max, bool input = true)
							{ fFactory->addnode(label, zone, init, min, max, fInit, input); }
		
		//--------------------------------------------------------------------------
		// This method is used for alias messages. The arguments imin and imax allow
		// to map incomming values from the alias input range to the actual range 
		template <typename T> void addAlias(const std::string& fullpath, T* zone, T imin, T imax, T init, T min, T max, const char* label)
							{ fFactory->addAlias(fullpath, zone, imin, imax, init, min, max, label); }

		void opengroup(const char* label)		{ fFactory->opengroup(label); }
		void closegroup()						{ fFactory->closegroup(); }
	   
		//--------------------------------------------------------------------------
		void run();				// starts the network services
		void endBundle();		// when bundle mode is on, close and send the current bundle (if any)
		void stop();			// stop the network services
		std::string getInfos() const; // gives information about the current environment (version, port numbers,...)

		int	getUDPPort() const			{ return fUDPPort; }
		int	getUDPOut()	const			{ return fUDPOut; }
		int	getUDPErr()	const			{ return fUPDErr; }
		const char*	getDestAddress() const { return fDestAddress.c_str(); }
		const char*	getRootName() const;	// probably useless, introduced for UI extension experiments
    
        void setUDPPort(int port) { fUDPPort = port; }
        void setUDPOut(int port) { fUDPOut = port; }
        void setUDPErr(int port) { fUPDErr = port; }
        void setDestAddress(const char* address) { fDestAddress = address; }

        // By default, an osc interface emits all parameters. You can filter specific params dynamically.
        static std::vector<OSCRegexp*>     fFilteredPaths; // filtered paths will not be emitted
        static void addFilteredPath(std::string path);
        static bool isPathFiltered(std::string path);
        static void resetFilteredPaths();
    
		static float version();				// the Faust OSC library version number
		static const char* versionstr();	// the Faust OSC library version number as a string
		static int gXmit;                   // a static variable to control the transmission of values
                                            // i.e. the use of the interface as a controler
		static int gBundle;                 // a static variable to control the osc bundle mode
};

#define kNoXmit     0
#define kAll        1
#define kAlias      2

}

#endif

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

/******************************************************************************
 *******************************************************************************
 
 OSC (Open Sound Control) USER INTERFACE
 
 *******************************************************************************
 *******************************************************************************/
/*
 
 Note about the OSC addresses and the Faust UI names:
 ----------------------------------------------------
 There are potential conflicts between the Faust UI objects naming scheme and
 the OSC address space. An OSC symbolic names is an ASCII string consisting of
 printable characters other than the following:
	space
 #	number sign
 *	asterisk
 ,	comma
 /	forward
 ?	question mark
 [	open bracket
 ]	close bracket
 {	open curly brace
 }	close curly brace
 
 a simple solution to address the problem consists in replacing
 space or tabulation with '_' (underscore)
 all the other osc excluded characters with '-' (hyphen)
 
 This solution is implemented in the proposed OSC UI;
 */

class OSCUI : public GUI
{
    
    private:
        
        oscfaust::OSCControler*	fCtrl;
        std::vector<const char*> fAlias;
        JSONUI fJSON;
        
        const char* tr(const char* label) const
        {
            static char buffer[1024];
            char* ptr = buffer; int n = 1;
            while (*label && (n++ < 1024)) {
                switch (*label) {
                    case ' ': case '	':
                        *ptr++ = '_';
                        break;
                    case '#': case '*': case ',': case '/': case '?':
                    case '[': case ']': case '{': case '}': case '(': case ')':
                        *ptr++ = '_';
                        break;
                    default:
                        *ptr++ = *label;
                }
                label++;
            }
            *ptr = 0;
            return buffer;
        }
        
        // add all accumulated alias
        void addalias(FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, const char* label)
        {
            for (unsigned int i = 0; i < fAlias.size(); i++) {
                fCtrl->addAlias(fAlias[i], zone, FAUSTFLOAT(0), FAUSTFLOAT(1), init, min, max, label);
            }
            fAlias.clear();
        }
        
    public:
        
        OSCUI(const char* /*applicationname*/, int argc, char* argv[],
              oscfaust::OSCIO* io = NULL,
              ErrorCallback errCallback = NULL,
              void* arg = NULL,
              bool init = true) : GUI()
        {
            fCtrl = new oscfaust::OSCControler(argc, argv, this, &fJSON, io, errCallback, arg, init);
            // fCtrl->opengroup(applicationname);
        }
        
        virtual ~OSCUI() { delete fCtrl; }
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label)          { fCtrl->opengroup(tr(label)); fJSON.openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fCtrl->opengroup(tr(label)); fJSON.openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fCtrl->opengroup(tr(label)); fJSON.openVerticalBox(label); }
        virtual void closeBox()                             { fCtrl->closegroup(); fJSON.closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            const char* l = tr(label);
            addalias(zone, 0, 0, 1, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1));
            fJSON.addButton(label, zone);
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            const char* l = tr(label);
            addalias(zone, 0, 0, 1, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1));
            fJSON.addCheckButton(label, zone);
        }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addVerticalSlider(label, zone, init, min, max, step);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addHorizontalSlider(label, zone, init, min, max, step);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addNumEntry(label, zone, init, min, max, step);
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            const char* l = tr(label);
            addalias(zone, 0, min, max, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
            fJSON.addHorizontalBargraph(label, zone, min, max);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            const char* l = tr(label);
            addalias(zone, 0, min, max, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
            fJSON.addVerticalBargraph(label, zone, min, max);
        }
            
        // -- metadata declarations
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* alias)
        {
            if (strcasecmp(key, "OSC") == 0) fAlias.push_back(alias);
            fJSON.declare(zone, key, alias);
        }
        
        bool run()
        {
            fCtrl->run();
            return true;
        }
        
        void stop()			{ fCtrl->stop(); }
        void endBundle() 	{ fCtrl->endBundle(); }
        
        std::string getInfos()          { return fCtrl->getInfos(); }
        
        const char* getRootName()		{ return fCtrl->getRootName(); }
        int getUDPPort()                { return fCtrl->getUDPPort(); }
        int getUDPOut()                 { return fCtrl->getUDPOut(); }
        int getUDPErr()                 { return fCtrl->getUDPErr(); }
        const char* getDestAddress()    { return fCtrl->getDestAddress(); }
        
        void setUDPPort(int port)       { fCtrl->setUDPPort(port); }
        void setUDPOut(int port)        { fCtrl->setUDPOut(port); }
        void setUDPErr(int port)        { fCtrl->setUDPErr(port); }
        void setDestAddress(const char* address)    { return fCtrl->setDestAddress(address); }
    
};

#endif // __OSCUI__
/**************************  END  OSCUI.h **************************/

#ifdef POLY2
#include "effect.h"
#endif

#if SOUNDFILE
/************************** BEGIN SoundUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <memory>


#if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
#include <CoreFoundation/CFBundle.h>
#endif

// Always included otherwise -i mode later on will not always include it (with the conditional includes)
/************************** BEGIN Soundfile.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __Soundfile__
#define __Soundfile__

#include <string.h>
#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define MAX_CHAN 64
#define MAX_SOUNDFILE_PARTS 256

#ifdef _MSC_VER
#define PRE_PACKED_STRUCTURE __pragma(pack(push, 1))
#define POST_PACKED_STRUCTURE \
    ;                         \
    __pragma(pack(pop))
#else
#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))
#endif

/*
 The soundfile structure to be used by the DSP code. Soundfile has a MAX_SOUNDFILE_PARTS parts 
 (even a single soundfile or an empty soundfile). 
 The fLength, fOffset and fSR fields are filled accordingly by repeating the actual parts if needed.
 The fBuffers contains MAX_CHAN non-interleaved arrays of samples.
 
 It has to be 'packed' to that the LLVM backend can correctly access it.

 Index computation:
    - p is the current part number [0..MAX_SOUNDFILE_PARTS-1] (must be proved by the type system)
    - i is the current position in the part. It will be constrained between [0..length]
    - idx(p,i) = fOffset[p] + max(0, min(i, fLength[p]));
*/

PRE_PACKED_STRUCTURE
struct Soundfile {
    void* fBuffers; // will correspond to a double** or float** pointer chosen at runtime
    int* fLength;   // length of each part (so fLength[P] contains the length in frames of part P)
    int* fSR;       // sample rate of each part (so fSR[P] contains the SR of part P)
    int* fOffset;   // offset of each part in the global buffer (so fOffset[P] contains the offset in frames of part P)
    int fChannels;  // max number of channels of all concatenated files
    int fParts;     // the total number of loaded parts
    bool fIsDouble; // keep the sample format (float or double)

    Soundfile(int cur_chan, int length, int max_chan, int total_parts, bool is_double)
    {
        fLength   = new int[MAX_SOUNDFILE_PARTS];
        fSR       = new int[MAX_SOUNDFILE_PARTS];
        fOffset   = new int[MAX_SOUNDFILE_PARTS];
        fIsDouble = is_double;
        fChannels = cur_chan;
        fParts    = total_parts;
        if (fIsDouble) {
            fBuffers = allocBufferReal<double>(cur_chan, length, max_chan);
        } else {
            fBuffers = allocBufferReal<float>(cur_chan, length, max_chan);
        }
    }
    
    template <typename REAL>
    void* allocBufferReal(int cur_chan, int length, int max_chan)
    {
        REAL** buffers = new REAL*[max_chan];
        for (int chan = 0; chan < cur_chan; chan++) {
            buffers[chan] = new REAL[length];
            memset(buffers[chan], 0, sizeof(REAL) * length);
        }
        return buffers;
    }
    
    void copyToOut(int size, int channels, int max_channels, int offset, void* buffer)
    {
        if (fIsDouble) {
            copyToOutReal<double>(size, channels, max_channels, offset, buffer);
       } else {
            copyToOutReal<float>(size, channels, max_channels, offset, buffer);
        }
    }
    
    void shareBuffers(int cur_chan, int max_chan)
    {
        // Share the same buffers for all other channels so that we have max_chan channels available
        if (fIsDouble) {
            for (int chan = cur_chan; chan < max_chan; chan++) {
                static_cast<double**>(fBuffers)[chan] = static_cast<double**>(fBuffers)[chan % cur_chan];
            }
        } else {
            for (int chan = cur_chan; chan < max_chan; chan++) {
                static_cast<float**>(fBuffers)[chan] = static_cast<float**>(fBuffers)[chan % cur_chan];
            }
        }
    }
    
    template <typename REAL>
    void copyToOutReal(int size, int channels, int max_channels, int offset, void* buffer)
    {
        for (int sample = 0; sample < size; sample++) {
            for (int chan = 0; chan < channels; chan++) {
                static_cast<REAL**>(fBuffers)[chan][offset + sample] = static_cast<REAL*>(buffer)[sample * max_channels + chan];
            }
        }
    }
    
    template <typename REAL>
    void getBuffersOffsetReal(void* buffers, int offset)
    {
        for (int chan = 0; chan < fChannels; chan++) {
            static_cast<REAL**>(buffers)[chan] = &(static_cast<REAL**>(fBuffers))[chan][offset];
        }
    }
    
    void emptyFile(int part, int& offset)
    {
        fLength[part] = BUFFER_SIZE;
        fSR[part] = SAMPLE_RATE;
        fOffset[part] = offset;
        // Update offset
        offset += fLength[part];
    }
 
    ~Soundfile()
    {
        // Free the real channels only
        if (fIsDouble) {
            for (int chan = 0; chan < fChannels; chan++) {
                delete[] static_cast<double**>(fBuffers)[chan];
            }
            delete[] static_cast<double**>(fBuffers);
        } else {
            for (int chan = 0; chan < fChannels; chan++) {
                delete[] static_cast<float**>(fBuffers)[chan];
            }
            delete[] static_cast<float**>(fBuffers);
        }
        delete[] fLength;
        delete[] fSR;
        delete[] fOffset;
    }

} POST_PACKED_STRUCTURE;

/*
 The generic soundfile reader.
 */

class SoundfileReader {
    
   protected:
    
    int fDriverSR;
   
    // Check if a soundfile exists and return its real path_name
    std::string checkFile(const std::vector<std::string>& sound_directories, const std::string& file_name)
    {
        if (checkFile(file_name)) {
            return file_name;
        } else {
            for (size_t i = 0; i < sound_directories.size(); i++) {
                std::string path_name = sound_directories[i] + "/" + file_name;
                if (checkFile(path_name)) { return path_name; }
            }
            return "";
        }
    }
    
    bool isResampling(int sample_rate) { return (fDriverSR > 0 && fDriverSR != sample_rate); }
 
    // To be implemented by subclasses

    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) = 0;
    
    /**
     * Check the availability of a sound resource.
     *
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     *
     * @return true if the sound resource is available, false otherwise.
     */

    virtual bool checkFile(unsigned char* buffer, size_t size) { return true; }

    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) = 0;
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length) {}

    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param soundfile - the soundfile to be filled
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) = 0;
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param soundfile - the soundfile to be filled
     * @param buffer - the sound buffer
     * @param size - the sound buffer length
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, unsigned char* buffer, size_t size, int part, int& offset, int max_chan) {}

  public:
    
    SoundfileReader() {}
    virtual ~SoundfileReader() {}
    
    void setSampleRate(int sample_rate) { fDriverSR = sample_rate; }
   
    Soundfile* createSoundfile(const std::vector<std::string>& path_name_list, int max_chan, bool is_double)
    {
        try {
            int cur_chan = 1; // At least one channel
            int total_length = 0;
            
            // Compute total length and channels max of all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                int chan, length;
                if (path_name_list[i] == "__empty_sound__") {
                    length = BUFFER_SIZE;
                    chan = 1;
                } else {
                    getParamsFile(path_name_list[i], chan, length);
                }
                cur_chan = std::max<int>(cur_chan, chan);
                total_length += length;
            }
           
            // Complete with empty parts
            total_length += (MAX_SOUNDFILE_PARTS - path_name_list.size()) * BUFFER_SIZE;
            
            // Create the soundfile
            Soundfile* soundfile = new Soundfile(cur_chan, total_length, max_chan, path_name_list.size(), is_double);
            
            // Init offset
            int offset = 0;
            
            // Read all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                if (path_name_list[i] == "__empty_sound__") {
                    soundfile->emptyFile(i, offset);
                } else {
                    readFile(soundfile, path_name_list[i], i, offset, max_chan);
                }
            }
            
            // Complete with empty parts
            for (int i = int(path_name_list.size()); i < MAX_SOUNDFILE_PARTS; i++) {
                soundfile->emptyFile(i, offset);
            }
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            soundfile->shareBuffers(cur_chan, max_chan);
            return soundfile;
            
        } catch (...) {
            return nullptr;
        }
    }

    // Check if all soundfiles exist and return their real path_name
    std::vector<std::string> checkFiles(const std::vector<std::string>& sound_directories,
                                        const std::vector<std::string>& file_name_list)
    {
        std::vector<std::string> path_name_list;
        for (size_t i = 0; i < file_name_list.size(); i++) {
            std::string path_name = checkFile(sound_directories, file_name_list[i]);
            // If 'path_name' is not found, it is replaced by an empty sound (= silence)
            path_name_list.push_back((path_name == "") ? "__empty_sound__" : path_name);
        }
        return path_name_list;
    }

};

#endif
/**************************  END  Soundfile.h **************************/

#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
/************************** BEGIN JuceReader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JuceReader__
#define __JuceReader__

#include <assert.h>

#include "../JuceLibraryCode/JuceHeader.h"


struct JuceReader : public SoundfileReader {
    
    juce::AudioFormatManager fFormatManager;
    
    JuceReader() { fFormatManager.registerBasicFormats(); }
    virtual ~JuceReader()
    {}
    
    bool checkFile(const std::string& path_name) override
    {
        juce::File file(path_name);
        if (file.existsAsFile()) {
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "'" << std::endl;
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length) override
    {
        std::unique_ptr<juce::AudioFormatReader> formatReader (fFormatManager.createReaderFor (juce::File (path_name)));
        channels = int(formatReader->numChannels);
        length = int(formatReader->lengthInSamples);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) override
    {
        std::unique_ptr<juce::AudioFormatReader> formatReader (fFormatManager.createReaderFor (juce::File (path_name)));
        
        soundfile->fLength[part] = int(formatReader->lengthInSamples);
        soundfile->fSR[part] = int(formatReader->sampleRate);
        soundfile->fOffset[part] = offset;
        
        void* buffers;
        if (soundfile->fIsDouble) {
            buffers = alloca(soundfile->fChannels * sizeof(double*));
            soundfile->getBuffersOffsetReal<double>(buffers, offset);
        } else {
            buffers = alloca(soundfile->fChannels * sizeof(float*));
            soundfile->getBuffersOffsetReal<float>(buffers, offset);
        }
        
        if (formatReader->read(reinterpret_cast<int *const *>(buffers), int(formatReader->numChannels), 0, int(formatReader->lengthInSamples), false)) {
            
            // Possibly convert samples
            if (!formatReader->usesFloatingPointData) {
                for (int chan = 0; chan < int(formatReader->numChannels); ++chan) {
                    if (soundfile->fIsDouble) {
                        // TODO
                    } else {
                        float* buffer = &(static_cast<float**>(soundfile->fBuffers))[chan][soundfile->fOffset[part]];
                        juce::FloatVectorOperations::convertFixedToFloat(buffer, reinterpret_cast<const int*>(buffer),
                                                                         1.0f/0x7fffffff, int(formatReader->lengthInSamples));
                    }
                }
            }
            
        } else {
            std::cerr << "Error reading the file : " << path_name << std::endl;
        }
            
        // Update offset
        offset += soundfile->fLength[part];
    }
    
};

#endif
/**************************  END  JuceReader.h **************************/
static JuceReader gReader;
#elif defined(ESP32)
/************************** BEGIN Esp32Reader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef FAUST_ESP32READER_H
#define FAUST_ESP32READER_H

#include <stdio.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spi_flash.h"
#include "esp_vfs_fat.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"

/************************** BEGIN WaveReader.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __WaveReader__
#define __WaveReader__

#include <string.h>
#include <assert.h>
#include <stdio.h>


// WAVE file description
typedef struct {
    
    // The canonical WAVE format starts with the RIFF header
    
    /**
     Variable: chunk_id
     Contains the letters "RIFF" in ASCII form (0x52494646 big-endian form).
     **/
    int chunk_id;
    
    /**
     Variable: chunk_size
     36 + SubChunk2Size, or more precisely: 4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
     This is the size of the rest of the chunk following this number.
     This is the size of the entire file in bytes minus 8 bytes for the
     two fields not included in this count: ChunkID and ChunkSize.
     **/
    int chunk_size;
    
    /**
     Variable: format
     Contains the letters "WAVE" (0x57415645 big-endian form).
     **/
    int format;
    
    // The "WAVE" format consists of two subchunks: "fmt " and "data":
    // The "fmt " subchunk describes the sound data's format:
    
    /**
     Variable: subchunk_1_id
     Contains the letters "fmt " (0x666d7420 big-endian form).
     **/
    int subchunk_1_id;
    
    /**
     Variable: subchunk_1_size
     16 for PCM. This is the size of the rest of the Subchunk which follows this number.
     **/
    int subchunk_1_size;
    
    /**
     Variable: audio_format
     PCM = 1 (i.e. Linear quantization) Values other than 1 indicate some form of compression.
     **/
    short audio_format;
    
    /**
     Variable: num_channels
     Mono = 1, Stereo = 2, etc.
     **/
    short num_channels;
    
    /**
     Variable: sample_rate
     8000, 44100, etc.
     **/
    int sample_rate;
    
    /**
     Variable: byte_rate
     == SampleRate * NumChannels * BitsPerSample/8
     **/
    int byte_rate;
    
    /**
     Variable: block_align
     == NumChannels * BitsPerSample/8
     The number of bytes for one sample including all channels. I wonder what happens
     when this number isn't an integer?
     **/
    short block_align;
    
    /**
     Variable: bits_per_sample
     8 bits = 8, 16 bits = 16, etc.
     **/
    short bits_per_sample;
    
    /**
     Here should come some extra parameters which i will avoid.
     **/
    
    // The "data" subchunk contains the size of the data and the actual sound:
    
    /**
     Variable: subchunk_2_id
     Contains the letters "data" (0x64617461 big-endian form).
     **/
    int subchunk_2_id;
    
    /**
     Variable: subchunk_2_size
     == NumSamples * NumChannels * BitsPerSample/8
     This is the number of bytes in the data. You can also think of this as the size
     of the read of the subchunk following this number.
     **/
    int subchunk_2_size;
    
    /**
     Variable: data
     The actual sound data.
     **/
    char* data;
    
} wave_t;

// Base reader
struct Reader {
    
    wave_t* fWave;

    inline int is_big_endian()
    {
        int a = 1;
        return !((char*)&a)[0];
    }
    
    inline int convert_to_int(char* buffer, int len)
    {
        int a = 0;
        if (!is_big_endian()) {
            for(int i = 0; i < len; i++) {
                ((char*)&a)[i] = buffer[i];
            }
        } else {
            for(int i = 0; i < len; i++) {
                ((char*)&a)[3-i] = buffer[i];
            }
        }
        return a;
    }
    
    Reader()
    {
        fWave = (wave_t*)calloc(1, sizeof(wave_t));
    }

    virtual ~Reader()
    {
        free(fWave->data);
        free(fWave);
    }

    bool load_wave_header()
    {
        char buffer[4];
        
        read(buffer, 4);
        if (strncmp(buffer, "RIFF", 4) != 0) {
            fprintf(stderr, "This is not valid WAV file!\n");
            return false;
        }
        fWave->chunk_id = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->chunk_size = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->format = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->subchunk_1_id = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->subchunk_1_size = convert_to_int(buffer, 4);
        
        read(buffer, 2);
        fWave->audio_format = convert_to_int(buffer, 2);
        
        read(buffer, 2);
        fWave->num_channels = convert_to_int(buffer, 2);
        
        read(buffer, 4);
        fWave->sample_rate = convert_to_int(buffer, 4);
        
        read(buffer, 4);
        fWave->byte_rate = convert_to_int(buffer, 4);
        
        read(buffer, 2);
        fWave->block_align = convert_to_int(buffer, 2);
        
        read(buffer, 2);
        fWave->bits_per_sample = convert_to_int(buffer, 2);
        
        read(buffer, 4);
        if (strncmp(buffer, "data", 4) != 0) {
            read(buffer, 4);
            int _extra_size = convert_to_int(buffer, 4);
            char _extra_data[_extra_size];
            read(_extra_data, _extra_size);
            read(buffer, 4);
            fWave->subchunk_2_id = convert_to_int(buffer, 4);
        } else {
            fWave->subchunk_2_id = convert_to_int(buffer, 4);
        }
        
        read(buffer, 4);
        fWave->subchunk_2_size = convert_to_int(buffer, 4);
        return true;
    }
    
    void load_wave()
    {
        // Read sound data
        fWave->data = (char*)malloc(fWave->subchunk_2_size);
        read(fWave->data, fWave->subchunk_2_size);
    }

    virtual void read(char* buffer, unsigned int size) = 0;
   
};

struct FileReader : public Reader {
    
    FILE* fFile;
    
    FileReader(const std::string& file_path)
    {
        fFile = fopen(file_path.c_str(), "rb");
        if (!fFile) {
            fprintf(stderr, "FileReader : cannot open file!\n");
            throw -1;
        }
        if (!load_wave_header()) {
            fprintf(stderr, "FileReader : not a WAV file!\n");
            throw -1;
        }
    }
    
    virtual ~FileReader()
    {
        fclose(fFile);
    }
    
    void read(char* buffer, unsigned int size)
    {
        fread(buffer, 1, size, fFile);
    }
    
};

extern const uint8_t file_start[] asm("_binary_FILE_start");
extern const uint8_t file_end[]   asm("_binary_FILE_end");

struct MemoryReader : public Reader {
    
    int fPos;
    const uint8_t* fStart;
    const uint8_t* fEnd;
    
    MemoryReader(const uint8_t* start, const uint8_t* end):fPos(0)
    {
        fStart = start;
        fEnd = end;
        if (!load_wave_header()) {
            fprintf(stderr, "MemoryReader : not a WAV file!\n");
            throw -1;
        }
    }
    
    virtual ~MemoryReader()
    {}
    
    void read(char* buffer, unsigned int size)
    {
        memcpy(buffer, fStart + fPos, size);
        fPos += size;
    }
    
};

// Using a FileReader to implement SoundfileReader

struct WaveReader : public SoundfileReader {
    
    WaveReader() {}
    virtual ~WaveReader() {}
    
    bool checkFile(const std::string& path_name) override
    {
        try {
            FileReader reader(path_name);
            return true;
        } catch (...)  {
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length) override
    {
        FileReader reader(path_name);
        channels = reader.fWave->num_channels;
        length = (reader.fWave->subchunk_2_size * 8) / (reader.fWave->num_channels * reader.fWave->bits_per_sample);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) override
    {
        FileReader reader(path_name);
        reader.load_wave();
        
        soundfile->fLength[part] = (reader.fWave->subchunk_2_size * 8) / (reader.fWave->num_channels * reader.fWave->bits_per_sample);
        soundfile->fSR[part] = reader.fWave->sample_rate;
        soundfile->fOffset[part] = offset;
        
        // Audio frames have to be written for each chan
        if (reader.fWave->bits_per_sample == 16) {
            float factor = 1.f/32767.f;
            for (int sample = 0; sample < soundfile->fLength[part]; sample++) {
                short* frame = (short*)&reader.fWave->data[reader.fWave->block_align * sample];
                for (int chan = 0; chan < reader.fWave->num_channels; chan++) {
                    soundfile->fBuffers[chan][offset + sample] = frame[chan] * factor;
                }
            }
        } else if (reader.fWave->bits_per_sample == 32) {
            fprintf(stderr, "readFile : not implemented\n");
        }
        
        // Update offset
        offset += soundfile->fLength[part];
    }
};

#endif
/**************************  END  WaveReader.h **************************/

#define TAG "Esp32Reader"

#define SD_PIN_NUM_MISO GPIO_NUM_2
#define SD_PIN_NUM_MOSI GPIO_NUM_15
#define SD_PIN_NUM_CLK  GPIO_NUM_14
#define SD_PIN_NUM_CS   GPIO_NUM_13

struct Esp32Reader : public WaveReader {
    
    void sdcard_init()
    {
        ESP_LOGI(TAG, "Initializing SD card");
        ESP_LOGI(TAG, "Using SPI peripheral");
        
        sdmmc_host_t host = SDSPI_HOST_DEFAULT();
        sdspi_slot_config_t slot_config = SDSPI_SLOT_CONFIG_DEFAULT();
        slot_config.gpio_miso = SD_PIN_NUM_MISO;
        slot_config.gpio_mosi = SD_PIN_NUM_MOSI;
        slot_config.gpio_sck  = SD_PIN_NUM_CLK;
        slot_config.gpio_cs   = SD_PIN_NUM_CS;
        // This initializes the slot without card detect (CD) and write protect (WP) signals.
        // Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
        
        // Options for mounting the filesystem.
        // If format_if_mount_failed is set to true, SD card will be partitioned and
        // formatted in case when mounting fails.
        esp_vfs_fat_sdmmc_mount_config_t mount_config = {
            .format_if_mount_failed = false,
            .max_files = 5,
            .allocation_unit_size = 16 * 1024
        };
        
        // Use settings defined above to initialize SD card and mount FAT filesystem.
        // Note: esp_vfs_fat_sdmmc_mount is an all-in-one convenience function.
        // Please check its source code and implement error recovery when developing
        // production applications.
        sdmmc_card_t* card;
        esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);
        
        if (ret != ESP_OK) {
            if (ret == ESP_FAIL) {
                ESP_LOGE(TAG, "Failed to mount filesystem. "
                         "If you want the card to be formatted, set format_if_mount_failed = true.");
            } else {
                ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                         "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
            }
            return;
        }
        
        // Card has been initialized, print its properties
        sdmmc_card_print_info(stdout, card);
        ESP_LOGI(TAG, "SD card initialized");
    }
    
    Esp32Reader()
    {
        sdcard_init();
    }
   
    // Access methods inherited from WaveReader
};

#endif // FAUST_ESP32READER_H
/**************************  END  Esp32Reader.h **************************/
static Esp32Reader gReader;
#elif defined(DAISY)
static WaveReader gReader;
#elif defined(MEMORY_READER)
/************************** BEGIN MemoryReader.h ************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __MemoryReader__
#define __MemoryReader__


/*
 A 'MemoryReader' object can be used to prepare a set of sound resources in memory, to be used by SoundUI::addSoundfile.
 
 A Soundfile* object will have to be filled with a list of sound resources: the fLength, fOffset, fSampleRate and fBuffers fields 
 have to be completed with the appropriate values, and will be accessed in the DSP object while running.
 *
 */

// To adapt for a real case use

#define SOUND_CHAN      2
#define SOUND_LENGTH    4096
#define SOUND_SR        44100

struct MemoryReader : public SoundfileReader {
    
    MemoryReader()
    {}
    virtual ~MemoryReader()
    {}
    
    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) override { return true; }
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) override
    {
        channels = SOUND_CHAN;
        length = SOUND_LENGTH;
    }
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) override
    {
        soundfile->fLength[part] = SOUND_LENGTH;
        soundfile->fSR[part] = SOUND_SR;
        soundfile->fOffset[part] = offset;
        
        // Audio frames have to be written for each chan
        if (soundfile->fIsDouble) {
            for (int sample = 0; sample < SOUND_LENGTH; sample++) {
                for (int chan = 0; chan < SOUND_CHAN; chan++) {
                    static_cast<double**>(soundfile->fBuffers)[chan][offset + sample] = 0.f;
                }
            }
        } else {
            for (int sample = 0; sample < SOUND_LENGTH; sample++) {
                for (int chan = 0; chan < SOUND_CHAN; chan++) {
                    static_cast<float**>(soundfile->fBuffers)[chan][offset + sample] = 0.f;
                }
            }
        }
        
        // Update offset
        offset += SOUND_LENGTH;
    }
    
};

#endif
/**************************  END  MemoryReader.h **************************/
static MemoryReader gReader;
#else
/************************** BEGIN LibsndfileReader.h *********************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __LibsndfileReader__
#define __LibsndfileReader__

#ifdef SAMPLERATE
#include <samplerate.h>
#endif
#include <sndfile.h>
#include <string.h>
#include <assert.h>
#include <iostream>


struct VFLibsndfile {
    
    #define SIGNED_SIZEOF(x) ((int)sizeof(x))
    
    unsigned char* fBuffer;
    size_t fLength;
    size_t fOffset;
    SF_VIRTUAL_IO fVIO;
    
    VFLibsndfile(unsigned char* buffer, size_t length):fBuffer(buffer), fLength(length), fOffset(0)
    {
        fVIO.get_filelen = vfget_filelen;
        fVIO.seek = vfseek;
        fVIO.read = vfread;
        fVIO.write = vfwrite;
        fVIO.tell = vftell;
    }
    
    static sf_count_t vfget_filelen(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fLength;
    }
  
    static sf_count_t vfseek(sf_count_t offset, int whence, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        switch (whence) {
            case SEEK_SET:
                vf->fOffset = offset;
                break;
                
            case SEEK_CUR:
                vf->fOffset = vf->fOffset + offset;
                break;
                
            case SEEK_END:
                vf->fOffset = vf->fLength + offset;
                break;
                
            default:
                break;
        };
        
        return vf->fOffset;
    }
    
    static sf_count_t vfread(void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset + count > vf->fLength) {
            count = vf->fLength - vf->fOffset;
        }
        
        memcpy(ptr, vf->fBuffer + vf->fOffset, count);
        vf->fOffset += count;
        
        return count;
    }
    
    static sf_count_t vfwrite(const void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset >= SIGNED_SIZEOF(vf->fBuffer)) {
            return 0;
        }
        
        if (vf->fOffset + count > SIGNED_SIZEOF(vf->fBuffer)) {
            count = sizeof (vf->fBuffer) - vf->fOffset;
        }
        
        memcpy(vf->fBuffer + vf->fOffset, ptr, (size_t)count);
        vf->fOffset += count;
        
        if (vf->fOffset > vf->fLength) {
            vf->fLength = vf->fOffset;
        }
        
        return count;
    }
    
    static sf_count_t vftell(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fOffset;
    }
 
};

struct LibsndfileReader : public SoundfileReader {
	
    LibsndfileReader() {}
	
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, void* buffer, sf_count_t frames);
	
    // Check file
    bool checkFile(const std::string& path_name) override
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        return checkFileAux(snd_file, path_name);
    }
    
    bool checkFile(unsigned char* buffer, size_t length) override
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        return checkFileAux(snd_file, "virtual file");
    }
    
    bool checkFileAux(SNDFILE* snd_file, const std::string& path_name)
    {
        if (snd_file) {
            sf_close(snd_file);
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return false;
        }
    }

    // Open the file and returns its length and channels
    void getParamsFile(const std::string& path_name, int& channels, int& length) override
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length) override
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, size);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFileAux(SNDFILE* snd_file, const SF_INFO& snd_info, int& channels, int& length)
    {
        assert(snd_file);
        channels = int(snd_info.channels);
    #ifdef SAMPLERATE
        length = (isResampling(snd_info.samplerate)) ? ((double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate)) + BUFFER_SIZE) : int(snd_info.frames);
    #else
        length = int(snd_info.frames);
    #endif
        sf_close(snd_file);
    }
    
    // Read the file
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) override
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
    
    void readFile(Soundfile* soundfile, unsigned char* buffer, size_t length, int part, int& offset, int max_chan) override
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
	
    // Will be called to fill all parts from 0 to MAX_SOUNDFILE_PARTS-1
    void readFileAux(Soundfile* soundfile, SNDFILE* snd_file, const SF_INFO& snd_info, int part, int& offset, int max_chan)
    {
        assert(snd_file);
        int channels = std::min<int>(max_chan, snd_info.channels);
    #ifdef SAMPLERATE
        if (isResampling(snd_info.samplerate)) {
            soundfile->fLength[part] = int(double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate));
            soundfile->fSR[part] = fDriverSR;
        } else {
            soundfile->fLength[part] = int(snd_info.frames);
            soundfile->fSR[part] = snd_info.samplerate;
        }
    #else
        soundfile->fLength[part] = int(snd_info.frames);
        soundfile->fSR[part] = snd_info.samplerate;
    #endif
        soundfile->fOffset[part] = offset;
		
        // Read and fill snd_info.channels number of channels
        sf_count_t nbf;
        
        sample_read reader;
        void* buffer_in = nullptr;
        if (soundfile->fIsDouble) {
            buffer_in = static_cast<double*>(alloca(BUFFER_SIZE * sizeof(double) * snd_info.channels));
            reader = reinterpret_cast<sample_read>(sf_readf_double);
        } else {
            buffer_in = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
            reader = reinterpret_cast<sample_read>(sf_readf_float);
        }
        
    #ifdef SAMPLERATE
        // Resampling
        SRC_STATE* resampler = nullptr;
        float* src_buffer_out = nullptr;
        float* src_buffer_in = nullptr;
        void* buffer_out = nullptr;
        if  (isResampling(snd_info.samplerate)) {
            int error;
            resampler = src_new(SRC_SINC_FASTEST, channels, &error);
            if (error != 0) {
                std::cerr << "ERROR : src_new " << src_strerror(error) << std::endl;
                throw -1;
            }
            if (soundfile->fIsDouble) {
                // Additional buffers for SRC resampling
                src_buffer_in = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
                src_buffer_out = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
                buffer_out = static_cast<double*>(alloca(BUFFER_SIZE * sizeof(double) * snd_info.channels));
            } else {
                buffer_out = static_cast<float*>(alloca(BUFFER_SIZE * sizeof(float) * snd_info.channels));
            }
        }
    #endif
        
        do {
            nbf = reader(snd_file, buffer_in, BUFFER_SIZE);
        #ifdef SAMPLERATE
            // Resampling
            if  (isResampling(snd_info.samplerate)) {
                int in_offset = 0;
                SRC_DATA src_data;
                src_data.src_ratio = double(fDriverSR)/double(snd_info.samplerate);
                if (soundfile->fIsDouble) {
                    for (int frame = 0; frame < (BUFFER_SIZE * snd_info.channels); frame++) {
                        src_buffer_in[frame] = float(static_cast<float*>(buffer_in)[frame]);
                    }
                }
                do {
                    if (soundfile->fIsDouble) {
                        src_data.data_in = src_buffer_in;
                        src_data.data_out = src_buffer_out;
                    } else {
                        src_data.data_in = static_cast<const float*>(buffer_in);
                        src_data.data_out = static_cast<float*>(buffer_out);
                    }
                    src_data.input_frames = nbf - in_offset;
                    src_data.output_frames = BUFFER_SIZE;
                    src_data.end_of_input = (nbf < BUFFER_SIZE);
                    int res = src_process(resampler, &src_data);
                    if (res != 0) {
                        std::cerr << "ERROR : src_process " << src_strerror(res) << std::endl;
                        throw -1;
                    }
                    if (soundfile->fIsDouble) {
                        for (int frame = 0; frame < (BUFFER_SIZE * snd_info.channels); frame++) {
                            static_cast<double*>(buffer_out)[frame] = double(src_buffer_out[frame]);
                        }
                    }
                    soundfile->copyToOut(src_data.output_frames_gen, channels, snd_info.channels, offset, buffer_out);
                    in_offset += src_data.input_frames_used;
                    // Update offset
                    offset += src_data.output_frames_gen;
                } while (in_offset < nbf);
            } else {
                soundfile->copyToOut(nbf, channels, snd_info.channels, offset, buffer_in);
                // Update offset
                offset += nbf;
            }
        #else
            soundfile->copyToOut(nbf, channels, snd_info.channels, offset, buffer_in);
            // Update offset
            offset += nbf;
        #endif
        } while (nbf == BUFFER_SIZE);
		
        sf_close(snd_file);
    #ifdef SAMPLERATE
        if (resampler) src_delete(resampler);
    #endif
    }

};

#endif
/**************************  END  LibsndfileReader.h **************************/
static LibsndfileReader gReader;
#endif

// To be used by DSP code if no SoundUI is used
static std::vector<std::string> path_name_list;
static Soundfile* defaultsound = nullptr;

class SoundUI : public SoundUIInterface
{
		
    protected:
    
        // The soundfile directories
        std::vector<std::string> fSoundfileDir;
        // Map to share loaded soundfiles
        std::map<std::string, std::shared_ptr<Soundfile>> fSoundfileMap;
        // The soundfile reader
        std::shared_ptr<SoundfileReader> fSoundReader;
        bool fIsDouble;

     public:
    
        /**
         * Create a soundfile loader which will typically use a concrete SoundfileReader like LibsndfileReader or JuceReader to load soundfiles.
         *
         * @param sound_directory - the base directory to look for files, which paths will be relative to this one
         * @param sample_rate - the audio driver SR which may be different from the file SR, to possibly resample files
         * @param reader - an alternative soundfile reader
         * @param is_double - whether Faust code has been compiled in -double mode and soundfile buffers have to be in double
         *
         * @return the soundfile loader.
         */
        SoundUI(const std::string& sound_directory = "", int sample_rate = -1, SoundfileReader* reader = nullptr, bool is_double = false)
        {
            fSoundfileDir.push_back(sound_directory);
            fSoundReader = (reader)
                ? std::shared_ptr<SoundfileReader>(reader)
                // the static gReader should not be deleted, so use an empty destructor
                : std::shared_ptr<SoundfileReader>(std::shared_ptr<SoundfileReader>{}, &gReader);
            fSoundReader->setSampleRate(sample_rate);
            fIsDouble = is_double;
            if (!defaultsound) defaultsound = gReader.createSoundfile(path_name_list, MAX_CHAN, is_double);
        }
    
        /**
         * Create a soundfile loader which will typically use a concrete SoundfileReader like LibsndfileReader or JuceReader to load soundfiles.
         *
         * @param sound_directories - a vector of base directories to look for files, which paths will be relative to these ones
         * @param sample_rate - the audio driver SR which may be different from the file SR, to possibly resample files
         * @param reader - an alternative soundfile reader
         * @param is_double - whether Faust code has been compiled in -double mode and soundfile buffers have to be in double
         *
         * @return the soundfile loader.
         */
        SoundUI(const std::vector<std::string>& sound_directories, int sample_rate = -1, SoundfileReader* reader = nullptr, bool is_double = false)
        :fSoundfileDir(sound_directories)
        {
            fSoundReader = (reader)
                ? std::shared_ptr<SoundfileReader>(reader)
                // the static gReader should not be deleted, so use an empty destructor
                : std::shared_ptr<SoundfileReader>(std::shared_ptr<SoundfileReader>{}, &gReader);
            fSoundReader->setSampleRate(sample_rate);
            fIsDouble = is_double;
            if (!defaultsound) defaultsound = gReader.createSoundfile(path_name_list, MAX_CHAN, is_double);
        }
    
        virtual ~SoundUI()
        {}

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            const char* saved_url = url; // 'url' is consumed by parseMenuList2
            std::vector<std::string> file_name_list;
            
            bool menu = parseMenuList2(url, file_name_list, true);
            // If not a list, we have as single file
            if (!menu) { file_name_list.push_back(saved_url); }
            
            // Parse the possible list
            std::string saved_url_real = std::string(saved_url) + "_" + std::to_string(fIsDouble); // fIsDouble is used in the key
            if (fSoundfileMap.find(saved_url_real) == fSoundfileMap.end()) {
                // Check all files and get their complete path
                std::vector<std::string> path_name_list = fSoundReader->checkFiles(fSoundfileDir, file_name_list);
                // Read them and create the Soundfile
                Soundfile* sound_file = fSoundReader->createSoundfile(path_name_list, MAX_CHAN, fIsDouble);
                if (sound_file) {
                    fSoundfileMap[saved_url_real] = std::shared_ptr<Soundfile>(sound_file);
                } else {
                    // If failure, use 'defaultsound'
                    std::cerr << "addSoundfile : soundfile for " << saved_url << " cannot be created !" << std::endl;
                    *sf_zone = defaultsound;
                    return;
                }
            }
            
            // Get the soundfile pointer
            *sf_zone = fSoundfileMap[saved_url_real].get();
        }
    
        /**
         * An OS dependant function to get the path of the running executable or plugin.
         * This will typically be used when creating a SoundUI soundfile loader, like new SoundUI(SoundUI::getBinaryPath());
         *
         * @return the running executable or plugin path.
         */
        static std::string getBinaryPath()
        {
            std::string bundle_path_str;
        #if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
            CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
            if (!bundle_ref) { std::cerr << "getBinaryPath CFBundleCopyBundleURL error\n"; return ""; }
      
            UInt8 bundle_path[1024];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 1024)) {
                bundle_path_str = std::string((char*)bundle_path);
            } else {
                std::cerr << "getBinaryPath CFURLGetFileSystemRepresentation error\n";
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
    
        /**
         * An OS dependant function to get the path of the running executable or plugin.
         * This will typically be used when creating a SoundUI soundfile loader, like new SoundUI(SoundUI::getBinaryPathFrom());
         *
         * @param path - entry point to start getting the path of the running executable or plugin.
         *
         * @return the running executable or plugin path.
         */
        static std::string getBinaryPathFrom(const std::string& path)
        {
            std::string bundle_path_str;
        #if defined(__APPLE__) && !defined(__VCVRACK__) && !defined(JUCE_32BIT) && !defined(JUCE_64BIT)
            CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
            if (!bundle) { std::cerr << "getBinaryPathFrom CFBundleGetBundleWithIdentifier error '" << path << "'" << std::endl; return ""; }
         
            CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
            if (!bundle_ref) { std::cerr << "getBinaryPathFrom CFBundleCopyBundleURL error\n"; return ""; }
            
            UInt8 bundle_path[1024];
            if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 1024)) {
                bundle_path_str = std::string((char*)bundle_path);
            } else {
                std::cerr << "getBinaryPathFrom CFURLGetFileSystemRepresentation error\n";
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
};

#endif
/**************************  END  SoundUI.h **************************/
#endif

// For FAUST_CLASS_NAME to be defined
#define FAUST_UIMACROS

// but we will ignore most of them
#define FAUST_ADDBUTTON(l,f)
#define FAUST_ADDCHECKBOX(l,f)
#define FAUST_ADDVERTICALSLIDER(l,f,i,a,b,s)
#define FAUST_ADDHORIZONTALSLIDER(l,f,i,a,b,s)
#define FAUST_ADDNUMENTRY(l,f,i,a,b,s)
#define FAUST_ADDVERTICALBARGRAPH(l,f,a,b)
#define FAUST_ADDHORIZONTALBARGRAPH(l,f,a,b)
#define FAUST_ADDSOUNDFILE(s,f)

using namespace std;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS scaleIt
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

const static int iscaleItSIG0Wave0[12] = {0,4,7,11,12,16,19,23,24,28,31,35};
class scaleItSIG0 {
	
  public:
	
	int iscaleItSIG0Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG0() {
		return 0;
	}
	int getNumOutputsscaleItSIG0() {
		return 1;
	}
	
	void instanceInitscaleItSIG0(int sample_rate) {
		iscaleItSIG0Wave0_idx = 0;
	}
	
	void fillscaleItSIG0(int count, int* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = iscaleItSIG0Wave0[iscaleItSIG0Wave0_idx];
			iscaleItSIG0Wave0_idx = (1 + iscaleItSIG0Wave0_idx) % 12;
		}
	}

};

static scaleItSIG0* newscaleItSIG0() { return (scaleItSIG0*)new scaleItSIG0(); }
static void deletescaleItSIG0(scaleItSIG0* dsp) { delete dsp; }

const static int iscaleItSIG1Wave0[12] = {0,3,7,12,15,19,24,27,31,36,39,43};
class scaleItSIG1 {
	
  public:
	
	int iscaleItSIG1Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG1() {
		return 0;
	}
	int getNumOutputsscaleItSIG1() {
		return 1;
	}
	
	void instanceInitscaleItSIG1(int sample_rate) {
		iscaleItSIG1Wave0_idx = 0;
	}
	
	void fillscaleItSIG1(int count, int* table) {
		for (int i2 = 0; i2 < count; i2 = i2 + 1) {
			table[i2] = iscaleItSIG1Wave0[iscaleItSIG1Wave0_idx];
			iscaleItSIG1Wave0_idx = (1 + iscaleItSIG1Wave0_idx) % 12;
		}
	}

};

static scaleItSIG1* newscaleItSIG1() { return (scaleItSIG1*)new scaleItSIG1(); }
static void deletescaleItSIG1(scaleItSIG1* dsp) { delete dsp; }

const static int iscaleItSIG2Wave0[12] = {0,4,7,12,16,19,24,28,31,36,40,43};
class scaleItSIG2 {
	
  public:
	
	int iscaleItSIG2Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG2() {
		return 0;
	}
	int getNumOutputsscaleItSIG2() {
		return 1;
	}
	
	void instanceInitscaleItSIG2(int sample_rate) {
		iscaleItSIG2Wave0_idx = 0;
	}
	
	void fillscaleItSIG2(int count, int* table) {
		for (int i3 = 0; i3 < count; i3 = i3 + 1) {
			table[i3] = iscaleItSIG2Wave0[iscaleItSIG2Wave0_idx];
			iscaleItSIG2Wave0_idx = (1 + iscaleItSIG2Wave0_idx) % 12;
		}
	}

};

static scaleItSIG2* newscaleItSIG2() { return (scaleItSIG2*)new scaleItSIG2(); }
static void deletescaleItSIG2(scaleItSIG2* dsp) { delete dsp; }

const static int iscaleItSIG3Wave0[12] = {0,2,4,6,8,10,12,14,16,18,20,22};
class scaleItSIG3 {
	
  public:
	
	int iscaleItSIG3Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG3() {
		return 0;
	}
	int getNumOutputsscaleItSIG3() {
		return 1;
	}
	
	void instanceInitscaleItSIG3(int sample_rate) {
		iscaleItSIG3Wave0_idx = 0;
	}
	
	void fillscaleItSIG3(int count, int* table) {
		for (int i4 = 0; i4 < count; i4 = i4 + 1) {
			table[i4] = iscaleItSIG3Wave0[iscaleItSIG3Wave0_idx];
			iscaleItSIG3Wave0_idx = (1 + iscaleItSIG3Wave0_idx) % 12;
		}
	}

};

static scaleItSIG3* newscaleItSIG3() { return (scaleItSIG3*)new scaleItSIG3(); }
static void deletescaleItSIG3(scaleItSIG3* dsp) { delete dsp; }

const static int iscaleItSIG4Wave0[13] = {0,1,2,3,4,5,6,7,8,9,10,12,13};
class scaleItSIG4 {
	
  public:
	
	int iscaleItSIG4Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG4() {
		return 0;
	}
	int getNumOutputsscaleItSIG4() {
		return 1;
	}
	
	void instanceInitscaleItSIG4(int sample_rate) {
		iscaleItSIG4Wave0_idx = 0;
	}
	
	void fillscaleItSIG4(int count, int* table) {
		for (int i5 = 0; i5 < count; i5 = i5 + 1) {
			table[i5] = iscaleItSIG4Wave0[iscaleItSIG4Wave0_idx];
			iscaleItSIG4Wave0_idx = (1 + iscaleItSIG4Wave0_idx) % 13;
		}
	}

};

static scaleItSIG4* newscaleItSIG4() { return (scaleItSIG4*)new scaleItSIG4(); }
static void deletescaleItSIG4(scaleItSIG4* dsp) { delete dsp; }

const static int iscaleItSIG5Wave0[12] = {0,2,3,7,8,12,14,15,19,20,24,26};
class scaleItSIG5 {
	
  public:
	
	int iscaleItSIG5Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG5() {
		return 0;
	}
	int getNumOutputsscaleItSIG5() {
		return 1;
	}
	
	void instanceInitscaleItSIG5(int sample_rate) {
		iscaleItSIG5Wave0_idx = 0;
	}
	
	void fillscaleItSIG5(int count, int* table) {
		for (int i6 = 0; i6 < count; i6 = i6 + 1) {
			table[i6] = iscaleItSIG5Wave0[iscaleItSIG5Wave0_idx];
			iscaleItSIG5Wave0_idx = (1 + iscaleItSIG5Wave0_idx) % 12;
		}
	}

};

static scaleItSIG5* newscaleItSIG5() { return (scaleItSIG5*)new scaleItSIG5(); }
static void deletescaleItSIG5(scaleItSIG5* dsp) { delete dsp; }

const static int iscaleItSIG6Wave0[12] = {0,1,5,6,10,12,13,17,18,22,24,25};
class scaleItSIG6 {
	
  public:
	
	int iscaleItSIG6Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG6() {
		return 0;
	}
	int getNumOutputsscaleItSIG6() {
		return 1;
	}
	
	void instanceInitscaleItSIG6(int sample_rate) {
		iscaleItSIG6Wave0_idx = 0;
	}
	
	void fillscaleItSIG6(int count, int* table) {
		for (int i7 = 0; i7 < count; i7 = i7 + 1) {
			table[i7] = iscaleItSIG6Wave0[iscaleItSIG6Wave0_idx];
			iscaleItSIG6Wave0_idx = (1 + iscaleItSIG6Wave0_idx) % 12;
		}
	}

};

static scaleItSIG6* newscaleItSIG6() { return (scaleItSIG6*)new scaleItSIG6(); }
static void deletescaleItSIG6(scaleItSIG6* dsp) { delete dsp; }

const static int iscaleItSIG7Wave0[13] = {0,3,5,7,10,12,15,17,19,22,24,27,29};
class scaleItSIG7 {
	
  public:
	
	int iscaleItSIG7Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG7() {
		return 0;
	}
	int getNumOutputsscaleItSIG7() {
		return 1;
	}
	
	void instanceInitscaleItSIG7(int sample_rate) {
		iscaleItSIG7Wave0_idx = 0;
	}
	
	void fillscaleItSIG7(int count, int* table) {
		for (int i8 = 0; i8 < count; i8 = i8 + 1) {
			table[i8] = iscaleItSIG7Wave0[iscaleItSIG7Wave0_idx];
			iscaleItSIG7Wave0_idx = (1 + iscaleItSIG7Wave0_idx) % 13;
		}
	}

};

static scaleItSIG7* newscaleItSIG7() { return (scaleItSIG7*)new scaleItSIG7(); }
static void deletescaleItSIG7(scaleItSIG7* dsp) { delete dsp; }

const static int iscaleItSIG8Wave0[13] = {0,2,4,7,9,12,14,16,19,21,24,26,28};
class scaleItSIG8 {
	
  public:
	
	int iscaleItSIG8Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG8() {
		return 0;
	}
	int getNumOutputsscaleItSIG8() {
		return 1;
	}
	
	void instanceInitscaleItSIG8(int sample_rate) {
		iscaleItSIG8Wave0_idx = 0;
	}
	
	void fillscaleItSIG8(int count, int* table) {
		for (int i9 = 0; i9 < count; i9 = i9 + 1) {
			table[i9] = iscaleItSIG8Wave0[iscaleItSIG8Wave0_idx];
			iscaleItSIG8Wave0_idx = (1 + iscaleItSIG8Wave0_idx) % 13;
		}
	}

};

static scaleItSIG8* newscaleItSIG8() { return (scaleItSIG8*)new scaleItSIG8(); }
static void deletescaleItSIG8(scaleItSIG8* dsp) { delete dsp; }

const static int iscaleItSIG9Wave0[12] = {0,1,3,5,6,8,10,12,13,15,17,18};
class scaleItSIG9 {
	
  public:
	
	int iscaleItSIG9Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG9() {
		return 0;
	}
	int getNumOutputsscaleItSIG9() {
		return 1;
	}
	
	void instanceInitscaleItSIG9(int sample_rate) {
		iscaleItSIG9Wave0_idx = 0;
	}
	
	void fillscaleItSIG9(int count, int* table) {
		for (int i10 = 0; i10 < count; i10 = i10 + 1) {
			table[i10] = iscaleItSIG9Wave0[iscaleItSIG9Wave0_idx];
			iscaleItSIG9Wave0_idx = (1 + iscaleItSIG9Wave0_idx) % 12;
		}
	}

};

static scaleItSIG9* newscaleItSIG9() { return (scaleItSIG9*)new scaleItSIG9(); }
static void deletescaleItSIG9(scaleItSIG9* dsp) { delete dsp; }

const static int iscaleItSIG10Wave0[12] = {0,2,3,5,7,8,10,12,14,15,17,18};
class scaleItSIG10 {
	
  public:
	
	int iscaleItSIG10Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG10() {
		return 0;
	}
	int getNumOutputsscaleItSIG10() {
		return 1;
	}
	
	void instanceInitscaleItSIG10(int sample_rate) {
		iscaleItSIG10Wave0_idx = 0;
	}
	
	void fillscaleItSIG10(int count, int* table) {
		for (int i11 = 0; i11 < count; i11 = i11 + 1) {
			table[i11] = iscaleItSIG10Wave0[iscaleItSIG10Wave0_idx];
			iscaleItSIG10Wave0_idx = (1 + iscaleItSIG10Wave0_idx) % 12;
		}
	}

};

static scaleItSIG10* newscaleItSIG10() { return (scaleItSIG10*)new scaleItSIG10(); }
static void deletescaleItSIG10(scaleItSIG10* dsp) { delete dsp; }

const static int iscaleItSIG11Wave0[12] = {0,2,4,5,7,9,10,12,14,15,17,18};
class scaleItSIG11 {
	
  public:
	
	int iscaleItSIG11Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG11() {
		return 0;
	}
	int getNumOutputsscaleItSIG11() {
		return 1;
	}
	
	void instanceInitscaleItSIG11(int sample_rate) {
		iscaleItSIG11Wave0_idx = 0;
	}
	
	void fillscaleItSIG11(int count, int* table) {
		for (int i12 = 0; i12 < count; i12 = i12 + 1) {
			table[i12] = iscaleItSIG11Wave0[iscaleItSIG11Wave0_idx];
			iscaleItSIG11Wave0_idx = (1 + iscaleItSIG11Wave0_idx) % 12;
		}
	}

};

static scaleItSIG11* newscaleItSIG11() { return (scaleItSIG11*)new scaleItSIG11(); }
static void deletescaleItSIG11(scaleItSIG11* dsp) { delete dsp; }

const static int iscaleItSIG12Wave0[12] = {0,2,4,6,7,9,11,12,14,16,17,18};
class scaleItSIG12 {
	
  public:
	
	int iscaleItSIG12Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG12() {
		return 0;
	}
	int getNumOutputsscaleItSIG12() {
		return 1;
	}
	
	void instanceInitscaleItSIG12(int sample_rate) {
		iscaleItSIG12Wave0_idx = 0;
	}
	
	void fillscaleItSIG12(int count, int* table) {
		for (int i13 = 0; i13 < count; i13 = i13 + 1) {
			table[i13] = iscaleItSIG12Wave0[iscaleItSIG12Wave0_idx];
			iscaleItSIG12Wave0_idx = (1 + iscaleItSIG12Wave0_idx) % 12;
		}
	}

};

static scaleItSIG12* newscaleItSIG12() { return (scaleItSIG12*)new scaleItSIG12(); }
static void deletescaleItSIG12(scaleItSIG12* dsp) { delete dsp; }

const static int iscaleItSIG13Wave0[12] = {0,1,3,5,7,8,10,12,13,15,17,19};
class scaleItSIG13 {
	
  public:
	
	int iscaleItSIG13Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG13() {
		return 0;
	}
	int getNumOutputsscaleItSIG13() {
		return 1;
	}
	
	void instanceInitscaleItSIG13(int sample_rate) {
		iscaleItSIG13Wave0_idx = 0;
	}
	
	void fillscaleItSIG13(int count, int* table) {
		for (int i14 = 0; i14 < count; i14 = i14 + 1) {
			table[i14] = iscaleItSIG13Wave0[iscaleItSIG13Wave0_idx];
			iscaleItSIG13Wave0_idx = (1 + iscaleItSIG13Wave0_idx) % 12;
		}
	}

};

static scaleItSIG13* newscaleItSIG13() { return (scaleItSIG13*)new scaleItSIG13(); }
static void deletescaleItSIG13(scaleItSIG13* dsp) { delete dsp; }

const static int iscaleItSIG14Wave0[12] = {0,2,3,5,7,9,10,12,14,15,17,19};
class scaleItSIG14 {
	
  public:
	
	int iscaleItSIG14Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG14() {
		return 0;
	}
	int getNumOutputsscaleItSIG14() {
		return 1;
	}
	
	void instanceInitscaleItSIG14(int sample_rate) {
		iscaleItSIG14Wave0_idx = 0;
	}
	
	void fillscaleItSIG14(int count, int* table) {
		for (int i15 = 0; i15 < count; i15 = i15 + 1) {
			table[i15] = iscaleItSIG14Wave0[iscaleItSIG14Wave0_idx];
			iscaleItSIG14Wave0_idx = (1 + iscaleItSIG14Wave0_idx) % 12;
		}
	}

};

static scaleItSIG14* newscaleItSIG14() { return (scaleItSIG14*)new scaleItSIG14(); }
static void deletescaleItSIG14(scaleItSIG14* dsp) { delete dsp; }

const static int iscaleItSIG15Wave0[12] = {0,2,4,5,7,9,11,12,14,16,17,19};
class scaleItSIG15 {
	
  public:
	
	int iscaleItSIG15Wave0_idx;
	
  public:
	
	int getNumInputsscaleItSIG15() {
		return 0;
	}
	int getNumOutputsscaleItSIG15() {
		return 1;
	}
	
	void instanceInitscaleItSIG15(int sample_rate) {
		iscaleItSIG15Wave0_idx = 0;
	}
	
	void fillscaleItSIG15(int count, int* table) {
		for (int i16 = 0; i16 < count; i16 = i16 + 1) {
			table[i16] = iscaleItSIG15Wave0[iscaleItSIG15Wave0_idx];
			iscaleItSIG15Wave0_idx = (1 + iscaleItSIG15Wave0_idx) % 12;
		}
	}

};

static scaleItSIG15* newscaleItSIG15() { return (scaleItSIG15*)new scaleItSIG15(); }
static void deletescaleItSIG15(scaleItSIG15* dsp) { delete dsp; }

class scaleItSIG16 {
	
  public:
	
	int iVec3[2];
	int iRec10[2];
	
  public:
	
	int getNumInputsscaleItSIG16() {
		return 0;
	}
	int getNumOutputsscaleItSIG16() {
		return 1;
	}
	
	void instanceInitscaleItSIG16(int sample_rate) {
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iVec3[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iRec10[l9] = 0;
		}
	}
	
	void fillscaleItSIG16(int count, double* table) {
		for (int i17 = 0; i17 < count; i17 = i17 + 1) {
			iVec3[0] = 1;
			iRec10[0] = (iVec3[1] + iRec10[1]) % 65536;
			table[i17] = std::sin(9.58738021850586e-05 * double(iRec10[0]));
			iVec3[1] = iVec3[0];
			iRec10[1] = iRec10[0];
		}
	}

};

static scaleItSIG16* newscaleItSIG16() { return (scaleItSIG16*)new scaleItSIG16(); }
static void deletescaleItSIG16(scaleItSIG16* dsp) { delete dsp; }

static int itbl0scaleItSIG0[12];
static int itbl1scaleItSIG1[12];
static int itbl2scaleItSIG2[12];
static int itbl3scaleItSIG3[12];
static int itbl4scaleItSIG4[13];
static int itbl5scaleItSIG5[12];
static int itbl6scaleItSIG6[12];
static int itbl7scaleItSIG7[13];
static int itbl8scaleItSIG8[13];
static int itbl9scaleItSIG9[12];
static int itbl10scaleItSIG10[12];
static int itbl11scaleItSIG11[12];
static int itbl12scaleItSIG12[12];
static int itbl13scaleItSIG13[12];
static int itbl14scaleItSIG14[12];
static int itbl15scaleItSIG15[12];
static double scaleIt_faustpower2_f(double value) {
	return value * value;
}
static double ftbl16scaleItSIG16[65536];

class scaleIt : public dsp {
	
 public:
	
	int iVec0[2];
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fEntry2;
	int iConst4;
	int iConst5;
	int iConst6;
	int iConst7;
	int iConst8;
	int iConst9;
	int iConst10;
	int iConst11;
	int iConst12;
	int iConst13;
	int iConst14;
	int iConst15;
	int iConst16;
	int iConst17;
	int iConst18;
	int iConst19;
	FAUSTFLOAT fEntry3;
	FAUSTFLOAT fEntry4;
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	int iRec5[2];
	double fRec4[3];
	FAUSTFLOAT fEntry5;
	FAUSTFLOAT fEntry6;
	double fRec6[2];
	double fVec1[2];
	int IOTA0;
	double fVec2[4096];
	double fConst28;
	double fConst29;
	double fRec7[2];
	double fConst30;
	double fRec8[2];
	double fRec11[2];
	FAUSTFLOAT fEntry7;
	FAUSTFLOAT fEntry8;
	FAUSTFLOAT fEntry9;
	FAUSTFLOAT fEntry10;
	int iVec4[2];
	int iVec5[2];
	int iVec6[2];
	int iVec7[2];
	int iVec8[2];
	int iVec9[2];
	int iVec10[2];
	int iVec11[2];
	int iVec12[2];
	int iVec13[2];
	int iVec14[2];
	int iVec15[2];
	int iVec16[2];
	int iRec12[2];
	FAUSTFLOAT fEntry11;
	int iRec13[2];
	FAUSTFLOAT fEntry12;
	FAUSTFLOAT fEntry13;
	FAUSTFLOAT fEntry14;
	FAUSTFLOAT fEntry15;
	int iConst31;
	int iConst32;
	int iConst33;
	int iConst34;
	int iConst35;
	int iConst36;
	int iConst37;
	int iConst38;
	int iConst39;
	int iConst40;
	int iConst41;
	int iConst42;
	int iConst43;
	int iConst44;
	int iConst45;
	int iConst46;
	double fRec14[3];
	double fRec15[2];
	double fVec17[2];
	double fVec18[4096];
	double fRec16[2];
	double fRec17[2];
	double fRec19[2];
	int iVec19[2];
	int iRec20[2];
	int iRec21[2];
	FAUSTFLOAT fEntry16;
	int iConst47;
	int iConst48;
	int iConst49;
	int iConst50;
	int iConst51;
	int iConst52;
	int iConst53;
	int iConst54;
	int iConst55;
	int iConst56;
	int iConst57;
	int iConst58;
	int iConst59;
	int iConst60;
	int iConst61;
	int iConst62;
	double fRec22[3];
	double fRec23[2];
	double fVec20[2];
	double fVec21[4096];
	double fRec24[2];
	double fRec25[2];
	double fRec27[2];
	int iVec22[2];
	int iRec28[2];
	int iRec29[2];
	FAUSTFLOAT fEntry17;
	int iConst63;
	int iConst64;
	int iConst65;
	int iConst66;
	int iConst67;
	int iConst68;
	int iConst69;
	int iConst70;
	int iConst71;
	int iConst72;
	int iConst73;
	int iConst74;
	int iConst75;
	int iConst76;
	int iConst77;
	int iConst78;
	double fRec30[3];
	double fRec31[2];
	double fVec23[2];
	double fVec24[4096];
	double fRec32[2];
	double fRec33[2];
	double fRec35[2];
	int iVec25[2];
	int iRec36[2];
	int iRec37[2];
	FAUSTFLOAT fEntry18;
	int iConst79;
	int iConst80;
	int iConst81;
	int iConst82;
	int iConst83;
	int iConst84;
	int iConst85;
	int iConst86;
	int iConst87;
	int iConst88;
	int iConst89;
	int iConst90;
	int iConst91;
	int iConst92;
	int iConst93;
	int iConst94;
	double fRec38[3];
	double fRec39[2];
	double fVec26[2];
	double fVec27[4096];
	double fRec40[2];
	double fRec41[2];
	double fRec43[2];
	int iVec28[2];
	int iRec44[2];
	int iRec45[2];
	FAUSTFLOAT fEntry19;
	int iConst95;
	int iConst96;
	int iConst97;
	int iConst98;
	int iConst99;
	int iConst100;
	int iConst101;
	int iConst102;
	int iConst103;
	int iConst104;
	int iConst105;
	int iConst106;
	int iConst107;
	int iConst108;
	int iConst109;
	int iConst110;
	double fRec46[3];
	double fRec47[2];
	double fVec29[2];
	double fVec30[4096];
	double fRec48[2];
	double fRec49[2];
	double fRec51[2];
	int iVec31[2];
	int iRec52[2];
	int iRec53[2];
	double fConst111;
	double fRec3[2];
	double fConst112;
	double fRec2[2];
	double fConst113;
	double fConst114;
	double fRec1[2];
	double fConst115;
	double fRec0[2];
	FAUSTFLOAT fEntry20;
	FAUSTFLOAT fEntry21;
	int iConst116;
	int iConst117;
	int iConst118;
	int iConst119;
	int iConst120;
	int iConst121;
	int iConst122;
	int iConst123;
	int iConst124;
	int iConst125;
	int iConst126;
	int iConst127;
	int iConst128;
	int iConst129;
	int iConst130;
	int iConst131;
	double fRec58[3];
	int iRec59[2];
	int iRec60[2];
	double fRec61[2];
	double fVec32[2];
	double fVec33[4096];
	double fRec62[2];
	double fConst132;
	double fRec63[2];
	double fConst133;
	double fRec65[2];
	FAUSTFLOAT fEntry22;
	double fRec66[3];
	int iRec67[2];
	int iRec68[2];
	double fRec69[2];
	double fVec34[2];
	double fVec35[4096];
	double fRec70[2];
	double fRec71[2];
	double fRec73[2];
	FAUSTFLOAT fEntry23;
	FAUSTFLOAT fEntry24;
	int iConst134;
	int iConst135;
	int iConst136;
	int iConst137;
	int iConst138;
	int iConst139;
	int iConst140;
	int iConst141;
	int iConst142;
	int iConst143;
	int iConst144;
	int iConst145;
	int iConst146;
	int iConst147;
	int iConst148;
	int iConst149;
	double fRec74[3];
	int iRec75[2];
	int iRec76[2];
	double fRec77[2];
	double fVec36[2];
	double fVec37[4096];
	double fRec78[2];
	double fRec79[2];
	double fRec81[2];
	FAUSTFLOAT fEntry25;
	double fRec82[3];
	int iRec83[2];
	int iRec84[2];
	double fRec85[2];
	double fVec38[2];
	double fVec39[4096];
	double fRec86[2];
	double fRec87[2];
	double fRec89[2];
	FAUSTFLOAT fEntry26;
	FAUSTFLOAT fEntry27;
	int iConst150;
	int iConst151;
	int iConst152;
	int iConst153;
	int iConst154;
	int iConst155;
	int iConst156;
	int iConst157;
	int iConst158;
	int iConst159;
	int iConst160;
	int iConst161;
	int iConst162;
	int iConst163;
	int iConst164;
	int iConst165;
	double fRec90[3];
	int iRec91[2];
	int iRec92[2];
	double fRec93[2];
	double fVec40[2];
	double fVec41[4096];
	double fRec94[2];
	double fRec95[2];
	double fRec97[2];
	FAUSTFLOAT fEntry28;
	double fRec98[3];
	int iRec99[2];
	int iRec100[2];
	double fRec101[2];
	double fVec42[2];
	double fVec43[4096];
	double fRec102[2];
	double fRec103[2];
	double fRec105[2];
	FAUSTFLOAT fEntry29;
	FAUSTFLOAT fEntry30;
	int iConst166;
	int iConst167;
	int iConst168;
	int iConst169;
	int iConst170;
	int iConst171;
	int iConst172;
	int iConst173;
	int iConst174;
	int iConst175;
	int iConst176;
	int iConst177;
	int iConst178;
	int iConst179;
	int iConst180;
	int iConst181;
	double fRec106[3];
	int iRec107[2];
	int iRec108[2];
	double fRec109[2];
	double fVec44[2];
	double fVec45[4096];
	double fRec110[2];
	double fRec111[2];
	double fRec113[2];
	FAUSTFLOAT fEntry31;
	double fRec114[3];
	int iRec115[2];
	int iRec116[2];
	double fRec117[2];
	double fVec46[2];
	double fVec47[4096];
	double fRec118[2];
	double fRec119[2];
	double fRec121[2];
	FAUSTFLOAT fEntry32;
	FAUSTFLOAT fEntry33;
	int iConst182;
	int iConst183;
	int iConst184;
	int iConst185;
	int iConst186;
	int iConst187;
	int iConst188;
	int iConst189;
	int iConst190;
	int iConst191;
	int iConst192;
	int iConst193;
	int iConst194;
	int iConst195;
	int iConst196;
	int iConst197;
	double fRec122[3];
	int iRec123[2];
	int iRec124[2];
	double fRec125[2];
	double fVec48[2];
	double fVec49[4096];
	double fRec126[2];
	double fRec127[2];
	double fRec129[2];
	FAUSTFLOAT fEntry34;
	double fRec130[3];
	int iRec131[2];
	int iRec132[2];
	double fRec133[2];
	double fVec50[2];
	double fVec51[4096];
	double fRec134[2];
	double fRec135[2];
	double fRec137[2];
	FAUSTFLOAT fEntry35;
	FAUSTFLOAT fEntry36;
	int iConst198;
	int iConst199;
	int iConst200;
	int iConst201;
	int iConst202;
	int iConst203;
	int iConst204;
	int iConst205;
	int iConst206;
	int iConst207;
	int iConst208;
	int iConst209;
	int iConst210;
	int iConst211;
	int iConst212;
	int iConst213;
	double fRec138[3];
	int iRec139[2];
	int iRec140[2];
	double fRec141[2];
	double fVec52[2];
	double fVec53[4096];
	double fRec142[2];
	double fRec143[2];
	double fRec145[2];
	FAUSTFLOAT fEntry37;
	double fRec146[2];
	double fVec54[2];
	double fVec55[4096];
	double fRec147[2];
	double fRec148[2];
	double fRec150[2];
	FAUSTFLOAT fEntry38;
	double fRec151[3];
	int iRec152[2];
	int iRec153[2];
	double fRec57[2];
	double fRec56[2];
	double fRec55[2];
	double fRec54[2];
	FAUSTFLOAT fEntry39;
	double fRec158[3];
	double fRec159[2];
	double fVec56[2];
	double fVec57[4096];
	double fRec160[2];
	double fRec161[2];
	double fRec163[2];
	int iVec58[2];
	int iRec164[2];
	int iRec165[2];
	double fRec166[3];
	double fRec167[2];
	double fVec59[2];
	double fVec60[4096];
	double fRec168[2];
	double fRec169[2];
	double fRec171[2];
	int iVec61[2];
	int iRec172[2];
	int iRec173[2];
	double fRec174[3];
	double fRec175[2];
	double fVec62[2];
	double fVec63[4096];
	double fRec176[2];
	double fRec177[2];
	double fRec179[2];
	int iVec64[2];
	int iRec180[2];
	int iRec181[2];
	double fRec182[3];
	double fRec183[2];
	double fVec65[2];
	double fVec66[4096];
	double fRec184[2];
	double fRec185[2];
	double fRec187[2];
	int iVec67[2];
	int iRec188[2];
	int iRec189[2];
	double fRec190[3];
	double fRec191[2];
	double fVec68[2];
	double fVec69[4096];
	double fRec192[2];
	double fRec193[2];
	double fRec195[2];
	int iVec70[2];
	int iRec196[2];
	int iRec197[2];
	double fRec198[3];
	double fRec199[2];
	double fVec71[2];
	double fVec72[4096];
	double fRec200[2];
	double fRec201[2];
	double fRec203[2];
	int iVec73[2];
	int iRec204[2];
	int iRec205[2];
	double fRec157[2];
	double fRec156[2];
	double fRec155[2];
	double fRec154[2];
	double fRec209[2];
	double fRec208[2];
	double fRec207[2];
	double fRec206[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers_lib_amp_follower_ar_author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers_lib_name", "Faust Analyzer Library");
		m->declare("analyzers_lib_version", "0.2");
		m->declare("basics_lib_name", "Faust Basic Element Library");
		m->declare("basics_lib_parallelMax_author", "Bart Brouns");
		m->declare("basics_lib_parallelMax_copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics_lib_parallelMax_licence", "GPL-3.0");
		m->declare("basics_lib_parallelMin_author", "Bart Brouns");
		m->declare("basics_lib_parallelMin_copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics_lib_parallelMin_licence", "GPL-3.0");
		m->declare("basics_lib_parallelOp_author", "Bart Brouns");
		m->declare("basics_lib_parallelOp_copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics_lib_parallelOp_licence", "GPL-3.0");
		m->declare("basics_lib_selectoutn_author", "Vince");
		m->declare("basics_lib_version", "0.8");
		m->declare("compile_options", "-a /usr/local/share/faust/max-msp/max-msp64.cpp -lang cpp -i -cn scaleIt -es 1 -mcd 16 -uim -double -ftz 0");
		m->declare("compressors_lib_compression_gain_mono_author", "Julius O. Smith III");
		m->declare("compressors_lib_compression_gain_mono_copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors_lib_compression_gain_mono_license", "MIT-style STK-4.3 license");
		m->declare("compressors_lib_compressor_lad_mono_author", "Julius O. Smith III");
		m->declare("compressors_lib_compressor_lad_mono_copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors_lib_compressor_lad_mono_license", "MIT-style STK-4.3 license");
		m->declare("compressors_lib_compressor_mono_author", "Julius O. Smith III");
		m->declare("compressors_lib_compressor_mono_copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors_lib_compressor_mono_license", "MIT-style STK-4.3 license");
		m->declare("compressors_lib_limiter_1176_R4_mono_author", "Julius O. Smith III");
		m->declare("compressors_lib_limiter_1176_R4_mono_copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors_lib_limiter_1176_R4_mono_license", "MIT-style STK-4.3 license");
		m->declare("compressors_lib_name", "Faust Compressor Effect Library");
		m->declare("compressors_lib_version", "0.4");
		m->declare("envelopes_lib_adsr_author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes_lib_author", "GRAME");
		m->declare("envelopes_lib_copyright", "GRAME");
		m->declare("envelopes_lib_license", "LGPL with exception");
		m->declare("envelopes_lib_name", "Faust Envelope Library");
		m->declare("envelopes_lib_version", "0.2");
		m->declare("filename", "scaleIt.dsp");
		m->declare("filters_lib_bandpass0_bandstop1_author", "Julius O. Smith III");
		m->declare("filters_lib_bandpass0_bandstop1_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_bandpass0_bandstop1_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_bandpass_author", "Julius O. Smith III");
		m->declare("filters_lib_bandpass_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_bandpass_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_fir_author", "Julius O. Smith III");
		m->declare("filters_lib_fir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_fir_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_iir_author", "Julius O. Smith III");
		m->declare("filters_lib_iir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_iir_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_name", "Faust Filters Library");
		m->declare("filters_lib_pole_author", "Julius O. Smith III");
		m->declare("filters_lib_pole_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_pole_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_tf1sb_author", "Julius O. Smith III");
		m->declare("filters_lib_tf1sb_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_tf1sb_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_tf2_author", "Julius O. Smith III");
		m->declare("filters_lib_tf2_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_tf2_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_version", "0.3");
		m->declare("library_path0", "/libraries/stdfaust.lib");
		m->declare("library_path1", "/libraries/basics.lib");
		m->declare("library_path10", "/libraries/filters.lib");
		m->declare("library_path11", "/libraries/noises.lib");
		m->declare("library_path12", "/libraries/analyzers.lib");
		m->declare("library_path2", "/libraries/routes.lib");
		m->declare("library_path3", "/libraries/signals.lib");
		m->declare("library_path4", "/libraries/envelopes.lib");
		m->declare("library_path5", "/libraries/spats.lib");
		m->declare("library_path6", "/libraries/compressors.lib");
		m->declare("library_path7", "/libraries/maths.lib");
		m->declare("library_path8", "/libraries/platform.lib");
		m->declare("library_path9", "/libraries/oscillators.lib");
		m->declare("maths_lib_author", "GRAME");
		m->declare("maths_lib_copyright", "GRAME");
		m->declare("maths_lib_license", "LGPL with exception");
		m->declare("maths_lib_name", "Faust Math Library");
		m->declare("maths_lib_version", "2.5");
		m->declare("name", "scaleIt");
		m->declare("noises_lib_name", "Faust Noise Generator Library");
		m->declare("noises_lib_version", "0.4");
		m->declare("oscillators_lib_lf_sawpos_author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators_lib_lf_sawpos_licence", "STK-4.3");
		m->declare("oscillators_lib_name", "Faust Oscillator Library");
		m->declare("oscillators_lib_version", "0.3");
		m->declare("platform_lib_name", "Generic Platform Library");
		m->declare("platform_lib_version", "0.2");
		m->declare("routes_lib_name", "Faust Signal Routing Library");
		m->declare("routes_lib_version", "0.2");
		m->declare("signals_lib_name", "Faust Signal Routing Library");
		m->declare("signals_lib_onePoleSwitching_author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals_lib_onePoleSwitching_licence", "STK-4.3");
		m->declare("signals_lib_version", "0.3");
		m->declare("spats_lib_name", "Faust Spatialization Library");
		m->declare("spats_lib_version", "0.0");
		m->declare("version", "2.52.3");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 3;
	}
	
	static void classInit(int sample_rate) {
		scaleItSIG0* sig0 = newscaleItSIG0();
		sig0->instanceInitscaleItSIG0(sample_rate);
		sig0->fillscaleItSIG0(12, itbl0scaleItSIG0);
		scaleItSIG1* sig1 = newscaleItSIG1();
		sig1->instanceInitscaleItSIG1(sample_rate);
		sig1->fillscaleItSIG1(12, itbl1scaleItSIG1);
		scaleItSIG2* sig2 = newscaleItSIG2();
		sig2->instanceInitscaleItSIG2(sample_rate);
		sig2->fillscaleItSIG2(12, itbl2scaleItSIG2);
		scaleItSIG3* sig3 = newscaleItSIG3();
		sig3->instanceInitscaleItSIG3(sample_rate);
		sig3->fillscaleItSIG3(12, itbl3scaleItSIG3);
		scaleItSIG4* sig4 = newscaleItSIG4();
		sig4->instanceInitscaleItSIG4(sample_rate);
		sig4->fillscaleItSIG4(13, itbl4scaleItSIG4);
		scaleItSIG5* sig5 = newscaleItSIG5();
		sig5->instanceInitscaleItSIG5(sample_rate);
		sig5->fillscaleItSIG5(12, itbl5scaleItSIG5);
		scaleItSIG6* sig6 = newscaleItSIG6();
		sig6->instanceInitscaleItSIG6(sample_rate);
		sig6->fillscaleItSIG6(12, itbl6scaleItSIG6);
		scaleItSIG7* sig7 = newscaleItSIG7();
		sig7->instanceInitscaleItSIG7(sample_rate);
		sig7->fillscaleItSIG7(13, itbl7scaleItSIG7);
		scaleItSIG8* sig8 = newscaleItSIG8();
		sig8->instanceInitscaleItSIG8(sample_rate);
		sig8->fillscaleItSIG8(13, itbl8scaleItSIG8);
		scaleItSIG9* sig9 = newscaleItSIG9();
		sig9->instanceInitscaleItSIG9(sample_rate);
		sig9->fillscaleItSIG9(12, itbl9scaleItSIG9);
		scaleItSIG10* sig10 = newscaleItSIG10();
		sig10->instanceInitscaleItSIG10(sample_rate);
		sig10->fillscaleItSIG10(12, itbl10scaleItSIG10);
		scaleItSIG11* sig11 = newscaleItSIG11();
		sig11->instanceInitscaleItSIG11(sample_rate);
		sig11->fillscaleItSIG11(12, itbl11scaleItSIG11);
		scaleItSIG12* sig12 = newscaleItSIG12();
		sig12->instanceInitscaleItSIG12(sample_rate);
		sig12->fillscaleItSIG12(12, itbl12scaleItSIG12);
		scaleItSIG13* sig13 = newscaleItSIG13();
		sig13->instanceInitscaleItSIG13(sample_rate);
		sig13->fillscaleItSIG13(12, itbl13scaleItSIG13);
		scaleItSIG14* sig14 = newscaleItSIG14();
		sig14->instanceInitscaleItSIG14(sample_rate);
		sig14->fillscaleItSIG14(12, itbl14scaleItSIG14);
		scaleItSIG15* sig15 = newscaleItSIG15();
		sig15->instanceInitscaleItSIG15(sample_rate);
		sig15->fillscaleItSIG15(12, itbl15scaleItSIG15);
		scaleItSIG16* sig16 = newscaleItSIG16();
		sig16->instanceInitscaleItSIG16(sample_rate);
		sig16->fillscaleItSIG16(65536, ftbl16scaleItSIG16);
		deletescaleItSIG0(sig0);
		deletescaleItSIG1(sig1);
		deletescaleItSIG2(sig2);
		deletescaleItSIG3(sig3);
		deletescaleItSIG4(sig4);
		deletescaleItSIG5(sig5);
		deletescaleItSIG6(sig6);
		deletescaleItSIG7(sig7);
		deletescaleItSIG8(sig8);
		deletescaleItSIG9(sig9);
		deletescaleItSIG10(sig10);
		deletescaleItSIG11(sig11);
		deletescaleItSIG12(sig12);
		deletescaleItSIG13(sig13);
		deletescaleItSIG14(sig14);
		deletescaleItSIG15(sig15);
		deletescaleItSIG16(sig16);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
		fConst1 = std::exp(0.0 - 2.5e+03 / fConst0);
		fConst2 = std::exp(0.0 - 2e+01 / fConst0);
		fConst3 = std::exp(0.0 - 1e+01 / fConst0);
		iConst4 = itbl0scaleItSIG0[10];
		iConst5 = itbl1scaleItSIG1[10];
		iConst6 = itbl2scaleItSIG2[10];
		iConst7 = itbl3scaleItSIG3[10];
		iConst8 = itbl4scaleItSIG4[10];
		iConst9 = itbl5scaleItSIG5[10];
		iConst10 = itbl6scaleItSIG6[10];
		iConst11 = itbl7scaleItSIG7[10];
		iConst12 = itbl8scaleItSIG8[10];
		iConst13 = itbl9scaleItSIG9[10];
		iConst14 = itbl10scaleItSIG10[10];
		iConst15 = itbl11scaleItSIG11[10];
		iConst16 = itbl12scaleItSIG12[10];
		iConst17 = itbl13scaleItSIG13[10];
		iConst18 = itbl14scaleItSIG14[10];
		iConst19 = itbl15scaleItSIG15[10];
		fConst20 = 3.14159275 / fConst0;
		fConst21 = 4.0 * scaleIt_faustpower2_f(fConst0);
		fConst22 = 0.5 / fConst0;
		fConst23 = 2.0 * fConst0;
		fConst24 = 2.0 / fConst0;
		fConst25 = 1.0 / fConst0;
		fConst26 = scaleIt_faustpower2_f(fConst25);
		fConst27 = 2.0 * fConst26;
		fConst28 = 0.5 * fConst0;
		fConst29 = 0.25 * fConst0;
		fConst30 = 4.0 / fConst0;
		iConst31 = itbl0scaleItSIG0[8];
		iConst32 = itbl1scaleItSIG1[8];
		iConst33 = itbl2scaleItSIG2[8];
		iConst34 = itbl3scaleItSIG3[8];
		iConst35 = itbl4scaleItSIG4[8];
		iConst36 = itbl5scaleItSIG5[8];
		iConst37 = itbl6scaleItSIG6[8];
		iConst38 = itbl7scaleItSIG7[8];
		iConst39 = itbl8scaleItSIG8[8];
		iConst40 = itbl9scaleItSIG9[8];
		iConst41 = itbl10scaleItSIG10[8];
		iConst42 = itbl11scaleItSIG11[8];
		iConst43 = itbl12scaleItSIG12[8];
		iConst44 = itbl13scaleItSIG13[8];
		iConst45 = itbl14scaleItSIG14[8];
		iConst46 = itbl15scaleItSIG15[8];
		iConst47 = itbl0scaleItSIG0[6];
		iConst48 = itbl1scaleItSIG1[6];
		iConst49 = itbl2scaleItSIG2[6];
		iConst50 = itbl3scaleItSIG3[6];
		iConst51 = itbl4scaleItSIG4[6];
		iConst52 = itbl5scaleItSIG5[6];
		iConst53 = itbl6scaleItSIG6[6];
		iConst54 = itbl7scaleItSIG7[6];
		iConst55 = itbl8scaleItSIG8[6];
		iConst56 = itbl9scaleItSIG9[6];
		iConst57 = itbl10scaleItSIG10[6];
		iConst58 = itbl11scaleItSIG11[6];
		iConst59 = itbl12scaleItSIG12[6];
		iConst60 = itbl13scaleItSIG13[6];
		iConst61 = itbl14scaleItSIG14[6];
		iConst62 = itbl15scaleItSIG15[6];
		iConst63 = itbl0scaleItSIG0[4];
		iConst64 = itbl1scaleItSIG1[4];
		iConst65 = itbl2scaleItSIG2[4];
		iConst66 = itbl3scaleItSIG3[4];
		iConst67 = itbl4scaleItSIG4[4];
		iConst68 = itbl5scaleItSIG5[4];
		iConst69 = itbl6scaleItSIG6[4];
		iConst70 = itbl7scaleItSIG7[4];
		iConst71 = itbl8scaleItSIG8[4];
		iConst72 = itbl9scaleItSIG9[4];
		iConst73 = itbl10scaleItSIG10[4];
		iConst74 = itbl11scaleItSIG11[4];
		iConst75 = itbl12scaleItSIG12[4];
		iConst76 = itbl13scaleItSIG13[4];
		iConst77 = itbl14scaleItSIG14[4];
		iConst78 = itbl15scaleItSIG15[4];
		iConst79 = itbl0scaleItSIG0[2];
		iConst80 = itbl1scaleItSIG1[2];
		iConst81 = itbl2scaleItSIG2[2];
		iConst82 = itbl3scaleItSIG3[2];
		iConst83 = itbl4scaleItSIG4[2];
		iConst84 = itbl5scaleItSIG5[2];
		iConst85 = itbl6scaleItSIG6[2];
		iConst86 = itbl7scaleItSIG7[2];
		iConst87 = itbl8scaleItSIG8[2];
		iConst88 = itbl9scaleItSIG9[2];
		iConst89 = itbl10scaleItSIG10[2];
		iConst90 = itbl11scaleItSIG11[2];
		iConst91 = itbl12scaleItSIG12[2];
		iConst92 = itbl13scaleItSIG13[2];
		iConst93 = itbl14scaleItSIG14[2];
		iConst94 = itbl15scaleItSIG15[2];
		iConst95 = itbl0scaleItSIG0[0];
		iConst96 = itbl1scaleItSIG1[0];
		iConst97 = itbl2scaleItSIG2[0];
		iConst98 = itbl3scaleItSIG3[0];
		iConst99 = itbl4scaleItSIG4[0];
		iConst100 = itbl5scaleItSIG5[0];
		iConst101 = itbl6scaleItSIG6[0];
		iConst102 = itbl7scaleItSIG7[0];
		iConst103 = itbl8scaleItSIG8[0];
		iConst104 = itbl9scaleItSIG9[0];
		iConst105 = itbl10scaleItSIG10[0];
		iConst106 = itbl11scaleItSIG11[0];
		iConst107 = itbl12scaleItSIG12[0];
		iConst108 = itbl13scaleItSIG13[0];
		iConst109 = itbl14scaleItSIG14[0];
		iConst110 = itbl15scaleItSIG15[0];
		fConst111 = 1.0 - fConst3;
		fConst112 = 1.0 - fConst2;
		fConst113 = std::exp(0.0 - fConst24);
		fConst114 = std::exp(0.0 - 1.25e+03 / fConst0);
		fConst115 = 1.0 - fConst1;
		iConst116 = itbl0scaleItSIG0[11];
		iConst117 = itbl1scaleItSIG1[11];
		iConst118 = itbl2scaleItSIG2[11];
		iConst119 = itbl3scaleItSIG3[11];
		iConst120 = itbl4scaleItSIG4[11];
		iConst121 = itbl5scaleItSIG5[11];
		iConst122 = itbl6scaleItSIG6[11];
		iConst123 = itbl7scaleItSIG7[11];
		iConst124 = itbl8scaleItSIG8[11];
		iConst125 = itbl9scaleItSIG9[11];
		iConst126 = itbl10scaleItSIG10[11];
		iConst127 = itbl11scaleItSIG11[11];
		iConst128 = itbl12scaleItSIG12[11];
		iConst129 = itbl13scaleItSIG13[11];
		iConst130 = itbl14scaleItSIG14[11];
		iConst131 = itbl15scaleItSIG15[11];
		fConst132 = 1.76e+03 / fConst0;
		fConst133 = 4.4e+02 / fConst0;
		iConst134 = itbl0scaleItSIG0[9];
		iConst135 = itbl1scaleItSIG1[9];
		iConst136 = itbl2scaleItSIG2[9];
		iConst137 = itbl3scaleItSIG3[9];
		iConst138 = itbl4scaleItSIG4[9];
		iConst139 = itbl5scaleItSIG5[9];
		iConst140 = itbl6scaleItSIG6[9];
		iConst141 = itbl7scaleItSIG7[9];
		iConst142 = itbl8scaleItSIG8[9];
		iConst143 = itbl9scaleItSIG9[9];
		iConst144 = itbl10scaleItSIG10[9];
		iConst145 = itbl11scaleItSIG11[9];
		iConst146 = itbl12scaleItSIG12[9];
		iConst147 = itbl13scaleItSIG13[9];
		iConst148 = itbl14scaleItSIG14[9];
		iConst149 = itbl15scaleItSIG15[9];
		iConst150 = itbl0scaleItSIG0[7];
		iConst151 = itbl1scaleItSIG1[7];
		iConst152 = itbl2scaleItSIG2[7];
		iConst153 = itbl3scaleItSIG3[7];
		iConst154 = itbl4scaleItSIG4[7];
		iConst155 = itbl5scaleItSIG5[7];
		iConst156 = itbl6scaleItSIG6[7];
		iConst157 = itbl7scaleItSIG7[7];
		iConst158 = itbl8scaleItSIG8[7];
		iConst159 = itbl9scaleItSIG9[7];
		iConst160 = itbl10scaleItSIG10[7];
		iConst161 = itbl11scaleItSIG11[7];
		iConst162 = itbl12scaleItSIG12[7];
		iConst163 = itbl13scaleItSIG13[7];
		iConst164 = itbl14scaleItSIG14[7];
		iConst165 = itbl15scaleItSIG15[7];
		iConst166 = itbl0scaleItSIG0[5];
		iConst167 = itbl1scaleItSIG1[5];
		iConst168 = itbl2scaleItSIG2[5];
		iConst169 = itbl3scaleItSIG3[5];
		iConst170 = itbl4scaleItSIG4[5];
		iConst171 = itbl5scaleItSIG5[5];
		iConst172 = itbl6scaleItSIG6[5];
		iConst173 = itbl7scaleItSIG7[5];
		iConst174 = itbl8scaleItSIG8[5];
		iConst175 = itbl9scaleItSIG9[5];
		iConst176 = itbl10scaleItSIG10[5];
		iConst177 = itbl11scaleItSIG11[5];
		iConst178 = itbl12scaleItSIG12[5];
		iConst179 = itbl13scaleItSIG13[5];
		iConst180 = itbl14scaleItSIG14[5];
		iConst181 = itbl15scaleItSIG15[5];
		iConst182 = itbl0scaleItSIG0[3];
		iConst183 = itbl1scaleItSIG1[3];
		iConst184 = itbl2scaleItSIG2[3];
		iConst185 = itbl3scaleItSIG3[3];
		iConst186 = itbl4scaleItSIG4[3];
		iConst187 = itbl5scaleItSIG5[3];
		iConst188 = itbl6scaleItSIG6[3];
		iConst189 = itbl7scaleItSIG7[3];
		iConst190 = itbl8scaleItSIG8[3];
		iConst191 = itbl9scaleItSIG9[3];
		iConst192 = itbl10scaleItSIG10[3];
		iConst193 = itbl11scaleItSIG11[3];
		iConst194 = itbl12scaleItSIG12[3];
		iConst195 = itbl13scaleItSIG13[3];
		iConst196 = itbl14scaleItSIG14[3];
		iConst197 = itbl15scaleItSIG15[3];
		iConst198 = itbl0scaleItSIG0[1];
		iConst199 = itbl1scaleItSIG1[1];
		iConst200 = itbl2scaleItSIG2[1];
		iConst201 = itbl3scaleItSIG3[1];
		iConst202 = itbl4scaleItSIG4[1];
		iConst203 = itbl5scaleItSIG5[1];
		iConst204 = itbl6scaleItSIG6[1];
		iConst205 = itbl7scaleItSIG7[1];
		iConst206 = itbl8scaleItSIG8[1];
		iConst207 = itbl9scaleItSIG9[1];
		iConst208 = itbl10scaleItSIG10[1];
		iConst209 = itbl11scaleItSIG11[1];
		iConst210 = itbl12scaleItSIG12[1];
		iConst211 = itbl13scaleItSIG13[1];
		iConst212 = itbl14scaleItSIG14[1];
		iConst213 = itbl15scaleItSIG15[1];
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(0.0);
		fEntry1 = FAUSTFLOAT(0.0);
		fEntry2 = FAUSTFLOAT(0.0);
		fEntry3 = FAUSTFLOAT(69.0);
		fEntry4 = FAUSTFLOAT(0.0);
		fEntry5 = FAUSTFLOAT(0.0);
		fEntry6 = FAUSTFLOAT(0.0);
		fEntry7 = FAUSTFLOAT(64.0);
		fEntry8 = FAUSTFLOAT(8.0);
		fEntry9 = FAUSTFLOAT(0.0);
		fEntry10 = FAUSTFLOAT(1.0);
		fEntry11 = FAUSTFLOAT(0.5);
		fEntry12 = FAUSTFLOAT(0.5);
		fEntry13 = FAUSTFLOAT(0.0);
		fEntry14 = FAUSTFLOAT(1.0);
		fEntry15 = FAUSTFLOAT(0.0);
		fEntry16 = FAUSTFLOAT(0.0);
		fEntry17 = FAUSTFLOAT(0.0);
		fEntry18 = FAUSTFLOAT(0.0);
		fEntry19 = FAUSTFLOAT(0.0);
		fEntry20 = FAUSTFLOAT(0.0);
		fEntry21 = FAUSTFLOAT(0.0);
		fEntry22 = FAUSTFLOAT(0.5);
		fEntry23 = FAUSTFLOAT(0.5);
		fEntry24 = FAUSTFLOAT(0.0);
		fEntry25 = FAUSTFLOAT(0.5);
		fEntry26 = FAUSTFLOAT(0.5);
		fEntry27 = FAUSTFLOAT(0.0);
		fEntry28 = FAUSTFLOAT(0.5);
		fEntry29 = FAUSTFLOAT(0.5);
		fEntry30 = FAUSTFLOAT(0.0);
		fEntry31 = FAUSTFLOAT(0.5);
		fEntry32 = FAUSTFLOAT(0.5);
		fEntry33 = FAUSTFLOAT(0.0);
		fEntry34 = FAUSTFLOAT(0.5);
		fEntry35 = FAUSTFLOAT(0.5);
		fEntry36 = FAUSTFLOAT(0.0);
		fEntry37 = FAUSTFLOAT(0.5);
		fEntry38 = FAUSTFLOAT(0.5);
		fEntry39 = FAUSTFLOAT(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec5[l1] = 0;
		}
		for (int l2 = 0; l2 < 3; l2 = l2 + 1) {
			fRec4[l2] = 0.0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec6[l3] = 0.0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fVec1[l4] = 0.0;
		}
		IOTA0 = 0;
		for (int l5 = 0; l5 < 4096; l5 = l5 + 1) {
			fVec2[l5] = 0.0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec7[l6] = 0.0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec8[l7] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec11[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iVec4[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			iVec5[l12] = 0;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			iVec6[l13] = 0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			iVec7[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iVec8[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			iVec9[l16] = 0;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			iVec10[l17] = 0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			iVec11[l18] = 0;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			iVec12[l19] = 0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iVec13[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			iVec14[l21] = 0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			iVec15[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			iVec16[l23] = 0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iRec12[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			iRec13[l25] = 0;
		}
		for (int l26 = 0; l26 < 3; l26 = l26 + 1) {
			fRec14[l26] = 0.0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec15[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fVec17[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 4096; l29 = l29 + 1) {
			fVec18[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec16[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec17[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec19[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			iVec19[l33] = 0;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			iRec20[l34] = 0;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			iRec21[l35] = 0;
		}
		for (int l36 = 0; l36 < 3; l36 = l36 + 1) {
			fRec22[l36] = 0.0;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec23[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fVec20[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 4096; l39 = l39 + 1) {
			fVec21[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec24[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec25[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec27[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			iVec22[l43] = 0;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			iRec28[l44] = 0;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			iRec29[l45] = 0;
		}
		for (int l46 = 0; l46 < 3; l46 = l46 + 1) {
			fRec30[l46] = 0.0;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec31[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fVec23[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 4096; l49 = l49 + 1) {
			fVec24[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec32[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec33[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec35[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			iVec25[l53] = 0;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			iRec36[l54] = 0;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			iRec37[l55] = 0;
		}
		for (int l56 = 0; l56 < 3; l56 = l56 + 1) {
			fRec38[l56] = 0.0;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec39[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fVec26[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 4096; l59 = l59 + 1) {
			fVec27[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fRec40[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec41[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec43[l62] = 0.0;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			iVec28[l63] = 0;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			iRec44[l64] = 0;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			iRec45[l65] = 0;
		}
		for (int l66 = 0; l66 < 3; l66 = l66 + 1) {
			fRec46[l66] = 0.0;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec47[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fVec29[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 4096; l69 = l69 + 1) {
			fVec30[l69] = 0.0;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fRec48[l70] = 0.0;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec49[l71] = 0.0;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec51[l72] = 0.0;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			iVec31[l73] = 0;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			iRec52[l74] = 0;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			iRec53[l75] = 0;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			fRec3[l76] = 0.0;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec2[l77] = 0.0;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec1[l78] = 0.0;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			fRec0[l79] = 0.0;
		}
		for (int l80 = 0; l80 < 3; l80 = l80 + 1) {
			fRec58[l80] = 0.0;
		}
		for (int l81 = 0; l81 < 2; l81 = l81 + 1) {
			iRec59[l81] = 0;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			iRec60[l82] = 0;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			fRec61[l83] = 0.0;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			fVec32[l84] = 0.0;
		}
		for (int l85 = 0; l85 < 4096; l85 = l85 + 1) {
			fVec33[l85] = 0.0;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			fRec62[l86] = 0.0;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fRec63[l87] = 0.0;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec65[l88] = 0.0;
		}
		for (int l89 = 0; l89 < 3; l89 = l89 + 1) {
			fRec66[l89] = 0.0;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			iRec67[l90] = 0;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			iRec68[l91] = 0;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			fRec69[l92] = 0.0;
		}
		for (int l93 = 0; l93 < 2; l93 = l93 + 1) {
			fVec34[l93] = 0.0;
		}
		for (int l94 = 0; l94 < 4096; l94 = l94 + 1) {
			fVec35[l94] = 0.0;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			fRec70[l95] = 0.0;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			fRec71[l96] = 0.0;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec73[l97] = 0.0;
		}
		for (int l98 = 0; l98 < 3; l98 = l98 + 1) {
			fRec74[l98] = 0.0;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			iRec75[l99] = 0;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			iRec76[l100] = 0;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			fRec77[l101] = 0.0;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fVec36[l102] = 0.0;
		}
		for (int l103 = 0; l103 < 4096; l103 = l103 + 1) {
			fVec37[l103] = 0.0;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			fRec78[l104] = 0.0;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			fRec79[l105] = 0.0;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			fRec81[l106] = 0.0;
		}
		for (int l107 = 0; l107 < 3; l107 = l107 + 1) {
			fRec82[l107] = 0.0;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			iRec83[l108] = 0;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			iRec84[l109] = 0;
		}
		for (int l110 = 0; l110 < 2; l110 = l110 + 1) {
			fRec85[l110] = 0.0;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			fVec38[l111] = 0.0;
		}
		for (int l112 = 0; l112 < 4096; l112 = l112 + 1) {
			fVec39[l112] = 0.0;
		}
		for (int l113 = 0; l113 < 2; l113 = l113 + 1) {
			fRec86[l113] = 0.0;
		}
		for (int l114 = 0; l114 < 2; l114 = l114 + 1) {
			fRec87[l114] = 0.0;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			fRec89[l115] = 0.0;
		}
		for (int l116 = 0; l116 < 3; l116 = l116 + 1) {
			fRec90[l116] = 0.0;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			iRec91[l117] = 0;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			iRec92[l118] = 0;
		}
		for (int l119 = 0; l119 < 2; l119 = l119 + 1) {
			fRec93[l119] = 0.0;
		}
		for (int l120 = 0; l120 < 2; l120 = l120 + 1) {
			fVec40[l120] = 0.0;
		}
		for (int l121 = 0; l121 < 4096; l121 = l121 + 1) {
			fVec41[l121] = 0.0;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			fRec94[l122] = 0.0;
		}
		for (int l123 = 0; l123 < 2; l123 = l123 + 1) {
			fRec95[l123] = 0.0;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			fRec97[l124] = 0.0;
		}
		for (int l125 = 0; l125 < 3; l125 = l125 + 1) {
			fRec98[l125] = 0.0;
		}
		for (int l126 = 0; l126 < 2; l126 = l126 + 1) {
			iRec99[l126] = 0;
		}
		for (int l127 = 0; l127 < 2; l127 = l127 + 1) {
			iRec100[l127] = 0;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			fRec101[l128] = 0.0;
		}
		for (int l129 = 0; l129 < 2; l129 = l129 + 1) {
			fVec42[l129] = 0.0;
		}
		for (int l130 = 0; l130 < 4096; l130 = l130 + 1) {
			fVec43[l130] = 0.0;
		}
		for (int l131 = 0; l131 < 2; l131 = l131 + 1) {
			fRec102[l131] = 0.0;
		}
		for (int l132 = 0; l132 < 2; l132 = l132 + 1) {
			fRec103[l132] = 0.0;
		}
		for (int l133 = 0; l133 < 2; l133 = l133 + 1) {
			fRec105[l133] = 0.0;
		}
		for (int l134 = 0; l134 < 3; l134 = l134 + 1) {
			fRec106[l134] = 0.0;
		}
		for (int l135 = 0; l135 < 2; l135 = l135 + 1) {
			iRec107[l135] = 0;
		}
		for (int l136 = 0; l136 < 2; l136 = l136 + 1) {
			iRec108[l136] = 0;
		}
		for (int l137 = 0; l137 < 2; l137 = l137 + 1) {
			fRec109[l137] = 0.0;
		}
		for (int l138 = 0; l138 < 2; l138 = l138 + 1) {
			fVec44[l138] = 0.0;
		}
		for (int l139 = 0; l139 < 4096; l139 = l139 + 1) {
			fVec45[l139] = 0.0;
		}
		for (int l140 = 0; l140 < 2; l140 = l140 + 1) {
			fRec110[l140] = 0.0;
		}
		for (int l141 = 0; l141 < 2; l141 = l141 + 1) {
			fRec111[l141] = 0.0;
		}
		for (int l142 = 0; l142 < 2; l142 = l142 + 1) {
			fRec113[l142] = 0.0;
		}
		for (int l143 = 0; l143 < 3; l143 = l143 + 1) {
			fRec114[l143] = 0.0;
		}
		for (int l144 = 0; l144 < 2; l144 = l144 + 1) {
			iRec115[l144] = 0;
		}
		for (int l145 = 0; l145 < 2; l145 = l145 + 1) {
			iRec116[l145] = 0;
		}
		for (int l146 = 0; l146 < 2; l146 = l146 + 1) {
			fRec117[l146] = 0.0;
		}
		for (int l147 = 0; l147 < 2; l147 = l147 + 1) {
			fVec46[l147] = 0.0;
		}
		for (int l148 = 0; l148 < 4096; l148 = l148 + 1) {
			fVec47[l148] = 0.0;
		}
		for (int l149 = 0; l149 < 2; l149 = l149 + 1) {
			fRec118[l149] = 0.0;
		}
		for (int l150 = 0; l150 < 2; l150 = l150 + 1) {
			fRec119[l150] = 0.0;
		}
		for (int l151 = 0; l151 < 2; l151 = l151 + 1) {
			fRec121[l151] = 0.0;
		}
		for (int l152 = 0; l152 < 3; l152 = l152 + 1) {
			fRec122[l152] = 0.0;
		}
		for (int l153 = 0; l153 < 2; l153 = l153 + 1) {
			iRec123[l153] = 0;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			iRec124[l154] = 0;
		}
		for (int l155 = 0; l155 < 2; l155 = l155 + 1) {
			fRec125[l155] = 0.0;
		}
		for (int l156 = 0; l156 < 2; l156 = l156 + 1) {
			fVec48[l156] = 0.0;
		}
		for (int l157 = 0; l157 < 4096; l157 = l157 + 1) {
			fVec49[l157] = 0.0;
		}
		for (int l158 = 0; l158 < 2; l158 = l158 + 1) {
			fRec126[l158] = 0.0;
		}
		for (int l159 = 0; l159 < 2; l159 = l159 + 1) {
			fRec127[l159] = 0.0;
		}
		for (int l160 = 0; l160 < 2; l160 = l160 + 1) {
			fRec129[l160] = 0.0;
		}
		for (int l161 = 0; l161 < 3; l161 = l161 + 1) {
			fRec130[l161] = 0.0;
		}
		for (int l162 = 0; l162 < 2; l162 = l162 + 1) {
			iRec131[l162] = 0;
		}
		for (int l163 = 0; l163 < 2; l163 = l163 + 1) {
			iRec132[l163] = 0;
		}
		for (int l164 = 0; l164 < 2; l164 = l164 + 1) {
			fRec133[l164] = 0.0;
		}
		for (int l165 = 0; l165 < 2; l165 = l165 + 1) {
			fVec50[l165] = 0.0;
		}
		for (int l166 = 0; l166 < 4096; l166 = l166 + 1) {
			fVec51[l166] = 0.0;
		}
		for (int l167 = 0; l167 < 2; l167 = l167 + 1) {
			fRec134[l167] = 0.0;
		}
		for (int l168 = 0; l168 < 2; l168 = l168 + 1) {
			fRec135[l168] = 0.0;
		}
		for (int l169 = 0; l169 < 2; l169 = l169 + 1) {
			fRec137[l169] = 0.0;
		}
		for (int l170 = 0; l170 < 3; l170 = l170 + 1) {
			fRec138[l170] = 0.0;
		}
		for (int l171 = 0; l171 < 2; l171 = l171 + 1) {
			iRec139[l171] = 0;
		}
		for (int l172 = 0; l172 < 2; l172 = l172 + 1) {
			iRec140[l172] = 0;
		}
		for (int l173 = 0; l173 < 2; l173 = l173 + 1) {
			fRec141[l173] = 0.0;
		}
		for (int l174 = 0; l174 < 2; l174 = l174 + 1) {
			fVec52[l174] = 0.0;
		}
		for (int l175 = 0; l175 < 4096; l175 = l175 + 1) {
			fVec53[l175] = 0.0;
		}
		for (int l176 = 0; l176 < 2; l176 = l176 + 1) {
			fRec142[l176] = 0.0;
		}
		for (int l177 = 0; l177 < 2; l177 = l177 + 1) {
			fRec143[l177] = 0.0;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			fRec145[l178] = 0.0;
		}
		for (int l179 = 0; l179 < 2; l179 = l179 + 1) {
			fRec146[l179] = 0.0;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			fVec54[l180] = 0.0;
		}
		for (int l181 = 0; l181 < 4096; l181 = l181 + 1) {
			fVec55[l181] = 0.0;
		}
		for (int l182 = 0; l182 < 2; l182 = l182 + 1) {
			fRec147[l182] = 0.0;
		}
		for (int l183 = 0; l183 < 2; l183 = l183 + 1) {
			fRec148[l183] = 0.0;
		}
		for (int l184 = 0; l184 < 2; l184 = l184 + 1) {
			fRec150[l184] = 0.0;
		}
		for (int l185 = 0; l185 < 3; l185 = l185 + 1) {
			fRec151[l185] = 0.0;
		}
		for (int l186 = 0; l186 < 2; l186 = l186 + 1) {
			iRec152[l186] = 0;
		}
		for (int l187 = 0; l187 < 2; l187 = l187 + 1) {
			iRec153[l187] = 0;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			fRec57[l188] = 0.0;
		}
		for (int l189 = 0; l189 < 2; l189 = l189 + 1) {
			fRec56[l189] = 0.0;
		}
		for (int l190 = 0; l190 < 2; l190 = l190 + 1) {
			fRec55[l190] = 0.0;
		}
		for (int l191 = 0; l191 < 2; l191 = l191 + 1) {
			fRec54[l191] = 0.0;
		}
		for (int l192 = 0; l192 < 3; l192 = l192 + 1) {
			fRec158[l192] = 0.0;
		}
		for (int l193 = 0; l193 < 2; l193 = l193 + 1) {
			fRec159[l193] = 0.0;
		}
		for (int l194 = 0; l194 < 2; l194 = l194 + 1) {
			fVec56[l194] = 0.0;
		}
		for (int l195 = 0; l195 < 4096; l195 = l195 + 1) {
			fVec57[l195] = 0.0;
		}
		for (int l196 = 0; l196 < 2; l196 = l196 + 1) {
			fRec160[l196] = 0.0;
		}
		for (int l197 = 0; l197 < 2; l197 = l197 + 1) {
			fRec161[l197] = 0.0;
		}
		for (int l198 = 0; l198 < 2; l198 = l198 + 1) {
			fRec163[l198] = 0.0;
		}
		for (int l199 = 0; l199 < 2; l199 = l199 + 1) {
			iVec58[l199] = 0;
		}
		for (int l200 = 0; l200 < 2; l200 = l200 + 1) {
			iRec164[l200] = 0;
		}
		for (int l201 = 0; l201 < 2; l201 = l201 + 1) {
			iRec165[l201] = 0;
		}
		for (int l202 = 0; l202 < 3; l202 = l202 + 1) {
			fRec166[l202] = 0.0;
		}
		for (int l203 = 0; l203 < 2; l203 = l203 + 1) {
			fRec167[l203] = 0.0;
		}
		for (int l204 = 0; l204 < 2; l204 = l204 + 1) {
			fVec59[l204] = 0.0;
		}
		for (int l205 = 0; l205 < 4096; l205 = l205 + 1) {
			fVec60[l205] = 0.0;
		}
		for (int l206 = 0; l206 < 2; l206 = l206 + 1) {
			fRec168[l206] = 0.0;
		}
		for (int l207 = 0; l207 < 2; l207 = l207 + 1) {
			fRec169[l207] = 0.0;
		}
		for (int l208 = 0; l208 < 2; l208 = l208 + 1) {
			fRec171[l208] = 0.0;
		}
		for (int l209 = 0; l209 < 2; l209 = l209 + 1) {
			iVec61[l209] = 0;
		}
		for (int l210 = 0; l210 < 2; l210 = l210 + 1) {
			iRec172[l210] = 0;
		}
		for (int l211 = 0; l211 < 2; l211 = l211 + 1) {
			iRec173[l211] = 0;
		}
		for (int l212 = 0; l212 < 3; l212 = l212 + 1) {
			fRec174[l212] = 0.0;
		}
		for (int l213 = 0; l213 < 2; l213 = l213 + 1) {
			fRec175[l213] = 0.0;
		}
		for (int l214 = 0; l214 < 2; l214 = l214 + 1) {
			fVec62[l214] = 0.0;
		}
		for (int l215 = 0; l215 < 4096; l215 = l215 + 1) {
			fVec63[l215] = 0.0;
		}
		for (int l216 = 0; l216 < 2; l216 = l216 + 1) {
			fRec176[l216] = 0.0;
		}
		for (int l217 = 0; l217 < 2; l217 = l217 + 1) {
			fRec177[l217] = 0.0;
		}
		for (int l218 = 0; l218 < 2; l218 = l218 + 1) {
			fRec179[l218] = 0.0;
		}
		for (int l219 = 0; l219 < 2; l219 = l219 + 1) {
			iVec64[l219] = 0;
		}
		for (int l220 = 0; l220 < 2; l220 = l220 + 1) {
			iRec180[l220] = 0;
		}
		for (int l221 = 0; l221 < 2; l221 = l221 + 1) {
			iRec181[l221] = 0;
		}
		for (int l222 = 0; l222 < 3; l222 = l222 + 1) {
			fRec182[l222] = 0.0;
		}
		for (int l223 = 0; l223 < 2; l223 = l223 + 1) {
			fRec183[l223] = 0.0;
		}
		for (int l224 = 0; l224 < 2; l224 = l224 + 1) {
			fVec65[l224] = 0.0;
		}
		for (int l225 = 0; l225 < 4096; l225 = l225 + 1) {
			fVec66[l225] = 0.0;
		}
		for (int l226 = 0; l226 < 2; l226 = l226 + 1) {
			fRec184[l226] = 0.0;
		}
		for (int l227 = 0; l227 < 2; l227 = l227 + 1) {
			fRec185[l227] = 0.0;
		}
		for (int l228 = 0; l228 < 2; l228 = l228 + 1) {
			fRec187[l228] = 0.0;
		}
		for (int l229 = 0; l229 < 2; l229 = l229 + 1) {
			iVec67[l229] = 0;
		}
		for (int l230 = 0; l230 < 2; l230 = l230 + 1) {
			iRec188[l230] = 0;
		}
		for (int l231 = 0; l231 < 2; l231 = l231 + 1) {
			iRec189[l231] = 0;
		}
		for (int l232 = 0; l232 < 3; l232 = l232 + 1) {
			fRec190[l232] = 0.0;
		}
		for (int l233 = 0; l233 < 2; l233 = l233 + 1) {
			fRec191[l233] = 0.0;
		}
		for (int l234 = 0; l234 < 2; l234 = l234 + 1) {
			fVec68[l234] = 0.0;
		}
		for (int l235 = 0; l235 < 4096; l235 = l235 + 1) {
			fVec69[l235] = 0.0;
		}
		for (int l236 = 0; l236 < 2; l236 = l236 + 1) {
			fRec192[l236] = 0.0;
		}
		for (int l237 = 0; l237 < 2; l237 = l237 + 1) {
			fRec193[l237] = 0.0;
		}
		for (int l238 = 0; l238 < 2; l238 = l238 + 1) {
			fRec195[l238] = 0.0;
		}
		for (int l239 = 0; l239 < 2; l239 = l239 + 1) {
			iVec70[l239] = 0;
		}
		for (int l240 = 0; l240 < 2; l240 = l240 + 1) {
			iRec196[l240] = 0;
		}
		for (int l241 = 0; l241 < 2; l241 = l241 + 1) {
			iRec197[l241] = 0;
		}
		for (int l242 = 0; l242 < 3; l242 = l242 + 1) {
			fRec198[l242] = 0.0;
		}
		for (int l243 = 0; l243 < 2; l243 = l243 + 1) {
			fRec199[l243] = 0.0;
		}
		for (int l244 = 0; l244 < 2; l244 = l244 + 1) {
			fVec71[l244] = 0.0;
		}
		for (int l245 = 0; l245 < 4096; l245 = l245 + 1) {
			fVec72[l245] = 0.0;
		}
		for (int l246 = 0; l246 < 2; l246 = l246 + 1) {
			fRec200[l246] = 0.0;
		}
		for (int l247 = 0; l247 < 2; l247 = l247 + 1) {
			fRec201[l247] = 0.0;
		}
		for (int l248 = 0; l248 < 2; l248 = l248 + 1) {
			fRec203[l248] = 0.0;
		}
		for (int l249 = 0; l249 < 2; l249 = l249 + 1) {
			iVec73[l249] = 0;
		}
		for (int l250 = 0; l250 < 2; l250 = l250 + 1) {
			iRec204[l250] = 0;
		}
		for (int l251 = 0; l251 < 2; l251 = l251 + 1) {
			iRec205[l251] = 0;
		}
		for (int l252 = 0; l252 < 2; l252 = l252 + 1) {
			fRec157[l252] = 0.0;
		}
		for (int l253 = 0; l253 < 2; l253 = l253 + 1) {
			fRec156[l253] = 0.0;
		}
		for (int l254 = 0; l254 < 2; l254 = l254 + 1) {
			fRec155[l254] = 0.0;
		}
		for (int l255 = 0; l255 < 2; l255 = l255 + 1) {
			fRec154[l255] = 0.0;
		}
		for (int l256 = 0; l256 < 2; l256 = l256 + 1) {
			fRec209[l256] = 0.0;
		}
		for (int l257 = 0; l257 < 2; l257 = l257 + 1) {
			fRec208[l257] = 0.0;
		}
		for (int l258 = 0; l258 < 2; l258 = l258 + 1) {
			fRec207[l258] = 0.0;
		}
		for (int l259 = 0; l259 < 2; l259 = l259 + 1) {
			fRec206[l259] = 0.0;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual scaleIt* clone() {
		return new scaleIt();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("scaleIt");
		ui_interface->addNumEntry("accordPan0", &fEntry38, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan1", &fEntry37, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan10", &fEntry23, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan11", &fEntry22, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan2", &fEntry35, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan3", &fEntry34, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan4", &fEntry32, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan5", &fEntry31, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan6", &fEntry29, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan7", &fEntry28, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan8", &fEntry26, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan9", &fEntry25, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("activeSteps", &fEntry8, FAUSTFLOAT(8.0), FAUSTFLOAT(0.0), FAUSTFLOAT(12.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("baseKeyMIDI", &fEntry3, FAUSTFLOAT(69.0), FAUSTFLOAT(0.0), FAUSTFLOAT(128.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("curve", &fEntry9, FAUSTFLOAT(0.0), FAUSTFLOAT(-1e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->addNumEntry("customScale0", &fEntry19, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale1", &fEntry36, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale10", &fEntry2, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale11", &fEntry21, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale2", &fEntry18, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale3", &fEntry33, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale4", &fEntry17, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale5", &fEntry30, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale6", &fEntry16, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale7", &fEntry27, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale8", &fEntry15, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale9", &fEntry24, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("envAttack", &fEntry12, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("envDecay", &fEntry13, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("envRelease", &fEntry11, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("envSustain", &fEntry14, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("gameAccordON", &fEntry39, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("gameToneON", &fEntry20, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("invert", &fEntry4, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("noiseLevel", &fEntry5, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(127.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("oscType", &fEntry6, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("playBelow", &fEntry10, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("scale", &fEntry1, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(15.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("scaleDown", &fEntry0, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("synthLevel", &fEntry7, FAUSTFLOAT(64.0), FAUSTFLOAT(0.0), FAUSTFLOAT(127.0), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		int iSlow0 = int(double(fEntry0));
		double fSlow1 = double(fEntry1);
		int iSlow2 = fSlow1 == 16.0;
		double fElse0 = double(fEntry2);
		int iSlow3 = fSlow1 < 16.0;
		int iSlow4 = (fSlow1 == 14.0) & iSlow3;
		int iSlow5 = (fSlow1 == 15.0) & iSlow3;
		int iSlow6 = (fSlow1 == 13.0) & iSlow3;
		int iSlow7 = (fSlow1 == 12.0) & iSlow3;
		int iSlow8 = (fSlow1 == 11.0) & iSlow3;
		int iSlow9 = (fSlow1 == 1e+01) & iSlow3;
		int iSlow10 = (fSlow1 == 9.0) & iSlow3;
		int iSlow11 = (fSlow1 == 8.0) & iSlow3;
		int iSlow12 = (fSlow1 == 7.0) & iSlow3;
		int iSlow13 = (fSlow1 == 6.0) & iSlow3;
		int iSlow14 = (fSlow1 == 5.0) & iSlow3;
		int iSlow15 = (fSlow1 == 4.0) & iSlow3;
		int iSlow16 = (fSlow1 == 3.0) & iSlow3;
		int iSlow17 = (fSlow1 == 2.0) & iSlow3;
		int iSlow18 = (fSlow1 == 1.0) & iSlow3;
		int iSlow19 = (fSlow1 == 0.0) & iSlow3;
		double fSlow20 = double(((iSlow19) ? iConst19 : 0) + ((iSlow18) ? iConst18 : 0) + ((iSlow17) ? iConst17 : 0) + ((iSlow16) ? iConst16 : 0) + ((iSlow15) ? iConst15 : 0) + ((iSlow14) ? iConst14 : 0) + ((iSlow13) ? iConst13 : 0) + ((iSlow12) ? iConst12 : 0) + ((iSlow11) ? iConst11 : 0) + ((iSlow10) ? iConst10 : 0) + ((iSlow9) ? iConst9 : 0) + ((iSlow8) ? iConst8 : 0) + ((iSlow7) ? iConst7 : 0) + ((iSlow6) ? iConst6 : 0) + ((iSlow5) ? iConst5 : 0) + ((iSlow4) ? iConst4 : 0)) + ((iSlow2) ? fElse0 : 0.0);
		double fSlow21 = double(fEntry3);
		double fSlow22 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow20 + -69.0));
		double fSlow23 = 4.4e+02 * fSlow22;
		double fSlow24 = double(fEntry4);
		int iSlow25 = fSlow24 == 0.0;
		double fSlow26 = fSlow21 + fSlow20;
		double fThen17 = fSlow21 - fSlow20;
		double fSlow27 = ((iSlow25) ? fSlow26 : fThen17);
		double fElse18 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow27 + -69.0));
		double fSlow28 = ((iSlow0) ? fElse18 : fSlow23);
		double fSlow29 = ((fSlow28 == 0.0) ? 1e+02 : fSlow28);
		double fSlow30 = std::tan(fConst20 * double(int(fSlow29 + 1e+01)));
		double fSlow31 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow29))) * fSlow30));
		double fSlow32 = fConst23 * fSlow30 - fConst22 * (fSlow31 / fSlow30);
		double fSlow33 = fConst24 * fSlow32;
		double fSlow34 = fConst26 * fSlow31;
		double fSlow35 = fSlow34 + fSlow33 + 4.0;
		double fSlow36 = 0.0 - fConst24 * (fSlow32 / fSlow35);
		double fSlow37 = fSlow34 + (4.0 - fSlow33);
		double fSlow38 = fConst27 * fSlow31 + -8.0;
		int iSlow39 = int(double(fEntry5));
		double fThen20 = 0.007874015748031496 * double(iSlow39);
		double fSlow40 = ((iSlow39 == 0) ? 0.0 : fThen20);
		double fSlow41 = double(fEntry6);
		int iSlow42 = fSlow41 == 3.0;
		double fSlow43 = std::max<double>(fSlow28, 23.44895);
		double fSlow44 = std::max<double>(2e+01, std::fabs(fSlow43));
		double fSlow45 = fConst25 * fSlow44;
		double fSlow46 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow43));
		int iSlow47 = int(fSlow46);
		int iSlow48 = iSlow47 + 1;
		double fSlow49 = std::floor(fSlow46);
		double fSlow50 = fSlow46 - fSlow49;
		double fSlow51 = fSlow49 + (1.0 - fSlow46);
		int iSlow52 = fSlow41 == 2.0;
		int iSlow53 = fSlow41 == 1.0;
		double fSlow54 = std::max<double>(1.1920929e-07, std::fabs(fSlow28));
		double fSlow55 = fConst25 * fSlow54;
		double fSlow56 = 1.0 - fConst0 / fSlow54;
		int iSlow57 = fSlow41 == 0.0;
		double fSlow58 = fConst25 * fSlow28;
		int iSlow59 = int(double(fEntry7));
		double fThen27 = 0.007874015748031496 * double(iSlow59);
		double fSlow60 = ((iSlow59 == 0) ? 0.0 : fThen27);
		double fSlow61 = double(fEntry8);
		int iSlow62 = 3.0 <= fSlow61;
		int iSlow63 = int(fSlow24);
		int iSlow64 = (12.0 == fSlow61) & iSlow63;
		double fSlow65 = std::pow(2.0, double(fEntry9));
		double fSlow66 = std::pow(9.0 / fSlow61, fSlow65);
		int iSlow67 = (11.0 == fSlow61) & iSlow63;
		double fSlow68 = std::pow(8.0 / fSlow61, fSlow65);
		int iSlow69 = (1e+01 == fSlow61) & iSlow63;
		double fSlow70 = std::pow(7.0 / fSlow61, fSlow65);
		int iSlow71 = (9.0 == fSlow61) & iSlow63;
		double fSlow72 = std::pow(6.0 / fSlow61, fSlow65);
		int iSlow73 = (8.0 == fSlow61) & iSlow63;
		double fSlow74 = std::pow(5.0 / fSlow61, fSlow65);
		int iSlow75 = (7.0 == fSlow61) & iSlow63;
		double fSlow76 = std::pow(4.0 / fSlow61, fSlow65);
		int iSlow77 = (6.0 == fSlow61) & iSlow63;
		double fSlow78 = std::pow(3.0 / fSlow61, fSlow65);
		int iSlow79 = (5.0 == fSlow61) & iSlow63;
		double fSlow80 = std::pow(2.0 / fSlow61, fSlow65);
		int iSlow81 = (4.0 == fSlow61) & iSlow63;
		double fSlow82 = std::pow(1.0 / fSlow61, fSlow65);
		int iSlow83 = (3.0 == fSlow61) & iSlow63;
		double fSlow84 = std::pow(0.0, fSlow65);
		double fSlow85 = double(fEntry10);
		int iSlow86 = fSlow85 == 0.0;
		int iSlow87 = fSlow85 == 1.0;
		int iSlow88 = (2.0 == fSlow61) & iSlow63;
		int iSlow89 = 1.0 <= fSlow61;
		double fSlow90 = std::pow(11.0 / fSlow61, fSlow65);
		double fSlow91 = std::pow(1e+01 / fSlow61, fSlow65);
		int iSlow92 = 5.0 <= fSlow61;
		int iSlow93 = 7.0 <= fSlow61;
		int iSlow94 = 9.0 <= fSlow61;
		int iSlow95 = 11.0 <= fSlow61;
		int iSlow96 = 4.0 <= fSlow61;
		int iSlow97 = 2.0 <= fSlow61;
		int iSlow98 = 6.0 <= fSlow61;
		int iSlow99 = 8.0 <= fSlow61;
		int iSlow100 = 1e+01 <= fSlow61;
		int iSlow101 = 12.0 <= fSlow61;
		double fSlow102 = 1.0 / std::max<double>(1.0, fConst0 * double(fEntry11));
		double fSlow103 = std::max<double>(1.0, fConst0 * double(fEntry12));
		double fSlow104 = 1.0 / fSlow103;
		double fSlow105 = double(fEntry14);
		double fSlow106 = (1.0 - fSlow105) / std::max<double>(1.0, fConst0 * double(fEntry13));
		double fElse185 = double(fEntry15);
		double fSlow107 = double(((iSlow19) ? iConst46 : 0) + ((iSlow18) ? iConst45 : 0) + ((iSlow17) ? iConst44 : 0) + ((iSlow16) ? iConst43 : 0) + ((iSlow15) ? iConst42 : 0) + ((iSlow14) ? iConst41 : 0) + ((iSlow13) ? iConst40 : 0) + ((iSlow12) ? iConst39 : 0) + ((iSlow11) ? iConst38 : 0) + ((iSlow10) ? iConst37 : 0) + ((iSlow9) ? iConst36 : 0) + ((iSlow8) ? iConst35 : 0) + ((iSlow7) ? iConst34 : 0) + ((iSlow6) ? iConst33 : 0) + ((iSlow5) ? iConst32 : 0) + ((iSlow4) ? iConst31 : 0)) + ((iSlow2) ? fElse185 : 0.0);
		double fSlow108 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow107 + -69.0));
		double fSlow109 = 4.4e+02 * fSlow108;
		double fSlow110 = fSlow21 + fSlow107;
		double fThen202 = fSlow21 - fSlow107;
		double fSlow111 = ((iSlow25) ? fSlow110 : fThen202);
		double fElse203 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow111 + -69.0));
		double fSlow112 = ((iSlow0) ? fElse203 : fSlow109);
		double fSlow113 = ((fSlow112 == 0.0) ? 1e+02 : fSlow112);
		double fSlow114 = std::tan(fConst20 * double(int(fSlow113 + 1e+01)));
		double fSlow115 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow113))) * fSlow114));
		double fSlow116 = fConst23 * fSlow114 - fConst22 * (fSlow115 / fSlow114);
		double fSlow117 = fConst24 * fSlow116;
		double fSlow118 = fConst26 * fSlow115;
		double fSlow119 = fSlow118 + fSlow117 + 4.0;
		double fSlow120 = 0.0 - fConst24 * (fSlow116 / fSlow119);
		double fSlow121 = fSlow118 + (4.0 - fSlow117);
		double fSlow122 = fConst27 * fSlow115 + -8.0;
		double fSlow123 = std::max<double>(fSlow112, 23.44895);
		double fSlow124 = std::max<double>(2e+01, std::fabs(fSlow123));
		double fSlow125 = fConst25 * fSlow124;
		double fSlow126 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow123));
		int iSlow127 = int(fSlow126);
		int iSlow128 = iSlow127 + 1;
		double fSlow129 = std::floor(fSlow126);
		double fSlow130 = fSlow126 - fSlow129;
		double fSlow131 = fSlow129 + (1.0 - fSlow126);
		double fSlow132 = std::max<double>(1.1920929e-07, std::fabs(fSlow112));
		double fSlow133 = fConst25 * fSlow132;
		double fSlow134 = 1.0 - fConst0 / fSlow132;
		double fSlow135 = fConst25 * fSlow112;
		double fElse211 = double(fEntry16);
		double fSlow136 = double(((iSlow19) ? iConst62 : 0) + ((iSlow18) ? iConst61 : 0) + ((iSlow17) ? iConst60 : 0) + ((iSlow16) ? iConst59 : 0) + ((iSlow15) ? iConst58 : 0) + ((iSlow14) ? iConst57 : 0) + ((iSlow13) ? iConst56 : 0) + ((iSlow12) ? iConst55 : 0) + ((iSlow11) ? iConst54 : 0) + ((iSlow10) ? iConst53 : 0) + ((iSlow9) ? iConst52 : 0) + ((iSlow8) ? iConst51 : 0) + ((iSlow7) ? iConst50 : 0) + ((iSlow6) ? iConst49 : 0) + ((iSlow5) ? iConst48 : 0) + ((iSlow4) ? iConst47 : 0)) + ((iSlow2) ? fElse211 : 0.0);
		double fSlow137 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow136 + -69.0));
		double fSlow138 = 4.4e+02 * fSlow137;
		double fSlow139 = fSlow21 + fSlow136;
		double fThen228 = fSlow21 - fSlow136;
		double fSlow140 = ((iSlow25) ? fSlow139 : fThen228);
		double fElse229 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow140 + -69.0));
		double fSlow141 = ((iSlow0) ? fElse229 : fSlow138);
		double fSlow142 = ((fSlow141 == 0.0) ? 1e+02 : fSlow141);
		double fSlow143 = std::tan(fConst20 * double(int(fSlow142 + 1e+01)));
		double fSlow144 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow142))) * fSlow143));
		double fSlow145 = fConst23 * fSlow143 - fConst22 * (fSlow144 / fSlow143);
		double fSlow146 = fConst24 * fSlow145;
		double fSlow147 = fConst26 * fSlow144;
		double fSlow148 = fSlow147 + fSlow146 + 4.0;
		double fSlow149 = 0.0 - fConst24 * (fSlow145 / fSlow148);
		double fSlow150 = fSlow147 + (4.0 - fSlow146);
		double fSlow151 = fConst27 * fSlow144 + -8.0;
		double fSlow152 = std::max<double>(fSlow141, 23.44895);
		double fSlow153 = std::max<double>(2e+01, std::fabs(fSlow152));
		double fSlow154 = fConst25 * fSlow153;
		double fSlow155 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow152));
		int iSlow156 = int(fSlow155);
		int iSlow157 = iSlow156 + 1;
		double fSlow158 = std::floor(fSlow155);
		double fSlow159 = fSlow155 - fSlow158;
		double fSlow160 = fSlow158 + (1.0 - fSlow155);
		double fSlow161 = std::max<double>(1.1920929e-07, std::fabs(fSlow141));
		double fSlow162 = fConst25 * fSlow161;
		double fSlow163 = 1.0 - fConst0 / fSlow161;
		double fSlow164 = fConst25 * fSlow141;
		double fElse237 = double(fEntry17);
		double fSlow165 = double(((iSlow19) ? iConst78 : 0) + ((iSlow18) ? iConst77 : 0) + ((iSlow17) ? iConst76 : 0) + ((iSlow16) ? iConst75 : 0) + ((iSlow15) ? iConst74 : 0) + ((iSlow14) ? iConst73 : 0) + ((iSlow13) ? iConst72 : 0) + ((iSlow12) ? iConst71 : 0) + ((iSlow11) ? iConst70 : 0) + ((iSlow10) ? iConst69 : 0) + ((iSlow9) ? iConst68 : 0) + ((iSlow8) ? iConst67 : 0) + ((iSlow7) ? iConst66 : 0) + ((iSlow6) ? iConst65 : 0) + ((iSlow5) ? iConst64 : 0) + ((iSlow4) ? iConst63 : 0)) + ((iSlow2) ? fElse237 : 0.0);
		double fSlow166 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow165 + -69.0));
		double fSlow167 = 4.4e+02 * fSlow166;
		double fSlow168 = fSlow21 + fSlow165;
		double fThen254 = fSlow21 - fSlow165;
		double fSlow169 = ((iSlow25) ? fSlow168 : fThen254);
		double fElse255 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow169 + -69.0));
		double fSlow170 = ((iSlow0) ? fElse255 : fSlow167);
		double fSlow171 = ((fSlow170 == 0.0) ? 1e+02 : fSlow170);
		double fSlow172 = std::tan(fConst20 * double(int(fSlow171 + 1e+01)));
		double fSlow173 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow171))) * fSlow172));
		double fSlow174 = fConst23 * fSlow172 - fConst22 * (fSlow173 / fSlow172);
		double fSlow175 = fConst24 * fSlow174;
		double fSlow176 = fConst26 * fSlow173;
		double fSlow177 = fSlow176 + fSlow175 + 4.0;
		double fSlow178 = 0.0 - fConst24 * (fSlow174 / fSlow177);
		double fSlow179 = fSlow176 + (4.0 - fSlow175);
		double fSlow180 = fConst27 * fSlow173 + -8.0;
		double fSlow181 = std::max<double>(fSlow170, 23.44895);
		double fSlow182 = std::max<double>(2e+01, std::fabs(fSlow181));
		double fSlow183 = fConst25 * fSlow182;
		double fSlow184 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow181));
		int iSlow185 = int(fSlow184);
		int iSlow186 = iSlow185 + 1;
		double fSlow187 = std::floor(fSlow184);
		double fSlow188 = fSlow184 - fSlow187;
		double fSlow189 = fSlow187 + (1.0 - fSlow184);
		double fSlow190 = std::max<double>(1.1920929e-07, std::fabs(fSlow170));
		double fSlow191 = fConst25 * fSlow190;
		double fSlow192 = 1.0 - fConst0 / fSlow190;
		double fSlow193 = fConst25 * fSlow170;
		double fElse263 = double(fEntry18);
		double fSlow194 = double(((iSlow19) ? iConst94 : 0) + ((iSlow18) ? iConst93 : 0) + ((iSlow17) ? iConst92 : 0) + ((iSlow16) ? iConst91 : 0) + ((iSlow15) ? iConst90 : 0) + ((iSlow14) ? iConst89 : 0) + ((iSlow13) ? iConst88 : 0) + ((iSlow12) ? iConst87 : 0) + ((iSlow11) ? iConst86 : 0) + ((iSlow10) ? iConst85 : 0) + ((iSlow9) ? iConst84 : 0) + ((iSlow8) ? iConst83 : 0) + ((iSlow7) ? iConst82 : 0) + ((iSlow6) ? iConst81 : 0) + ((iSlow5) ? iConst80 : 0) + ((iSlow4) ? iConst79 : 0)) + ((iSlow2) ? fElse263 : 0.0);
		double fSlow195 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow194 + -69.0));
		double fSlow196 = 4.4e+02 * fSlow195;
		double fSlow197 = fSlow21 + fSlow194;
		double fThen280 = fSlow21 - fSlow194;
		double fSlow198 = ((iSlow25) ? fSlow197 : fThen280);
		double fElse281 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow198 + -69.0));
		double fSlow199 = ((iSlow0) ? fElse281 : fSlow196);
		double fSlow200 = ((fSlow199 == 0.0) ? 1e+02 : fSlow199);
		double fSlow201 = std::tan(fConst20 * double(int(fSlow200 + 1e+01)));
		double fSlow202 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow200))) * fSlow201));
		double fSlow203 = fConst23 * fSlow201 - fConst22 * (fSlow202 / fSlow201);
		double fSlow204 = fConst24 * fSlow203;
		double fSlow205 = fConst26 * fSlow202;
		double fSlow206 = fSlow205 + fSlow204 + 4.0;
		double fSlow207 = 0.0 - fConst24 * (fSlow203 / fSlow206);
		double fSlow208 = fSlow205 + (4.0 - fSlow204);
		double fSlow209 = fConst27 * fSlow202 + -8.0;
		double fSlow210 = std::max<double>(fSlow199, 23.44895);
		double fSlow211 = std::max<double>(2e+01, std::fabs(fSlow210));
		double fSlow212 = fConst25 * fSlow211;
		double fSlow213 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow210));
		int iSlow214 = int(fSlow213);
		int iSlow215 = iSlow214 + 1;
		double fSlow216 = std::floor(fSlow213);
		double fSlow217 = fSlow213 - fSlow216;
		double fSlow218 = fSlow216 + (1.0 - fSlow213);
		double fSlow219 = std::max<double>(1.1920929e-07, std::fabs(fSlow199));
		double fSlow220 = fConst25 * fSlow219;
		double fSlow221 = 1.0 - fConst0 / fSlow219;
		double fSlow222 = fConst25 * fSlow199;
		double fElse289 = double(fEntry19);
		double fSlow223 = double(((iSlow19) ? iConst110 : 0) + ((iSlow18) ? iConst109 : 0) + ((iSlow17) ? iConst108 : 0) + ((iSlow16) ? iConst107 : 0) + ((iSlow15) ? iConst106 : 0) + ((iSlow14) ? iConst105 : 0) + ((iSlow13) ? iConst104 : 0) + ((iSlow12) ? iConst103 : 0) + ((iSlow11) ? iConst102 : 0) + ((iSlow10) ? iConst101 : 0) + ((iSlow9) ? iConst100 : 0) + ((iSlow8) ? iConst99 : 0) + ((iSlow7) ? iConst98 : 0) + ((iSlow6) ? iConst97 : 0) + ((iSlow5) ? iConst96 : 0) + ((iSlow4) ? iConst95 : 0)) + ((iSlow2) ? fElse289 : 0.0);
		double fSlow224 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow223 + -69.0));
		double fSlow225 = 4.4e+02 * fSlow224;
		double fSlow226 = fSlow21 + fSlow223;
		double fThen306 = fSlow21 - fSlow223;
		double fSlow227 = ((iSlow25) ? fSlow226 : fThen306);
		double fElse307 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow227 + -69.0));
		double fSlow228 = ((iSlow0) ? fElse307 : fSlow225);
		double fSlow229 = ((fSlow228 == 0.0) ? 1e+02 : fSlow228);
		double fSlow230 = std::tan(fConst20 * double(int(fSlow229 + 1e+01)));
		double fSlow231 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow229))) * fSlow230));
		double fSlow232 = fConst23 * fSlow230 - fConst22 * (fSlow231 / fSlow230);
		double fSlow233 = fConst24 * fSlow232;
		double fSlow234 = fConst26 * fSlow231;
		double fSlow235 = fSlow234 + fSlow233 + 4.0;
		double fSlow236 = 0.0 - fConst24 * (fSlow232 / fSlow235);
		double fSlow237 = fSlow234 + (4.0 - fSlow233);
		double fSlow238 = fConst27 * fSlow231 + -8.0;
		double fSlow239 = std::max<double>(fSlow228, 23.44895);
		double fSlow240 = std::max<double>(2e+01, std::fabs(fSlow239));
		double fSlow241 = fConst25 * fSlow240;
		double fSlow242 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow239));
		int iSlow243 = int(fSlow242);
		int iSlow244 = iSlow243 + 1;
		double fSlow245 = std::floor(fSlow242);
		double fSlow246 = fSlow242 - fSlow245;
		double fSlow247 = fSlow245 + (1.0 - fSlow242);
		double fSlow248 = std::max<double>(1.1920929e-07, std::fabs(fSlow228));
		double fSlow249 = fConst25 * fSlow248;
		double fSlow250 = 1.0 - fConst0 / fSlow248;
		double fSlow251 = fConst25 * fSlow228;
		double fSlow252 = double(fEntry20);
		double fElse316 = double(fEntry21);
		double fSlow253 = double(((iSlow19) ? iConst131 : 0) + ((iSlow18) ? iConst130 : 0) + ((iSlow17) ? iConst129 : 0) + ((iSlow16) ? iConst128 : 0) + ((iSlow15) ? iConst127 : 0) + ((iSlow14) ? iConst126 : 0) + ((iSlow13) ? iConst125 : 0) + ((iSlow12) ? iConst124 : 0) + ((iSlow11) ? iConst123 : 0) + ((iSlow10) ? iConst122 : 0) + ((iSlow9) ? iConst121 : 0) + ((iSlow8) ? iConst120 : 0) + ((iSlow7) ? iConst119 : 0) + ((iSlow6) ? iConst118 : 0) + ((iSlow5) ? iConst117 : 0) + ((iSlow4) ? iConst116 : 0)) + ((iSlow2) ? fElse316 : 0.0);
		double fSlow254 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow253 + -69.0));
		double fSlow255 = 4.4e+02 * fSlow254;
		double fSlow256 = ((fSlow255 == 0.0) ? 1e+02 : fSlow255);
		double fSlow257 = std::tan(fConst20 * double(int(fSlow256 + 1e+01)));
		double fSlow258 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow256))) * fSlow257));
		double fSlow259 = fConst23 * fSlow257 - fConst22 * (fSlow258 / fSlow257);
		double fSlow260 = fConst24 * fSlow259;
		double fSlow261 = fConst26 * fSlow258;
		double fSlow262 = fSlow261 + fSlow260 + 4.0;
		double fSlow263 = 0.0 - fConst24 * (fSlow259 / fSlow262);
		double fSlow264 = fSlow261 + (4.0 - fSlow260);
		double fSlow265 = fConst27 * fSlow258 + -8.0;
		double fSlow266 = std::max<double>(fSlow255, 23.44895);
		double fSlow267 = std::max<double>(2e+01, std::fabs(fSlow266));
		double fSlow268 = fConst25 * fSlow267;
		double fSlow269 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow266));
		int iSlow270 = int(fSlow269);
		int iSlow271 = iSlow270 + 1;
		double fSlow272 = std::floor(fSlow269);
		double fSlow273 = fSlow269 - fSlow272;
		double fSlow274 = fSlow272 + (1.0 - fSlow269);
		double fSlow275 = std::max<double>(1.1920929e-07, std::fabs(fSlow255));
		double fSlow276 = fConst25 * fSlow275;
		double fSlow277 = 1.0 - fConst0 / fSlow275;
		double fSlow278 = fConst133 * fSlow254;
		double fSlow279 = double(fEntry22);
		double fSlow280 = 1.0 - fSlow279;
		double fSlow281 = ((fSlow23 == 0.0) ? 1e+02 : fSlow23);
		double fSlow282 = std::tan(fConst20 * double(int(fSlow281 + 1e+01)));
		double fSlow283 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow281))) * fSlow282));
		double fSlow284 = fConst23 * fSlow282 - fConst22 * (fSlow283 / fSlow282);
		double fSlow285 = fConst24 * fSlow284;
		double fSlow286 = fConst26 * fSlow283;
		double fSlow287 = fSlow286 + fSlow285 + 4.0;
		double fSlow288 = 0.0 - fConst24 * (fSlow284 / fSlow287);
		double fSlow289 = fSlow286 + (4.0 - fSlow285);
		double fSlow290 = fConst27 * fSlow283 + -8.0;
		double fSlow291 = std::max<double>(fSlow23, 23.44895);
		double fSlow292 = std::max<double>(2e+01, std::fabs(fSlow291));
		double fSlow293 = fConst25 * fSlow292;
		double fSlow294 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow291));
		int iSlow295 = int(fSlow294);
		int iSlow296 = iSlow295 + 1;
		double fSlow297 = std::floor(fSlow294);
		double fSlow298 = fSlow294 - fSlow297;
		double fSlow299 = fSlow297 + (1.0 - fSlow294);
		double fSlow300 = std::max<double>(1.1920929e-07, std::fabs(fSlow23));
		double fSlow301 = fConst25 * fSlow300;
		double fSlow302 = 1.0 - fConst0 / fSlow300;
		double fSlow303 = fConst133 * fSlow22;
		double fSlow304 = double(fEntry23);
		double fSlow305 = 1.0 - fSlow304;
		double fElse347 = double(fEntry24);
		double fSlow306 = double(((iSlow19) ? iConst149 : 0) + ((iSlow18) ? iConst148 : 0) + ((iSlow17) ? iConst147 : 0) + ((iSlow16) ? iConst146 : 0) + ((iSlow15) ? iConst145 : 0) + ((iSlow14) ? iConst144 : 0) + ((iSlow13) ? iConst143 : 0) + ((iSlow12) ? iConst142 : 0) + ((iSlow11) ? iConst141 : 0) + ((iSlow10) ? iConst140 : 0) + ((iSlow9) ? iConst139 : 0) + ((iSlow8) ? iConst138 : 0) + ((iSlow7) ? iConst137 : 0) + ((iSlow6) ? iConst136 : 0) + ((iSlow5) ? iConst135 : 0) + ((iSlow4) ? iConst134 : 0)) + ((iSlow2) ? fElse347 : 0.0);
		double fSlow307 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow306 + -69.0));
		double fSlow308 = 4.4e+02 * fSlow307;
		double fSlow309 = ((fSlow308 == 0.0) ? 1e+02 : fSlow308);
		double fSlow310 = std::tan(fConst20 * double(int(fSlow309 + 1e+01)));
		double fSlow311 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow309))) * fSlow310));
		double fSlow312 = fConst23 * fSlow310 - fConst22 * (fSlow311 / fSlow310);
		double fSlow313 = fConst24 * fSlow312;
		double fSlow314 = fConst26 * fSlow311;
		double fSlow315 = fSlow314 + fSlow313 + 4.0;
		double fSlow316 = 0.0 - fConst24 * (fSlow312 / fSlow315);
		double fSlow317 = fSlow314 + (4.0 - fSlow313);
		double fSlow318 = fConst27 * fSlow311 + -8.0;
		double fSlow319 = std::max<double>(fSlow308, 23.44895);
		double fSlow320 = std::max<double>(2e+01, std::fabs(fSlow319));
		double fSlow321 = fConst25 * fSlow320;
		double fSlow322 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow319));
		int iSlow323 = int(fSlow322);
		int iSlow324 = iSlow323 + 1;
		double fSlow325 = std::floor(fSlow322);
		double fSlow326 = fSlow322 - fSlow325;
		double fSlow327 = fSlow325 + (1.0 - fSlow322);
		double fSlow328 = std::max<double>(1.1920929e-07, std::fabs(fSlow308));
		double fSlow329 = fConst25 * fSlow328;
		double fSlow330 = 1.0 - fConst0 / fSlow328;
		double fSlow331 = fConst133 * fSlow307;
		double fSlow332 = double(fEntry25);
		double fSlow333 = 1.0 - fSlow332;
		double fSlow334 = ((fSlow109 == 0.0) ? 1e+02 : fSlow109);
		double fSlow335 = std::tan(fConst20 * double(int(fSlow334 + 1e+01)));
		double fSlow336 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow334))) * fSlow335));
		double fSlow337 = fConst23 * fSlow335 - fConst22 * (fSlow336 / fSlow335);
		double fSlow338 = fConst24 * fSlow337;
		double fSlow339 = fConst26 * fSlow336;
		double fSlow340 = fSlow339 + fSlow338 + 4.0;
		double fSlow341 = 0.0 - fConst24 * (fSlow337 / fSlow340);
		double fSlow342 = fSlow339 + (4.0 - fSlow338);
		double fSlow343 = fConst27 * fSlow336 + -8.0;
		double fSlow344 = std::max<double>(fSlow109, 23.44895);
		double fSlow345 = std::max<double>(2e+01, std::fabs(fSlow344));
		double fSlow346 = fConst25 * fSlow345;
		double fSlow347 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow344));
		int iSlow348 = int(fSlow347);
		int iSlow349 = iSlow348 + 1;
		double fSlow350 = std::floor(fSlow347);
		double fSlow351 = fSlow347 - fSlow350;
		double fSlow352 = fSlow350 + (1.0 - fSlow347);
		double fSlow353 = std::max<double>(1.1920929e-07, std::fabs(fSlow109));
		double fSlow354 = fConst25 * fSlow353;
		double fSlow355 = 1.0 - fConst0 / fSlow353;
		double fSlow356 = fConst133 * fSlow108;
		double fSlow357 = double(fEntry26);
		double fSlow358 = 1.0 - fSlow357;
		double fElse378 = double(fEntry27);
		double fSlow359 = double(((iSlow19) ? iConst165 : 0) + ((iSlow18) ? iConst164 : 0) + ((iSlow17) ? iConst163 : 0) + ((iSlow16) ? iConst162 : 0) + ((iSlow15) ? iConst161 : 0) + ((iSlow14) ? iConst160 : 0) + ((iSlow13) ? iConst159 : 0) + ((iSlow12) ? iConst158 : 0) + ((iSlow11) ? iConst157 : 0) + ((iSlow10) ? iConst156 : 0) + ((iSlow9) ? iConst155 : 0) + ((iSlow8) ? iConst154 : 0) + ((iSlow7) ? iConst153 : 0) + ((iSlow6) ? iConst152 : 0) + ((iSlow5) ? iConst151 : 0) + ((iSlow4) ? iConst150 : 0)) + ((iSlow2) ? fElse378 : 0.0);
		double fSlow360 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow359 + -69.0));
		double fSlow361 = 4.4e+02 * fSlow360;
		double fSlow362 = ((fSlow361 == 0.0) ? 1e+02 : fSlow361);
		double fSlow363 = std::tan(fConst20 * double(int(fSlow362 + 1e+01)));
		double fSlow364 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow362))) * fSlow363));
		double fSlow365 = fConst23 * fSlow363 - fConst22 * (fSlow364 / fSlow363);
		double fSlow366 = fConst24 * fSlow365;
		double fSlow367 = fConst26 * fSlow364;
		double fSlow368 = fSlow367 + fSlow366 + 4.0;
		double fSlow369 = 0.0 - fConst24 * (fSlow365 / fSlow368);
		double fSlow370 = fSlow367 + (4.0 - fSlow366);
		double fSlow371 = fConst27 * fSlow364 + -8.0;
		double fSlow372 = std::max<double>(fSlow361, 23.44895);
		double fSlow373 = std::max<double>(2e+01, std::fabs(fSlow372));
		double fSlow374 = fConst25 * fSlow373;
		double fSlow375 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow372));
		int iSlow376 = int(fSlow375);
		int iSlow377 = iSlow376 + 1;
		double fSlow378 = std::floor(fSlow375);
		double fSlow379 = fSlow375 - fSlow378;
		double fSlow380 = fSlow378 + (1.0 - fSlow375);
		double fSlow381 = std::max<double>(1.1920929e-07, std::fabs(fSlow361));
		double fSlow382 = fConst25 * fSlow381;
		double fSlow383 = 1.0 - fConst0 / fSlow381;
		double fSlow384 = fConst133 * fSlow360;
		double fSlow385 = double(fEntry28);
		double fSlow386 = 1.0 - fSlow385;
		double fSlow387 = ((fSlow138 == 0.0) ? 1e+02 : fSlow138);
		double fSlow388 = std::tan(fConst20 * double(int(fSlow387 + 1e+01)));
		double fSlow389 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow387))) * fSlow388));
		double fSlow390 = fConst23 * fSlow388 - fConst22 * (fSlow389 / fSlow388);
		double fSlow391 = fConst24 * fSlow390;
		double fSlow392 = fConst26 * fSlow389;
		double fSlow393 = fSlow392 + fSlow391 + 4.0;
		double fSlow394 = 0.0 - fConst24 * (fSlow390 / fSlow393);
		double fSlow395 = fSlow392 + (4.0 - fSlow391);
		double fSlow396 = fConst27 * fSlow389 + -8.0;
		double fSlow397 = std::max<double>(fSlow138, 23.44895);
		double fSlow398 = std::max<double>(2e+01, std::fabs(fSlow397));
		double fSlow399 = fConst25 * fSlow398;
		double fSlow400 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow397));
		int iSlow401 = int(fSlow400);
		int iSlow402 = iSlow401 + 1;
		double fSlow403 = std::floor(fSlow400);
		double fSlow404 = fSlow400 - fSlow403;
		double fSlow405 = fSlow403 + (1.0 - fSlow400);
		double fSlow406 = std::max<double>(1.1920929e-07, std::fabs(fSlow138));
		double fSlow407 = fConst25 * fSlow406;
		double fSlow408 = 1.0 - fConst0 / fSlow406;
		double fSlow409 = fConst133 * fSlow137;
		double fSlow410 = double(fEntry29);
		double fSlow411 = 1.0 - fSlow410;
		double fElse409 = double(fEntry30);
		double fSlow412 = double(((iSlow19) ? iConst181 : 0) + ((iSlow18) ? iConst180 : 0) + ((iSlow17) ? iConst179 : 0) + ((iSlow16) ? iConst178 : 0) + ((iSlow15) ? iConst177 : 0) + ((iSlow14) ? iConst176 : 0) + ((iSlow13) ? iConst175 : 0) + ((iSlow12) ? iConst174 : 0) + ((iSlow11) ? iConst173 : 0) + ((iSlow10) ? iConst172 : 0) + ((iSlow9) ? iConst171 : 0) + ((iSlow8) ? iConst170 : 0) + ((iSlow7) ? iConst169 : 0) + ((iSlow6) ? iConst168 : 0) + ((iSlow5) ? iConst167 : 0) + ((iSlow4) ? iConst166 : 0)) + ((iSlow2) ? fElse409 : 0.0);
		double fSlow413 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow412 + -69.0));
		double fSlow414 = 4.4e+02 * fSlow413;
		double fSlow415 = ((fSlow414 == 0.0) ? 1e+02 : fSlow414);
		double fSlow416 = std::tan(fConst20 * double(int(fSlow415 + 1e+01)));
		double fSlow417 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow415))) * fSlow416));
		double fSlow418 = fConst23 * fSlow416 - fConst22 * (fSlow417 / fSlow416);
		double fSlow419 = fConst24 * fSlow418;
		double fSlow420 = fConst26 * fSlow417;
		double fSlow421 = fSlow420 + fSlow419 + 4.0;
		double fSlow422 = 0.0 - fConst24 * (fSlow418 / fSlow421);
		double fSlow423 = fSlow420 + (4.0 - fSlow419);
		double fSlow424 = fConst27 * fSlow417 + -8.0;
		double fSlow425 = std::max<double>(fSlow414, 23.44895);
		double fSlow426 = std::max<double>(2e+01, std::fabs(fSlow425));
		double fSlow427 = fConst25 * fSlow426;
		double fSlow428 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow425));
		int iSlow429 = int(fSlow428);
		int iSlow430 = iSlow429 + 1;
		double fSlow431 = std::floor(fSlow428);
		double fSlow432 = fSlow428 - fSlow431;
		double fSlow433 = fSlow431 + (1.0 - fSlow428);
		double fSlow434 = std::max<double>(1.1920929e-07, std::fabs(fSlow414));
		double fSlow435 = fConst25 * fSlow434;
		double fSlow436 = 1.0 - fConst0 / fSlow434;
		double fSlow437 = fConst133 * fSlow413;
		double fSlow438 = double(fEntry31);
		double fSlow439 = 1.0 - fSlow438;
		double fSlow440 = ((fSlow167 == 0.0) ? 1e+02 : fSlow167);
		double fSlow441 = std::tan(fConst20 * double(int(fSlow440 + 1e+01)));
		double fSlow442 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow440))) * fSlow441));
		double fSlow443 = fConst23 * fSlow441 - fConst22 * (fSlow442 / fSlow441);
		double fSlow444 = fConst24 * fSlow443;
		double fSlow445 = fConst26 * fSlow442;
		double fSlow446 = fSlow445 + fSlow444 + 4.0;
		double fSlow447 = 0.0 - fConst24 * (fSlow443 / fSlow446);
		double fSlow448 = fSlow445 + (4.0 - fSlow444);
		double fSlow449 = fConst27 * fSlow442 + -8.0;
		double fSlow450 = std::max<double>(fSlow167, 23.44895);
		double fSlow451 = std::max<double>(2e+01, std::fabs(fSlow450));
		double fSlow452 = fConst25 * fSlow451;
		double fSlow453 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow450));
		int iSlow454 = int(fSlow453);
		int iSlow455 = iSlow454 + 1;
		double fSlow456 = std::floor(fSlow453);
		double fSlow457 = fSlow453 - fSlow456;
		double fSlow458 = fSlow456 + (1.0 - fSlow453);
		double fSlow459 = std::max<double>(1.1920929e-07, std::fabs(fSlow167));
		double fSlow460 = fConst25 * fSlow459;
		double fSlow461 = 1.0 - fConst0 / fSlow459;
		double fSlow462 = fConst133 * fSlow166;
		double fSlow463 = double(fEntry32);
		double fSlow464 = 1.0 - fSlow463;
		double fElse440 = double(fEntry33);
		double fSlow465 = double(((iSlow19) ? iConst197 : 0) + ((iSlow18) ? iConst196 : 0) + ((iSlow17) ? iConst195 : 0) + ((iSlow16) ? iConst194 : 0) + ((iSlow15) ? iConst193 : 0) + ((iSlow14) ? iConst192 : 0) + ((iSlow13) ? iConst191 : 0) + ((iSlow12) ? iConst190 : 0) + ((iSlow11) ? iConst189 : 0) + ((iSlow10) ? iConst188 : 0) + ((iSlow9) ? iConst187 : 0) + ((iSlow8) ? iConst186 : 0) + ((iSlow7) ? iConst185 : 0) + ((iSlow6) ? iConst184 : 0) + ((iSlow5) ? iConst183 : 0) + ((iSlow4) ? iConst182 : 0)) + ((iSlow2) ? fElse440 : 0.0);
		double fSlow466 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow465 + -69.0));
		double fSlow467 = 4.4e+02 * fSlow466;
		double fSlow468 = ((fSlow467 == 0.0) ? 1e+02 : fSlow467);
		double fSlow469 = std::tan(fConst20 * double(int(fSlow468 + 1e+01)));
		double fSlow470 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow468))) * fSlow469));
		double fSlow471 = fConst23 * fSlow469 - fConst22 * (fSlow470 / fSlow469);
		double fSlow472 = fConst24 * fSlow471;
		double fSlow473 = fConst26 * fSlow470;
		double fSlow474 = fSlow473 + fSlow472 + 4.0;
		double fSlow475 = 0.0 - fConst24 * (fSlow471 / fSlow474);
		double fSlow476 = fSlow473 + (4.0 - fSlow472);
		double fSlow477 = fConst27 * fSlow470 + -8.0;
		double fSlow478 = std::max<double>(fSlow467, 23.44895);
		double fSlow479 = std::max<double>(2e+01, std::fabs(fSlow478));
		double fSlow480 = fConst25 * fSlow479;
		double fSlow481 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow478));
		int iSlow482 = int(fSlow481);
		int iSlow483 = iSlow482 + 1;
		double fSlow484 = std::floor(fSlow481);
		double fSlow485 = fSlow481 - fSlow484;
		double fSlow486 = fSlow484 + (1.0 - fSlow481);
		double fSlow487 = std::max<double>(1.1920929e-07, std::fabs(fSlow467));
		double fSlow488 = fConst25 * fSlow487;
		double fSlow489 = 1.0 - fConst0 / fSlow487;
		double fSlow490 = fConst133 * fSlow466;
		double fSlow491 = double(fEntry34);
		double fSlow492 = 1.0 - fSlow491;
		double fSlow493 = ((fSlow196 == 0.0) ? 1e+02 : fSlow196);
		double fSlow494 = std::tan(fConst20 * double(int(fSlow493 + 1e+01)));
		double fSlow495 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow493))) * fSlow494));
		double fSlow496 = fConst23 * fSlow494 - fConst22 * (fSlow495 / fSlow494);
		double fSlow497 = fConst24 * fSlow496;
		double fSlow498 = fConst26 * fSlow495;
		double fSlow499 = fSlow498 + fSlow497 + 4.0;
		double fSlow500 = 0.0 - fConst24 * (fSlow496 / fSlow499);
		double fSlow501 = fSlow498 + (4.0 - fSlow497);
		double fSlow502 = fConst27 * fSlow495 + -8.0;
		double fSlow503 = std::max<double>(fSlow196, 23.44895);
		double fSlow504 = std::max<double>(2e+01, std::fabs(fSlow503));
		double fSlow505 = fConst25 * fSlow504;
		double fSlow506 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow503));
		int iSlow507 = int(fSlow506);
		int iSlow508 = iSlow507 + 1;
		double fSlow509 = std::floor(fSlow506);
		double fSlow510 = fSlow506 - fSlow509;
		double fSlow511 = fSlow509 + (1.0 - fSlow506);
		double fSlow512 = std::max<double>(1.1920929e-07, std::fabs(fSlow196));
		double fSlow513 = fConst25 * fSlow512;
		double fSlow514 = 1.0 - fConst0 / fSlow512;
		double fSlow515 = fConst133 * fSlow195;
		double fSlow516 = double(fEntry35);
		double fSlow517 = 1.0 - fSlow516;
		double fElse471 = double(fEntry36);
		double fSlow518 = double(((iSlow19) ? iConst213 : 0) + ((iSlow18) ? iConst212 : 0) + ((iSlow17) ? iConst211 : 0) + ((iSlow16) ? iConst210 : 0) + ((iSlow15) ? iConst209 : 0) + ((iSlow14) ? iConst208 : 0) + ((iSlow13) ? iConst207 : 0) + ((iSlow12) ? iConst206 : 0) + ((iSlow11) ? iConst205 : 0) + ((iSlow10) ? iConst204 : 0) + ((iSlow9) ? iConst203 : 0) + ((iSlow8) ? iConst202 : 0) + ((iSlow7) ? iConst201 : 0) + ((iSlow6) ? iConst200 : 0) + ((iSlow5) ? iConst199 : 0) + ((iSlow4) ? iConst198 : 0)) + ((iSlow2) ? fElse471 : 0.0);
		double fSlow519 = std::pow(2.0, 0.08333333333333333 * (fSlow21 + fSlow518 + -69.0));
		double fSlow520 = 4.4e+02 * fSlow519;
		double fSlow521 = ((fSlow520 == 0.0) ? 1e+02 : fSlow520);
		double fSlow522 = std::tan(fConst20 * double(int(fSlow521 + 1e+01)));
		double fSlow523 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow521))) * fSlow522));
		double fSlow524 = fConst23 * fSlow522 - fConst22 * (fSlow523 / fSlow522);
		double fSlow525 = fConst24 * fSlow524;
		double fSlow526 = fConst26 * fSlow523;
		double fSlow527 = fSlow526 + fSlow525 + 4.0;
		double fSlow528 = 0.0 - fConst24 * (fSlow524 / fSlow527);
		double fSlow529 = fSlow526 + (4.0 - fSlow525);
		double fSlow530 = fConst27 * fSlow523 + -8.0;
		double fSlow531 = std::max<double>(fSlow520, 23.44895);
		double fSlow532 = std::max<double>(2e+01, std::fabs(fSlow531));
		double fSlow533 = fConst25 * fSlow532;
		double fSlow534 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow531));
		int iSlow535 = int(fSlow534);
		int iSlow536 = iSlow535 + 1;
		double fSlow537 = std::floor(fSlow534);
		double fSlow538 = fSlow534 - fSlow537;
		double fSlow539 = fSlow537 + (1.0 - fSlow534);
		double fSlow540 = std::max<double>(1.1920929e-07, std::fabs(fSlow520));
		double fSlow541 = fConst25 * fSlow540;
		double fSlow542 = 1.0 - fConst0 / fSlow540;
		double fSlow543 = fConst133 * fSlow519;
		double fSlow544 = double(fEntry37);
		double fSlow545 = 1.0 - fSlow544;
		double fSlow546 = std::max<double>(fSlow225, 23.44895);
		double fSlow547 = std::max<double>(2e+01, std::fabs(fSlow546));
		double fSlow548 = fConst25 * fSlow547;
		double fSlow549 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow546));
		int iSlow550 = int(fSlow549);
		int iSlow551 = iSlow550 + 1;
		double fSlow552 = std::floor(fSlow549);
		double fSlow553 = fSlow549 - fSlow552;
		double fSlow554 = fSlow552 + (1.0 - fSlow549);
		double fSlow555 = std::max<double>(1.1920929e-07, std::fabs(fSlow225));
		double fSlow556 = fConst25 * fSlow555;
		double fSlow557 = 1.0 - fConst0 / fSlow555;
		double fSlow558 = fConst133 * fSlow224;
		double fSlow559 = double(fEntry38);
		double fSlow560 = 1.0 - fSlow559;
		double fSlow561 = ((fSlow225 == 0.0) ? 1e+02 : fSlow225);
		double fSlow562 = std::tan(fConst20 * double(int(fSlow561 + 1e+01)));
		double fSlow563 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow561))) * fSlow562));
		double fSlow564 = fConst23 * fSlow562 - fConst22 * (fSlow563 / fSlow562);
		double fSlow565 = fConst24 * fSlow564;
		double fSlow566 = fConst26 * fSlow563;
		double fSlow567 = fSlow566 + fSlow565 + 4.0;
		double fSlow568 = 0.0 - fConst24 * (fSlow564 / fSlow567);
		double fSlow569 = fSlow566 + (4.0 - fSlow565);
		double fSlow570 = fConst27 * fSlow563 + -8.0;
		double fSlow571 = 0.5 * double(fEntry39);
		double fSlow572 = fSlow21 + fSlow253;
		double fThen503 = fSlow21 - fSlow253;
		double fSlow573 = ((iSlow25) ? fSlow572 : fThen503);
		double fElse504 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow573 + -69.0));
		double fSlow574 = ((iSlow0) ? fElse504 : fSlow255);
		double fSlow575 = ((fSlow574 == 0.0) ? 1e+02 : fSlow574);
		double fSlow576 = std::tan(fConst20 * double(int(fSlow575 + 1e+01)));
		double fSlow577 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow575))) * fSlow576));
		double fSlow578 = fConst23 * fSlow576 - fConst22 * (fSlow577 / fSlow576);
		double fSlow579 = fConst24 * fSlow578;
		double fSlow580 = fConst26 * fSlow577;
		double fSlow581 = fSlow580 + fSlow579 + 4.0;
		double fSlow582 = 0.0 - fConst24 * (fSlow578 / fSlow581);
		double fSlow583 = fSlow580 + (4.0 - fSlow579);
		double fSlow584 = fConst27 * fSlow577 + -8.0;
		double fSlow585 = std::max<double>(fSlow574, 23.44895);
		double fSlow586 = std::max<double>(2e+01, std::fabs(fSlow585));
		double fSlow587 = fConst25 * fSlow586;
		double fSlow588 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow585));
		int iSlow589 = int(fSlow588);
		int iSlow590 = iSlow589 + 1;
		double fSlow591 = std::floor(fSlow588);
		double fSlow592 = fSlow588 - fSlow591;
		double fSlow593 = fSlow591 + (1.0 - fSlow588);
		double fSlow594 = std::max<double>(1.1920929e-07, std::fabs(fSlow574));
		double fSlow595 = fConst25 * fSlow594;
		double fSlow596 = 1.0 - fConst0 / fSlow594;
		double fSlow597 = fConst25 * fSlow574;
		double fSlow598 = fSlow21 + fSlow306;
		double fThen512 = fSlow21 - fSlow306;
		double fSlow599 = ((iSlow25) ? fSlow598 : fThen512);
		double fElse513 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow599 + -69.0));
		double fSlow600 = ((iSlow0) ? fElse513 : fSlow308);
		double fSlow601 = ((fSlow600 == 0.0) ? 1e+02 : fSlow600);
		double fSlow602 = std::tan(fConst20 * double(int(fSlow601 + 1e+01)));
		double fSlow603 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow601))) * fSlow602));
		double fSlow604 = fConst23 * fSlow602 - fConst22 * (fSlow603 / fSlow602);
		double fSlow605 = fConst24 * fSlow604;
		double fSlow606 = fConst26 * fSlow603;
		double fSlow607 = fSlow606 + fSlow605 + 4.0;
		double fSlow608 = 0.0 - fConst24 * (fSlow604 / fSlow607);
		double fSlow609 = fSlow606 + (4.0 - fSlow605);
		double fSlow610 = fConst27 * fSlow603 + -8.0;
		double fSlow611 = std::max<double>(fSlow600, 23.44895);
		double fSlow612 = std::max<double>(2e+01, std::fabs(fSlow611));
		double fSlow613 = fConst25 * fSlow612;
		double fSlow614 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow611));
		int iSlow615 = int(fSlow614);
		int iSlow616 = iSlow615 + 1;
		double fSlow617 = std::floor(fSlow614);
		double fSlow618 = fSlow614 - fSlow617;
		double fSlow619 = fSlow617 + (1.0 - fSlow614);
		double fSlow620 = std::max<double>(1.1920929e-07, std::fabs(fSlow600));
		double fSlow621 = fConst25 * fSlow620;
		double fSlow622 = 1.0 - fConst0 / fSlow620;
		double fSlow623 = fConst25 * fSlow600;
		double fSlow624 = fSlow21 + fSlow359;
		double fThen521 = fSlow21 - fSlow359;
		double fSlow625 = ((iSlow25) ? fSlow624 : fThen521);
		double fElse522 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow625 + -69.0));
		double fSlow626 = ((iSlow0) ? fElse522 : fSlow361);
		double fSlow627 = ((fSlow626 == 0.0) ? 1e+02 : fSlow626);
		double fSlow628 = std::tan(fConst20 * double(int(fSlow627 + 1e+01)));
		double fSlow629 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow627))) * fSlow628));
		double fSlow630 = fConst23 * fSlow628 - fConst22 * (fSlow629 / fSlow628);
		double fSlow631 = fConst24 * fSlow630;
		double fSlow632 = fConst26 * fSlow629;
		double fSlow633 = fSlow632 + fSlow631 + 4.0;
		double fSlow634 = 0.0 - fConst24 * (fSlow630 / fSlow633);
		double fSlow635 = fSlow632 + (4.0 - fSlow631);
		double fSlow636 = fConst27 * fSlow629 + -8.0;
		double fSlow637 = std::max<double>(fSlow626, 23.44895);
		double fSlow638 = std::max<double>(2e+01, std::fabs(fSlow637));
		double fSlow639 = fConst25 * fSlow638;
		double fSlow640 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow637));
		int iSlow641 = int(fSlow640);
		int iSlow642 = iSlow641 + 1;
		double fSlow643 = std::floor(fSlow640);
		double fSlow644 = fSlow640 - fSlow643;
		double fSlow645 = fSlow643 + (1.0 - fSlow640);
		double fSlow646 = std::max<double>(1.1920929e-07, std::fabs(fSlow626));
		double fSlow647 = fConst25 * fSlow646;
		double fSlow648 = 1.0 - fConst0 / fSlow646;
		double fSlow649 = fConst25 * fSlow626;
		double fSlow650 = fSlow21 + fSlow412;
		double fThen530 = fSlow21 - fSlow412;
		double fSlow651 = ((iSlow25) ? fSlow650 : fThen530);
		double fElse531 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow651 + -69.0));
		double fSlow652 = ((iSlow0) ? fElse531 : fSlow414);
		double fSlow653 = ((fSlow652 == 0.0) ? 1e+02 : fSlow652);
		double fSlow654 = std::tan(fConst20 * double(int(fSlow653 + 1e+01)));
		double fSlow655 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow653))) * fSlow654));
		double fSlow656 = fConst23 * fSlow654 - fConst22 * (fSlow655 / fSlow654);
		double fSlow657 = fConst24 * fSlow656;
		double fSlow658 = fConst26 * fSlow655;
		double fSlow659 = fSlow658 + fSlow657 + 4.0;
		double fSlow660 = 0.0 - fConst24 * (fSlow656 / fSlow659);
		double fSlow661 = fSlow658 + (4.0 - fSlow657);
		double fSlow662 = fConst27 * fSlow655 + -8.0;
		double fSlow663 = std::max<double>(fSlow652, 23.44895);
		double fSlow664 = std::max<double>(2e+01, std::fabs(fSlow663));
		double fSlow665 = fConst25 * fSlow664;
		double fSlow666 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow663));
		int iSlow667 = int(fSlow666);
		int iSlow668 = iSlow667 + 1;
		double fSlow669 = std::floor(fSlow666);
		double fSlow670 = fSlow666 - fSlow669;
		double fSlow671 = fSlow669 + (1.0 - fSlow666);
		double fSlow672 = std::max<double>(1.1920929e-07, std::fabs(fSlow652));
		double fSlow673 = fConst25 * fSlow672;
		double fSlow674 = 1.0 - fConst0 / fSlow672;
		double fSlow675 = fConst25 * fSlow652;
		double fSlow676 = fSlow21 + fSlow465;
		double fThen539 = fSlow21 - fSlow465;
		double fSlow677 = ((iSlow25) ? fSlow676 : fThen539);
		double fElse540 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow677 + -69.0));
		double fSlow678 = ((iSlow0) ? fElse540 : fSlow467);
		double fSlow679 = ((fSlow678 == 0.0) ? 1e+02 : fSlow678);
		double fSlow680 = std::tan(fConst20 * double(int(fSlow679 + 1e+01)));
		double fSlow681 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow679))) * fSlow680));
		double fSlow682 = fConst23 * fSlow680 - fConst22 * (fSlow681 / fSlow680);
		double fSlow683 = fConst24 * fSlow682;
		double fSlow684 = fConst26 * fSlow681;
		double fSlow685 = fSlow684 + fSlow683 + 4.0;
		double fSlow686 = 0.0 - fConst24 * (fSlow682 / fSlow685);
		double fSlow687 = fSlow684 + (4.0 - fSlow683);
		double fSlow688 = fConst27 * fSlow681 + -8.0;
		double fSlow689 = std::max<double>(fSlow678, 23.44895);
		double fSlow690 = std::max<double>(2e+01, std::fabs(fSlow689));
		double fSlow691 = fConst25 * fSlow690;
		double fSlow692 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow689));
		int iSlow693 = int(fSlow692);
		int iSlow694 = iSlow693 + 1;
		double fSlow695 = std::floor(fSlow692);
		double fSlow696 = fSlow692 - fSlow695;
		double fSlow697 = fSlow695 + (1.0 - fSlow692);
		double fSlow698 = std::max<double>(1.1920929e-07, std::fabs(fSlow678));
		double fSlow699 = fConst25 * fSlow698;
		double fSlow700 = 1.0 - fConst0 / fSlow698;
		double fSlow701 = fConst25 * fSlow678;
		double fSlow702 = fSlow21 + fSlow518;
		double fThen548 = fSlow21 - fSlow518;
		double fSlow703 = ((iSlow25) ? fSlow702 : fThen548);
		double fElse549 = 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow703 + -69.0));
		double fSlow704 = ((iSlow0) ? fElse549 : fSlow520);
		double fSlow705 = ((fSlow704 == 0.0) ? 1e+02 : fSlow704);
		double fSlow706 = std::tan(fConst20 * double(int(fSlow705 + 1e+01)));
		double fSlow707 = scaleIt_faustpower2_f(std::sqrt(fConst21 * std::tan(fConst20 * double(int(fSlow705))) * fSlow706));
		double fSlow708 = fConst23 * fSlow706 - fConst22 * (fSlow707 / fSlow706);
		double fSlow709 = fConst24 * fSlow708;
		double fSlow710 = fConst26 * fSlow707;
		double fSlow711 = fSlow710 + fSlow709 + 4.0;
		double fSlow712 = 0.0 - fConst24 * (fSlow708 / fSlow711);
		double fSlow713 = fSlow710 + (4.0 - fSlow709);
		double fSlow714 = fConst27 * fSlow707 + -8.0;
		double fSlow715 = std::max<double>(fSlow704, 23.44895);
		double fSlow716 = std::max<double>(2e+01, std::fabs(fSlow715));
		double fSlow717 = fConst25 * fSlow716;
		double fSlow718 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow715));
		int iSlow719 = int(fSlow718);
		int iSlow720 = iSlow719 + 1;
		double fSlow721 = std::floor(fSlow718);
		double fSlow722 = fSlow718 - fSlow721;
		double fSlow723 = fSlow721 + (1.0 - fSlow718);
		double fSlow724 = std::max<double>(1.1920929e-07, std::fabs(fSlow704));
		double fSlow725 = fConst25 * fSlow724;
		double fSlow726 = 1.0 - fConst0 / fSlow724;
		double fSlow727 = fConst25 * fSlow704;
		double fSlow728 = ((iSlow0) ? fSlow227 : fSlow226);
		double fSlow729 = ((iSlow0) ? fSlow703 : fSlow702);
		double fSlow730 = ((iSlow0) ? fSlow198 : fSlow197);
		double fSlow731 = ((iSlow0) ? fSlow677 : fSlow676);
		double fSlow732 = ((iSlow0) ? fSlow169 : fSlow168);
		double fSlow733 = ((iSlow0) ? fSlow651 : fSlow650);
		double fSlow734 = ((iSlow0) ? fSlow140 : fSlow139);
		double fSlow735 = ((iSlow0) ? fSlow625 : fSlow624);
		double fSlow736 = ((iSlow0) ? fSlow111 : fSlow110);
		double fSlow737 = ((iSlow0) ? fSlow599 : fSlow598);
		double fSlow738 = ((iSlow0) ? fSlow27 : fSlow26);
		double fSlow739 = ((iSlow0) ? fSlow573 : fSlow572);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			iRec5[0] = 1103515245 * iRec5[1] + 12345;
			double fTemp0 = 6.984919465741205e-10 * double(iRec5[0]);
			fRec4[0] = fTemp0 - (fRec4[1] * fSlow38 + fRec4[2] * fSlow37) / fSlow35;
			double fTemp1 = fRec6[1] + fSlow45;
			fRec6[0] = fTemp1 - std::floor(fTemp1);
			double fTemp2 = scaleIt_faustpower2_f(2.0 * fRec6[0] + -1.0);
			fVec1[0] = fTemp2;
			double fTemp3 = double(iVec0[1]);
			double fTemp4 = fTemp3 * (fTemp2 - fVec1[1]) / fSlow44;
			fVec2[IOTA0 & 4095] = fTemp4;
			double fTemp5 = fConst29 * (fTemp4 - fVec2[(IOTA0 - iSlow47) & 4095] * fSlow51 - fSlow50 * fVec2[(IOTA0 - iSlow48) & 4095]);
			fRec7[0] = 0.999 * fRec7[1] + fTemp5;
			double fElse22 = fConst30 * fRec7[0] * fSlow28;
			double fTemp6 = fRec8[1] + fSlow55;
			double fTemp7 = fTemp6 + -1.0;
			int iTemp8 = fTemp7 < 0.0;
			fRec8[0] = ((iTemp8) ? fTemp6 : fTemp7);
			double fThen24 = fTemp6 + fTemp7 * fSlow56;
			double fRec9 = ((iTemp8) ? fTemp6 : fThen24);
			double fElse25 = 2.0 * fRec9 + -1.0;
			double fTemp9 = fRec11[1] + fSlow58;
			fRec11[0] = fTemp9 - std::floor(fTemp9);
			double fElse26 = ftbl16scaleItSIG16[int(65536.0 * fRec11[0])];
			double fTemp10 = double(input1[i0]);
			double fTemp11 = double(input0[i0]);
			int iTemp12 = fTemp11 > (fSlow66 * fTemp10);
			int iTemp13 = (-1 * iTemp12) == iTemp12;
			int iTemp14 = fTemp11 > (fSlow68 * fTemp10);
			int iTemp15 = (-1 * iTemp14) == iTemp14;
			int iTemp16 = fTemp11 > (fSlow70 * fTemp10);
			int iTemp17 = (-1 * iTemp16) == iTemp16;
			int iTemp18 = fTemp11 > (fSlow72 * fTemp10);
			int iTemp19 = (-1 * iTemp18) == iTemp18;
			int iTemp20 = fTemp11 > (fSlow74 * fTemp10);
			int iTemp21 = (-1 * iTemp20) == iTemp20;
			int iTemp22 = fTemp11 > (fSlow76 * fTemp10);
			int iTemp23 = (-1 * iTemp22) == iTemp22;
			int iTemp24 = fTemp11 > (fSlow78 * fTemp10);
			int iTemp25 = (-1 * iTemp24) == iTemp24;
			int iTemp26 = fTemp11 > (fSlow80 * fTemp10);
			int iTemp27 = (-1 * iTemp26) == iTemp26;
			int iTemp28 = fTemp11 > (fSlow82 * fTemp10);
			int iTemp29 = (-1 * iTemp28) == iTemp28;
			double fTemp30 = fSlow84 * fTemp10;
			int iTemp31 = (iSlow87 & (fTemp30 <= 0.0)) | (iSlow86 & (fTemp11 > fTemp30));
			int iTemp32 = (-1 * iTemp31) == iTemp31;
			int iElse40 = ((iSlow25) ? iTemp26 : 0) + ((iSlow88) ? iTemp27 : 0) + ((iSlow83) ? iTemp32 : 0) + ((iSlow81) ? iTemp29 : 0) + ((iSlow79) ? iTemp27 : 0) + ((iSlow77) ? iTemp25 : 0) + ((iSlow75) ? iTemp23 : 0) + ((iSlow73) ? iTemp21 : 0) + ((iSlow71) ? iTemp19 : 0) + ((iSlow69) ? iTemp17 : 0) + ((iSlow67) ? iTemp15 : 0) + ((iSlow64) ? iTemp13 : 0);
			int iTemp33 = ((iSlow62) ? iElse40 : 0);
			iVec4[0] = iTemp33;
			int iTemp34 = fTemp11 > (fSlow90 * fTemp10);
			int iTemp35 = (-1 * iTemp34) == iTemp34;
			int iTemp36 = fTemp11 > (fSlow91 * fTemp10);
			int iTemp37 = (-1 * iTemp36) == iTemp36;
			int iElse53 = ((iSlow25) ? iTemp31 : 0) + ((iSlow88) ? iTemp29 : 0) + ((iSlow83) ? iTemp27 : 0) + ((iSlow81) ? iTemp25 : 0) + ((iSlow79) ? iTemp23 : 0) + ((iSlow77) ? iTemp21 : 0) + ((iSlow75) ? iTemp19 : 0) + ((iSlow73) ? iTemp17 : 0) + ((iSlow71) ? iTemp15 : 0) + ((iSlow69) ? iTemp13 : 0) + ((iSlow67) ? iTemp37 : 0) + ((iSlow64) ? iTemp35 : 0);
			int iTemp38 = ((iSlow89) ? iElse53 : 0);
			iVec5[0] = iTemp38;
			int iElse66 = ((iSlow25) ? iTemp22 : 0) + ((iSlow88) ? iTemp23 : 0) + ((iSlow83) ? iTemp23 : 0) + ((iSlow81) ? iTemp23 : 0) + ((iSlow79) ? iTemp32 : 0) + ((iSlow77) ? iTemp29 : 0) + ((iSlow75) ? iTemp27 : 0) + ((iSlow73) ? iTemp25 : 0) + ((iSlow71) ? iTemp23 : 0) + ((iSlow69) ? iTemp21 : 0) + ((iSlow67) ? iTemp19 : 0) + ((iSlow64) ? iTemp17 : 0);
			int iTemp39 = ((iSlow92) ? iElse66 : 0);
			iVec6[0] = iTemp39;
			int iElse79 = ((iSlow25) ? iTemp18 : 0) + ((iSlow88) ? iTemp19 : 0) + ((iSlow83) ? iTemp19 : 0) + ((iSlow81) ? iTemp19 : 0) + ((iSlow79) ? iTemp19 : 0) + ((iSlow77) ? iTemp19 : 0) + ((iSlow75) ? iTemp32 : 0) + ((iSlow73) ? iTemp29 : 0) + ((iSlow71) ? iTemp27 : 0) + ((iSlow69) ? iTemp25 : 0) + ((iSlow67) ? iTemp23 : 0) + ((iSlow64) ? iTemp21 : 0);
			int iTemp40 = ((iSlow93) ? iElse79 : 0);
			iVec7[0] = iTemp40;
			int iElse92 = ((iSlow25) ? iTemp14 : 0) + ((iSlow88) ? iTemp15 : 0) + ((iSlow83) ? iTemp15 : 0) + ((iSlow81) ? iTemp15 : 0) + ((iSlow79) ? iTemp15 : 0) + ((iSlow77) ? iTemp15 : 0) + ((iSlow75) ? iTemp15 : 0) + ((iSlow73) ? iTemp15 : 0) + ((iSlow71) ? iTemp32 : 0) + ((iSlow69) ? iTemp29 : 0) + ((iSlow67) ? iTemp27 : 0) + ((iSlow64) ? iTemp25 : 0);
			int iTemp41 = ((iSlow94) ? iElse92 : 0);
			iVec8[0] = iTemp41;
			int iElse105 = ((iSlow25) ? iTemp36 : 0) + ((iSlow88) ? iTemp37 : 0) + ((iSlow83) ? iTemp37 : 0) + ((iSlow81) ? iTemp37 : 0) + ((iSlow79) ? iTemp37 : 0) + ((iSlow77) ? iTemp37 : 0) + ((iSlow75) ? iTemp37 : 0) + ((iSlow73) ? iTemp37 : 0) + ((iSlow71) ? iTemp37 : 0) + ((iSlow69) ? iTemp37 : 0) + ((iSlow67) ? iTemp32 : 0) + ((iSlow64) ? iTemp29 : 0);
			int iTemp42 = ((iSlow95) ? iElse105 : 0);
			iVec9[0] = iTemp42;
			double fTemp43 = double(iTemp42 + iTemp41 + iTemp40 + iTemp39 + iTemp38 + iTemp33);
			double fThen106 = fSlow61 - fTemp43;
			double fTemp44 = ((iSlow25) ? fTemp43 : fThen106);
			int iElse119 = ((iSlow25) ? iTemp24 : 0) + ((iSlow88) ? iTemp25 : 0) + ((iSlow83) ? iTemp25 : 0) + ((iSlow81) ? iTemp32 : 0) + ((iSlow79) ? iTemp29 : 0) + ((iSlow77) ? iTemp27 : 0) + ((iSlow75) ? iTemp25 : 0) + ((iSlow73) ? iTemp23 : 0) + ((iSlow71) ? iTemp21 : 0) + ((iSlow69) ? iTemp19 : 0) + ((iSlow67) ? iTemp17 : 0) + ((iSlow64) ? iTemp15 : 0);
			int iTemp45 = ((iSlow96) ? iElse119 : 0);
			iVec10[0] = iTemp45;
			int iElse132 = ((iSlow25) ? iTemp28 : 0) + ((iSlow88) ? iTemp32 : 0) + ((iSlow83) ? iTemp29 : 0) + ((iSlow81) ? iTemp27 : 0) + ((iSlow79) ? iTemp25 : 0) + ((iSlow77) ? iTemp23 : 0) + ((iSlow75) ? iTemp21 : 0) + ((iSlow73) ? iTemp19 : 0) + ((iSlow71) ? iTemp17 : 0) + ((iSlow69) ? iTemp15 : 0) + ((iSlow67) ? iTemp13 : 0) + ((iSlow64) ? iTemp37 : 0);
			int iTemp46 = ((iSlow97) ? iElse132 : 0);
			iVec11[0] = iTemp46;
			int iElse145 = ((iSlow25) ? iTemp20 : 0) + ((iSlow88) ? iTemp21 : 0) + ((iSlow83) ? iTemp21 : 0) + ((iSlow81) ? iTemp21 : 0) + ((iSlow79) ? iTemp21 : 0) + ((iSlow77) ? iTemp32 : 0) + ((iSlow75) ? iTemp29 : 0) + ((iSlow73) ? iTemp27 : 0) + ((iSlow71) ? iTemp25 : 0) + ((iSlow69) ? iTemp23 : 0) + ((iSlow67) ? iTemp21 : 0) + ((iSlow64) ? iTemp19 : 0);
			int iTemp47 = ((iSlow98) ? iElse145 : 0);
			iVec12[0] = iTemp47;
			int iElse158 = ((iSlow25) ? iTemp16 : 0) + ((iSlow88) ? iTemp17 : 0) + ((iSlow83) ? iTemp17 : 0) + ((iSlow81) ? iTemp17 : 0) + ((iSlow79) ? iTemp17 : 0) + ((iSlow77) ? iTemp17 : 0) + ((iSlow75) ? iTemp17 : 0) + ((iSlow73) ? iTemp32 : 0) + ((iSlow71) ? iTemp29 : 0) + ((iSlow69) ? iTemp27 : 0) + ((iSlow67) ? iTemp25 : 0) + ((iSlow64) ? iTemp23 : 0);
			int iTemp48 = ((iSlow99) ? iElse158 : 0);
			iVec13[0] = iTemp48;
			int iElse171 = ((iSlow25) ? iTemp12 : 0) + ((iSlow88) ? iTemp13 : 0) + ((iSlow83) ? iTemp13 : 0) + ((iSlow81) ? iTemp13 : 0) + ((iSlow79) ? iTemp13 : 0) + ((iSlow77) ? iTemp13 : 0) + ((iSlow75) ? iTemp13 : 0) + ((iSlow73) ? iTemp13 : 0) + ((iSlow71) ? iTemp13 : 0) + ((iSlow69) ? iTemp32 : 0) + ((iSlow67) ? iTemp29 : 0) + ((iSlow64) ? iTemp27 : 0);
			int iTemp49 = ((iSlow100) ? iElse171 : 0);
			iVec14[0] = iTemp49;
			int iElse184 = ((iSlow25) ? iTemp34 : 0) + ((iSlow88) ? iTemp35 : 0) + ((iSlow83) ? iTemp35 : 0) + ((iSlow81) ? iTemp35 : 0) + ((iSlow79) ? iTemp35 : 0) + ((iSlow77) ? iTemp35 : 0) + ((iSlow75) ? iTemp35 : 0) + ((iSlow73) ? iTemp35 : 0) + ((iSlow71) ? iTemp35 : 0) + ((iSlow69) ? iTemp35 : 0) + ((iSlow67) ? iTemp35 : 0) + ((iSlow64) ? iTemp32 : 0);
			int iTemp50 = ((iSlow101) ? iElse184 : 0);
			iVec15[0] = iTemp50;
			int iTemp51 = iTemp50 + iTemp49 + iTemp48 + iTemp47 + iTemp46 + iTemp45;
			int iTemp52 = iTemp51 * (fTemp44 == 1e+01);
			iVec16[0] = iTemp52;
			iRec12[0] = (iRec12[1] + 1) * (iTemp52 == 0);
			iRec13[0] = iTemp52 + iRec13[1] * (iVec16[1] >= iTemp52);
			double fTemp53 = double(iRec13[0]);
			fRec14[0] = fTemp0 - (fRec14[1] * fSlow122 + fRec14[2] * fSlow121) / fSlow119;
			double fTemp54 = fRec15[1] + fSlow125;
			fRec15[0] = fTemp54 - std::floor(fTemp54);
			double fTemp55 = scaleIt_faustpower2_f(2.0 * fRec15[0] + -1.0);
			fVec17[0] = fTemp55;
			double fTemp56 = fTemp3 * (fTemp55 - fVec17[1]) / fSlow124;
			fVec18[IOTA0 & 4095] = fTemp56;
			double fTemp57 = fConst29 * (fTemp56 - fVec18[(IOTA0 - iSlow127) & 4095] * fSlow131 - fSlow130 * fVec18[(IOTA0 - iSlow128) & 4095]);
			fRec16[0] = 0.999 * fRec16[1] + fTemp57;
			double fElse206 = fConst30 * fRec16[0] * fSlow112;
			double fTemp58 = fRec17[1] + fSlow133;
			double fTemp59 = fTemp58 + -1.0;
			int iTemp60 = fTemp59 < 0.0;
			fRec17[0] = ((iTemp60) ? fTemp58 : fTemp59);
			double fThen208 = fTemp58 + fTemp59 * fSlow134;
			double fRec18 = ((iTemp60) ? fTemp58 : fThen208);
			double fElse209 = 2.0 * fRec18 + -1.0;
			double fTemp61 = fRec19[1] + fSlow135;
			fRec19[0] = fTemp61 - std::floor(fTemp61);
			double fElse210 = ftbl16scaleItSIG16[int(65536.0 * fRec19[0])];
			int iTemp62 = iTemp51 * (fTemp44 == 8.0);
			iVec19[0] = iTemp62;
			iRec20[0] = (iRec20[1] + 1) * (iTemp62 == 0);
			iRec21[0] = iTemp62 + iRec21[1] * (iVec19[1] >= iTemp62);
			double fTemp63 = double(iRec21[0]);
			fRec22[0] = fTemp0 - (fRec22[1] * fSlow151 + fRec22[2] * fSlow150) / fSlow148;
			double fTemp64 = fRec23[1] + fSlow154;
			fRec23[0] = fTemp64 - std::floor(fTemp64);
			double fTemp65 = scaleIt_faustpower2_f(2.0 * fRec23[0] + -1.0);
			fVec20[0] = fTemp65;
			double fTemp66 = fTemp3 * (fTemp65 - fVec20[1]) / fSlow153;
			fVec21[IOTA0 & 4095] = fTemp66;
			double fTemp67 = fConst29 * (fTemp66 - fVec21[(IOTA0 - iSlow156) & 4095] * fSlow160 - fSlow159 * fVec21[(IOTA0 - iSlow157) & 4095]);
			fRec24[0] = 0.999 * fRec24[1] + fTemp67;
			double fElse232 = fConst30 * fRec24[0] * fSlow141;
			double fTemp68 = fRec25[1] + fSlow162;
			double fTemp69 = fTemp68 + -1.0;
			int iTemp70 = fTemp69 < 0.0;
			fRec25[0] = ((iTemp70) ? fTemp68 : fTemp69);
			double fThen234 = fTemp68 + fTemp69 * fSlow163;
			double fRec26 = ((iTemp70) ? fTemp68 : fThen234);
			double fElse235 = 2.0 * fRec26 + -1.0;
			double fTemp71 = fRec27[1] + fSlow164;
			fRec27[0] = fTemp71 - std::floor(fTemp71);
			double fElse236 = ftbl16scaleItSIG16[int(65536.0 * fRec27[0])];
			int iTemp72 = iTemp51 * (fTemp44 == 6.0);
			iVec22[0] = iTemp72;
			iRec28[0] = (iRec28[1] + 1) * (iTemp72 == 0);
			iRec29[0] = iTemp72 + iRec29[1] * (iVec22[1] >= iTemp72);
			double fTemp73 = double(iRec29[0]);
			fRec30[0] = fTemp0 - (fRec30[1] * fSlow180 + fRec30[2] * fSlow179) / fSlow177;
			double fTemp74 = fRec31[1] + fSlow183;
			fRec31[0] = fTemp74 - std::floor(fTemp74);
			double fTemp75 = scaleIt_faustpower2_f(2.0 * fRec31[0] + -1.0);
			fVec23[0] = fTemp75;
			double fTemp76 = fTemp3 * (fTemp75 - fVec23[1]) / fSlow182;
			fVec24[IOTA0 & 4095] = fTemp76;
			double fTemp77 = fConst29 * (fTemp76 - fVec24[(IOTA0 - iSlow185) & 4095] * fSlow189 - fSlow188 * fVec24[(IOTA0 - iSlow186) & 4095]);
			fRec32[0] = 0.999 * fRec32[1] + fTemp77;
			double fElse258 = fConst30 * fRec32[0] * fSlow170;
			double fTemp78 = fRec33[1] + fSlow191;
			double fTemp79 = fTemp78 + -1.0;
			int iTemp80 = fTemp79 < 0.0;
			fRec33[0] = ((iTemp80) ? fTemp78 : fTemp79);
			double fThen260 = fTemp78 + fTemp79 * fSlow192;
			double fRec34 = ((iTemp80) ? fTemp78 : fThen260);
			double fElse261 = 2.0 * fRec34 + -1.0;
			double fTemp81 = fRec35[1] + fSlow193;
			fRec35[0] = fTemp81 - std::floor(fTemp81);
			double fElse262 = ftbl16scaleItSIG16[int(65536.0 * fRec35[0])];
			int iTemp82 = iTemp51 * (fTemp44 == 4.0);
			iVec25[0] = iTemp82;
			iRec36[0] = (iRec36[1] + 1) * (iTemp82 == 0);
			iRec37[0] = iTemp82 + iRec37[1] * (iVec25[1] >= iTemp82);
			double fTemp83 = double(iRec37[0]);
			fRec38[0] = fTemp0 - (fRec38[1] * fSlow209 + fRec38[2] * fSlow208) / fSlow206;
			double fTemp84 = fRec39[1] + fSlow212;
			fRec39[0] = fTemp84 - std::floor(fTemp84);
			double fTemp85 = scaleIt_faustpower2_f(2.0 * fRec39[0] + -1.0);
			fVec26[0] = fTemp85;
			double fTemp86 = fTemp3 * (fTemp85 - fVec26[1]) / fSlow211;
			fVec27[IOTA0 & 4095] = fTemp86;
			double fTemp87 = fConst29 * (fTemp86 - fVec27[(IOTA0 - iSlow214) & 4095] * fSlow218 - fSlow217 * fVec27[(IOTA0 - iSlow215) & 4095]);
			fRec40[0] = 0.999 * fRec40[1] + fTemp87;
			double fElse284 = fConst30 * fRec40[0] * fSlow199;
			double fTemp88 = fRec41[1] + fSlow220;
			double fTemp89 = fTemp88 + -1.0;
			int iTemp90 = fTemp89 < 0.0;
			fRec41[0] = ((iTemp90) ? fTemp88 : fTemp89);
			double fThen286 = fTemp88 + fTemp89 * fSlow221;
			double fRec42 = ((iTemp90) ? fTemp88 : fThen286);
			double fElse287 = 2.0 * fRec42 + -1.0;
			double fTemp91 = fRec43[1] + fSlow222;
			fRec43[0] = fTemp91 - std::floor(fTemp91);
			double fElse288 = ftbl16scaleItSIG16[int(65536.0 * fRec43[0])];
			int iTemp92 = iTemp51 * (fTemp44 == 2.0);
			iVec28[0] = iTemp92;
			iRec44[0] = (iRec44[1] + 1) * (iTemp92 == 0);
			iRec45[0] = iTemp92 + iRec45[1] * (iVec28[1] >= iTemp92);
			double fTemp93 = double(iRec45[0]);
			fRec46[0] = fTemp0 - (fRec46[1] * fSlow238 + fRec46[2] * fSlow237) / fSlow235;
			double fTemp94 = fRec47[1] + fSlow241;
			fRec47[0] = fTemp94 - std::floor(fTemp94);
			double fTemp95 = scaleIt_faustpower2_f(2.0 * fRec47[0] + -1.0);
			fVec29[0] = fTemp95;
			double fTemp96 = fTemp3 * (fTemp95 - fVec29[1]) / fSlow240;
			fVec30[IOTA0 & 4095] = fTemp96;
			double fTemp97 = fConst29 * (fTemp96 - fVec30[(IOTA0 - iSlow243) & 4095] * fSlow247 - fSlow246 * fVec30[(IOTA0 - iSlow244) & 4095]);
			fRec48[0] = 0.999 * fRec48[1] + fTemp97;
			double fElse310 = fConst30 * fRec48[0] * fSlow228;
			double fTemp98 = fRec49[1] + fSlow249;
			double fTemp99 = fTemp98 + -1.0;
			int iTemp100 = fTemp99 < 0.0;
			fRec49[0] = ((iTemp100) ? fTemp98 : fTemp99);
			double fThen312 = fTemp98 + fTemp99 * fSlow250;
			double fRec50 = ((iTemp100) ? fTemp98 : fThen312);
			double fElse313 = 2.0 * fRec50 + -1.0;
			double fTemp101 = fRec51[1] + fSlow251;
			fRec51[0] = fTemp101 - std::floor(fTemp101);
			double fElse314 = ftbl16scaleItSIG16[int(65536.0 * fRec51[0])];
			int iTemp102 = iTemp51 * (fTemp44 == 0.0);
			iVec31[0] = iTemp102;
			iRec52[0] = (iRec52[1] + 1) * (iTemp102 == 0);
			iRec53[0] = iTemp102 + iRec53[1] * (iVec31[1] >= iTemp102);
			double fTemp103 = double(iRec53[0]);
			double fTemp104 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp103, std::max<double>(fSlow106 * (fSlow103 - fTemp103) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec52[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse314 : 0.0) + ((iSlow53) ? fElse313 : 0.0) + ((iSlow52) ? fElse310 : 0.0) + ((iSlow42) ? fTemp97 : 0.0)) + fSlow40 * (fConst24 * (fRec46[0] * fSlow232 / fSlow235) + fRec46[2] * fSlow236)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp93, std::max<double>(fSlow106 * (fSlow103 - fTemp93) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec44[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse288 : 0.0) + ((iSlow53) ? fElse287 : 0.0) + ((iSlow52) ? fElse284 : 0.0) + ((iSlow42) ? fTemp87 : 0.0)) + fSlow40 * (fConst24 * (fRec38[0] * fSlow203 / fSlow206) + fRec38[2] * fSlow207)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp83, std::max<double>(fSlow106 * (fSlow103 - fTemp83) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec36[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse262 : 0.0) + ((iSlow53) ? fElse261 : 0.0) + ((iSlow52) ? fElse258 : 0.0) + ((iSlow42) ? fTemp77 : 0.0)) + fSlow40 * (fConst24 * (fRec30[0] * fSlow174 / fSlow177) + fRec30[2] * fSlow178)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp73, std::max<double>(fSlow106 * (fSlow103 - fTemp73) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec28[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse236 : 0.0) + ((iSlow53) ? fElse235 : 0.0) + ((iSlow52) ? fElse232 : 0.0) + ((iSlow42) ? fTemp67 : 0.0)) + fSlow40 * (fConst24 * (fRec22[0] * fSlow145 / fSlow148) + fRec22[2] * fSlow149)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp63, std::max<double>(fSlow106 * (fSlow103 - fTemp63) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec20[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse210 : 0.0) + ((iSlow53) ? fElse209 : 0.0) + ((iSlow52) ? fElse206 : 0.0) + ((iSlow42) ? fTemp57 : 0.0)) + fSlow40 * (fConst24 * (fRec14[0] * fSlow116 / fSlow119) + fRec14[2] * fSlow120)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp53, std::max<double>(fSlow106 * (fSlow103 - fTemp53) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec12[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse26 : 0.0) + ((iSlow53) ? fElse25 : 0.0) + ((iSlow52) ? fElse22 : 0.0) + ((iSlow42) ? fTemp5 : 0.0)) + fSlow40 * (fConst24 * (fRec4[0] * fSlow32 / fSlow35) + fRec4[2] * fSlow36));
			fRec3[0] = fConst111 * std::fabs(fTemp104) + fConst3 * fRec3[1];
			fRec2[0] = fConst112 * (0.0 - 0.9666666666666667 * std::max<double>(2e+01 * std::log10(std::max<double>(1.1754944e-38, fRec3[0])) + 7.9588003, 0.0)) + fConst2 * fRec2[1];
			double fTemp105 = fTemp104 * std::pow(1e+01, 0.05 * fRec2[0]);
			double fTemp106 = std::fabs(fTemp105);
			double fTemp107 = ((fTemp106 > fRec1[1]) ? fConst114 : fConst113);
			fRec1[0] = fTemp106 * (1.0 - fTemp107) + fRec1[1] * fTemp107;
			fRec0[0] = fConst115 * (0.0 - 0.75 * std::max<double>(2e+01 * std::log10(std::max<double>(1.1754944e-38, fRec1[0])) + 6.0, 0.0)) + fConst1 * fRec0[1];
			fRec58[0] = fTemp0 - (fRec58[1] * fSlow265 + fRec58[2] * fSlow264) / fSlow262;
			iRec59[0] = (iRec59[1] + 1) * (iTemp50 == 0);
			iRec60[0] = iTemp50 + iRec60[1] * (iVec15[1] >= iTemp50);
			double fTemp108 = double(iRec60[0]);
			double fTemp109 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp108, std::max<double>(fSlow106 * (fSlow103 - fTemp108) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec59[0])));
			double fTemp110 = fSlow40 * fTemp109 * (fConst24 * (fRec58[0] * fSlow259 / fSlow262) + fRec58[2] * fSlow263);
			double fTemp111 = fRec61[1] + fSlow268;
			fRec61[0] = fTemp111 - std::floor(fTemp111);
			double fTemp112 = scaleIt_faustpower2_f(2.0 * fRec61[0] + -1.0);
			fVec32[0] = fTemp112;
			double fTemp113 = fTemp3 * (fTemp112 - fVec32[1]) / fSlow267;
			fVec33[IOTA0 & 4095] = fTemp113;
			double fTemp114 = fConst29 * (fTemp113 - fVec33[(IOTA0 - iSlow270) & 4095] * fSlow274 - fSlow273 * fVec33[(IOTA0 - iSlow271) & 4095]);
			fRec62[0] = 0.999 * fRec62[1] + fTemp114;
			double fElse335 = fConst132 * fRec62[0] * fSlow254;
			double fTemp115 = fRec63[1] + fSlow276;
			double fTemp116 = fTemp115 + -1.0;
			int iTemp117 = fTemp116 < 0.0;
			fRec63[0] = ((iTemp117) ? fTemp115 : fTemp116);
			double fThen337 = fTemp115 + fTemp116 * fSlow277;
			double fRec64 = ((iTemp117) ? fTemp115 : fThen337);
			double fElse338 = 2.0 * fRec64 + -1.0;
			double fTemp118 = fRec65[1] + fSlow278;
			fRec65[0] = fTemp118 - std::floor(fTemp118);
			double fElse339 = ftbl16scaleItSIG16[int(65536.0 * fRec65[0])];
			double fTemp119 = fSlow60 * fTemp109 * (((iSlow57) ? fElse339 : 0.0) + ((iSlow53) ? fElse338 : 0.0) + ((iSlow52) ? fElse335 : 0.0) + ((iSlow42) ? fTemp114 : 0.0));
			fRec66[0] = fTemp0 - (fRec66[1] * fSlow290 + fRec66[2] * fSlow289) / fSlow287;
			iRec67[0] = (iRec67[1] + 1) * (iTemp42 == 0);
			iRec68[0] = iTemp42 + iRec68[1] * (iVec9[1] >= iTemp42);
			double fTemp120 = double(iRec68[0]);
			double fTemp121 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp120, std::max<double>(fSlow106 * (fSlow103 - fTemp120) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec67[0])));
			double fTemp122 = fSlow40 * fTemp121 * (fConst24 * (fRec66[0] * fSlow284 / fSlow287) + fRec66[2] * fSlow288);
			double fTemp123 = fRec69[1] + fSlow293;
			fRec69[0] = fTemp123 - std::floor(fTemp123);
			double fTemp124 = scaleIt_faustpower2_f(2.0 * fRec69[0] + -1.0);
			fVec34[0] = fTemp124;
			double fTemp125 = fTemp3 * (fTemp124 - fVec34[1]) / fSlow292;
			fVec35[IOTA0 & 4095] = fTemp125;
			double fTemp126 = fConst29 * (fTemp125 - fVec35[(IOTA0 - iSlow295) & 4095] * fSlow299 - fSlow298 * fVec35[(IOTA0 - iSlow296) & 4095]);
			fRec70[0] = 0.999 * fRec70[1] + fTemp126;
			double fElse342 = fConst132 * fRec70[0] * fSlow22;
			double fTemp127 = fRec71[1] + fSlow301;
			double fTemp128 = fTemp127 + -1.0;
			int iTemp129 = fTemp128 < 0.0;
			fRec71[0] = ((iTemp129) ? fTemp127 : fTemp128);
			double fThen344 = fTemp127 + fTemp128 * fSlow302;
			double fRec72 = ((iTemp129) ? fTemp127 : fThen344);
			double fElse345 = 2.0 * fRec72 + -1.0;
			double fTemp130 = fRec73[1] + fSlow303;
			fRec73[0] = fTemp130 - std::floor(fTemp130);
			double fElse346 = ftbl16scaleItSIG16[int(65536.0 * fRec73[0])];
			double fTemp131 = fSlow60 * fTemp121 * (((iSlow57) ? fElse346 : 0.0) + ((iSlow53) ? fElse345 : 0.0) + ((iSlow52) ? fElse342 : 0.0) + ((iSlow42) ? fTemp126 : 0.0));
			fRec74[0] = fTemp0 - (fRec74[1] * fSlow318 + fRec74[2] * fSlow317) / fSlow315;
			iRec75[0] = (iRec75[1] + 1) * (iTemp49 == 0);
			iRec76[0] = iTemp49 + iRec76[1] * (iVec14[1] >= iTemp49);
			double fTemp132 = double(iRec76[0]);
			double fTemp133 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp132, std::max<double>(fSlow106 * (fSlow103 - fTemp132) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec75[0])));
			double fTemp134 = fSlow40 * fTemp133 * (fConst24 * (fRec74[0] * fSlow312 / fSlow315) + fRec74[2] * fSlow316);
			double fTemp135 = fRec77[1] + fSlow321;
			fRec77[0] = fTemp135 - std::floor(fTemp135);
			double fTemp136 = scaleIt_faustpower2_f(2.0 * fRec77[0] + -1.0);
			fVec36[0] = fTemp136;
			double fTemp137 = fTemp3 * (fTemp136 - fVec36[1]) / fSlow320;
			fVec37[IOTA0 & 4095] = fTemp137;
			double fTemp138 = fConst29 * (fTemp137 - fVec37[(IOTA0 - iSlow323) & 4095] * fSlow327 - fSlow326 * fVec37[(IOTA0 - iSlow324) & 4095]);
			fRec78[0] = 0.999 * fRec78[1] + fTemp138;
			double fElse366 = fConst132 * fRec78[0] * fSlow307;
			double fTemp139 = fRec79[1] + fSlow329;
			double fTemp140 = fTemp139 + -1.0;
			int iTemp141 = fTemp140 < 0.0;
			fRec79[0] = ((iTemp141) ? fTemp139 : fTemp140);
			double fThen368 = fTemp139 + fTemp140 * fSlow330;
			double fRec80 = ((iTemp141) ? fTemp139 : fThen368);
			double fElse369 = 2.0 * fRec80 + -1.0;
			double fTemp142 = fRec81[1] + fSlow331;
			fRec81[0] = fTemp142 - std::floor(fTemp142);
			double fElse370 = ftbl16scaleItSIG16[int(65536.0 * fRec81[0])];
			double fTemp143 = fSlow60 * fTemp133 * (((iSlow57) ? fElse370 : 0.0) + ((iSlow53) ? fElse369 : 0.0) + ((iSlow52) ? fElse366 : 0.0) + ((iSlow42) ? fTemp138 : 0.0));
			fRec82[0] = fTemp0 - (fRec82[1] * fSlow343 + fRec82[2] * fSlow342) / fSlow340;
			iRec83[0] = (iRec83[1] + 1) * (iTemp41 == 0);
			iRec84[0] = iTemp41 + iRec84[1] * (iVec8[1] >= iTemp41);
			double fTemp144 = double(iRec84[0]);
			double fTemp145 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp144, std::max<double>(fSlow106 * (fSlow103 - fTemp144) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec83[0])));
			double fTemp146 = fSlow40 * fTemp145 * (fConst24 * (fRec82[0] * fSlow337 / fSlow340) + fRec82[2] * fSlow341);
			double fTemp147 = fRec85[1] + fSlow346;
			fRec85[0] = fTemp147 - std::floor(fTemp147);
			double fTemp148 = scaleIt_faustpower2_f(2.0 * fRec85[0] + -1.0);
			fVec38[0] = fTemp148;
			double fTemp149 = fTemp3 * (fTemp148 - fVec38[1]) / fSlow345;
			fVec39[IOTA0 & 4095] = fTemp149;
			double fTemp150 = fConst29 * (fTemp149 - fVec39[(IOTA0 - iSlow348) & 4095] * fSlow352 - fSlow351 * fVec39[(IOTA0 - iSlow349) & 4095]);
			fRec86[0] = 0.999 * fRec86[1] + fTemp150;
			double fElse373 = fConst132 * fRec86[0] * fSlow108;
			double fTemp151 = fRec87[1] + fSlow354;
			double fTemp152 = fTemp151 + -1.0;
			int iTemp153 = fTemp152 < 0.0;
			fRec87[0] = ((iTemp153) ? fTemp151 : fTemp152);
			double fThen375 = fTemp151 + fTemp152 * fSlow355;
			double fRec88 = ((iTemp153) ? fTemp151 : fThen375);
			double fElse376 = 2.0 * fRec88 + -1.0;
			double fTemp154 = fRec89[1] + fSlow356;
			fRec89[0] = fTemp154 - std::floor(fTemp154);
			double fElse377 = ftbl16scaleItSIG16[int(65536.0 * fRec89[0])];
			double fTemp155 = fSlow60 * fTemp145 * (((iSlow57) ? fElse377 : 0.0) + ((iSlow53) ? fElse376 : 0.0) + ((iSlow52) ? fElse373 : 0.0) + ((iSlow42) ? fTemp150 : 0.0));
			fRec90[0] = fTemp0 - (fRec90[1] * fSlow371 + fRec90[2] * fSlow370) / fSlow368;
			iRec91[0] = (iRec91[1] + 1) * (iTemp48 == 0);
			iRec92[0] = iTemp48 + iRec92[1] * (iVec13[1] >= iTemp48);
			double fTemp156 = double(iRec92[0]);
			double fTemp157 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp156, std::max<double>(fSlow106 * (fSlow103 - fTemp156) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec91[0])));
			double fTemp158 = fSlow40 * fTemp157 * (fConst24 * (fRec90[0] * fSlow365 / fSlow368) + fRec90[2] * fSlow369);
			double fTemp159 = fRec93[1] + fSlow374;
			fRec93[0] = fTemp159 - std::floor(fTemp159);
			double fTemp160 = scaleIt_faustpower2_f(2.0 * fRec93[0] + -1.0);
			fVec40[0] = fTemp160;
			double fTemp161 = fTemp3 * (fTemp160 - fVec40[1]) / fSlow373;
			fVec41[IOTA0 & 4095] = fTemp161;
			double fTemp162 = fConst29 * (fTemp161 - fVec41[(IOTA0 - iSlow376) & 4095] * fSlow380 - fSlow379 * fVec41[(IOTA0 - iSlow377) & 4095]);
			fRec94[0] = 0.999 * fRec94[1] + fTemp162;
			double fElse397 = fConst132 * fRec94[0] * fSlow360;
			double fTemp163 = fRec95[1] + fSlow382;
			double fTemp164 = fTemp163 + -1.0;
			int iTemp165 = fTemp164 < 0.0;
			fRec95[0] = ((iTemp165) ? fTemp163 : fTemp164);
			double fThen399 = fTemp163 + fTemp164 * fSlow383;
			double fRec96 = ((iTemp165) ? fTemp163 : fThen399);
			double fElse400 = 2.0 * fRec96 + -1.0;
			double fTemp166 = fRec97[1] + fSlow384;
			fRec97[0] = fTemp166 - std::floor(fTemp166);
			double fElse401 = ftbl16scaleItSIG16[int(65536.0 * fRec97[0])];
			double fTemp167 = fSlow60 * fTemp157 * (((iSlow57) ? fElse401 : 0.0) + ((iSlow53) ? fElse400 : 0.0) + ((iSlow52) ? fElse397 : 0.0) + ((iSlow42) ? fTemp162 : 0.0));
			fRec98[0] = fTemp0 - (fRec98[1] * fSlow396 + fRec98[2] * fSlow395) / fSlow393;
			iRec99[0] = (iRec99[1] + 1) * (iTemp40 == 0);
			iRec100[0] = iTemp40 + iRec100[1] * (iVec7[1] >= iTemp40);
			double fTemp168 = double(iRec100[0]);
			double fTemp169 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp168, std::max<double>(fSlow106 * (fSlow103 - fTemp168) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec99[0])));
			double fTemp170 = fSlow40 * fTemp169 * (fConst24 * (fRec98[0] * fSlow390 / fSlow393) + fRec98[2] * fSlow394);
			double fTemp171 = fRec101[1] + fSlow399;
			fRec101[0] = fTemp171 - std::floor(fTemp171);
			double fTemp172 = scaleIt_faustpower2_f(2.0 * fRec101[0] + -1.0);
			fVec42[0] = fTemp172;
			double fTemp173 = fTemp3 * (fTemp172 - fVec42[1]) / fSlow398;
			fVec43[IOTA0 & 4095] = fTemp173;
			double fTemp174 = fConst29 * (fTemp173 - fVec43[(IOTA0 - iSlow401) & 4095] * fSlow405 - fSlow404 * fVec43[(IOTA0 - iSlow402) & 4095]);
			fRec102[0] = 0.999 * fRec102[1] + fTemp174;
			double fElse404 = fConst132 * fRec102[0] * fSlow137;
			double fTemp175 = fRec103[1] + fSlow407;
			double fTemp176 = fTemp175 + -1.0;
			int iTemp177 = fTemp176 < 0.0;
			fRec103[0] = ((iTemp177) ? fTemp175 : fTemp176);
			double fThen406 = fTemp175 + fTemp176 * fSlow408;
			double fRec104 = ((iTemp177) ? fTemp175 : fThen406);
			double fElse407 = 2.0 * fRec104 + -1.0;
			double fTemp178 = fRec105[1] + fSlow409;
			fRec105[0] = fTemp178 - std::floor(fTemp178);
			double fElse408 = ftbl16scaleItSIG16[int(65536.0 * fRec105[0])];
			double fTemp179 = fSlow60 * fTemp169 * (((iSlow57) ? fElse408 : 0.0) + ((iSlow53) ? fElse407 : 0.0) + ((iSlow52) ? fElse404 : 0.0) + ((iSlow42) ? fTemp174 : 0.0));
			fRec106[0] = fTemp0 - (fRec106[1] * fSlow424 + fRec106[2] * fSlow423) / fSlow421;
			iRec107[0] = (iRec107[1] + 1) * (iTemp47 == 0);
			iRec108[0] = iTemp47 + iRec108[1] * (iVec12[1] >= iTemp47);
			double fTemp180 = double(iRec108[0]);
			double fTemp181 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp180, std::max<double>(fSlow106 * (fSlow103 - fTemp180) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec107[0])));
			double fTemp182 = fSlow40 * fTemp181 * (fConst24 * (fRec106[0] * fSlow418 / fSlow421) + fRec106[2] * fSlow422);
			double fTemp183 = fRec109[1] + fSlow427;
			fRec109[0] = fTemp183 - std::floor(fTemp183);
			double fTemp184 = scaleIt_faustpower2_f(2.0 * fRec109[0] + -1.0);
			fVec44[0] = fTemp184;
			double fTemp185 = fTemp3 * (fTemp184 - fVec44[1]) / fSlow426;
			fVec45[IOTA0 & 4095] = fTemp185;
			double fTemp186 = fConst29 * (fTemp185 - fVec45[(IOTA0 - iSlow429) & 4095] * fSlow433 - fSlow432 * fVec45[(IOTA0 - iSlow430) & 4095]);
			fRec110[0] = 0.999 * fRec110[1] + fTemp186;
			double fElse428 = fConst132 * fRec110[0] * fSlow413;
			double fTemp187 = fRec111[1] + fSlow435;
			double fTemp188 = fTemp187 + -1.0;
			int iTemp189 = fTemp188 < 0.0;
			fRec111[0] = ((iTemp189) ? fTemp187 : fTemp188);
			double fThen430 = fTemp187 + fTemp188 * fSlow436;
			double fRec112 = ((iTemp189) ? fTemp187 : fThen430);
			double fElse431 = 2.0 * fRec112 + -1.0;
			double fTemp190 = fRec113[1] + fSlow437;
			fRec113[0] = fTemp190 - std::floor(fTemp190);
			double fElse432 = ftbl16scaleItSIG16[int(65536.0 * fRec113[0])];
			double fTemp191 = fSlow60 * fTemp181 * (((iSlow57) ? fElse432 : 0.0) + ((iSlow53) ? fElse431 : 0.0) + ((iSlow52) ? fElse428 : 0.0) + ((iSlow42) ? fTemp186 : 0.0));
			fRec114[0] = fTemp0 - (fRec114[1] * fSlow449 + fRec114[2] * fSlow448) / fSlow446;
			iRec115[0] = (iRec115[1] + 1) * (iTemp39 == 0);
			iRec116[0] = iTemp39 + iRec116[1] * (iVec6[1] >= iTemp39);
			double fTemp192 = double(iRec116[0]);
			double fTemp193 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp192, std::max<double>(fSlow106 * (fSlow103 - fTemp192) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec115[0])));
			double fTemp194 = fSlow40 * fTemp193 * (fConst24 * (fRec114[0] * fSlow443 / fSlow446) + fRec114[2] * fSlow447);
			double fTemp195 = fRec117[1] + fSlow452;
			fRec117[0] = fTemp195 - std::floor(fTemp195);
			double fTemp196 = scaleIt_faustpower2_f(2.0 * fRec117[0] + -1.0);
			fVec46[0] = fTemp196;
			double fTemp197 = fTemp3 * (fTemp196 - fVec46[1]) / fSlow451;
			fVec47[IOTA0 & 4095] = fTemp197;
			double fTemp198 = fConst29 * (fTemp197 - fVec47[(IOTA0 - iSlow454) & 4095] * fSlow458 - fSlow457 * fVec47[(IOTA0 - iSlow455) & 4095]);
			fRec118[0] = 0.999 * fRec118[1] + fTemp198;
			double fElse435 = fConst132 * fRec118[0] * fSlow166;
			double fTemp199 = fRec119[1] + fSlow460;
			double fTemp200 = fTemp199 + -1.0;
			int iTemp201 = fTemp200 < 0.0;
			fRec119[0] = ((iTemp201) ? fTemp199 : fTemp200);
			double fThen437 = fTemp199 + fTemp200 * fSlow461;
			double fRec120 = ((iTemp201) ? fTemp199 : fThen437);
			double fElse438 = 2.0 * fRec120 + -1.0;
			double fTemp202 = fRec121[1] + fSlow462;
			fRec121[0] = fTemp202 - std::floor(fTemp202);
			double fElse439 = ftbl16scaleItSIG16[int(65536.0 * fRec121[0])];
			double fTemp203 = fSlow60 * fTemp193 * (((iSlow57) ? fElse439 : 0.0) + ((iSlow53) ? fElse438 : 0.0) + ((iSlow52) ? fElse435 : 0.0) + ((iSlow42) ? fTemp198 : 0.0));
			fRec122[0] = fTemp0 - (fRec122[1] * fSlow477 + fRec122[2] * fSlow476) / fSlow474;
			iRec123[0] = (iRec123[1] + 1) * (iTemp45 == 0);
			iRec124[0] = iTemp45 + iRec124[1] * (iVec10[1] >= iTemp45);
			double fTemp204 = double(iRec124[0]);
			double fTemp205 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp204, std::max<double>(fSlow106 * (fSlow103 - fTemp204) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec123[0])));
			double fTemp206 = fSlow40 * fTemp205 * (fConst24 * (fRec122[0] * fSlow471 / fSlow474) + fRec122[2] * fSlow475);
			double fTemp207 = fRec125[1] + fSlow480;
			fRec125[0] = fTemp207 - std::floor(fTemp207);
			double fTemp208 = scaleIt_faustpower2_f(2.0 * fRec125[0] + -1.0);
			fVec48[0] = fTemp208;
			double fTemp209 = fTemp3 * (fTemp208 - fVec48[1]) / fSlow479;
			fVec49[IOTA0 & 4095] = fTemp209;
			double fTemp210 = fConst29 * (fTemp209 - fVec49[(IOTA0 - iSlow482) & 4095] * fSlow486 - fSlow485 * fVec49[(IOTA0 - iSlow483) & 4095]);
			fRec126[0] = 0.999 * fRec126[1] + fTemp210;
			double fElse459 = fConst132 * fRec126[0] * fSlow466;
			double fTemp211 = fRec127[1] + fSlow488;
			double fTemp212 = fTemp211 + -1.0;
			int iTemp213 = fTemp212 < 0.0;
			fRec127[0] = ((iTemp213) ? fTemp211 : fTemp212);
			double fThen461 = fTemp211 + fTemp212 * fSlow489;
			double fRec128 = ((iTemp213) ? fTemp211 : fThen461);
			double fElse462 = 2.0 * fRec128 + -1.0;
			double fTemp214 = fRec129[1] + fSlow490;
			fRec129[0] = fTemp214 - std::floor(fTemp214);
			double fElse463 = ftbl16scaleItSIG16[int(65536.0 * fRec129[0])];
			double fTemp215 = fSlow60 * fTemp205 * (((iSlow57) ? fElse463 : 0.0) + ((iSlow53) ? fElse462 : 0.0) + ((iSlow52) ? fElse459 : 0.0) + ((iSlow42) ? fTemp210 : 0.0));
			fRec130[0] = fTemp0 - (fRec130[1] * fSlow502 + fRec130[2] * fSlow501) / fSlow499;
			iRec131[0] = (iRec131[1] + 1) * (iTemp33 == 0);
			iRec132[0] = iTemp33 + iRec132[1] * (iVec4[1] >= iTemp33);
			double fTemp216 = double(iRec132[0]);
			double fTemp217 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp216, std::max<double>(fSlow106 * (fSlow103 - fTemp216) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec131[0])));
			double fTemp218 = fSlow40 * fTemp217 * (fConst24 * (fRec130[0] * fSlow496 / fSlow499) + fRec130[2] * fSlow500);
			double fTemp219 = fRec133[1] + fSlow505;
			fRec133[0] = fTemp219 - std::floor(fTemp219);
			double fTemp220 = scaleIt_faustpower2_f(2.0 * fRec133[0] + -1.0);
			fVec50[0] = fTemp220;
			double fTemp221 = fTemp3 * (fTemp220 - fVec50[1]) / fSlow504;
			fVec51[IOTA0 & 4095] = fTemp221;
			double fTemp222 = fConst29 * (fTemp221 - fVec51[(IOTA0 - iSlow507) & 4095] * fSlow511 - fSlow510 * fVec51[(IOTA0 - iSlow508) & 4095]);
			fRec134[0] = 0.999 * fRec134[1] + fTemp222;
			double fElse466 = fConst132 * fRec134[0] * fSlow195;
			double fTemp223 = fRec135[1] + fSlow513;
			double fTemp224 = fTemp223 + -1.0;
			int iTemp225 = fTemp224 < 0.0;
			fRec135[0] = ((iTemp225) ? fTemp223 : fTemp224);
			double fThen468 = fTemp223 + fTemp224 * fSlow514;
			double fRec136 = ((iTemp225) ? fTemp223 : fThen468);
			double fElse469 = 2.0 * fRec136 + -1.0;
			double fTemp226 = fRec137[1] + fSlow515;
			fRec137[0] = fTemp226 - std::floor(fTemp226);
			double fElse470 = ftbl16scaleItSIG16[int(65536.0 * fRec137[0])];
			double fTemp227 = fSlow60 * fTemp217 * (((iSlow57) ? fElse470 : 0.0) + ((iSlow53) ? fElse469 : 0.0) + ((iSlow52) ? fElse466 : 0.0) + ((iSlow42) ? fTemp222 : 0.0));
			fRec138[0] = fTemp0 - (fRec138[1] * fSlow530 + fRec138[2] * fSlow529) / fSlow527;
			iRec139[0] = (iRec139[1] + 1) * (iTemp46 == 0);
			iRec140[0] = iTemp46 + iRec140[1] * (iVec11[1] >= iTemp46);
			double fTemp228 = double(iRec140[0]);
			double fTemp229 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp228, std::max<double>(fSlow106 * (fSlow103 - fTemp228) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec139[0])));
			double fTemp230 = fSlow40 * fTemp229 * (fConst24 * (fRec138[0] * fSlow524 / fSlow527) + fRec138[2] * fSlow528);
			double fTemp231 = fRec141[1] + fSlow533;
			fRec141[0] = fTemp231 - std::floor(fTemp231);
			double fTemp232 = scaleIt_faustpower2_f(2.0 * fRec141[0] + -1.0);
			fVec52[0] = fTemp232;
			double fTemp233 = fTemp3 * (fTemp232 - fVec52[1]) / fSlow532;
			fVec53[IOTA0 & 4095] = fTemp233;
			double fTemp234 = fConst29 * (fTemp233 - fVec53[(IOTA0 - iSlow535) & 4095] * fSlow539 - fSlow538 * fVec53[(IOTA0 - iSlow536) & 4095]);
			fRec142[0] = 0.999 * fRec142[1] + fTemp234;
			double fElse490 = fConst132 * fRec142[0] * fSlow519;
			double fTemp235 = fRec143[1] + fSlow541;
			double fTemp236 = fTemp235 + -1.0;
			int iTemp237 = fTemp236 < 0.0;
			fRec143[0] = ((iTemp237) ? fTemp235 : fTemp236);
			double fThen492 = fTemp235 + fTemp236 * fSlow542;
			double fRec144 = ((iTemp237) ? fTemp235 : fThen492);
			double fElse493 = 2.0 * fRec144 + -1.0;
			double fTemp238 = fRec145[1] + fSlow543;
			fRec145[0] = fTemp238 - std::floor(fTemp238);
			double fElse494 = ftbl16scaleItSIG16[int(65536.0 * fRec145[0])];
			double fTemp239 = fSlow60 * fTemp229 * (((iSlow57) ? fElse494 : 0.0) + ((iSlow53) ? fElse493 : 0.0) + ((iSlow52) ? fElse490 : 0.0) + ((iSlow42) ? fTemp234 : 0.0));
			double fTemp240 = fRec146[1] + fSlow548;
			fRec146[0] = fTemp240 - std::floor(fTemp240);
			double fTemp241 = scaleIt_faustpower2_f(2.0 * fRec146[0] + -1.0);
			fVec54[0] = fTemp241;
			double fTemp242 = fTemp3 * (fTemp241 - fVec54[1]) / fSlow547;
			fVec55[IOTA0 & 4095] = fTemp242;
			double fTemp243 = fConst29 * (fTemp242 - fVec55[(IOTA0 - iSlow550) & 4095] * fSlow554 - fSlow553 * fVec55[(IOTA0 - iSlow551) & 4095]);
			fRec147[0] = 0.999 * fRec147[1] + fTemp243;
			double fElse496 = fConst132 * fRec147[0] * fSlow224;
			double fTemp244 = fRec148[1] + fSlow556;
			double fTemp245 = fTemp244 + -1.0;
			int iTemp246 = fTemp245 < 0.0;
			fRec148[0] = ((iTemp246) ? fTemp244 : fTemp245);
			double fThen498 = fTemp244 + fTemp245 * fSlow557;
			double fRec149 = ((iTemp246) ? fTemp244 : fThen498);
			double fElse499 = 2.0 * fRec149 + -1.0;
			double fTemp247 = fRec150[1] + fSlow558;
			fRec150[0] = fTemp247 - std::floor(fTemp247);
			double fElse500 = ftbl16scaleItSIG16[int(65536.0 * fRec150[0])];
			double fTemp248 = (((iSlow57) ? fElse500 : 0.0) + ((iSlow53) ? fElse499 : 0.0) + ((iSlow52) ? fElse496 : 0.0) + ((iSlow42) ? fTemp243 : 0.0)) * fSlow60;
			fRec151[0] = fTemp0 - (fRec151[1] * fSlow570 + fRec151[2] * fSlow569) / fSlow567;
			double fTemp249 = (fConst24 * (fRec151[0] * fSlow564 / fSlow567) + fRec151[2] * fSlow568) * fSlow40;
			iRec152[0] = (iRec152[1] + 1) * (iTemp38 == 0);
			iRec153[0] = iTemp38 + iRec153[1] * (iVec5[1] >= iTemp38);
			double fTemp250 = double(iRec153[0]);
			double fTemp251 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp250, std::max<double>(fSlow106 * (fSlow103 - fTemp250) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec152[0])));
			double fTemp252 = fTemp251 * (fTemp249 + fSlow560 * fTemp248) + fSlow545 * fTemp239 + fTemp230 + fSlow517 * fTemp227 + fTemp218 + fSlow492 * fTemp215 + fTemp206 + fSlow464 * fTemp203 + fTemp194 + fSlow439 * fTemp191 + fTemp182 + fSlow411 * fTemp179 + fTemp170 + fSlow386 * fTemp167 + fTemp158 + fSlow358 * fTemp155 + fTemp146 + fSlow333 * fTemp143 + fTemp134 + fSlow305 * fTemp131 + fTemp122 + fSlow280 * fTemp119 + fTemp110;
			fRec57[0] = fConst111 * std::fabs(0.5 * fTemp252) + fConst3 * fRec57[1];
			fRec56[0] = fConst112 * (0.0 - 0.9666666666666667 * std::max<double>(2e+01 * std::log10(std::max<double>(1.1754944e-38, fRec57[0])) + 7.9588003, 0.0)) + fConst2 * fRec56[1];
			double fTemp253 = fTemp252 * std::pow(1e+01, 0.05 * fRec56[0]);
			double fTemp254 = std::fabs(0.5 * fTemp253);
			double fTemp255 = ((fTemp254 > fRec55[1]) ? fConst114 : fConst113);
			fRec55[0] = fTemp254 * (1.0 - fTemp255) + fRec55[1] * fTemp255;
			fRec54[0] = fConst115 * (0.0 - 0.75 * std::max<double>(2e+01 * std::log10(std::max<double>(1.1754944e-38, fRec55[0])) + 6.0, 0.0)) + fConst1 * fRec54[1];
			output0[i0] = FAUSTFLOAT(fSlow571 * fTemp253 * std::pow(1e+01, 0.05 * fRec54[0]) + fSlow252 * fTemp105 * std::pow(1e+01, 0.05 * fRec0[0]));
			fRec158[0] = fTemp0 - (fRec158[1] * fSlow584 + fRec158[2] * fSlow583) / fSlow581;
			double fTemp256 = fRec159[1] + fSlow587;
			fRec159[0] = fTemp256 - std::floor(fTemp256);
			double fTemp257 = scaleIt_faustpower2_f(2.0 * fRec159[0] + -1.0);
			fVec56[0] = fTemp257;
			double fTemp258 = fTemp3 * (fTemp257 - fVec56[1]) / fSlow586;
			fVec57[IOTA0 & 4095] = fTemp258;
			double fTemp259 = fConst29 * (fTemp258 - fVec57[(IOTA0 - iSlow589) & 4095] * fSlow593 - fSlow592 * fVec57[(IOTA0 - iSlow590) & 4095]);
			fRec160[0] = 0.999 * fRec160[1] + fTemp259;
			double fElse507 = fConst30 * fRec160[0] * fSlow574;
			double fTemp260 = fRec161[1] + fSlow595;
			double fTemp261 = fTemp260 + -1.0;
			int iTemp262 = fTemp261 < 0.0;
			fRec161[0] = ((iTemp262) ? fTemp260 : fTemp261);
			double fThen509 = fTemp260 + fTemp261 * fSlow596;
			double fRec162 = ((iTemp262) ? fTemp260 : fThen509);
			double fElse510 = 2.0 * fRec162 + -1.0;
			double fTemp263 = fRec163[1] + fSlow597;
			fRec163[0] = fTemp263 - std::floor(fTemp263);
			double fElse511 = ftbl16scaleItSIG16[int(65536.0 * fRec163[0])];
			int iTemp264 = iTemp51 * (fTemp44 == 11.0);
			iVec58[0] = iTemp264;
			iRec164[0] = (iRec164[1] + 1) * (iTemp264 == 0);
			iRec165[0] = iTemp264 + iRec165[1] * (iVec58[1] >= iTemp264);
			double fTemp265 = double(iRec165[0]);
			fRec166[0] = fTemp0 - (fRec166[1] * fSlow610 + fRec166[2] * fSlow609) / fSlow607;
			double fTemp266 = fRec167[1] + fSlow613;
			fRec167[0] = fTemp266 - std::floor(fTemp266);
			double fTemp267 = scaleIt_faustpower2_f(2.0 * fRec167[0] + -1.0);
			fVec59[0] = fTemp267;
			double fTemp268 = fTemp3 * (fTemp267 - fVec59[1]) / fSlow612;
			fVec60[IOTA0 & 4095] = fTemp268;
			double fTemp269 = fConst29 * (fTemp268 - fVec60[(IOTA0 - iSlow615) & 4095] * fSlow619 - fSlow618 * fVec60[(IOTA0 - iSlow616) & 4095]);
			fRec168[0] = 0.999 * fRec168[1] + fTemp269;
			double fElse516 = fConst30 * fRec168[0] * fSlow600;
			double fTemp270 = fRec169[1] + fSlow621;
			double fTemp271 = fTemp270 + -1.0;
			int iTemp272 = fTemp271 < 0.0;
			fRec169[0] = ((iTemp272) ? fTemp270 : fTemp271);
			double fThen518 = fTemp270 + fTemp271 * fSlow622;
			double fRec170 = ((iTemp272) ? fTemp270 : fThen518);
			double fElse519 = 2.0 * fRec170 + -1.0;
			double fTemp273 = fRec171[1] + fSlow623;
			fRec171[0] = fTemp273 - std::floor(fTemp273);
			double fElse520 = ftbl16scaleItSIG16[int(65536.0 * fRec171[0])];
			int iTemp274 = iTemp51 * (fTemp44 == 9.0);
			iVec61[0] = iTemp274;
			iRec172[0] = (iRec172[1] + 1) * (iTemp274 == 0);
			iRec173[0] = iTemp274 + iRec173[1] * (iVec61[1] >= iTemp274);
			double fTemp275 = double(iRec173[0]);
			fRec174[0] = fTemp0 - (fRec174[1] * fSlow636 + fRec174[2] * fSlow635) / fSlow633;
			double fTemp276 = fRec175[1] + fSlow639;
			fRec175[0] = fTemp276 - std::floor(fTemp276);
			double fTemp277 = scaleIt_faustpower2_f(2.0 * fRec175[0] + -1.0);
			fVec62[0] = fTemp277;
			double fTemp278 = fTemp3 * (fTemp277 - fVec62[1]) / fSlow638;
			fVec63[IOTA0 & 4095] = fTemp278;
			double fTemp279 = fConst29 * (fTemp278 - fVec63[(IOTA0 - iSlow641) & 4095] * fSlow645 - fSlow644 * fVec63[(IOTA0 - iSlow642) & 4095]);
			fRec176[0] = 0.999 * fRec176[1] + fTemp279;
			double fElse525 = fConst30 * fRec176[0] * fSlow626;
			double fTemp280 = fRec177[1] + fSlow647;
			double fTemp281 = fTemp280 + -1.0;
			int iTemp282 = fTemp281 < 0.0;
			fRec177[0] = ((iTemp282) ? fTemp280 : fTemp281);
			double fThen527 = fTemp280 + fTemp281 * fSlow648;
			double fRec178 = ((iTemp282) ? fTemp280 : fThen527);
			double fElse528 = 2.0 * fRec178 + -1.0;
			double fTemp283 = fRec179[1] + fSlow649;
			fRec179[0] = fTemp283 - std::floor(fTemp283);
			double fElse529 = ftbl16scaleItSIG16[int(65536.0 * fRec179[0])];
			int iTemp284 = iTemp51 * (fTemp44 == 7.0);
			iVec64[0] = iTemp284;
			iRec180[0] = (iRec180[1] + 1) * (iTemp284 == 0);
			iRec181[0] = iTemp284 + iRec181[1] * (iVec64[1] >= iTemp284);
			double fTemp285 = double(iRec181[0]);
			fRec182[0] = fTemp0 - (fRec182[1] * fSlow662 + fRec182[2] * fSlow661) / fSlow659;
			double fTemp286 = fRec183[1] + fSlow665;
			fRec183[0] = fTemp286 - std::floor(fTemp286);
			double fTemp287 = scaleIt_faustpower2_f(2.0 * fRec183[0] + -1.0);
			fVec65[0] = fTemp287;
			double fTemp288 = fTemp3 * (fTemp287 - fVec65[1]) / fSlow664;
			fVec66[IOTA0 & 4095] = fTemp288;
			double fTemp289 = fConst29 * (fTemp288 - fVec66[(IOTA0 - iSlow667) & 4095] * fSlow671 - fSlow670 * fVec66[(IOTA0 - iSlow668) & 4095]);
			fRec184[0] = 0.999 * fRec184[1] + fTemp289;
			double fElse534 = fConst30 * fRec184[0] * fSlow652;
			double fTemp290 = fRec185[1] + fSlow673;
			double fTemp291 = fTemp290 + -1.0;
			int iTemp292 = fTemp291 < 0.0;
			fRec185[0] = ((iTemp292) ? fTemp290 : fTemp291);
			double fThen536 = fTemp290 + fTemp291 * fSlow674;
			double fRec186 = ((iTemp292) ? fTemp290 : fThen536);
			double fElse537 = 2.0 * fRec186 + -1.0;
			double fTemp293 = fRec187[1] + fSlow675;
			fRec187[0] = fTemp293 - std::floor(fTemp293);
			double fElse538 = ftbl16scaleItSIG16[int(65536.0 * fRec187[0])];
			int iTemp294 = iTemp51 * (fTemp44 == 5.0);
			iVec67[0] = iTemp294;
			iRec188[0] = (iRec188[1] + 1) * (iTemp294 == 0);
			iRec189[0] = iTemp294 + iRec189[1] * (iVec67[1] >= iTemp294);
			double fTemp295 = double(iRec189[0]);
			fRec190[0] = fTemp0 - (fRec190[1] * fSlow688 + fRec190[2] * fSlow687) / fSlow685;
			double fTemp296 = fRec191[1] + fSlow691;
			fRec191[0] = fTemp296 - std::floor(fTemp296);
			double fTemp297 = scaleIt_faustpower2_f(2.0 * fRec191[0] + -1.0);
			fVec68[0] = fTemp297;
			double fTemp298 = fTemp3 * (fTemp297 - fVec68[1]) / fSlow690;
			fVec69[IOTA0 & 4095] = fTemp298;
			double fTemp299 = fConst29 * (fTemp298 - fVec69[(IOTA0 - iSlow693) & 4095] * fSlow697 - fSlow696 * fVec69[(IOTA0 - iSlow694) & 4095]);
			fRec192[0] = 0.999 * fRec192[1] + fTemp299;
			double fElse543 = fConst30 * fRec192[0] * fSlow678;
			double fTemp300 = fRec193[1] + fSlow699;
			double fTemp301 = fTemp300 + -1.0;
			int iTemp302 = fTemp301 < 0.0;
			fRec193[0] = ((iTemp302) ? fTemp300 : fTemp301);
			double fThen545 = fTemp300 + fTemp301 * fSlow700;
			double fRec194 = ((iTemp302) ? fTemp300 : fThen545);
			double fElse546 = 2.0 * fRec194 + -1.0;
			double fTemp303 = fRec195[1] + fSlow701;
			fRec195[0] = fTemp303 - std::floor(fTemp303);
			double fElse547 = ftbl16scaleItSIG16[int(65536.0 * fRec195[0])];
			int iTemp304 = iTemp51 * (fTemp44 == 3.0);
			iVec70[0] = iTemp304;
			iRec196[0] = (iRec196[1] + 1) * (iTemp304 == 0);
			iRec197[0] = iTemp304 + iRec197[1] * (iVec70[1] >= iTemp304);
			double fTemp305 = double(iRec197[0]);
			fRec198[0] = fTemp0 - (fRec198[1] * fSlow714 + fRec198[2] * fSlow713) / fSlow711;
			double fTemp306 = fRec199[1] + fSlow717;
			fRec199[0] = fTemp306 - std::floor(fTemp306);
			double fTemp307 = scaleIt_faustpower2_f(2.0 * fRec199[0] + -1.0);
			fVec71[0] = fTemp307;
			double fTemp308 = fTemp3 * (fTemp307 - fVec71[1]) / fSlow716;
			fVec72[IOTA0 & 4095] = fTemp308;
			double fTemp309 = fConst29 * (fTemp308 - fVec72[(IOTA0 - iSlow719) & 4095] * fSlow723 - fSlow722 * fVec72[(IOTA0 - iSlow720) & 4095]);
			fRec200[0] = 0.999 * fRec200[1] + fTemp309;
			double fElse552 = fConst30 * fRec200[0] * fSlow704;
			double fTemp310 = fRec201[1] + fSlow725;
			double fTemp311 = fTemp310 + -1.0;
			int iTemp312 = fTemp311 < 0.0;
			fRec201[0] = ((iTemp312) ? fTemp310 : fTemp311);
			double fThen554 = fTemp310 + fTemp311 * fSlow726;
			double fRec202 = ((iTemp312) ? fTemp310 : fThen554);
			double fElse555 = 2.0 * fRec202 + -1.0;
			double fTemp313 = fRec203[1] + fSlow727;
			fRec203[0] = fTemp313 - std::floor(fTemp313);
			double fElse556 = ftbl16scaleItSIG16[int(65536.0 * fRec203[0])];
			int iTemp314 = iTemp51 * (fTemp44 == 1.0);
			iVec73[0] = iTemp314;
			iRec204[0] = (iRec204[1] + 1) * (iTemp314 == 0);
			iRec205[0] = iTemp314 + iRec205[1] * (iVec73[1] >= iTemp314);
			double fTemp315 = double(iRec205[0]);
			double fTemp316 = std::max<double>(0.0, std::min<double>(fSlow104 * fTemp315, std::max<double>(fSlow106 * (fSlow103 - fTemp315) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec204[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse556 : 0.0) + ((iSlow53) ? fElse555 : 0.0) + ((iSlow52) ? fElse552 : 0.0) + ((iSlow42) ? fTemp309 : 0.0)) + fSlow40 * (fConst24 * (fRec198[0] * fSlow708 / fSlow711) + fRec198[2] * fSlow712)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp305, std::max<double>(fSlow106 * (fSlow103 - fTemp305) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec196[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse547 : 0.0) + ((iSlow53) ? fElse546 : 0.0) + ((iSlow52) ? fElse543 : 0.0) + ((iSlow42) ? fTemp299 : 0.0)) + fSlow40 * (fConst24 * (fRec190[0] * fSlow682 / fSlow685) + fRec190[2] * fSlow686)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp295, std::max<double>(fSlow106 * (fSlow103 - fTemp295) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec188[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse538 : 0.0) + ((iSlow53) ? fElse537 : 0.0) + ((iSlow52) ? fElse534 : 0.0) + ((iSlow42) ? fTemp289 : 0.0)) + fSlow40 * (fConst24 * (fRec182[0] * fSlow656 / fSlow659) + fRec182[2] * fSlow660)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp285, std::max<double>(fSlow106 * (fSlow103 - fTemp285) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec180[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse529 : 0.0) + ((iSlow53) ? fElse528 : 0.0) + ((iSlow52) ? fElse525 : 0.0) + ((iSlow42) ? fTemp279 : 0.0)) + fSlow40 * (fConst24 * (fRec174[0] * fSlow630 / fSlow633) + fRec174[2] * fSlow634)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp275, std::max<double>(fSlow106 * (fSlow103 - fTemp275) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec172[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse520 : 0.0) + ((iSlow53) ? fElse519 : 0.0) + ((iSlow52) ? fElse516 : 0.0) + ((iSlow42) ? fTemp269 : 0.0)) + fSlow40 * (fConst24 * (fRec166[0] * fSlow604 / fSlow607) + fRec166[2] * fSlow608)) + std::max<double>(0.0, std::min<double>(fSlow104 * fTemp265, std::max<double>(fSlow106 * (fSlow103 - fTemp265) + 1.0, fSlow105)) * (1.0 - fSlow102 * double(iRec164[0]))) * (0.5 * fSlow60 * (((iSlow57) ? fElse511 : 0.0) + ((iSlow53) ? fElse510 : 0.0) + ((iSlow52) ? fElse507 : 0.0) + ((iSlow42) ? fTemp259 : 0.0)) + fSlow40 * (fConst24 * (fRec158[0] * fSlow578 / fSlow581) + fRec158[2] * fSlow582));
			fRec157[0] = fConst111 * std::fabs(fTemp316) + fConst3 * fRec157[1];
			fRec156[0] = fConst112 * (0.0 - 0.9666666666666667 * std::max<double>(2e+01 * std::log10(std::max<double>(1.1754944e-38, fRec157[0])) + 7.9588003, 0.0)) + fConst2 * fRec156[1];
			double fTemp317 = fTemp316 * std::pow(1e+01, 0.05 * fRec156[0]);
			double fTemp318 = std::fabs(fTemp317);
			double fTemp319 = ((fTemp318 > fRec155[1]) ? fConst114 : fConst113);
			fRec155[0] = fTemp318 * (1.0 - fTemp319) + fRec155[1] * fTemp319;
			fRec154[0] = fConst115 * (0.0 - 0.75 * std::max<double>(2e+01 * std::log10(std::max<double>(1.1754944e-38, fRec155[0])) + 6.0, 0.0)) + fConst1 * fRec154[1];
			double fTemp320 = fTemp110 + fTemp122 + fTemp134 + fTemp146 + fTemp158 + fTemp170 + fTemp182 + fTemp194 + fTemp206 + fTemp218 + fTemp230 + fTemp251 * (fTemp249 + fSlow559 * fTemp248) + fSlow544 * fTemp239 + fSlow516 * fTemp227 + fSlow491 * fTemp215 + fSlow463 * fTemp203 + fSlow438 * fTemp191 + fSlow410 * fTemp179 + fSlow385 * fTemp167 + fSlow357 * fTemp155 + fSlow332 * fTemp143 + fSlow304 * fTemp131 + fSlow279 * fTemp119;
			fRec209[0] = fConst111 * std::fabs(0.5 * fTemp320) + fConst3 * fRec209[1];
			fRec208[0] = fConst112 * (0.0 - 0.9666666666666667 * std::max<double>(2e+01 * std::log10(std::max<double>(1.1754944e-38, fRec209[0])) + 7.9588003, 0.0)) + fConst2 * fRec208[1];
			double fTemp321 = fTemp320 * std::pow(1e+01, 0.05 * fRec208[0]);
			double fTemp322 = std::fabs(0.5 * fTemp321);
			double fTemp323 = ((fTemp322 > fRec207[1]) ? fConst114 : fConst113);
			fRec207[0] = fTemp322 * (1.0 - fTemp323) + fRec207[1] * fTemp323;
			fRec206[0] = fConst115 * (0.0 - 0.75 * std::max<double>(2e+01 * std::log10(std::max<double>(1.1754944e-38, fRec207[0])) + 6.0, 0.0)) + fConst1 * fRec206[1];
			output1[i0] = FAUSTFLOAT(fSlow571 * fTemp321 * std::pow(1e+01, 0.05 * fRec206[0]) + fSlow252 * fTemp317 * std::pow(1e+01, 0.05 * fRec154[0]));
			double fTemp324 = fSlow728 * double(iTemp38);
			double fTemp325 = fSlow729 * double(iTemp46);
			double fTemp326 = fSlow730 * double(iTemp33);
			double fTemp327 = fSlow731 * double(iTemp45);
			double fTemp328 = fSlow732 * double(iTemp39);
			double fTemp329 = fSlow733 * double(iTemp47);
			double fTemp330 = fSlow734 * double(iTemp40);
			double fTemp331 = fSlow735 * double(iTemp48);
			double fTemp332 = fSlow736 * double(iTemp41);
			double fTemp333 = fSlow737 * double(iTemp49);
			double fTemp334 = fSlow738 * double(iTemp42);
			double fTemp335 = fSlow739 * double(iTemp50);
			double fThen571 = std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(fTemp324, fTemp325), fTemp326), fTemp327), fTemp328), fTemp329), fTemp330), fTemp331), fTemp332), fTemp333), fTemp334), fTemp335);
			double fElse571 = std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(fTemp324, fTemp325), fTemp326), fTemp327), fTemp328), fTemp329), fTemp330), fTemp331), fTemp332), fTemp333), fTemp334), fTemp335);
			output2[i0] = FAUSTFLOAT(((iSlow25) ? fElse571 : fThen571));
			iVec0[1] = iVec0[0];
			iRec5[1] = iRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fVec1[1] = fVec1[0];
			IOTA0 = IOTA0 + 1;
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			iVec4[1] = iVec4[0];
			iVec5[1] = iVec5[0];
			iVec6[1] = iVec6[0];
			iVec7[1] = iVec7[0];
			iVec8[1] = iVec8[0];
			iVec9[1] = iVec9[0];
			iVec10[1] = iVec10[0];
			iVec11[1] = iVec11[0];
			iVec12[1] = iVec12[0];
			iVec13[1] = iVec13[0];
			iVec14[1] = iVec14[0];
			iVec15[1] = iVec15[0];
			iVec16[1] = iVec16[0];
			iRec12[1] = iRec12[0];
			iRec13[1] = iRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fVec17[1] = fVec17[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec19[1] = fRec19[0];
			iVec19[1] = iVec19[0];
			iRec20[1] = iRec20[0];
			iRec21[1] = iRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fVec20[1] = fVec20[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			iVec22[1] = iVec22[0];
			iRec28[1] = iRec28[0];
			iRec29[1] = iRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			fVec23[1] = fVec23[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fRec35[1] = fRec35[0];
			iVec25[1] = iVec25[0];
			iRec36[1] = iRec36[0];
			iRec37[1] = iRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fVec26[1] = fVec26[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec43[1] = fRec43[0];
			iVec28[1] = iVec28[0];
			iRec44[1] = iRec44[0];
			iRec45[1] = iRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fVec29[1] = fVec29[0];
			fRec48[1] = fRec48[0];
			fRec49[1] = fRec49[0];
			fRec51[1] = fRec51[0];
			iVec31[1] = iVec31[0];
			iRec52[1] = iRec52[0];
			iRec53[1] = iRec53[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			iRec59[1] = iRec59[0];
			iRec60[1] = iRec60[0];
			fRec61[1] = fRec61[0];
			fVec32[1] = fVec32[0];
			fRec62[1] = fRec62[0];
			fRec63[1] = fRec63[0];
			fRec65[1] = fRec65[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			iRec67[1] = iRec67[0];
			iRec68[1] = iRec68[0];
			fRec69[1] = fRec69[0];
			fVec34[1] = fVec34[0];
			fRec70[1] = fRec70[0];
			fRec71[1] = fRec71[0];
			fRec73[1] = fRec73[0];
			fRec74[2] = fRec74[1];
			fRec74[1] = fRec74[0];
			iRec75[1] = iRec75[0];
			iRec76[1] = iRec76[0];
			fRec77[1] = fRec77[0];
			fVec36[1] = fVec36[0];
			fRec78[1] = fRec78[0];
			fRec79[1] = fRec79[0];
			fRec81[1] = fRec81[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			iRec83[1] = iRec83[0];
			iRec84[1] = iRec84[0];
			fRec85[1] = fRec85[0];
			fVec38[1] = fVec38[0];
			fRec86[1] = fRec86[0];
			fRec87[1] = fRec87[0];
			fRec89[1] = fRec89[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			iRec91[1] = iRec91[0];
			iRec92[1] = iRec92[0];
			fRec93[1] = fRec93[0];
			fVec40[1] = fVec40[0];
			fRec94[1] = fRec94[0];
			fRec95[1] = fRec95[0];
			fRec97[1] = fRec97[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			iRec99[1] = iRec99[0];
			iRec100[1] = iRec100[0];
			fRec101[1] = fRec101[0];
			fVec42[1] = fVec42[0];
			fRec102[1] = fRec102[0];
			fRec103[1] = fRec103[0];
			fRec105[1] = fRec105[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			iRec107[1] = iRec107[0];
			iRec108[1] = iRec108[0];
			fRec109[1] = fRec109[0];
			fVec44[1] = fVec44[0];
			fRec110[1] = fRec110[0];
			fRec111[1] = fRec111[0];
			fRec113[1] = fRec113[0];
			fRec114[2] = fRec114[1];
			fRec114[1] = fRec114[0];
			iRec115[1] = iRec115[0];
			iRec116[1] = iRec116[0];
			fRec117[1] = fRec117[0];
			fVec46[1] = fVec46[0];
			fRec118[1] = fRec118[0];
			fRec119[1] = fRec119[0];
			fRec121[1] = fRec121[0];
			fRec122[2] = fRec122[1];
			fRec122[1] = fRec122[0];
			iRec123[1] = iRec123[0];
			iRec124[1] = iRec124[0];
			fRec125[1] = fRec125[0];
			fVec48[1] = fVec48[0];
			fRec126[1] = fRec126[0];
			fRec127[1] = fRec127[0];
			fRec129[1] = fRec129[0];
			fRec130[2] = fRec130[1];
			fRec130[1] = fRec130[0];
			iRec131[1] = iRec131[0];
			iRec132[1] = iRec132[0];
			fRec133[1] = fRec133[0];
			fVec50[1] = fVec50[0];
			fRec134[1] = fRec134[0];
			fRec135[1] = fRec135[0];
			fRec137[1] = fRec137[0];
			fRec138[2] = fRec138[1];
			fRec138[1] = fRec138[0];
			iRec139[1] = iRec139[0];
			iRec140[1] = iRec140[0];
			fRec141[1] = fRec141[0];
			fVec52[1] = fVec52[0];
			fRec142[1] = fRec142[0];
			fRec143[1] = fRec143[0];
			fRec145[1] = fRec145[0];
			fRec146[1] = fRec146[0];
			fVec54[1] = fVec54[0];
			fRec147[1] = fRec147[0];
			fRec148[1] = fRec148[0];
			fRec150[1] = fRec150[0];
			fRec151[2] = fRec151[1];
			fRec151[1] = fRec151[0];
			iRec152[1] = iRec152[0];
			iRec153[1] = iRec153[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec158[2] = fRec158[1];
			fRec158[1] = fRec158[0];
			fRec159[1] = fRec159[0];
			fVec56[1] = fVec56[0];
			fRec160[1] = fRec160[0];
			fRec161[1] = fRec161[0];
			fRec163[1] = fRec163[0];
			iVec58[1] = iVec58[0];
			iRec164[1] = iRec164[0];
			iRec165[1] = iRec165[0];
			fRec166[2] = fRec166[1];
			fRec166[1] = fRec166[0];
			fRec167[1] = fRec167[0];
			fVec59[1] = fVec59[0];
			fRec168[1] = fRec168[0];
			fRec169[1] = fRec169[0];
			fRec171[1] = fRec171[0];
			iVec61[1] = iVec61[0];
			iRec172[1] = iRec172[0];
			iRec173[1] = iRec173[0];
			fRec174[2] = fRec174[1];
			fRec174[1] = fRec174[0];
			fRec175[1] = fRec175[0];
			fVec62[1] = fVec62[0];
			fRec176[1] = fRec176[0];
			fRec177[1] = fRec177[0];
			fRec179[1] = fRec179[0];
			iVec64[1] = iVec64[0];
			iRec180[1] = iRec180[0];
			iRec181[1] = iRec181[0];
			fRec182[2] = fRec182[1];
			fRec182[1] = fRec182[0];
			fRec183[1] = fRec183[0];
			fVec65[1] = fVec65[0];
			fRec184[1] = fRec184[0];
			fRec185[1] = fRec185[0];
			fRec187[1] = fRec187[0];
			iVec67[1] = iVec67[0];
			iRec188[1] = iRec188[0];
			iRec189[1] = iRec189[0];
			fRec190[2] = fRec190[1];
			fRec190[1] = fRec190[0];
			fRec191[1] = fRec191[0];
			fVec68[1] = fVec68[0];
			fRec192[1] = fRec192[0];
			fRec193[1] = fRec193[0];
			fRec195[1] = fRec195[0];
			iVec70[1] = iVec70[0];
			iRec196[1] = iRec196[0];
			iRec197[1] = iRec197[0];
			fRec198[2] = fRec198[1];
			fRec198[1] = fRec198[0];
			fRec199[1] = fRec199[0];
			fVec71[1] = fVec71[0];
			fRec200[1] = fRec200[0];
			fRec201[1] = fRec201[0];
			fRec203[1] = fRec203[0];
			iVec73[1] = iVec73[0];
			iRec204[1] = iRec204[0];
			iRec205[1] = iRec205[0];
			fRec157[1] = fRec157[0];
			fRec156[1] = fRec156[0];
			fRec155[1] = fRec155[0];
			fRec154[1] = fRec154[0];
			fRec209[1] = fRec209[0];
			fRec208[1] = fRec208[0];
			fRec207[1] = fRec207[0];
			fRec206[1] = fRec206[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "scaleIt.dsp"
	#define FAUST_CLASS_NAME "scaleIt"
	#define FAUST_COMPILATION_OPIONS "-a /usr/local/share/faust/max-msp/max-msp64.cpp -lang cpp -i -cn scaleIt -es 1 -mcd 16 -uim -double -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 3
	#define FAUST_ACTIVES 40
	#define FAUST_PASSIVES 0

	FAUST_ADDNUMENTRY("accordPan0", fEntry38, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan1", fEntry37, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan10", fEntry23, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan11", fEntry22, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan2", fEntry35, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan3", fEntry34, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan4", fEntry32, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan5", fEntry31, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan6", fEntry29, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan7", fEntry28, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan8", fEntry26, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan9", fEntry25, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("activeSteps", fEntry8, 8.0, 0.0, 12.0, 1.0);
	FAUST_ADDNUMENTRY("baseKeyMIDI", fEntry3, 69.0, 0.0, 128.0, 1.0);
	FAUST_ADDNUMENTRY("curve", fEntry9, 0.0, -1e+01, 1e+01, 0.01);
	FAUST_ADDNUMENTRY("customScale0", fEntry19, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale1", fEntry36, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale10", fEntry2, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale11", fEntry21, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale2", fEntry18, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale3", fEntry33, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale4", fEntry17, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale5", fEntry30, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale6", fEntry16, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale7", fEntry27, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale8", fEntry15, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale9", fEntry24, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("envAttack", fEntry12, 0.5, 0.0, 5.0, 0.05);
	FAUST_ADDNUMENTRY("envDecay", fEntry13, 0.0, 0.0, 5.0, 0.05);
	FAUST_ADDNUMENTRY("envRelease", fEntry11, 0.5, 0.0, 5.0, 0.05);
	FAUST_ADDNUMENTRY("envSustain", fEntry14, 1.0, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("gameAccordON", fEntry39, 0.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("gameToneON", fEntry20, 0.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("invert", fEntry4, 0.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("noiseLevel", fEntry5, 0.0, 0.0, 127.0, 1.0);
	FAUST_ADDNUMENTRY("oscType", fEntry6, 0.0, 0.0, 4.0, 1.0);
	FAUST_ADDNUMENTRY("playBelow", fEntry10, 1.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("scale", fEntry1, 0.0, 0.0, 15.0, 1.0);
	FAUST_ADDNUMENTRY("scaleDown", fEntry0, 0.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("synthLevel", fEntry7, 64.0, 0.0, 127.0, 1.0);

	#define FAUST_LIST_ACTIVES(p) \
		p(NUMENTRY, accordPan0, "accordPan0", fEntry38, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan1, "accordPan1", fEntry37, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan10, "accordPan10", fEntry23, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan11, "accordPan11", fEntry22, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan2, "accordPan2", fEntry35, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan3, "accordPan3", fEntry34, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan4, "accordPan4", fEntry32, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan5, "accordPan5", fEntry31, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan6, "accordPan6", fEntry29, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan7, "accordPan7", fEntry28, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan8, "accordPan8", fEntry26, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan9, "accordPan9", fEntry25, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, activeSteps, "activeSteps", fEntry8, 8.0, 0.0, 12.0, 1.0) \
		p(NUMENTRY, baseKeyMIDI, "baseKeyMIDI", fEntry3, 69.0, 0.0, 128.0, 1.0) \
		p(NUMENTRY, curve, "curve", fEntry9, 0.0, -1e+01, 1e+01, 0.01) \
		p(NUMENTRY, customScale0, "customScale0", fEntry19, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale1, "customScale1", fEntry36, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale10, "customScale10", fEntry2, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale11, "customScale11", fEntry21, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale2, "customScale2", fEntry18, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale3, "customScale3", fEntry33, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale4, "customScale4", fEntry17, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale5, "customScale5", fEntry30, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale6, "customScale6", fEntry16, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale7, "customScale7", fEntry27, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale8, "customScale8", fEntry15, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale9, "customScale9", fEntry24, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, envAttack, "envAttack", fEntry12, 0.5, 0.0, 5.0, 0.05) \
		p(NUMENTRY, envDecay, "envDecay", fEntry13, 0.0, 0.0, 5.0, 0.05) \
		p(NUMENTRY, envRelease, "envRelease", fEntry11, 0.5, 0.0, 5.0, 0.05) \
		p(NUMENTRY, envSustain, "envSustain", fEntry14, 1.0, 0.0, 1.0, 0.05) \
		p(NUMENTRY, gameAccordON, "gameAccordON", fEntry39, 0.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, gameToneON, "gameToneON", fEntry20, 0.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, invert, "invert", fEntry4, 0.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, noiseLevel, "noiseLevel", fEntry5, 0.0, 0.0, 127.0, 1.0) \
		p(NUMENTRY, oscType, "oscType", fEntry6, 0.0, 0.0, 4.0, 1.0) \
		p(NUMENTRY, playBelow, "playBelow", fEntry10, 1.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, scale, "scale", fEntry1, 0.0, 0.0, 15.0, 1.0) \
		p(NUMENTRY, scaleDown, "scaleDown", fEntry0, 0.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, synthLevel, "synthLevel", fEntry7, 64.0, 0.0, 127.0, 1.0) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1
#define ASSIST_OUTLET 	2

#define EXTERNAL_VERSION    "0.86"
#define STR_SIZE            512

/************************** BEGIN MidiUI.h ****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>

/************************** BEGIN MapUI.h ******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***********************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>
#include <stdio.h>


/*******************************************************************************
 * MapUI : Faust User Interface.
 *
 * This class creates:
 * - a map of 'labels' and zones for each UI item.
 * - a map of unique 'shortname' (built so that they never collide) and zones for each UI item
 * - a map of complete hierarchical 'paths' and zones for each UI item
 *
 * Simple 'labels', 'shortname' and complete 'paths' (to fully discriminate between possible same
 * 'labels' at different location in the UI hierachy) can be used to access a given parameter.
 ******************************************************************************/

class FAUST_API MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
        // Shortname zone map
        std::map<std::string, FAUSTFLOAT*> fShortnameZoneMap;
    
        // Full path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        void addZoneLabel(const std::string& label, FAUSTFLOAT* zone)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            fPathZoneMap[path] = zone;
            fLabelZoneMap[label] = zone;
        }
    
    public:
        
        MapUI() {}
        virtual ~MapUI() {}
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' map
                for (const auto& it : fFullPaths) {
                    fShortnameZoneMap[fFull2Short[it]] = fPathZoneMap[it];
                }
            }
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
    
        //-------------------------------------------------------------------------------
        // Public API
        //-------------------------------------------------------------------------------
    
        /**
         * Set the param value.
         *
         * @param str - the UI parameter label/shortname/path
         * @param value - the UI parameter value
         *
         */
        void setParamValue(const std::string& str, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                *fPathZoneMap[str] = value;
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                *fShortnameZoneMap[str] = value;
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                *fLabelZoneMap[str] = value;
            } else {
                fprintf(stderr, "ERROR : setParamValue '%s' not found\n", str.c_str());
            }
        }
        
        /**
         * Return the param value.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return *fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return *fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[str];
            } else {
                fprintf(stderr, "ERROR : getParamValue '%s' not found\n", str.c_str());
                return 0;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getFullpathMap() { return fPathZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getShortnameMap() { return fShortnameZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getLabelMap() { return fLabelZoneMap; }
            
        /**
         * Return the number of parameters in the UI.
         *
         * @return the number of parameters
         */
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        /**
         * Return the param path.
         *
         * @param index - the UI parameter index
         *
         * @return the param path
         */
        std::string getParamAddress(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return "";
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamAddress1(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param shortname.
         *
         * @param index - the UI parameter index
         *
         * @return the param shortname
         */
        std::string getParamShortname(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return "";
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamShortname1(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param label.
         *
         * @param index - the UI parameter index
         *
         * @return the param label
         */
        std::string getParamLabel(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return "";
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamLabel1(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param path.
         *
         * @param zone - the UI parameter memory zone
         *
         * @return the param path
         */
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            for (const auto& it : fPathZoneMap) {
                if (it.second == zone) return it.first;
            }
            return "";
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter label/shortname/path
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return fLabelZoneMap[str];
            }
            return nullptr;
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter index
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->second;
            }
        }
    
        static bool endsWith(const std::string& str, const std::string& end)
        {
            size_t l1 = str.length();
            size_t l2 = end.length();
            return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
        }
    
};

#endif // FAUST_MAPUI_H
/**************************  END  MapUI.h **************************/
/************************** BEGIN midi.h *******************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <assert.h>


class FAUST_API MapUI;

/**
 * A timestamped short MIDI message used with SOUL.
 */

// Force contiguous memory layout
#pragma pack (push, 1)
struct MIDIMessage
{
    uint32_t frameIndex;
    uint8_t byte0, byte1, byte2;
};
#pragma pack (pop)

/**
 * For timestamped MIDI messages (in usec).
 */
struct DatedMessage {
    
    double fDate;
    unsigned char fBuffer[3];
    size_t fSize;
    
    DatedMessage(double date, unsigned char* buffer, size_t size)
    :fDate(date), fSize(size)
    {
        assert(size <= 3);
        memcpy(fBuffer, buffer, size);
    }
    
    DatedMessage():fDate(0.0), fSize(0)
    {}
    
};

/**
 * MIDI processor definition.
 *
 * MIDI input or output handling classes will implement this interface,
 * so the same method names (keyOn, keyOff, ctrlChange...) will be used either
 * when decoding MIDI input or encoding MIDI output events.
 * MIDI channel is numbered in [0..15] in this layer.
 */
class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 0)
        {
            keyOff(channel, pitch, velocity);
        }
    
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
    
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
    
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }
    
        virtual void rpn(double, int channel, int ctrl, int value)
        {
            rpn(channel, ctrl, value);
        }

        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
    
        virtual void sysEx(double, std::vector<unsigned char>& message)
        {
            sysEx(message);
        }

        // MIDI sync
        virtual void startSync(double date)  {}
        virtual void stopSync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return nullptr; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void rpn(int channel, int ctrl, int value)              {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}
        virtual void sysEx(std::vector<unsigned char>& message)         {}

        enum MidiStatus {
            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_CONT = 0xFB,
            MIDI_STOP = 0xFC,
            MIDI_SYSEX_START = 0xF0,
            MIDI_SYSEX_STOP = 0xF7
        };

        enum MidiCtrl {
            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120
        };
    
        enum MidiNPN {
            PITCH_BEND_RANGE = 0
        };

};

/**
 * A class to decode NRPN and RPN messages, adapted from JUCE forum message:
 * https://forum.juce.com/t/14bit-midi-controller-support/11517
 */
class MidiNRPN {
    
    private:
    
        bool ctrlnew;
        int ctrlnum;
        int ctrlval;
        
        int nrpn_lsb, nrpn_msb;
        int data_lsb, data_msb;
        
        enum
        {
            midi_nrpn_lsb = 98,
            midi_nrpn_msb = 99,
            midi_rpn_lsb  = 100,
            midi_rpn_msb  = 101,
            midi_data_lsb = 38,
            midi_data_msb = 6
        };
    
    public:
        
        MidiNRPN(): ctrlnew(false), nrpn_lsb(-1), nrpn_msb(-1), data_lsb(-1), data_msb(-1)
        {}
        
        // return true if the message has been filtered
        bool process(int data1, int data2)
        {
            switch (data1)
            {
                case midi_nrpn_lsb: nrpn_lsb = data2; return true;
                case midi_nrpn_msb: nrpn_msb = data2; return true;
                case midi_rpn_lsb: {
                    if (data2 == 127) {
                        nrpn_lsb = data_lsb = -1;
                    } else {
                        nrpn_lsb = 0;
                        data_lsb = -1;
                    }
                    return true;
                }
                case midi_rpn_msb: {
                    if (data2 == 127) {
                        nrpn_msb = data_msb = -1;
                    } else {
                        nrpn_msb = 0;
                        data_msb = -1;
                    }
                    return true;
                }
                case midi_data_lsb:
                case midi_data_msb:
                {
                    if (data1 == midi_data_msb) {
                        if (nrpn_msb < 0) {
                            return false;
                        }
                        data_msb = data2;
                    } else { // midi_data_lsb
                        if (nrpn_lsb < 0) {
                            return false;
                        }
                        data_lsb = data2;
                    }
                    if (data_lsb >= 0 && data_msb >= 0) {
                        ctrlnum = (nrpn_msb << 7) | nrpn_lsb;
                        ctrlval = (data_msb << 7) | data_lsb;
                        data_lsb = data_msb = -1;
                        nrpn_msb = nrpn_lsb = -1;
                        ctrlnew = true;
                    }
                    return true;
                }
                default: return false;
            };
        }
        
        bool hasNewNRPN() { bool res = ctrlnew; ctrlnew = false; return res; }
        
        // results in [0, 16383]
        int getCtrl() const { return ctrlnum; }
        int getVal() const { return ctrlval; }
    
};

/**
 * A pure interface for MIDI handlers that can send/receive MIDI messages to/from 'midi' objects.
 */
struct midi_interface {
    virtual void addMidiIn(midi* midi_dsp)      = 0;
    virtual void removeMidiIn(midi* midi_dsp)   = 0;
    virtual ~midi_interface() {}
};

/****************************************************
 * Base class for MIDI input handling.
 *
 * Shared common code used for input handling:
 * - decoding Real-Time messages: handleSync
 * - decoding one data byte messages: handleData1
 * - decoding two data byte messages: handleData2
 * - getting ready messages in polling mode
 ****************************************************/
class midi_handler : public midi, public midi_interface {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;
        MidiNRPN fNRPN;
    
        int range(int min, int max, int val) { return (val < min) ? min : ((val >= max) ? max : val); }
  
    public:

        midi_handler(const std::string& name = "MIDIHandler"):midi_interface(), fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        // Those 2 methods have to be implemented by subclasses
        virtual bool startMidi() { return true; }
        virtual void stopMidi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
    
        // To be used in polling mode
        virtual int recvMessages(std::vector<MIDIMessage>* message) { return 0; }
        virtual void sendMessages(std::vector<MIDIMessage>* message, int count) {}
    
        // MIDI Real-Time
        void handleClock(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->clock(time);
            }
        }
        
        void handleStart(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->startSync(time);
            }
        }
        
        void handleStop(double time)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->stopSync(time);
            }
        }
    
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                handleClock(time);
            // We can consider start and continue as identical messages
            } else if ((type == MIDI_START) || (type == MIDI_CONT)) {
                handleStart(time);
            } else if (type == MIDI_STOP) {
                handleStop(time);
            }
        }
    
        // MIDI 1 data
        void handleProgChange(double time, int channel, int data1)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->progChange(time, channel, data1);
            }
        }
    
        void handleAfterTouch(double time, int channel, int data1)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->chanPress(time, channel, data1);
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                handleProgChange(time, channel, data1);
            } else if (type == MIDI_AFTERTOUCH) {
                handleAfterTouch(time, channel, data1);
            }
        }
    
        // MIDI 2 datas
        void handleKeyOff(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->keyOff(time, channel, data1, data2);
            }
        }
        
        void handleKeyOn(double time, int channel, int data1, int data2)
        {
            if (data2 == 0) {
                handleKeyOff(time, channel, data1, data2);
            } else {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            }
        }
    
        void handleCtrlChange(double time, int channel, int data1, int data2)
        {
            // Special processing for NRPN and RPN
            if (fNRPN.process(data1, data2)) {
                if (fNRPN.hasNewNRPN()) {
                    for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                        fMidiInputs[i]->rpn(time, channel, fNRPN.getCtrl(), fNRPN.getVal());
                    }
                }
            } else {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            }
        }
        
        void handlePitchWheel(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->pitchWheel(time, channel, (data2 << 7) + data1);
            }
        }
    
        void handlePitchWheel(double time, int channel, int bend)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->pitchWheel(time, channel, bend);
            }
        }
        
        void handlePolyAfterTouch(double time, int channel, int data1, int data2)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->keyPress(time, channel, data1, data2);
            }
        }
  
        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF) {
                handleKeyOff(time, channel,  data1, data2);
            } else if (type == MIDI_NOTE_ON) {
                handleKeyOn(time, channel, data1, data2);
            } else if (type == MIDI_CONTROL_CHANGE) {
                handleCtrlChange(time, channel, data1, data2);
            } else if (type == MIDI_PITCH_BEND) {
                handlePitchWheel(time, channel, data1, data2);
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                handlePolyAfterTouch(time, channel, data1, data2);
            }
        }
    
        // SysEx
        void handleSysex(double time, std::vector<unsigned char>& message)
        {
            for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                fMidiInputs[i]->sysEx(time, message);
            }
        }
    
        void handleMessage(double time, int type, std::vector<unsigned char>& message)
        {
            if (type == MIDI_SYSEX_START) {
                handleSysex(time, message);
            }
        }
  
};

#endif // __midi__
/**************************  END  midi.h **************************/

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/**
 * Helper code for MIDI meta and polyphonic 'nvoices' parsing.
 */
struct MidiMeta : public Meta, public std::map<std::string, std::string> {
    
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        return (this->find(key) != this->end()) ? (*this)[key] : def;
    }
    
    static void analyse(dsp* mono_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        mono_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos) ||
                      (json.find("timestamp") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        mono_dsp->metadata(&meta);
        bool found_voices = false;
        // If "options" metadata is used
        std::string options = meta.get("options", "");
        if (options != "") {
            std::map<std::string, std::string> metadata;
            std::string res;
            MetaDataUI::extractMetadata(options, res, metadata);
            if (metadata.find("nvoices") != metadata.end()) {
                nvoices = std::atoi(metadata["nvoices"].c_str());
                found_voices = true;
            }
        }
        // Otherwise test for "nvoices" metadata
        if (!found_voices) {
            std::string numVoices = meta.get("nvoices", "0");
            nvoices = std::atoi(numVoices.c_str());
        }
        nvoices = std::max<int>(0, nvoices);
    #endif
    }
    
    static bool checkPolyphony(dsp* mono_dsp)
    {
        MapUI map_ui;
        mono_dsp->buildUserInterface(&map_ui);
        bool has_freq = false;
        bool has_gate = false;
        bool has_gain = false;
        for (int i = 0; i < map_ui.getParamsCount(); i++) {
            std::string path = map_ui.getParamAddress(i);
            has_freq |= MapUI::endsWith(path, "/freq");
            has_freq |= MapUI::endsWith(path, "/key");
            has_gate |= MapUI::endsWith(path, "/gate");
            has_gain |= MapUI::endsWith(path, "/gain");
            has_gain |= MapUI::endsWith(path, "/vel");
            has_gain |= MapUI::endsWith(path, "/velocity");
        }
        return (has_freq && has_gate && has_gain);
    }
    
};

/**
 * uiMidi : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrlChange, keyOn/keyOff, keyPress, progChange, chanPress, pitchWheel/pitchBend
 * start/stop/clock meta data is handled.
 * MIDI channel is numbered in [1..16] in this layer.
 * Channel 0 means "all channels" when receiving or sending.
 */
class uiMidi {
    
    friend class MidiUI;
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        int fChan;
    
        bool inRange(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT v) { return (min <= v && v <= max); }
    
    public:
        
        uiMidi(midi* midi_out, bool input, int chan = 0):fMidiOut(midi_out), fInputCtrl(input), fChan(chan)
        {}
        virtual ~uiMidi()
        {}

};

/**
 * Base class for MIDI aware UI items.
 */
class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true, int chan = 0)
            :uiMidi(midi_out, input, chan), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

/**
 * Base class for MIDI aware UI items with timestamp support.
 */
class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true, int chan = 0)
            :uiMidi(midi_out, input, chan), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

/**
 * MIDI sync.
 */
class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->startSync(0);
            }
        }
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem {
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stopSync(0);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
};

class uiMidiClock : public uiMidiTimedItem {

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }

};

/**
 * Standard MIDI events.
 */

/**
 * uiMidiProgChange uses the [min...max] range.
 */
class uiMidiProgChange : public uiMidiTimedItem {
    
    public:
    
        FAUSTFLOAT fMin, fMax;
    
        uiMidiProgChange(midi* midi_out, GUI* ui, FAUSTFLOAT* zone,
                         FAUSTFLOAT min, FAUSTFLOAT max,
                         bool input = true, int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), fMin(min), fMax(max)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (inRange(fMin, fMax, v)) {
                if (fChan == 0) {
                    // Send on [0..15] channels on the MIDI layer
                    for (int chan = 0; chan < 16; chan++) {
                        fMidiOut->progChange(chan, v);
                    }
                } else {
                    fMidiOut->progChange(fChan - 1, v);
                }
            }
        }
    
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl && inRange(fMin, fMax, v)) {
                uiItem::modifyZone(v);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl && inRange(fMin, fMax, v)) {
                uiMidiTimedItem::modifyZone(date, v);
            }
        }
        
};

/**
 * uiMidiChanPress.
 */
class uiMidiChanPress : public uiMidiTimedItem, public uiConverter {
    
    public:
    
        uiMidiChanPress(midi* midi_out, GUI* ui,
                        FAUSTFLOAT* zone,
                        FAUSTFLOAT min, FAUSTFLOAT max,
                        bool input = true,
                        MetaDataUI::Scale scale = MetaDataUI::kLin,
                        int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->chanPress(chan, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->chanPress(fChan - 1, fConverter->faust2ui(v));
            }
        }
    
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
        
};

/**
 * uiMidiCtrlChange does scale (kLin/kLog/kExp) mapping.
 */
class uiMidiCtrlChange : public uiMidiTimedItem, public uiConverter {
    
    private:
    
        int fCtrl;
 
    public:

        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui,
                     FAUSTFLOAT* zone,
                     FAUSTFLOAT min, FAUSTFLOAT max,
                     bool input = true,
                     MetaDataUI::Scale scale = MetaDataUI::kLin,
                     int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fCtrl(ctrl)
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->ctrlChange(chan, fCtrl, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->ctrlChange(fChan - 1, fCtrl, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
};

class uiMidiPitchWheel : public uiMidiTimedItem {

    private:
    
        LinearValueConverter2 fConverter;
    
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone,
                         FAUSTFLOAT min, FAUSTFLOAT max,
                         bool input = true, int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan)
        {
            if (min <= 0 && max >= 0) {
                fConverter = LinearValueConverter2(0., 8191., 16383., double(min), 0., double(max));
            } else {
                // Degenerated case...
                fConverter = LinearValueConverter2(0., 8191., 16383., double(min),double(min + (max - min)/FAUSTFLOAT(2)), double(max));
            }
        }
    
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->pitchWheel(chan, fConverter.faust2ui(v));
                }
            } else {
                fMidiOut->pitchWheel(fChan - 1, fConverter.faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void setRange(int val)
        {
            double semi = (val / 128) + ((val % 128) / 100.);
            fConverter.setMappingValues(0., 8191., 16383., -semi, 0., semi);
        }
 
};

/**
 * uiMidiKeyOn does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyOn : public uiMidiTimedItem, public uiConverter {

    private:
        
        int fKeyOn;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui,
                    FAUSTFLOAT* zone,
                    FAUSTFLOAT min, FAUSTFLOAT max,
                    bool input = true,
                    MetaDataUI::Scale scale = MetaDataUI::kLin,
                    int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKeyOn(key)
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKeyOn, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKeyOn, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/**
 * uiMidiKeyOff does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyOff : public uiMidiTimedItem, public uiConverter {

    private:
        
        int fKeyOff;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui,
                     FAUSTFLOAT* zone,
                     FAUSTFLOAT min, FAUSTFLOAT max,
                     bool input = true,
                     MetaDataUI::Scale scale = MetaDataUI::kLin,
                     int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKeyOff(key)
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKeyOff, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKeyOff, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/**
 * uiMidiKeyPress does scale (kLin/kLog/kExp) mapping for velocity.
 */
class uiMidiKeyPress : public uiMidiTimedItem, public uiConverter {

    private:
    
        int fKey;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui,
                       FAUSTFLOAT* zone,
                       FAUSTFLOAT min, FAUSTFLOAT max,
                       bool input = true,
                       MetaDataUI::Scale scale = MetaDataUI::kLin,
                       int chan = 0)
            :uiMidiTimedItem(midi_out, ui, zone, input, chan), uiConverter(scale, 0., 127., min, max), fKey(key)
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (fChan == 0) {
                // Send on [0..15] channels on the MIDI layer
                for (int chan = 0; chan < 16; chan++) {
                    fMidiOut->keyOn(chan, fKey, fConverter->faust2ui(v));
                }
            } else {
                fMidiOut->keyOn(fChan - 1, fKey, fConverter->faust2ui(v));
            }
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter->ui2faust(v)));
            }
        }
    
};

/******************************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI metadata and maps incoming MIDI messages to them.
 * Currently ctrlChange, keyOn/keyOff, keyPress, progChange, chanPress, pitchWheel/pitchBend
 * start/stop/clock meta data are handled.
 *
 * Maps associating MIDI event ID (like each ctrl number) with all MIDI aware UI items
 * are defined and progressively filled when decoding MIDI related metadata.
 * MIDI aware UI items are used in both directions:
 *  - modifying their internal state when receving MIDI input events
 *  - sending their internal state as MIDI output events
 *******************************************************************************************/

class MidiUI : public GUI, public midi, public midi_interface, public MetaDataUI {

    // Add uiItem subclasses objects are deallocated by the inherited GUI class
    typedef std::map <int, std::vector<uiMidiCtrlChange*> > TCtrlChangeTable;
    typedef std::vector<uiMidiProgChange*>                  TProgChangeTable;
    typedef std::vector<uiMidiChanPress*>                   TChanPressTable;
    typedef std::map <int, std::vector<uiMidiKeyOn*> >      TKeyOnTable;
    typedef std::map <int, std::vector<uiMidiKeyOff*> >     TKeyOffTable;
    typedef std::map <int, std::vector<uiMidiKeyPress*> >   TKeyPressTable;
    typedef std::vector<uiMidiPitchWheel*>                  TPitchWheelTable;
    
    protected:
    
        TCtrlChangeTable fCtrlChangeTable;
        TProgChangeTable fProgChangeTable;
        TChanPressTable  fChanPressTable;
        TKeyOnTable      fKeyOnTable;
        TKeyOffTable     fKeyOffTable;
        TKeyOnTable      fKeyTable;
        TKeyPressTable   fKeyPressTable;
        TPitchWheelTable fPitchWheelTable;
        
        std::vector<uiMidiStart*> fStartTable;
        std::vector<uiMidiStop*>  fStopTable;
        std::vector<uiMidiClock*> fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
        bool fTimeStamp;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    unsigned chan;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u %u", &num, &chan) == 2) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u %u", &num, &chan) == 2) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u %u", &num, &chan) == 2) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u %u", &num, &chan) == 2) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u %u", &num, &chan) == 2) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input, getScale(zone), chan));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input, getScale(zone)));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &chan) == 1) {
                            fProgChangeTable.push_back(new uiMidiProgChange(fMidiHandler, this, zone, min, max, input, chan));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pgm") == 0) {
                            fProgChangeTable.push_back(new uiMidiProgChange(fMidiHandler, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &chan) == 1) {
                            fChanPressTable.push_back(new uiMidiChanPress(fMidiHandler, this, zone, min, max, input, getScale(zone), chan));
                        } else if ((fMetaAux[i].second == "chanpress")) {
                            fChanPressTable.push_back(new uiMidiChanPress(fMidiHandler, this, zone, min, max, input, getScale(zone)));
                        } else if ((gsscanf(fMetaAux[i].second.c_str(), "pitchwheel %u", &chan) == 1) || (gsscanf(fMetaAux[i].second.c_str(), "pitchbend %u", &chan) == 1)) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, min, max, input, chan));
                        } else if ((fMetaAux[i].second == "pitchwheel") || (fMetaAux[i].second == "pitchbend")) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, min, max, input));
                        // MIDI sync
                        } else if (fMetaAux[i].second == "start") {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "stop") {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "clock") {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        // Explicit metadata to activate 'timestamp' mode
                        } else if (fMetaAux[i].second == "timestamp") {
                            fTimeStamp = true;
                        }
                    }
                }
            }
            fMetaAux.clear();
        }
    
        template <typename TABLE>
        void updateTable1(TABLE& table, double date, int channel, int val1)
        {
            for (size_t i = 0; i < table.size(); i++) {
                int channel_aux = table[i]->fChan;
                // channel_aux == 0 means "all channels"
                if (channel_aux == 0 || channel == channel_aux - 1) {
                    if (fTimeStamp) {
                        table[i]->modifyZone(date, FAUSTFLOAT(val1));
                    } else {
                        table[i]->modifyZone(FAUSTFLOAT(val1));
                    }
                }
            }
        }
        
        template <typename TABLE>
        void updateTable2(TABLE& table, double date, int channel, int val1, int val2)
        {
            if (table.find(val1) != table.end()) {
                for (size_t i = 0; i < table[val1].size(); i++) {
                    int channel_aux = table[val1][i]->fChan;
                    // channel_aux == 0 means "all channels"
                    if (channel_aux == 0 || channel == channel_aux - 1) {
                        if (fTimeStamp) {
                            table[val1][i]->modifyZone(date, FAUSTFLOAT(val2));
                        } else {
                            table[val1][i]->modifyZone(FAUSTFLOAT(val2));
                        }
                    }
                }
            }
        }
    
    public:
    
        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            // TODO: use shared_ptr based implementation
            fDelete = delete_handler;
            fTimeStamp = false;
        }
 
        virtual ~MidiUI() 
        {
            // Remove from fMidiHandler
            fMidiHandler->removeMidiIn(this);
            // TODO: use shared_ptr based implementation
            if (fDelete) delete fMidiHandler;
        }
    
        bool run() { return fMidiHandler->startMidi(); }
        void stop() { fMidiHandler->stopMidi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            MetaDataUI::declare(zone, key, val);
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API
    
        void key(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOnTable>(fKeyTable, date, channel, note, velocity);
        }
    
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOnTable>(fKeyOnTable, date, channel, note, velocity);
            // If note is in fKeyTable, handle it as a keyOn
            key(date, channel, note, velocity);
            return nullptr;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            updateTable2<TKeyOffTable>(fKeyOffTable, date, channel, note, velocity);
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            key(date, channel, note, 0);
        }
        
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            updateTable2<TCtrlChangeTable>(fCtrlChangeTable, date, channel, ctrl, value);
        }
    
        void rpn(double date, int channel, int ctrl, int value)
        {
            if (ctrl == midi::PITCH_BEND_RANGE) {
                for (size_t i = 0; i < fPitchWheelTable.size(); i++) {
                    // channel_aux == 0 means "all channels"
                    int channel_aux = fPitchWheelTable[i]->fChan;
                    if (channel_aux == 0 || channel == channel_aux - 1) {
                        fPitchWheelTable[i]->setRange(value);
                    }
                }
            }
        }
    
        void progChange(double date, int channel, int pgm)
        {
            updateTable1<TProgChangeTable>(fProgChangeTable, date, channel, pgm);
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            updateTable1<TPitchWheelTable>(fPitchWheelTable, date, channel, wheel);
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            updateTable2<TKeyPressTable>(fKeyPressTable, date, channel, pitch, press);
        }
        
        void chanPress(double date, int channel, int press)
        {
            updateTable1<TChanPressTable>(fChanPressTable, date, channel, press);
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void startSync(double date)
        {
            for (size_t i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stopSync(double date)
        {
            for (size_t i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (size_t i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/**************************  END  MidiUI.h **************************/
/************************** BEGIN mspUI.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 mspUI.h for static Max/MSP externals and faustgen~
 Created by Martin Di Rollo on 18/04/12.
 ********************************************************************/

#ifndef _mspUI_h
#define _mspUI_h

#include <math.h>
#include <assert.h>
#include <string>
#include <map>


#define STR_SIZE    512
#define MULTI_SIZE  256

#ifdef WIN32
#include <stdio.h>
#define snprintf _snprintf
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

using namespace std;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
    
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};

struct Max_Meta3 : Meta
{
    string fName;
    
    bool endWith(const string& str, const string& suffix)
    {
        size_t i = str.rfind(suffix);
        return (i != string::npos) && (i == (str.length() - suffix.length()));
    }
    
    void declare(const char* key, const char* value)
    {
        if ((strcmp("filename", key) == 0)) {
            string val = value;
            if (endWith(value, ".dsp")) {
                fName = "com.grame." + val.substr(0, val.size() - 4) + "~";
            } else {
                fName = "com.grame." + val + "~";
            }
        }
    }
};

class mspUIObject {
    
    protected:
        
        string fLabel;
        FAUSTFLOAT* fZone;
        
        FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}
        
    public:
        
        mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
        virtual ~mspUIObject() {}
        
        virtual void setValue(FAUSTFLOAT f) { *fZone = range(0.0, 1.0, f); }
        virtual FAUSTFLOAT getValue() { return *fZone; }
    
        virtual FAUSTFLOAT getInitValue() { return FAUSTFLOAT(0); }
        virtual FAUSTFLOAT getMinValue() { return FAUSTFLOAT(0); }
        virtual FAUSTFLOAT getMaxValue() { return FAUSTFLOAT(0); }
    
        virtual void toString(char* buffer) {}
        virtual string getName() { return fLabel; }
};

class mspCheckButton : public mspUIObject {
    
    public:
        
        mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
        virtual ~mspCheckButton() {}
        
        void toString(char* buffer)
        {
            snprintf(buffer, STR_SIZE, "CheckButton(float): %s", fLabel.c_str());
        }
};

class mspButton : public mspUIObject {
    
    public:
        
        mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
        virtual ~mspButton() {}
        
        void toString(char* buffer)
        {
            snprintf(buffer, STR_SIZE, "Button(float): %s", fLabel.c_str());
        }
};

class mspSlider : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fInit;
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fStep;
        
    public:
        
        mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        :mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
        virtual ~mspSlider() {}
        
        void toString(char* buffer)
        {
            stringstream str;
            str << "Slider(float): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }
        
        void setValue(FAUSTFLOAT f) { *fZone = range(fMin, fMax, f); }
    
        virtual FAUSTFLOAT getInitValue() { return fInit; }
        virtual FAUSTFLOAT getMinValue() { return fMin; }
        virtual FAUSTFLOAT getMaxValue() { return fMax; }
    
};

class mspBargraph : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fCurrent;
        
    public:
        
        mspBargraph(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        :mspUIObject(label,zone), fMin(min), fMax(max), fCurrent(*zone) {}
        virtual ~mspBargraph() {}
        
        void toString(char* buffer)
        {
            stringstream str;
            str << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }
    
        // special version
        virtual FAUSTFLOAT getValue(bool& new_val)
        {
            if (*fZone != fCurrent) {
                fCurrent = *fZone;
                new_val = true;
            } else {
                new_val = false;
            }
            return fCurrent;
        }
    
        virtual FAUSTFLOAT getMinValue() { return fMin; }
        virtual FAUSTFLOAT getMaxValue() { return fMax; }
    
};

class mspUI : public UI, public PathBuilder
{
    private:
        
        map<string, mspUIObject*> fInputLabelTable;      // Input table using labels
        map<string, mspUIObject*> fInputShortnameTable;  // Input table using shortnames
        map<string, mspUIObject*> fInputPathTable;       // Input table using paths
        map<string, mspUIObject*> fOutputLabelTable;     // Table containing bargraph with labels
        map<string, mspUIObject*> fOutputShortnameTable; // Table containing bargraph with shortnames
        map<string, mspUIObject*> fOutputPathTable;      // Table containing bargraph with paths
        
        map<const char*, const char*> fDeclareTable;
        
        FAUSTFLOAT* fMultiTable[MULTI_SIZE];
        int fMultiIndex;
        int fMultiControl;
        
        string createLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }
    
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fInputLabelTable[string(label)] = obj;
            string path = buildPath(label);
            fInputPathTable[path] = obj;
            fFullPaths.push_back(path);
            fDeclareTable.clear();
        }
    
        void addBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            mspUIObject* obj = new mspBargraph(createLabel(label), zone, min, max);
            fOutputLabelTable[string(label)] = obj;
            string path = buildPath(label);
            fOutputPathTable[path] = obj;
            fFullPaths.push_back(path);
            fDeclareTable.clear();
        }
    
    public:
        
        typedef map<string, mspUIObject*>::iterator iterator;
        
        mspUI()
        {
            for (int i = 0; i < MULTI_SIZE; i++) {
                fMultiTable[i] = 0;
            }
            fMultiIndex = fMultiControl = 0;
        }
    
        virtual ~mspUI()
        {
            clear();
        }
        
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            mspUIObject* obj = new mspButton(createLabel(label), zone);
            fInputLabelTable[string(label)] = obj;
            string path = buildPath(label);
            fInputPathTable[path] = obj;
            fFullPaths.push_back(path);
        }
        
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            mspUIObject* obj = new mspCheckButton(createLabel(label), zone);
            fInputLabelTable[string(label)] = obj;
            string path = buildPath(label);
            fInputPathTable[path] = obj;
            fFullPaths.push_back(path);
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
    
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addBargraph(label, zone, min, max);
        }
    
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addBargraph(label, zone, min, max);
        }
        
        void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        void openTabBox(const char* label) { pushLabel(label); fDeclareTable.clear(); }
        void openHorizontalBox(const char* label) { pushLabel(label); fDeclareTable.clear(); }
        void openVerticalBox(const char* label) { pushLabel(label); fDeclareTable.clear(); }
        void closeBox()
        {
            fDeclareTable.clear();
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' map
                for (const auto& path : fFullPaths) {
                    if (fInputPathTable.count(path)) {
                        fInputShortnameTable[fFull2Short[path]] = fInputPathTable[path];
                    } else if (fOutputPathTable.count(path)) {
                        fOutputShortnameTable[fFull2Short[path]] = fOutputPathTable[path];
                    } else {
                        assert(false);
                    }
                }
             }
        }
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            if (strcmp(key, "multi") == 0) {
                int index = atoi(val);
                if (index >= 0 && index < MULTI_SIZE) {
                    fMultiTable[index] = zone;
                    fMultiControl++;
                } else {
                    post("Invalid multi index = %d", index);
                }
            }
            
            fDeclareTable[key] = val;
        }
        
        void setMultiValues(FAUSTFLOAT* multi, int buffer_size)
        {
            for (int read = 0; read < buffer_size; read++) {
                int write = (fMultiIndex + read) & (MULTI_SIZE - 1);
                if (fMultiTable[write]) {
                    *fMultiTable[write] = multi[read];
                }
            }
            fMultiIndex += buffer_size;
        }
        
        bool isMulti() { return fMultiControl > 0; }
        
        bool isValue(const string& name)
        {
            return (isOutputValue(name) || isInputValue(name));
        }
    
        bool isInputValue(const string& name)
        {
            return fInputLabelTable.count(name) || fInputShortnameTable.count(name) || fInputPathTable.count(name);
        }
    
        bool isOutputValue(const string& name)
        {
            return fOutputLabelTable.count(name) || fOutputShortnameTable.count(name) || fOutputPathTable.count(name);
        }
    
        bool setValue(const string& name, FAUSTFLOAT val)
        {
            if (fInputLabelTable.count(name)) {
                fInputLabelTable[name]->setValue(val);
                return true;
            } else if (fInputShortnameTable.count(name)) {
                fInputShortnameTable[name]->setValue(val);
                return true;
            } else if (fInputPathTable.count(name)) {
                fInputPathTable[name]->setValue(val);
                return true;
            } else {
                return false;
            }
        }
    
        FAUSTFLOAT getOutputValue(const string& name, bool& new_val)
        {
            return static_cast<mspBargraph*>(fOutputPathTable[name])->getValue(new_val);
        }
        
        iterator begin1() { return fInputLabelTable.begin(); }
        iterator end1() { return fInputLabelTable.end(); }
        
        iterator begin2() { return fInputPathTable.begin(); }
        iterator end2() { return fInputPathTable.end(); }
    
        iterator begin3() { return fOutputLabelTable.begin(); }
        iterator end3() { return fOutputLabelTable.end(); }
    
        iterator begin4() { return fOutputPathTable.begin(); }
        iterator end4() { return fOutputPathTable.end(); }
    
        int inputItemsCount() { return fInputLabelTable.size(); }
        int outputItemsCount() { return fOutputLabelTable.size(); }
    
        void clear()
        {
            for (const auto& it : fInputLabelTable) {
                delete it.second;
            }
            fInputLabelTable.clear();
            fInputShortnameTable.clear();
            fInputPathTable.clear();
            
            for (const auto& it : fOutputLabelTable) {
                delete it.second;
            }
            fOutputLabelTable.clear();
            fOutputShortnameTable.clear();
            fOutputPathTable.clear();
        }
        
        void displayControls()
        {
            post("------- Range, shortname and path ----------");
            for (const auto& it : fInputPathTable) {
                char param[STR_SIZE];
                it.second->toString(param);
                post(param);
                string shortname = "Shortname: " + fFull2Short[it.first];
                post(shortname.c_str());
                string path = "Complete path: " + it.first;
                post(path.c_str());
            }
            post("---------------------------------------------");
        }
    
        static bool checkDigit(const string& name)
        {
            for (int i = name.size() - 1; i >= 0; i--) {
                if (isdigit(name[i])) { return true; }
            }
            return false;
        }
        
        static int countDigit(const string& name)
        {
            int count = 0;
            for (int i = name.size() - 1; i >= 0; i--) {
                if (isdigit(name[i])) { count++; }
            }
            return count;
        }

};

//==============
// MIDI handler
//==============

struct max_midi : public midi_handler {
    
    void* m_midi_outlet = NULL;
    
    max_midi(void* midi_outlet = NULL):m_midi_outlet(midi_outlet)
    {}
    
    void sendMessage(std::vector<unsigned char>& message)
    {
        assert(m_midi_outlet);
        for (int i = 0; i < message.size(); i++) {
            outlet_int(m_midi_outlet, message[i]);
        }
    }
    
    // MIDI output API
    MapUI* keyOn(int channel, int pitch, int velocity)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_NOTE_ON + channel);
        message.push_back(pitch);
        message.push_back(velocity);
        sendMessage(message);
        return NULL;
    }
    
    void keyOff(int channel, int pitch, int velocity)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_NOTE_OFF + channel);
        message.push_back(pitch);
        message.push_back(velocity);
        sendMessage(message);
    }
    
    void ctrlChange(int channel, int ctrl, int val)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_CONTROL_CHANGE + channel);
        message.push_back(ctrl);
        message.push_back(val);
        sendMessage(message);
    }
    
    void chanPress(int channel, int press)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_AFTERTOUCH + channel);
        message.push_back(press);
        sendMessage(message);
    }
    
    void progChange(int channel, int pgm)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_PROGRAM_CHANGE + channel);
        message.push_back(pgm);
        sendMessage(message);
    }
    
    void keyPress(int channel, int pitch, int press)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_POLY_AFTERTOUCH + channel);
        message.push_back(pitch);
        message.push_back(press);
        sendMessage(message);
    }
    
    void pitchWheel(int channel, int wheel)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_PITCH_BEND + channel);
        message.push_back(wheel & 0x7F);           // lsb 7bit
        message.push_back((wheel >> 7) & 0x7F);    // msb 7bit
        sendMessage(message);
    }
    
    void ctrlChange14bits(int channel, int ctrl, int value) {}
    
    void startSync(double date)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_START);
        sendMessage(message);
    }
    
    void stopSync(double date)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_STOP);
        sendMessage(message);
    }
    
    void clock(double date)
    {
        std::vector<unsigned char> message;
        message.push_back(MIDI_CLOCK);
        sendMessage(message);
    }
    
    void sysEx(double, std::vector<unsigned char>& message)
    {
        sendMessage(message);
    }
};

#endif
/**************************  END  mspUI.h **************************/
/************************** BEGIN poly-dsp.h *************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*********************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>
#include <assert.h>

/************************** BEGIN proxy-dsp.h ***************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
***************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************** BEGIN JSONUIDecoder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <functional>

/************************** BEGIN CGlue.h *****************************
FAUST Architecture File
Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
---------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

EXCEPTION : As a special exception, you may create a larger work
that contains this FAUST architecture section and distribute
that work under terms of your choice, so long as this FAUST
architecture section is not modified.
*************************************************************************/

#ifndef CGLUE_H
#define CGLUE_H

/************************** BEGIN CInterface.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef CINTERFACE_H
#define CINTERFACE_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
struct Soundfile;

/*******************************************************************************
 * UI, Meta and MemoryManager structures for C code.
 ******************************************************************************/

// -- widget's layouts

typedef void (* openTabBoxFun) (void* ui_interface, const char* label);
typedef void (* openHorizontalBoxFun) (void* ui_interface, const char* label);
typedef void (* openVerticalBoxFun) (void* ui_interface, const char* label);
typedef void (* closeBoxFun) (void* ui_interface);

// -- active widgets

typedef void (* addButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addCheckButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addVerticalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addHorizontalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addNumEntryFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);

// -- passive widgets

typedef void (* addHorizontalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);
typedef void (* addVerticalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);

// -- soundfiles
    
typedef void (* addSoundfileFun) (void* ui_interface, const char* label, const char* url, struct Soundfile** sf_zone);

typedef void (* declareFun) (void* ui_interface, FAUSTFLOAT* zone, const char* key, const char* value);

typedef struct {

    void* uiInterface;

    openTabBoxFun openTabBox;
    openHorizontalBoxFun openHorizontalBox;
    openVerticalBoxFun openVerticalBox;
    closeBoxFun closeBox;
    addButtonFun addButton;
    addCheckButtonFun addCheckButton;
    addVerticalSliderFun addVerticalSlider;
    addHorizontalSliderFun addHorizontalSlider;
    addNumEntryFun addNumEntry;
    addHorizontalBargraphFun addHorizontalBargraph;
    addVerticalBargraphFun addVerticalBargraph;
    addSoundfileFun addSoundfile;
    declareFun declare;

} UIGlue;

typedef void (* metaDeclareFun) (void* ui_interface, const char* key, const char* value);

typedef struct {

    void* metaInterface;
    
    metaDeclareFun declare;

} MetaGlue;

/***************************************
 *  Interface for the DSP object
 ***************************************/

typedef char dsp_imp;
    
typedef dsp_imp* (* newDspFun) ();
typedef void (* destroyDspFun) (dsp_imp* dsp);
typedef int (* getNumInputsFun) (dsp_imp* dsp);
typedef int (* getNumOutputsFun) (dsp_imp* dsp);
typedef void (* buildUserInterfaceFun) (dsp_imp* dsp, UIGlue* ui);
typedef int (* getSampleRateFun) (dsp_imp* dsp);
typedef void (* initFun) (dsp_imp* dsp, int sample_rate);
typedef void (* classInitFun) (int sample_rate);
typedef void (* instanceInitFun) (dsp_imp* dsp, int sample_rate);
typedef void (* instanceConstantsFun) (dsp_imp* dsp, int sample_rate);
typedef void (* instanceResetUserInterfaceFun) (dsp_imp* dsp);
typedef void (* instanceClearFun) (dsp_imp* dsp);
typedef void (* computeFun) (dsp_imp* dsp, int len, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs);
typedef void (* metadataFun) (MetaGlue* meta);
    
/***************************************
 * DSP memory manager functions
 ***************************************/

typedef void* (* allocateFun) (void* manager_interface, size_t size);
typedef void (* destroyFun) (void* manager_interface, void* ptr);

typedef struct {
    
    void* managerInterface;
    
    allocateFun allocate;
    destroyFun destroy;
    
} MemoryManagerGlue;

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CInterface.h **************************/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * UI glue code
 ******************************************************************************/
 
class UIFloat
{

    public:

        UIFloat() {}

        virtual ~UIFloat() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, float* zone) = 0;
        virtual void addCheckButton(const char* label, float* zone) = 0;
        virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
        virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(float* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueFloat(void* cpp_interface)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueFloat(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueFloat(void* cpp_interface, float* zone, const char* key, const char* value)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

class UIDouble
{

    public:

        UIDouble() {}

        virtual ~UIDouble() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, double* zone) = 0;
        virtual void addCheckButton(const char* label, double* zone) = 0;
        virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max) = 0;
        virtual void addVerticalBargraph(const char* label, double* zone, double min, double max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(double* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueDouble(void* cpp_interface)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueDouble(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueDouble(void* cpp_interface, double* zone, const char* key, const char* value)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

static void buildUIGlue(UIGlue* glue, UI* ui_interface, bool is_double)
{
    glue->uiInterface = ui_interface;
    
    if (is_double) {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueDouble);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueDouble);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueDouble);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueDouble);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueDouble);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueDouble);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueDouble);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueDouble);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueDouble);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueDouble);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueDouble);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueDouble);
        glue->declare = reinterpret_cast<declareFun>(declareGlueDouble);
    } else {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueFloat);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueFloat);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueFloat);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueFloat);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueFloat);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueFloat);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueFloat);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueFloat);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueFloat);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueFloat);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueFloat);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueFloat);
        glue->declare = reinterpret_cast<declareFun>(declareGlueFloat);
    }
}
    
// Base class
    
struct UIInterface
{
    virtual ~UIInterface() {}
    
    virtual int sizeOfFAUSTFLOAT() = 0;
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // float version
    
    // -- active widgets
    
    virtual void addButton(const char* label, float* zone) = 0;
    virtual void addCheckButton(const char* label, float* zone) = 0;
    
    virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
    virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    
    // -- metadata declarations
    
    virtual void declare(float* zone, const char* key, const char* val) = 0;
    
    // double version
    
    virtual void addButton(const char* label, double* zone) = 0;
    virtual void addCheckButton(const char* label, double* zone) = 0;
  
    virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
    virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
    
    virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max) = 0;
    virtual void addVerticalBargraph(const char* label, double* zone, double min, double max) = 0;
     
    // -- metadata declarations
    
    virtual void declare(double* zone, const char* key, const char* val) = 0;
    
};
    
struct UITemplate : public UIInterface
{
 
    void* fCPPInterface;

    UITemplate(void* cpp_interface):fCPPInterface(cpp_interface)
    {}
    virtual ~UITemplate() {}
    
    int sizeOfFAUSTFLOAT()
    {
        return reinterpret_cast<UI*>(fCPPInterface)->sizeOfFAUSTFLOAT();
    }
    
    // -- widget's layouts
    
    void openTabBox(const char* label)
    {
        openTabBoxGlueFloat(fCPPInterface, label);
    }
    void openHorizontalBox(const char* label)
    {
        openHorizontalBoxGlueFloat(fCPPInterface, label);
    }
    void openVerticalBox(const char* label)
    {
        openVerticalBoxGlueFloat(fCPPInterface, label);
    }
    void closeBox()
    {
        closeBoxGlueFloat(fCPPInterface);
    }
    
    // float version
    
    // -- active widgets
    
    void addButton(const char* label, float* zone)
    {
        addButtonGlueFloat(fCPPInterface, label, zone);
    }
    void addCheckButton(const char* label, float* zone)
    {
        addCheckButtonGlueFloat(fCPPInterface, label, zone);
    }
    
    void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        addVerticalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        addHorizontalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addNumEntry(const char* label, float* zone, float init, float min, float max, float step)
    {
        addNumEntryGlueFloat(fCPPInterface, label, zone, init, min, max, step);
    }
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, float* zone, float min, float max)
    {
        addHorizontalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
    }
    
    void addVerticalBargraph(const char* label, float* zone, float min, float max)
    {
        addVerticalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
    }

    // -- metadata declarations
    
    void declare(float* zone, const char* key, const char* val)
    {
        declareGlueFloat(fCPPInterface, zone, key, val);
    }
    
    // double version
    
    void addButton(const char* label, double* zone)
    {
        addButtonGlueDouble(fCPPInterface, label, zone);
    }
    void addCheckButton(const char* label, double* zone)
    {
        addCheckButtonGlueDouble(fCPPInterface, label, zone);
    }
    
    void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        addVerticalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        addHorizontalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }
    
    void addNumEntry(const char* label, double* zone, double init, double min, double max, double step)
    {
        addNumEntryGlueDouble(fCPPInterface, label, zone, init, min, max, step);
    }

    // -- soundfiles
    
    void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
    {
        addSoundfileGlueFloat(fCPPInterface, label, url, sf_zone);
    }

    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, double* zone, double min, double max)
    {
        addHorizontalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
    }
    
    void addVerticalBargraph(const char* label, double* zone, double min, double max)
    {
        addVerticalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
    }

    // -- metadata declarations
    
    void declare(double* zone, const char* key, const char* val)
    {
        declareGlueDouble(fCPPInterface, zone, key, val);
    }

};
    
struct UIGlueTemplate : public UIInterface
{
    
    UIGlue* fGlue;
    
    UIGlueTemplate(UIGlue* glue):fGlue(glue)
    {}
    virtual ~UIGlueTemplate() {}
    
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
    
    // -- widget's layouts
    
    void openTabBox(const char* label)
    {
        fGlue->openTabBox(fGlue->uiInterface, label);
    }
    void openHorizontalBox(const char* label)
    {
        fGlue->openHorizontalBox(fGlue->uiInterface, label);
    }
    void openVerticalBox(const char* label)
    {
        fGlue->openVerticalBox(fGlue->uiInterface, label);
    }
    void closeBox()
    {
        fGlue->closeBox(fGlue->uiInterface);
    }

    // float version
    
    // -- active widgets
    
    void addButton(const char* label, float* zone)
    {
        fGlue->addButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    void addCheckButton(const char* label, float* zone)
    {
        fGlue->addCheckButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    
    void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addVerticalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addHorizontalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addNumEntry(const char* label, float* zone, float init, float min, float max, float step)
    {
        fGlue->addNumEntry(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, float* zone, float min, float max)
    {
        fGlue->addHorizontalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    void addVerticalBargraph(const char* label, float* zone, float min, float max)
    {
        fGlue->addVerticalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    
    // -- metadata declarations
    
    void declare(float* zone, const char* key, const char* val)
    {
        fGlue->declare(fGlue->uiInterface, reinterpret_cast<FAUSTFLOAT*>(zone), key, val);
    }
    
    // double version
    
    void addButton(const char* label, double* zone)
    {
        fGlue->addButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    void addCheckButton(const char* label, double* zone)
    {
        fGlue->addCheckButton(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone));
    }
    
    void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addVerticalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addHorizontalSlider(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    void addNumEntry(const char* label, double* zone, double init, double min, double max, double step)
    {
        fGlue->addNumEntry(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), init, min, max, step);
    }
    // -- soundfiles
    
    void addSoundfile(const char* label, const char* url, Soundfile** sf_zone) {}
    
    // -- passive widgets
    
    void addHorizontalBargraph(const char* label, double* zone, double min, double max)
    {
        fGlue->addHorizontalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    void addVerticalBargraph(const char* label, double* zone, double min, double max)
    {
        fGlue->addVerticalBargraph(fGlue->uiInterface, label, reinterpret_cast<FAUSTFLOAT*>(zone), min, max);
    }
    
    // -- metadata declarations
    
    void declare(double* zone, const char* key, const char* val)
    {
        fGlue->declare(fGlue->uiInterface, reinterpret_cast<FAUSTFLOAT*>(zone), key, val);
    }
    
};

/*******************************************************************************
 * Meta glue code
 ******************************************************************************/

static void declareMetaGlue(void* cpp_interface, const char* key, const char* value)
{
    Meta* meta_interface = static_cast<Meta*>(cpp_interface);
    meta_interface->declare(key, value);
}

static void buildMetaGlue(MetaGlue* glue, Meta* meta)
{
    glue->metaInterface = meta;
    glue->declare = declareMetaGlue;
}
    
/*******************************************************************************
 * Memory manager glue code
 ******************************************************************************/

static void* allocateMemoryManagerGlue(void* cpp_interface, size_t size)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    return manager_interface->allocate(size);
}
    
static void destroyMemoryManagerGlue(void* cpp_interface, void* ptr)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    manager_interface->destroy(ptr);
}

static void buildManagerGlue(MemoryManagerGlue* glue, dsp_memory_manager* manager)
{
    glue->managerInterface = manager;
    glue->allocate = allocateMemoryManagerGlue;
    glue->destroy = destroyMemoryManagerGlue;
}

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CGlue.h **************************/

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

//------------------------------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface' and 'metadata' methods
//------------------------------------------------------------------------------------------

#define REAL_UI(ui_interface) reinterpret_cast<UIReal<REAL>*>(ui_interface)
#define REAL_ADR(index)      reinterpret_cast<REAL*>(&memory_block[index])
#define REAL_EXT_ADR(index)  reinterpret_cast<FAUSTFLOAT*>(&memory_block[index])
#define SOUNDFILE_ADR(index) reinterpret_cast<Soundfile**>(&memory_block[index])

typedef std::function<void(FAUSTFLOAT)> ReflectFunction;
typedef std::function<FAUSTFLOAT()> ModifyFunction;

struct FAUST_API ExtZoneParam {

    virtual void reflectZone() = 0;
    virtual void modifyZone() = 0;
    
    virtual void setReflectZoneFun(ReflectFunction reflect) = 0;
    virtual void setModifyZoneFun(ModifyFunction modify) = 0;
    
    virtual ~ExtZoneParam()
    {}
    
};

// Templated decoder

struct FAUST_API JSONUIDecoderBase
{
    virtual ~JSONUIDecoderBase()
    {}
    
    virtual void metadata(Meta* m) = 0;
    virtual void metadata(MetaGlue* glue) = 0;
    virtual int getDSPSize() = 0;
    virtual std::string getName() = 0;
    virtual std::string getLibVersion() = 0;
    virtual std::string getCompileOptions() = 0;
    virtual std::vector<std::string> getLibraryList() = 0;
    virtual std::vector<std::string> getIncludePathnames() = 0;
    virtual int getNumInputs() = 0;
    virtual int getNumOutputs() = 0;
    virtual int getSampleRate(char* memory_block) = 0;
    virtual void setReflectZoneFun(int index, ReflectFunction fun) = 0;
    virtual void setModifyZoneFun(int index, ModifyFunction fun) = 0;
    virtual void setupDSPProxy(UI* ui_interface, char* memory_block) = 0;
    virtual bool hasDSPProxy() = 0;
    virtual std::vector<ExtZoneParam*>& getInputControls() = 0;
    virtual std::vector<ExtZoneParam*>& getOutputControls() = 0;
    virtual void resetUserInterface() = 0;
    virtual void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr) = 0;
    virtual void buildUserInterface(UI* ui_interface) = 0;
    virtual void buildUserInterface(UI* ui_interface, char* memory_block) = 0;
    virtual void buildUserInterface(UIGlue* ui_interface, char* memory_block) = 0;
    virtual bool hasCompileOption(const std::string& option) = 0;
};

template <typename REAL>
struct FAUST_API JSONUIDecoderReal : public JSONUIDecoderBase {
    
    struct ZoneParam : public ExtZoneParam {
        
        FAUSTFLOAT fZone;
        ReflectFunction fReflect;
        ModifyFunction fModify;
        
    #if defined(TARGET_OS_IPHONE) || defined(WIN32)
        ZoneParam(ReflectFunction reflect = nullptr, ModifyFunction modify = nullptr)
        :fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { if (fReflect) fReflect(fZone); }
        void modifyZone() { if (fModify) fZone = fModify(); }
    #else
        ZoneParam(ReflectFunction reflect = [](FAUSTFLOAT value) {}, ModifyFunction modify = []() { return FAUSTFLOAT(-1); })
        :fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { fReflect(fZone); }
        void modifyZone() { fZone = fModify(); }
    #endif
        
        void setReflectZoneFun(ReflectFunction reflect) { fReflect = reflect; }
        void setModifyZoneFun(ModifyFunction modify) { fModify = modify; }
        
    };
    
    typedef std::vector<ExtZoneParam*> controlMap;
  
    std::string fName;
    std::string fFileName;
    std::string fJSON;
    std::string fVersion;
    std::string fCompileOptions;
    
    std::map<std::string, std::string> fMetadata;
    std::vector<itemInfo> fUiItems;
    
    std::vector<std::string> fLibraryList;
    std::vector<std::string> fIncludePathnames;
    
    int fNumInputs, fNumOutputs, fSRIndex;
    int fDSPSize;
    bool fDSPProxy;
    
    controlMap fPathInputTable;     // [path, ZoneParam]
    controlMap fPathOutputTable;    // [path, ZoneParam]
    
    bool startWith(const std::string& str, const std::string& prefix)
    {
        return (str.substr(0, prefix.size()) == prefix);
    }

    bool isInput(const std::string& type)
    {
        return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox");
    }
    bool isOutput(const std::string& type) { return (type == "hbargraph" || type == "vbargraph"); }
    bool isSoundfile(const std::string& type) { return (type == "soundfile"); }
    
    std::string getString(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? map[key].first : "";
    }
    
    int getInt(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? int(map[key].second) : -1;
    }
    
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        fPathInputTable[index]->setReflectZoneFun(fun);
    }
    
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        fPathOutputTable[index]->setModifyZoneFun(fun);
    }

    JSONUIDecoderReal(const std::string& json)
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        std::map<std::string, std::pair<std::string, double> > meta_data1;
        std::map<std::string, std::vector<std::string> > meta_data2;
        parseJson(p, meta_data1, fMetadata, meta_data2, fUiItems);
        
        // meta_data1 contains <name : val>, <inputs : val>, <ouputs : val> pairs etc...
        fName = getString(meta_data1, "name");
        fFileName = getString(meta_data1, "filename");
        fVersion = getString(meta_data1, "version");
        fCompileOptions = getString(meta_data1, "compile_options");
        
        if (meta_data2.find("library_list") != meta_data2.end()) {
            fLibraryList = meta_data2["library_list"];
        } else {
            // 'library_list' is coded as successive 'library_pathN' metadata
            for (const auto& it : fMetadata) {
                if (startWith(it.first, "library_path")) {
                    fLibraryList.push_back(it.second);
                }
            }
        }
        if (meta_data2.find("include_pathnames") != meta_data2.end()) {
            fIncludePathnames = meta_data2["include_pathnames"];
        }
        
        fDSPSize = getInt(meta_data1, "size");
        fNumInputs = getInt(meta_data1, "inputs");
        fNumOutputs = getInt(meta_data1, "outputs");
        fSRIndex = getInt(meta_data1, "sr_index");
        fDSPProxy = false;
        
        // Prepare the fPathTable and init zone
        for (const auto& it : fUiItems) {
            std::string type = it.type;
            // Meta data declaration for input items
            if (isInput(type)) {
                ZoneParam* param = new ZoneParam();
                fPathInputTable.push_back(param);
                param->fZone = it.init;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                ZoneParam* param = new ZoneParam();
                fPathOutputTable.push_back(param);
                param->fZone = REAL(0);
            }
        }
    }
    
    virtual ~JSONUIDecoderReal()
    {
        for (const auto& it : fPathInputTable) {
            delete it;
        }
        for (const auto& it : fPathOutputTable) {
            delete it;
        }
    }
    
    void metadata(Meta* m)
    {
        for (const auto& it : fMetadata) {
            m->declare(it.first.c_str(), it.second.c_str());
        }
    }
    
    void metadata(MetaGlue* m)
    {
        for (const auto& it : fMetadata) {
            m->declare(m->metaInterface, it.first.c_str(), it.second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        int item = 0;
        for (const auto& it : fUiItems) {
            if (isInput(it.type)) {
                static_cast<ZoneParam*>(fPathInputTable[item++])->fZone = it.init;
            }
        }
    }
    
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        for (const auto& it : fUiItems) {
            int index = it.index;
            if (isInput(it.type)) {
                *REAL_ADR(index) = it.init;
            } else if (isSoundfile(it.type)) {
                if (*SOUNDFILE_ADR(index) == nullptr) {
                    *SOUNDFILE_ADR(index) = defaultsound;
                }
            }
        }
    }
    
    int getSampleRate(char* memory_block)
    {
        return *reinterpret_cast<int*>(&memory_block[fSRIndex]);
    }
    
    void setupDSPProxy(UI* ui_interface, char* memory_block)
    {
        if (!fDSPProxy) {
            fDSPProxy = true;
            int countIn = 0;
            int countOut = 0;
            for (const auto& it : fUiItems) {
                std::string type = it.type;
                int index = it.index;
                if (isInput(type)) {
                    fPathInputTable[countIn++]->setReflectZoneFun([=](FAUSTFLOAT value) { *REAL_ADR(index) = REAL(value); });
                } else if (isOutput(type)) {
                    fPathOutputTable[countOut++]->setModifyZoneFun([=]() { return FAUSTFLOAT(*REAL_ADR(index)); });
                }
            }
        }
        
        // Setup soundfile in any case
        for (const auto& it : fUiItems) {
            if (isSoundfile(it.type)) {
                ui_interface->addSoundfile(it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(it.index));
            }
        }
    }
    
    bool hasDSPProxy() { return fDSPProxy; }
  
    void buildUserInterface(UI* ui_interface)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        int countIn = 0;
        int countOut = 0;
        int countSound = 0;
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(&static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(&static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui_interface->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") {
                ui_interface->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                ui_interface->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                ui_interface->addVerticalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "hslider") {
                ui_interface->addHorizontalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "checkbox") {
                ui_interface->addCheckButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "soundfile") {
                // Nothing
            } else if (type == "hbargraph") {
                ui_interface->addHorizontalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "vbargraph") {
                ui_interface->addVerticalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "nentry") {
                ui_interface->addNumEntry(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "button") {
                ui_interface->addButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "close") {
                ui_interface->closeBox();
            }
            
            if (isInput(type)) {
                countIn++;
            } else if (isOutput(type)) {
                countOut++;
            } else if (isSoundfile(type)) {
                countSound++;
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            int index = it.index;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                REAL_UI(ui_interface)->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") {
                REAL_UI(ui_interface)->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                REAL_UI(ui_interface)->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                REAL_UI(ui_interface)->addVerticalSlider(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "hslider") {
                REAL_UI(ui_interface)->addHorizontalSlider(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "checkbox") {
                REAL_UI(ui_interface)->addCheckButton(it.label.c_str(), REAL_ADR(index));
            } else if (type == "soundfile") {
                REAL_UI(ui_interface)->addSoundfile(it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(index));
            } else if (type == "hbargraph") {
                REAL_UI(ui_interface)->addHorizontalBargraph(it.label.c_str(), REAL_ADR(index), min, max);
            } else if (type == "vbargraph") {
                REAL_UI(ui_interface)->addVerticalBargraph(it.label.c_str(), REAL_ADR(index), min, max);
            } else if (type == "nentry") {
                REAL_UI(ui_interface)->addNumEntry(it.label.c_str(), REAL_ADR(index), init, min, max, step);
            } else if (type == "button") {
                REAL_UI(ui_interface)->addButton(it.label.c_str(), REAL_ADR(index));
            } else if (type == "close") {
                REAL_UI(ui_interface)->closeBox();
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        if (tmp_local != NULL) {
            tmp_local = strdup(tmp_local);
        }
        setlocale(LC_ALL, "C");
        
        for (const auto& it : fUiItems) {
            
            std::string type = it.type;
            int index = it.index;
            REAL init = REAL(it.init);
            REAL min = REAL(it.fmin);
            REAL max = REAL(it.fmax);
            REAL step = REAL(it.step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, REAL_EXT_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, REAL_EXT_ADR(index), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    ui_interface->declare(ui_interface->uiInterface, 0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui_interface->openHorizontalBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "vgroup") {
                ui_interface->openVerticalBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "tgroup") {
                ui_interface->openTabBox(ui_interface->uiInterface, it.label.c_str());
            } else if (type == "vslider") {
                ui_interface->addVerticalSlider(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "hslider") {
                ui_interface->addHorizontalSlider(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "checkbox") {
                ui_interface->addCheckButton(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index));
            } else if (type == "soundfile") {
                ui_interface->addSoundfile(ui_interface->uiInterface, it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(index));
            } else if (type == "hbargraph") {
                ui_interface->addHorizontalBargraph(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), min, max);
            } else if (type == "vbargraph") {
                ui_interface->addVerticalBargraph(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), min, max);
            } else if (type == "nentry") {
                ui_interface->addNumEntry(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index), init, min, max, step);
            } else if (type == "button") {
                ui_interface->addButton(ui_interface->uiInterface, it.label.c_str(), REAL_EXT_ADR(index));
            } else if (type == "close") {
                ui_interface->closeBox(ui_interface->uiInterface);
            }
        }
        
        if (tmp_local != NULL) {
            setlocale(LC_ALL, tmp_local);
            free(tmp_local);
        }
    }
    
    bool hasCompileOption(const std::string& option)
    {
        std::istringstream iss(fCompileOptions);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            if (token == option) return true;
        }
        return false;
    }
    
    int getDSPSize() { return fDSPSize; }
    std::string getName() { return fName; }
    std::string getLibVersion() { return fVersion; }
    std::string getCompileOptions() { return fCompileOptions; }
    std::vector<std::string> getLibraryList() { return fLibraryList; }
    std::vector<std::string> getIncludePathnames() { return fIncludePathnames; }
    int getNumInputs() { return fNumInputs; }
    int getNumOutputs() { return fNumOutputs; }
    
    std::vector<ExtZoneParam*>& getInputControls()
    {
        return fPathInputTable;
    }
    std::vector<ExtZoneParam*>& getOutputControls()
    {
        return fPathOutputTable;
    }
    
};

// FAUSTFLOAT templated decoder

struct FAUST_API JSONUIDecoder : public JSONUIDecoderReal<FAUSTFLOAT>
{
    JSONUIDecoder(const std::string& json):JSONUIDecoderReal<FAUSTFLOAT>(json)
    {}
};

// Generic factory

static JSONUIDecoderBase* createJSONUIDecoder(const std::string& json)
{
    JSONUIDecoder decoder(json);
    if (decoder.hasCompileOption("-double")) {
        return new JSONUIDecoderReal<double>(json);
    } else {
        return new JSONUIDecoderReal<float>(json);
    }
}

#endif
/**************************  END  JSONUIDecoder.h **************************/

/**
 * Proxy dsp definition created from the DSP JSON description.
 * This class allows a 'proxy' dsp to control a real dsp
 * possibly running somewhere else.
 */
class proxy_dsp : public dsp {

    protected:
    
        JSONUIDecoder* fDecoder;
        int fSampleRate;
    
        void init(const std::string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSampleRate = -1;
        }
        
    public:
    
        proxy_dsp():fDecoder(nullptr), fSampleRate(-1)
        {}
    
        proxy_dsp(const std::string& json)
        {
            init(json);
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSampleRate = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
    
        virtual int getNumInputs() { return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int sample_rate)
        {
            instanceInit(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            instanceConstants(sample_rate);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int sample_rate) { fSampleRate = sample_rate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSampleRate; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif
/************************** END proxy-dsp.h **************************/

/************************** BEGIN JSONControl.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 *************************************************************************/

#ifndef __JSON_CONTROL__
#define __JSON_CONTROL__

#include <string>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API JSONControl {
    
    virtual std::string getJSON() { return ""; }

    virtual void setParamValue(const std::string& path, FAUSTFLOAT value) {}

    virtual FAUSTFLOAT getParamValue(const std::string& path) { return 0; }
    
    virtual ~JSONControl()
    {}
    
};

#endif
/**************************  END  JSONControl.h **************************/

#define kActiveVoice    0
#define kFreeVoice     -1
#define kReleaseVoice  -2
#define kLegatoVoice   -3
#define kNoVoice       -4

#define VOICE_STOP_LEVEL  0.0005    // -70 db
#define MIX_BUFFER_SIZE   4096

/**
 * Allows to control zones in a grouped manner.
 */
class GroupUI : public GUI, public PathBuilder {

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!MapUI::endsWith(label, "/gate")
                && !MapUI::endsWith(label, "/freq")
                && !MapUI::endsWith(label, "/key")
                && !MapUI::endsWith(label, "/gain")
                && !MapUI::endsWith(label, "/vel")
                && !MapUI::endsWith(label, "/velocity")) {

                // Groups all controllers except 'freq/key', 'gate', and 'gain/vel|velocity'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            popLabel();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */
struct dsp_voice : public MapUI, public decorator_dsp {
    
    typedef std::function<double(int)> TransformFunction;
  
    static double midiToFreq(double note)
    {
        return 440.0 * std::pow(2.0, (note-69.0)/12.0);
    }
    
    int fCurNote;                       // Playing note pitch
    int fNextNote;                      // In kLegatoVoice state, next note to play
    int fNextVel;                       // In kLegatoVoice state, next velocity to play
    int fDate;                          // KeyOn date
    int fRelease;                       // Current number of samples used in release mode to detect end of note
    FAUSTFLOAT fLevel;                  // Last audio block level
    double fReleaseLengthSec;           // Maximum release length in seconds (estimated time to silence after note release)
    std::vector<std::string> fGatePath; // Paths of 'gate' control
    std::vector<std::string> fGainPath; // Paths of 'gain/vel|velocity' control
    std::vector<std::string> fFreqPath; // Paths of 'freq/key' control
    TransformFunction        fKeyFun;   // MIDI key to freq conversion function
    TransformFunction        fVelFun;   // MIDI velocity to gain conversion function
    
    FAUSTFLOAT** fInputsSlice;
    FAUSTFLOAT** fOutputsSlice;
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        // Default versions
        fVelFun = [](int velocity) { return double(velocity)/127.0; };
        fKeyFun = [](int pitch) { return midiToFreq(pitch); };
        dsp->buildUserInterface(this);
        fCurNote = kFreeVoice;
        fNextNote = fNextVel = -1;
        fLevel = FAUSTFLOAT(0);
        fDate = fRelease = 0;
        fReleaseLengthSec = 0.5;  // A half second is a reasonable default maximum release length.
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }
    virtual ~dsp_voice()
    {}
    
    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        FAUSTFLOAT** inputsSlice = static_cast<FAUSTFLOAT**>(alloca(sizeof(FAUSTFLOAT*) * getNumInputs()));
        for (int chan = 0; chan < getNumInputs(); chan++) {
            inputsSlice[chan] = &(inputs[chan][offset]);
        }
        FAUSTFLOAT** outputsSlice = static_cast<FAUSTFLOAT**>(alloca(sizeof(FAUSTFLOAT*) * getNumOutputs()));
        for (int chan = 0; chan < getNumOutputs(); chan++) {
            outputsSlice[chan] = &(outputs[chan][offset]);
        }
        compute(slice, inputsSlice, outputsSlice);
    }
    
    void computeLegato(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        int slice = count/2;
        
        // Reset envelops
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        // Compute current voice on half buffer
        computeSlice(0, slice, inputs, outputs);
         
        // Start next keyOn
        keyOn(fNextNote, fNextVel);
        
        // Compute on second half buffer
        computeSlice(slice, slice, inputs, outputs);
    }

    void extractPaths(std::vector<std::string>& gate, std::vector<std::string>& freq, std::vector<std::string>& gain)
    {
        // Keep gain/vel|velocity, freq/key and gate labels
        for (const auto& it : getFullpathMap()) {
            std::string path = it.first;
            if (endsWith(path, "/gate")) {
                gate.push_back(path);
            } else if (endsWith(path, "/freq")) {
                fKeyFun = [](int pitch) { return midiToFreq(pitch); };
                freq.push_back(path);
            } else if (endsWith(path, "/key")) {
                fKeyFun = [](int pitch) { return pitch; };
                freq.push_back(path);
            } else if (endsWith(path, "/gain")) {
                fVelFun = [](int velocity) { return double(velocity)/127.0; };
                gain.push_back(path);
            } else if (endsWith(path, "/vel") || endsWith(path, "/velocity")) {
                fVelFun = [](int velocity) { return double(velocity); };
                gain.push_back(path);
            }
        }
    }
    
    void reset()
    {
        init(getSampleRate());
    }
 
    void instanceClear()
    {
        decorator_dsp::instanceClear();
        fCurNote = kFreeVoice;
        fNextNote = fNextVel = -1;
        fLevel = FAUSTFLOAT(0);
        fDate = fRelease = 0;
    }
    
    // Keep 'pitch' and 'velocity' to fadeOut the current voice and start next one in the next buffer
    void keyOn(int pitch, int velocity, bool legato = false)
    {
        if (legato) {
            fNextNote = pitch;
            fNextVel = velocity;
        } else {
            keyOn(pitch, fVelFun(velocity));
        }
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, double velocity)
    {
        for (size_t i = 0; i < fFreqPath.size(); i++) {
            setParamValue(fFreqPath[i], fKeyFun(pitch));
        }
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(1));
        }
        for (size_t i = 0; i < fGainPath.size(); i++) {
            setParamValue(fGainPath[i], velocity);
        }
        
        fCurNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        if (hard) {
            // Immediately stop voice
            fCurNote = kFreeVoice;
        } else {
            // Release voice
            fRelease = fReleaseLengthSec * fDSP->getSampleRate();
            fCurNote = kReleaseVoice;
        }
    }
 
    // Change the voice release
    void setReleaseLength(double sec)
    {
        fReleaseLengthSec = sec;
    }

};

/**
 * A group of voices.
 */
struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }
    
    void instanceResetUserInterface()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->instanceResetUserInterface();
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl || dynamic_cast<SoundUIInterface*>(ui_interface)) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), long(i+1));
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for MIDI controllable polyphonic DSP.
 */
#ifdef EMCC
#endif

class dsp_poly : public decorator_dsp, public midi, public JSONControl {

    protected:
    
    #ifdef EMCC
        MapUI fMapUI;
        std::string fJSON;
        midi_handler fMidiHandler;
        MidiUI fMIDIUI;
    #endif
    
    public:
    
    #ifdef EMCC
        dsp_poly(dsp* dsp):decorator_dsp(dsp), fMIDIUI(&fMidiHandler)
        {
            JSONUI jsonui(getNumInputs(), getNumOutputs());
            buildUserInterface(&jsonui);
            fJSON = jsonui.JSON(true);
            buildUserInterface(&fMapUI);
            buildUserInterface(&fMIDIUI);
        }
    #else
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {}
    #endif
    
        virtual ~dsp_poly() {}
    
        // Reimplemented for EMCC
    #ifdef EMCC
        virtual int getNumInputs() { return decorator_dsp::getNumInputs(); }
        virtual int getNumOutputs() { return decorator_dsp::getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { decorator_dsp::buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return decorator_dsp::getSampleRate(); }
        virtual void init(int sample_rate) { decorator_dsp::init(sample_rate); }
        virtual void instanceInit(int sample_rate) { decorator_dsp::instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { decorator_dsp::instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { decorator_dsp::instanceResetUserInterface(); }
        virtual void instanceClear() { decorator_dsp::instanceClear(); }
        virtual dsp_poly* clone() { return new dsp_poly(fDSP->clone()); }
        virtual void metadata(Meta* m) { decorator_dsp::metadata(m); }
    
        // Additional API
        std::string getJSON()
        {
            return fJSON;
        }
    
        virtual void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            fMapUI.setParamValue(path, value);
            GUI::updateAllGuis();
        }
        
        virtual FAUSTFLOAT getParamValue(const std::string& path) { return fMapUI.getParamValue(path); }

        virtual void computeJS(int count, uintptr_t inputs, uintptr_t outputs)
        {
            decorator_dsp::compute(count, reinterpret_cast<FAUSTFLOAT**>(inputs),reinterpret_cast<FAUSTFLOAT**>(outputs));
        }
    #endif
    
        virtual MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return midi::keyOn(channel, pitch, velocity);
        }
        virtual void keyOff(int channel, int pitch, int velocity)
        {
            midi::keyOff(channel, pitch, velocity);
        }
        virtual void keyPress(int channel, int pitch, int press)
        {
            midi::keyPress(channel, pitch, press);
        }
        virtual void chanPress(int channel, int press)
        {
            midi::chanPress(channel, press);
        }
        virtual void ctrlChange(int channel, int ctrl, int value)
        {
            midi::ctrlChange(channel, ctrl, value);
        }
        virtual void ctrlChange14bits(int channel, int ctrl, int value)
        {
            midi::ctrlChange14bits(channel, ctrl, value);
        }
        virtual void pitchWheel(int channel, int wheel)
        {
        #ifdef EMCC
            fMIDIUI.pitchWheel(0., channel, wheel);
            GUI::updateAllGuis();
        #else
            midi::pitchWheel(channel, wheel);
        #endif
        }
        virtual void progChange(int channel, int pgm)
        {
            midi::progChange(channel, pgm);
        }
    
        // Change the voice release
        virtual void setReleaseLength(double seconds)
        {}
    
};

/**
 * Polyphonic DSP: groups a set of DSP to be played together or triggered by MIDI.
 *
 * All voices are preallocated by cloning the single DSP voice given at creation time.
 * Dynamic voice allocation is done in 'getFreeVoice'
 */
class scaleIt_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        FAUSTFLOAT** fOutBuffer;
        midi_interface* fMidiHandler; // The midi_interface the DSP is connected to
        int fDate;
    
        void fadeOut(int count, FAUSTFLOAT** outBuffer)
        {
            // FadeOut on half buffer
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                double factor = 1., step = 1./double(count);
                for (int frame = 0; frame < count; frame++) {
                    outBuffer[chan][frame] *= factor;
                    factor -= step;
                }
            }
        }
    
        FAUSTFLOAT mixCheckVoice(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                FAUSTFLOAT* mixChannel = mixBuffer[chan];
                FAUSTFLOAT* outChannel = outBuffer[chan];
                for (int frame = 0; frame < count; frame++) {
                    level = std::max<FAUSTFLOAT>(level, (FAUSTFLOAT)fabs(mixChannel[frame]));
                    outChannel[frame] += mixChannel[frame];
                }
            }
            return level;
        }
    
        void mixVoice(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                FAUSTFLOAT* mixChannel = mixBuffer[chan];
                FAUSTFLOAT* outChannel = outBuffer[chan];
                for (int frame = 0; frame < count; frame++) {
                    outChannel[frame] += mixChannel[frame];
                }
            }
        }
    
        void copy(int count, FAUSTFLOAT** mixBuffer, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                memcpy(outBuffer[chan], mixBuffer[chan], count * sizeof(FAUSTFLOAT));
            }
        }

        void clear(int count, FAUSTFLOAT** outBuffer)
        {
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                memset(outBuffer[chan], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
            
            return voice_playing;
        }
    
        int allocVoice(int voice, int type)
        {
            fVoiceTable[voice]->fDate++;
            fVoiceTable[voice]->fCurNote = type;
            return voice;
        }
    
        // Always returns a voice
        int getFreeVoice()
        {
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == kFreeVoice) {
                    return allocVoice(i, kActiveVoice);
                }
            }

            // Otherwise steal one
            int voice_release = kNoVoice;
            int voice_playing = kNoVoice;
            int oldest_date_release = INT_MAX;
            int oldest_date_playing = INT_MAX;

            // Scan all voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fCurNote == kReleaseVoice) {
                    // Keeps oldest release voice
                    if (fVoiceTable[i]->fDate < oldest_date_release) {
                        oldest_date_release = fVoiceTable[i]->fDate;
                        voice_release = int(i);
                    }
                } else {
                    // Otherwise keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
        
            // Then decide which one to steal
            if (oldest_date_release != INT_MAX) {
                fprintf(stderr, "Steal release voice : voice_date = %d cur_date = %d voice = %d \n",
                        fVoiceTable[voice_release]->fDate,
                        fDate,
                        voice_release);
                return allocVoice(voice_release, kLegatoVoice);
            } else if (oldest_date_playing != INT_MAX) {
                fprintf(stderr, "Steal playing voice : voice_date = %d cur_date = %d voice = %d \n",
                        fVoiceTable[voice_playing]->fDate,
                        fDate,
                        voice_release);
                return allocVoice(voice_playing, kLegatoVoice);
            } else {
                assert(false);
                return kNoVoice;
            }
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<scaleIt_poly*>(arg)->allNotesOff(true);
            }
        }

        bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                fprintf(stderr, "DSP is not polyphonic...\n");
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: scaleIt_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices, should be at least 1
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        scaleIt_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp) // dsp parameter is deallocated by ~dsp_poly
        {
            fDate = 0;
            fMidiHandler = nullptr;

            // Create voices
            assert(nvoices > 0);
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            fOutBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                fMixBuffer[chan] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
                fOutBuffer[chan] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~scaleIt_poly()
        {
            // Remove from fMidiHandler
            if (fMidiHandler) fMidiHandler->removeMidiIn(this);
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                delete[] fMixBuffer[chan];
                delete[] fOutBuffer[chan];
            }
            delete[] fMixBuffer;
            delete[] fOutBuffer;
            
        }

        // DSP API
        void buildUserInterface(UI* ui_interface)
        {
            // MidiUI ui_interface contains the midi_handler connected to the MIDI driver
            if (dynamic_cast<midi_interface*>(ui_interface)) {
                fMidiHandler = dynamic_cast<midi_interface*>(ui_interface);
                fMidiHandler->addMidiIn(this);
            }
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int sample_rate)
        {
            decorator_dsp::init(sample_rate);
            fVoiceGroup->init(sample_rate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(sample_rate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int sample_rate)
        {
            decorator_dsp::instanceConstants(sample_rate);
            fVoiceGroup->instanceConstants(sample_rate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(sample_rate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual scaleIt_poly* clone()
        {
            return new scaleIt_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= MIX_BUFFER_SIZE);

            // First clear the intermediate fOutBuffer
            clear(count, fOutBuffer);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fCurNote == kLegatoVoice) {
                        // Play from current note and next note
                        voice->computeLegato(count, inputs, fMixBuffer);
                        // FadeOut on first half buffer
                        fadeOut(count/2, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixCheckVoice(count, fMixBuffer, fOutBuffer);
                    } else if (voice->fCurNote != kFreeVoice) {
                        // Compute current note
                        voice->compute(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixCheckVoice(count, fMixBuffer, fOutBuffer);
                        // Check the level to possibly set the voice in kFreeVoice again
                        voice->fRelease -= count;
                        if ((voice->fCurNote == kReleaseVoice)
                            && (voice->fRelease < 0)
                            && (voice->fLevel < VOICE_STOP_LEVEL)) {
                            voice->fCurNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, fOutBuffer);
                }
            }
            
            // Finally copy intermediate buffer to outputs
            copy(count, fOutBuffer, outputs);
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }
    
        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }
 
        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            auto it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                dsp_voice* voice = *it;
                voice->keyOff();
                voice->reset();
            } else {
                fprintf(stderr, "Voice not found\n");
            }
        }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity, fVoiceTable[voice]->fCurNote == kLegatoVoice);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    fprintf(stderr, "Playing pitch = %d not found\n", pitch);
                }
            }
        }

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        // Change the voice release
        void setReleaseLength(double seconds)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->setReleaseLength(seconds);
            }
        }

};

/**
 * Polyphonic DSP with an integrated effect.
 */
class dsp_poly_effect : public dsp_poly {
    
    private:
    
        // fPolyDSP will respond to MIDI messages.
        dsp_poly* fPolyDSP;
        
    public:
        
        dsp_poly_effect(dsp_poly* voice, dsp* combined)
        :dsp_poly(combined), fPolyDSP(voice)
        {}
        
        virtual ~dsp_poly_effect()
        {
            // dsp_poly_effect is also a decorator_dsp, which will free fPolyDSP
        }
    
        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return fPolyDSP->keyOn(channel, pitch, velocity);
        }
        void keyOff(int channel, int pitch, int velocity)
        {
            fPolyDSP->keyOff(channel, pitch, velocity);
        }
        void keyPress(int channel, int pitch, int press)
        {
            fPolyDSP->keyPress(channel, pitch, press);
        }
        void chanPress(int channel, int press)
        {
            fPolyDSP->chanPress(channel, press);
        }
        void ctrlChange(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange(channel, ctrl, value);
        }
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange14bits(channel, ctrl, value);
        }
        void pitchWheel(int channel, int wheel)
        {
            fPolyDSP->pitchWheel(channel, wheel);
        }
        void progChange(int channel, int pgm)
        {
            fPolyDSP->progChange(channel, pgm);
        }
    
        // Change the voice release
        void setReleaseLength(double sec)
        {
            fPolyDSP->setReleaseLength(sec);
        }
    
};

/**
 * Polyphonic DSP factory class. Helper code to support polyphonic DSP source with an integrated effect.
 */
struct dsp_poly_factory : public dsp_factory {
    
    dsp_factory* fProcessFactory;
    dsp_factory* fEffectFactory;
    
    dsp* adaptDSP(dsp* dsp, bool is_double)
    {
        return (is_double) ? new dsp_sample_adapter<double, float>(dsp) : dsp;
    }

    dsp_poly_factory(dsp_factory* process_factory = nullptr,
                     dsp_factory* effect_factory = nullptr):
    fProcessFactory(process_factory)
    ,fEffectFactory(effect_factory)
    {}

    virtual ~dsp_poly_factory()
    {}

    virtual std::string getName() { return fProcessFactory->getName(); }
    virtual std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    virtual std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    virtual std::string getCompileOptions() { return fProcessFactory->getCompileOptions(); }
    virtual std::vector<std::string> getLibraryList() { return fProcessFactory->getLibraryList(); }
    virtual std::vector<std::string> getIncludePathnames() { return fProcessFactory->getIncludePathnames(); }

    std::string getEffectCode(const std::string& dsp_content)
    {
        std::stringstream effect_code;
        effect_code << "adapt(1,1) = _; adapt(2,2) = _,_; adapt(1,2) = _ <: _,_; adapt(2,1) = _,_ :> _;";
        effect_code << "adaptor(F,G) = adapt(outputs(F),inputs(G)); dsp_code = environment{ " << dsp_content << " };";
        effect_code << "process = adaptor(dsp_code.process, dsp_code.effect) : dsp_code.effect;";
        return effect_code.str();
    }

    virtual void setMemoryManager(dsp_memory_manager* manager)
    {
        fProcessFactory->setMemoryManager(manager);
        if (fEffectFactory) {
            fEffectFactory->setMemoryManager(manager);
        }
    }
    virtual dsp_memory_manager* getMemoryManager() { return fProcessFactory->getMemoryManager(); }

    /* Create a new polyphonic DSP instance with global effect, to be deleted with C++ 'delete'
     *
     * @param nvoices - number of polyphony voices, should be at least 1
     * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
     *                If false all voices are always running.
     * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
     *                a given control on all voices, assuming GUI::updateAllGuis() is called.
     *                If false, all voices can be individually controlled.
     * @param is_double - if true, internally allocated DSPs will be adapted to receive 'double' samples.
     */
    dsp_poly* createPolyDSPInstance(int nvoices, bool control, bool group, bool is_double = false)
    {
        dsp_poly* dsp_poly = new scaleIt_poly(adaptDSP(fProcessFactory->createDSPInstance(), is_double), nvoices, control, group);
        if (fEffectFactory) {
            // the 'dsp_poly' object has to be controlled with MIDI, so kept separated from new dsp_sequencer(...) object
            return new dsp_poly_effect(dsp_poly, new dsp_sequencer(dsp_poly, adaptDSP(fEffectFactory->createDSPInstance(), is_double)));
        } else {
            return new dsp_poly_effect(dsp_poly, dsp_poly);
        }
    }

    /* Create a new DSP instance, to be deleted with C++ 'delete' */
    dsp* createDSPInstance()
    {
        return fProcessFactory->createDSPInstance();
    }

};

#endif // __poly_dsp__
/************************** END poly-dsp.h **************************/

list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static t_class* faust_class;

/*--------------------------------------------------------------------------*/
static const char* getCodeSize()
{
    int tmp;
    return (sizeof(&tmp) == 8) ? "64 bits" : "32 bits";
}

/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    map<string, vector<t_object*> > m_output_table;
    short m_where;
    bool m_mute;
    void** m_args;
    mspUI* m_dspUI;
    dsp* m_dsp;
    void* m_control_outlet;
    char* m_json;
    t_systhread_mutex m_mutex;    
    int m_Inputs;
    int m_Outputs;
    SaveUI* m_savedUI;
#ifdef MIDICTRL
    MidiUI* m_midiUI;
    max_midi* m_midiHandler;
    void* m_midi_outlet;
#endif
#ifdef SOUNDFILE
    SoundUI* m_soundInterface;
#endif
#ifdef OSCCTRL
    OSCUI* m_oscInterface;
#endif
} t_faust;

void faust_create_jsui(t_faust* x);
void faust_make_json(t_faust* x);

/*--------------------------------------------------------------------------*/
void faust_allocate(t_faust* x, int nvoices)
{
    // Delete old
    delete x->m_dsp;
    x->m_dspUI->clear();
    
    if (nvoices > 0) {
    #ifdef POST
        post("polyphonic DSP voices = %d", nvoices);
    #endif
        x->m_dsp = new scaleIt_poly(new scaleIt(), nvoices, true, true);
    #ifdef POLY2
        x->m_dsp = new dsp_sequencer(x->m_dsp, new effect());
    #endif
    } else {
    #ifdef POST
        post("monophonic DSP");
    #endif
        // Create a DS/US + Filter adapted DSP
        x->m_dsp = createSRAdapter<FAUSTFLOAT>(new scaleIt(), DOWN_SAMPLING, UP_SAMPLING, FILTER_TYPE);
    }
    
#ifdef MIDICTRL
    x->m_dsp->buildUserInterface(x->m_midiUI);
#endif
  
    // Possible sample adaptation
    if (sizeof(FAUSTFLOAT) == 4) {
        x->m_dsp = new dsp_sample_adapter<FAUSTFLOAT, double>(x->m_dsp);
    }
    
    x->m_Inputs = x->m_dsp->getNumInputs();
    x->m_Outputs = x->m_dsp->getNumOutputs();
    
    // Initialize at the system's sampling rate
    x->m_dsp->init(long(sys_getsr()));
    
    // Initialize User Interface (here connnection with controls)
    x->m_dsp->buildUserInterface(x->m_dspUI);
    
#ifdef SOUNDFILE
    x->m_dsp->buildUserInterface(x->m_soundInterface);
#endif
    
    // Prepare JSON
    faust_make_json(x);
    
    // Send JSON to JS script
    faust_create_jsui(x);
    
#ifdef OSCCTRL
    x->m_oscInterface = NULL;
#endif
    
    // Load old controller state
    x->m_dsp->buildUserInterface(x->m_savedUI);
}

/*--------------------------------------------------------------------------*/
void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    bool res = false;
    string name = string((s)->s_name);
    
    // If no argument is there, consider it as a toggle message for a button
    if (ac == 0 && obj->m_dspUI->isValue(name)) {
        
        FAUSTFLOAT off = FAUSTFLOAT(0.0);
        FAUSTFLOAT on = FAUSTFLOAT(1.0);
        obj->m_dspUI->setValue(name, off);
        obj->m_dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_anything(obj, s, 1, av);
        
    } else if (mspUI::checkDigit(name)) { // List of values
        
        int pos, ndigit = 0;
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            FAUSTFLOAT value;
            switch (atom_gettype(ap)) {
                case A_LONG:
                    value = FAUSTFLOAT(ap[0].a_w.w_long);
                    break;
                case A_FLOAT:
                    value = FAUSTFLOAT(ap[0].a_w.w_float);
                    break;
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            string num_val = to_string(num + i);
            stringstream param_name; param_name << prefix;
            for (int i = 0; i < ndigit - mspUI::countDigit(num_val); i++) {
                param_name << ' ';
            }
            param_name << num_val;
              
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name.str(), value);
            
            // Otherwise try standard name
            if (!res) {
                res = obj->m_dspUI->setValue(name, value);
            }
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
        
    } else {
        // Standard parameter name
        FAUSTFLOAT value = (av[0].a_type == A_LONG) ? FAUSTFLOAT(av[0].a_w.w_long) : FAUSTFLOAT(av[0].a_w.w_float);
        res = obj->m_dspUI->setValue(name, value);
        if (!res) {
            post("Unknown parameter : %s", (s)->s_name);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_polyphony(t_faust* x, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(x->m_mutex) == MAX_ERR_NONE) {
        faust_allocate(x, av[0].a_w.w_long);
        systhread_mutex_unlock(x->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* x, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            x->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            x->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            x->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
        }
    }
}
#endif

/*--------------------------------------------------------------------------*/
void faust_create_jsui(t_faust* x)
{
    t_object *patcher, *box, *obj;
    object_obex_lookup((t_object*)x, gensym("#P"), &patcher);
    
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        // Notify JSON
        if (obj && strcmp(object_classname(obj)->s_name, "js") == 0) {
            t_atom json;
            atom_setsym(&json, gensym(x->m_json));
            object_method_typed(obj, gensym("anything"), 1, &json, 0);
        }
    }
        
    // Keep all outputs to be notified in update_outputs
    x->m_output_table.clear();
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        t_symbol* scriptingname = jbox_get_varname(obj); // scripting name
        // Keep control outputs
        if (scriptingname && x->m_dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name].push_back(obj);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_update_outputs(t_faust* x)
{
    for (const auto& it1 : x->m_output_table) {
        bool new_val = false;
        FAUSTFLOAT value = x->m_dspUI->getOutputValue(it1.first, new_val);
        if (new_val) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            for (const auto& it2 : it1.second) {
                object_method_typed(it2, gensym("float"), 1, &at_value, 0);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_make_json(t_faust* x)
{
    // Prepare JSON
    if (x->m_json) free(x->m_json);
    JSONUI builder(x->m_dsp->getNumInputs(), x->m_dsp->getNumOutputs());
    x->m_dsp->metadata(&builder);
    x->m_dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    bool midi_sync = false;
    int nvoices = 0;
    t_faust* x = (t_faust*)object_alloc(faust_class);
    
    scaleIt* tmp_dsp = new scaleIt();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
 #ifdef SOUNDFILE
    Max_Meta3 meta3;
    tmp_dsp->metadata(&meta3);
    string bundle_path_str = SoundUI::getBinaryPathFrom(meta3.fName);
    if (bundle_path_str == "") {
        post("Bundle_path '%s' cannot be found!", meta3.fName.c_str());
    }
    x->m_soundInterface = new SoundUI(bundle_path_str, -1, nullptr, sizeof(FAUSTFLOAT) == 8);
 #endif
    delete tmp_dsp;
    
    x->m_savedUI = new SaveLabelUI();
    x->m_dspUI = new mspUI();
    x->m_dsp = NULL;
    x->m_json = NULL;
    x->m_mute = false;
    x->m_control_outlet = outlet_new((t_pxobject*)x, (char*)"list");
    
#ifdef MIDICTRL
    x->m_midi_outlet = outlet_new((t_pxobject*)x, NULL);
    x->m_midiHandler = new max_midi(x->m_midi_outlet);
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
    faust_allocate(x, nvoices);
   
    if (systhread_mutex_new(&x->m_mutex, SYSTHREAD_MUTEX_NORMAL) != MAX_ERR_NONE) {
        post("Cannot allocate mutex...");
    }
    
    int num_input;
    if (x->m_dspUI->isMulti()) {
        num_input = x->m_dsp->getNumInputs() + 1;
    } else {
        num_input = x->m_dsp->getNumInputs();
    }
    
    x->m_args = (void**)calloc((num_input + x->m_dsp->getNumOutputs()) + 2, sizeof(void*));
    
    /* Multi in */
    dsp_setup((t_pxobject*)x, num_input);

    /* Multi out */
    for (int i = 0; i < x->m_dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different
 
    // Display controls
#ifdef POST
    x->m_dspUI->displayControls();
#endif
    
    // Get attributes values
    attr_args_process(x, ac, av);
    return x;
}

#ifdef OSCCTRL
// osc 'IP inport outport xmit bundle'
/*--------------------------------------------------------------------------*/
void faust_osc(t_faust* x, t_symbol* s, short ac, t_atom* av)
{
    if (ac == 5) {
        if (systhread_mutex_lock(x->m_mutex) == MAX_ERR_NONE) {
            
            delete x->m_oscInterface;
            
            const char* argv1[32];
            int argc1 = 0;
            
            argv1[argc1++] = "Faust";
            
            argv1[argc1++]  = "-desthost";
            argv1[argc1++]  = atom_getsym(&av[0])->s_name;
            
            char inport[32];
            snprintf(inport, 32, "%ld", long(av[1].a_w.w_long));
            argv1[argc1++] = "-port";
            argv1[argc1++] = inport;
            
            char outport[32];
            snprintf(outport, 32, "%ld", long(av[2].a_w.w_long));
            argv1[argc1++] = "-outport";
            argv1[argc1++] = outport;
            
            char xmit[32];
            snprintf(xmit, 32, "%ld", long(av[3].a_w.w_long));
            argv1[argc1++] = "-xmit";
            argv1[argc1++] = xmit;
            
            char bundle[32];
            snprintf(bundle, 32, "%ld", long(av[4].a_w.w_long));
            argv1[argc1++] = "-bundle";
            argv1[argc1++] = bundle;
            
            x->m_oscInterface = new OSCUI("Faust", argc1, (char**)argv1);
            x->m_dsp->buildUserInterface(x->m_oscInterface);
            x->m_oscInterface->run();

            post(x->m_oscInterface->getInfos().c_str());

            systhread_mutex_unlock(x->m_mutex);
        } else {
            post("Mutex lock cannot be taken...");
        }
    } else {
        post("Should be : osc 'IP inport outport xmit(0|1|2) bundle(0|1)'");
    }
}
#endif

/*--------------------------------------------------------------------------*/
// Reset controllers to init value and send [path, init, min, max]
void faust_init(t_faust* x, t_symbol* s, short ac, t_atom* av)
{
    // Reset internal state
    x->m_savedUI->reset();
    
    // Input controllers
    for (mspUI::iterator it = x->m_dspUI->begin2(); it != x->m_dspUI->end2(); it++) {
        t_atom myList[4];
        atom_setsym(&myList[0], gensym((*it).first.c_str()));
        atom_setfloat(&myList[1], (*it).second->getInitValue());    // init value
        atom_setfloat(&myList[2], (*it).second->getMinValue());
        atom_setfloat(&myList[3], (*it).second->getMaxValue());
        outlet_list(x->m_control_outlet, 0, 4, myList);
    }
    // Output controllers
    for (mspUI::iterator it = x->m_dspUI->begin4(); it != x->m_dspUI->end4(); it++) {
        t_atom myList[4];
        atom_setsym(&myList[0], gensym((*it).first.c_str()));
        atom_setfloat(&myList[1], (*it).second->getInitValue());    // init value
        atom_setfloat(&myList[2], (*it).second->getMinValue());
        atom_setfloat(&myList[3], (*it).second->getMaxValue());
        outlet_list(x->m_control_outlet, 0, 4, myList);
    }
 }

/*--------------------------------------------------------------------------*/
void faust_dump_inputs(t_faust* x)
{
    // Input controllers
    for (mspUI::iterator it = x->m_dspUI->begin2(); it != x->m_dspUI->end2(); it++) {
        t_atom myList[4];
        atom_setsym(&myList[0], gensym((*it).first.c_str()));
        atom_setfloat(&myList[1], (*it).second->getValue());    // cur value
        atom_setfloat(&myList[2], (*it).second->getMinValue());
        atom_setfloat(&myList[3], (*it).second->getMaxValue());
        outlet_list(x->m_control_outlet, 0, 4, myList);
    }
}

/*--------------------------------------------------------------------------*/
void faust_dump_outputs(t_faust* x)
{
    // Output controllers
    for (mspUI::iterator it = x->m_dspUI->begin4(); it != x->m_dspUI->end4(); it++) {
        t_atom myList[4];
        atom_setsym(&myList[0], gensym((*it).first.c_str()));
        atom_setfloat(&myList[1], (*it).second->getValue());    // cur value
        atom_setfloat(&myList[2], (*it).second->getMinValue());
        atom_setfloat(&myList[3], (*it).second->getMaxValue());
        outlet_list(x->m_control_outlet, 0, 4, myList);
    }
}

/*--------------------------------------------------------------------------*/
// Dump controllers as list of [path, cur, min, max]
void faust_dump(t_faust* x, t_symbol* s, short ac, t_atom* av)
{
    faust_dump_inputs(x);
    faust_dump_outputs(x);
}

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    x->m_dspUI->displayControls();
}

/*--------------------------------------------------------------------------*/
//11/13/2015 : faust_assist is actually called at each click in the patcher, so we now use 'faust_dblclick' to display the parameters...
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->m_dsp->getNumInputs() == 0) {
                sprintf(dst, "(messages)");
            } else {
                sprintf(dst, "(messages/signal) : Audio Input %ld", (a+1));
            }
        } else if (a < x->m_dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        if (a < x->m_dsp->getNumOutputs()) {
            sprintf(dst, "(signal) : Audio Output %ld", (a+1));
        } else if (a == x->m_dsp->getNumOutputs()) {
            sprintf(dst, "(list) : [path, cur|init, min, max]*");
        } else {
            sprintf(dst, "(int) : raw MIDI bytes*");
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
    dsp_free((t_pxobject*)x);
    delete x->m_dsp;
    delete x->m_dspUI;
    delete x->m_savedUI;
    if (x->m_args) free(x->m_args);
    if (x->m_json) free(x->m_json);
    systhread_mutex_free(x->m_mutex);
#ifdef MIDICTRL
    // m_midiUI *must* be deleted before m_midiHandler
    delete x->m_midiUI;
    delete x->m_midiHandler;
#endif
#ifdef SOUNDFILE
    delete x->m_soundInterface;
#endif
#ifdef OSCCTRL
    delete x->m_oscInterface;
#endif
}

/*--------------------------------------------------------------------------*/
void faust_perform64(t_faust* x, t_object* dsp64, double** ins, long numins, double** outs, long numouts, long sampleframes, long flags, void* userparam)
{
    AVOIDDENORMALS;
    if (!x->m_mute && systhread_mutex_trylock(x->m_mutex) == MAX_ERR_NONE) {
        if (x->m_dsp) {
            if (x->m_dspUI->isMulti()) {
                x->m_dspUI->setMultiValues(reinterpret_cast<FAUSTFLOAT*>(ins[0]), sampleframes);
                x->m_dsp->compute(sampleframes, reinterpret_cast<FAUSTFLOAT**>(++ins), reinterpret_cast<FAUSTFLOAT**>(outs));
            } else {
                x->m_dsp->compute(sampleframes, reinterpret_cast<FAUSTFLOAT**>(ins), reinterpret_cast<FAUSTFLOAT**>(outs));
            }
        #ifdef OSCCTRL
            if (x->m_oscInterface) x->m_oscInterface->endBundle();
        #endif
            //faust_update_outputs(x);
            // Use the right outlet to output messages
            faust_dump_outputs(x);
        }
    #if defined(MIDICTRL) || defined(OSCCTRL)
        GUI::updateAllGuis();
    #endif
        systhread_mutex_unlock(x->m_mutex);
    } else {
        // Write null buffers to outs
        for (int i = 0; i < numouts; i++) {
             memset(outs[i], 0, sizeof(double) * sampleframes);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_dsp64(t_faust* x, t_object* dsp64, short* count, double samplerate, long maxvectorsize, long flags)
{
    object_method(dsp64, gensym("dsp_add64"), x, faust_perform64, 0, NULL);
}

/*--------------------------------------------------------------------------*/
t_max_err faust_attr_set(t_faust* x, t_object* attr, long ac, t_atom* av)
{
    if (ac && av) {
        t_symbol* attrname = (t_symbol*)object_method(attr, gensym("getname"));
        // Redirect on the generic message handling method
        faust_anything(x, attrname, ac, av);
    }
    return MAX_ERR_NONE;
}

/*--------------------------------------------------------------------------*/
#ifdef _WIN32
extern "C" int main(void)
#else
void ext_main(void* r)
#endif
{
    string file_name = string(FAUST_FILE_NAME);
    // Remove ".dsp" ending
    string class_name = file_name.erase(file_name.size()-4) + "~";
    t_class* c = class_new(class_name.c_str(), (method)faust_new, (method)faust_free, sizeof(t_faust), 0L, A_GIMME, 0);
    
    class_addmethod(c, (method)faust_anything, "anything", A_GIMME, 0);
    class_addmethod(c, (method)faust_polyphony, "polyphony", A_GIMME, 0);
#ifdef OSCCTRL
    class_addmethod(c, (method)faust_osc, "osc", A_GIMME, 0);
#endif
    class_addmethod(c, (method)faust_init, "init", A_GIMME, 0);
    class_addmethod(c, (method)faust_dump, "dump", A_GIMME, 0);
#ifdef MIDICTRL
    class_addmethod(c, (method)faust_midievent, "midievent", A_GIMME, 0);
#endif
    class_addmethod(c, (method)faust_dsp64, "dsp64", A_CANT, 0);
    class_addmethod(c, (method)faust_dblclick, "dblclick", A_CANT, 0);
    class_addmethod(c, (method)faust_assist, "assist", A_CANT, 0);
    class_addmethod(c, (method)faust_mute, "mute", A_GIMME, 0);
    
    dsp* tmp_dsp = new scaleIt();
    mspUI tmp_UI;
    tmp_dsp->buildUserInterface(&tmp_UI);
    
    // Setup attributes
    if (sizeof(FAUSTFLOAT) == 4) {
        for (mspUI::iterator it = tmp_UI.begin1(); it != tmp_UI.end1(); it++) {
            CLASS_ATTR_FLOAT(c, (*it).first.c_str(), 0, t_faust, m_ob);
            CLASS_ATTR_ACCESSORS(c, (*it).first.c_str(), NULL, (method)faust_attr_set);
        }
    } else {
        for (mspUI::iterator it = tmp_UI.begin1(); it != tmp_UI.end1(); it++) {
            CLASS_ATTR_DOUBLE(c, (*it).first.c_str(), 0, t_faust, m_ob);
            CLASS_ATTR_ACCESSORS(c, (*it).first.c_str(), NULL, (method)faust_attr_set);
        }
    }
    
    class_dspinit(c);
    class_register(CLASS_BOX, c);
    faust_class = c;
#ifdef POST
    post((char*)"Faust DSP object v%s (sample = %s bits code = %s)", EXTERNAL_VERSION, ((sizeof(FAUSTFLOAT) == 4) ? "32" : "64"), getCodeSize());
    post((char*)"Copyright (c) 2012-2022 Grame");
#endif
    Max_Meta1 meta1;
    tmp_dsp->metadata(&meta1);
    if (meta1.fCount > 0) {
    #ifdef POST
        Max_Meta2 meta2;
        post("------------------------------");
        tmp_dsp->metadata(&meta2);
        post("------------------------------");
    #endif
    }
    delete(tmp_dsp);
#ifdef _WIN32
    return 0;
#endif
}

/******************* END max-msp64.cpp ****************/


#endif
