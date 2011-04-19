-------------------------------------------------------------------------------
-- Title      : 
-- Project    : 
-------------------------------------------------------------------------------
-- File       : dat_buf_v2.vhd
-- Author     :   <Administrator@HEAVEN>
-- Company    : 
-- Created    : 2011-04-19
-- Last update: 2011-04-19
-- Platform   : 
-- Standard   : VHDL'87
-------------------------------------------------------------------------------
-- Description: 
-------------------------------------------------------------------------------
-- Copyright (c) 2011 
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2011-04-19  1.0      Administrator   Created
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity dat_buf_v2 is

  port (
    LB_Clk_i   : in  std_logic;
    LB_Reset_i : in  std_logic;
    LB_Addr_i  : in  std_logic_vector(15 downto 0);
    LB_Write_i : in  std_logic;
    LB_Read_i  : in  std_logic;
    LB_Ready_o : out std_logic;
    LB_DataW_i : in  std_logic_vector(15 downto 0);
    LB_DataR_o : out std_logic_vector(15 downto 0);

    clk_i : in std_logic;
    rst_i : in std_logic;

    rd_req_o   : out std_logic;
    rd_q_i     : in  std_logic_vector(63 downto 0);
    rd_empty_i : in  std_logic;

    rd_i    : in  std_logic;
    empty_o : out std_logic;
    dout_o  : out std_logic_vector(15 downto 0);

    ssram0_clk_o   : out std_logic;
    ssram0_cke_n_o : out std_logic;
    ssram0_ce1_n_o : out std_logic;
    ssram0_ce2_n_o : out std_logic;
    ssram0_ce2_o   : out std_logic;

    ssram0_oe_n_o : out   std_logic;
    ssram0_we_n_o : out   std_logic;
    ssram0_bw_n_o : out   std_logic;
    ssram0_addr_o : out   std_logic_vector(ADDR_WIDTH - 1 downto 0);
    ssram0_dq_io  : inout std_logic_vector(DATA_WIDTH - 1 downto 0);
    ssram0_adv_o  : out   std_logic;

    ssram0_zz_o   : out std_logic;
    ssram0_mode_o : out std_logic);

end dat_buf_v2;

architecture impl of dat_buf_v2 is

  component ssram_fifo
    generic (
      DATA_WIDTH : integer;
      ADDR_WIDTH : integer);
    port (
      clk_i         : in  std_logic;
      rst_i         : in  std_logic;
      count_o       : out integer range 2**ADDR_WIDTH downto 0;
      empty_o       : out std_logic;
      full_o        : out std_logic;
      wr_i          : in  std_logic;
      d_i           : in  std_logic_vector(DATA_WIDTH - 1 downto 0);
      rd_i          : in  std_logic;
      vld_o         : out std_logic;
      q_o           : out std_logic_vector(DATA_WIDTH - 1 downto 0);
      ssram_clk_o   : out std_logic;
      ssram_ce1_n_o : out std_logic;
      ssram_ce2_n_o : out std_logic;
      ssram_ce2_o   : out std_logic;
      ssram_addr_o  : out std_logic_vector(ADDR_WIDTH - 1 downto 0);
      ssram_d_i     : in  std_logic_vector(DATA_WIDTH - 1 downto 0);
      ssram_d_t_o   : out std_logic;
      ssram_d_o     : out std_logic_vector(DATA_WIDTH - 1 downto 0);
      ssram_adv_o   : out std_logic;
      ssram_we_n_o  : out std_logic;
      ssram_oe_n_o  : out std_logic;
      ssram_bw_n_o  : out std_logic;
      ssram_cke_n_o : out std_logic;
      ssram_zz_o    : out std_logic;
      ssram_mode_o  : out std_logic);
  end component;

  signal ss_count_o : integer range 2**ADDR_WIDTH downto 0;
  signal ss_empty_o : std_logic;
  signal ss_full_o  : std_logic;
  signal ss_wr_i    : std_logic;
  signal ss_d_i     : std_logic_vector(DATA_WIDTH - 1 downto 0);
  signal ss_rd_i    : std_logic;
  signal ss_vld_o   : std_logic;
  signal ss_q_o     : std_logic_vector(DATA_WIDTH - 1 downto 0);

  component lb_target_reg
    generic (
      ADDR : std_logic_vector(15 downto 0));
    port (
      LB_Clk_i   : in  std_logic;
      LB_Reset_i : in  std_logic;
      LB_Addr_i  : in  std_logic_vector(15 downto 0);
      LB_Write_i : in  std_logic;
      LB_Read_i  : in  std_logic;
      LB_Ready_o : out std_logic;
      LB_DataW_i : in  std_logic_vector(15 downto 0);
      LB_DataR_o : out std_logic_vector(15 downto 0);
      updated_o  : out std_logic;
      ctrl_o     : out std_logic_vector(15 downto 0);
      sta_i      : in  std_logic_vector(15 downto 0));
  end component;

  signal reg_updated_o : std_logic;
  signal updated_r2    : std_logic;
  signal reg_ctrl_o    : std_logic_vector(15 downto 0);
  signal reg_sta_i     : std_logic_vector(15 downto 0);

  component dff_en_r_pline
    generic (
      Pipeline : integer); 
    port (
      CK     : in  std_logic;
      Clear  : in  std_logic := '0';
      Data   : in  std_logic;
      Enable : in  std_logic := '1';
      Q      : out std_logic); 
  end component;

  component fifo64to16
    port (
      aclr    : in  std_logic := '0';
      data    : in  std_logic_vector (63 downto 0);
      rdclk   : in  std_logic;
      rdreq   : in  std_logic;
      wrclk   : in  std_logic;
      wrreq   : in  std_logic;
      q       : out std_logic_vector (15 downto 0);
      rdempty : out std_logic;
      rdusedw : out std_logic_vector (14 downto 0);
      wrfull  : out std_logic;
      wrusedw : out std_logic_vector (12 downto 0)); 
  end component;

  signal async_aclr    : std_logic := '0';
  signal async_data    : std_logic_vector (63 downto 0);
  signal async_rdclk   : std_logic;
  signal async_rdreq   : std_logic;
  signal async_wrclk   : std_logic;
  signal async_wrreq   : std_logic;
  signal async_q       : std_logic_vector (15 downto 0);
  signal async_rdempty : std_logic;
  signal async_rdusedw : std_logic_vector (14 downto 0);
  signal async_wrfull  : std_logic;
  signal async_wrusedw : std_logic_vector (12 downto 0);

  type   state_t is (s_idle, s_reset, s_fill, s_dump);
  signal cs : state_t;

  constant RST_CNT_MAX : 32;
  signal   rst_cnt     : integer range 0 to RST_CNT_MAX - 1;

  
