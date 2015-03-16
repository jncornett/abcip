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

//-------------------------------------------------------------------------
// raw stuff
//-------------------------------------------------------------------------

#include "cake.h"
#include "raw.h"

static const char* s_type = "raw";

RawProtocol::RawProtocol () : Protocol(s_type) { }

RawProtocol::~RawProtocol () { }

bool RawProtocol::Bind (const string&) {
    return true;
}

const uint8_t* RawProtocol::GetHeader(
    Packet& p, uint32_t& len
) {
    return Protocol::GetHeader(p, len);
    const string& s = p.cake.GetValue("hdr");
    len = s.length();
    return (uint8_t*)s.data();
}

//-------------------------------------------------------------------------

class RawPimp : public Pimp {
public:
    RawPimp() : Pimp(s_type, NULL) { };

    Protocol* New(PseudoHdr*) {
        return new RawProtocol();
    };

    void HelpBind(ostream&);
};

void RawPimp::HelpBind (ostream& out) {
    out << Type() << " -> any" << endl;
}

Pimp* RawProtocol::GetPimp () { return new RawPimp; }

