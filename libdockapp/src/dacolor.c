/*
 * Copyright (c) 1999-2005 Alfredo K. Kojima, Alban Hertroys
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */

#include "dockapp.h"
#include "daargs.h"
#include "dautil.h"

extern struct DAContext *_daContext;

unsigned long
DAGetColor(char *colorName)
{
    XColor color;

    if (!XParseColor(DADisplay,
		DefaultColormap(DADisplay, DefaultScreen(DADisplay)),
		colorName, &color))
	DAError("could not parse color %s", colorName);

    if (!XAllocColor(DADisplay, DefaultColormap(DADisplay, DefaultScreen(DADisplay)), &color)) {
	DAWarning("could not allocate color %s. Using black instead", colorName);
	return BlackPixel(DADisplay, DefaultScreen(DADisplay));
    }

    return color.pixel;
}

