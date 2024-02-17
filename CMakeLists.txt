cmake_minimum_required(VERSION 3.14)

project(task LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

set(HEADERS
  include/database.hpp
  include/lessondialog.hpp 
  include/window.hpp
  resources/icons.qrc
  include/groupdialog.hpp
  include/lessonvalidator.hpp
  include/studentdialog.hpp
  include/namevalidatior.hpp
  include/markdialog.hpp
  include/groupselectiondialog.hpp
)

set(SOURCES
  src/main.cpp
  src/database.cpp
  src/lessondialog.cpp
  src/window.cpp
  src/groupdialog.cpp
  src/lessonvalidator.cpp
  src/studentdialog.cpp
  src/namevalidatior.cpp
  src/markdialog.cpp
  src/groupselectiondialog.cpp
)

add_executable(task ${HEADERS} ${SOURCES})
target_link_libraries(task Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Sql)

