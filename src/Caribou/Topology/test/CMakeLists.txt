project(Caribou.Topology.Test)

set(HEADER_FILES
        Grid/Grid_1D.h
        Grid/Grid_2D.h
        Grid/Grid_3D.h
        topology_test.h
)

set(SOURCE_FILES
        Grid/Grid.cpp
        test_barycentric_container.cpp
        test_domain.cpp
        test_mesh.cpp
        main.cpp)

set(MESH_FILES
        meshes/1D_linear.vtk
        meshes/1D_quadratic.vtk
        meshes/2D_quad_linear.vtk
        meshes/2D_quad_quadratic.vtk
        meshes/2D_triangle_linear.vtk
        meshes/2D_triangle_quadratic.vtk
        meshes/3D_hexahedron_linear.vtk
        meshes/3D_hexahedron_quadratic.vtk
        meshes/3D_quad_linear.vtk
        meshes/3D_quad_quadratic.vtk
        meshes/3D_tetrahedron_linear.vtk
        meshes/3D_tetrahedron_quadratic.vtk
        meshes/3D_triangle_linear.vtk
        meshes/3D_triangle_quadratic.vtk
        meshes/deformed_liver_surface.stl
        meshes/deformed_liver_volume_hexahedrons.vtu
        meshes/deformed_liver_volume_tetrahedrons.vtu
)

if (CARIBOU_WITH_VTK)
    list(APPEND SOURCE_FILES test_vtkreader.cpp)
endif()

enable_testing()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} Topology)
target_link_libraries(${PROJECT_NAME} gtest pthread)
foreach(file ${MESH_FILES})
    file(RELATIVE_PATH path_from_package "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
    configure_file("${file}" "${CMAKE_BINARY_DIR}/bin/${path_from_package}" COPYONLY)
endforeach()