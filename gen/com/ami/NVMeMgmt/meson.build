# Generated file; do not modify.
subdir('NVMeMgmt')

sdbusplus_current_path = 'com/ami/NVMeMgmt'

generated_markdown += custom_target(
    'com/ami/NVMeMgmt/NVMeMgmt__markdown'.underscorify(),
    input: [
        '../../../../yaml/com/ami/NVMeMgmt/NVMeMgmt.interface.yaml',
    ],
    output: ['NVMeMgmt.md'],
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
        'com/ami/NVMeMgmt/NVMeMgmt',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

