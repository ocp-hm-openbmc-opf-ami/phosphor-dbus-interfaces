# Generated file; do not modify.
subdir('Management')
generated_others += custom_target(
    'com/ami/storage/mscc/Management__markdown'.underscorify(),
    input: [ '../../../../../yaml/com/ami/storage/mscc/Management.interface.yaml',  ],
    output: [ 'Management.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'com/ami/storage/mscc/Management',
    ],
)

subdir('ctrl')
