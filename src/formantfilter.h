/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Igor Zinken - https://www.igorski.nl
 *
 * Adapted from public source code by alex@smartelectronix.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __FORMANTFILTER_H_INCLUDED__
#define __FORMANTFILTER_H_INCLUDED__

#include "lfo.h"

namespace Igorski {
class FormantFilter
{
    static const int VOWEL_A = 0;
    static const int VOWEL_E = 1;
    static const int VOWEL_I = 2;
    static const int VOWEL_O = 3;
    static const int VOWEL_U = 4;

    public:
        FormantFilter( float aVowel );
        ~FormantFilter();

        void setVowel( float aVowel );
        float getVowel();
        void setLFO( float LFORatePercentage, float LFODepth );
        void process( float* inBuffer, int bufferSize );

        LFO* lfo;
        bool hasLFO;

        void store();
        void restore();

    private:
        float  _vowel;
        float _tempVowel;
        float _lfoDepth;
        float _lfoRange;
        float _lfoMax;
        float _lfoMin;

        float _currentCoeffs[ 11 ];
        float _coeffs[ 5 ][ 11 ];
        float _memory[ 10 ];
        float _storedMemory[ 10 ];

        void calculateCoeffs();
        void cacheVowel();
        void cacheLFO();
};
}

#endif
