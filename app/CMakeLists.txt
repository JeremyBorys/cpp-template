
add_executable(template
  main.cpp
)

target_link_libraries(template
  PRIVATE
    CONAN_PKG::fmt
    Template::hello
)
