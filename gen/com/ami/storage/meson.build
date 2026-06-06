# Generated file; do not modify.
subdir('Common')
subdir('HbaBrcm')
subdir('Information')
subdir('RaidBrcm')
subdir('RaidBrcm8')
subdir('RaidMscc')
subdir('brcm8')
subdir('mscc')

sdbusplus_current_path = 'com/ami/storage'

generated_markdown += custom_target(
    'com/ami/storage/Common__markdown'.underscorify(),
    input: [
        '../../../../yaml/com/ami/storage/Common.errors.yaml',
        '../../../../yaml/com/ami/storage/Common.interface.yaml',
    ],
    output: ['Common.md'],
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
        'com/ami/storage/Common',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'com/ami/storage/HbaBrcm__markdown'.underscorify(),
    input: [
        '../../../../yaml/com/ami/storage/HbaBrcm.interface.yaml',
    ],
    output: ['HbaBrcm.md'],
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
        'com/ami/storage/HbaBrcm',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'com/ami/storage/Information__markdown'.underscorify(),
    input: [
        '../../../../yaml/com/ami/storage/Information.interface.yaml',
    ],
    output: ['Information.md'],
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
        'com/ami/storage/Information',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'com/ami/storage/RaidBrcm__markdown'.underscorify(),
    input: [
        '../../../../yaml/com/ami/storage/RaidBrcm.interface.yaml',
    ],
    output: ['RaidBrcm.md'],
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
        'com/ami/storage/RaidBrcm',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'com/ami/storage/RaidBrcm8__markdown'.underscorify(),
    input: [
        '../../../../yaml/com/ami/storage/RaidBrcm8.interface.yaml',
    ],
    output: ['RaidBrcm8.md'],
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
        'com/ami/storage/RaidBrcm8',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

generated_markdown += custom_target(
    'com/ami/storage/RaidMscc__markdown'.underscorify(),
    input: [
        '../../../../yaml/com/ami/storage/RaidMscc.interface.yaml',
    ],
    output: ['RaidMscc.md'],
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
        'com/ami/storage/RaidMscc',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

