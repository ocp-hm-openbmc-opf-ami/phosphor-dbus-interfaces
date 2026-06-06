# Generated file; do not modify.
subdir('I3C')
subdir('PCIe')
subdir('SMBus')

sdbusplus_current_path = 'xyz/openbmc_project/MCTP/Binding'

generated_markdown += custom_target(
    'xyz/openbmc_project/MCTP/Binding/I3C__markdown'.underscorify(),
    input: [
        '../../../../../yaml/xyz/openbmc_project/MCTP/Binding/I3C.interface.yaml',
    ],
    output: ['I3C.md'],
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
        meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/MCTP/Binding/I3C',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/MCTP/Binding/PCIe__markdown'.underscorify(),
    input: [
        '../../../../../yaml/xyz/openbmc_project/MCTP/Binding/PCIe.interface.yaml',
    ],
    output: ['PCIe.md'],
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
        meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/MCTP/Binding/PCIe',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'xyz/openbmc_project/MCTP/Binding/SMBus__markdown'.underscorify(),
    input: [
        '../../../../../yaml/xyz/openbmc_project/MCTP/Binding/SMBus.interface.yaml',
    ],
    output: ['SMBus.md'],
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
        meson.current_source_dir() / '../../../../../yaml',
        'xyz/openbmc_project/MCTP/Binding/SMBus',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

