# Generated file; do not modify.
subdir('WebTwoFactorAuthentication')
generated_others += custom_target(
    'xyz/openbmc_project/TwoFactorAuthentication/WebTwoFactorAuthentication__markdown'.underscorify(),
    input: [ '../../../../yaml/xyz/openbmc_project/TwoFactorAuthentication/WebTwoFactorAuthentication.interface.yaml',  ],
    output: [ 'WebTwoFactorAuthentication.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../yaml',
        'xyz/openbmc_project/TwoFactorAuthentication/WebTwoFactorAuthentication',
    ],
)

