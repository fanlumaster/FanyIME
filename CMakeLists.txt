cmake_minimum_required(VERSION 3.0.0)
project(fullkeylogger VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_UNICODE /DUNICODE")

# add_definitions(-DWIN32_LEAN_AND_MEAN)

# 这个是为了在 win32 图形程序中使用
# SET(CMAKE_CXX_STANDARD_LIBRARIES -lmsvcprt.lib)
include_directories(".")
include_directories(include)

# 指定 sqlite 头文件路径
include_directories("./libs/sqlite")

# 指定 sqlite dll 和 lib 文件路径
link_directories("./libs/sqlite")

add_executable(fullkeylogger "main.cpp" "flypytblsqlite.cpp")
set(LIBS sqlite3)
target_link_libraries(fullkeylogger ${LIBS})
