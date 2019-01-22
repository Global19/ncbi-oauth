/*==============================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 */

#ifndef _hpp_ncbi_memset_priv_
#define _hpp_ncbi_memset_priv_

#include <stddef.h>

namespace ncbi
{
    /**
     * @fn memset_while_respecting_language_semantics
     * @brief what is supposed to be memset_s but isn't always available
     * @param dest pointer to destination block of memory
     * @param dsize the number of bytes pointed to by dest
     * @param ch the byte value to give dest memory
     * @param count the number of bytes to actually set
     * @param str a const char version of dest
     *
     * hopefully this is a memset that doesn't get easily optimized out
     * our wonderful C/C++ stewards have seen proper the introduction of
     * very clever optimizations that unfortunately change the semantics
     * of the language in ways that can be danced around due to the language
     * not having defined behavior with regard to de-allocated memory.
     *
     * the extra parameter "str" should have the same address as "dest"
     * but is passed in so that the compiler can't perform aliasing tricks.
     * it is there for potential examination for proper operation.
     */
    void memset_while_respecting_language_semantics ( void * dest, size_t dsize,
        int ch, size_t count, const char * str );
}

#endif // _hpp_ncbi_memset_priv_
