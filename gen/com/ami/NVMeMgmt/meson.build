# Generated file; do not modify.
subdir('NVMeMgmt')
generated_others += custom_target(
    'com/ami/NVMeMgmt/NVMeMgmt__markdown'.underscorify(),
    input: [ '../../../../yaml/com/ami/NVMeMgmt/NVMeMgmt.interface.yaml',  ],
    output: [ 'NVMeMgmt.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'com/ami/NVMeMgmt/NVMeMgmt',
    ],
)

