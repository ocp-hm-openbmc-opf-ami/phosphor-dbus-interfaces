# Generated file; do not modify.
subdir('Base')
generated_others += custom_target(
    'xyz/openbmc_project/MCTP/Base__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/MCTP/Base.interface.yaml',  ],
    output: [ 'Base.md' ],
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/MCTP/Base',
    ],
)

subdir('Binding')
subdir('BusOwner')
generated_others += custom_target(
    'xyz/openbmc_project/MCTP/BusOwner__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/MCTP/BusOwner.interface.yaml',  ],
    output: [ 'BusOwner.md' ],
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/MCTP/BusOwner',
    ],
)

subdir('Endpoint')
generated_others += custom_target(
    'xyz/openbmc_project/MCTP/Endpoint__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/MCTP/Endpoint.interface.yaml',  ],
    output: [ 'Endpoint.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/MCTP/Endpoint',
    ],
)

subdir('SupportedMessageTypes')
generated_others += custom_target(
    'xyz/openbmc_project/MCTP/SupportedMessageTypes__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/MCTP/SupportedMessageTypes.interface.yaml',  ],
    output: [ 'SupportedMessageTypes.md' ],
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/MCTP/SupportedMessageTypes',
    ],
)
