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

#include "Version.hpp"

#include <QString>

namespace natural
{

/*!
 * @ingroup api
 * @brief An interface for plugins.
 */
class Plugin
{
public:

	/*!
	 * @brief Destroys the plugin.
	 *
	 * Thie function should only called when the plugin is detached.
	 */
	virtual ~Plugin();

	/*!
	 * @brief Returns the name of the plugin.
	 *
	 * This function does not return a valid value unless the plugin is
	 * attached.
	 */
	QString plugin_name() const;

	/*!
	 * @brief Returns the description of the plugin.
	 *
	 * This function does not return a valid value unless the plugin is
	 * attached.
	 */
	QString plugin_description() const;

	/*!
	 * @brief Returns the authors of the plugin.
	 *
	 * This function does not return a valid value unless the plugin is
	 * attached.
	 */
	QStringList plugin_authors() const;

	/*!
	 * @brief Returns the version of the plugin.
	 *
	 * This function does not return a valid value unless the plugin is
	 * attached.
	 */
	Version plugin_version() const;

	/*!
	 * @brief Returns true if the plugin is currently attached, false otherwise.
	 *
	 * A plugin is considered attached after the plugin manager requests the
	 * plugin to allocate its data and begin performing actions. If the plugin
	 * is not attached, then it should not perform any actions.
	 */
	bool is_attached() const;

protected:

	/*!
	 * @brief Initializes a plugin.
	 *
	 * Plugins should NOT allocate or initialize their data here. Instead, all
	 * data should be allocated and initialized on the on_attach method.
	*/
	Plugin();

	/*!
	 * @brief Returns the plugin data directory.
	 *
	 * The directory returned here is where the plugin can store its data, such
	 * as user settings. It is recommended that plugins do not store their data
	 * elsewhere but here. Note, that this directory is not the same directory
	 * that the plugin is stored in.
	 *
	 * This function does not return a valid value unless the plugin is
	 * attached.
	 */
	QString directory() const;
};

}
