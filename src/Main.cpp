/*
 * Copyright (c) 2015 Daniel Hrabovcak
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

#include <QApplication>
#include <QDialog>

#include "PluginManager.hpp"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QDialog dialog;
	dialog.show();

	ide::PluginManager pluginManager;
	pluginManager.join();

	return app.exec();
}
