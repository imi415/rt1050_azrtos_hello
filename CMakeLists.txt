cmake_minimum_required(VERSION 3.10)

project(imxrt1050_azrtos_hello)

enable_language(CXX)
enable_language(ASM)

# Device specific settings, goes to CFLAGS and LDFLAGS
set(TARGET_CFLAGS_HARDWARE "-mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb")

# Extra CFlags
set(TARGET_CFLAGS_EXTRA   "-Og")
set(TARGET_CXXFLAGS_EXTRA "")
set(TARGET_LDFLAGS_EXTRA  "-Wl,--print-memory-usage -Xlinker --defsym=__heap_size__=0x1F000") # ThreadX uses the default heap.

# Different linker scripts
set(TARGET_LDSCRIPT_RAM           "${CMAKE_SOURCE_DIR}/devices/MIMXRT1052/gcc/MIMXRT1052xxxxx_ram.ld")
set(TARGET_LDSCRIPT_FLEXSPI       "${CMAKE_SOURCE_DIR}/devices/MIMXRT1052/gcc/MIMXRT1052xxxxx_flexspi_nor.ld")
set(TARGET_LDSCRIPT_SDRAM         "${CMAKE_SOURCE_DIR}/devices/MIMXRT1052/gcc/MIMXRT1052xxxxx_sdram.ld")
set(TARGET_LDSCRIPT_FLEXSPI_SDRAM "${CMAKE_SOURCE_DIR}/devices/MIMXRT1052/gcc/MIMXRT1052xxxxx_flexspi_nor_sdram.ld")

# Copy them from Makefile
set(TARGET_C_SOURCES
    "devices/MIMXRT1052/system_MIMXRT1052.c"
    "devices/MIMXRT1052/drivers/fsl_adc.c"
    "devices/MIMXRT1052/drivers/fsl_adc_etc.c"
    "devices/MIMXRT1052/drivers/fsl_aipstz.c"
    "devices/MIMXRT1052/drivers/fsl_aoi.c"
    "devices/MIMXRT1052/drivers/fsl_bee.c"
    "devices/MIMXRT1052/drivers/fsl_cache.c"
    "devices/MIMXRT1052/drivers/fsl_clock.c"
    "devices/MIMXRT1052/drivers/fsl_cmp.c"
    "devices/MIMXRT1052/drivers/fsl_common_arm.c"
    "devices/MIMXRT1052/drivers/fsl_common.c"
    "devices/MIMXRT1052/drivers/fsl_csi.c"
    "devices/MIMXRT1052/drivers/fsl_dcdc.c"
    "devices/MIMXRT1052/drivers/fsl_dcp.c"
    "devices/MIMXRT1052/drivers/fsl_dmamux.c"
    "devices/MIMXRT1052/drivers/fsl_edma.c"
    "devices/MIMXRT1052/drivers/fsl_elcdif.c"
    "devices/MIMXRT1052/drivers/fsl_enc.c"
    "devices/MIMXRT1052/drivers/fsl_enet.c"
    "devices/MIMXRT1052/drivers/fsl_ewm.c"
    "devices/MIMXRT1052/drivers/fsl_flexcan.c"
    "devices/MIMXRT1052/drivers/fsl_flexio.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_camera.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_camera_edma.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_i2c_master.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_i2s.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_i2s_edma.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_mculcd.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_mculcd_edma.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_spi.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_spi_edma.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_uart.c"
    "devices/MIMXRT1052/drivers/fsl_flexio_uart_edma.c"
    "devices/MIMXRT1052/drivers/fsl_flexram_allocate.c"
    "devices/MIMXRT1052/drivers/fsl_flexram.c"
    "devices/MIMXRT1052/drivers/fsl_flexspi.c"
    "devices/MIMXRT1052/drivers/fsl_flexspi_edma.c"
    "devices/MIMXRT1052/drivers/fsl_gpc.c"
    "devices/MIMXRT1052/drivers/fsl_gpio.c"
    "devices/MIMXRT1052/drivers/fsl_gpt.c"
    "devices/MIMXRT1052/drivers/fsl_kpp.c"
    "devices/MIMXRT1052/drivers/fsl_lpi2c.c"
    "devices/MIMXRT1052/drivers/fsl_lpi2c_edma.c"
    "devices/MIMXRT1052/drivers/fsl_lpspi.c"
    "devices/MIMXRT1052/drivers/fsl_lpspi_edma.c"
    "devices/MIMXRT1052/drivers/fsl_lpuart.c"
    "devices/MIMXRT1052/drivers/fsl_lpuart_edma.c"
    "devices/MIMXRT1052/drivers/fsl_ocotp.c"
    "devices/MIMXRT1052/drivers/fsl_pit.c"
    "devices/MIMXRT1052/drivers/fsl_pmu.c"
    "devices/MIMXRT1052/drivers/fsl_pwm.c"
    "devices/MIMXRT1052/drivers/fsl_pxp.c"
    "devices/MIMXRT1052/drivers/fsl_qtmr.c"
    "devices/MIMXRT1052/drivers/fsl_romapi.c"
    "devices/MIMXRT1052/drivers/fsl_rtwdog.c"
    "devices/MIMXRT1052/drivers/fsl_sai.c"
    "devices/MIMXRT1052/drivers/fsl_sai_edma.c"
    "devices/MIMXRT1052/drivers/fsl_semc.c"
    "devices/MIMXRT1052/drivers/fsl_snvs_hp.c"
    "devices/MIMXRT1052/drivers/fsl_snvs_lp.c"
    "devices/MIMXRT1052/drivers/fsl_spdif.c"
    "devices/MIMXRT1052/drivers/fsl_spdif_edma.c"
    "devices/MIMXRT1052/drivers/fsl_src.c"
    "devices/MIMXRT1052/drivers/fsl_tempmon.c"
    "devices/MIMXRT1052/drivers/fsl_trng.c"
    "devices/MIMXRT1052/drivers/fsl_tsc.c"
    "devices/MIMXRT1052/drivers/fsl_usdhc.c"
    "devices/MIMXRT1052/drivers/fsl_wdog.c"
    "devices/MIMXRT1052/drivers/fsl_xbara.c"
    "devices/MIMXRT1052/drivers/fsl_xbarb.c"
    "devices/MIMXRT1052/xip/fsl_flexspi_nor_boot.c"
    "board/board.c"
    "board/clock_config.c"
    "board/peripherals.c"
    "board/pin_mux.c"
    "board/xip/fire_ebf1052_flexspi_nor_config.c"
    "source/main.c"
    "source/tx_init_lowlevel.c"
)