begin  -- impl


--  ss_empty_o : std_logic;
  ss_wr_i <= '1' when cs = s_write and rd_empty_i = '0'
             else '0';
  rd_req_o <= ss_wr_i;

  ss_d_i <= rd_q_i;

  ss_rd_i <= '1' when cs = s_idle and async_wrusedw(async_wrusedw'length - 1) = '0' and ss_empty_o = '0'
             else '0';
  async_wrreq <= ss_vld_o;
  async_data  <= ss_q_o;

  dff_en_r_pline_1 : dff_en_r_pline
    generic map (
      Pipeline => 1)
    port map (
      CK     => clk_i,
      Clear  => '0',
      Data   => reg_updated_o,
      Enable => '1',
      Q      => updated_r2);

  lb_target_reg_1 : lb_target_reg
    generic map (
      ADDR => ADDR)
    port map (
      LB_Clk_i   => LB_Clk_i,
      LB_Reset_i => LB_Reset_i,
      LB_Addr_i  => LB_Addr_i,
      LB_Write_i => LB_Write_i,
      LB_Read_i  => LB_Read_i,
      LB_Ready_o => LB_Ready_o,
      LB_DataW_i => LB_DataW_i,
      LB_DataR_o => LB_DataR_o,
      updated_o  => reg_updated_o,
      ctrl_o     => reg_ctrl_o,
      sta_i      => reg_sta_i);


  ssram_fifo_1 : ssram_fifo
    generic map (
      DATA_WIDTH => DATA_WIDTH,
      ADDR_WIDTH => ADDR_WIDTH)
    port map (
      clk_i => clk_i,
      rst_i => rst_i,

      count_o => ss_count_o,
      full_o  => ss_full_o,
      wr_i    => ss_wr_i,
      d_i     => ss_d_i,

      rd_i    => ss_rd_i,
      vld_o   => ss_vld_o,
      empty_o => ss_empty_o,
      q_o     => ss_q_o,

      ssram_clk_o   => ssram0_clk_o,
      ssram_ce1_n_o => ssram0_ce1_n_o,
      ssram_ce2_n_o => ssram0_ce2_n_o,
      ssram_ce2_o   => ssram0_ce2_o,
      ssram_addr_o  => ssram0_addr_o,
      ssram_d_i     => ssram0_d_i,
      ssram_d_t_o   => ssram0_d_t_o,
      ssram_d_o     => ssram0_d_o,
      ssram_adv_o   => ssram0_adv_o,
      ssram_we_n_o  => ssram0_we_n_o,
      ssram_oe_n_o  => ssram0_oe_n_o,
      ssram_bw_n_o  => ssram0_bw_n_o,
      ssram_cke_n_o => ssram0_cke_n_o,
      ssram_zz_o    => ssram0_zz_o,
      ssram_mode_o  => ssram0_mode_o);

  
  async_aclr  <= rst_i;
  async_wrclk <= clk_i;

  async_rdclk <= LB_Clk_i;
  async_rdreq <= rd_i;
  dout_o      <= async_q;
  empty_o     <= async_rdempty;

  fifo64to16_1 : fifo64to16
    port map (
      aclr    => async_aclr,
      data    => async_data,
      rdclk   => async_rdclk,
      rdreq   => async_rdreq,
      wrclk   => async_wrclk,
      wrreq   => async_wrreq,
      q       => async_q,
      rdempty => async_rdempty,
      rdusedw => async_rdusedw,
      wrfull  => async_wrfull,
      wrusedw => async_wrusedw);

  process (clk_i, rst_i)
  begin  -- process
    if rst_i = '1' then
      cs      <= s_idle;
      rst_cnt <= 0;
      
    elsif clk_i'event and clk_i = '1' then  -- rising clock edge

      case cs is
        when s_idle =>
          if updated_r2 = '1' then
            cs <= s_reset;
          end if;
          rst_cnt <= 0;

        when s_reset =>
          if rst_cnt < RST_CNT_MAX - 1 then
            rst_cnt <= rst_cnt + 1;
          else
            rst_cnt <= rst_cnt;
            cs      <= s_fill;
          end if;
          
        when s_fill =>
          if ss_full_o = '1' then
            cs <= s_idle;
          end if;

        when others => null;
      end case;
    end if;
  end process;

end impl;
