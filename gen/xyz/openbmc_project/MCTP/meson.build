# Generated file; do not modify.
subdir('Base')
subdir('Binding')
subdir('BusOwner')
subdir('Endpoint')
subdir('SupportedMessageTypes')
subdir('UUID')

sdbusplus_current_path = 'xyz/openbmc_project/MCTP'

generated_markdown += custom_target(
    'xyz/openbmc_project/MCTP/Base__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/MCTP/Base.interface.yaml',
    ],
    output: ['Base.md'],
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
        'xyz/openbmc_project/MCTP/Base',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/MCTP/BusOwner__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/MCTP/BusOwner.interface.yaml',
    ],
    output: ['BusOwner.md'],
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
        'xyz/openbmc_project/MCTP/BusOwner',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/MCTP/Endpoint__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/MCTP/Endpoint.interface.yaml',
    ],
    output: ['Endpoint.md'],
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
        'xyz/openbmc_project/MCTP/Endpoint',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/MCTP/SupportedMessageTypes__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/MCTP/SupportedMessageTypes.interface.yaml',
    ],
    output: ['SupportedMessageTypes.md'],
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
        'xyz/openbmc_project/MCTP/SupportedMessageTypes',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/MCTP/UUID__markdown'.underscorify(),
    input: [
        '../../../../yaml/xyz/openbmc_project/MCTP/UUID.interface.yaml',
    ],
    output: ['UUID.md'],
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
        'xyz/openbmc_project/MCTP/UUID',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