# Copy them from Makefile
set(TARGET_ASM_SOURCES
    "devices/MIMXRT1052/gcc/startup_MIMXRT1052.S"
)

# Copy them from Makefile
set(TARGET_DEFINES
    "-DCPU_MIMXRT1052DVL6B"
    "-D__STARTUP_CLEAR_BSS"
    "-D__STARTUP_INITIALIZE_NONCACHEDATA"
)

# Copy them from Makefile
set(TARGET_INCLUDES
    "board"
    "source"
    "devices/MIMXRT1052"
    "devices/MIMXRT1052/drivers"
    "CMSIS/Core/Include"
    "components/threadx/common/inc"
)

set(TARGET_LIBS
    "threadx"
    "filex"
)

# Final compiler flags
set(CMAKE_C_FLAGS          "${TARGET_CFLAGS_HARDWARE} ${TARGET_CFLAGS_EXTRA} ${TARGET_CFLGAGS_DEBUG} -Wall -fdata-sections -ffunction-sections -ffreestanding -fno-builtin")
set(CMAKE_CXX_FLAGS        "${CMAKE_C_FLAGS} ${TARGET_CXXFLAGS_EXTRA}")
set(CMAKE_ASM_FLAGS        "${CMAKE_C_FLAGS} -x assembler-with-cpp")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_C_FLAGS} -specs=nano.specs -specs=nosys.specs -Wl,--gc-sections -lc -lm -lnosys ${TARGET_LDFLAGS_EXTRA}")

# Configure ThreadX
set(THREADX_ARCH "cortex_m7" CACHE STRING "ThreadX Arch")
set(THREADX_TOOLCHAIN "gnu" CACHE STRING "ThreadX Toolchain")
set(TX_USER_FILE "${CMAKE_CURRENT_SOURCE_DIR}/include/tx_user.h")
add_subdirectory(components/threadx)
add_subdirectory(components/filex)

# Main targets are added here

# **** All In SRAM ****

# Create ELF
add_executable("${CMAKE_PROJECT_NAME}_RAM.elf" ${TARGET_C_SOURCES} ${TARGET_ASM_SOURCES})

# Linker script and Map files
target_link_options("${CMAKE_PROJECT_NAME}_RAM.elf"
    PRIVATE "-T${TARGET_LDSCRIPT_RAM}"
    PRIVATE "-Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}_RAM.map,--cref"
)
target_compile_definitions("${CMAKE_PROJECT_NAME}_RAM.elf" PRIVATE ${TARGET_DEFINES})
target_include_directories("${CMAKE_PROJECT_NAME}_RAM.elf" PRIVATE ${TARGET_INCLUDES})
target_link_libraries("${CMAKE_PROJECT_NAME}_RAM.elf" PRIVATE ${TARGET_LIBS})

add_custom_command(OUTPUT "${CMAKE_PROJECT_NAME}_RAM.hex"
    COMMAND ${CMAKE_OBJCOPY} "-O" "ihex" "${CMAKE_PROJECT_NAME}_RAM.elf" "${CMAKE_PROJECT_NAME}_RAM.hex"
    DEPENDS "${CMAKE_PROJECT_NAME}_RAM.elf"
)

