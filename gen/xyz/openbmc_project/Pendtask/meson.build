# Generated file; do not modify.
subdir('pef')
generated_others += custom_target(
    'xyz/openbmc_project/Pendtask/pef__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Pendtask/pef.interface.yaml',  ],
    output: [ 'pef.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Pendtask/pef',
    ],
)

