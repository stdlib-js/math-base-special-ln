/**
* @license Apache-2.0
*
* Copyright (c) 2022 The Stdlib Authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* ## Notice
*
* The following copyright and license were part of the original implementation available as part of [FreeBSD]{@link https://svnweb.freebsd.org/base/release/9.3.0/lib/msun/src/e_log.c}. The implementation follows the original, but has been modified according to project conventions.
*
* ```text
* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
*
* Developed at SunPro, a Sun Microsystems, Inc. business.
* Permission to use, copy, modify, and distribute this
* software is freely granted, provided that this notice
* is preserved.
* ```
*/

#include "stdlib/math/base/special/ln.h"
#include "stdlib/number/float64/base/get_high_word.h"
#include "stdlib/number/float64/base/set_high_word.h"
#include "stdlib/math/base/assert/is_nan.h"
#include "stdlib/constants/float64/ninf.h"
#include "stdlib/constants/float64/exponent_bias.h"
#include <stdint.h>

static const double LN2_HI = 6.93147180369123816490e-01; // 3FE62E42 FEE00000
static const double LN2_LO = 1.90821492927058770002e-10; // 3DEA39EF 35793C76
static const double TWO54 = 1.80143985094819840000e+16;  // 0x43500000, 0x00000000
static const double ONE_THIRD = 0.33333333333333333;

static const double
Lg1 = 6.666666666666735130e-01,  /* 3FE55555 55555593 */
Lg2 = 3.999999999940941908e-01,  /* 3FD99999 9997FA04 */
Lg3 = 2.857142874366239149e-01,  /* 3FD24924 94229359 */
Lg4 = 2.222219843214978396e-01,  /* 3FCC71C5 1D8E78AF */
Lg5 = 1.818357216161805012e-01,  /* 3FC74664 96CB03DE */
Lg6 = 1.531383769920937332e-01,  /* 3FC39A09 D078C69F */
Lg7 = 1.479819860511658591e-01;  /* 3FC2F112 DF3E5244 */

// 0x000fffff = 1048575 => 0 00000000000 11111111111111111111
static const int32_t HIGH_SIGNIFICAND_MASK = 0x000fffff;

// 0x7ff00000 = 2146435072 => 0 11111111111 00000000000000000000 => biased exponent: 2047 = 1023+1023 => 2^1023
static const int32_t HIGH_MAX_NORMAL_EXP = 0x7ff00000;

// 0x00100000 = 1048576 => 0 00000000001 00000000000000000000 => biased exponent: 1 = -1022+1023 => 2^-1022
static const int32_t HIGH_MIN_NORMAL_EXP = 0x00100000;

// 0x3ff00000 = 1072693248 => 0 01111111111 00000000000000000000 => biased exponent: 1023 = 0+1023 => 2^0 = 1
static const int32_t HIGH_BIASED_EXP_0 = 0x3ff00000;

/**
* Evaluates the natural-logarithm.
*
* @param x    input value
* @return     natural logarithm
*
* @example
* double out = stdlib_base_ln( 2.0 );
* // returns ~0.693
*/
double stdlib_base_ln( const double x ) {
	double hfsq;
	uint32_t hx;
	int32_t k;
	int32_t i;
	int32_t j;
	double t1;
	double t2;
	double xc;
	double f;
	double R;
	double s;
	double z;
	double w;

	if ( x == 0.0 ) {
		return STDLIB_CONSTANT_FLOAT64_NINF;
	}
	if ( stdlib_base_is_nan( x ) || x < 0.0 ) {
		return 0.0/0.0; // NaN
	}
	stdlib_base_float64_get_high_word( x, &hx );
	xc = x;
	k = 0;
	if ( hx < HIGH_MIN_NORMAL_EXP ) {
		// Case: 0 < x < 2**-1022
		k -= 54;

		// Subnormal number, scale up `x`:
		xc = x * TWO54;
		stdlib_base_float64_get_high_word( xc, &hx );
	}
	if ( hx >= HIGH_MAX_NORMAL_EXP ) {
		return x + x;
	}
	k += ( ( hx>>20 ) - STDLIB_CONSTANT_FLOAT64_EXPONENT_BIAS );
	hx &= HIGH_SIGNIFICAND_MASK;
	i = ( (hx+0x95f64) & 0x100000 );

	// Normalize `x` or `x/2`...
	stdlib_base_float64_set_high_word( hx|( (i^HIGH_BIASED_EXP_0) ), &xc );
	k += ( i>>20 );
	f = xc - 1.0;
	if ( (HIGH_SIGNIFICAND_MASK&(2+hx)) < 3 ) {
		// Case: -2**-20 <= f < 2**-20
		if ( f == 0.0 ) {
			if ( k == 0 ) {
				return 0.0;
			}
			return (k * LN2_HI) + (k * LN2_LO);
		}
		R = f * f * ( 0.5 - (ONE_THIRD*f) );
		if ( k == 0 ) {
			return f - R;
		}
		return (k * LN2_HI) - ( (R-(k*LN2_LO)) - f );
	}
	s = f / (2.0 + f);
	z = s * s;
	i = ( hx - 0x6147a );
	w = z * z;
	j = ( 0x6b851 - hx );
	t1= w*(Lg2+w*(Lg4+w*Lg6));
	t2= z*(Lg1+w*(Lg3+w*(Lg5+w*Lg7)));
	i |= j;
	R = t2 + t1;
	if ( i > 0 ) {
		hfsq = 0.5 * f * f;
		if ( k == 0 ) {
			return f - ( hfsq - (s * (hfsq+R)) );
		}
		return (k * LN2_HI) - ( hfsq - ((s*(hfsq+R))+(k*LN2_LO)) - f );
	}
	if ( k == 0 ) {
		return f - (s*(f-R));
	}
	return (k * LN2_HI) - ( ( (s*(f-R)) - (k*LN2_LO) ) - f );
}
