
add_library(hello
    inc/hello.h
    src/hello.cpp
)

add_library(Template::hello ALIAS hello)

target_include_directories(hello PUBLIC inc)
