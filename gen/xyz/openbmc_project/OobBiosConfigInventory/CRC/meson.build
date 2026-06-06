# Generated file; do not modify.
subdir('GroupCrc')
subdir('OobCrc')

sdbusplus_current_path = 'xyz/openbmc_project/OobBiosConfigInventory/CRC'

generated_markdown += custom_target(
    'xyz/openbmc_project/OobBiosConfigInventory/CRC/GroupCrc__markdown'.underscorify(),
    input: [
        '../../../../../yaml/xyz/openbmc_project/OobBiosConfigInventory/CRC/GroupCrc.interface.yaml',
    ],
    output: ['GroupCrc.md'],
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
        'xyz/openbmc_project/OobBiosConfigInventory/CRC/GroupCrc',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/OobBiosConfigInventory/CRC/OobCrc__markdown'.underscorify(),
    input: [
        '../../../../../yaml/xyz/openbmc_project/OobBiosConfigInventory/CRC/OobCrc.interface.yaml',
    ],
    output: ['OobCrc.md'],
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
        'xyz/openbmc_project/OobBiosConfigInventory/CRC/OobCrc',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

