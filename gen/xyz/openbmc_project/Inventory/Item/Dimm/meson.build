# Generated file; do not modify.
generated_sources += custom_target(
    'xyz/openbmc_project/Inventory/Item/Dimm__cpp'.underscorify(),
    input: [ '../../../../../../yaml/xyz/openbmc_project/Inventory/Item/Dimm.interface.yaml',  ],
    output: [ 'common.hpp', 'server.cpp', 'server.hpp', 'aserver.hpp', 'client.hpp',  ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'cpp',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../../yaml',
        'xyz/openbmc_project/Inventory/Item/Dimm',
    ],
)

subdir('MemoryLocation')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/Item/Dimm/MemoryLocation__markdown'.underscorify(),
    input: [ '../../../../../../yaml/xyz/openbmc_project/Inventory/Item/Dimm/MemoryLocation.interface.yaml',  ],
    output: [ 'MemoryLocation.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../../yaml',
        'xyz/openbmc_project/Inventory/Item/Dimm/MemoryLocation',
    ],
)

subdir('MemoryMetrics')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/Item/Dimm/MemoryMetrics__markdown'.underscorify(),
    input: [ '../../../../../../yaml/xyz/openbmc_project/Inventory/Item/Dimm/MemoryMetrics.interface.yaml',  ],
    output: [ 'MemoryMetrics.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../../yaml',
        'xyz/openbmc_project/Inventory/Item/Dimm/MemoryMetrics',
    ],
)

