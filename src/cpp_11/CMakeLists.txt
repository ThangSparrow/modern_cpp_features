# Glob all subdirectories
file(GLOB FEATURE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/*)

# Loop through all subdirectories
foreach(feature_dir ${FEATURE_DIRS})
    if(IS_DIRECTORY ${feature_dir})
        # Get the name of the feature directory
        get_filename_component(feature_name ${feature_dir} NAME)

        # Add the subdirectory
        add_subdirectory(${feature_dir})
    endif()
endforeach()
