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

#include <mutex>

namespace ide
{

/*!
 * @brief Loads and executes plugins.
 */
class PluginManager
{
public:

	/*!
	 * @brief Finds and load plugin metadata.
	 *
	 * This function starts a new thread to do work in. join() must be called
	 * directly after this function in order to load all external plugins.
	 */
	PluginManager();

	/*!
	 * @brief Blocks the current thread execution until all plugins are
	 *        initialized.
	 *
	 * This function is only used for checking if the initial plugins were
	 * finished loading.
	 */
	void join();

private:

	void load_all();

	std::mutex mutex_;
};

}
