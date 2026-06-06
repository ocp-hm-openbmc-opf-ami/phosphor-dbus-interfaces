# Generated file; do not modify.
subdir('KvmSessionInfo')
subdir('SshSessionInfo')
subdir('VmediaSessionInfo')
subdir('WebSessionInfo')

sdbusplus_current_path = 'xyz/openbmc_project/SessionManager'

generated_markdown += custom_target(
    'xyz/openbmc_project/SessionManager/KvmSessionInfo__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/SessionManager/KvmSessionInfo.interface.yaml',  ],
    output: [ 'KvmSessionInfo.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/SessionManager/KvmSessionInfo',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/SessionManager/SshSessionInfo__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/SessionManager/SshSessionInfo.interface.yaml',  ],
    output: [ 'SshSessionInfo.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/SessionManager/SshSessionInfo',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/SessionManager/VmediaSessionInfo__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/SessionManager/VmediaSessionInfo.interface.yaml',  ],
    output: [ 'VmediaSessionInfo.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/SessionManager/VmediaSessionInfo',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/SessionManager/WebSessionInfo__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/SessionManager/WebSessionInfo.interface.yaml',  ],
    output: [ 'WebSessionInfo.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/SessionManager/WebSessionInfo',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

