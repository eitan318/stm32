ENTRY(reset_handler) /* Initial function */

MEMORY
{
    /* FLASH REGIONS (Non-Volatile Storage) */
    FLASH_BANK1 (rx) : ORIGIN = 0x08000000, LENGTH = 1M  /* Primary application */
    FLASH_BANK2 (rx) : ORIGIN = 0x08100000, LENGTH = 1M  /* OTA/Backup storage  */

    /* RAM REGIONS (Volatile Workspace) */
    DTCM       (rwx) : ORIGIN = 0x20000000, LENGTH = 128K /* Critical real-time */
    AXI_SRAM   (rwx) : ORIGIN = 0x24000000, LENGTH = 512K /* General purpose    */
    BKPSRAM    (rwx) : ORIGIN = 0x38800000, LENGTH = 4K   /* Data persistence   */
}

/* Initial stack pointer: top of DTCM */
PROVIDE(_estack = ORIGIN(DTCM) + LENGTH(DTCM));

SECTIONS
{
    .text : {
        KEEP(*(.vectors))   /* Must be first */
        *(.text*)
        *(.rodata*)
    } > FLASH_BANK1

    /* Starts in FLASH, copied to RAM at startup */
    .data : {
        *(.data*)
    } > AXI_SRAM AT > FLASH_BANK1

    .bss : {
        *(.bss*)
        *(COMMON)
    } > AXI_SRAM
}
