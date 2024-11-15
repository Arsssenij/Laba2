cmake_minimum_required(VERSION 3.14)
project(GTests) #
enable_testing()

# включает модуль CMake FetchContent, позволяет загружать и распаковывать сторонние проекты в виде подмодулей
include(FetchContent)
# использование модуля FetchContent для объявления подмодуля с именем "googletest"
# URL-адрес указывает зипку репозитория GoogleTest, содержащий версию 609281088cfefc76f9d0ce82e1ff6c30cc3591e5
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip

)
# применяется только для систем Windows и предотвращает переопределение родительских настроек компилятора/линковщика
# настройка gtest_force_shared_crt устанавливается в значение ON
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# делает подмодуль googletest доступным для использования в проекте CMake
# извлекает и распаковывает архив ZIP и создает необходимые зависимости для компиляции и связывания тестов
FetchContent_MakeAvailable(googletest)
# создает список COMMON_SRCS с одним исходным файлом cool.cpp 
# этот файл содержит общий код, который будет использоваться в тестах
set(COMMON_SRCS
    "../ip_filter.cpp"
)
# cоздает исполняемый файл с именем "tests", который будет содержать исходный код из файлов tests.cpp и cool.cpp
add_executable(tests tests.cpp ${COMMON_SRCS})
# устанавливает каталоги включения для исполняемого файла tests
# компилятор будет искать заголовочные файлы в каталоге CMAKE_SOURCE_DIR и его подкаталогах
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR})
# связывает исполняемый файл tests с библиотеками gtest и gtest_main 
# эти библиотеки предоставляют функции для написания и запуска модульных тестов
target_link_libraries(tests PUBLIC gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)