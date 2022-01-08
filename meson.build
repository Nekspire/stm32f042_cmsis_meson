project('stm32f042_cmsis_meson', 'c')

# global variables tracking sources and includes
c_args = []
c_link_args = []
project_src = []
project_inc = []
test_src = []
test_inc = []
link_deps = []

#set specific compiler flags
c_args += [
    '-mcpu=cortex-m0',
    '-mthumb',
    '-mthumb-interwork',
    '-ffunction-sections',
    '-fdata-sections',
    '-fno-common',
    '-fmessage-length=0',
    '-O0'
]

#set specific linker flags
c_link_args += [
    '-mcpu=cortex-m0',
    '-mthumb',
    '-mthumb-interwork',
    '-Wl,--gc-sections',
    '-Wl,--print-memory-usage'
]

# microcontroller specific settings
defines = [
    '-DSTM32F042x6'
]

linker_file = files('Drivers/CMSIS/Device/ST/STM32F0xx/STM32F042K6Tx_FLASH.ld')
startup_file = files('Drivers/CMSIS/Device/ST/STM32F0xx/Source/startup_stm32f042x6.s')

# add defines to the c_args
c_args += defines

# add the linker script to flags
c_link_args += ['-Wl,-T,@0@/@1@'.format(meson.current_source_dir(), linker_file[0])]

project_inc += include_directories(
    'Drivers/CMSIS/Core/Include',
    'Drivers/CMSIS/Device/ST/STM32F0xx/Include',
    'inc'
)


project_src += files(
    'Drivers/CMSIS/Device/ST/STM32F0xx/Source/system_stm32f0xx.c',
    'src/main.c'
)

# create .elf executable
elf = executable(
    meson.project_name(),
    [project_src, startup_file],
    name_suffix : 'elf',
    c_args : c_args,
    link_args : c_link_args,
    dependencies : link_deps,
    include_directories : project_inc
)

# create .bin executable based on .elf
bin = custom_target(
    'bin',
    input: elf,
    output:  meson.project_name() + '.bin',
    command: [find_program('objcopy'), '-O', 'binary', '@INPUT@', '@OUTPUT@'],
    build_by_default: true,
    depends: elf
)

# create .hex executable based on .elf
hex = custom_target(
    'hex',
    input: elf,
    output:  meson.project_name() + '.hex',
    command: [find_program('objcopy'), '-O', 'binary', '@INPUT@', '@OUTPUT@'],
    build_by_default: true,
    depends: elf
)