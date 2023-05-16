# Generated file; do not modify.
subdir('NICMgmt')
generated_others += custom_target(
    'com/ami/NICMgmt/NICMgmt__markdown'.underscorify(),
    input: [ '../../../../yaml/com/ami/NICMgmt/NICMgmt.interface.yaml',  ],
    output: [ 'NICMgmt.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'com/ami/NICMgmt/NICMgmt',
    ],
)

