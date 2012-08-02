# Try to find the sqlite library
#  SQLITE_FOUND - system has sqlite
#  SQLITE_INCLUDE_DIR - the sqlite include directory
#  SQLITE_LIBRARY - the sqlite library

FIND_PATH(SQLITE_INCLUDE_DIR NAMES sqlite3.h PATH_SUFFIXES sqlite)
SET(_SQLITE_STATIC_LIBS sqlite3.a)
SET(_SQLITE_SHARED_LIBS sqlite3)
IF(USE_STATIC_LIBS)
    FIND_LIBRARY(SQLITE_LIBRARY NAMES ${_SQLITE_STATIC_LIBS} ${_SQLITE_SHARED_LIBS})
ELSE()
    FIND_LIBRARY(SQLITE_LIBRARY NAMES ${_SQLITE_SHARED_LIBS} ${_SQLITE_STATIC_LIBS})
ENDIF()
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SQLite DEFAULT_MSG SQLITE_LIBRARY SQLITE_INCLUDE_DIR)
MARK_AS_ADVANCED(SQLITE_LIBRARY SQLITE_INCLUDE_DIR)