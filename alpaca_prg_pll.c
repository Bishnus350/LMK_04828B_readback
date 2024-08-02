#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> // uint8_t, uint16_t
#include <unistd.h> // usleep 

#include <errno.h>
#include <assert.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>

#include "alpaca_rfclks.h"
#define PLL_TYPE  0;

int main(int argc, char**argv) {
  // file data
  FILE* fileptr;
  char* tcsfile;
  struct stat st;
  // pll config data
   // uint32_t* rp;
  uint8_t pll_type ;
  uint32_t rp[] = {0x018200, 0x018300, 0x018800};



  int prg_cnt = REGISTER_COUNT;
  int pkt_len = LMK_PKT_SIZE;

//  int prg_cnt = (pll_type == 0) ? REGISTER_COUNT : LMX2594_REG_CNT;
//  int pkt_len = (pll_type == 0) ? LMK_PKT_SIZE: LMX_PKT_SIZE;



//  printf("loaded the following config:\n");
//  for (int i=0; i<prg_cnt; i++) {
//    if (i%9==8) {
//      printf("0x%06x,\n", rp[i]);
//    } else {
//      printf("0x%06x, ", rp[i]);
//    }
//  }
//  printf("\n\n");

  /* program zcu216 plls */
  int ret;
  // init i2c
  init_i2c_bus();
  // init spi bridge
  init_i2c_dev(I2C_DEV_CLK104);
  // init fabric gpio for SDIO readback (no IO Expander on zcu216/208)
  init_clk104_gpio(510);

  
  
  // init spi device configuration
  uint8_t spi_config[2] = {0xf0, 0x03};
  i2c_write(I2C_DEV_CLK104, spi_config, 2);

  
  /* readback */
//  get_pll_config(pll_type, rp);//By default code, since i don't have pll_type, i need to modify
    get_pll_config( rp);

  // close i2c devices
  close_i2c_dev(I2C_DEV_CLK104);
  close_i2c_bus();

  return 0;

}



