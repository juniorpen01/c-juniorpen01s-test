file(GLOB_RECURSE sources src/*.c)

add_library(core ${sources})
target_include_directories(core PUBLIC include)
target_compile_options(
	core PUBLIC
	$<$<C_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic -Werror>
	$<$<C_COMPILER_ID:MSVC>:/W4 /WX /permissive->
)

if(BUILD_TESTING)
	file(GLOB_RECURSE testSources tests/*_test.c)
	foreach(testSource IN LISTS testSources)
		cmake_path(GET testSource STEM testSourceName)
		add_executable(${testSourceName} ${testSource})
		target_link_libraries(${testSourceName} PRIVATE core)
		add_test(NAME ${testSourceName} COMMAND ${testSourceName})
	endforeach()
endif()
