# Generated file; do not modify.
subdir('RedfishPreserve')
subdir('RFPmethod')

sdbusplus_current_path = 'xyz/openbmc_project/RFPreserve'

generated_markdown += custom_target(
    'xyz/openbmc_project/RFPreserve/RedfishPreserve__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/RFPreserve/RedfishPreserve.interface.yaml',
    ],
    output: ['RedfishPreserve.md'],
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
        'xyz/openbmc_project/RFPreserve/RedfishPreserve',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/RFPreserve/RFPmethod__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/RFPreserve/RFPmethod.interface.yaml',
    ],
    output: ['RFPmethod.md'],
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
        'xyz/openbmc_project/RFPreserve/RFPmethod',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

