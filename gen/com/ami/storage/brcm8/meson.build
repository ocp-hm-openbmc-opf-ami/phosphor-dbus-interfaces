# Generated file; do not modify.
subdir('Enumerations')
generated_others += custom_target(
    'com/ami/storage/brcm8/Enumerations__markdown'.underscorify(),
    input: [ '../../../../../yaml/com/ami/storage/brcm8/Enumerations.interface.yaml',  ],
    output: [ 'Enumerations.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'com/ami/storage/brcm8/Enumerations',
    ],
)

subdir('ctrl')
