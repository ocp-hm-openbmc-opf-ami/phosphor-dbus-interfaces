gtest_dep = dependency('gtest', main: false, disabler: true, required: false)
gmock_dep = dependency('gmock', disabler: true, required: false)

if not (gtest_dep.found() and gmock_dep.found())
    cmake = import('cmake')
    opt_var = cmake.subproject_options()
    opt_var.add_cmake_defines({'CMAKE_CXX_FLAGS': '-Wno-pedantic'})
    opt_var.set_override_option('warning_level', '3')
    opt_var.set_override_option('werror', 'true')

    gtest_proj = cmake.subproject('gtest', options: opt_var, required: true)
    if gtest_proj.found()
        gtest_dep = declare_dependency(
            dependencies: [
                dependency('threads'),
                gtest_proj.dependency('gtest'),
            ],
        )
        gmock_dep = gtest_proj.dependency('gmock')
    else
        assert(
            not get_option('tests').enabled(),
            'Googletest is required if tests are enabled',
        )
    endif
endif

test_deps = [
    gtest_dep,
    gmock_dep,
    phosphor_dbus_interfaces_dep,
]

# Remap build/gen/ → gen_src/ so gcovr sees paths outside build/ and includes them.
test_cpp_args = [
    '-ffile-prefix-map=' + meson.project_build_root() / 'gen' + '=' +
    meson.project_source_root() / 'gen_src',
]

foreach t : [
    ['test_progress',             ['test_main.cpp', 'test_progress.cpp']],
    ['test_uuid',                 ['test_main.cpp', 'test_uuid.cpp']],
    ['test_software_activation',  ['test_main.cpp', 'test_software_activation.cpp']],
    ['test_state_host',           ['test_main.cpp', 'test_state_host.cpp']],
    ['test_state_chassis_bmc',    ['test_main.cpp', 'test_state_chassis_bmc.cpp']],
    ['test_sensor_value',         ['test_main.cpp', 'test_sensor_value.cpp']],
    ['test_led_physical',         ['test_main.cpp', 'test_led_physical.cpp']],
    ['test_control_boot',         ['test_main.cpp', 'test_control_boot.cpp']],
    ['test_misc_interfaces',      ['test_main.cpp', 'test_misc_interfaces.cpp']],
    ['test_inventory_state',      ['test_main.cpp', 'test_inventory_state.cpp']],
]
    test(
        t[0],
        executable(
            t[0],
            t[1],
            dependencies: test_deps,
            cpp_args: test_cpp_args,
        ),
    )
endforeach
