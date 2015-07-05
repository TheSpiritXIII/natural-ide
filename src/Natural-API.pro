#------------------------------------------------
# Natural IDE - API
#------------------------------------------------
#   Build options.
#------------------------------------------------
QT             += core widgets
CONFIG         += c++14
TEMPLATE        = lib
MOC_DIR         = lib
RCC_DIR         = lib
UI_DIR          = lib
DESTDIR         = "../bin"
DEFINES        += QT_NO_CAST_FROM_ASCII QT_USE_QSTRINGBUILDER
QMAKE_CXXFLAGS += -Werror -fno-exceptions -fno-rtti
#------------------------------------------------
#   Compiler options.
#------------------------------------------------
*clang* { QMAKE_CXXFLAGS += -stdlib=libstdc++ }
#------------------------------------------------
#   Target options.
#------------------------------------------------
!win32:VERSION = 0.0.1
CONFIG(release, debug|release):TARGET = "Natural-API"
CONFIG(debug,   debug|release):TARGET = "Natural-APId"
#------------------------------------------------
#   Included paths.
#------------------------------------------------
INCLUDEPATH += \
	API
#------------------------------------------------
#   Header files.
#------------------------------------------------
HEADERS += \
	API/Plugin.hpp \
    API/Version.hpp
#------------------------------------------------
#   Source files.
#------------------------------------------------
SOURCES += \
	API/Plugin.cpp \
    API/Version.cpp
