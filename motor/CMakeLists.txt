add_library(motor
motor.c
)

target_include_directories(motor PUBLIC
	.
)



target_link_libraries(motor
pico_stdlib 
)
