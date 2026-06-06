# Generated file; do not modify.

sdbusplus_current_path = 'com/ami/PcieSwMgmt/BrcmAtlas/Ports/Manager'

generated_sources += custom_target(
    'com/ami/PcieSwMgmt/BrcmAtlas/Ports/Manager__cpp'.underscorify(),
    input: [
        '../../../../../../../yaml/com/ami/PcieSwMgmt/BrcmAtlas/Ports/Manager.interface.yaml',
    ],
    output: [
        'common.hpp',
        'server.hpp',
        'server.cpp',
        'aserver.hpp',
        'client.hpp',
    ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog,
        '--command',
        'cpp',
        '--output',
        meson.current_build_dir(),
        '--tool',
        sdbusplusplus_prog,
        '--directory',
        meson.current_source_dir() / '../../../../../../../yaml',
        'com/ami/PcieSwMgmt/BrcmAtlas/Ports/Manager',
    ],
    install: should_generate_cpp,
    install_dir: [
        get_option('includedir') / sdbusplus_current_path,
        get_option('includedir') / sdbusplus_current_path,
        false,
        get_option('includedir') / sdbusplus_current_path,
        get_option('includedir') / sdbusplus_current_path,
    ],
    build_by_default: should_generate_cpp,
)

