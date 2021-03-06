library verilog;
use verilog.vl_types.all;

entity ddc_for_asic is
  generic(
    ADBITWIDTH     : integer := 16;
    NCOBITWIDTH    : integer := 25;
    FILTERBITWIDTH : integer := 18;
    MIXBITWIDTH    : integer := 22;
    COEBITWIDTH    : integer := 16;
    FIRBITWIDTH    : integer := 26
    );
  port(
    clk                  : in  vl_logic;
    rst_m0               : in  vl_logic;
    rst_start            : in  vl_logic;
    rst                  : in  vl_logic;
    config_sync          : in  vl_logic;
    nco_param            : in  vl_logic_vector(COEBITWIDTH-1 downto 0);
    ncogain_param        : in  vl_logic_vector(COEBITWIDTH-1 downto 0);
    hb_param             : in  vl_logic_vector(COEBITWIDTH-1 downto 0);
    cic_param            : in  vl_logic_vector(COEBITWIDTH-1 downto 0);
    decimgain_param      : in  vl_logic_vector(COEBITWIDTH-1 downto 0);
    hbgain_param         : in  vl_logic_vector(COEBITWIDTH-1 downto 0);
    fir_param            : in  vl_logic_vector(COEBITWIDTH-1 downto 0);
    firgain_param        : in  vl_logic_vector(COEBITWIDTH-1 downto 0);
    orp                  : in  vl_logic;
    data_in              : in  vl_logic_vector(ADBITWIDTH-1 downto 0);
    nco_indicator        : in  vl_logic;
    nco_pass_flag        : in  vl_logic;
    ncogain_indicator    : in  vl_logic;
    hb_indicator         : in  vl_logic;
    hb_pass_flag         : in  vl_logic;
    decimgain_indicator  : in  vl_logic;
    cic_indicator        : in  vl_logic;
    cic_pass_flag        : in  vl_logic;
    hbgain_indicator     : in  vl_logic;
    fir_indicator        : in  vl_logic;
    fir_pass_flag        : in  vl_logic;
    firgain_indicator    : in  vl_logic;
    sin_val              : in  vl_logic_vector(15 downto 0);
    nco_test_en          : in  vl_logic;
    nco_sine_test        : out vl_logic_vector(NCOBITWIDTH-1 downto 0);
    nco_cosine_test      : out vl_logic_vector(NCOBITWIDTH-1 downto 0);
    mixer_i_test         : out vl_logic_vector(MIXBITWIDTH-1 downto 0);
    mixer_q_test         : out vl_logic_vector(MIXBITWIDTH-1 downto 0);
    nco_i_pass_data_test : out vl_logic_vector(FILTERBITWIDTH-1 downto 0);
    nco_q_pass_data_test : out vl_logic_vector(FILTERBITWIDTH-1 downto 0);
    hb_i_test            : out vl_logic_vector(MIXBITWIDTH-1 downto 0);
    hb_q_test            : out vl_logic_vector(MIXBITWIDTH-1 downto 0);
    cic_i_test           : out vl_logic_vector(MIXBITWIDTH-1 downto 0);
    cic_q_test           : out vl_logic_vector(MIXBITWIDTH-1 downto 0);
    hb_flag              : out vl_logic;
    cic_flag             : out vl_logic;
    fir_i_result_test    : out vl_logic_vector(FIRBITWIDTH-1 downto 0);
    fir_q_result_test    : out vl_logic_vector(FIRBITWIDTH-1 downto 0);
    fir_flag             : out vl_logic;
    ddc_i_data           : out vl_logic_vector(ADBITWIDTH-1 downto 0);
    ddc_q_data           : out vl_logic_vector(ADBITWIDTH-1 downto 0);
    ddc_flag             : out vl_logic;
    nco_test             : out vl_logic_vector(14 downto 0);
    freq_word            : out vl_logic_vector(31 downto 0)
    );
end ddc_for_asic;