add_custom_target("${CMAKE_PROJECT_NAME}_RAM_HEX"
    DEPENDS "${CMAKE_PROJECT_NAME}_RAM.hex"
)

# **** FLEXSPI ****

# Create ELF
add_executable("${CMAKE_PROJECT_NAME}_FLEXSPI.elf" ${TARGET_C_SOURCES} ${TARGET_ASM_SOURCES})

# Linker script and Map files
target_link_options("${CMAKE_PROJECT_NAME}_FLEXSPI.elf"
    PRIVATE "-T${TARGET_LDSCRIPT_FLEXSPI}"
    PRIVATE "-Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}_FLEXSPI.map,--cref"
)
target_compile_definitions("${CMAKE_PROJECT_NAME}_FLEXSPI.elf"
    PRIVATE ${TARGET_DEFINES}
    PRIVATE "XIP_EXTERNAL_FLASH=1"
    PRIVATE "XIP_BOOT_HEADER_ENABLE=1"
)
target_include_directories("${CMAKE_PROJECT_NAME}_FLEXSPI.elf" PRIVATE ${TARGET_INCLUDES})
target_link_libraries("${CMAKE_PROJECT_NAME}_FLEXSPI.elf" PRIVATE ${TARGET_LIBS})

add_custom_command(OUTPUT "${CMAKE_PROJECT_NAME}_FLEXSPI.hex"
    COMMAND ${CMAKE_OBJCOPY} "-O" "ihex" "${CMAKE_PROJECT_NAME}_FLEXSPI.elf" "${CMAKE_PROJECT_NAME}_FLEXSPI.hex"
    DEPENDS "${CMAKE_PROJECT_NAME}_FLEXSPI.elf"
)

add_custom_target("${CMAKE_PROJECT_NAME}_FLEXSPI_HEX"
    DEPENDS "${CMAKE_PROJECT_NAME}_FLEXSPI.hex"
)

# **** SDRAM ****

# Create ELF
add_executable("${CMAKE_PROJECT_NAME}_SDRAM.elf" ${TARGET_C_SOURCES} ${TARGET_ASM_SOURCES})

# Linker script and Map files
target_link_options("${CMAKE_PROJECT_NAME}_SDRAM.elf"
    PRIVATE "-T${TARGET_LDSCRIPT_SDRAM}"
    PRIVATE "-Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}_SDRAM.map,--cref"
)
target_compile_definitions("${CMAKE_PROJECT_NAME}_SDRAM.elf"
    PRIVATE ${TARGET_DEFINES}
    PRIVATE "DATA_SECTION_IS_CACHABLE=1"
    PRIVATE "SKIP_SYSCLK_INIT"
)
target_include_directories("${CMAKE_PROJECT_NAME}_SDRAM.elf" PRIVATE ${TARGET_INCLUDES})
target_link_libraries("${CMAKE_PROJECT_NAME}_SDRAM.elf" PRIVATE ${TARGET_LIBS})

add_custom_command(OUTPUT "${CMAKE_PROJECT_NAME}_SDRAM.hex"
    COMMAND ${CMAKE_OBJCOPY} "-O" "ihex" "${CMAKE_PROJECT_NAME}_SDRAM.elf" "${CMAKE_PROJECT_NAME}_SDRAM.hex"
    DEPENDS "${CMAKE_PROJECT_NAME}_SDRAM.elf"
)

add_custom_target("${CMAKE_PROJECT_NAME}_SDRAM_HEX"
    DEPENDS "${CMAKE_PROJECT_NAME}_SDRAM.hex"
)

# **** FlexSPI boot, data in SDRAM ****

# Create ELF
add_executable("${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.elf" ${TARGET_C_SOURCES} ${TARGET_ASM_SOURCES})

# Linker script and Map files
target_link_options("${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.elf"
    PRIVATE "-T${TARGET_LDSCRIPT_FLEXSPI_SDRAM}"
    PRIVATE "-Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.map,--cref"
)
target_compile_definitions("${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.elf"
    PRIVATE ${TARGET_DEFINES}
    PRIVATE "XIP_EXTERNAL_FLASH=1"
    PRIVATE "XIP_BOOT_HEADER_ENABLE=1"
    PRIVATE "DATA_SECTION_IS_CACHABLE=1"
    PRIVATE "SKIP_SYSCLK_INIT"
)
target_include_directories("${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.elf" PRIVATE ${TARGET_INCLUDES})
target_link_libraries("${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.elf" PRIVATE ${TARGET_LIBS})

add_custom_command(OUTPUT "${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.hex"
    COMMAND ${CMAKE_OBJCOPY} "-O" "ihex" "${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.elf" "${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.hex"
    DEPENDS "${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.elf"
)

add_custom_target("${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM_HEX"
    DEPENDS "${CMAKE_PROJECT_NAME}_FLEXSPI_SDRAM.hex"
)
