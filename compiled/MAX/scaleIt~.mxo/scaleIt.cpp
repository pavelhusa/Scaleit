/* ------------------------------------------------------------
name: "scaleIt"
Code generated with Faust 2.54.9 (https://faust.grame.fr)
Compilation options: -a /opt/homebrew/Cellar/faust/2.54.9/share/faust/max-msp/max-msp64.cpp -lang cpp -i -cn scaleIt -es 1 -mcd 16 -uim -double -ftz 0
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

#define FAUSTVERSION "2.54.9"

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
        virtual std::vector<std::string> getWarningMessages() = 0;
    
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
                } else if ((strcmp(key, "hidden") == 0) && (strcmp(value, "1") == 0)) {
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
                else if ((strcmp(key, "hidden") == 0) && (strcmp(value, "1") == 0)) {
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

const static int iscaleItSIG0Wave0[12] = {0,2,4,5,7,9,11,12,14,16,17,19};
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

const static int iscaleItSIG1Wave0[12] = {0,2,3,5,7,9,10,12,14,15,17,19};
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

const static int iscaleItSIG2Wave0[12] = {0,1,3,5,7,8,10,12,13,15,17,19};
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

const static int iscaleItSIG3Wave0[12] = {0,2,4,6,7,9,11,12,14,16,17,18};
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

const static int iscaleItSIG4Wave0[12] = {0,2,4,5,7,9,10,12,14,15,17,18};
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
			iscaleItSIG4Wave0_idx = (1 + iscaleItSIG4Wave0_idx) % 12;
		}
	}

};

static scaleItSIG4* newscaleItSIG4() { return (scaleItSIG4*)new scaleItSIG4(); }
static void deletescaleItSIG4(scaleItSIG4* dsp) { delete dsp; }

const static int iscaleItSIG5Wave0[12] = {0,2,3,5,7,8,10,12,14,15,17,18};
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

const static int iscaleItSIG6Wave0[12] = {0,1,3,5,6,8,10,12,13,15,17,18};
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

const static int iscaleItSIG7Wave0[13] = {0,2,4,7,9,12,14,16,19,21,24,26,28};
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

const static int iscaleItSIG8Wave0[13] = {0,3,5,7,10,12,15,17,19,22,24,27,29};
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

const static int iscaleItSIG9Wave0[12] = {0,1,5,6,10,12,13,17,18,22,24,25};
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

const static int iscaleItSIG10Wave0[12] = {0,2,3,7,8,12,14,15,19,20,24,26};
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

const static int iscaleItSIG11Wave0[13] = {0,1,2,3,4,5,6,7,8,9,10,12,13};
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
			iscaleItSIG11Wave0_idx = (1 + iscaleItSIG11Wave0_idx) % 13;
		}
	}

};

static scaleItSIG11* newscaleItSIG11() { return (scaleItSIG11*)new scaleItSIG11(); }
static void deletescaleItSIG11(scaleItSIG11* dsp) { delete dsp; }

const static int iscaleItSIG12Wave0[12] = {0,2,4,6,8,10,12,14,16,18,20,22};
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

const static int iscaleItSIG13Wave0[12] = {0,4,7,12,16,19,24,28,31,36,40,43};
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

const static int iscaleItSIG14Wave0[12] = {0,4,7,11,12,16,19,23,24,28,31,35};
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

const static int iscaleItSIG15Wave0[12] = {0,3,7,12,15,19,24,27,31,36,39,43};
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
	
	int iVec2[2];
	int iRec4[2];
	
  public:
	
	int getNumInputsscaleItSIG16() {
		return 0;
	}
	int getNumOutputsscaleItSIG16() {
		return 1;
	}
	
	void instanceInitscaleItSIG16(int sample_rate) {
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iVec2[l6] = 0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec4[l7] = 0;
		}
	}
	
	void fillscaleItSIG16(int count, double* table) {
		for (int i17 = 0; i17 < count; i17 = i17 + 1) {
			iVec2[0] = 1;
			iRec4[0] = (iVec2[1] + iRec4[1]) % 65536;
			table[i17] = std::sin(9.587379924285257e-05 * double(iRec4[0]));
			iVec2[1] = iVec2[0];
			iRec4[1] = iRec4[0];
		}
	}

};

static scaleItSIG16* newscaleItSIG16() { return (scaleItSIG16*)new scaleItSIG16(); }
static void deletescaleItSIG16(scaleItSIG16* dsp) { delete dsp; }

static double scaleIt_faustpower2_f(double value) {
	return value * value;
}
static int itbl0scaleItSIG0[12];
static int itbl1scaleItSIG1[12];
static int itbl2scaleItSIG2[12];
static int itbl3scaleItSIG3[12];
static int itbl4scaleItSIG4[12];
static int itbl5scaleItSIG5[12];
static int itbl6scaleItSIG6[12];
static int itbl7scaleItSIG7[13];
static int itbl8scaleItSIG8[13];
static int itbl9scaleItSIG9[12];
static int itbl10scaleItSIG10[12];
static int itbl11scaleItSIG11[13];
static int itbl12scaleItSIG12[12];
static int itbl13scaleItSIG13[12];
static int itbl14scaleItSIG14[12];
static int itbl15scaleItSIG15[12];
static double ftbl16scaleItSIG16[65536];

class scaleIt : public dsp {
	
 public:
	
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fEntry2;
	int fSampleRate;
	double fConst0;
	FAUSTFLOAT fEntry3;
	FAUSTFLOAT fEntry4;
	FAUSTFLOAT fEntry5;
	FAUSTFLOAT fEntry6;
	int iVec0[2];
	int iVec1[2];
	int iRec0[2];
	FAUSTFLOAT fEntry7;
	FAUSTFLOAT fEntry8;
	FAUSTFLOAT fEntry9;
	int iRec1[2];
	double fConst1;
	int iRec3[2];
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	FAUSTFLOAT fEntry10;
	FAUSTFLOAT fEntry11;
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
	int iConst20;
	int iConst21;
	int iConst22;
	FAUSTFLOAT fEntry12;
	double fConst23;
	double fConst24;
	double fRec2[3];
	FAUSTFLOAT fEntry13;
	FAUSTFLOAT fEntry14;
	FAUSTFLOAT fEntry15;
	double fConst25;
	double fRec5[2];
	double fRec6[2];
	double fConst26;
	double fConst27;
	double fRec9[2];
	double fVec3[2];
	int IOTA0;
	double fVec4[4096];
	double fConst28;
	double fRec8[2];
	FAUSTFLOAT fEntry16;
	FAUSTFLOAT fEntry17;
	int iVec5[2];
	int iRec10[2];
	int iRec11[2];
	int iConst29;
	int iConst30;
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
	FAUSTFLOAT fEntry18;
	double fRec12[2];
	double fRec13[2];
	double fRec16[2];
	double fVec6[2];
	double fVec7[4096];
	double fRec15[2];
	double fRec17[3];
	FAUSTFLOAT fEntry19;
	int iVec8[2];
	int iRec18[2];
	int iRec19[2];
	int iConst45;
	int iConst46;
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
	FAUSTFLOAT fEntry20;
	double fRec20[2];
	double fRec21[2];
	double fRec24[2];
	double fVec9[2];
	double fVec10[4096];
	double fRec23[2];
	double fRec25[3];
	FAUSTFLOAT fEntry21;
	int iVec11[2];
	int iRec26[2];
	int iRec27[2];
	int iConst61;
	int iConst62;
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
	FAUSTFLOAT fEntry22;
	double fRec28[2];
	double fRec29[2];
	double fRec32[2];
	double fVec12[2];
	double fVec13[4096];
	double fRec31[2];
	double fRec33[3];
	FAUSTFLOAT fEntry23;
	int iVec14[2];
	int iRec34[2];
	int iRec35[2];
	int iConst77;
	int iConst78;
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
	FAUSTFLOAT fEntry24;
	double fRec36[2];
	double fRec37[2];
	double fRec40[2];
	double fVec15[2];
	double fVec16[4096];
	double fRec39[2];
	double fRec41[3];
	FAUSTFLOAT fEntry25;
	int iVec17[2];
	int iRec42[2];
	int iRec43[2];
	int iConst93;
	int iConst94;
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
	FAUSTFLOAT fEntry26;
	double fRec44[2];
	double fRec45[2];
	double fRec48[2];
	double fVec18[2];
	double fVec19[4096];
	double fRec47[2];
	double fRec49[3];
	FAUSTFLOAT fEntry27;
	int iVec20[2];
	int iRec50[2];
	int iRec51[2];
	int iConst109;
	int iConst110;
	int iConst111;
	int iConst112;
	int iConst113;
	int iConst114;
	int iConst115;
	int iConst116;
	int iConst117;
	int iConst118;
	int iConst119;
	int iConst120;
	int iConst121;
	int iConst122;
	int iConst123;
	int iConst124;
	FAUSTFLOAT fEntry28;
	double fRec52[2];
	double fRec53[2];
	double fRec56[2];
	double fVec21[2];
	double fVec22[4096];
	double fRec55[2];
	double fRec57[3];
	FAUSTFLOAT fEntry29;
	int iVec23[2];
	int iRec58[2];
	int iRec59[2];
	int iConst125;
	int iConst126;
	int iConst127;
	int iConst128;
	int iConst129;
	int iConst130;
	int iConst131;
	int iConst132;
	int iConst133;
	int iConst134;
	int iConst135;
	int iConst136;
	int iConst137;
	int iConst138;
	int iConst139;
	int iConst140;
	FAUSTFLOAT fEntry30;
	double fRec60[2];
	double fRec61[2];
	double fRec64[2];
	double fVec24[2];
	double fVec25[4096];
	double fRec63[2];
	double fRec65[3];
	FAUSTFLOAT fEntry31;
	int iVec26[2];
	int iRec66[2];
	int iRec67[2];
	int iConst141;
	int iConst142;
	int iConst143;
	int iConst144;
	int iConst145;
	int iConst146;
	int iConst147;
	int iConst148;
	int iConst149;
	int iConst150;
	int iConst151;
	int iConst152;
	int iConst153;
	int iConst154;
	int iConst155;
	int iConst156;
	FAUSTFLOAT fEntry32;
	double fRec68[2];
	double fRec69[2];
	double fRec72[2];
	double fVec27[2];
	double fVec28[4096];
	double fRec71[2];
	double fRec73[3];
	FAUSTFLOAT fEntry33;
	int iVec29[2];
	int iRec74[2];
	int iRec75[2];
	int iConst157;
	int iConst158;
	int iConst159;
	int iConst160;
	int iConst161;
	int iConst162;
	int iConst163;
	int iConst164;
	int iConst165;
	int iConst166;
	int iConst167;
	int iConst168;
	int iConst169;
	int iConst170;
	int iConst171;
	int iConst172;
	FAUSTFLOAT fEntry34;
	double fRec76[2];
	double fRec77[2];
	double fRec80[2];
	double fVec30[2];
	double fVec31[4096];
	double fRec79[2];
	double fRec81[3];
	FAUSTFLOAT fEntry35;
	int iVec32[2];
	int iRec82[2];
	int iRec83[2];
	int iConst173;
	int iConst174;
	int iConst175;
	int iConst176;
	int iConst177;
	int iConst178;
	int iConst179;
	int iConst180;
	int iConst181;
	int iConst182;
	int iConst183;
	int iConst184;
	int iConst185;
	int iConst186;
	int iConst187;
	int iConst188;
	FAUSTFLOAT fEntry36;
	double fRec84[2];
	double fRec85[2];
	double fRec88[2];
	double fVec33[2];
	double fVec34[4096];
	double fRec87[2];
	double fRec89[3];
	FAUSTFLOAT fEntry37;
	int iVec35[2];
	int iRec90[2];
	int iRec91[2];
	int iConst189;
	int iConst190;
	int iConst191;
	int iConst192;
	int iConst193;
	int iConst194;
	int iConst195;
	int iConst196;
	int iConst197;
	int iConst198;
	int iConst199;
	int iConst200;
	int iConst201;
	int iConst202;
	int iConst203;
	int iConst204;
	FAUSTFLOAT fEntry38;
	double fRec92[2];
	double fRec93[2];
	double fRec96[2];
	double fVec36[2];
	double fVec37[4096];
	double fRec95[2];
	double fRec97[3];
	double fConst205;
	double fConst206;
	double fConst207;
	double fConst208;
	double fRec99[2];
	double fRec98[2];
	double fConst209;
	double fConst210;
	double fConst211;
	double fConst212;
	double fRec101[2];
	double fRec100[2];
	FAUSTFLOAT fEntry39;
	int iVec38[2];
	int iRec102[2];
	int iRec103[2];
	FAUSTFLOAT fEntry40;
	double fRec104[2];
	double fRec105[2];
	double fConst213;
	double fRec108[2];
	double fVec39[2];
	double fVec40[4096];
	double fRec107[2];
	double fRec109[3];
	int iVec41[2];
	int iRec110[2];
	int iRec111[2];
	double fRec112[2];
	double fRec113[2];
	double fRec116[2];
	double fVec42[2];
	double fVec43[4096];
	double fRec115[2];
	double fRec117[3];
	int iVec44[2];
	int iRec118[2];
	int iRec119[2];
	double fRec120[2];
	double fRec121[2];
	double fRec124[2];
	double fVec45[2];
	double fVec46[4096];
	double fRec123[2];
	double fRec125[3];
	int iVec47[2];
	int iRec126[2];
	int iRec127[2];
	double fRec128[2];
	double fRec129[2];
	double fRec132[2];
	double fVec48[2];
	double fVec49[4096];
	double fRec131[2];
	double fRec133[3];
	int iVec50[2];
	int iRec134[2];
	int iRec135[2];
	double fRec136[2];
	double fRec137[2];
	double fRec140[2];
	double fVec51[2];
	double fVec52[4096];
	double fRec139[2];
	double fRec141[3];
	int iVec53[2];
	int iRec142[2];
	int iRec143[2];
	double fRec144[2];
	double fRec145[2];
	double fRec148[2];
	double fVec54[2];
	double fVec55[4096];
	double fRec147[2];
	double fRec149[3];
	double fRec151[2];
	double fRec150[2];
	double fRec153[2];
	double fRec152[2];
	double fRec155[2];
	double fRec154[2];
	double fRec157[2];
	double fRec156[2];
	int iVec56[2];
	int iRec158[2];
	int iRec159[2];
	double fRec160[2];
	double fRec161[2];
	double fRec164[2];
	double fVec57[2];
	double fVec58[4096];
	double fRec163[2];
	double fRec165[3];
	int iVec59[2];
	int iRec166[2];
	int iRec167[2];
	double fRec168[2];
	double fRec169[2];
	double fRec172[2];
	double fVec60[2];
	double fVec61[4096];
	double fRec171[2];
	double fRec173[3];
	int iVec62[2];
	int iRec174[2];
	int iRec175[2];
	double fRec176[2];
	double fRec177[2];
	double fRec180[2];
	double fVec63[2];
	double fVec64[4096];
	double fRec179[2];
	double fRec181[3];
	int iVec65[2];
	int iRec182[2];
	int iRec183[2];
	double fRec184[2];
	double fRec185[2];
	double fRec188[2];
	double fVec66[2];
	double fVec67[4096];
	double fRec187[2];
	double fRec189[3];
	int iVec68[2];
	int iRec190[2];
	int iRec191[2];
	double fRec192[2];
	double fRec193[2];
	double fRec196[2];
	double fVec69[2];
	double fVec70[4096];
	double fRec195[2];
	double fRec197[3];
	int iVec71[2];
	int iRec198[2];
	int iRec199[2];
	double fRec200[2];
	double fRec201[2];
	double fRec204[2];
	double fVec72[2];
	double fVec73[4096];
	double fRec203[2];
	double fRec205[3];
	double fRec207[2];
	double fRec206[2];
	double fRec209[2];
	double fRec208[2];
	FAUSTFLOAT fHbargraph0;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.2");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/parallelMax:author", "Bart Brouns");
		m->declare("basics.lib/parallelMax:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelMax:licence", "GPL-3.0");
		m->declare("basics.lib/parallelMin:author", "Bart Brouns");
		m->declare("basics.lib/parallelMin:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelMin:licence", "GPL-3.0");
		m->declare("basics.lib/parallelOp:author", "Bart Brouns");
		m->declare("basics.lib/parallelOp:copyright", "Copyright (c) 2020 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/parallelOp:licence", "GPL-3.0");
		m->declare("basics.lib/selectoutn:author", "Vince");
		m->declare("basics.lib/version", "0.9");
		m->declare("compile_options", "-a /opt/homebrew/Cellar/faust/2.54.9/share/faust/max-msp/max-msp64.cpp -lang cpp -i -cn scaleIt -es 1 -mcd 16 -uim -double -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_lad_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_lad_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_lad_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/limiter_1176_R4_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/limiter_1176_R4_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/limiter_1176_R4_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "0.4");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.2");
		m->declare("filename", "scaleIt.dsp");
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "scaleIt");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.4");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/saw2ptr:author", "Julius O. Smith III");
		m->declare("oscillators.lib/saw2ptr:license", "STK-4.3");
		m->declare("oscillators.lib/sawN:author", "Julius O. Smith III");
		m->declare("oscillators.lib/sawN:license", "STK-4.3");
		m->declare("oscillators.lib/version", "0.3");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.3");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
		m->declare("signals.lib/version", "0.3");
		m->declare("spats.lib/name", "Faust Spatialization Library");
		m->declare("spats.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 4;
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
		sig4->fillscaleItSIG4(12, itbl4scaleItSIG4);
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
		sig11->fillscaleItSIG11(13, itbl11scaleItSIG11);
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
		fConst1 = 2.0 / fConst0;
		fConst2 = 1.0 / fConst0;
		fConst3 = scaleIt_faustpower2_f(fConst2);
		fConst4 = 2.0 * fConst3;
		fConst5 = 4.0 * scaleIt_faustpower2_f(fConst0);
		fConst6 = 3.141592653589793 / fConst0;
		iConst7 = itbl0scaleItSIG0[0];
		iConst8 = itbl1scaleItSIG1[0];
		iConst9 = itbl2scaleItSIG2[0];
		iConst10 = itbl3scaleItSIG3[0];
		iConst11 = itbl4scaleItSIG4[0];
		iConst12 = itbl5scaleItSIG5[0];
		iConst13 = itbl6scaleItSIG6[0];
		iConst14 = itbl7scaleItSIG7[0];
		iConst15 = itbl8scaleItSIG8[0];
		iConst16 = itbl9scaleItSIG9[0];
		iConst17 = itbl10scaleItSIG10[0];
		iConst18 = itbl11scaleItSIG11[0];
		iConst19 = itbl12scaleItSIG12[0];
		iConst20 = itbl13scaleItSIG13[0];
		iConst21 = itbl14scaleItSIG14[0];
		iConst22 = itbl15scaleItSIG15[0];
		fConst23 = 2.0 * fConst0;
		fConst24 = 0.5 / fConst0;
		fConst25 = 4.4e+02 / fConst0;
		fConst26 = 1.76e+03 / fConst0;
		fConst27 = 0.25 * fConst0;
		fConst28 = 0.5 * fConst0;
		iConst29 = itbl0scaleItSIG0[1];
		iConst30 = itbl1scaleItSIG1[1];
		iConst31 = itbl2scaleItSIG2[1];
		iConst32 = itbl3scaleItSIG3[1];
		iConst33 = itbl4scaleItSIG4[1];
		iConst34 = itbl5scaleItSIG5[1];
		iConst35 = itbl6scaleItSIG6[1];
		iConst36 = itbl7scaleItSIG7[1];
		iConst37 = itbl8scaleItSIG8[1];
		iConst38 = itbl9scaleItSIG9[1];
		iConst39 = itbl10scaleItSIG10[1];
		iConst40 = itbl11scaleItSIG11[1];
		iConst41 = itbl12scaleItSIG12[1];
		iConst42 = itbl13scaleItSIG13[1];
		iConst43 = itbl14scaleItSIG14[1];
		iConst44 = itbl15scaleItSIG15[1];
		iConst45 = itbl0scaleItSIG0[2];
		iConst46 = itbl1scaleItSIG1[2];
		iConst47 = itbl2scaleItSIG2[2];
		iConst48 = itbl3scaleItSIG3[2];
		iConst49 = itbl4scaleItSIG4[2];
		iConst50 = itbl5scaleItSIG5[2];
		iConst51 = itbl6scaleItSIG6[2];
		iConst52 = itbl7scaleItSIG7[2];
		iConst53 = itbl8scaleItSIG8[2];
		iConst54 = itbl9scaleItSIG9[2];
		iConst55 = itbl10scaleItSIG10[2];
		iConst56 = itbl11scaleItSIG11[2];
		iConst57 = itbl12scaleItSIG12[2];
		iConst58 = itbl13scaleItSIG13[2];
		iConst59 = itbl14scaleItSIG14[2];
		iConst60 = itbl15scaleItSIG15[2];
		iConst61 = itbl0scaleItSIG0[3];
		iConst62 = itbl1scaleItSIG1[3];
		iConst63 = itbl2scaleItSIG2[3];
		iConst64 = itbl3scaleItSIG3[3];
		iConst65 = itbl4scaleItSIG4[3];
		iConst66 = itbl5scaleItSIG5[3];
		iConst67 = itbl6scaleItSIG6[3];
		iConst68 = itbl7scaleItSIG7[3];
		iConst69 = itbl8scaleItSIG8[3];
		iConst70 = itbl9scaleItSIG9[3];
		iConst71 = itbl10scaleItSIG10[3];
		iConst72 = itbl11scaleItSIG11[3];
		iConst73 = itbl12scaleItSIG12[3];
		iConst74 = itbl13scaleItSIG13[3];
		iConst75 = itbl14scaleItSIG14[3];
		iConst76 = itbl15scaleItSIG15[3];
		iConst77 = itbl0scaleItSIG0[4];
		iConst78 = itbl1scaleItSIG1[4];
		iConst79 = itbl2scaleItSIG2[4];
		iConst80 = itbl3scaleItSIG3[4];
		iConst81 = itbl4scaleItSIG4[4];
		iConst82 = itbl5scaleItSIG5[4];
		iConst83 = itbl6scaleItSIG6[4];
		iConst84 = itbl7scaleItSIG7[4];
		iConst85 = itbl8scaleItSIG8[4];
		iConst86 = itbl9scaleItSIG9[4];
		iConst87 = itbl10scaleItSIG10[4];
		iConst88 = itbl11scaleItSIG11[4];
		iConst89 = itbl12scaleItSIG12[4];
		iConst90 = itbl13scaleItSIG13[4];
		iConst91 = itbl14scaleItSIG14[4];
		iConst92 = itbl15scaleItSIG15[4];
		iConst93 = itbl0scaleItSIG0[5];
		iConst94 = itbl1scaleItSIG1[5];
		iConst95 = itbl2scaleItSIG2[5];
		iConst96 = itbl3scaleItSIG3[5];
		iConst97 = itbl4scaleItSIG4[5];
		iConst98 = itbl5scaleItSIG5[5];
		iConst99 = itbl6scaleItSIG6[5];
		iConst100 = itbl7scaleItSIG7[5];
		iConst101 = itbl8scaleItSIG8[5];
		iConst102 = itbl9scaleItSIG9[5];
		iConst103 = itbl10scaleItSIG10[5];
		iConst104 = itbl11scaleItSIG11[5];
		iConst105 = itbl12scaleItSIG12[5];
		iConst106 = itbl13scaleItSIG13[5];
		iConst107 = itbl14scaleItSIG14[5];
		iConst108 = itbl15scaleItSIG15[5];
		iConst109 = itbl0scaleItSIG0[6];
		iConst110 = itbl1scaleItSIG1[6];
		iConst111 = itbl2scaleItSIG2[6];
		iConst112 = itbl3scaleItSIG3[6];
		iConst113 = itbl4scaleItSIG4[6];
		iConst114 = itbl5scaleItSIG5[6];
		iConst115 = itbl6scaleItSIG6[6];
		iConst116 = itbl7scaleItSIG7[6];
		iConst117 = itbl8scaleItSIG8[6];
		iConst118 = itbl9scaleItSIG9[6];
		iConst119 = itbl10scaleItSIG10[6];
		iConst120 = itbl11scaleItSIG11[6];
		iConst121 = itbl12scaleItSIG12[6];
		iConst122 = itbl13scaleItSIG13[6];
		iConst123 = itbl14scaleItSIG14[6];
		iConst124 = itbl15scaleItSIG15[6];
		iConst125 = itbl0scaleItSIG0[7];
		iConst126 = itbl1scaleItSIG1[7];
		iConst127 = itbl2scaleItSIG2[7];
		iConst128 = itbl3scaleItSIG3[7];
		iConst129 = itbl4scaleItSIG4[7];
		iConst130 = itbl5scaleItSIG5[7];
		iConst131 = itbl6scaleItSIG6[7];
		iConst132 = itbl7scaleItSIG7[7];
		iConst133 = itbl8scaleItSIG8[7];
		iConst134 = itbl9scaleItSIG9[7];
		iConst135 = itbl10scaleItSIG10[7];
		iConst136 = itbl11scaleItSIG11[7];
		iConst137 = itbl12scaleItSIG12[7];
		iConst138 = itbl13scaleItSIG13[7];
		iConst139 = itbl14scaleItSIG14[7];
		iConst140 = itbl15scaleItSIG15[7];
		iConst141 = itbl0scaleItSIG0[8];
		iConst142 = itbl1scaleItSIG1[8];
		iConst143 = itbl2scaleItSIG2[8];
		iConst144 = itbl3scaleItSIG3[8];
		iConst145 = itbl4scaleItSIG4[8];
		iConst146 = itbl5scaleItSIG5[8];
		iConst147 = itbl6scaleItSIG6[8];
		iConst148 = itbl7scaleItSIG7[8];
		iConst149 = itbl8scaleItSIG8[8];
		iConst150 = itbl9scaleItSIG9[8];
		iConst151 = itbl10scaleItSIG10[8];
		iConst152 = itbl11scaleItSIG11[8];
		iConst153 = itbl12scaleItSIG12[8];
		iConst154 = itbl13scaleItSIG13[8];
		iConst155 = itbl14scaleItSIG14[8];
		iConst156 = itbl15scaleItSIG15[8];
		iConst157 = itbl0scaleItSIG0[9];
		iConst158 = itbl1scaleItSIG1[9];
		iConst159 = itbl2scaleItSIG2[9];
		iConst160 = itbl3scaleItSIG3[9];
		iConst161 = itbl4scaleItSIG4[9];
		iConst162 = itbl5scaleItSIG5[9];
		iConst163 = itbl6scaleItSIG6[9];
		iConst164 = itbl7scaleItSIG7[9];
		iConst165 = itbl8scaleItSIG8[9];
		iConst166 = itbl9scaleItSIG9[9];
		iConst167 = itbl10scaleItSIG10[9];
		iConst168 = itbl11scaleItSIG11[9];
		iConst169 = itbl12scaleItSIG12[9];
		iConst170 = itbl13scaleItSIG13[9];
		iConst171 = itbl14scaleItSIG14[9];
		iConst172 = itbl15scaleItSIG15[9];
		iConst173 = itbl0scaleItSIG0[10];
		iConst174 = itbl1scaleItSIG1[10];
		iConst175 = itbl2scaleItSIG2[10];
		iConst176 = itbl3scaleItSIG3[10];
		iConst177 = itbl4scaleItSIG4[10];
		iConst178 = itbl5scaleItSIG5[10];
		iConst179 = itbl6scaleItSIG6[10];
		iConst180 = itbl7scaleItSIG7[10];
		iConst181 = itbl8scaleItSIG8[10];
		iConst182 = itbl9scaleItSIG9[10];
		iConst183 = itbl10scaleItSIG10[10];
		iConst184 = itbl11scaleItSIG11[10];
		iConst185 = itbl12scaleItSIG12[10];
		iConst186 = itbl13scaleItSIG13[10];
		iConst187 = itbl14scaleItSIG14[10];
		iConst188 = itbl15scaleItSIG15[10];
		iConst189 = itbl0scaleItSIG0[11];
		iConst190 = itbl1scaleItSIG1[11];
		iConst191 = itbl2scaleItSIG2[11];
		iConst192 = itbl3scaleItSIG3[11];
		iConst193 = itbl4scaleItSIG4[11];
		iConst194 = itbl5scaleItSIG5[11];
		iConst195 = itbl6scaleItSIG6[11];
		iConst196 = itbl7scaleItSIG7[11];
		iConst197 = itbl8scaleItSIG8[11];
		iConst198 = itbl9scaleItSIG9[11];
		iConst199 = itbl10scaleItSIG10[11];
		iConst200 = itbl11scaleItSIG11[11];
		iConst201 = itbl12scaleItSIG12[11];
		iConst202 = itbl13scaleItSIG13[11];
		iConst203 = itbl14scaleItSIG14[11];
		iConst204 = itbl15scaleItSIG15[11];
		fConst205 = std::exp(0.0 - 2e+01 / fConst0);
		fConst206 = 1.0 - fConst205;
		fConst207 = std::exp(0.0 - 1e+01 / fConst0);
		fConst208 = 1.0 - fConst207;
		fConst209 = std::exp(0.0 - 2.5e+03 / fConst0);
		fConst210 = 1.0 - fConst209;
		fConst211 = std::exp(0.0 - fConst1);
		fConst212 = std::exp(0.0 - 1.25e+03 / fConst0);
		fConst213 = 4.0 / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(1.0);
		fEntry1 = FAUSTFLOAT(1.0);
		fEntry2 = FAUSTFLOAT(0.0);
		fEntry3 = FAUSTFLOAT(0.5);
		fEntry4 = FAUSTFLOAT(8.0);
		fEntry5 = FAUSTFLOAT(0.0);
		fEntry6 = FAUSTFLOAT(0.0);
		fEntry7 = FAUSTFLOAT(1.0);
		fEntry8 = FAUSTFLOAT(0.0);
		fEntry9 = FAUSTFLOAT(0.5);
		fEntry10 = FAUSTFLOAT(69.0);
		fEntry11 = FAUSTFLOAT(0.0);
		fEntry12 = FAUSTFLOAT(0.0);
		fEntry13 = FAUSTFLOAT(0.0);
		fEntry14 = FAUSTFLOAT(0.5);
		fEntry15 = FAUSTFLOAT(0.0);
		fEntry16 = FAUSTFLOAT(64.0);
		fEntry17 = FAUSTFLOAT(0.5);
		fEntry18 = FAUSTFLOAT(0.0);
		fEntry19 = FAUSTFLOAT(0.5);
		fEntry20 = FAUSTFLOAT(0.0);
		fEntry21 = FAUSTFLOAT(0.5);
		fEntry22 = FAUSTFLOAT(0.0);
		fEntry23 = FAUSTFLOAT(0.5);
		fEntry24 = FAUSTFLOAT(0.0);
		fEntry25 = FAUSTFLOAT(0.5);
		fEntry26 = FAUSTFLOAT(0.0);
		fEntry27 = FAUSTFLOAT(0.5);
		fEntry28 = FAUSTFLOAT(0.0);
		fEntry29 = FAUSTFLOAT(0.5);
		fEntry30 = FAUSTFLOAT(0.0);
		fEntry31 = FAUSTFLOAT(0.5);
		fEntry32 = FAUSTFLOAT(0.0);
		fEntry33 = FAUSTFLOAT(0.5);
		fEntry34 = FAUSTFLOAT(0.0);
		fEntry35 = FAUSTFLOAT(0.5);
		fEntry36 = FAUSTFLOAT(0.0);
		fEntry37 = FAUSTFLOAT(0.5);
		fEntry38 = FAUSTFLOAT(0.0);
		fEntry39 = FAUSTFLOAT(0.0);
		fEntry40 = FAUSTFLOAT(0.0);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec0[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec1[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iRec3[l4] = 0;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec2[l5] = 0.0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec5[l8] = 0.0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec6[l9] = 0.0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec9[l10] = 0.0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fVec3[l11] = 0.0;
		}
		IOTA0 = 0;
		for (int l12 = 0; l12 < 4096; l12 = l12 + 1) {
			fVec4[l12] = 0.0;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec8[l13] = 0.0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			iVec5[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iRec10[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			iRec11[l16] = 0;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec12[l17] = 0.0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec13[l18] = 0.0;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec16[l19] = 0.0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fVec6[l20] = 0.0;
		}
		for (int l21 = 0; l21 < 4096; l21 = l21 + 1) {
			fVec7[l21] = 0.0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec15[l22] = 0.0;
		}
		for (int l23 = 0; l23 < 3; l23 = l23 + 1) {
			fRec17[l23] = 0.0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iVec8[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			iRec18[l25] = 0;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			iRec19[l26] = 0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec20[l27] = 0.0;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec21[l28] = 0.0;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec24[l29] = 0.0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fVec9[l30] = 0.0;
		}
		for (int l31 = 0; l31 < 4096; l31 = l31 + 1) {
			fVec10[l31] = 0.0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec23[l32] = 0.0;
		}
		for (int l33 = 0; l33 < 3; l33 = l33 + 1) {
			fRec25[l33] = 0.0;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			iVec11[l34] = 0;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			iRec26[l35] = 0;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			iRec27[l36] = 0;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec28[l37] = 0.0;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec29[l38] = 0.0;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec32[l39] = 0.0;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fVec12[l40] = 0.0;
		}
		for (int l41 = 0; l41 < 4096; l41 = l41 + 1) {
			fVec13[l41] = 0.0;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec31[l42] = 0.0;
		}
		for (int l43 = 0; l43 < 3; l43 = l43 + 1) {
			fRec33[l43] = 0.0;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			iVec14[l44] = 0;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			iRec34[l45] = 0;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			iRec35[l46] = 0;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec36[l47] = 0.0;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec37[l48] = 0.0;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec40[l49] = 0.0;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fVec15[l50] = 0.0;
		}
		for (int l51 = 0; l51 < 4096; l51 = l51 + 1) {
			fVec16[l51] = 0.0;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec39[l52] = 0.0;
		}
		for (int l53 = 0; l53 < 3; l53 = l53 + 1) {
			fRec41[l53] = 0.0;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			iVec17[l54] = 0;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			iRec42[l55] = 0;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			iRec43[l56] = 0;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec44[l57] = 0.0;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec45[l58] = 0.0;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec48[l59] = 0.0;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fVec18[l60] = 0.0;
		}
		for (int l61 = 0; l61 < 4096; l61 = l61 + 1) {
			fVec19[l61] = 0.0;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec47[l62] = 0.0;
		}
		for (int l63 = 0; l63 < 3; l63 = l63 + 1) {
			fRec49[l63] = 0.0;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			iVec20[l64] = 0;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			iRec50[l65] = 0;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			iRec51[l66] = 0;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec52[l67] = 0.0;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fRec53[l68] = 0.0;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			fRec56[l69] = 0.0;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fVec21[l70] = 0.0;
		}
		for (int l71 = 0; l71 < 4096; l71 = l71 + 1) {
			fVec22[l71] = 0.0;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec55[l72] = 0.0;
		}
		for (int l73 = 0; l73 < 3; l73 = l73 + 1) {
			fRec57[l73] = 0.0;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			iVec23[l74] = 0;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			iRec58[l75] = 0;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			iRec59[l76] = 0;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec60[l77] = 0.0;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec61[l78] = 0.0;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			fRec64[l79] = 0.0;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			fVec24[l80] = 0.0;
		}
		for (int l81 = 0; l81 < 4096; l81 = l81 + 1) {
			fVec25[l81] = 0.0;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			fRec63[l82] = 0.0;
		}
		for (int l83 = 0; l83 < 3; l83 = l83 + 1) {
			fRec65[l83] = 0.0;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			iVec26[l84] = 0;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			iRec66[l85] = 0;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			iRec67[l86] = 0;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fRec68[l87] = 0.0;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec69[l88] = 0.0;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			fRec72[l89] = 0.0;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			fVec27[l90] = 0.0;
		}
		for (int l91 = 0; l91 < 4096; l91 = l91 + 1) {
			fVec28[l91] = 0.0;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			fRec71[l92] = 0.0;
		}
		for (int l93 = 0; l93 < 3; l93 = l93 + 1) {
			fRec73[l93] = 0.0;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			iVec29[l94] = 0;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			iRec74[l95] = 0;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			iRec75[l96] = 0;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec76[l97] = 0.0;
		}
		for (int l98 = 0; l98 < 2; l98 = l98 + 1) {
			fRec77[l98] = 0.0;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			fRec80[l99] = 0.0;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			fVec30[l100] = 0.0;
		}
		for (int l101 = 0; l101 < 4096; l101 = l101 + 1) {
			fVec31[l101] = 0.0;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			fRec79[l102] = 0.0;
		}
		for (int l103 = 0; l103 < 3; l103 = l103 + 1) {
			fRec81[l103] = 0.0;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			iVec32[l104] = 0;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			iRec82[l105] = 0;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			iRec83[l106] = 0;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			fRec84[l107] = 0.0;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			fRec85[l108] = 0.0;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fRec88[l109] = 0.0;
		}
		for (int l110 = 0; l110 < 2; l110 = l110 + 1) {
			fVec33[l110] = 0.0;
		}
		for (int l111 = 0; l111 < 4096; l111 = l111 + 1) {
			fVec34[l111] = 0.0;
		}
		for (int l112 = 0; l112 < 2; l112 = l112 + 1) {
			fRec87[l112] = 0.0;
		}
		for (int l113 = 0; l113 < 3; l113 = l113 + 1) {
			fRec89[l113] = 0.0;
		}
		for (int l114 = 0; l114 < 2; l114 = l114 + 1) {
			iVec35[l114] = 0;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			iRec90[l115] = 0;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			iRec91[l116] = 0;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			fRec92[l117] = 0.0;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			fRec93[l118] = 0.0;
		}
		for (int l119 = 0; l119 < 2; l119 = l119 + 1) {
			fRec96[l119] = 0.0;
		}
		for (int l120 = 0; l120 < 2; l120 = l120 + 1) {
			fVec36[l120] = 0.0;
		}
		for (int l121 = 0; l121 < 4096; l121 = l121 + 1) {
			fVec37[l121] = 0.0;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			fRec95[l122] = 0.0;
		}
		for (int l123 = 0; l123 < 3; l123 = l123 + 1) {
			fRec97[l123] = 0.0;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			fRec99[l124] = 0.0;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fRec98[l125] = 0.0;
		}
		for (int l126 = 0; l126 < 2; l126 = l126 + 1) {
			fRec101[l126] = 0.0;
		}
		for (int l127 = 0; l127 < 2; l127 = l127 + 1) {
			fRec100[l127] = 0.0;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			iVec38[l128] = 0;
		}
		for (int l129 = 0; l129 < 2; l129 = l129 + 1) {
			iRec102[l129] = 0;
		}
		for (int l130 = 0; l130 < 2; l130 = l130 + 1) {
			iRec103[l130] = 0;
		}
		for (int l131 = 0; l131 < 2; l131 = l131 + 1) {
			fRec104[l131] = 0.0;
		}
		for (int l132 = 0; l132 < 2; l132 = l132 + 1) {
			fRec105[l132] = 0.0;
		}
		for (int l133 = 0; l133 < 2; l133 = l133 + 1) {
			fRec108[l133] = 0.0;
		}
		for (int l134 = 0; l134 < 2; l134 = l134 + 1) {
			fVec39[l134] = 0.0;
		}
		for (int l135 = 0; l135 < 4096; l135 = l135 + 1) {
			fVec40[l135] = 0.0;
		}
		for (int l136 = 0; l136 < 2; l136 = l136 + 1) {
			fRec107[l136] = 0.0;
		}
		for (int l137 = 0; l137 < 3; l137 = l137 + 1) {
			fRec109[l137] = 0.0;
		}
		for (int l138 = 0; l138 < 2; l138 = l138 + 1) {
			iVec41[l138] = 0;
		}
		for (int l139 = 0; l139 < 2; l139 = l139 + 1) {
			iRec110[l139] = 0;
		}
		for (int l140 = 0; l140 < 2; l140 = l140 + 1) {
			iRec111[l140] = 0;
		}
		for (int l141 = 0; l141 < 2; l141 = l141 + 1) {
			fRec112[l141] = 0.0;
		}
		for (int l142 = 0; l142 < 2; l142 = l142 + 1) {
			fRec113[l142] = 0.0;
		}
		for (int l143 = 0; l143 < 2; l143 = l143 + 1) {
			fRec116[l143] = 0.0;
		}
		for (int l144 = 0; l144 < 2; l144 = l144 + 1) {
			fVec42[l144] = 0.0;
		}
		for (int l145 = 0; l145 < 4096; l145 = l145 + 1) {
			fVec43[l145] = 0.0;
		}
		for (int l146 = 0; l146 < 2; l146 = l146 + 1) {
			fRec115[l146] = 0.0;
		}
		for (int l147 = 0; l147 < 3; l147 = l147 + 1) {
			fRec117[l147] = 0.0;
		}
		for (int l148 = 0; l148 < 2; l148 = l148 + 1) {
			iVec44[l148] = 0;
		}
		for (int l149 = 0; l149 < 2; l149 = l149 + 1) {
			iRec118[l149] = 0;
		}
		for (int l150 = 0; l150 < 2; l150 = l150 + 1) {
			iRec119[l150] = 0;
		}
		for (int l151 = 0; l151 < 2; l151 = l151 + 1) {
			fRec120[l151] = 0.0;
		}
		for (int l152 = 0; l152 < 2; l152 = l152 + 1) {
			fRec121[l152] = 0.0;
		}
		for (int l153 = 0; l153 < 2; l153 = l153 + 1) {
			fRec124[l153] = 0.0;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			fVec45[l154] = 0.0;
		}
		for (int l155 = 0; l155 < 4096; l155 = l155 + 1) {
			fVec46[l155] = 0.0;
		}
		for (int l156 = 0; l156 < 2; l156 = l156 + 1) {
			fRec123[l156] = 0.0;
		}
		for (int l157 = 0; l157 < 3; l157 = l157 + 1) {
			fRec125[l157] = 0.0;
		}
		for (int l158 = 0; l158 < 2; l158 = l158 + 1) {
			iVec47[l158] = 0;
		}
		for (int l159 = 0; l159 < 2; l159 = l159 + 1) {
			iRec126[l159] = 0;
		}
		for (int l160 = 0; l160 < 2; l160 = l160 + 1) {
			iRec127[l160] = 0;
		}
		for (int l161 = 0; l161 < 2; l161 = l161 + 1) {
			fRec128[l161] = 0.0;
		}
		for (int l162 = 0; l162 < 2; l162 = l162 + 1) {
			fRec129[l162] = 0.0;
		}
		for (int l163 = 0; l163 < 2; l163 = l163 + 1) {
			fRec132[l163] = 0.0;
		}
		for (int l164 = 0; l164 < 2; l164 = l164 + 1) {
			fVec48[l164] = 0.0;
		}
		for (int l165 = 0; l165 < 4096; l165 = l165 + 1) {
			fVec49[l165] = 0.0;
		}
		for (int l166 = 0; l166 < 2; l166 = l166 + 1) {
			fRec131[l166] = 0.0;
		}
		for (int l167 = 0; l167 < 3; l167 = l167 + 1) {
			fRec133[l167] = 0.0;
		}
		for (int l168 = 0; l168 < 2; l168 = l168 + 1) {
			iVec50[l168] = 0;
		}
		for (int l169 = 0; l169 < 2; l169 = l169 + 1) {
			iRec134[l169] = 0;
		}
		for (int l170 = 0; l170 < 2; l170 = l170 + 1) {
			iRec135[l170] = 0;
		}
		for (int l171 = 0; l171 < 2; l171 = l171 + 1) {
			fRec136[l171] = 0.0;
		}
		for (int l172 = 0; l172 < 2; l172 = l172 + 1) {
			fRec137[l172] = 0.0;
		}
		for (int l173 = 0; l173 < 2; l173 = l173 + 1) {
			fRec140[l173] = 0.0;
		}
		for (int l174 = 0; l174 < 2; l174 = l174 + 1) {
			fVec51[l174] = 0.0;
		}
		for (int l175 = 0; l175 < 4096; l175 = l175 + 1) {
			fVec52[l175] = 0.0;
		}
		for (int l176 = 0; l176 < 2; l176 = l176 + 1) {
			fRec139[l176] = 0.0;
		}
		for (int l177 = 0; l177 < 3; l177 = l177 + 1) {
			fRec141[l177] = 0.0;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			iVec53[l178] = 0;
		}
		for (int l179 = 0; l179 < 2; l179 = l179 + 1) {
			iRec142[l179] = 0;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			iRec143[l180] = 0;
		}
		for (int l181 = 0; l181 < 2; l181 = l181 + 1) {
			fRec144[l181] = 0.0;
		}
		for (int l182 = 0; l182 < 2; l182 = l182 + 1) {
			fRec145[l182] = 0.0;
		}
		for (int l183 = 0; l183 < 2; l183 = l183 + 1) {
			fRec148[l183] = 0.0;
		}
		for (int l184 = 0; l184 < 2; l184 = l184 + 1) {
			fVec54[l184] = 0.0;
		}
		for (int l185 = 0; l185 < 4096; l185 = l185 + 1) {
			fVec55[l185] = 0.0;
		}
		for (int l186 = 0; l186 < 2; l186 = l186 + 1) {
			fRec147[l186] = 0.0;
		}
		for (int l187 = 0; l187 < 3; l187 = l187 + 1) {
			fRec149[l187] = 0.0;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			fRec151[l188] = 0.0;
		}
		for (int l189 = 0; l189 < 2; l189 = l189 + 1) {
			fRec150[l189] = 0.0;
		}
		for (int l190 = 0; l190 < 2; l190 = l190 + 1) {
			fRec153[l190] = 0.0;
		}
		for (int l191 = 0; l191 < 2; l191 = l191 + 1) {
			fRec152[l191] = 0.0;
		}
		for (int l192 = 0; l192 < 2; l192 = l192 + 1) {
			fRec155[l192] = 0.0;
		}
		for (int l193 = 0; l193 < 2; l193 = l193 + 1) {
			fRec154[l193] = 0.0;
		}
		for (int l194 = 0; l194 < 2; l194 = l194 + 1) {
			fRec157[l194] = 0.0;
		}
		for (int l195 = 0; l195 < 2; l195 = l195 + 1) {
			fRec156[l195] = 0.0;
		}
		for (int l196 = 0; l196 < 2; l196 = l196 + 1) {
			iVec56[l196] = 0;
		}
		for (int l197 = 0; l197 < 2; l197 = l197 + 1) {
			iRec158[l197] = 0;
		}
		for (int l198 = 0; l198 < 2; l198 = l198 + 1) {
			iRec159[l198] = 0;
		}
		for (int l199 = 0; l199 < 2; l199 = l199 + 1) {
			fRec160[l199] = 0.0;
		}
		for (int l200 = 0; l200 < 2; l200 = l200 + 1) {
			fRec161[l200] = 0.0;
		}
		for (int l201 = 0; l201 < 2; l201 = l201 + 1) {
			fRec164[l201] = 0.0;
		}
		for (int l202 = 0; l202 < 2; l202 = l202 + 1) {
			fVec57[l202] = 0.0;
		}
		for (int l203 = 0; l203 < 4096; l203 = l203 + 1) {
			fVec58[l203] = 0.0;
		}
		for (int l204 = 0; l204 < 2; l204 = l204 + 1) {
			fRec163[l204] = 0.0;
		}
		for (int l205 = 0; l205 < 3; l205 = l205 + 1) {
			fRec165[l205] = 0.0;
		}
		for (int l206 = 0; l206 < 2; l206 = l206 + 1) {
			iVec59[l206] = 0;
		}
		for (int l207 = 0; l207 < 2; l207 = l207 + 1) {
			iRec166[l207] = 0;
		}
		for (int l208 = 0; l208 < 2; l208 = l208 + 1) {
			iRec167[l208] = 0;
		}
		for (int l209 = 0; l209 < 2; l209 = l209 + 1) {
			fRec168[l209] = 0.0;
		}
		for (int l210 = 0; l210 < 2; l210 = l210 + 1) {
			fRec169[l210] = 0.0;
		}
		for (int l211 = 0; l211 < 2; l211 = l211 + 1) {
			fRec172[l211] = 0.0;
		}
		for (int l212 = 0; l212 < 2; l212 = l212 + 1) {
			fVec60[l212] = 0.0;
		}
		for (int l213 = 0; l213 < 4096; l213 = l213 + 1) {
			fVec61[l213] = 0.0;
		}
		for (int l214 = 0; l214 < 2; l214 = l214 + 1) {
			fRec171[l214] = 0.0;
		}
		for (int l215 = 0; l215 < 3; l215 = l215 + 1) {
			fRec173[l215] = 0.0;
		}
		for (int l216 = 0; l216 < 2; l216 = l216 + 1) {
			iVec62[l216] = 0;
		}
		for (int l217 = 0; l217 < 2; l217 = l217 + 1) {
			iRec174[l217] = 0;
		}
		for (int l218 = 0; l218 < 2; l218 = l218 + 1) {
			iRec175[l218] = 0;
		}
		for (int l219 = 0; l219 < 2; l219 = l219 + 1) {
			fRec176[l219] = 0.0;
		}
		for (int l220 = 0; l220 < 2; l220 = l220 + 1) {
			fRec177[l220] = 0.0;
		}
		for (int l221 = 0; l221 < 2; l221 = l221 + 1) {
			fRec180[l221] = 0.0;
		}
		for (int l222 = 0; l222 < 2; l222 = l222 + 1) {
			fVec63[l222] = 0.0;
		}
		for (int l223 = 0; l223 < 4096; l223 = l223 + 1) {
			fVec64[l223] = 0.0;
		}
		for (int l224 = 0; l224 < 2; l224 = l224 + 1) {
			fRec179[l224] = 0.0;
		}
		for (int l225 = 0; l225 < 3; l225 = l225 + 1) {
			fRec181[l225] = 0.0;
		}
		for (int l226 = 0; l226 < 2; l226 = l226 + 1) {
			iVec65[l226] = 0;
		}
		for (int l227 = 0; l227 < 2; l227 = l227 + 1) {
			iRec182[l227] = 0;
		}
		for (int l228 = 0; l228 < 2; l228 = l228 + 1) {
			iRec183[l228] = 0;
		}
		for (int l229 = 0; l229 < 2; l229 = l229 + 1) {
			fRec184[l229] = 0.0;
		}
		for (int l230 = 0; l230 < 2; l230 = l230 + 1) {
			fRec185[l230] = 0.0;
		}
		for (int l231 = 0; l231 < 2; l231 = l231 + 1) {
			fRec188[l231] = 0.0;
		}
		for (int l232 = 0; l232 < 2; l232 = l232 + 1) {
			fVec66[l232] = 0.0;
		}
		for (int l233 = 0; l233 < 4096; l233 = l233 + 1) {
			fVec67[l233] = 0.0;
		}
		for (int l234 = 0; l234 < 2; l234 = l234 + 1) {
			fRec187[l234] = 0.0;
		}
		for (int l235 = 0; l235 < 3; l235 = l235 + 1) {
			fRec189[l235] = 0.0;
		}
		for (int l236 = 0; l236 < 2; l236 = l236 + 1) {
			iVec68[l236] = 0;
		}
		for (int l237 = 0; l237 < 2; l237 = l237 + 1) {
			iRec190[l237] = 0;
		}
		for (int l238 = 0; l238 < 2; l238 = l238 + 1) {
			iRec191[l238] = 0;
		}
		for (int l239 = 0; l239 < 2; l239 = l239 + 1) {
			fRec192[l239] = 0.0;
		}
		for (int l240 = 0; l240 < 2; l240 = l240 + 1) {
			fRec193[l240] = 0.0;
		}
		for (int l241 = 0; l241 < 2; l241 = l241 + 1) {
			fRec196[l241] = 0.0;
		}
		for (int l242 = 0; l242 < 2; l242 = l242 + 1) {
			fVec69[l242] = 0.0;
		}
		for (int l243 = 0; l243 < 4096; l243 = l243 + 1) {
			fVec70[l243] = 0.0;
		}
		for (int l244 = 0; l244 < 2; l244 = l244 + 1) {
			fRec195[l244] = 0.0;
		}
		for (int l245 = 0; l245 < 3; l245 = l245 + 1) {
			fRec197[l245] = 0.0;
		}
		for (int l246 = 0; l246 < 2; l246 = l246 + 1) {
			iVec71[l246] = 0;
		}
		for (int l247 = 0; l247 < 2; l247 = l247 + 1) {
			iRec198[l247] = 0;
		}
		for (int l248 = 0; l248 < 2; l248 = l248 + 1) {
			iRec199[l248] = 0;
		}
		for (int l249 = 0; l249 < 2; l249 = l249 + 1) {
			fRec200[l249] = 0.0;
		}
		for (int l250 = 0; l250 < 2; l250 = l250 + 1) {
			fRec201[l250] = 0.0;
		}
		for (int l251 = 0; l251 < 2; l251 = l251 + 1) {
			fRec204[l251] = 0.0;
		}
		for (int l252 = 0; l252 < 2; l252 = l252 + 1) {
			fVec72[l252] = 0.0;
		}
		for (int l253 = 0; l253 < 4096; l253 = l253 + 1) {
			fVec73[l253] = 0.0;
		}
		for (int l254 = 0; l254 < 2; l254 = l254 + 1) {
			fRec203[l254] = 0.0;
		}
		for (int l255 = 0; l255 < 3; l255 = l255 + 1) {
			fRec205[l255] = 0.0;
		}
		for (int l256 = 0; l256 < 2; l256 = l256 + 1) {
			fRec207[l256] = 0.0;
		}
		for (int l257 = 0; l257 < 2; l257 = l257 + 1) {
			fRec206[l257] = 0.0;
		}
		for (int l258 = 0; l258 < 2; l258 = l258 + 1) {
			fRec209[l258] = 0.0;
		}
		for (int l259 = 0; l259 < 2; l259 = l259 + 1) {
			fRec208[l259] = 0.0;
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
		ui_interface->addHorizontalBargraph("Threshold:", &fHbargraph0, FAUSTFLOAT(0.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("accordPan0", &fEntry14, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan1", &fEntry17, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan10", &fEntry35, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan11", &fEntry37, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan2", &fEntry19, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan3", &fEntry21, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan4", &fEntry23, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan5", &fEntry25, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan6", &fEntry27, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan7", &fEntry29, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan8", &fEntry31, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("accordPan9", &fEntry33, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("activeSteps", &fEntry4, FAUSTFLOAT(8.0), FAUSTFLOAT(0.0), FAUSTFLOAT(12.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("baseKeyMIDI", &fEntry10, FAUSTFLOAT(69.0), FAUSTFLOAT(0.0), FAUSTFLOAT(128.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("curve", &fEntry6, FAUSTFLOAT(0.0), FAUSTFLOAT(-1e+01), FAUSTFLOAT(1e+01), FAUSTFLOAT(0.01));
		ui_interface->addNumEntry("customScale0", &fEntry12, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale1", &fEntry18, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale10", &fEntry36, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale11", &fEntry38, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale2", &fEntry20, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale3", &fEntry22, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale4", &fEntry24, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale5", &fEntry26, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale6", &fEntry28, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale7", &fEntry30, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale8", &fEntry32, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("customScale9", &fEntry34, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(48.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("envAttack", &fEntry3, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("envDecay", &fEntry8, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("envRelease", &fEntry9, FAUSTFLOAT(0.5), FAUSTFLOAT(0.0), FAUSTFLOAT(5.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("envSustain", &fEntry7, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(0.05));
		ui_interface->addNumEntry("gameAccordON", &fEntry2, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("gameToneON", &fEntry39, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("invert", &fEntry5, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("noiseLevel", &fEntry13, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(127.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("oscType", &fEntry15, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(4.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("playAbove", &fEntry1, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("playBelow", &fEntry0, FAUSTFLOAT(1.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("scale", &fEntry11, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(15.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("scaleDown", &fEntry40, FAUSTFLOAT(0.0), FAUSTFLOAT(0.0), FAUSTFLOAT(1.0), FAUSTFLOAT(1.0));
		ui_interface->addNumEntry("synthLevel", &fEntry16, FAUSTFLOAT(64.0), FAUSTFLOAT(0.0), FAUSTFLOAT(127.0), FAUSTFLOAT(1.0));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		int iSlow0 = double(fEntry0) == 0.0;
		int iSlow1 = double(fEntry1) == 0.0;
		double fSlow2 = 0.5 * double(fEntry2);
		double fSlow3 = std::max<double>(1.0, fConst0 * double(fEntry3));
		double fSlow4 = 1.0 / fSlow3;
		double fSlow5 = double(fEntry4);
		int iSlow6 = 1.0 <= fSlow5;
		double fSlow7 = double(fEntry5);
		int iSlow8 = fSlow7 == 0.0;
		double fSlow9 = std::pow(2.0, double(fEntry6));
		double fSlow10 = std::pow(0.0, fSlow9);
		int iSlow11 = int(fSlow7);
		int iSlow12 = (2.0 == fSlow5) & iSlow11;
		double fSlow13 = 1.0 / fSlow5;
		double fSlow14 = std::pow(fSlow13, fSlow9);
		int iSlow15 = (3.0 == fSlow5) & iSlow11;
		double fSlow16 = std::pow(2.0 / fSlow5, fSlow9);
		int iSlow17 = (4.0 == fSlow5) & iSlow11;
		double fSlow18 = std::pow(3.0 / fSlow5, fSlow9);
		int iSlow19 = (5.0 == fSlow5) & iSlow11;
		double fSlow20 = std::pow(4.0 / fSlow5, fSlow9);
		int iSlow21 = (6.0 == fSlow5) & iSlow11;
		double fSlow22 = std::pow(5.0 / fSlow5, fSlow9);
		int iSlow23 = (7.0 == fSlow5) & iSlow11;
		double fSlow24 = std::pow(6.0 / fSlow5, fSlow9);
		int iSlow25 = (8.0 == fSlow5) & iSlow11;
		double fSlow26 = std::pow(7.0 / fSlow5, fSlow9);
		int iSlow27 = (9.0 == fSlow5) & iSlow11;
		double fSlow28 = std::pow(8.0 / fSlow5, fSlow9);
		int iSlow29 = (1e+01 == fSlow5) & iSlow11;
		double fSlow30 = std::pow(9.0 / fSlow5, fSlow9);
		int iSlow31 = (11.0 == fSlow5) & iSlow11;
		double fSlow32 = std::pow(1e+01 / fSlow5, fSlow9);
		int iSlow33 = (12.0 == fSlow5) & iSlow11;
		double fSlow34 = std::pow(11.0 / fSlow5, fSlow9);
		double fSlow35 = double(fEntry7);
		double fSlow36 = (1.0 - fSlow35) / std::max<double>(1.0, fConst0 * double(fEntry8));
		double fSlow37 = 1.0 / std::max<double>(1.0, fConst0 * double(fEntry9));
		double fSlow38 = double(fEntry10);
		double fSlow39 = double(fEntry11);
		int iSlow40 = fSlow39 < 16.0;
		int iSlow41 = (fSlow39 == 0.0) & iSlow40;
		int iSlow42 = (fSlow39 == 1.0) & iSlow40;
		int iSlow43 = (fSlow39 == 2.0) & iSlow40;
		int iSlow44 = (fSlow39 == 3.0) & iSlow40;
		int iSlow45 = (fSlow39 == 4.0) & iSlow40;
		int iSlow46 = (fSlow39 == 5.0) & iSlow40;
		int iSlow47 = (fSlow39 == 6.0) & iSlow40;
		int iSlow48 = (fSlow39 == 7.0) & iSlow40;
		int iSlow49 = (fSlow39 == 8.0) & iSlow40;
		int iSlow50 = (fSlow39 == 9.0) & iSlow40;
		int iSlow51 = (fSlow39 == 1e+01) & iSlow40;
		int iSlow52 = (fSlow39 == 11.0) & iSlow40;
		int iSlow53 = (fSlow39 == 12.0) & iSlow40;
		int iSlow54 = (fSlow39 == 13.0) & iSlow40;
		int iSlow55 = (fSlow39 == 14.0) & iSlow40;
		int iSlow56 = (fSlow39 == 15.0) & iSlow40;
		int iSlow57 = fSlow39 == 16.0;
		double fSlow58 = double(((iSlow41) ? iConst7 : 0) + ((iSlow42) ? iConst8 : 0) + ((iSlow43) ? iConst9 : 0) + ((iSlow44) ? iConst10 : 0) + ((iSlow45) ? iConst11 : 0) + ((iSlow46) ? iConst12 : 0) + ((iSlow47) ? iConst13 : 0) + ((iSlow48) ? iConst14 : 0) + ((iSlow49) ? iConst15 : 0) + ((iSlow50) ? iConst16 : 0) + ((iSlow51) ? iConst17 : 0) + ((iSlow52) ? iConst18 : 0) + ((iSlow53) ? iConst19 : 0) + ((iSlow54) ? iConst20 : 0) + ((iSlow55) ? iConst21 : 0) + ((iSlow56) ? iConst22 : 0)) + ((iSlow57) ? double(fEntry12) : 0.0);
		double fSlow59 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow58 + -69.0));
		double fSlow60 = 4.4e+02 * fSlow59;
		double fSlow61 = ((fSlow60 == 0.0) ? 1e+02 : fSlow60);
		double fSlow62 = std::tan(fConst6 * double(int(fSlow61 + 1e+01)));
		double fSlow63 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow61))) * fSlow62));
		double fSlow64 = fConst4 * fSlow63 + -8.0;
		double fSlow65 = fConst3 * fSlow63;
		double fSlow66 = fConst23 * fSlow62 - fConst24 * (fSlow63 / fSlow62);
		double fSlow67 = fConst1 * fSlow66;
		double fSlow68 = fSlow65 + (4.0 - fSlow67);
		double fSlow69 = fSlow65 + fSlow67 + 4.0;
		double fSlow70 = 0.0 - fConst1 * (fSlow66 / fSlow69);
		int iSlow71 = int(double(fEntry13));
		double fSlow72 = ((iSlow71 == 0) ? 0.0 : 0.007874015748031496 * double(iSlow71));
		double fSlow73 = double(fEntry14);
		double fSlow74 = 1.0 - fSlow73;
		double fSlow75 = double(fEntry15);
		int iSlow76 = fSlow75 == 0.0;
		double fSlow77 = fConst25 * fSlow59;
		int iSlow78 = fSlow75 == 1.0;
		double fSlow79 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow60));
		double fSlow80 = fConst2 * fSlow79;
		double fSlow81 = 1.0 - fConst0 / fSlow79;
		int iSlow82 = fSlow75 == 2.0;
		double fSlow83 = std::max<double>(fSlow60, 23.44894968246214);
		double fSlow84 = std::max<double>(2e+01, std::fabs(fSlow83));
		double fSlow85 = fConst2 * fSlow84;
		double fSlow86 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow83));
		int iSlow87 = int(fSlow86);
		double fSlow88 = std::floor(fSlow86);
		double fSlow89 = fSlow88 + (1.0 - fSlow86);
		double fSlow90 = fSlow86 - fSlow88;
		int iSlow91 = iSlow87 + 1;
		int iSlow92 = fSlow75 == 3.0;
		int iSlow93 = int(double(fEntry16));
		double fSlow94 = ((iSlow93 == 0) ? 0.0 : 0.007874015748031496 * double(iSlow93));
		double fSlow95 = double(fEntry17);
		double fSlow96 = 1.0 - fSlow95;
		int iSlow97 = 2.0 <= fSlow5;
		double fSlow98 = double(((iSlow41) ? iConst29 : 0) + ((iSlow42) ? iConst30 : 0) + ((iSlow43) ? iConst31 : 0) + ((iSlow44) ? iConst32 : 0) + ((iSlow45) ? iConst33 : 0) + ((iSlow46) ? iConst34 : 0) + ((iSlow47) ? iConst35 : 0) + ((iSlow48) ? iConst36 : 0) + ((iSlow49) ? iConst37 : 0) + ((iSlow50) ? iConst38 : 0) + ((iSlow51) ? iConst39 : 0) + ((iSlow52) ? iConst40 : 0) + ((iSlow53) ? iConst41 : 0) + ((iSlow54) ? iConst42 : 0) + ((iSlow55) ? iConst43 : 0) + ((iSlow56) ? iConst44 : 0)) + ((iSlow57) ? double(fEntry18) : 0.0);
		double fSlow99 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow98 + -69.0));
		double fSlow100 = fConst25 * fSlow99;
		double fSlow101 = 4.4e+02 * fSlow99;
		double fSlow102 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow101));
		double fSlow103 = fConst2 * fSlow102;
		double fSlow104 = 1.0 - fConst0 / fSlow102;
		double fSlow105 = std::max<double>(fSlow101, 23.44894968246214);
		double fSlow106 = std::max<double>(2e+01, std::fabs(fSlow105));
		double fSlow107 = fConst2 * fSlow106;
		double fSlow108 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow105));
		int iSlow109 = int(fSlow108);
		double fSlow110 = std::floor(fSlow108);
		double fSlow111 = fSlow110 + (1.0 - fSlow108);
		double fSlow112 = fSlow108 - fSlow110;
		int iSlow113 = iSlow109 + 1;
		double fSlow114 = ((fSlow101 == 0.0) ? 1e+02 : fSlow101);
		double fSlow115 = std::tan(fConst6 * double(int(fSlow114 + 1e+01)));
		double fSlow116 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow114))) * fSlow115));
		double fSlow117 = fConst4 * fSlow116 + -8.0;
		double fSlow118 = fConst3 * fSlow116;
		double fSlow119 = fConst23 * fSlow115 - fConst24 * (fSlow116 / fSlow115);
		double fSlow120 = fConst1 * fSlow119;
		double fSlow121 = fSlow118 + (4.0 - fSlow120);
		double fSlow122 = fSlow118 + fSlow120 + 4.0;
		double fSlow123 = 0.0 - fConst1 * (fSlow119 / fSlow122);
		double fSlow124 = double(fEntry19);
		double fSlow125 = 1.0 - fSlow124;
		int iSlow126 = 3.0 <= fSlow5;
		double fSlow127 = double(((iSlow41) ? iConst45 : 0) + ((iSlow42) ? iConst46 : 0) + ((iSlow43) ? iConst47 : 0) + ((iSlow44) ? iConst48 : 0) + ((iSlow45) ? iConst49 : 0) + ((iSlow46) ? iConst50 : 0) + ((iSlow47) ? iConst51 : 0) + ((iSlow48) ? iConst52 : 0) + ((iSlow49) ? iConst53 : 0) + ((iSlow50) ? iConst54 : 0) + ((iSlow51) ? iConst55 : 0) + ((iSlow52) ? iConst56 : 0) + ((iSlow53) ? iConst57 : 0) + ((iSlow54) ? iConst58 : 0) + ((iSlow55) ? iConst59 : 0) + ((iSlow56) ? iConst60 : 0)) + ((iSlow57) ? double(fEntry20) : 0.0);
		double fSlow128 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow127 + -69.0));
		double fSlow129 = fConst25 * fSlow128;
		double fSlow130 = 4.4e+02 * fSlow128;
		double fSlow131 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow130));
		double fSlow132 = fConst2 * fSlow131;
		double fSlow133 = 1.0 - fConst0 / fSlow131;
		double fSlow134 = std::max<double>(fSlow130, 23.44894968246214);
		double fSlow135 = std::max<double>(2e+01, std::fabs(fSlow134));
		double fSlow136 = fConst2 * fSlow135;
		double fSlow137 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow134));
		int iSlow138 = int(fSlow137);
		double fSlow139 = std::floor(fSlow137);
		double fSlow140 = fSlow139 + (1.0 - fSlow137);
		double fSlow141 = fSlow137 - fSlow139;
		int iSlow142 = iSlow138 + 1;
		double fSlow143 = ((fSlow130 == 0.0) ? 1e+02 : fSlow130);
		double fSlow144 = std::tan(fConst6 * double(int(fSlow143 + 1e+01)));
		double fSlow145 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow143))) * fSlow144));
		double fSlow146 = fConst4 * fSlow145 + -8.0;
		double fSlow147 = fConst3 * fSlow145;
		double fSlow148 = fConst23 * fSlow144 - fConst24 * (fSlow145 / fSlow144);
		double fSlow149 = fConst1 * fSlow148;
		double fSlow150 = fSlow147 + (4.0 - fSlow149);
		double fSlow151 = fSlow147 + fSlow149 + 4.0;
		double fSlow152 = 0.0 - fConst1 * (fSlow148 / fSlow151);
		double fSlow153 = double(fEntry21);
		double fSlow154 = 1.0 - fSlow153;
		int iSlow155 = 4.0 <= fSlow5;
		double fSlow156 = double(((iSlow41) ? iConst61 : 0) + ((iSlow42) ? iConst62 : 0) + ((iSlow43) ? iConst63 : 0) + ((iSlow44) ? iConst64 : 0) + ((iSlow45) ? iConst65 : 0) + ((iSlow46) ? iConst66 : 0) + ((iSlow47) ? iConst67 : 0) + ((iSlow48) ? iConst68 : 0) + ((iSlow49) ? iConst69 : 0) + ((iSlow50) ? iConst70 : 0) + ((iSlow51) ? iConst71 : 0) + ((iSlow52) ? iConst72 : 0) + ((iSlow53) ? iConst73 : 0) + ((iSlow54) ? iConst74 : 0) + ((iSlow55) ? iConst75 : 0) + ((iSlow56) ? iConst76 : 0)) + ((iSlow57) ? double(fEntry22) : 0.0);
		double fSlow157 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow156 + -69.0));
		double fSlow158 = fConst25 * fSlow157;
		double fSlow159 = 4.4e+02 * fSlow157;
		double fSlow160 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow159));
		double fSlow161 = fConst2 * fSlow160;
		double fSlow162 = 1.0 - fConst0 / fSlow160;
		double fSlow163 = std::max<double>(fSlow159, 23.44894968246214);
		double fSlow164 = std::max<double>(2e+01, std::fabs(fSlow163));
		double fSlow165 = fConst2 * fSlow164;
		double fSlow166 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow163));
		int iSlow167 = int(fSlow166);
		double fSlow168 = std::floor(fSlow166);
		double fSlow169 = fSlow168 + (1.0 - fSlow166);
		double fSlow170 = fSlow166 - fSlow168;
		int iSlow171 = iSlow167 + 1;
		double fSlow172 = ((fSlow159 == 0.0) ? 1e+02 : fSlow159);
		double fSlow173 = std::tan(fConst6 * double(int(fSlow172 + 1e+01)));
		double fSlow174 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow172))) * fSlow173));
		double fSlow175 = fConst4 * fSlow174 + -8.0;
		double fSlow176 = fConst3 * fSlow174;
		double fSlow177 = fConst23 * fSlow173 - fConst24 * (fSlow174 / fSlow173);
		double fSlow178 = fConst1 * fSlow177;
		double fSlow179 = fSlow176 + (4.0 - fSlow178);
		double fSlow180 = fSlow176 + fSlow178 + 4.0;
		double fSlow181 = 0.0 - fConst1 * (fSlow177 / fSlow180);
		double fSlow182 = double(fEntry23);
		double fSlow183 = 1.0 - fSlow182;
		int iSlow184 = 5.0 <= fSlow5;
		double fSlow185 = double(((iSlow41) ? iConst77 : 0) + ((iSlow42) ? iConst78 : 0) + ((iSlow43) ? iConst79 : 0) + ((iSlow44) ? iConst80 : 0) + ((iSlow45) ? iConst81 : 0) + ((iSlow46) ? iConst82 : 0) + ((iSlow47) ? iConst83 : 0) + ((iSlow48) ? iConst84 : 0) + ((iSlow49) ? iConst85 : 0) + ((iSlow50) ? iConst86 : 0) + ((iSlow51) ? iConst87 : 0) + ((iSlow52) ? iConst88 : 0) + ((iSlow53) ? iConst89 : 0) + ((iSlow54) ? iConst90 : 0) + ((iSlow55) ? iConst91 : 0) + ((iSlow56) ? iConst92 : 0)) + ((iSlow57) ? double(fEntry24) : 0.0);
		double fSlow186 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow185 + -69.0));
		double fSlow187 = fConst25 * fSlow186;
		double fSlow188 = 4.4e+02 * fSlow186;
		double fSlow189 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow188));
		double fSlow190 = fConst2 * fSlow189;
		double fSlow191 = 1.0 - fConst0 / fSlow189;
		double fSlow192 = std::max<double>(fSlow188, 23.44894968246214);
		double fSlow193 = std::max<double>(2e+01, std::fabs(fSlow192));
		double fSlow194 = fConst2 * fSlow193;
		double fSlow195 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow192));
		int iSlow196 = int(fSlow195);
		double fSlow197 = std::floor(fSlow195);
		double fSlow198 = fSlow197 + (1.0 - fSlow195);
		double fSlow199 = fSlow195 - fSlow197;
		int iSlow200 = iSlow196 + 1;
		double fSlow201 = ((fSlow188 == 0.0) ? 1e+02 : fSlow188);
		double fSlow202 = std::tan(fConst6 * double(int(fSlow201 + 1e+01)));
		double fSlow203 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow201))) * fSlow202));
		double fSlow204 = fConst4 * fSlow203 + -8.0;
		double fSlow205 = fConst3 * fSlow203;
		double fSlow206 = fConst23 * fSlow202 - fConst24 * (fSlow203 / fSlow202);
		double fSlow207 = fConst1 * fSlow206;
		double fSlow208 = fSlow205 + (4.0 - fSlow207);
		double fSlow209 = fSlow205 + fSlow207 + 4.0;
		double fSlow210 = 0.0 - fConst1 * (fSlow206 / fSlow209);
		double fSlow211 = double(fEntry25);
		double fSlow212 = 1.0 - fSlow211;
		int iSlow213 = 6.0 <= fSlow5;
		double fSlow214 = double(((iSlow41) ? iConst93 : 0) + ((iSlow42) ? iConst94 : 0) + ((iSlow43) ? iConst95 : 0) + ((iSlow44) ? iConst96 : 0) + ((iSlow45) ? iConst97 : 0) + ((iSlow46) ? iConst98 : 0) + ((iSlow47) ? iConst99 : 0) + ((iSlow48) ? iConst100 : 0) + ((iSlow49) ? iConst101 : 0) + ((iSlow50) ? iConst102 : 0) + ((iSlow51) ? iConst103 : 0) + ((iSlow52) ? iConst104 : 0) + ((iSlow53) ? iConst105 : 0) + ((iSlow54) ? iConst106 : 0) + ((iSlow55) ? iConst107 : 0) + ((iSlow56) ? iConst108 : 0)) + ((iSlow57) ? double(fEntry26) : 0.0);
		double fSlow215 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow214 + -69.0));
		double fSlow216 = fConst25 * fSlow215;
		double fSlow217 = 4.4e+02 * fSlow215;
		double fSlow218 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow217));
		double fSlow219 = fConst2 * fSlow218;
		double fSlow220 = 1.0 - fConst0 / fSlow218;
		double fSlow221 = std::max<double>(fSlow217, 23.44894968246214);
		double fSlow222 = std::max<double>(2e+01, std::fabs(fSlow221));
		double fSlow223 = fConst2 * fSlow222;
		double fSlow224 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow221));
		int iSlow225 = int(fSlow224);
		double fSlow226 = std::floor(fSlow224);
		double fSlow227 = fSlow226 + (1.0 - fSlow224);
		double fSlow228 = fSlow224 - fSlow226;
		int iSlow229 = iSlow225 + 1;
		double fSlow230 = ((fSlow217 == 0.0) ? 1e+02 : fSlow217);
		double fSlow231 = std::tan(fConst6 * double(int(fSlow230 + 1e+01)));
		double fSlow232 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow230))) * fSlow231));
		double fSlow233 = fConst4 * fSlow232 + -8.0;
		double fSlow234 = fConst3 * fSlow232;
		double fSlow235 = fConst23 * fSlow231 - fConst24 * (fSlow232 / fSlow231);
		double fSlow236 = fConst1 * fSlow235;
		double fSlow237 = fSlow234 + (4.0 - fSlow236);
		double fSlow238 = fSlow234 + fSlow236 + 4.0;
		double fSlow239 = 0.0 - fConst1 * (fSlow235 / fSlow238);
		double fSlow240 = double(fEntry27);
		double fSlow241 = 1.0 - fSlow240;
		int iSlow242 = 7.0 <= fSlow5;
		double fSlow243 = double(((iSlow41) ? iConst109 : 0) + ((iSlow42) ? iConst110 : 0) + ((iSlow43) ? iConst111 : 0) + ((iSlow44) ? iConst112 : 0) + ((iSlow45) ? iConst113 : 0) + ((iSlow46) ? iConst114 : 0) + ((iSlow47) ? iConst115 : 0) + ((iSlow48) ? iConst116 : 0) + ((iSlow49) ? iConst117 : 0) + ((iSlow50) ? iConst118 : 0) + ((iSlow51) ? iConst119 : 0) + ((iSlow52) ? iConst120 : 0) + ((iSlow53) ? iConst121 : 0) + ((iSlow54) ? iConst122 : 0) + ((iSlow55) ? iConst123 : 0) + ((iSlow56) ? iConst124 : 0)) + ((iSlow57) ? double(fEntry28) : 0.0);
		double fSlow244 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow243 + -69.0));
		double fSlow245 = fConst25 * fSlow244;
		double fSlow246 = 4.4e+02 * fSlow244;
		double fSlow247 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow246));
		double fSlow248 = fConst2 * fSlow247;
		double fSlow249 = 1.0 - fConst0 / fSlow247;
		double fSlow250 = std::max<double>(fSlow246, 23.44894968246214);
		double fSlow251 = std::max<double>(2e+01, std::fabs(fSlow250));
		double fSlow252 = fConst2 * fSlow251;
		double fSlow253 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow250));
		int iSlow254 = int(fSlow253);
		double fSlow255 = std::floor(fSlow253);
		double fSlow256 = fSlow255 + (1.0 - fSlow253);
		double fSlow257 = fSlow253 - fSlow255;
		int iSlow258 = iSlow254 + 1;
		double fSlow259 = ((fSlow246 == 0.0) ? 1e+02 : fSlow246);
		double fSlow260 = std::tan(fConst6 * double(int(fSlow259 + 1e+01)));
		double fSlow261 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow259))) * fSlow260));
		double fSlow262 = fConst4 * fSlow261 + -8.0;
		double fSlow263 = fConst3 * fSlow261;
		double fSlow264 = fConst23 * fSlow260 - fConst24 * (fSlow261 / fSlow260);
		double fSlow265 = fConst1 * fSlow264;
		double fSlow266 = fSlow263 + (4.0 - fSlow265);
		double fSlow267 = fSlow263 + fSlow265 + 4.0;
		double fSlow268 = 0.0 - fConst1 * (fSlow264 / fSlow267);
		double fSlow269 = double(fEntry29);
		double fSlow270 = 1.0 - fSlow269;
		int iSlow271 = 8.0 <= fSlow5;
		double fSlow272 = double(((iSlow41) ? iConst125 : 0) + ((iSlow42) ? iConst126 : 0) + ((iSlow43) ? iConst127 : 0) + ((iSlow44) ? iConst128 : 0) + ((iSlow45) ? iConst129 : 0) + ((iSlow46) ? iConst130 : 0) + ((iSlow47) ? iConst131 : 0) + ((iSlow48) ? iConst132 : 0) + ((iSlow49) ? iConst133 : 0) + ((iSlow50) ? iConst134 : 0) + ((iSlow51) ? iConst135 : 0) + ((iSlow52) ? iConst136 : 0) + ((iSlow53) ? iConst137 : 0) + ((iSlow54) ? iConst138 : 0) + ((iSlow55) ? iConst139 : 0) + ((iSlow56) ? iConst140 : 0)) + ((iSlow57) ? double(fEntry30) : 0.0);
		double fSlow273 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow272 + -69.0));
		double fSlow274 = fConst25 * fSlow273;
		double fSlow275 = 4.4e+02 * fSlow273;
		double fSlow276 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow275));
		double fSlow277 = fConst2 * fSlow276;
		double fSlow278 = 1.0 - fConst0 / fSlow276;
		double fSlow279 = std::max<double>(fSlow275, 23.44894968246214);
		double fSlow280 = std::max<double>(2e+01, std::fabs(fSlow279));
		double fSlow281 = fConst2 * fSlow280;
		double fSlow282 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow279));
		int iSlow283 = int(fSlow282);
		double fSlow284 = std::floor(fSlow282);
		double fSlow285 = fSlow284 + (1.0 - fSlow282);
		double fSlow286 = fSlow282 - fSlow284;
		int iSlow287 = iSlow283 + 1;
		double fSlow288 = ((fSlow275 == 0.0) ? 1e+02 : fSlow275);
		double fSlow289 = std::tan(fConst6 * double(int(fSlow288 + 1e+01)));
		double fSlow290 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow288))) * fSlow289));
		double fSlow291 = fConst4 * fSlow290 + -8.0;
		double fSlow292 = fConst3 * fSlow290;
		double fSlow293 = fConst23 * fSlow289 - fConst24 * (fSlow290 / fSlow289);
		double fSlow294 = fConst1 * fSlow293;
		double fSlow295 = fSlow292 + (4.0 - fSlow294);
		double fSlow296 = fSlow292 + fSlow294 + 4.0;
		double fSlow297 = 0.0 - fConst1 * (fSlow293 / fSlow296);
		double fSlow298 = double(fEntry31);
		double fSlow299 = 1.0 - fSlow298;
		int iSlow300 = 9.0 <= fSlow5;
		double fSlow301 = double(((iSlow41) ? iConst141 : 0) + ((iSlow42) ? iConst142 : 0) + ((iSlow43) ? iConst143 : 0) + ((iSlow44) ? iConst144 : 0) + ((iSlow45) ? iConst145 : 0) + ((iSlow46) ? iConst146 : 0) + ((iSlow47) ? iConst147 : 0) + ((iSlow48) ? iConst148 : 0) + ((iSlow49) ? iConst149 : 0) + ((iSlow50) ? iConst150 : 0) + ((iSlow51) ? iConst151 : 0) + ((iSlow52) ? iConst152 : 0) + ((iSlow53) ? iConst153 : 0) + ((iSlow54) ? iConst154 : 0) + ((iSlow55) ? iConst155 : 0) + ((iSlow56) ? iConst156 : 0)) + ((iSlow57) ? double(fEntry32) : 0.0);
		double fSlow302 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow301 + -69.0));
		double fSlow303 = fConst25 * fSlow302;
		double fSlow304 = 4.4e+02 * fSlow302;
		double fSlow305 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow304));
		double fSlow306 = fConst2 * fSlow305;
		double fSlow307 = 1.0 - fConst0 / fSlow305;
		double fSlow308 = std::max<double>(fSlow304, 23.44894968246214);
		double fSlow309 = std::max<double>(2e+01, std::fabs(fSlow308));
		double fSlow310 = fConst2 * fSlow309;
		double fSlow311 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow308));
		int iSlow312 = int(fSlow311);
		double fSlow313 = std::floor(fSlow311);
		double fSlow314 = fSlow313 + (1.0 - fSlow311);
		double fSlow315 = fSlow311 - fSlow313;
		int iSlow316 = iSlow312 + 1;
		double fSlow317 = ((fSlow304 == 0.0) ? 1e+02 : fSlow304);
		double fSlow318 = std::tan(fConst6 * double(int(fSlow317 + 1e+01)));
		double fSlow319 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow317))) * fSlow318));
		double fSlow320 = fConst4 * fSlow319 + -8.0;
		double fSlow321 = fConst3 * fSlow319;
		double fSlow322 = fConst23 * fSlow318 - fConst24 * (fSlow319 / fSlow318);
		double fSlow323 = fConst1 * fSlow322;
		double fSlow324 = fSlow321 + (4.0 - fSlow323);
		double fSlow325 = fSlow321 + fSlow323 + 4.0;
		double fSlow326 = 0.0 - fConst1 * (fSlow322 / fSlow325);
		double fSlow327 = double(fEntry33);
		double fSlow328 = 1.0 - fSlow327;
		int iSlow329 = 1e+01 <= fSlow5;
		double fSlow330 = double(((iSlow41) ? iConst157 : 0) + ((iSlow42) ? iConst158 : 0) + ((iSlow43) ? iConst159 : 0) + ((iSlow44) ? iConst160 : 0) + ((iSlow45) ? iConst161 : 0) + ((iSlow46) ? iConst162 : 0) + ((iSlow47) ? iConst163 : 0) + ((iSlow48) ? iConst164 : 0) + ((iSlow49) ? iConst165 : 0) + ((iSlow50) ? iConst166 : 0) + ((iSlow51) ? iConst167 : 0) + ((iSlow52) ? iConst168 : 0) + ((iSlow53) ? iConst169 : 0) + ((iSlow54) ? iConst170 : 0) + ((iSlow55) ? iConst171 : 0) + ((iSlow56) ? iConst172 : 0)) + ((iSlow57) ? double(fEntry34) : 0.0);
		double fSlow331 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow330 + -69.0));
		double fSlow332 = fConst25 * fSlow331;
		double fSlow333 = 4.4e+02 * fSlow331;
		double fSlow334 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow333));
		double fSlow335 = fConst2 * fSlow334;
		double fSlow336 = 1.0 - fConst0 / fSlow334;
		double fSlow337 = std::max<double>(fSlow333, 23.44894968246214);
		double fSlow338 = std::max<double>(2e+01, std::fabs(fSlow337));
		double fSlow339 = fConst2 * fSlow338;
		double fSlow340 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow337));
		int iSlow341 = int(fSlow340);
		double fSlow342 = std::floor(fSlow340);
		double fSlow343 = fSlow342 + (1.0 - fSlow340);
		double fSlow344 = fSlow340 - fSlow342;
		int iSlow345 = iSlow341 + 1;
		double fSlow346 = ((fSlow333 == 0.0) ? 1e+02 : fSlow333);
		double fSlow347 = std::tan(fConst6 * double(int(fSlow346 + 1e+01)));
		double fSlow348 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow346))) * fSlow347));
		double fSlow349 = fConst4 * fSlow348 + -8.0;
		double fSlow350 = fConst3 * fSlow348;
		double fSlow351 = fConst23 * fSlow347 - fConst24 * (fSlow348 / fSlow347);
		double fSlow352 = fConst1 * fSlow351;
		double fSlow353 = fSlow350 + (4.0 - fSlow352);
		double fSlow354 = fSlow350 + fSlow352 + 4.0;
		double fSlow355 = 0.0 - fConst1 * (fSlow351 / fSlow354);
		double fSlow356 = double(fEntry35);
		double fSlow357 = 1.0 - fSlow356;
		int iSlow358 = 11.0 <= fSlow5;
		double fSlow359 = double(((iSlow41) ? iConst173 : 0) + ((iSlow42) ? iConst174 : 0) + ((iSlow43) ? iConst175 : 0) + ((iSlow44) ? iConst176 : 0) + ((iSlow45) ? iConst177 : 0) + ((iSlow46) ? iConst178 : 0) + ((iSlow47) ? iConst179 : 0) + ((iSlow48) ? iConst180 : 0) + ((iSlow49) ? iConst181 : 0) + ((iSlow50) ? iConst182 : 0) + ((iSlow51) ? iConst183 : 0) + ((iSlow52) ? iConst184 : 0) + ((iSlow53) ? iConst185 : 0) + ((iSlow54) ? iConst186 : 0) + ((iSlow55) ? iConst187 : 0) + ((iSlow56) ? iConst188 : 0)) + ((iSlow57) ? double(fEntry36) : 0.0);
		double fSlow360 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow359 + -69.0));
		double fSlow361 = fConst25 * fSlow360;
		double fSlow362 = 4.4e+02 * fSlow360;
		double fSlow363 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow362));
		double fSlow364 = fConst2 * fSlow363;
		double fSlow365 = 1.0 - fConst0 / fSlow363;
		double fSlow366 = std::max<double>(fSlow362, 23.44894968246214);
		double fSlow367 = std::max<double>(2e+01, std::fabs(fSlow366));
		double fSlow368 = fConst2 * fSlow367;
		double fSlow369 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow366));
		int iSlow370 = int(fSlow369);
		double fSlow371 = std::floor(fSlow369);
		double fSlow372 = fSlow371 + (1.0 - fSlow369);
		double fSlow373 = fSlow369 - fSlow371;
		int iSlow374 = iSlow370 + 1;
		double fSlow375 = ((fSlow362 == 0.0) ? 1e+02 : fSlow362);
		double fSlow376 = std::tan(fConst6 * double(int(fSlow375 + 1e+01)));
		double fSlow377 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow375))) * fSlow376));
		double fSlow378 = fConst4 * fSlow377 + -8.0;
		double fSlow379 = fConst3 * fSlow377;
		double fSlow380 = fConst23 * fSlow376 - fConst24 * (fSlow377 / fSlow376);
		double fSlow381 = fConst1 * fSlow380;
		double fSlow382 = fSlow379 + (4.0 - fSlow381);
		double fSlow383 = fSlow379 + fSlow381 + 4.0;
		double fSlow384 = 0.0 - fConst1 * (fSlow380 / fSlow383);
		double fSlow385 = double(fEntry37);
		double fSlow386 = 1.0 - fSlow385;
		int iSlow387 = 12.0 <= fSlow5;
		double fSlow388 = double(((iSlow41) ? iConst189 : 0) + ((iSlow42) ? iConst190 : 0) + ((iSlow43) ? iConst191 : 0) + ((iSlow44) ? iConst192 : 0) + ((iSlow45) ? iConst193 : 0) + ((iSlow46) ? iConst194 : 0) + ((iSlow47) ? iConst195 : 0) + ((iSlow48) ? iConst196 : 0) + ((iSlow49) ? iConst197 : 0) + ((iSlow50) ? iConst198 : 0) + ((iSlow51) ? iConst199 : 0) + ((iSlow52) ? iConst200 : 0) + ((iSlow53) ? iConst201 : 0) + ((iSlow54) ? iConst202 : 0) + ((iSlow55) ? iConst203 : 0) + ((iSlow56) ? iConst204 : 0)) + ((iSlow57) ? double(fEntry38) : 0.0);
		double fSlow389 = std::pow(2.0, 0.08333333333333333 * (fSlow38 + fSlow388 + -69.0));
		double fSlow390 = fConst25 * fSlow389;
		double fSlow391 = 4.4e+02 * fSlow389;
		double fSlow392 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow391));
		double fSlow393 = fConst2 * fSlow392;
		double fSlow394 = 1.0 - fConst0 / fSlow392;
		double fSlow395 = std::max<double>(fSlow391, 23.44894968246214);
		double fSlow396 = std::max<double>(2e+01, std::fabs(fSlow395));
		double fSlow397 = fConst2 * fSlow396;
		double fSlow398 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow395));
		int iSlow399 = int(fSlow398);
		double fSlow400 = std::floor(fSlow398);
		double fSlow401 = fSlow400 + (1.0 - fSlow398);
		double fSlow402 = fSlow398 - fSlow400;
		int iSlow403 = iSlow399 + 1;
		double fSlow404 = ((fSlow391 == 0.0) ? 1e+02 : fSlow391);
		double fSlow405 = std::tan(fConst6 * double(int(fSlow404 + 1e+01)));
		double fSlow406 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow404))) * fSlow405));
		double fSlow407 = fConst4 * fSlow406 + -8.0;
		double fSlow408 = fConst3 * fSlow406;
		double fSlow409 = fConst23 * fSlow405 - fConst24 * (fSlow406 / fSlow405);
		double fSlow410 = fConst1 * fSlow409;
		double fSlow411 = fSlow408 + (4.0 - fSlow410);
		double fSlow412 = fSlow408 + fSlow410 + 4.0;
		double fSlow413 = 0.0 - fConst1 * (fSlow409 / fSlow412);
		double fSlow414 = double(fEntry39);
		int iSlow415 = int(double(fEntry40));
		double fSlow416 = fSlow38 + fSlow58;
		double fSlow417 = ((iSlow8) ? fSlow416 : fSlow38 - fSlow58);
		double fSlow418 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow417 + -69.0)) : fSlow60);
		double fSlow419 = fConst2 * fSlow418;
		double fSlow420 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow418));
		double fSlow421 = fConst2 * fSlow420;
		double fSlow422 = 1.0 - fConst0 / fSlow420;
		double fSlow423 = std::max<double>(fSlow418, 23.44894968246214);
		double fSlow424 = std::max<double>(2e+01, std::fabs(fSlow423));
		double fSlow425 = fConst2 * fSlow424;
		double fSlow426 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow423));
		int iSlow427 = int(fSlow426);
		double fSlow428 = std::floor(fSlow426);
		double fSlow429 = fSlow428 + (1.0 - fSlow426);
		double fSlow430 = fSlow426 - fSlow428;
		int iSlow431 = iSlow427 + 1;
		double fSlow432 = ((fSlow418 == 0.0) ? 1e+02 : fSlow418);
		double fSlow433 = std::tan(fConst6 * double(int(fSlow432 + 1e+01)));
		double fSlow434 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow432))) * fSlow433));
		double fSlow435 = fConst4 * fSlow434 + -8.0;
		double fSlow436 = fConst3 * fSlow434;
		double fSlow437 = fConst23 * fSlow433 - fConst24 * (fSlow434 / fSlow433);
		double fSlow438 = fConst1 * fSlow437;
		double fSlow439 = fSlow436 + (4.0 - fSlow438);
		double fSlow440 = fSlow436 + fSlow438 + 4.0;
		double fSlow441 = 0.0 - fConst1 * (fSlow437 / fSlow440);
		double fSlow442 = fSlow38 + fSlow127;
		double fSlow443 = ((iSlow8) ? fSlow442 : fSlow38 - fSlow127);
		double fSlow444 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow443 + -69.0)) : fSlow130);
		double fSlow445 = fConst2 * fSlow444;
		double fSlow446 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow444));
		double fSlow447 = fConst2 * fSlow446;
		double fSlow448 = 1.0 - fConst0 / fSlow446;
		double fSlow449 = std::max<double>(fSlow444, 23.44894968246214);
		double fSlow450 = std::max<double>(2e+01, std::fabs(fSlow449));
		double fSlow451 = fConst2 * fSlow450;
		double fSlow452 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow449));
		int iSlow453 = int(fSlow452);
		double fSlow454 = std::floor(fSlow452);
		double fSlow455 = fSlow454 + (1.0 - fSlow452);
		double fSlow456 = fSlow452 - fSlow454;
		int iSlow457 = iSlow453 + 1;
		double fSlow458 = ((fSlow444 == 0.0) ? 1e+02 : fSlow444);
		double fSlow459 = std::tan(fConst6 * double(int(fSlow458 + 1e+01)));
		double fSlow460 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow458))) * fSlow459));
		double fSlow461 = fConst4 * fSlow460 + -8.0;
		double fSlow462 = fConst3 * fSlow460;
		double fSlow463 = fConst23 * fSlow459 - fConst24 * (fSlow460 / fSlow459);
		double fSlow464 = fConst1 * fSlow463;
		double fSlow465 = fSlow462 + (4.0 - fSlow464);
		double fSlow466 = fSlow462 + fSlow464 + 4.0;
		double fSlow467 = 0.0 - fConst1 * (fSlow463 / fSlow466);
		double fSlow468 = fSlow38 + fSlow185;
		double fSlow469 = ((iSlow8) ? fSlow468 : fSlow38 - fSlow185);
		double fSlow470 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow469 + -69.0)) : fSlow188);
		double fSlow471 = fConst2 * fSlow470;
		double fSlow472 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow470));
		double fSlow473 = fConst2 * fSlow472;
		double fSlow474 = 1.0 - fConst0 / fSlow472;
		double fSlow475 = std::max<double>(fSlow470, 23.44894968246214);
		double fSlow476 = std::max<double>(2e+01, std::fabs(fSlow475));
		double fSlow477 = fConst2 * fSlow476;
		double fSlow478 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow475));
		int iSlow479 = int(fSlow478);
		double fSlow480 = std::floor(fSlow478);
		double fSlow481 = fSlow480 + (1.0 - fSlow478);
		double fSlow482 = fSlow478 - fSlow480;
		int iSlow483 = iSlow479 + 1;
		double fSlow484 = ((fSlow470 == 0.0) ? 1e+02 : fSlow470);
		double fSlow485 = std::tan(fConst6 * double(int(fSlow484 + 1e+01)));
		double fSlow486 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow484))) * fSlow485));
		double fSlow487 = fConst4 * fSlow486 + -8.0;
		double fSlow488 = fConst3 * fSlow486;
		double fSlow489 = fConst23 * fSlow485 - fConst24 * (fSlow486 / fSlow485);
		double fSlow490 = fConst1 * fSlow489;
		double fSlow491 = fSlow488 + (4.0 - fSlow490);
		double fSlow492 = fSlow488 + fSlow490 + 4.0;
		double fSlow493 = 0.0 - fConst1 * (fSlow489 / fSlow492);
		double fSlow494 = fSlow38 + fSlow243;
		double fSlow495 = ((iSlow8) ? fSlow494 : fSlow38 - fSlow243);
		double fSlow496 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow495 + -69.0)) : fSlow246);
		double fSlow497 = fConst2 * fSlow496;
		double fSlow498 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow496));
		double fSlow499 = fConst2 * fSlow498;
		double fSlow500 = 1.0 - fConst0 / fSlow498;
		double fSlow501 = std::max<double>(fSlow496, 23.44894968246214);
		double fSlow502 = std::max<double>(2e+01, std::fabs(fSlow501));
		double fSlow503 = fConst2 * fSlow502;
		double fSlow504 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow501));
		int iSlow505 = int(fSlow504);
		double fSlow506 = std::floor(fSlow504);
		double fSlow507 = fSlow506 + (1.0 - fSlow504);
		double fSlow508 = fSlow504 - fSlow506;
		int iSlow509 = iSlow505 + 1;
		double fSlow510 = ((fSlow496 == 0.0) ? 1e+02 : fSlow496);
		double fSlow511 = std::tan(fConst6 * double(int(fSlow510 + 1e+01)));
		double fSlow512 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow510))) * fSlow511));
		double fSlow513 = fConst4 * fSlow512 + -8.0;
		double fSlow514 = fConst3 * fSlow512;
		double fSlow515 = fConst23 * fSlow511 - fConst24 * (fSlow512 / fSlow511);
		double fSlow516 = fConst1 * fSlow515;
		double fSlow517 = fSlow514 + (4.0 - fSlow516);
		double fSlow518 = fSlow514 + fSlow516 + 4.0;
		double fSlow519 = 0.0 - fConst1 * (fSlow515 / fSlow518);
		double fSlow520 = fSlow38 + fSlow301;
		double fSlow521 = ((iSlow8) ? fSlow520 : fSlow38 - fSlow301);
		double fSlow522 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow521 + -69.0)) : fSlow304);
		double fSlow523 = fConst2 * fSlow522;
		double fSlow524 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow522));
		double fSlow525 = fConst2 * fSlow524;
		double fSlow526 = 1.0 - fConst0 / fSlow524;
		double fSlow527 = std::max<double>(fSlow522, 23.44894968246214);
		double fSlow528 = std::max<double>(2e+01, std::fabs(fSlow527));
		double fSlow529 = fConst2 * fSlow528;
		double fSlow530 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow527));
		int iSlow531 = int(fSlow530);
		double fSlow532 = std::floor(fSlow530);
		double fSlow533 = fSlow532 + (1.0 - fSlow530);
		double fSlow534 = fSlow530 - fSlow532;
		int iSlow535 = iSlow531 + 1;
		double fSlow536 = ((fSlow522 == 0.0) ? 1e+02 : fSlow522);
		double fSlow537 = std::tan(fConst6 * double(int(fSlow536 + 1e+01)));
		double fSlow538 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow536))) * fSlow537));
		double fSlow539 = fConst4 * fSlow538 + -8.0;
		double fSlow540 = fConst3 * fSlow538;
		double fSlow541 = fConst23 * fSlow537 - fConst24 * (fSlow538 / fSlow537);
		double fSlow542 = fConst1 * fSlow541;
		double fSlow543 = fSlow540 + (4.0 - fSlow542);
		double fSlow544 = fSlow540 + fSlow542 + 4.0;
		double fSlow545 = 0.0 - fConst1 * (fSlow541 / fSlow544);
		double fSlow546 = fSlow38 + fSlow359;
		double fSlow547 = ((iSlow8) ? fSlow546 : fSlow38 - fSlow359);
		double fSlow548 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow547 + -69.0)) : fSlow362);
		double fSlow549 = fConst2 * fSlow548;
		double fSlow550 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow548));
		double fSlow551 = fConst2 * fSlow550;
		double fSlow552 = 1.0 - fConst0 / fSlow550;
		double fSlow553 = std::max<double>(fSlow548, 23.44894968246214);
		double fSlow554 = std::max<double>(2e+01, std::fabs(fSlow553));
		double fSlow555 = fConst2 * fSlow554;
		double fSlow556 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow553));
		int iSlow557 = int(fSlow556);
		double fSlow558 = std::floor(fSlow556);
		double fSlow559 = fSlow558 + (1.0 - fSlow556);
		double fSlow560 = fSlow556 - fSlow558;
		int iSlow561 = iSlow557 + 1;
		double fSlow562 = ((fSlow548 == 0.0) ? 1e+02 : fSlow548);
		double fSlow563 = std::tan(fConst6 * double(int(fSlow562 + 1e+01)));
		double fSlow564 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow562))) * fSlow563));
		double fSlow565 = fConst4 * fSlow564 + -8.0;
		double fSlow566 = fConst3 * fSlow564;
		double fSlow567 = fConst23 * fSlow563 - fConst24 * (fSlow564 / fSlow563);
		double fSlow568 = fConst1 * fSlow567;
		double fSlow569 = fSlow566 + (4.0 - fSlow568);
		double fSlow570 = fSlow566 + fSlow568 + 4.0;
		double fSlow571 = 0.0 - fConst1 * (fSlow567 / fSlow570);
		double fSlow572 = fSlow38 + fSlow98;
		double fSlow573 = ((iSlow8) ? fSlow572 : fSlow38 - fSlow98);
		double fSlow574 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow573 + -69.0)) : fSlow101);
		double fSlow575 = fConst2 * fSlow574;
		double fSlow576 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow574));
		double fSlow577 = fConst2 * fSlow576;
		double fSlow578 = 1.0 - fConst0 / fSlow576;
		double fSlow579 = std::max<double>(fSlow574, 23.44894968246214);
		double fSlow580 = std::max<double>(2e+01, std::fabs(fSlow579));
		double fSlow581 = fConst2 * fSlow580;
		double fSlow582 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow579));
		int iSlow583 = int(fSlow582);
		double fSlow584 = std::floor(fSlow582);
		double fSlow585 = fSlow584 + (1.0 - fSlow582);
		double fSlow586 = fSlow582 - fSlow584;
		int iSlow587 = iSlow583 + 1;
		double fSlow588 = ((fSlow574 == 0.0) ? 1e+02 : fSlow574);
		double fSlow589 = std::tan(fConst6 * double(int(fSlow588 + 1e+01)));
		double fSlow590 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow588))) * fSlow589));
		double fSlow591 = fConst4 * fSlow590 + -8.0;
		double fSlow592 = fConst3 * fSlow590;
		double fSlow593 = fConst23 * fSlow589 - fConst24 * (fSlow590 / fSlow589);
		double fSlow594 = fConst1 * fSlow593;
		double fSlow595 = fSlow592 + (4.0 - fSlow594);
		double fSlow596 = fSlow592 + fSlow594 + 4.0;
		double fSlow597 = 0.0 - fConst1 * (fSlow593 / fSlow596);
		double fSlow598 = fSlow38 + fSlow156;
		double fSlow599 = ((iSlow8) ? fSlow598 : fSlow38 - fSlow156);
		double fSlow600 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow599 + -69.0)) : fSlow159);
		double fSlow601 = fConst2 * fSlow600;
		double fSlow602 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow600));
		double fSlow603 = fConst2 * fSlow602;
		double fSlow604 = 1.0 - fConst0 / fSlow602;
		double fSlow605 = std::max<double>(fSlow600, 23.44894968246214);
		double fSlow606 = std::max<double>(2e+01, std::fabs(fSlow605));
		double fSlow607 = fConst2 * fSlow606;
		double fSlow608 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow605));
		int iSlow609 = int(fSlow608);
		double fSlow610 = std::floor(fSlow608);
		double fSlow611 = fSlow610 + (1.0 - fSlow608);
		double fSlow612 = fSlow608 - fSlow610;
		int iSlow613 = iSlow609 + 1;
		double fSlow614 = ((fSlow600 == 0.0) ? 1e+02 : fSlow600);
		double fSlow615 = std::tan(fConst6 * double(int(fSlow614 + 1e+01)));
		double fSlow616 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow614))) * fSlow615));
		double fSlow617 = fConst4 * fSlow616 + -8.0;
		double fSlow618 = fConst3 * fSlow616;
		double fSlow619 = fConst23 * fSlow615 - fConst24 * (fSlow616 / fSlow615);
		double fSlow620 = fConst1 * fSlow619;
		double fSlow621 = fSlow618 + (4.0 - fSlow620);
		double fSlow622 = fSlow618 + fSlow620 + 4.0;
		double fSlow623 = 0.0 - fConst1 * (fSlow619 / fSlow622);
		double fSlow624 = fSlow38 + fSlow214;
		double fSlow625 = ((iSlow8) ? fSlow624 : fSlow38 - fSlow214);
		double fSlow626 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow625 + -69.0)) : fSlow217);
		double fSlow627 = fConst2 * fSlow626;
		double fSlow628 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow626));
		double fSlow629 = fConst2 * fSlow628;
		double fSlow630 = 1.0 - fConst0 / fSlow628;
		double fSlow631 = std::max<double>(fSlow626, 23.44894968246214);
		double fSlow632 = std::max<double>(2e+01, std::fabs(fSlow631));
		double fSlow633 = fConst2 * fSlow632;
		double fSlow634 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow631));
		int iSlow635 = int(fSlow634);
		double fSlow636 = std::floor(fSlow634);
		double fSlow637 = fSlow636 + (1.0 - fSlow634);
		double fSlow638 = fSlow634 - fSlow636;
		int iSlow639 = iSlow635 + 1;
		double fSlow640 = ((fSlow626 == 0.0) ? 1e+02 : fSlow626);
		double fSlow641 = std::tan(fConst6 * double(int(fSlow640 + 1e+01)));
		double fSlow642 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow640))) * fSlow641));
		double fSlow643 = fConst4 * fSlow642 + -8.0;
		double fSlow644 = fConst3 * fSlow642;
		double fSlow645 = fConst23 * fSlow641 - fConst24 * (fSlow642 / fSlow641);
		double fSlow646 = fConst1 * fSlow645;
		double fSlow647 = fSlow644 + (4.0 - fSlow646);
		double fSlow648 = fSlow644 + fSlow646 + 4.0;
		double fSlow649 = 0.0 - fConst1 * (fSlow645 / fSlow648);
		double fSlow650 = fSlow38 + fSlow272;
		double fSlow651 = ((iSlow8) ? fSlow650 : fSlow38 - fSlow272);
		double fSlow652 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow651 + -69.0)) : fSlow275);
		double fSlow653 = fConst2 * fSlow652;
		double fSlow654 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow652));
		double fSlow655 = fConst2 * fSlow654;
		double fSlow656 = 1.0 - fConst0 / fSlow654;
		double fSlow657 = std::max<double>(fSlow652, 23.44894968246214);
		double fSlow658 = std::max<double>(2e+01, std::fabs(fSlow657));
		double fSlow659 = fConst2 * fSlow658;
		double fSlow660 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow657));
		int iSlow661 = int(fSlow660);
		double fSlow662 = std::floor(fSlow660);
		double fSlow663 = fSlow662 + (1.0 - fSlow660);
		double fSlow664 = fSlow660 - fSlow662;
		int iSlow665 = iSlow661 + 1;
		double fSlow666 = ((fSlow652 == 0.0) ? 1e+02 : fSlow652);
		double fSlow667 = std::tan(fConst6 * double(int(fSlow666 + 1e+01)));
		double fSlow668 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow666))) * fSlow667));
		double fSlow669 = fConst4 * fSlow668 + -8.0;
		double fSlow670 = fConst3 * fSlow668;
		double fSlow671 = fConst23 * fSlow667 - fConst24 * (fSlow668 / fSlow667);
		double fSlow672 = fConst1 * fSlow671;
		double fSlow673 = fSlow670 + (4.0 - fSlow672);
		double fSlow674 = fSlow670 + fSlow672 + 4.0;
		double fSlow675 = 0.0 - fConst1 * (fSlow671 / fSlow674);
		double fSlow676 = fSlow38 + fSlow330;
		double fSlow677 = ((iSlow8) ? fSlow676 : fSlow38 - fSlow330);
		double fSlow678 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow677 + -69.0)) : fSlow333);
		double fSlow679 = fConst2 * fSlow678;
		double fSlow680 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow678));
		double fSlow681 = fConst2 * fSlow680;
		double fSlow682 = 1.0 - fConst0 / fSlow680;
		double fSlow683 = std::max<double>(fSlow678, 23.44894968246214);
		double fSlow684 = std::max<double>(2e+01, std::fabs(fSlow683));
		double fSlow685 = fConst2 * fSlow684;
		double fSlow686 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow683));
		int iSlow687 = int(fSlow686);
		double fSlow688 = std::floor(fSlow686);
		double fSlow689 = fSlow688 + (1.0 - fSlow686);
		double fSlow690 = fSlow686 - fSlow688;
		int iSlow691 = iSlow687 + 1;
		double fSlow692 = ((fSlow678 == 0.0) ? 1e+02 : fSlow678);
		double fSlow693 = std::tan(fConst6 * double(int(fSlow692 + 1e+01)));
		double fSlow694 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow692))) * fSlow693));
		double fSlow695 = fConst4 * fSlow694 + -8.0;
		double fSlow696 = fConst3 * fSlow694;
		double fSlow697 = fConst23 * fSlow693 - fConst24 * (fSlow694 / fSlow693);
		double fSlow698 = fConst1 * fSlow697;
		double fSlow699 = fSlow696 + (4.0 - fSlow698);
		double fSlow700 = fSlow696 + fSlow698 + 4.0;
		double fSlow701 = 0.0 - fConst1 * (fSlow697 / fSlow700);
		double fSlow702 = fSlow38 + fSlow388;
		double fSlow703 = ((iSlow8) ? fSlow702 : fSlow38 - fSlow388);
		double fSlow704 = ((iSlow415) ? 4.4e+02 * std::pow(2.0, 0.08333333333333333 * (fSlow703 + -69.0)) : fSlow391);
		double fSlow705 = fConst2 * fSlow704;
		double fSlow706 = std::max<double>(2.220446049250313e-16, std::fabs(fSlow704));
		double fSlow707 = fConst2 * fSlow706;
		double fSlow708 = 1.0 - fConst0 / fSlow706;
		double fSlow709 = std::max<double>(fSlow704, 23.44894968246214);
		double fSlow710 = std::max<double>(2e+01, std::fabs(fSlow709));
		double fSlow711 = fConst2 * fSlow710;
		double fSlow712 = std::max<double>(0.0, std::min<double>(2047.0, fConst28 / fSlow709));
		int iSlow713 = int(fSlow712);
		double fSlow714 = std::floor(fSlow712);
		double fSlow715 = fSlow714 + (1.0 - fSlow712);
		double fSlow716 = fSlow712 - fSlow714;
		int iSlow717 = iSlow713 + 1;
		double fSlow718 = ((fSlow704 == 0.0) ? 1e+02 : fSlow704);
		double fSlow719 = std::tan(fConst6 * double(int(fSlow718 + 1e+01)));
		double fSlow720 = scaleIt_faustpower2_f(std::sqrt(fConst5 * std::tan(fConst6 * double(int(fSlow718))) * fSlow719));
		double fSlow721 = fConst4 * fSlow720 + -8.0;
		double fSlow722 = fConst3 * fSlow720;
		double fSlow723 = fConst23 * fSlow719 - fConst24 * (fSlow720 / fSlow719);
		double fSlow724 = fConst1 * fSlow723;
		double fSlow725 = fSlow722 + (4.0 - fSlow724);
		double fSlow726 = fSlow722 + fSlow724 + 4.0;
		double fSlow727 = 0.0 - fConst1 * (fSlow723 / fSlow726);
		double fSlow728 = ((iSlow415) ? fSlow417 : fSlow416);
		double fSlow729 = ((iSlow415) ? fSlow573 : fSlow572);
		double fSlow730 = ((iSlow415) ? fSlow443 : fSlow442);
		double fSlow731 = ((iSlow415) ? fSlow599 : fSlow598);
		double fSlow732 = ((iSlow415) ? fSlow469 : fSlow468);
		double fSlow733 = ((iSlow415) ? fSlow625 : fSlow624);
		double fSlow734 = ((iSlow415) ? fSlow495 : fSlow494);
		double fSlow735 = ((iSlow415) ? fSlow651 : fSlow650);
		double fSlow736 = ((iSlow415) ? fSlow521 : fSlow520);
		double fSlow737 = ((iSlow415) ? fSlow677 : fSlow676);
		double fSlow738 = ((iSlow415) ? fSlow547 : fSlow546);
		double fSlow739 = ((iSlow415) ? fSlow703 : fSlow702);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			double fTemp0 = double(input0[i0]);
			double fTemp1 = double(input1[i0]);
			int iTemp2 = ((fTemp0 <= 0.0) & iSlow0) | ((fTemp0 >= fTemp1) & iSlow1);
			int iTemp3 = fTemp0 >= (fSlow10 * fTemp1);
			int iTemp4 = fTemp0 >= (fSlow14 * fTemp1);
			int iTemp5 = (-1 * iTemp4) == iTemp4;
			int iTemp6 = fTemp0 >= (fSlow16 * fTemp1);
			int iTemp7 = (-1 * iTemp6) == iTemp6;
			int iTemp8 = fTemp0 >= (fSlow18 * fTemp1);
			int iTemp9 = (-1 * iTemp8) == iTemp8;
			int iTemp10 = fTemp0 >= (fSlow20 * fTemp1);
			int iTemp11 = (-1 * iTemp10) == iTemp10;
			int iTemp12 = fTemp0 >= (fSlow22 * fTemp1);
			int iTemp13 = (-1 * iTemp12) == iTemp12;
			int iTemp14 = fTemp0 >= (fSlow24 * fTemp1);
			int iTemp15 = (-1 * iTemp14) == iTemp14;
			int iTemp16 = fTemp0 >= (fSlow26 * fTemp1);
			int iTemp17 = (-1 * iTemp16) == iTemp16;
			int iTemp18 = fTemp0 >= (fSlow28 * fTemp1);
			int iTemp19 = (-1 * iTemp18) == iTemp18;
			int iTemp20 = fTemp0 >= (fSlow30 * fTemp1);
			int iTemp21 = (-1 * iTemp20) == iTemp20;
			int iTemp22 = fTemp0 >= (fSlow32 * fTemp1);
			int iTemp23 = (-1 * iTemp22) == iTemp22;
			int iTemp24 = fTemp0 >= (fSlow34 * fTemp1);
			int iTemp25 = (-1 * iTemp24) == iTemp24;
			int iTemp26 = ((iSlow6) ? ((iSlow8) ? iTemp3 : 0) + ((iSlow12) ? iTemp5 : 0) + ((iSlow15) ? iTemp7 : 0) + ((iSlow17) ? iTemp9 : 0) + ((iSlow19) ? iTemp11 : 0) + ((iSlow21) ? iTemp13 : 0) + ((iSlow23) ? iTemp15 : 0) + ((iSlow25) ? iTemp17 : 0) + ((iSlow27) ? iTemp19 : 0) + ((iSlow29) ? iTemp21 : 0) + ((iSlow31) ? iTemp23 : 0) + ((iSlow33) ? iTemp25 : 0) : 0);
			iVec0[0] = iTemp26;
			iVec1[0] = 1;
			iRec0[0] = iTemp26 + iRec0[1] * (iVec0[1] >= iTemp26);
			double fTemp27 = double(iRec0[0]);
			iRec1[0] = (iRec1[1] + 1) * (iTemp26 == 0);
			double fTemp28 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp27, std::max<double>(fSlow36 * (fSlow3 - fTemp27) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec1[0])));
			iRec3[0] = 1103515245 * iRec3[1] + 12345;
			double fTemp29 = 6.984919312868695e-10 * double(iRec3[0]);
			fRec2[0] = fTemp29 - (fRec2[1] * fSlow64 + fRec2[2] * fSlow68) / fSlow69;
			double fTemp30 = (fConst1 * (fRec2[0] * fSlow66 / fSlow69) + fRec2[2] * fSlow70) * fSlow72;
			double fTemp31 = fRec5[1] + fSlow77;
			fRec5[0] = fTemp31 - std::floor(fTemp31);
			double fTemp32 = fRec6[1] + fSlow80;
			double fTemp33 = fTemp32 + -1.0;
			int iTemp34 = fTemp33 < 0.0;
			fRec6[0] = ((iTemp34) ? fTemp32 : fTemp33);
			double fRec7 = ((iTemp34) ? fTemp32 : fTemp32 + fTemp33 * fSlow81);
			double fTemp35 = double(iVec1[1]);
			double fTemp36 = fRec9[1] + fSlow85;
			fRec9[0] = fTemp36 - std::floor(fTemp36);
			double fTemp37 = scaleIt_faustpower2_f(2.0 * fRec9[0] + -1.0);
			fVec3[0] = fTemp37;
			double fTemp38 = fTemp35 * (fTemp37 - fVec3[1]) / fSlow84;
			fVec4[IOTA0 & 4095] = fTemp38;
			double fTemp39 = fConst27 * (fTemp38 - fVec4[(IOTA0 - iSlow87) & 4095] * fSlow89 - fSlow90 * fVec4[(IOTA0 - iSlow91) & 4095]);
			fRec8[0] = 0.999 * fRec8[1] + fTemp39;
			double fTemp40 = (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec5[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec7 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec8[0] * fSlow59 : 0.0) + ((iSlow92) ? fTemp39 : 0.0)) * fSlow94;
			int iTemp41 = (-1 * iTemp3) == iTemp3;
			int iTemp42 = ((iSlow97) ? ((iSlow8) ? iTemp4 : 0) + ((iSlow12) ? iTemp41 : 0) + ((iSlow15) ? iTemp5 : 0) + ((iSlow17) ? iTemp7 : 0) + ((iSlow19) ? iTemp9 : 0) + ((iSlow21) ? iTemp11 : 0) + ((iSlow23) ? iTemp13 : 0) + ((iSlow25) ? iTemp15 : 0) + ((iSlow27) ? iTemp17 : 0) + ((iSlow29) ? iTemp19 : 0) + ((iSlow31) ? iTemp21 : 0) + ((iSlow33) ? iTemp23 : 0) : 0);
			iVec5[0] = iTemp42;
			iRec10[0] = iTemp42 + iRec10[1] * (iVec5[1] >= iTemp42);
			double fTemp43 = double(iRec10[0]);
			iRec11[0] = (iRec11[1] + 1) * (iTemp42 == 0);
			double fTemp44 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp43, std::max<double>(fSlow36 * (fSlow3 - fTemp43) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec11[0])));
			double fTemp45 = fRec12[1] + fSlow100;
			fRec12[0] = fTemp45 - std::floor(fTemp45);
			double fTemp46 = fRec13[1] + fSlow103;
			double fTemp47 = fTemp46 + -1.0;
			int iTemp48 = fTemp47 < 0.0;
			fRec13[0] = ((iTemp48) ? fTemp46 : fTemp47);
			double fRec14 = ((iTemp48) ? fTemp46 : fTemp46 + fTemp47 * fSlow104);
			double fTemp49 = fRec16[1] + fSlow107;
			fRec16[0] = fTemp49 - std::floor(fTemp49);
			double fTemp50 = scaleIt_faustpower2_f(2.0 * fRec16[0] + -1.0);
			fVec6[0] = fTemp50;
			double fTemp51 = fTemp35 * (fTemp50 - fVec6[1]) / fSlow106;
			fVec7[IOTA0 & 4095] = fTemp51;
			double fTemp52 = fConst27 * (fTemp51 - fVec7[(IOTA0 - iSlow109) & 4095] * fSlow111 - fSlow112 * fVec7[(IOTA0 - iSlow113) & 4095]);
			fRec15[0] = 0.999 * fRec15[1] + fTemp52;
			double fTemp53 = fSlow94 * fTemp44 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec12[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec14 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec15[0] * fSlow99 : 0.0) + ((iSlow92) ? fTemp52 : 0.0));
			fRec17[0] = fTemp29 - (fRec17[1] * fSlow117 + fRec17[2] * fSlow121) / fSlow122;
			double fTemp54 = fSlow72 * fTemp44 * (fConst1 * (fRec17[0] * fSlow119 / fSlow122) + fRec17[2] * fSlow123);
			int iTemp55 = ((iSlow126) ? ((iSlow8) ? iTemp6 : 0) + ((iSlow12) ? iTemp7 : 0) + ((iSlow15) ? iTemp41 : 0) + ((iSlow17) ? iTemp5 : 0) + ((iSlow19) ? iTemp7 : 0) + ((iSlow21) ? iTemp9 : 0) + ((iSlow23) ? iTemp11 : 0) + ((iSlow25) ? iTemp13 : 0) + ((iSlow27) ? iTemp15 : 0) + ((iSlow29) ? iTemp17 : 0) + ((iSlow31) ? iTemp19 : 0) + ((iSlow33) ? iTemp21 : 0) : 0);
			iVec8[0] = iTemp55;
			iRec18[0] = iTemp55 + iRec18[1] * (iVec8[1] >= iTemp55);
			double fTemp56 = double(iRec18[0]);
			iRec19[0] = (iRec19[1] + 1) * (iTemp55 == 0);
			double fTemp57 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp56, std::max<double>(fSlow36 * (fSlow3 - fTemp56) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec19[0])));
			double fTemp58 = fRec20[1] + fSlow129;
			fRec20[0] = fTemp58 - std::floor(fTemp58);
			double fTemp59 = fRec21[1] + fSlow132;
			double fTemp60 = fTemp59 + -1.0;
			int iTemp61 = fTemp60 < 0.0;
			fRec21[0] = ((iTemp61) ? fTemp59 : fTemp60);
			double fRec22 = ((iTemp61) ? fTemp59 : fTemp59 + fTemp60 * fSlow133);
			double fTemp62 = fRec24[1] + fSlow136;
			fRec24[0] = fTemp62 - std::floor(fTemp62);
			double fTemp63 = scaleIt_faustpower2_f(2.0 * fRec24[0] + -1.0);
			fVec9[0] = fTemp63;
			double fTemp64 = fTemp35 * (fTemp63 - fVec9[1]) / fSlow135;
			fVec10[IOTA0 & 4095] = fTemp64;
			double fTemp65 = fConst27 * (fTemp64 - fVec10[(IOTA0 - iSlow138) & 4095] * fSlow140 - fSlow141 * fVec10[(IOTA0 - iSlow142) & 4095]);
			fRec23[0] = 0.999 * fRec23[1] + fTemp65;
			double fTemp66 = fSlow94 * fTemp57 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec20[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec22 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec23[0] * fSlow128 : 0.0) + ((iSlow92) ? fTemp65 : 0.0));
			fRec25[0] = fTemp29 - (fRec25[1] * fSlow146 + fRec25[2] * fSlow150) / fSlow151;
			double fTemp67 = fSlow72 * fTemp57 * (fConst1 * (fRec25[0] * fSlow148 / fSlow151) + fRec25[2] * fSlow152);
			int iTemp68 = ((iSlow155) ? ((iSlow8) ? iTemp8 : 0) + ((iSlow12) ? iTemp9 : 0) + ((iSlow15) ? iTemp9 : 0) + ((iSlow17) ? iTemp41 : 0) + ((iSlow19) ? iTemp5 : 0) + ((iSlow21) ? iTemp7 : 0) + ((iSlow23) ? iTemp9 : 0) + ((iSlow25) ? iTemp11 : 0) + ((iSlow27) ? iTemp13 : 0) + ((iSlow29) ? iTemp15 : 0) + ((iSlow31) ? iTemp17 : 0) + ((iSlow33) ? iTemp19 : 0) : 0);
			iVec11[0] = iTemp68;
			iRec26[0] = iTemp68 + iRec26[1] * (iVec11[1] >= iTemp68);
			double fTemp69 = double(iRec26[0]);
			iRec27[0] = (iRec27[1] + 1) * (iTemp68 == 0);
			double fTemp70 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp69, std::max<double>(fSlow36 * (fSlow3 - fTemp69) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec27[0])));
			double fTemp71 = fRec28[1] + fSlow158;
			fRec28[0] = fTemp71 - std::floor(fTemp71);
			double fTemp72 = fRec29[1] + fSlow161;
			double fTemp73 = fTemp72 + -1.0;
			int iTemp74 = fTemp73 < 0.0;
			fRec29[0] = ((iTemp74) ? fTemp72 : fTemp73);
			double fRec30 = ((iTemp74) ? fTemp72 : fTemp72 + fTemp73 * fSlow162);
			double fTemp75 = fRec32[1] + fSlow165;
			fRec32[0] = fTemp75 - std::floor(fTemp75);
			double fTemp76 = scaleIt_faustpower2_f(2.0 * fRec32[0] + -1.0);
			fVec12[0] = fTemp76;
			double fTemp77 = fTemp35 * (fTemp76 - fVec12[1]) / fSlow164;
			fVec13[IOTA0 & 4095] = fTemp77;
			double fTemp78 = fConst27 * (fTemp77 - fVec13[(IOTA0 - iSlow167) & 4095] * fSlow169 - fSlow170 * fVec13[(IOTA0 - iSlow171) & 4095]);
			fRec31[0] = 0.999 * fRec31[1] + fTemp78;
			double fTemp79 = fSlow94 * fTemp70 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec28[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec30 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec31[0] * fSlow157 : 0.0) + ((iSlow92) ? fTemp78 : 0.0));
			fRec33[0] = fTemp29 - (fRec33[1] * fSlow175 + fRec33[2] * fSlow179) / fSlow180;
			double fTemp80 = fSlow72 * fTemp70 * (fConst1 * (fRec33[0] * fSlow177 / fSlow180) + fRec33[2] * fSlow181);
			int iTemp81 = ((iSlow184) ? ((iSlow8) ? iTemp10 : 0) + ((iSlow12) ? iTemp11 : 0) + ((iSlow15) ? iTemp11 : 0) + ((iSlow17) ? iTemp11 : 0) + ((iSlow19) ? iTemp41 : 0) + ((iSlow21) ? iTemp5 : 0) + ((iSlow23) ? iTemp7 : 0) + ((iSlow25) ? iTemp9 : 0) + ((iSlow27) ? iTemp11 : 0) + ((iSlow29) ? iTemp13 : 0) + ((iSlow31) ? iTemp15 : 0) + ((iSlow33) ? iTemp17 : 0) : 0);
			iVec14[0] = iTemp81;
			iRec34[0] = iTemp81 + iRec34[1] * (iVec14[1] >= iTemp81);
			double fTemp82 = double(iRec34[0]);
			iRec35[0] = (iRec35[1] + 1) * (iTemp81 == 0);
			double fTemp83 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp82, std::max<double>(1.0 - fSlow36 * (fTemp82 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec35[0])));
			double fTemp84 = fRec36[1] + fSlow187;
			fRec36[0] = fTemp84 - std::floor(fTemp84);
			double fTemp85 = fRec37[1] + fSlow190;
			double fTemp86 = fTemp85 + -1.0;
			int iTemp87 = fTemp86 < 0.0;
			fRec37[0] = ((iTemp87) ? fTemp85 : fTemp86);
			double fRec38 = ((iTemp87) ? fTemp85 : fTemp85 + fTemp86 * fSlow191);
			double fTemp88 = fRec40[1] + fSlow194;
			fRec40[0] = fTemp88 - std::floor(fTemp88);
			double fTemp89 = scaleIt_faustpower2_f(2.0 * fRec40[0] + -1.0);
			fVec15[0] = fTemp89;
			double fTemp90 = fTemp35 * (fTemp89 - fVec15[1]) / fSlow193;
			fVec16[IOTA0 & 4095] = fTemp90;
			double fTemp91 = fConst27 * (fTemp90 - fVec16[(IOTA0 - iSlow196) & 4095] * fSlow198 - fSlow199 * fVec16[(IOTA0 - iSlow200) & 4095]);
			fRec39[0] = 0.999 * fRec39[1] + fTemp91;
			double fTemp92 = fSlow94 * fTemp83 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec36[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec38 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec39[0] * fSlow186 : 0.0) + ((iSlow92) ? fTemp91 : 0.0));
			fRec41[0] = fTemp29 - (fRec41[1] * fSlow204 + fRec41[2] * fSlow208) / fSlow209;
			double fTemp93 = fSlow72 * fTemp83 * (fConst1 * (fRec41[0] * fSlow206 / fSlow209) + fRec41[2] * fSlow210);
			int iTemp94 = ((iSlow213) ? ((iSlow8) ? iTemp12 : 0) + ((iSlow12) ? iTemp13 : 0) + ((iSlow15) ? iTemp13 : 0) + ((iSlow17) ? iTemp13 : 0) + ((iSlow19) ? iTemp13 : 0) + ((iSlow21) ? iTemp41 : 0) + ((iSlow23) ? iTemp5 : 0) + ((iSlow25) ? iTemp7 : 0) + ((iSlow27) ? iTemp9 : 0) + ((iSlow29) ? iTemp11 : 0) + ((iSlow31) ? iTemp13 : 0) + ((iSlow33) ? iTemp15 : 0) : 0);
			iVec17[0] = iTemp94;
			iRec42[0] = iTemp94 + iRec42[1] * (iVec17[1] >= iTemp94);
			double fTemp95 = double(iRec42[0]);
			iRec43[0] = (iRec43[1] + 1) * (iTemp94 == 0);
			double fTemp96 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp95, std::max<double>(1.0 - fSlow36 * (fTemp95 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec43[0])));
			double fTemp97 = fRec44[1] + fSlow216;
			fRec44[0] = fTemp97 - std::floor(fTemp97);
			double fTemp98 = fRec45[1] + fSlow219;
			double fTemp99 = fTemp98 + -1.0;
			int iTemp100 = fTemp99 < 0.0;
			fRec45[0] = ((iTemp100) ? fTemp98 : fTemp99);
			double fRec46 = ((iTemp100) ? fTemp98 : fTemp98 + fTemp99 * fSlow220);
			double fTemp101 = fRec48[1] + fSlow223;
			fRec48[0] = fTemp101 - std::floor(fTemp101);
			double fTemp102 = scaleIt_faustpower2_f(2.0 * fRec48[0] + -1.0);
			fVec18[0] = fTemp102;
			double fTemp103 = fTemp35 * (fTemp102 - fVec18[1]) / fSlow222;
			fVec19[IOTA0 & 4095] = fTemp103;
			double fTemp104 = fConst27 * (fTemp103 - fVec19[(IOTA0 - iSlow225) & 4095] * fSlow227 - fSlow228 * fVec19[(IOTA0 - iSlow229) & 4095]);
			fRec47[0] = 0.999 * fRec47[1] + fTemp104;
			double fTemp105 = fSlow94 * fTemp96 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec44[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec46 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec47[0] * fSlow215 : 0.0) + ((iSlow92) ? fTemp104 : 0.0));
			fRec49[0] = fTemp29 - (fRec49[1] * fSlow233 + fRec49[2] * fSlow237) / fSlow238;
			double fTemp106 = fSlow72 * fTemp96 * (fConst1 * (fRec49[0] * fSlow235 / fSlow238) + fRec49[2] * fSlow239);
			int iTemp107 = ((iSlow242) ? ((iSlow8) ? iTemp14 : 0) + ((iSlow12) ? iTemp15 : 0) + ((iSlow15) ? iTemp15 : 0) + ((iSlow17) ? iTemp15 : 0) + ((iSlow19) ? iTemp15 : 0) + ((iSlow21) ? iTemp15 : 0) + ((iSlow23) ? iTemp41 : 0) + ((iSlow25) ? iTemp5 : 0) + ((iSlow27) ? iTemp7 : 0) + ((iSlow29) ? iTemp9 : 0) + ((iSlow31) ? iTemp11 : 0) + ((iSlow33) ? iTemp13 : 0) : 0);
			iVec20[0] = iTemp107;
			iRec50[0] = iTemp107 + iRec50[1] * (iVec20[1] >= iTemp107);
			double fTemp108 = double(iRec50[0]);
			iRec51[0] = (iRec51[1] + 1) * (iTemp107 == 0);
			double fTemp109 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp108, std::max<double>(1.0 - fSlow36 * (fTemp108 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec51[0])));
			double fTemp110 = fRec52[1] + fSlow245;
			fRec52[0] = fTemp110 - std::floor(fTemp110);
			double fTemp111 = fRec53[1] + fSlow248;
			double fTemp112 = fTemp111 + -1.0;
			int iTemp113 = fTemp112 < 0.0;
			fRec53[0] = ((iTemp113) ? fTemp111 : fTemp112);
			double fRec54 = ((iTemp113) ? fTemp111 : fTemp111 + fTemp112 * fSlow249);
			double fTemp114 = fRec56[1] + fSlow252;
			fRec56[0] = fTemp114 - std::floor(fTemp114);
			double fTemp115 = scaleIt_faustpower2_f(2.0 * fRec56[0] + -1.0);
			fVec21[0] = fTemp115;
			double fTemp116 = fTemp35 * (fTemp115 - fVec21[1]) / fSlow251;
			fVec22[IOTA0 & 4095] = fTemp116;
			double fTemp117 = fConst27 * (fTemp116 - fVec22[(IOTA0 - iSlow254) & 4095] * fSlow256 - fSlow257 * fVec22[(IOTA0 - iSlow258) & 4095]);
			fRec55[0] = 0.999 * fRec55[1] + fTemp117;
			double fTemp118 = fSlow94 * fTemp109 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec52[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec54 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec55[0] * fSlow244 : 0.0) + ((iSlow92) ? fTemp117 : 0.0));
			fRec57[0] = fTemp29 - (fRec57[1] * fSlow262 + fRec57[2] * fSlow266) / fSlow267;
			double fTemp119 = fSlow72 * fTemp109 * (fConst1 * (fRec57[0] * fSlow264 / fSlow267) + fRec57[2] * fSlow268);
			int iTemp120 = ((iSlow271) ? ((iSlow8) ? iTemp16 : 0) + ((iSlow12) ? iTemp17 : 0) + ((iSlow15) ? iTemp17 : 0) + ((iSlow17) ? iTemp17 : 0) + ((iSlow19) ? iTemp17 : 0) + ((iSlow21) ? iTemp17 : 0) + ((iSlow23) ? iTemp17 : 0) + ((iSlow25) ? iTemp41 : 0) + ((iSlow27) ? iTemp5 : 0) + ((iSlow29) ? iTemp7 : 0) + ((iSlow31) ? iTemp9 : 0) + ((iSlow33) ? iTemp11 : 0) : 0);
			iVec23[0] = iTemp120;
			iRec58[0] = iTemp120 + iRec58[1] * (iVec23[1] >= iTemp120);
			double fTemp121 = double(iRec58[0]);
			iRec59[0] = (iRec59[1] + 1) * (iTemp120 == 0);
			double fTemp122 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp121, std::max<double>(1.0 - fSlow36 * (fTemp121 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec59[0])));
			double fTemp123 = fRec60[1] + fSlow274;
			fRec60[0] = fTemp123 - std::floor(fTemp123);
			double fTemp124 = fRec61[1] + fSlow277;
			double fTemp125 = fTemp124 + -1.0;
			int iTemp126 = fTemp125 < 0.0;
			fRec61[0] = ((iTemp126) ? fTemp124 : fTemp125);
			double fRec62 = ((iTemp126) ? fTemp124 : fTemp124 + fTemp125 * fSlow278);
			double fTemp127 = fRec64[1] + fSlow281;
			fRec64[0] = fTemp127 - std::floor(fTemp127);
			double fTemp128 = scaleIt_faustpower2_f(2.0 * fRec64[0] + -1.0);
			fVec24[0] = fTemp128;
			double fTemp129 = fTemp35 * (fTemp128 - fVec24[1]) / fSlow280;
			fVec25[IOTA0 & 4095] = fTemp129;
			double fTemp130 = fConst27 * (fTemp129 - fVec25[(IOTA0 - iSlow283) & 4095] * fSlow285 - fSlow286 * fVec25[(IOTA0 - iSlow287) & 4095]);
			fRec63[0] = 0.999 * fRec63[1] + fTemp130;
			double fTemp131 = fSlow94 * fTemp122 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec60[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec62 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec63[0] * fSlow273 : 0.0) + ((iSlow92) ? fTemp130 : 0.0));
			fRec65[0] = fTemp29 - (fRec65[1] * fSlow291 + fRec65[2] * fSlow295) / fSlow296;
			double fTemp132 = fSlow72 * fTemp122 * (fConst1 * (fRec65[0] * fSlow293 / fSlow296) + fRec65[2] * fSlow297);
			int iTemp133 = ((iSlow300) ? ((iSlow8) ? iTemp18 : 0) + ((iSlow12) ? iTemp19 : 0) + ((iSlow15) ? iTemp19 : 0) + ((iSlow17) ? iTemp19 : 0) + ((iSlow19) ? iTemp19 : 0) + ((iSlow21) ? iTemp19 : 0) + ((iSlow23) ? iTemp19 : 0) + ((iSlow25) ? iTemp19 : 0) + ((iSlow27) ? iTemp41 : 0) + ((iSlow29) ? iTemp5 : 0) + ((iSlow31) ? iTemp7 : 0) + ((iSlow33) ? iTemp9 : 0) : 0);
			iVec26[0] = iTemp133;
			iRec66[0] = iTemp133 + iRec66[1] * (iVec26[1] >= iTemp133);
			double fTemp134 = double(iRec66[0]);
			iRec67[0] = (iRec67[1] + 1) * (iTemp133 == 0);
			double fTemp135 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp134, std::max<double>(1.0 - fSlow36 * (fTemp134 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec67[0])));
			double fTemp136 = fRec68[1] + fSlow303;
			fRec68[0] = fTemp136 - std::floor(fTemp136);
			double fTemp137 = fRec69[1] + fSlow306;
			double fTemp138 = fTemp137 + -1.0;
			int iTemp139 = fTemp138 < 0.0;
			fRec69[0] = ((iTemp139) ? fTemp137 : fTemp138);
			double fRec70 = ((iTemp139) ? fTemp137 : fTemp137 + fTemp138 * fSlow307);
			double fTemp140 = fRec72[1] + fSlow310;
			fRec72[0] = fTemp140 - std::floor(fTemp140);
			double fTemp141 = scaleIt_faustpower2_f(2.0 * fRec72[0] + -1.0);
			fVec27[0] = fTemp141;
			double fTemp142 = fTemp35 * (fTemp141 - fVec27[1]) / fSlow309;
			fVec28[IOTA0 & 4095] = fTemp142;
			double fTemp143 = fConst27 * (fTemp142 - fVec28[(IOTA0 - iSlow312) & 4095] * fSlow314 - fSlow315 * fVec28[(IOTA0 - iSlow316) & 4095]);
			fRec71[0] = 0.999 * fRec71[1] + fTemp143;
			double fTemp144 = fSlow94 * fTemp135 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec68[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec70 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec71[0] * fSlow302 : 0.0) + ((iSlow92) ? fTemp143 : 0.0));
			fRec73[0] = fTemp29 - (fRec73[1] * fSlow320 + fRec73[2] * fSlow324) / fSlow325;
			double fTemp145 = fSlow72 * fTemp135 * (fConst1 * (fRec73[0] * fSlow322 / fSlow325) + fRec73[2] * fSlow326);
			int iTemp146 = ((iSlow329) ? ((iSlow8) ? iTemp20 : 0) + ((iSlow12) ? iTemp21 : 0) + ((iSlow15) ? iTemp21 : 0) + ((iSlow17) ? iTemp21 : 0) + ((iSlow19) ? iTemp21 : 0) + ((iSlow21) ? iTemp21 : 0) + ((iSlow23) ? iTemp21 : 0) + ((iSlow25) ? iTemp21 : 0) + ((iSlow27) ? iTemp21 : 0) + ((iSlow29) ? iTemp41 : 0) + ((iSlow31) ? iTemp5 : 0) + ((iSlow33) ? iTemp7 : 0) : 0);
			iVec29[0] = iTemp146;
			iRec74[0] = iTemp146 + iRec74[1] * (iVec29[1] >= iTemp146);
			double fTemp147 = double(iRec74[0]);
			iRec75[0] = (iRec75[1] + 1) * (iTemp146 == 0);
			double fTemp148 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp147, std::max<double>(1.0 - fSlow36 * (fTemp147 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec75[0])));
			double fTemp149 = fRec76[1] + fSlow332;
			fRec76[0] = fTemp149 - std::floor(fTemp149);
			double fTemp150 = fRec77[1] + fSlow335;
			double fTemp151 = fTemp150 + -1.0;
			int iTemp152 = fTemp151 < 0.0;
			fRec77[0] = ((iTemp152) ? fTemp150 : fTemp151);
			double fRec78 = ((iTemp152) ? fTemp150 : fTemp150 + fTemp151 * fSlow336);
			double fTemp153 = fRec80[1] + fSlow339;
			fRec80[0] = fTemp153 - std::floor(fTemp153);
			double fTemp154 = scaleIt_faustpower2_f(2.0 * fRec80[0] + -1.0);
			fVec30[0] = fTemp154;
			double fTemp155 = fTemp35 * (fTemp154 - fVec30[1]) / fSlow338;
			fVec31[IOTA0 & 4095] = fTemp155;
			double fTemp156 = fConst27 * (fTemp155 - fVec31[(IOTA0 - iSlow341) & 4095] * fSlow343 - fSlow344 * fVec31[(IOTA0 - iSlow345) & 4095]);
			fRec79[0] = 0.999 * fRec79[1] + fTemp156;
			double fTemp157 = fSlow94 * fTemp148 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec76[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec78 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec79[0] * fSlow331 : 0.0) + ((iSlow92) ? fTemp156 : 0.0));
			fRec81[0] = fTemp29 - (fRec81[1] * fSlow349 + fRec81[2] * fSlow353) / fSlow354;
			double fTemp158 = fSlow72 * fTemp148 * (fConst1 * (fRec81[0] * fSlow351 / fSlow354) + fRec81[2] * fSlow355);
			int iTemp159 = ((iSlow358) ? ((iSlow8) ? iTemp22 : 0) + ((iSlow12) ? iTemp23 : 0) + ((iSlow15) ? iTemp23 : 0) + ((iSlow17) ? iTemp23 : 0) + ((iSlow19) ? iTemp23 : 0) + ((iSlow21) ? iTemp23 : 0) + ((iSlow23) ? iTemp23 : 0) + ((iSlow25) ? iTemp23 : 0) + ((iSlow27) ? iTemp23 : 0) + ((iSlow29) ? iTemp23 : 0) + ((iSlow31) ? iTemp41 : 0) + ((iSlow33) ? iTemp5 : 0) : 0);
			iVec32[0] = iTemp159;
			iRec82[0] = iTemp159 + iRec82[1] * (iVec32[1] >= iTemp159);
			double fTemp160 = double(iRec82[0]);
			iRec83[0] = (iRec83[1] + 1) * (iTemp159 == 0);
			double fTemp161 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp160, std::max<double>(1.0 - fSlow36 * (fTemp160 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec83[0])));
			double fTemp162 = fRec84[1] + fSlow361;
			fRec84[0] = fTemp162 - std::floor(fTemp162);
			double fTemp163 = fRec85[1] + fSlow364;
			double fTemp164 = fTemp163 + -1.0;
			int iTemp165 = fTemp164 < 0.0;
			fRec85[0] = ((iTemp165) ? fTemp163 : fTemp164);
			double fRec86 = ((iTemp165) ? fTemp163 : fTemp163 + fTemp164 * fSlow365);
			double fTemp166 = fRec88[1] + fSlow368;
			fRec88[0] = fTemp166 - std::floor(fTemp166);
			double fTemp167 = scaleIt_faustpower2_f(2.0 * fRec88[0] + -1.0);
			fVec33[0] = fTemp167;
			double fTemp168 = fTemp35 * (fTemp167 - fVec33[1]) / fSlow367;
			fVec34[IOTA0 & 4095] = fTemp168;
			double fTemp169 = fConst27 * (fTemp168 - fVec34[(IOTA0 - iSlow370) & 4095] * fSlow372 - fSlow373 * fVec34[(IOTA0 - iSlow374) & 4095]);
			fRec87[0] = 0.999 * fRec87[1] + fTemp169;
			double fTemp170 = fSlow94 * fTemp161 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec84[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec86 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec87[0] * fSlow360 : 0.0) + ((iSlow92) ? fTemp169 : 0.0));
			fRec89[0] = fTemp29 - (fRec89[1] * fSlow378 + fRec89[2] * fSlow382) / fSlow383;
			double fTemp171 = fSlow72 * fTemp161 * (fConst1 * (fRec89[0] * fSlow380 / fSlow383) + fRec89[2] * fSlow384);
			int iTemp172 = ((iSlow387) ? ((iSlow8) ? iTemp24 : 0) + ((iSlow12) ? iTemp25 : 0) + ((iSlow15) ? iTemp25 : 0) + ((iSlow17) ? iTemp25 : 0) + ((iSlow19) ? iTemp25 : 0) + ((iSlow21) ? iTemp25 : 0) + ((iSlow23) ? iTemp25 : 0) + ((iSlow25) ? iTemp25 : 0) + ((iSlow27) ? iTemp25 : 0) + ((iSlow29) ? iTemp25 : 0) + ((iSlow31) ? iTemp25 : 0) + ((iSlow33) ? iTemp41 : 0) : 0);
			iVec35[0] = iTemp172;
			iRec90[0] = iTemp172 + iRec90[1] * (iVec35[1] >= iTemp172);
			double fTemp173 = double(iRec90[0]);
			iRec91[0] = (iRec91[1] + 1) * (iTemp172 == 0);
			double fTemp174 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp173, std::max<double>(1.0 - fSlow36 * (fTemp173 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec91[0])));
			double fTemp175 = fRec92[1] + fSlow390;
			fRec92[0] = fTemp175 - std::floor(fTemp175);
			double fTemp176 = fRec93[1] + fSlow393;
			double fTemp177 = fTemp176 + -1.0;
			int iTemp178 = fTemp177 < 0.0;
			fRec93[0] = ((iTemp178) ? fTemp176 : fTemp177);
			double fRec94 = ((iTemp178) ? fTemp176 : fTemp176 + fTemp177 * fSlow394);
			double fTemp179 = fRec96[1] + fSlow397;
			fRec96[0] = fTemp179 - std::floor(fTemp179);
			double fTemp180 = scaleIt_faustpower2_f(2.0 * fRec96[0] + -1.0);
			fVec36[0] = fTemp180;
			double fTemp181 = fTemp35 * (fTemp180 - fVec36[1]) / fSlow396;
			fVec37[IOTA0 & 4095] = fTemp181;
			double fTemp182 = fConst27 * (fTemp181 - fVec37[(IOTA0 - iSlow399) & 4095] * fSlow401 - fSlow402 * fVec37[(IOTA0 - iSlow403) & 4095]);
			fRec95[0] = 0.999 * fRec95[1] + fTemp182;
			double fTemp183 = fSlow94 * fTemp174 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec92[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec94 + -1.0 : 0.0) + ((iSlow82) ? fConst26 * fRec95[0] * fSlow389 : 0.0) + ((iSlow92) ? fTemp182 : 0.0));
			fRec97[0] = fTemp29 - (fRec97[1] * fSlow407 + fRec97[2] * fSlow411) / fSlow412;
			double fTemp184 = fSlow72 * fTemp174 * (fConst1 * (fRec97[0] * fSlow409 / fSlow412) + fRec97[2] * fSlow413);
			double fTemp185 = fTemp28 * (fTemp30 + fSlow74 * fTemp40) + fSlow96 * fTemp53 + fTemp54 + fSlow125 * fTemp66 + fTemp67 + fSlow154 * fTemp79 + fTemp80 + fSlow183 * fTemp92 + fTemp93 + fSlow212 * fTemp105 + fTemp106 + fSlow241 * fTemp118 + fTemp119 + fSlow270 * fTemp131 + fTemp132 + fSlow299 * fTemp144 + fTemp145 + fSlow328 * fTemp157 + fTemp158 + fSlow357 * fTemp170 + fTemp171 + fSlow386 * fTemp183 + fTemp184;
			fRec99[0] = fConst208 * std::fabs(0.5 * fTemp185) + fConst207 * fRec99[1];
			fRec98[0] = fConst206 * (0.0 - 0.9666666666666667 * std::max<double>(2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec99[0])) + 7.958800173440752, 0.0)) + fConst205 * fRec98[1];
			double fTemp186 = fTemp185 * std::pow(1e+01, 0.05 * fRec98[0]);
			double fTemp187 = std::fabs(0.5 * fTemp186);
			double fTemp188 = ((fTemp187 > fRec101[1]) ? fConst212 : fConst211);
			fRec101[0] = fTemp187 * (1.0 - fTemp188) + fRec101[1] * fTemp188;
			fRec100[0] = fConst210 * (0.0 - 0.75 * std::max<double>(2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec101[0])) + 6.0, 0.0)) + fConst209 * fRec100[1];
			int iTemp189 = iTemp68 + iTemp55 + iTemp42 + iTemp26 + iTemp172 + iTemp159 + iTemp146 + iTemp133 + iTemp120 + iTemp107 + iTemp81 + iTemp94;
			double fTemp190 = double(iTemp189);
			double fTemp191 = ((iSlow8) ? double(iTemp189 + -1) : fSlow5 + (-1.0 - fTemp190));
			int iTemp192 = fTemp191 == 0.0;
			iVec38[0] = iTemp192;
			iRec102[0] = iTemp192 + iRec102[1] * (iVec38[1] >= iTemp192);
			double fTemp193 = double(iRec102[0]);
			iRec103[0] = (iRec103[1] + 1) * (iTemp192 == 0);
			double fTemp194 = fRec104[1] + fSlow419;
			fRec104[0] = fTemp194 - std::floor(fTemp194);
			double fTemp195 = fRec105[1] + fSlow421;
			double fTemp196 = fTemp195 + -1.0;
			int iTemp197 = fTemp196 < 0.0;
			fRec105[0] = ((iTemp197) ? fTemp195 : fTemp196);
			double fRec106 = ((iTemp197) ? fTemp195 : fTemp195 + fTemp196 * fSlow422);
			double fTemp198 = fRec108[1] + fSlow425;
			fRec108[0] = fTemp198 - std::floor(fTemp198);
			double fTemp199 = scaleIt_faustpower2_f(2.0 * fRec108[0] + -1.0);
			fVec39[0] = fTemp199;
			double fTemp200 = fTemp35 * (fTemp199 - fVec39[1]) / fSlow424;
			fVec40[IOTA0 & 4095] = fTemp200;
			double fTemp201 = fConst27 * (fTemp200 - fVec40[(IOTA0 - iSlow427) & 4095] * fSlow429 - fSlow430 * fVec40[(IOTA0 - iSlow431) & 4095]);
			fRec107[0] = 0.999 * fRec107[1] + fTemp201;
			fRec109[0] = fTemp29 - (fRec109[1] * fSlow435 + fRec109[2] * fSlow439) / fSlow440;
			int iTemp202 = fTemp191 == 2.0;
			iVec41[0] = iTemp202;
			iRec110[0] = iTemp202 + iRec110[1] * (iVec41[1] >= iTemp202);
			double fTemp203 = double(iRec110[0]);
			iRec111[0] = (iRec111[1] + 1) * (iTemp202 == 0);
			double fTemp204 = fRec112[1] + fSlow445;
			fRec112[0] = fTemp204 - std::floor(fTemp204);
			double fTemp205 = fRec113[1] + fSlow447;
			double fTemp206 = fTemp205 + -1.0;
			int iTemp207 = fTemp206 < 0.0;
			fRec113[0] = ((iTemp207) ? fTemp205 : fTemp206);
			double fRec114 = ((iTemp207) ? fTemp205 : fTemp205 + fTemp206 * fSlow448);
			double fTemp208 = fRec116[1] + fSlow451;
			fRec116[0] = fTemp208 - std::floor(fTemp208);
			double fTemp209 = scaleIt_faustpower2_f(2.0 * fRec116[0] + -1.0);
			fVec42[0] = fTemp209;
			double fTemp210 = fTemp35 * (fTemp209 - fVec42[1]) / fSlow450;
			fVec43[IOTA0 & 4095] = fTemp210;
			double fTemp211 = fConst27 * (fTemp210 - fVec43[(IOTA0 - iSlow453) & 4095] * fSlow455 - fSlow456 * fVec43[(IOTA0 - iSlow457) & 4095]);
			fRec115[0] = 0.999 * fRec115[1] + fTemp211;
			fRec117[0] = fTemp29 - (fRec117[1] * fSlow461 + fRec117[2] * fSlow465) / fSlow466;
			int iTemp212 = fTemp191 == 4.0;
			iVec44[0] = iTemp212;
			iRec118[0] = iTemp212 + iRec118[1] * (iVec44[1] >= iTemp212);
			double fTemp213 = double(iRec118[0]);
			iRec119[0] = (iRec119[1] + 1) * (iTemp212 == 0);
			double fTemp214 = fRec120[1] + fSlow471;
			fRec120[0] = fTemp214 - std::floor(fTemp214);
			double fTemp215 = fRec121[1] + fSlow473;
			double fTemp216 = fTemp215 + -1.0;
			int iTemp217 = fTemp216 < 0.0;
			fRec121[0] = ((iTemp217) ? fTemp215 : fTemp216);
			double fRec122 = ((iTemp217) ? fTemp215 : fTemp215 + fTemp216 * fSlow474);
			double fTemp218 = fRec124[1] + fSlow477;
			fRec124[0] = fTemp218 - std::floor(fTemp218);
			double fTemp219 = scaleIt_faustpower2_f(2.0 * fRec124[0] + -1.0);
			fVec45[0] = fTemp219;
			double fTemp220 = fTemp35 * (fTemp219 - fVec45[1]) / fSlow476;
			fVec46[IOTA0 & 4095] = fTemp220;
			double fTemp221 = fConst27 * (fTemp220 - fVec46[(IOTA0 - iSlow479) & 4095] * fSlow481 - fSlow482 * fVec46[(IOTA0 - iSlow483) & 4095]);
			fRec123[0] = 0.999 * fRec123[1] + fTemp221;
			fRec125[0] = fTemp29 - (fRec125[1] * fSlow487 + fRec125[2] * fSlow491) / fSlow492;
			int iTemp222 = fTemp191 == 6.0;
			iVec47[0] = iTemp222;
			iRec126[0] = iTemp222 + iRec126[1] * (iVec47[1] >= iTemp222);
			double fTemp223 = double(iRec126[0]);
			iRec127[0] = (iRec127[1] + 1) * (iTemp222 == 0);
			double fTemp224 = fRec128[1] + fSlow497;
			fRec128[0] = fTemp224 - std::floor(fTemp224);
			double fTemp225 = fRec129[1] + fSlow499;
			double fTemp226 = fTemp225 + -1.0;
			int iTemp227 = fTemp226 < 0.0;
			fRec129[0] = ((iTemp227) ? fTemp225 : fTemp226);
			double fRec130 = ((iTemp227) ? fTemp225 : fTemp225 + fTemp226 * fSlow500);
			double fTemp228 = fRec132[1] + fSlow503;
			fRec132[0] = fTemp228 - std::floor(fTemp228);
			double fTemp229 = scaleIt_faustpower2_f(2.0 * fRec132[0] + -1.0);
			fVec48[0] = fTemp229;
			double fTemp230 = fTemp35 * (fTemp229 - fVec48[1]) / fSlow502;
			fVec49[IOTA0 & 4095] = fTemp230;
			double fTemp231 = fConst27 * (fTemp230 - fVec49[(IOTA0 - iSlow505) & 4095] * fSlow507 - fSlow508 * fVec49[(IOTA0 - iSlow509) & 4095]);
			fRec131[0] = 0.999 * fRec131[1] + fTemp231;
			fRec133[0] = fTemp29 - (fRec133[1] * fSlow513 + fRec133[2] * fSlow517) / fSlow518;
			int iTemp232 = fTemp191 == 8.0;
			iVec50[0] = iTemp232;
			iRec134[0] = iTemp232 + iRec134[1] * (iVec50[1] >= iTemp232);
			double fTemp233 = double(iRec134[0]);
			iRec135[0] = (iRec135[1] + 1) * (iTemp232 == 0);
			double fTemp234 = fRec136[1] + fSlow523;
			fRec136[0] = fTemp234 - std::floor(fTemp234);
			double fTemp235 = fRec137[1] + fSlow525;
			double fTemp236 = fTemp235 + -1.0;
			int iTemp237 = fTemp236 < 0.0;
			fRec137[0] = ((iTemp237) ? fTemp235 : fTemp236);
			double fRec138 = ((iTemp237) ? fTemp235 : fTemp235 + fTemp236 * fSlow526);
			double fTemp238 = fRec140[1] + fSlow529;
			fRec140[0] = fTemp238 - std::floor(fTemp238);
			double fTemp239 = scaleIt_faustpower2_f(2.0 * fRec140[0] + -1.0);
			fVec51[0] = fTemp239;
			double fTemp240 = fTemp35 * (fTemp239 - fVec51[1]) / fSlow528;
			fVec52[IOTA0 & 4095] = fTemp240;
			double fTemp241 = fConst27 * (fTemp240 - fVec52[(IOTA0 - iSlow531) & 4095] * fSlow533 - fSlow534 * fVec52[(IOTA0 - iSlow535) & 4095]);
			fRec139[0] = 0.999 * fRec139[1] + fTemp241;
			fRec141[0] = fTemp29 - (fRec141[1] * fSlow539 + fRec141[2] * fSlow543) / fSlow544;
			int iTemp242 = fTemp191 == 1e+01;
			iVec53[0] = iTemp242;
			iRec142[0] = iTemp242 + iRec142[1] * (iVec53[1] >= iTemp242);
			double fTemp243 = double(iRec142[0]);
			iRec143[0] = (iRec143[1] + 1) * (iTemp242 == 0);
			double fTemp244 = fRec144[1] + fSlow549;
			fRec144[0] = fTemp244 - std::floor(fTemp244);
			double fTemp245 = fRec145[1] + fSlow551;
			double fTemp246 = fTemp245 + -1.0;
			int iTemp247 = fTemp246 < 0.0;
			fRec145[0] = ((iTemp247) ? fTemp245 : fTemp246);
			double fRec146 = ((iTemp247) ? fTemp245 : fTemp245 + fTemp246 * fSlow552);
			double fTemp248 = fRec148[1] + fSlow555;
			fRec148[0] = fTemp248 - std::floor(fTemp248);
			double fTemp249 = scaleIt_faustpower2_f(2.0 * fRec148[0] + -1.0);
			fVec54[0] = fTemp249;
			double fTemp250 = fTemp35 * (fTemp249 - fVec54[1]) / fSlow554;
			fVec55[IOTA0 & 4095] = fTemp250;
			double fTemp251 = fConst27 * (fTemp250 - fVec55[(IOTA0 - iSlow557) & 4095] * fSlow559 - fSlow560 * fVec55[(IOTA0 - iSlow561) & 4095]);
			fRec147[0] = 0.999 * fRec147[1] + fTemp251;
			fRec149[0] = fTemp29 - (fRec149[1] * fSlow565 + fRec149[2] * fSlow569) / fSlow570;
			double fTemp252 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp193, std::max<double>(1.0 - fSlow36 * (fTemp193 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec103[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec104[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec106 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec107[0] * fSlow418 : 0.0) + ((iSlow92) ? fTemp201 : 0.0)) + fSlow72 * (fConst1 * (fRec109[0] * fSlow437 / fSlow440) + fRec109[2] * fSlow441)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp203, std::max<double>(1.0 - fSlow36 * (fTemp203 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec111[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec112[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec114 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec115[0] * fSlow444 : 0.0) + ((iSlow92) ? fTemp211 : 0.0)) + fSlow72 * (fConst1 * (fRec117[0] * fSlow463 / fSlow466) + fRec117[2] * fSlow467)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp213, std::max<double>(1.0 - fSlow36 * (fTemp213 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec119[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec120[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec122 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec123[0] * fSlow470 : 0.0) + ((iSlow92) ? fTemp221 : 0.0)) + fSlow72 * (fConst1 * (fRec125[0] * fSlow489 / fSlow492) + fRec125[2] * fSlow493)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp223, std::max<double>(1.0 - fSlow36 * (fTemp223 - fSlow3), fSlow35)) * (1.0 - fSlow37 * double(iRec127[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec128[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec130 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec131[0] * fSlow496 : 0.0) + ((iSlow92) ? fTemp231 : 0.0)) + fSlow72 * (fConst1 * (fRec133[0] * fSlow515 / fSlow518) + fRec133[2] * fSlow519)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp233, std::max<double>(fSlow36 * (fSlow3 - fTemp233) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec135[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec136[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec138 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec139[0] * fSlow522 : 0.0) + ((iSlow92) ? fTemp241 : 0.0)) + fSlow72 * (fConst1 * (fRec141[0] * fSlow541 / fSlow544) + fRec141[2] * fSlow545)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp243, std::max<double>(fSlow36 * (fSlow3 - fTemp243) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec143[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec144[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec146 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec147[0] * fSlow548 : 0.0) + ((iSlow92) ? fTemp251 : 0.0)) + fSlow72 * (fConst1 * (fRec149[0] * fSlow567 / fSlow570) + fRec149[2] * fSlow571));
			fRec151[0] = fConst208 * std::fabs(fTemp252) + fConst207 * fRec151[1];
			fRec150[0] = fConst206 * (0.0 - 0.9666666666666667 * std::max<double>(2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec151[0])) + 7.958800173440752, 0.0)) + fConst205 * fRec150[1];
			double fTemp253 = fTemp252 * std::pow(1e+01, 0.05 * fRec150[0]);
			double fTemp254 = std::fabs(fTemp253);
			double fTemp255 = ((fTemp254 > fRec153[1]) ? fConst212 : fConst211);
			fRec153[0] = fTemp254 * (1.0 - fTemp255) + fRec153[1] * fTemp255;
			fRec152[0] = fConst210 * (0.0 - 0.75 * std::max<double>(2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec153[0])) + 6.0, 0.0)) + fConst209 * fRec152[1];
			output0[i0] = FAUSTFLOAT(((iTemp2) ? 0.0 : fSlow2 * fTemp186 * std::pow(1e+01, 0.05 * fRec100[0]) + fSlow414 * fTemp253 * std::pow(1e+01, 0.05 * fRec152[0])));
			double fTemp256 = fTemp184 + fTemp171 + fTemp158 + fTemp145 + fTemp132 + fTemp119 + fTemp106 + fTemp93 + fTemp80 + fTemp67 + fTemp54 + fTemp28 * (fTemp30 + fSlow73 * fTemp40) + fSlow95 * fTemp53 + fSlow124 * fTemp66 + fSlow153 * fTemp79 + fSlow182 * fTemp92 + fSlow211 * fTemp105 + fSlow240 * fTemp118 + fSlow269 * fTemp131 + fSlow298 * fTemp144 + fSlow327 * fTemp157 + fSlow356 * fTemp170 + fSlow385 * fTemp183;
			fRec155[0] = fConst208 * std::fabs(0.5 * fTemp256) + fConst207 * fRec155[1];
			fRec154[0] = fConst206 * (0.0 - 0.9666666666666667 * std::max<double>(2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec155[0])) + 7.958800173440752, 0.0)) + fConst205 * fRec154[1];
			double fTemp257 = fTemp256 * std::pow(1e+01, 0.05 * fRec154[0]);
			double fTemp258 = std::fabs(0.5 * fTemp257);
			double fTemp259 = ((fTemp258 > fRec157[1]) ? fConst212 : fConst211);
			fRec157[0] = fTemp258 * (1.0 - fTemp259) + fRec157[1] * fTemp259;
			fRec156[0] = fConst210 * (0.0 - 0.75 * std::max<double>(2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec157[0])) + 6.0, 0.0)) + fConst209 * fRec156[1];
			int iTemp260 = fTemp191 == 1.0;
			iVec56[0] = iTemp260;
			iRec158[0] = iTemp260 + iRec158[1] * (iVec56[1] >= iTemp260);
			double fTemp261 = double(iRec158[0]);
			iRec159[0] = (iRec159[1] + 1) * (iTemp260 == 0);
			double fTemp262 = fRec160[1] + fSlow575;
			fRec160[0] = fTemp262 - std::floor(fTemp262);
			double fTemp263 = fRec161[1] + fSlow577;
			double fTemp264 = fTemp263 + -1.0;
			int iTemp265 = fTemp264 < 0.0;
			fRec161[0] = ((iTemp265) ? fTemp263 : fTemp264);
			double fRec162 = ((iTemp265) ? fTemp263 : fTemp263 + fTemp264 * fSlow578);
			double fTemp266 = fRec164[1] + fSlow581;
			fRec164[0] = fTemp266 - std::floor(fTemp266);
			double fTemp267 = scaleIt_faustpower2_f(2.0 * fRec164[0] + -1.0);
			fVec57[0] = fTemp267;
			double fTemp268 = fTemp35 * (fTemp267 - fVec57[1]) / fSlow580;
			fVec58[IOTA0 & 4095] = fTemp268;
			double fTemp269 = fConst27 * (fTemp268 - fVec58[(IOTA0 - iSlow583) & 4095] * fSlow585 - fSlow586 * fVec58[(IOTA0 - iSlow587) & 4095]);
			fRec163[0] = 0.999 * fRec163[1] + fTemp269;
			fRec165[0] = fTemp29 - (fRec165[1] * fSlow591 + fRec165[2] * fSlow595) / fSlow596;
			int iTemp270 = fTemp191 == 3.0;
			iVec59[0] = iTemp270;
			iRec166[0] = iTemp270 + iRec166[1] * (iVec59[1] >= iTemp270);
			double fTemp271 = double(iRec166[0]);
			iRec167[0] = (iRec167[1] + 1) * (iTemp270 == 0);
			double fTemp272 = fRec168[1] + fSlow601;
			fRec168[0] = fTemp272 - std::floor(fTemp272);
			double fTemp273 = fRec169[1] + fSlow603;
			double fTemp274 = fTemp273 + -1.0;
			int iTemp275 = fTemp274 < 0.0;
			fRec169[0] = ((iTemp275) ? fTemp273 : fTemp274);
			double fRec170 = ((iTemp275) ? fTemp273 : fTemp273 + fTemp274 * fSlow604);
			double fTemp276 = fRec172[1] + fSlow607;
			fRec172[0] = fTemp276 - std::floor(fTemp276);
			double fTemp277 = scaleIt_faustpower2_f(2.0 * fRec172[0] + -1.0);
			fVec60[0] = fTemp277;
			double fTemp278 = fTemp35 * (fTemp277 - fVec60[1]) / fSlow606;
			fVec61[IOTA0 & 4095] = fTemp278;
			double fTemp279 = fConst27 * (fTemp278 - fVec61[(IOTA0 - iSlow609) & 4095] * fSlow611 - fSlow612 * fVec61[(IOTA0 - iSlow613) & 4095]);
			fRec171[0] = 0.999 * fRec171[1] + fTemp279;
			fRec173[0] = fTemp29 - (fRec173[1] * fSlow617 + fRec173[2] * fSlow621) / fSlow622;
			int iTemp280 = fTemp191 == 5.0;
			iVec62[0] = iTemp280;
			iRec174[0] = iTemp280 + iRec174[1] * (iVec62[1] >= iTemp280);
			double fTemp281 = double(iRec174[0]);
			iRec175[0] = (iRec175[1] + 1) * (iTemp280 == 0);
			double fTemp282 = fRec176[1] + fSlow627;
			fRec176[0] = fTemp282 - std::floor(fTemp282);
			double fTemp283 = fRec177[1] + fSlow629;
			double fTemp284 = fTemp283 + -1.0;
			int iTemp285 = fTemp284 < 0.0;
			fRec177[0] = ((iTemp285) ? fTemp283 : fTemp284);
			double fRec178 = ((iTemp285) ? fTemp283 : fTemp283 + fTemp284 * fSlow630);
			double fTemp286 = fRec180[1] + fSlow633;
			fRec180[0] = fTemp286 - std::floor(fTemp286);
			double fTemp287 = scaleIt_faustpower2_f(2.0 * fRec180[0] + -1.0);
			fVec63[0] = fTemp287;
			double fTemp288 = fTemp35 * (fTemp287 - fVec63[1]) / fSlow632;
			fVec64[IOTA0 & 4095] = fTemp288;
			double fTemp289 = fConst27 * (fTemp288 - fVec64[(IOTA0 - iSlow635) & 4095] * fSlow637 - fSlow638 * fVec64[(IOTA0 - iSlow639) & 4095]);
			fRec179[0] = 0.999 * fRec179[1] + fTemp289;
			fRec181[0] = fTemp29 - (fRec181[1] * fSlow643 + fRec181[2] * fSlow647) / fSlow648;
			int iTemp290 = fTemp191 == 7.0;
			iVec65[0] = iTemp290;
			iRec182[0] = iTemp290 + iRec182[1] * (iVec65[1] >= iTemp290);
			double fTemp291 = double(iRec182[0]);
			iRec183[0] = (iRec183[1] + 1) * (iTemp290 == 0);
			double fTemp292 = fRec184[1] + fSlow653;
			fRec184[0] = fTemp292 - std::floor(fTemp292);
			double fTemp293 = fRec185[1] + fSlow655;
			double fTemp294 = fTemp293 + -1.0;
			int iTemp295 = fTemp294 < 0.0;
			fRec185[0] = ((iTemp295) ? fTemp293 : fTemp294);
			double fRec186 = ((iTemp295) ? fTemp293 : fTemp293 + fTemp294 * fSlow656);
			double fTemp296 = fRec188[1] + fSlow659;
			fRec188[0] = fTemp296 - std::floor(fTemp296);
			double fTemp297 = scaleIt_faustpower2_f(2.0 * fRec188[0] + -1.0);
			fVec66[0] = fTemp297;
			double fTemp298 = fTemp35 * (fTemp297 - fVec66[1]) / fSlow658;
			fVec67[IOTA0 & 4095] = fTemp298;
			double fTemp299 = fConst27 * (fTemp298 - fVec67[(IOTA0 - iSlow661) & 4095] * fSlow663 - fSlow664 * fVec67[(IOTA0 - iSlow665) & 4095]);
			fRec187[0] = 0.999 * fRec187[1] + fTemp299;
			fRec189[0] = fTemp29 - (fRec189[1] * fSlow669 + fRec189[2] * fSlow673) / fSlow674;
			int iTemp300 = fTemp191 == 9.0;
			iVec68[0] = iTemp300;
			iRec190[0] = iTemp300 + iRec190[1] * (iVec68[1] >= iTemp300);
			double fTemp301 = double(iRec190[0]);
			iRec191[0] = (iRec191[1] + 1) * (iTemp300 == 0);
			double fTemp302 = fRec192[1] + fSlow679;
			fRec192[0] = fTemp302 - std::floor(fTemp302);
			double fTemp303 = fRec193[1] + fSlow681;
			double fTemp304 = fTemp303 + -1.0;
			int iTemp305 = fTemp304 < 0.0;
			fRec193[0] = ((iTemp305) ? fTemp303 : fTemp304);
			double fRec194 = ((iTemp305) ? fTemp303 : fTemp303 + fTemp304 * fSlow682);
			double fTemp306 = fRec196[1] + fSlow685;
			fRec196[0] = fTemp306 - std::floor(fTemp306);
			double fTemp307 = scaleIt_faustpower2_f(2.0 * fRec196[0] + -1.0);
			fVec69[0] = fTemp307;
			double fTemp308 = fTemp35 * (fTemp307 - fVec69[1]) / fSlow684;
			fVec70[IOTA0 & 4095] = fTemp308;
			double fTemp309 = fConst27 * (fTemp308 - fVec70[(IOTA0 - iSlow687) & 4095] * fSlow689 - fSlow690 * fVec70[(IOTA0 - iSlow691) & 4095]);
			fRec195[0] = 0.999 * fRec195[1] + fTemp309;
			fRec197[0] = fTemp29 - (fRec197[1] * fSlow695 + fRec197[2] * fSlow699) / fSlow700;
			int iTemp310 = fTemp191 == 11.0;
			iVec71[0] = iTemp310;
			iRec198[0] = iTemp310 + iRec198[1] * (iVec71[1] >= iTemp310);
			double fTemp311 = double(iRec198[0]);
			iRec199[0] = (iRec199[1] + 1) * (iTemp310 == 0);
			double fTemp312 = fRec200[1] + fSlow705;
			fRec200[0] = fTemp312 - std::floor(fTemp312);
			double fTemp313 = fRec201[1] + fSlow707;
			double fTemp314 = fTemp313 + -1.0;
			int iTemp315 = fTemp314 < 0.0;
			fRec201[0] = ((iTemp315) ? fTemp313 : fTemp314);
			double fRec202 = ((iTemp315) ? fTemp313 : fTemp313 + fTemp314 * fSlow708);
			double fTemp316 = fRec204[1] + fSlow711;
			fRec204[0] = fTemp316 - std::floor(fTemp316);
			double fTemp317 = scaleIt_faustpower2_f(2.0 * fRec204[0] + -1.0);
			fVec72[0] = fTemp317;
			double fTemp318 = fTemp35 * (fTemp317 - fVec72[1]) / fSlow710;
			fVec73[IOTA0 & 4095] = fTemp318;
			double fTemp319 = fConst27 * (fTemp318 - fVec73[(IOTA0 - iSlow713) & 4095] * fSlow715 - fSlow716 * fVec73[(IOTA0 - iSlow717) & 4095]);
			fRec203[0] = 0.999 * fRec203[1] + fTemp319;
			fRec205[0] = fTemp29 - (fRec205[1] * fSlow721 + fRec205[2] * fSlow725) / fSlow726;
			double fTemp320 = std::max<double>(0.0, std::min<double>(fSlow4 * fTemp261, std::max<double>(fSlow36 * (fSlow3 - fTemp261) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec159[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec160[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec162 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec163[0] * fSlow574 : 0.0) + ((iSlow92) ? fTemp269 : 0.0)) + fSlow72 * (fConst1 * (fRec165[0] * fSlow593 / fSlow596) + fRec165[2] * fSlow597)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp271, std::max<double>(fSlow36 * (fSlow3 - fTemp271) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec167[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec168[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec170 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec171[0] * fSlow600 : 0.0) + ((iSlow92) ? fTemp279 : 0.0)) + fSlow72 * (fConst1 * (fRec173[0] * fSlow619 / fSlow622) + fRec173[2] * fSlow623)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp281, std::max<double>(fSlow36 * (fSlow3 - fTemp281) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec175[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec176[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec178 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec179[0] * fSlow626 : 0.0) + ((iSlow92) ? fTemp289 : 0.0)) + fSlow72 * (fConst1 * (fRec181[0] * fSlow645 / fSlow648) + fRec181[2] * fSlow649)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp291, std::max<double>(fSlow36 * (fSlow3 - fTemp291) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec183[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec184[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec186 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec187[0] * fSlow652 : 0.0) + ((iSlow92) ? fTemp299 : 0.0)) + fSlow72 * (fConst1 * (fRec189[0] * fSlow671 / fSlow674) + fRec189[2] * fSlow675)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp301, std::max<double>(fSlow36 * (fSlow3 - fTemp301) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec191[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec192[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec194 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec195[0] * fSlow678 : 0.0) + ((iSlow92) ? fTemp309 : 0.0)) + fSlow72 * (fConst1 * (fRec197[0] * fSlow697 / fSlow700) + fRec197[2] * fSlow701)) + std::max<double>(0.0, std::min<double>(fSlow4 * fTemp311, std::max<double>(fSlow36 * (fSlow3 - fTemp311) + 1.0, fSlow35)) * (1.0 - fSlow37 * double(iRec199[0]))) * (0.5 * fSlow94 * (((iSlow76) ? ftbl16scaleItSIG16[std::max<int>(0, std::min<int>(int(65536.0 * fRec200[0]), 65535))] : 0.0) + ((iSlow78) ? 2.0 * fRec202 + -1.0 : 0.0) + ((iSlow82) ? fConst213 * fRec203[0] * fSlow704 : 0.0) + ((iSlow92) ? fTemp319 : 0.0)) + fSlow72 * (fConst1 * (fRec205[0] * fSlow723 / fSlow726) + fRec205[2] * fSlow727));
			fRec207[0] = fConst208 * std::fabs(fTemp320) + fConst207 * fRec207[1];
			fRec206[0] = fConst206 * (0.0 - 0.9666666666666667 * std::max<double>(2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec207[0])) + 7.958800173440752, 0.0)) + fConst205 * fRec206[1];
			double fTemp321 = fTemp320 * std::pow(1e+01, 0.05 * fRec206[0]);
			double fTemp322 = std::fabs(fTemp321);
			double fTemp323 = ((fTemp322 > fRec209[1]) ? fConst212 : fConst211);
			fRec209[0] = fTemp322 * (1.0 - fTemp323) + fRec209[1] * fTemp323;
			fRec208[0] = fConst210 * (0.0 - 0.75 * std::max<double>(2e+01 * std::log10(std::max<double>(2.2250738585072014e-308, fRec209[0])) + 6.0, 0.0)) + fConst209 * fRec208[1];
			output1[i0] = FAUSTFLOAT(((iTemp2) ? 0.0 : fSlow2 * fTemp257 * std::pow(1e+01, 0.05 * fRec156[0]) + fSlow414 * fTemp321 * std::pow(1e+01, 0.05 * fRec208[0])));
			double fTemp324 = fSlow728 * double(iTemp26);
			double fTemp325 = fSlow729 * double(iTemp42);
			double fTemp326 = fSlow730 * double(iTemp55);
			double fTemp327 = fSlow731 * double(iTemp68);
			double fTemp328 = fSlow732 * double(iTemp81);
			double fTemp329 = fSlow733 * double(iTemp94);
			double fTemp330 = fSlow734 * double(iTemp107);
			double fTemp331 = fSlow735 * double(iTemp120);
			double fTemp332 = fSlow736 * double(iTemp133);
			double fTemp333 = fSlow737 * double(iTemp146);
			double fTemp334 = fSlow738 * double(iTemp159);
			double fTemp335 = fSlow739 * double(iTemp172);
			output2[i0] = FAUSTFLOAT(((iSlow8) ? std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(std::max<double>(fTemp324, fTemp325), fTemp326), fTemp327), fTemp328), fTemp329), fTemp330), fTemp331), fTemp332), fTemp333), fTemp334), fTemp335) : std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(std::min<double>(fTemp324, fTemp325), fTemp326), fTemp327), fTemp328), fTemp329), fTemp330), fTemp331), fTemp332), fTemp333), fTemp334), fTemp335)));
			double fTemp336 = fSlow13 * fTemp190;
			fHbargraph0 = FAUSTFLOAT(((iSlow11) ? fSlow7 - fTemp336 : fTemp336));
			output3[i0] = FAUSTFLOAT(fHbargraph0);
			iVec0[1] = iVec0[0];
			iVec1[1] = iVec1[0];
			iRec0[1] = iRec0[0];
			iRec1[1] = iRec1[0];
			iRec3[1] = iRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec9[1] = fRec9[0];
			fVec3[1] = fVec3[0];
			IOTA0 = IOTA0 + 1;
			fRec8[1] = fRec8[0];
			iVec5[1] = iVec5[0];
			iRec10[1] = iRec10[0];
			iRec11[1] = iRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec16[1] = fRec16[0];
			fVec6[1] = fVec6[0];
			fRec15[1] = fRec15[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			iVec8[1] = iVec8[0];
			iRec18[1] = iRec18[0];
			iRec19[1] = iRec19[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec24[1] = fRec24[0];
			fVec9[1] = fVec9[0];
			fRec23[1] = fRec23[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			iVec11[1] = iVec11[0];
			iRec26[1] = iRec26[0];
			iRec27[1] = iRec27[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec32[1] = fRec32[0];
			fVec12[1] = fVec12[0];
			fRec31[1] = fRec31[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			iVec14[1] = iVec14[0];
			iRec34[1] = iRec34[0];
			iRec35[1] = iRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec40[1] = fRec40[0];
			fVec15[1] = fVec15[0];
			fRec39[1] = fRec39[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			iVec17[1] = iVec17[0];
			iRec42[1] = iRec42[0];
			iRec43[1] = iRec43[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec48[1] = fRec48[0];
			fVec18[1] = fVec18[0];
			fRec47[1] = fRec47[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			iVec20[1] = iVec20[0];
			iRec50[1] = iRec50[0];
			iRec51[1] = iRec51[0];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			fRec56[1] = fRec56[0];
			fVec21[1] = fVec21[0];
			fRec55[1] = fRec55[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			iVec23[1] = iVec23[0];
			iRec58[1] = iRec58[0];
			iRec59[1] = iRec59[0];
			fRec60[1] = fRec60[0];
			fRec61[1] = fRec61[0];
			fRec64[1] = fRec64[0];
			fVec24[1] = fVec24[0];
			fRec63[1] = fRec63[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			iVec26[1] = iVec26[0];
			iRec66[1] = iRec66[0];
			iRec67[1] = iRec67[0];
			fRec68[1] = fRec68[0];
			fRec69[1] = fRec69[0];
			fRec72[1] = fRec72[0];
			fVec27[1] = fVec27[0];
			fRec71[1] = fRec71[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			iVec29[1] = iVec29[0];
			iRec74[1] = iRec74[0];
			iRec75[1] = iRec75[0];
			fRec76[1] = fRec76[0];
			fRec77[1] = fRec77[0];
			fRec80[1] = fRec80[0];
			fVec30[1] = fVec30[0];
			fRec79[1] = fRec79[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			iVec32[1] = iVec32[0];
			iRec82[1] = iRec82[0];
			iRec83[1] = iRec83[0];
			fRec84[1] = fRec84[0];
			fRec85[1] = fRec85[0];
			fRec88[1] = fRec88[0];
			fVec33[1] = fVec33[0];
			fRec87[1] = fRec87[0];
			fRec89[2] = fRec89[1];
			fRec89[1] = fRec89[0];
			iVec35[1] = iVec35[0];
			iRec90[1] = iRec90[0];
			iRec91[1] = iRec91[0];
			fRec92[1] = fRec92[0];
			fRec93[1] = fRec93[0];
			fRec96[1] = fRec96[0];
			fVec36[1] = fVec36[0];
			fRec95[1] = fRec95[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			iVec38[1] = iVec38[0];
			iRec102[1] = iRec102[0];
			iRec103[1] = iRec103[0];
			fRec104[1] = fRec104[0];
			fRec105[1] = fRec105[0];
			fRec108[1] = fRec108[0];
			fVec39[1] = fVec39[0];
			fRec107[1] = fRec107[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			iVec41[1] = iVec41[0];
			iRec110[1] = iRec110[0];
			iRec111[1] = iRec111[0];
			fRec112[1] = fRec112[0];
			fRec113[1] = fRec113[0];
			fRec116[1] = fRec116[0];
			fVec42[1] = fVec42[0];
			fRec115[1] = fRec115[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			iVec44[1] = iVec44[0];
			iRec118[1] = iRec118[0];
			iRec119[1] = iRec119[0];
			fRec120[1] = fRec120[0];
			fRec121[1] = fRec121[0];
			fRec124[1] = fRec124[0];
			fVec45[1] = fVec45[0];
			fRec123[1] = fRec123[0];
			fRec125[2] = fRec125[1];
			fRec125[1] = fRec125[0];
			iVec47[1] = iVec47[0];
			iRec126[1] = iRec126[0];
			iRec127[1] = iRec127[0];
			fRec128[1] = fRec128[0];
			fRec129[1] = fRec129[0];
			fRec132[1] = fRec132[0];
			fVec48[1] = fVec48[0];
			fRec131[1] = fRec131[0];
			fRec133[2] = fRec133[1];
			fRec133[1] = fRec133[0];
			iVec50[1] = iVec50[0];
			iRec134[1] = iRec134[0];
			iRec135[1] = iRec135[0];
			fRec136[1] = fRec136[0];
			fRec137[1] = fRec137[0];
			fRec140[1] = fRec140[0];
			fVec51[1] = fVec51[0];
			fRec139[1] = fRec139[0];
			fRec141[2] = fRec141[1];
			fRec141[1] = fRec141[0];
			iVec53[1] = iVec53[0];
			iRec142[1] = iRec142[0];
			iRec143[1] = iRec143[0];
			fRec144[1] = fRec144[0];
			fRec145[1] = fRec145[0];
			fRec148[1] = fRec148[0];
			fVec54[1] = fVec54[0];
			fRec147[1] = fRec147[0];
			fRec149[2] = fRec149[1];
			fRec149[1] = fRec149[0];
			fRec151[1] = fRec151[0];
			fRec150[1] = fRec150[0];
			fRec153[1] = fRec153[0];
			fRec152[1] = fRec152[0];
			fRec155[1] = fRec155[0];
			fRec154[1] = fRec154[0];
			fRec157[1] = fRec157[0];
			fRec156[1] = fRec156[0];
			iVec56[1] = iVec56[0];
			iRec158[1] = iRec158[0];
			iRec159[1] = iRec159[0];
			fRec160[1] = fRec160[0];
			fRec161[1] = fRec161[0];
			fRec164[1] = fRec164[0];
			fVec57[1] = fVec57[0];
			fRec163[1] = fRec163[0];
			fRec165[2] = fRec165[1];
			fRec165[1] = fRec165[0];
			iVec59[1] = iVec59[0];
			iRec166[1] = iRec166[0];
			iRec167[1] = iRec167[0];
			fRec168[1] = fRec168[0];
			fRec169[1] = fRec169[0];
			fRec172[1] = fRec172[0];
			fVec60[1] = fVec60[0];
			fRec171[1] = fRec171[0];
			fRec173[2] = fRec173[1];
			fRec173[1] = fRec173[0];
			iVec62[1] = iVec62[0];
			iRec174[1] = iRec174[0];
			iRec175[1] = iRec175[0];
			fRec176[1] = fRec176[0];
			fRec177[1] = fRec177[0];
			fRec180[1] = fRec180[0];
			fVec63[1] = fVec63[0];
			fRec179[1] = fRec179[0];
			fRec181[2] = fRec181[1];
			fRec181[1] = fRec181[0];
			iVec65[1] = iVec65[0];
			iRec182[1] = iRec182[0];
			iRec183[1] = iRec183[0];
			fRec184[1] = fRec184[0];
			fRec185[1] = fRec185[0];
			fRec188[1] = fRec188[0];
			fVec66[1] = fVec66[0];
			fRec187[1] = fRec187[0];
			fRec189[2] = fRec189[1];
			fRec189[1] = fRec189[0];
			iVec68[1] = iVec68[0];
			iRec190[1] = iRec190[0];
			iRec191[1] = iRec191[0];
			fRec192[1] = fRec192[0];
			fRec193[1] = fRec193[0];
			fRec196[1] = fRec196[0];
			fVec69[1] = fVec69[0];
			fRec195[1] = fRec195[0];
			fRec197[2] = fRec197[1];
			fRec197[1] = fRec197[0];
			iVec71[1] = iVec71[0];
			iRec198[1] = iRec198[0];
			iRec199[1] = iRec199[0];
			fRec200[1] = fRec200[0];
			fRec201[1] = fRec201[0];
			fRec204[1] = fRec204[0];
			fVec72[1] = fVec72[0];
			fRec203[1] = fRec203[0];
			fRec205[2] = fRec205[1];
			fRec205[1] = fRec205[0];
			fRec207[1] = fRec207[0];
			fRec206[1] = fRec206[0];
			fRec209[1] = fRec209[0];
			fRec208[1] = fRec208[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "scaleIt.dsp"
	#define FAUST_CLASS_NAME "scaleIt"
	#define FAUST_COMPILATION_OPIONS "-a /opt/homebrew/Cellar/faust/2.54.9/share/faust/max-msp/max-msp64.cpp -lang cpp -i -cn scaleIt -es 1 -mcd 16 -uim -double -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 4
	#define FAUST_ACTIVES 41
	#define FAUST_PASSIVES 1

	FAUST_ADDHORIZONTALBARGRAPH("Threshold:", fHbargraph0, 0.0, 1.0);
	FAUST_ADDNUMENTRY("accordPan0", fEntry14, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan1", fEntry17, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan10", fEntry35, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan11", fEntry37, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan2", fEntry19, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan3", fEntry21, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan4", fEntry23, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan5", fEntry25, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan6", fEntry27, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan7", fEntry29, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan8", fEntry31, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("accordPan9", fEntry33, 0.5, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("activeSteps", fEntry4, 8.0, 0.0, 12.0, 1.0);
	FAUST_ADDNUMENTRY("baseKeyMIDI", fEntry10, 69.0, 0.0, 128.0, 1.0);
	FAUST_ADDNUMENTRY("curve", fEntry6, 0.0, -1e+01, 1e+01, 0.01);
	FAUST_ADDNUMENTRY("customScale0", fEntry12, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale1", fEntry18, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale10", fEntry36, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale11", fEntry38, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale2", fEntry20, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale3", fEntry22, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale4", fEntry24, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale5", fEntry26, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale6", fEntry28, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale7", fEntry30, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale8", fEntry32, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("customScale9", fEntry34, 0.0, 0.0, 48.0, 1.0);
	FAUST_ADDNUMENTRY("envAttack", fEntry3, 0.5, 0.0, 5.0, 0.05);
	FAUST_ADDNUMENTRY("envDecay", fEntry8, 0.0, 0.0, 5.0, 0.05);
	FAUST_ADDNUMENTRY("envRelease", fEntry9, 0.5, 0.0, 5.0, 0.05);
	FAUST_ADDNUMENTRY("envSustain", fEntry7, 1.0, 0.0, 1.0, 0.05);
	FAUST_ADDNUMENTRY("gameAccordON", fEntry2, 0.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("gameToneON", fEntry39, 0.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("invert", fEntry5, 0.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("noiseLevel", fEntry13, 0.0, 0.0, 127.0, 1.0);
	FAUST_ADDNUMENTRY("oscType", fEntry15, 0.0, 0.0, 4.0, 1.0);
	FAUST_ADDNUMENTRY("playAbove", fEntry1, 1.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("playBelow", fEntry0, 1.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("scale", fEntry11, 0.0, 0.0, 15.0, 1.0);
	FAUST_ADDNUMENTRY("scaleDown", fEntry40, 0.0, 0.0, 1.0, 1.0);
	FAUST_ADDNUMENTRY("synthLevel", fEntry16, 64.0, 0.0, 127.0, 1.0);

	#define FAUST_LIST_ACTIVES(p) \
		p(NUMENTRY, accordPan0, "accordPan0", fEntry14, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan1, "accordPan1", fEntry17, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan10, "accordPan10", fEntry35, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan11, "accordPan11", fEntry37, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan2, "accordPan2", fEntry19, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan3, "accordPan3", fEntry21, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan4, "accordPan4", fEntry23, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan5, "accordPan5", fEntry25, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan6, "accordPan6", fEntry27, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan7, "accordPan7", fEntry29, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan8, "accordPan8", fEntry31, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, accordPan9, "accordPan9", fEntry33, 0.5, 0.0, 1.0, 0.05) \
		p(NUMENTRY, activeSteps, "activeSteps", fEntry4, 8.0, 0.0, 12.0, 1.0) \
		p(NUMENTRY, baseKeyMIDI, "baseKeyMIDI", fEntry10, 69.0, 0.0, 128.0, 1.0) \
		p(NUMENTRY, curve, "curve", fEntry6, 0.0, -1e+01, 1e+01, 0.01) \
		p(NUMENTRY, customScale0, "customScale0", fEntry12, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale1, "customScale1", fEntry18, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale10, "customScale10", fEntry36, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale11, "customScale11", fEntry38, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale2, "customScale2", fEntry20, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale3, "customScale3", fEntry22, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale4, "customScale4", fEntry24, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale5, "customScale5", fEntry26, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale6, "customScale6", fEntry28, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale7, "customScale7", fEntry30, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale8, "customScale8", fEntry32, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, customScale9, "customScale9", fEntry34, 0.0, 0.0, 48.0, 1.0) \
		p(NUMENTRY, envAttack, "envAttack", fEntry3, 0.5, 0.0, 5.0, 0.05) \
		p(NUMENTRY, envDecay, "envDecay", fEntry8, 0.0, 0.0, 5.0, 0.05) \
		p(NUMENTRY, envRelease, "envRelease", fEntry9, 0.5, 0.0, 5.0, 0.05) \
		p(NUMENTRY, envSustain, "envSustain", fEntry7, 1.0, 0.0, 1.0, 0.05) \
		p(NUMENTRY, gameAccordON, "gameAccordON", fEntry2, 0.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, gameToneON, "gameToneON", fEntry39, 0.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, invert, "invert", fEntry5, 0.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, noiseLevel, "noiseLevel", fEntry13, 0.0, 0.0, 127.0, 1.0) \
		p(NUMENTRY, oscType, "oscType", fEntry15, 0.0, 0.0, 4.0, 1.0) \
		p(NUMENTRY, playAbove, "playAbove", fEntry1, 1.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, playBelow, "playBelow", fEntry0, 1.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, scale, "scale", fEntry11, 0.0, 0.0, 15.0, 1.0) \
		p(NUMENTRY, scaleDown, "scaleDown", fEntry40, 0.0, 0.0, 1.0, 1.0) \
		p(NUMENTRY, synthLevel, "synthLevel", fEntry16, 64.0, 0.0, 127.0, 1.0) \

	#define FAUST_LIST_PASSIVES(p) \
		p(HORIZONTALBARGRAPH, Threshold:, "Threshold:", fHbargraph0, 0.0, 0.0, 1.0, 0.0) \

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

    std::string getName() { return fProcessFactory->getName(); }
    std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    std::string getCompileOptions() { return fProcessFactory->getCompileOptions(); }
    std::vector<std::string> getLibraryList() { return fProcessFactory->getLibraryList(); }
    std::vector<std::string> getIncludePathnames() { return fProcessFactory->getIncludePathnames(); }
    std::vector<std::string> getWarningMessages() { return fProcessFactory->getWarningMessages(); }
   
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
