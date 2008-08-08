/*
Open Asset Import Library (ASSIMP)
----------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team
All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the 
following conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/

/** @file Definition of platform independent string comparison functions */
#ifndef AI_STRINGCOMPARISON_H_INC
#define AI_STRINGCOMPARISON_H_INC


namespace Assimp
{

// ---------------------------------------------------------------------------
/** \brief Helper function to do platform independent string comparison.
 *
 *  This is required since stricmp() is not consistently available on
 *  all platforms. Some platforms use the '_' prefix, others don't even
 *  have such a function. Yes, this is called an ISO standard.
 *
 *  \param s1 First input string
 *  \param s2 Second input string
 */
// ---------------------------------------------------------------------------
inline int ASSIMP_stricmp(const char *s1, const char *s2)
{
#if (defined _MSC_VER)

	return ::_stricmp(s1,s2);

#else
	const char *a1, *a2;
	a1 = s1;
	a2 = s2;

	while (true)
	{
		char c1 = (char)::tolower(*a1); 
		char c2 = (char)::tolower(*a2);
		if ((0 == c1) && (0 == c2)) return 0;
		if (c1 < c2) return-1;
		if (c1 > c2) return 1;
		++a1; 
		++a2;
	}
#endif
}

// ---------------------------------------------------------------------------
/** \brief Helper function to do platform independent string comparison.
 *
 *  This is required since strincmp() is not consistently available on
 *  all platforms. Some platforms use the '_' prefix, others don't even
 *  have such a function. Yes, this is called an ISO standard.
 *
 *  \param s1 First input string
 *  \param s2 Second input string
 *  \param n Macimum number of characters to compare
 */
// ---------------------------------------------------------------------------
inline int ASSIMP_strincmp(const char *s1, const char *s2, unsigned int n)
{
#if (defined _MSC_VER)

	return ::_strnicmp(s1,s2,n);

#else
	const char *a1, *a2;
	a1 = s1;
	a2 = s2;

	unsigned int p = 0;

	while (true)
	{
		if (p >= n)return 0;

		char c1 = (char)::tolower(*a1); 
		char c2 = (char)::tolower(*a2);
		if ((0 == c1) && (0 == c2)) return 0;
		if (c1 < c2) return-1;
		if (c1 > c2) return 1;
		++a1; 
		++a2;
		++p;
	}
#endif
}
};

#endif // !  AI_STRINGCOMPARISON_H_INC