###########################################################################
#
# Generated by : Version 8.0 Build 231 07/10/2008 Service Pack 1 SJ Full Version
#
# Project      : top
# Revision     : top
#
# Date         : Wed Apr 20 10:17:02 China Standard Time 2011
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

# Original Clock Setting Name: lvds_i:lvds_i_1|rx_inclock
create_clock -period "3.333 ns" \
             -name {rx_inclock_i} {rx_inclock_i}
# ---------------------------------------------


# Original Clock Setting Name: FX_CLK_i
create_clock -period "25.000 ns" \
             -name {FX_CLK_i} {FX_CLK_i}
# ---------------------------------------------


# Original Clock Setting Name: clk_80m
create_clock -period "8.000 ns" \
             -name {clk_80m} {clk_80m}


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
set_input_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min 0 [get_ports {ssram0_dq_io*}]
set_input_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 3 [get_ports {ssram0_dq_io*}]


set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram0_dq_io*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram0_dq_io*}]

set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram0_adr_o*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram0_adr_o*}]

set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram0_we*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram0_we*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram0_oe*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram0_oe*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram0_ce*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram0_ce*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram0_cke*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram0_cke*}]

set_input_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min 0 [get_ports {ssram1_dq_io*}]
set_input_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 3 [get_ports {ssram1_dq_io*}]


set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram1_dq_io*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram1_dq_io*}]

set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram1_adr_o*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram1_adr_o*}]

set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram1_we*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram1_we*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram1_oe*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram1_oe*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram1_ce*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram1_ce*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -min -0.4 [get_ports {ssram1_cke*}]
set_output_delay -clock { dcm45:dcm45_ssram|altpll:altpll_component|_clk0 } -max 1.4 [get_ports {ssram1_cke*}]


set_input_delay -clock { rx_inclock_i } -min 0 [get_ports {rx_in_i*}]
set_input_delay -clock { rx_inclock_i } -max 3.18 [get_ports {rx_in_i*}]


# ** Tpd requirements
#    ----------------

# ** Setup/Hold Relationships
#    ------------------------

# ** Tsu/Th requirements
#    -------------------


# ** Tco/MinTco requirements
#    -----------------------



# ---------------------------------------------
# The following clock group is added to try to 
# match the behavior of:
#   CUT_OFF_PATHS_BETWEEN_CLOCK_DOMAINS = ON
# ---------------------------------------------

set_clock_groups -asynchronous \
                 -group { \
                       rx_inclock_i \
                        } \
                 -group { \
                       dcm45:dcm45_ssram|altpll:altpll_component|_clk1 \
                       dcm45:dcm45_ssram|altpll:altpll_component|_clk0 \
                       clk_80m \
                        } \
                 -group { \
                       tlc3548:tlc3548_1|dcm_1M:dcm_1M_1|altpll:altpll_component|_clk0 \
                       dcm_user:dcm_user_1|altpll:altpll_component|_clk0 \
                       FX_CLK_i \
                        } \

# ---------------------------------------------
