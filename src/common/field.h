//--------------------------------------------------------------------- SOL
// This file is part of abcip, a simple packet crafting tool.
// Copyright (C) 2010-2013 Charles R. Combs
//
// Abcip is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your
// option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//--------------------------------------------------------------------- EOL

#include <iostream>
#include <string>

using namespace std;

#ifndef __FIELD_H__
#define __FIELD_H__

enum FieldType {
    FT_DEF, FT_CFG, FT_PKT, FT_MAX
};

struct Field {
    FieldType use;
    const char* name;
    const char* type;
    const char* help;

    static FieldType GetType(const string& cmd);
    static void Print(ostream&, FieldType, string&, const Field*);

    static bool Validate(const Field*, FieldType,
        const string& var, const string& val);
};

ostream& operator<< (ostream& os, const Field&);

#endif

