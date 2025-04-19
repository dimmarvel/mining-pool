add_executable(mining-pool
    src/main.cpp
)

target_link_libraries(mining-pool PRIVATE
    server-lib
)

install(TARGETS mining-pool
    RUNTIME DESTINATION bin
)