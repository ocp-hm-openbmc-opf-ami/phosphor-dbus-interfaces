# Generated file; do not modify.
generated_sources += custom_target(
    'xyz/openbmc_project/Inventory/SecureBoot__cpp'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Inventory/SecureBoot.interface.yaml',  ],
    output: [ 'common.hpp', 'server.cpp', 'server.hpp', 'aserver.hpp', 'client.hpp',  ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'cpp',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Inventory/SecureBoot',
    ],
)

subdir('SecureBootDatabases')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/SecureBoot/SecureBootDatabases__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Inventory/SecureBoot/SecureBootDatabases.interface.yaml',  ],
    output: [ 'SecureBootDatabases.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Inventory/SecureBoot/SecureBootDatabases',
    ],
)

subdir('SignatureInstall')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/SecureBoot/SignatureInstall__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Inventory/SecureBoot/SignatureInstall.interface.yaml',  ],
    output: [ 'SignatureInstall.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Inventory/SecureBoot/SignatureInstall',
    ],
)

subdir('Signatures')
generated_others += custom_target(
    'xyz/openbmc_project/Inventory/SecureBoot/Signatures__markdown'.underscorify(),
    input: [ '../../../../../yaml/xyz/openbmc_project/Inventory/SecureBoot/Signatures.interface.yaml',  ],
    output: [ 'Signatures.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/Inventory/SecureBoot/Signatures',
    ],
)

