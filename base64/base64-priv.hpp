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

#ifndef _hpp_ncbi_base64_priv_
#define _hpp_ncbi_base64_priv_

#ifndef _hpp_ncbi_jwp_
#include <ncbi/jwp.hpp>
#endif

#include <string>

namespace ncbi
{
    const std :: string encodeBase64 ( const void * data, size_t bytes, unsigned int line_wrap = 0 );
    const JWPayload decodeBase64 ( const std :: string & encoding, bool allow_whitespace );
    const std :: string decodeBase64String ( const std :: string & encoding, bool allow_whitespace );
    
    const std :: string encodeBase64URL ( const void * data, size_t bytes, unsigned int line_wrap = 0 );
    const JWPayload decodeBase64URL ( const std :: string & encoding, bool allow_whitespace );
    const std :: string decodeBase64URLString ( const std :: string & encoding, bool allow_whitespace );
    
    /*=================================================*
     *                   EXCEPTIONS                    *
     *=================================================*/
    DECLARE_JWX_MSG_EXCEPTION ( B64Exception, JWX );
}

#endif // _hpp_ncbi_base64_priv_
