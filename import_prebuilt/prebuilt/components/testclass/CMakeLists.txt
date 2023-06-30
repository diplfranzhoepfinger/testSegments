idf_component_register(SRCS "TestClass.cpp" "stringdict.cpp"
                    INCLUDE_DIRS ".")

# After build, copy the archive file and header file to parent example directory's main component
add_custom_command(TARGET ${COMPONENT_LIB}
                  POST_BUILD
                  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${COMPONENT_LIB}> ${CMAKE_SOURCE_DIR}/../main
                  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/TestClass.h ${CMAKE_SOURCE_DIR}/../main
                  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/stringdict.h ${CMAKE_SOURCE_DIR}/../main
                  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/singlet.h ${CMAKE_SOURCE_DIR}/../main
                  COMMENT "Copying built archive file and header to parent example directory...")
