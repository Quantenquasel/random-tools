// $Id: birthday.h,v 6453a4c3269e 2009/02/25 13:55:36 oliver $
// Copyright (c) 2008 Oliver Lau <oliver@von-und-fuer-lau.de>
// Alle Rechte vorbehalten.

#ifndef __BIRTHDAYSPACINGS_H_
#define __BIRTHDAYSPACINGS_H_

#include <cstdlib>
#include <cassert>
#include <vector>

#include "chisq.h"
#include "bitvector.h"

namespace randomtools {

    /// Birthday Spacings Test.
    /// TODO: Birthday Spacings Test implementieren.
    template <typename VariateType>
    double birthday_spacings_test(const std::vector<VariateType>& ran, const VariateType _min, const VariateType _max)
    {
        assert(_max > _min);
        assert(ran.size() > 100);
        return 0.0;
    }

};

#endif // __BIRTHDAYSPACINGS_H_
