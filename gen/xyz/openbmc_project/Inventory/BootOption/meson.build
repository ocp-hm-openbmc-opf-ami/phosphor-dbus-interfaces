# Generated file; do not modify.
generated_sources += custom_target(
    'xyz/openbmc_project/Inventory/BootOption__cpp'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Inventory/BootOption.interface.yaml',  ],
    output: [ 'common.hpp', 'server.cpp', 'server.hpp', 'aserver.hpp', 'client.hpp',  ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'cpp',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Inventory/BootOption',
    ],
)

subdir('BootOptionInstall')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/BootOption/BootOptionInstall__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Inventory/BootOption/BootOptionInstall.interface.yaml',  ],
    output: [ 'BootOptionInstall.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Inventory/BootOption/BootOptionInstall',
    ],
)

subdir('OobUpdatedDatabases')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/BootOption/OobUpdatedDatabases__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Inventory/BootOption/OobUpdatedDatabases.interface.yaml',  ],
    output: [ 'OobUpdatedDatabases.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Inventory/BootOption/OobUpdatedDatabases',
    ],
)

