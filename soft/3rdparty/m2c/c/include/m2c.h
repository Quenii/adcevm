// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the M2C_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// M2C_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef M2C_EXPORTS
#define M2C_API __declspec(dllexport)
#else
#define M2C_API __declspec(dllimport)
#endif

#ifdef __cplusplus


class M2C_API LibInitializer
{
public:
	LibInitializer();
	~LibInitializer();
};

extern "C" {

#endif

M2C_API void AlgDynTest(double* cdata1, double* cdata2, double cnumpt, double cfclk, double cnumbit, double cr,
						double& cSNR__o, double& cSINAD__o, double& cSFDR__o, double& cENOB__o, double* cy);

M2C_API void AlgDynTest1k(double* cfpga_i, double* cfpga_q, double cnumpt, double cfclk, double cnumbit, double cVppFs, double cr
				  , double& cSNR__o, double& cSINAD__o, double& cSFDR__o, /*double& cENOB__o, */double& cTHD__o
				  , double* cHD, double* cSpectrum, double* cFh, double* cHarbin, double* cHarbin_dis
				  , double& cfreq_fin, double& cVin, double& cVpp, double& cPn_dB
				  );

M2C_API void AlgDynTestv3(double* cfpga_i, double* cfpga_q, double cnumpt, double cfclk, double cnumbit, double cVppFs, double cr,
						  double& cSNR__o, double& cSINAD__o, double& cSFDR__o, double& cENOB__o, double& cTHD__o,
						  double* cHD, double* cSpectrum, double* cFh, double* cHarbin);
//M2C_API void AdcDynTest(double* cdata, int cdata_cnt, double cfclk, double cnumbit, double cNFFT, double cV, double ccode,
//						double& cSNR__o, double& cSFDR__o, double& cSNRFS__o, double& cSINAD__o, double* cy);
M2C_API void AdcDynTest(double* cdata, int cdata_cnt, double cfclk, double cnumbit, double cNFFT, double cV, double ccode,
                        double& cSNR__o, double& cSINAD__o, double& cSFDR__o, double& cENOB__o,
                        double* cHD, double* cy, double& cVpp__o, double& cVin__o, double& cTHD__o, double& Pn_dB__o, double& freq_fin__o,
						double* cHarbin, double* cHarbin_disturb);

M2C_API void inldnl(double* csamples, int cnumbit, int cnumpt, double cT1, double cT2, 
                    double cT_ideal_1, double cT_ideal_2, double* cINLar__o, double* cDNLar__o,
                    double* cH__o, int& cindexl__o, int& cindexh__o) ;

M2C_API void DualToneTest64k(double* cADout, double cfclk, int cnumbit, double cV, int ctone_code, double cf1, double cf2, 
							 int cspan_dc, int cspan_s, int cspan_har,
							 double *cADout_dB, double* cmarker, double& cFo1, double& cF1_dBFS, double& cFo2, double& cF2_dBFS, 
							 double& cSFDR, double& cSFDR_dBFS, double& cIMD2_Worst, double& cIMD2_w_dBFS, 
							 double& cIMD3_Worst, double& cIMD3_w_dBFS) ;

M2C_API void AdcDynTest64k(double* cADout, double cfclk, int cnumbit, double cV, int ctone_code, double cfin_input, 
						   int cspan_dc, int cspan_har, int cspan_s, double& cfreq_fin, double& cVin, double& cVpp, 
						   double& cSNR, double& cSFDR, double& cSINAD, double& cTHD, double& cPn_dB, int& cdisturb_len, double& cref_dB,
						   double* cADout_dB, double* cHD, double* cHarbin, double* cHarbin_disturb);

//M2C_API void FFT(double* data, int data_cnt, double* result, int result_cnt);
//M2C_API void FFT_complex(double* r_data, double* i_data, int data_cnt, double* result, int result_cnt);

#ifdef __cplusplus

} 

#endif
