# Generated file; do not modify.
subdir('I3C')
generated_others += custom_target(
    'xyz/openbmc_project/MCTP/Binding/I3C__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/MCTP/Binding/I3C.interface.yaml',  ],
    output: [ 'I3C.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/MCTP/Binding/I3C',
    ],
)

subdir('PCIe')
generated_others += custom_target(
    'xyz/openbmc_project/MCTP/Binding/PCIe__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/MCTP/Binding/PCIe.interface.yaml',  ],
    output: [ 'PCIe.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/MCTP/Binding/PCIe',
    ],
)

subdir('SMBus')
generated_others += custom_target(
    'xyz/openbmc_project/MCTP/Binding/SMBus__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/MCTP/Binding/SMBus.interface.yaml',  ],
    output: [ 'SMBus.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/MCTP/Binding/SMBus',
    ],
)

