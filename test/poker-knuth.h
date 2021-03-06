// $Id: poker-knuth.h,v af569101d24e 2009/02/25 15:00:20 oliver $
// Copyright (c) 2008 Oliver Lau <oliver@von-und-fuer-lau.de>
// Alle Rechte vorbehalten.

#ifndef __POKERKNUTH_H_
#define __POKERKNUTH_H_

#include <cstdlib>
#include <cmath>
#include <cassert>
#include <vector>
#include <map>

#include "math_functions.h"
#include "chisq.h"

namespace randomtools {
    
    /// Poker-Test � la Knuth.
    /// @param ran Array mit Zufallszahlen
    /// @param _min kleinstm�glicher Zufallswert
    /// @param _max gr��tm�glicher Zufallswert
    /// @return p-Wert des Chi-Quadrat-Anpassungstests
    template <typename VariateType>
    double poker_test_knuth(const std::vector<VariateType>& ran, const VariateType _min, const VariateType _max)
    {
        assert(_max > _min);
        assert(ran.size() > 100);
        const int k = 5;
        long d = 1L + ((long) _max - (long) _min);
        std::vector<int> histo(5, 0);
        std::vector<int> expected(5);
        double chunkCount = (double) ran.size() / (double) k;
        for (int r = 1; r <= 5; ++r)
        {
            double nominator = (double) d;
            for (long j = d - r + 1; j < d; ++j)
                nominator *= (double) j;
            expected[r-1] = (size_t) (chunkCount * nominator / pow((double) d, (double) k) * stirling<double>(k, r));
        }
        // TODO: Schleife parallelisieren
        for (int i = 0; i < (int) ran.size() - k; i += k)
        {
            std::map<VariateType, int> hand;
            for (int j = 0; j < k; ++j)
                ++hand[ran.at(i+j)];
            ++histo[hand.size()-1];
        }
        double res = ChiSq<int>(histo, expected);
        double p = ChiSquareProbability(res, k-1);
        return p;
    }

};

#endif // __POKER_H_
