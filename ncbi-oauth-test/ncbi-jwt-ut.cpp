//
//  ncbi-jwt-ut.cpp
//  ncbi-oauth-test
//
//  Created by User on 7/30/18.
//  Copyright © 2018 NCBI. All rights reserved.
//

#include "gtest/gtest.h"
#include <ncbi/jwt.hpp>

#include <iostream>

namespace ncbi
{
    /* JWT
     *
     **********************************************************************************/
    class JWTFixture_BasicConstruction : public :: testing :: Test
    {
    public:
        void SetUp ()
        {
            jwt_fact . setIssuer ( "ncbi" );
            jwt_fact . setDuration ( 15 );
        }
        
        void TearDown ()
        {
        }
        
    protected:
        JWTFactory jwt_fact;
    };
   
    /*
    TEST_F ( JWTFixture_BasicConstruction, JWT_Parse_Member )
    {
    }
     */

} // namespace
