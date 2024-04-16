cmake_minimum_required(VERSION 3.12)
project(new_project)

# Source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")
set(SRC_FILES
  ${SRC_DIR}/canvas/canvas.c
  ${SRC_DIR}/canvas/pixel.c
  ${SRC_DIR}/general/linked_list.c
  ${SRC_DIR}/language/ast.c
  ${SRC_DIR}/language/execute.c
  ${SRC_DIR}/language/execute_expression.c
  ${SRC_DIR}/language/execute_shape.c
  ${SRC_DIR}/language/internal_node_type.c
  ${SRC_DIR}/language/symbol.c
  ${SRC_DIR}/language/symbol_table.c
  ${SRC_DIR}/language/token.c
  ${SRC_DIR}/shape/coordinate.c
  ${SRC_DIR}/shape/ellipse.c
  ${SRC_DIR}/shape/line.c
  ${SRC_DIR}/shape/rectangle.c
  ${CMAKE_SOURCE_DIR}/flex/lexer.c
  ${CMAKE_SOURCE_DIR}/bison/parser.tab.c
)

# Include directories
include_directories(
  ${SRC_DIR}
  ${TEST_DIR}
  ${CMAKE_SOURCE_DIR}/bison
)

# Bison
find_package(BISON REQUIRED)
set(BISON_OUTPUT ${CMAKE_SOURCE_DIR}/bison/parser.tab.c)
set(BISON_DEFINES ${CMAKE_SOURCE_DIR}/bison/parser.tab.h)
set(BISON_FLAGS -d)
add_custom_command(
    OUTPUT ${BISON_OUTPUT}
    COMMAND ${BISON_EXECUTABLE}
            ${BISON_FLAGS}
            -o ${BISON_OUTPUT}
            ${CMAKE_SOURCE_DIR}/bison/parser.y
    DEPENDS ${CMAKE_SOURCE_DIR}/bison/parser.y
    COMMENT "Generating Bison source"
)
add_custom_target(bison_target
  DEPENDS ${BISON_OUTPUT}
)

# Flex
find_package(FLEX REQUIRED)
set(FLEX_OUTPUT ${CMAKE_SOURCE_DIR}/flex/lexer.c)
flex_target(Lexer ${CMAKE_SOURCE_DIR}/flex/lexer.l ${FLEX_OUTPUT} DEFINES_FILE
  ${BISON_DEFINES})
add_custom_target(flex_target
  DEPENDS ${FLEX_OUTPUT}
)

# Add executable
add_executable(new_project ${SRC_FILES} ${SRC_DIR}/main/main.c)

# Link libraries
find_package(PNG REQUIRED)
target_link_libraries(new_project PNG::PNG m)

target_compile_options(new_project PRIVATE -Wall -Wextra -g)

# Tests
set(TEST_FILES
    ${TEST_DIR}/shape/ellipse_test.c
    ${TEST_DIR}/shape/line_test.c
    ${TEST_DIR}/shape/rectangle_test.c
)

# Add tests executable
add_executable(tests ${SRC_FILES} ${TEST_FILES} ${TEST_DIR}/main/main.c)

# Set compiler flags for tests target
target_compile_options(tests PRIVATE -Wall -Wextra -g)

# Link libraries for tests
target_link_libraries(tests PNG::PNG m)
