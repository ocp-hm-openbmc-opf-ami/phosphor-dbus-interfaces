# Generated file; do not modify.
subdir('Manager')

sdbusplus_current_path = 'com/ami/PcieSwMgmt/BrcmAtlas/Ports'

generated_markdown += custom_target(
    'com/ami/PcieSwMgmt/BrcmAtlas/Ports/Manager__markdown'.underscorify(),
    input: [
        '../../../../../../yaml/com/ami/PcieSwMgmt/BrcmAtlas/Ports/Manager.interface.yaml',
    ],
    output: ['Manager.md'],
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
        meson.current_source_dir() / '../../../../../../yaml',
        'com/ami/PcieSwMgmt/BrcmAtlas/Ports/Manager',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

