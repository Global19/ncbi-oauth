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

#include <ncbi/json.hpp>
#include <ncbi/jwt.hpp>
#include <ncbi/jws.hpp>
#include <ncbi/jwk.hpp>
#include "base64-priv.hpp"

#include <iostream>

namespace ncbi
{
    HMAC_JWKey * HMAC_JWKey :: make ( const std :: string & kid )
    {
        return new HMAC_JWKey ( kid );
    }

    // get/set symmetric key "k"
    std :: string HMAC_JWKey :: getValue () const
    {
        return props -> getValue ( "k" ) . toString ();
    }

    void HMAC_JWKey :: setValue ( const std :: string & k )
    {
        // TBD - inspect value
        props -> setValueOrDelete ( "k", JSONValue :: makeString ( k ) );
    }

    HMAC_JWKey * HMAC_JWKey :: make ( JSONObject * props )
    {
        // TBD - inspect props for being a proper HMAC JWK
        return new HMAC_JWKey ( props );
    }

    // "kty" = "oct"
    HMAC_JWKey :: HMAC_JWKey ( const std :: string & kid )
        : JWK ( kid, "oct" )
    {
    }

    HMAC_JWKey :: HMAC_JWKey ( JSONObject * props )
        : JWK ( props )
    {
    }

}
