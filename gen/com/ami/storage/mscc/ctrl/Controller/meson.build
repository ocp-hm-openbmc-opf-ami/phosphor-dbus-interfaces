# Generated file; do not modify.
generated_sources += custom_target(
    'com/ami/storage/mscc/ctrl/Controller__cpp'.underscorify(),
    input: [ '../../../../../../../yaml/com/ami/storage/mscc/ctrl/Controller.interface.yaml',  ],
    output: [ 'common.hpp', 'server.cpp', 'server.hpp', 'client.hpp',  ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'cpp',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../../../../../../yaml',
        'com/ami/storage/mscc/ctrl/Controller',
    ],
)

