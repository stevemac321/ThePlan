
/*==============================================================================
 Name        : assert-h.cpp
 Author      : Stephen MacKenzie
 Copyright   : Licensed under GPL version 2 (GPLv2)
 Abstract    : Conformance Testing to C2x per N2310 draft.

 See README at the root of this project.  libconf.cpp comment header.
==============================================================================*/
#define NDEBUG
#include <assert.h>
#undef NDEBUG
bool Test_7_2()
{
        assert(0);
        return true;
}
