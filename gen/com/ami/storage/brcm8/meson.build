# Generated file; do not modify.
subdir('Enumerations')
subdir('Management')
subdir('ctrl')

sdbusplus_current_path = 'com/ami/storage/brcm8'

generated_markdown += custom_target(
    'com/ami/storage/brcm8/Enumerations__markdown'.underscorify(),
    input: [
        '../../../../../yaml/com/ami/storage/brcm8/Enumerations.interface.yaml',
    ],
    output: ['Enumerations.md'],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog,
        '--command',
        'markdown',
        '--output',
        meson.current_build_dir(),
        '--tool',
        sdbusplusplus_prog,
        '--directory',
        meson.current_source_dir() / '../../../../../yaml',
        'com/ami/storage/brcm8/Enumerations',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'com/ami/storage/brcm8/Management__markdown'.underscorify(),
    input: [
        '../../../../../yaml/com/ami/storage/brcm8/Management.interface.yaml',
    ],
    output: ['Management.md'],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog,
        '--command',
        'markdown',
        '--output',
        meson.current_build_dir(),
        '--tool',
        sdbusplusplus_prog,
        '--directory',
        meson.current_source_dir() / '../../../../../yaml',
        'com/ami/storage/brcm8/Management',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

