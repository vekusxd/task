cmake_minimum_required(VERSION 3.14)

project(task LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

add_executable(task
  main.cpp
  database.hpp database.cpp
  lessondialog.hpp lessondialog.cpp
  window.hpp window.cpp
  icons.qrc
  groupdialog.hpp groupdialog.cpp
  lessonvalidator.hpp lessonvalidator.cpp
  studentdialog.hpp studentdialog.cpp
  namevalidatior.hpp namevalidatior.cpp
  markdialog.hpp markdialog.cpp
  groupselectiondialog.hpp groupselectiondialog.cpp
)
target_link_libraries(task Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Sql)

