# Generated file; do not modify.
generated_sources += custom_target(
    'xyz/openbmc_project/Inventory__cpp'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Inventory.errors.yaml',  ],
    output: [ 'error.cpp', 'error.hpp',  ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'cpp',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Inventory',
    ],
)

subdir('BiosPasswordManager')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/BiosPasswordManager__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Inventory/BiosPasswordManager.interface.yaml',  ],
    output: [ 'BiosPasswordManager.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Inventory/BiosPasswordManager',
    ],
)

subdir('BootOption')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/BootOption__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Inventory/BootOption.interface.yaml',  ],
    output: [ 'BootOption.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Inventory/BootOption',
    ],
)

subdir('Connector')
subdir('Decorator')
subdir('Item')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/Item__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Inventory/Item.interface.yaml',  ],
    output: [ 'Item.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Inventory/Item',
    ],
)

subdir('Manager')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/Manager__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Inventory/Manager.interface.yaml',  ],
    output: [ 'Manager.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Inventory/Manager',
    ],
)

subdir('SecureBoot')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/SecureBoot__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Inventory/SecureBoot.interface.yaml',  ],
    output: [ 'SecureBoot.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Inventory/SecureBoot',
    ],
)

subdir('Source')
