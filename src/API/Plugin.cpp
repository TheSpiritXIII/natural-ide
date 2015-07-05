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

#include "Plugin.hpp"

#include <cassert>

#include <QStringList>

namespace natural
{

Plugin::Plugin()
{

}

Plugin::~Plugin()
{
	assert(!is_attached());
}

QString Plugin::plugin_name() const
{
	return QString();
}

QString Plugin::plugin_description() const
{
	return QString();
}

QStringList Plugin::plugin_authors() const
{
	return QStringList();
}

Version Plugin::plugin_version() const
{
	return Version();
}

bool Plugin::is_attached() const
{
	return false;
}

}
