cmake_minimum_required(VERSION 3.4.1)
project(nfutil CXX)

set(CMAKE_DEBUG_POSTFIX _d)

file(GLOB SRC_LIST "src/*.cpp")

# add_library(nfutil STATIC ${SRC_LIST})
# add_library(nfutil_dynamic SHARED ${SRC_LIST})
# set_target_properties(nfutil_dynamic PROPERTIES OUTPUT_NAME "nfutil")

include_directories(include)
include_directories(submodules/spdlog/include)
include_directories(submodules/boolinq/include)

# install(DIRECTORY include DESTINATION /usr/local/include/nfutil)
# install(DIRECTORY submodules/spdlog/include DESTINATION /usr/local/include/spdlog)
# install(DIRECTORY submodules/boolinq/include DESTINATION /usr/local/include/boolinq)
# install(FILES build/libnfutil.a DESTINATION /usr/local/lib)
# install(FILES build/libnfutil.so DESTINATION /usr/local/lib)