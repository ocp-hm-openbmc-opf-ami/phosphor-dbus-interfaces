# Generated file; do not modify.
subdir('Common')
generated_others += custom_target(
    'com/ami/storage/Common__markdown'.underscorify(),
    input: [ '../../../../yaml/com/ami/storage/Common.errors.yaml',  ],
    output: [ 'Common.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'com/ami/storage/Common',
    ],
)

subdir('Information')
generated_others += custom_target(
    'com/ami/storage/Information__markdown'.underscorify(),
    input: [ '../../../../yaml/com/ami/storage/Information.interface.yaml',  ],
    output: [ 'Information.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'com/ami/storage/Information',
    ],
)

subdir('RaidMscc')
generated_others += custom_target(
    'com/ami/storage/RaidMscc__markdown'.underscorify(),
    input: [ '../../../../yaml/com/ami/storage/RaidMscc.interface.yaml',  ],
    output: [ 'RaidMscc.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'com/ami/storage/RaidMscc',
    ],
)

subdir('brcm')
subdir('mscc')
