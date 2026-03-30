file(GLOB SOURCE_FILES *.cpp)
file(GLOB HEADER_FILES *.h)

add_library(custom_functions STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(custom_functions PUBLIC include)