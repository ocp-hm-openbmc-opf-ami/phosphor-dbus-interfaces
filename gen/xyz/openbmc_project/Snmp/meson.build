# Generated file; do not modify.
subdir('SnmpAgent')
generated_others += custom_target(
    'xyz/openbmc_project/Snmp/SnmpAgent__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/Snmp/SnmpAgent.interface.yaml',  ],
    output: [ 'SnmpAgent.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/Snmp/SnmpAgent',
    ],
)

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

