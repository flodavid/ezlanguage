cmake_minimum_required(VERSION 2.8)

project(ezlanguage)


find_program(MAKE make)
if (MAKE)
	execute_process(COMMAND
		${MAKE}
	)
	# Deuxième version
#	add_custom_command(TARGET schema_data POST_BUILD
#		COMMAND ${MAKE}
#	)

endif()