# LMK_04828B_readback 10 MHZ status 
I modify the code available in GitLab from Mitch Burnett "https://gitlab.ras.byu.edu/alpaca/i2c-utils" to get a readback for 3 registers R386, R387, R392: 0x018206, 0x018306, 0x018800 in order to read the Clk_104 status in ZCU216 board. The code is written in C program and it gives us readback according to the status of LEDs of Clk_104
# When the CLK_104 LED is ON
- casper@localhost:$./alpaca_prg_pll_nolmk 
- Reading LMK04828 register config
- LMK04828 readback config data are:
- 0x018206, 0x018306, 0x018800, 
- LMK register readbacks are R386, R387, R392: 0x018206, 0x018306, 0x018800
- LED is lit
- PLL1 DLD is set
- PLL2 DLD is set
# When the CLK_104 LED is OFF
- Reading LMK04828 register config
- LMK04828 readback config data are:
- 0x018204, 0x018306, 0x018810, 
- LMK register readbacks are R386, R387, R392: 0x018204, 0x018306, 0x018810
- LED is not lit
- PLL1 DLD is not set
- PLL2 DLD is not set
