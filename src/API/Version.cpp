/*
 * Copyright (c) 2014-2015 Daniel Hrabovcak
 *
 * This file is part of Natural IDE.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
**/

#include "Version.hpp"

#include <cstdio>
#include <cinttypes>

#ifdef __MINGW32__
#ifndef SCNu8
#define SCNu8 "hhu"
#endif
#endif

namespace natural
{

Version::Version()
	: major_(0)
	, minor_(0)
	, patch_(0)
{}

Version::Version(uint8_t major, uint8_t minor, uint8_t patch)
	: major_(major)
	, minor_(minor)
	, patch_(patch)
{}

Version::Version(const char *str)
{
	uint8_t major, minor;
	uint16_t patch;
	if (sscanf(str, "%" SCNu8 ".%" SCNu8 ".%" SCNu16,
		&major, &minor, &patch) != 3)
	{
		Version();
		return;
	}
	Version(major, minor, patch);
}

bool Version::compatible(const Version &other)
{
	return (major_ == other.major_ && (minor_ < other.minor_ ||
		(minor_ == other.minor_ && patch_ <= other.patch_)));
}

bool Version::forward_compatible(const Version &other)
{
	return (major_ > other.major_ || compatible(other));
}

Version Version::version()
{
	// Must be in the `.cpp` file, so it is compiled into the shared library.
	return Version(NATURAL_VERSION_MAJOR, NATURAL_VERSION_MINOR,
		NATURAL_VERSION_PATCH);
}

}
