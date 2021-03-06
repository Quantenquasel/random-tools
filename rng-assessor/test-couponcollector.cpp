// $Id$
// Copyright (c) 2008 Oliver Lau <oliver@von-und-fuer-lau.de>
// Alle Rechte vorbehalten.

#include "rng-assessor.h"
#include "test/couponcollector.h"


////////////////////////////////////////////////////////////
/////
///// COUPON COLLECTOR'S TEST
/////
////////////////////////////////////////////////////////////
void test_couponcollector(void)
{
    if (!quiet)
        std::cout << "COUPON COLLECTOR'S TEST" << std::endl;
    for (size_t d = 2; d <= 16; ++d) 
    {
        double p = randomtools::coupon_collector_test<variate_t>(r, d, 20);
        if (!quiet)
            std::cout << " ... " << std::flush
                      << "d = " << std::setw(2) << std::right << d << ": " << std::flush
                      << "p = " << std::setprecision(5) << std::setw(9) << std::left << p << " "
                      << " " << (((alpha < p) && (p < (1-alpha)))? "OK" : "NICHT BESTANDEN")
                      << '.' << std::endl;
    }
    if (!quiet)
        std::cout << std::endl;
}
