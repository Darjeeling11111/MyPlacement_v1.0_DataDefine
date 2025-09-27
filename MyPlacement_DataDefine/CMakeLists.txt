# cmake needs this line
cmake_minimum_required(VERSION 3.5)

# Define project name
project(Darjeeling_placement VERSION 1.0.0 LANGUAGES CXX)
set(bookshelf_lib_name Darjeeling_BookShelfParser)
set(Darjeeling_test_name Darjeeling_test)


add_library(${bookshelf_lib_name} SHARED 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BookShelfParser/BookshelfParserStarter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BookShelfParser/BookshelfParser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pojo/IPojo/IModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pojo/DO/SiteRowDO.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pojo/Module.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pojo/PlaceData.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pojo/Pin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pojo/Net.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pojo/SiteRow.cpp
)

# Declare the executable target built from your sources
add_executable(
    ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/myplace_main.cpp
)
add_executable(
    ${Darjeeling_test_name}
    ${CMAKE_SOURCE_DIR}/test/test01.cpp
)

target_include_directories(${bookshelf_lib_name} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Common
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Enum
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo/DO
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo/IPojo
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/BookShelfParser
)
target_link_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Common
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Enum
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo/DO
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo/IPojo
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/BookShelfParser
)
target_link_directories(${Darjeeling_test_name} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Common
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Enum
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo/DO
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/Pojo/IPojo
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/MyPlacement_DataDefine/BookShelfParser
)
#target_link_libraries(myplace "-lm -ldl -lX11")
target_link_libraries(${PROJECT_NAME} PUBLIC ${bookshelf_lib_name})
target_link_libraries(${Darjeeling_test_name} PUBLIC ${bookshelf_lib_name})