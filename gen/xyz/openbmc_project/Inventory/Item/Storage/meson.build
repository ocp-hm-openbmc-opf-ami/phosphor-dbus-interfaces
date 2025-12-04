# Generated file; do not modify.
generated_sources += custom_target(
    'xyz/openbmc_project/Inventory/Item/Storage__cpp'.underscorify(),
    input: [ '../../../../../../yaml/xyz/openbmc_project/Inventory/Item/Storage.interface.yaml',  ],
    output: [ 'common.hpp', 'server.cpp', 'server.hpp', 'aserver.hpp', 'client.hpp',  ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'cpp',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../../yaml',
        'xyz/openbmc_project/Inventory/Item/Storage',
    ],
)

subdir('Drive')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/Storage/Drive__markdown'.underscorify(),
    input: [ '../../../../../../yaml/xyz/openbmc_project/Inventory/Item/Storage/Drive.interface.yaml',  ],
    output: [ 'Drive.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../../yaml',
        'xyz/openbmc_project/Inventory/Item/Storage/Drive',
    ],
)

subdir('Volume')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/Storage/Volume__markdown'.underscorify(),
    input: [ '../../../../../../yaml/xyz/openbmc_project/Inventory/Item/Storage/Volume.interface.yaml',  ],
    output: [ 'Volume.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../../yaml',
        'xyz/openbmc_project/Inventory/Item/Storage/Volume',
    ],
)

subdir('Controller')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/Storage/Controller__markdown'.underscorify(),
    input: [ '../../../../../../yaml/xyz/openbmc_project/Inventory/Item/Storage/Controller.interface.yaml',  ],
    output: [ 'Controller.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../../yaml',
        'xyz/openbmc_project/Inventory/Item/Storage/Controller',
    ],
)