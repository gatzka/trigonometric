/*
 * SPDX-License-Identifier: BSL-1.0
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
 * Copyright (c) 2007 John Maddock
 */

#include <math.h>
#include <stdbool.h>

#include "sinpi.h"

static const double pi = 3.141592653589793238462643383279502884e+00;

double sin_pi(double x)
{
	if(x < 0) {
		return -sin_pi(-x);
	}

	bool invert;
	if (x < 0.5) {
		return sin(pi * x);
	}

	if (x < 1) {
		invert = true;
		x = -x;
	} else {
		invert = false;
	}

	double rem = floor(x);
	if (((int)rem) & 1) {
		invert = !invert;
	}

	rem = x - rem;
	if (rem > 0.5) {
		rem = 1.0 - rem;
	}

	if (rem == 0.5) {
		return (double)(invert ? -1.0 : 1.0);
	}

	rem = sin(pi * rem);
	return invert ? (-rem) : rem;
}

