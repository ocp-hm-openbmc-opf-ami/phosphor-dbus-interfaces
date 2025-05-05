# Generated file; do not modify.
subdir('SnmpUtils')
generated_others += custom_target(
    'xyz/openbmc_project/Snmp/SnmpUtils__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Snmp/SnmpUtils.interface.yaml',  ],
    output: [ 'SnmpUtils.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Snmp/SnmpUtils',
    ],
)

subdir('CommunityStrManager')
generated_others += custom_target(
    'xyz/openbmc_project/Snmp/CommunityStrManager__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Snmp/CommunityStrManager.interface.yaml',  ],
    output: [ 'CommunityStrManager.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Snmp/CommunityStrManager',
    ],
)

subdir('UserManager')
generated_others += custom_target(
    'xyz/openbmc_project/Snmp/UserManager__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Snmp/UserManager.interface.yaml',  ],
    output: [ 'UserManager.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Snmp/UserManager',
    ],
)

