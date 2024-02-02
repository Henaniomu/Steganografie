cmake_minimum_required(VERSION 3.5)
project(stegim LANGUAGES C)

# Указываем флаги компилятора
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -ansi")

# Поиск библиотеки libpng
find_package(PNG REQUIRED)

# Добавляем исполняемый файл и указываем исходные файлы проекта
add_executable(${PROJECT_NAME} 
    src/main.c 
    src/bmp.c
    src/lzw.c
    src/coder.c
    src/png_process.c
)

# Подключаем библиотеку libpng
target_link_libraries(${PROJECT_NAME} PRIVATE PNG::PNG m)

# Включаем директорию с заголовочными файлами библиотеки
target_include_directories(${PROJECT_NAME} PRIVATE ${PNG_INCLUDE_DIRS})
