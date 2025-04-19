add_library(server-lib STATIC
    src/server.cpp
    src/session.cpp
)

# Публичные заголовки
target_include_directories(server-lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Зависимости
find_package(Boost 1.81 REQUIRED COMPONENTS system)
target_link_libraries(server-lib PUBLIC Boost::system)

# Установка
install(TARGETS server-lib EXPORT NetworkCoreTargets
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)