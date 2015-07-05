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
#pragma once

#include <cstdint>

#define NATURAL_VERSION_MAJOR 0
#define NATURAL_VERSION_MINOR 1
#define NATURAL_VERSION_PATCH 0

namespace natural
{

/*!
 * @ingroup api
 * @brief Stores a version number.
 */
struct Version
{
	/*!
	 * @brief Constructs an invalid, all zero, version.
	 */
	Version();

	/*!
	 * @brief Constructs a version with the given numbers.
	 */
	Version(uint8_t major, uint8_t minor, uint8_t patch = 0);

	/*!
	 * @brief Constructs a version using the given string.
	 *
	 * The given string must be of format "major.minor.patch". An invalid
	 * format will set a version of 0.0.0.
	 */
	Version(const char *str);

	/*!
	 * @brief The major version number.
	 *
	 * This number indicates an API version. Generally, each different major
	 * number contains its own API, and may or may not be compatible with
	 * previous API versions.
	 */
	inline uint8_t major() const
	{
		return major_;
	}

	/*!
	 * @brief The minor version number.
	 *
	 * This number indicates that an API version is backwards compatible, with
	 * the some possible new forward incompatible features.
	 */
	inline uint8_t minor() const
	{
		return minor_;
	}

	/*!
	 * @brief The patch version number.
	 *
	 * This number indicates that an API version is both forward and background
	 * compatible, with the only changes consisting of bug fixes.
	 */
	inline uint16_t patch() const
	{
		return patch_;
	}

	/*!
	 * @brief Returns true if this version is compatible with the other actual
	 *        version.
	 */
	bool compatible(const Version &other);

	/*!
	 * @brief Returns true if this version is compatible with the other actual
	 *        version, assuming forward compatibility.
	 */
	bool forward_compatible(const Version &other);

	/*!
	 * @brief Returns the program API version.
	 *
	 * Plugins may use this for figuring out which API version the application
	 * was compiled with at run-time.
	 *
	 * For compile-time API version checking, use NATURAL_VERSION_MAJOR,
	 * NATURAL_VERSION_MINOR and NATURAL_VERSION_PATCH.
	 */
	static Version version();

private:
	uint8_t major_;
	uint8_t minor_;
	uint16_t patch_;
};

}
