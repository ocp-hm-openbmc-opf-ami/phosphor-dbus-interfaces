# Generated file; do not modify.
subdir('NIC')
generated_others += custom_target(
    'com/ami/NIC/NIC__markdown'.underscorify(),
    input: [ '../../../../yaml/com/ami/NIC/NIC.interface.yaml',  ],
    output: [ 'NIC.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'com/ami/NIC/NIC',
    ],
)

