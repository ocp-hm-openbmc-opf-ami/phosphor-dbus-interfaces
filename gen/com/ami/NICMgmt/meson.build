# Generated file; do not modify.
subdir('NICMgmt')

sdbusplus_current_path = 'com/ami/NICMgmt'

generated_markdown += custom_target(
    'com/ami/NICMgmt/NICMgmt__markdown'.underscorify(),
    input: [
        '../../../../yaml/com/ami/NICMgmt/NICMgmt.interface.yaml',
    ],
    output: ['NICMgmt.md'],
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
        meson.current_source_dir() / '../../../../yaml',
        'com/ami/NICMgmt/NICMgmt',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

