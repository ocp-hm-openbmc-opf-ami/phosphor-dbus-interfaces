# Generated file; do not modify.
subdir('CommunityStrManager')
subdir('SnmpUtils')
subdir('UserManager')

sdbusplus_current_path = 'xyz/openbmc_project/Snmp'

generated_markdown += custom_target(
    'xyz/openbmc_project/Snmp/CommunityStrManager__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/Snmp/CommunityStrManager.interface.yaml',
    ],
    output: ['CommunityStrManager.md'],
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
        'xyz/openbmc_project/Snmp/CommunityStrManager',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/Snmp/SnmpUtils__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/Snmp/SnmpUtils.interface.yaml',
    ],
    output: ['SnmpUtils.md'],
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
        'xyz/openbmc_project/Snmp/SnmpUtils',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/Snmp/UserManager__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/Snmp/UserManager.interface.yaml',
    ],
    output: ['UserManager.md'],
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
        'xyz/openbmc_project/Snmp/UserManager',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

