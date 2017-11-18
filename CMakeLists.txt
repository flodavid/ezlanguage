cmake_minimum_required(VERSION 2.8)

project(ezlanguage)

set(DEC_CPP src/declarations/Class.cpp src/declarations/Container.cpp src/declarations/Function.cpp
    src/declarations/MultipleVariable.cpp src/declarations/Procedure.cpp src/declarations/Variable.cpp)

set(MOD_CPP src/modules/Node.cpp src/modules/Program.cpp src/modules/TranslatedNode.cpp
src/modules/ArrayAccess.cpp src/modules/BooleanExpr.cpp src/modules/If.cpp src/modules/Operator.cpp
src/modules/ConditionalExpression.cpp src/modules/For.cpp src/modules/Repeat.cpp
src/modules/While.cpp)

set(ADDONS_CPP src/addons/String_addon.cpp src/addons/log.cpp)

set(HT_CPP src/hash_table/HashElement.cpp src/hash_table/HashTable.cpp
src/hash_table/ScopeHashTable.cpp src/hash_table/ClassHashTable.cpp
src/hash_table/ClassHashed.cpp src/hash_table/FunctionHashed.cpp
src/hash_table/VariableHashed.cpp)

set(ezlanguage_SRCS ${DEC_CPP} ${MOD_CPP} ${ADDONS_CPP} ${HT_CPP} src/main.cpp)

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

add_executable(ezlanguage WIN32 ${ezlanguage_SRCS} ${HEADERS})
