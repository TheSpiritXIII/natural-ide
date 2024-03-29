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

#include "PluginManager.hpp"

#include <thread>
#include <iostream>

namespace ide
{

void foo()
{
	std::cout << "Yes";
}

PluginManager::PluginManager()
{
	std::thread thread(foo);
	thread.detach();
}

void PluginManager::join()
{

}

}
