cmake_minimum_required(VERSION 3.10.0)
project(challengehub
    VERSION 0.1.0
    LANGUAGES CXX
)

# 1) Вимога до сучасного стандарту C++:
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD       20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS      OFF)


# 3) Додаємо ваш main.cpp як виконуваний тарґет
add_executable(challengehub main.cpp)


enable_testing()
include(CTest)
