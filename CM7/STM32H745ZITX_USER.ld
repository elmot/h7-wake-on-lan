INCLUDE STM32H745ZITX_FLASH.ld

SECTIONS {
  .lwip_sec (NOLOAD) :
  {
    . = ABSOLUTE(0x30040000);
    *(.RxDecripSection)

    . = ABSOLUTE(0x30040060);
    *(.TxDecripSection)

    . = ABSOLUTE(0x30040200);
    *(.Rx_PoolSection)
  } >RAM_D2
}