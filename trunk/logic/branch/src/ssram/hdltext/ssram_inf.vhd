-------------------------------------------------------------------------------
-- Title      : 
-- Project    : 
-------------------------------------------------------------------------------
-- File       : ssram_inf.vhd
-- Author     :   <Liu Peng@GKHY-LIUPENG>
-- Company    : 
-- Created    : 2011-04-19
-- Last update: 2011-04-19
-- Platform   : 
-- Standard   : VHDL'87
-------------------------------------------------------------------------------
-- Description:
--
--
--
-- 
-------------------------------------------------------------------------------
-- Copyright (c) 2011 
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 2011-04-19  1.0      Liu Peng        Created
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity ssram_inf is

  generic (
    DATA_WIDTH : integer := 32;
    ADDR_WIDTH : integer := 12);
  port(
    clk_i : in std_logic;
    rst_i : in std_logic;

--    rdy_o : out std_logic;
    we_i : in std_logic;
    rd_i : in std_logic;

    addr_i : in std_logic_vector(ADDR_WIDTH - 1 downto 0);

    d_i : in  std_logic_vector(DATA_WIDTH - 1 downto 0);
    q_o : out std_logic_vector(DATA_WIDTH - 1 downto 0);


    -- SSRAM 0
    ssram_clk_o   : out std_logic;
    ssram_ce1_n_o : out std_logic;
    ssram_ce2_n_o : out std_logic;
    ssram_ce2_o   : out std_logic;

    ssram_addr_o : out std_logic_vector(ADDR_WIDTH - 1 downto 0);
    ssram_d_i    : in  std_logic_vector(DATA_WIDTH - 1 downto 0);
    ssram_oe_n_o : out std_logic;
    ssram_d_o    : out std_logic_vector(DATA_WIDTH - 1 downto 0);
    ssram_adv_o  : out std_logic;
    ssram_we_n_o : out std_logic;
    ssram_zz_o   : out std_logic;
    ssram_mode_o : out std_logic);

end ssram_inf;

architecture archi of ssram_inf is

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
  component dff_en_r_pline_w
    generic (
      Pipeline : integer);
    port (
      Clk    : in  std_logic;
      Clear  : in  std_logic := '0';
      D      : in  std_logic_vector;
      Enable : in  std_logic := '1';
      Q      : out std_logic_vector);
  end component;

  signal we_en, rd_en       : std_logic;
  signal we, rd, rd_r2      : std_logic;
  signal d_r2, ssram_din_r2 : std_logic_vector(DATA_WIDTH - 1 downto 0);

  signal ce : std_logic;

begin  -- archi

  ssram_clk_o   <= clk_i;
  ssram_ce1_n_o <= not ce;
  ssram_ce2_n_o <= not ce;
  ssram_ce2_o   <= ce;

  ssram_d_o    <= d_r2;
  ssram_oe_n_o <= '0' when rd_r2 = '1' else '1';
  ssram_adv_o  <= '0';

  ssram_zz_o   <= '0';
  ssram_mode_o <= '0';

  ssram_addr_o <= addr_i;

  ssram_we_n_o <= not we;


  -----------------------------------------------------------------------------

  we_en <= '1';
  rd_en <= '1';

  we <= we_en and we_i;
  rd <= rd_en and rd_i;
  ce <= we or rd;

  we_r2_ffd : dff_en_r_pline
    generic map (
      Pipeline => 1)
    port map (
      CK     => clk_i,
      Clear  => rst_i,
      Data   => rd,
      Enable => '1',
      Q      => rd_r2);
  d_r2_ffd : dff_en_r_pline_w
    generic map (
      Pipeline => 1)
    port map (
      Clk    => clk_i,
      Clear  => rst_i,
      D      => d_i,
      Enable => '1',
      Q      => d_r2);  

  ssram_din_r2_ffd : dff_en_r_pline_w
    generic map (
      Pipeline => 1)
    port map (
      Clk    => clk_i,
      Clear  => rst_i,
      D      => ssram_d_i,
      Enable => '1',
      Q      => ssram_din_r2);  


end archi;