# Generated file; do not modify.
subdir('CurrentOperatingConfig')
generated_others += custom_target(
    'xyz/openbmc_project/Control/Processor/CurrentOperatingConfig__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Control/Processor/CurrentOperatingConfig.interface.yaml',  ],
    output: [ 'CurrentOperatingConfig.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Control/Processor/CurrentOperatingConfig',
    ],
)

subdir('ErrConfig')
generated_others += custom_target(
    'xyz/openbmc_project/Control/Processor/ErrConfig__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Control/Processor/ErrConfig.interface.yaml',  ],
    output: [ 'ErrConfig.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Control/Processor/ErrConfig',
    ],
)

