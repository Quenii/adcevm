###########################################################################
#
# Generated by : Version 8.0 Build 231 07/10/2008 Service Pack 1 SJ Full Version
#
# Project      : top
# Revision     : top
#
# Date         : Fri Jun 18 22:15:59 China Standard Time 2010
#
###########################################################################
 
 
# WARNING: Expected ENABLE_CLOCK_LATENCY to be set to 'ON', but it is set to 'OFF'
#          In SDC, create_generated_clock auto-generates clock latency
#
# ------------------------------------------
#
# Create generated clocks based on PLLs
derive_pll_clocks -use_tan_name
#
# ------------------------------------------


# Original Clock Setting Name: FX_CLK_i
create_clock -period "25.000 ns" \
             -name {FX_CLK_i} {FX_CLK_i}
# ---------------------------------------------

create_clock -period "4.000 ns" \
             -name {clk_80m} {clk_80m}
             
# Original Clock Setting Name: rx_inclock_i
create_clock -period "4.000 ns" \
             -name {rx_inclock_i} {rx_inclock_i}
# ---------------------------------------------

# ** Clock Latency
#    -------------

# ** Clock Uncertainty
#    -----------------

# ** Multicycles
#    -----------
# ** Cuts
#    ----

# ** Input/Output Delays
#    -------------------
set_output_delay -clock { had_rec:had_rec_2|dat_buf:dat_buf_1|dcm45:dcm45_1|altpll:altpll_component|_clk0 } 6 [get_ports {ssram0_bw*}]
set_output_delay -clock { had_rec:had_rec_2|dat_buf:dat_buf_1|dcm45:dcm45_1|altpll:altpll_component|_clk0 } 6 [get_ports {ssram0_adv_n_o}]
set_output_delay -clock { had_rec:had_rec_2|dat_buf:dat_buf_1|dcm45:dcm45_1|altpll:altpll_component|_clk0 } 6 [get_ports {ssram0_oe_n_o}]
set_output_delay -clock { had_rec:had_rec_2|dat_buf:dat_buf_1|dcm45:dcm45_1|altpll:altpll_component|_clk0 } 6 [get_ports {ssram0_gw_n_o}]
set_output_delay -clock { had_rec:had_rec_2|dat_buf:dat_buf_1|dcm45:dcm45_1|altpll:altpll_component|_clk0 } 6 [get_ports {ssram0_adr_o[*]}]
set_output_delay -clock { had_rec:had_rec_2|dat_buf:dat_buf_1|dcm45:dcm45_1|altpll:altpll_component|_clk0 } 6 [get_ports {ssram0_dinout_io[*]}]
set_input_delay -clock { had_rec:had_rec_2|dat_buf:dat_buf_1|dcm45:dcm45_1|altpll:altpll_component|_clk0 } 4 [get_ports {ssram0_dinout_io[*]}]

# ** Tpd requirements
#    ----------------

# ** Setup/Hold Relationships
#    ------------------------

# ** Tsu/Th requirements
#    -------------------


# ** Tco/MinTco requirements
#    -----------------------

#
# Entity Specific Timing Assignments found in
# the Timing Analyzer Settings report panel
#
set_false_path -from [get_keepers {*dcfifo_rhj1*|delayed_wrptr_g[*]}] -to [get_keepers {*dcfifo_rhj1*|*rs_dgwp|*dffpipe13|dffe14a[*]}]
set_false_path -from [get_keepers {*dcfifo_rhj1*|rdptr_g[*]}] -to [get_keepers {*dcfifo_rhj1*|*ws_dgrp|*dffpipe17|dffe18a[*]}]
set_multicycle_path -setup -start 4 -from [get_keepers {*lvds_i_lvds_rx*|wire_rx_dataout*}] -to [get_keepers {*lvds_i_lvds_rx*|rxreg*}]
set_multicycle_path -hold -start 3 -from [get_keepers {*lvds_i_lvds_rx*|wire_rx_dataout*}] -to [get_keepers {*lvds_i_lvds_rx*|rxreg*}]


# ---------------------------------------------
# The following clock group is added to try to 
# match the behavior of:
#   CUT_OFF_PATHS_BETWEEN_CLOCK_DOMAINS = ON
# ---------------------------------------------

set_clock_groups -asynchronous \
                 -group { \
                       had_rec:had_rec_2|dat_buf:dat_buf_1|dcm45:dcm45_1|altpll:altpll_component|_clk0 \
                       had_rec:had_rec_2|lvds_i:lvds_i_1|altlvds_rx:altlvds_rx_component|lvds_i_lvds_rx:auto_generated|wire_pll_clk[0] \
                       had_rec:had_rec_2|lvds_i:lvds_i_1|altlvds_rx:altlvds_rx_component|lvds_i_lvds_rx:auto_generated|wire_pll_sclkout[0] \
                       rx_inclock_i \
                        } \
                 -group { \
                       dcm_user:dcm_user_1|altpll:altpll_component|_clk0 \
                       FX_CLK_i \
                        } \

# ---------------------------------------------

