# Glob all .cpp files in this folder
file(GLOB CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Loop through each .cpp file and create an executable
foreach(cpp_file ${CPP_FILES})
    # Get the filename without the path or extension
    get_filename_component(file_name ${cpp_file} NAME_WE)

    # Create executable for this .cpp file
    add_executable(${feature_name}_${file_name} ${cpp_file})

    # Register it as a test
    add_test(NAME ${feature_name}/${file_name} COMMAND ${feature_name}_${file_name})
endforeach()