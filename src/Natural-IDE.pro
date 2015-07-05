#------------------------------------------------
# Natural IDE - IDE
#------------------------------------------------
#   Build options.
#------------------------------------------------
QT             += core widgets
CONFIG         += c++14
TEMPLATE        = app
MOC_DIR         = app
RCC_DIR         = app
UI_DIR          = app
DESTDIR         = "../bin"
DEFINES        += QT_NO_CAST_FROM_ASCII QT_USE_QSTRINGBUILDER
DEFINES        += NATURAL_PORTABLE
QMAKE_CXXFLAGS += -Werror -fno-exceptions -fno-rtti
#------------------------------------------------
#   Compiler options.
#------------------------------------------------
*clang* { QMAKE_CXXFLAGS += -stdlib=libstdc++ }
#------------------------------------------------
#   Included paths.
#------------------------------------------------
INCLUDEPATH += \
	Manager
#------------------------------------------------
#   Header files.
#------------------------------------------------
HEADERS += \
    Manager/PluginManager.hpp
#------------------------------------------------
#   Source files.
#------------------------------------------------
SOURCES += \
	Main.cpp \
    Manager/PluginManager.cpp
