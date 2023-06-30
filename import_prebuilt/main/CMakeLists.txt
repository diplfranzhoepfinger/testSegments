idf_component_register(SRCS "main.cpp"
                    INCLUDE_DIRS ".")

# Import the library, specifying a target name and the library path.
# The private dependencies of the library is also specified.
add_prebuilt_library(libtestclass "libtestclass.a"
             PRIV_REQUIRES spi_flash app_update log)

# `main` calls a function from the library, so link it to `main`
target_link_libraries(${COMPONENT_LIB} PRIVATE libtestclass)
