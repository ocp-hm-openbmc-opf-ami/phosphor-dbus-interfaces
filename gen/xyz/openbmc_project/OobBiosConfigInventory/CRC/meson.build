# Generated file; do not modify.
subdir('GroupCrc')
generated_others += custom_target(
    'xyz/openbmc_project/OobBiosConfigInventory/CRC/GroupCrc__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/OobBiosConfigInventory/CRC/GroupCrc.interface.yaml',  ],
    output: [ 'GroupCrc.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/OobBiosConfigInventory/CRC/GroupCrc',
    ],
)

subdir('OobCrc')
generated_others += custom_target(
    'xyz/openbmc_project/OobBiosConfigInventory/CRC/OobCrc__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/OobBiosConfigInventory/CRC/OobCrc.interface.yaml',  ],
    output: [ 'OobCrc.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/OobBiosConfigInventory/CRC/OobCrc',
    ],
)

