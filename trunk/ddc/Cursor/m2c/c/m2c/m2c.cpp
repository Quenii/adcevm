// m2c.cpp : Defines the entry point for the DLL application.
//
#include "m2c.h"
#include "matlib.h"
#include "AlgDynTest.h"


#define DECLEAR_Mm(v, d, l) \
	Mm v; v = zeros(l, 1); memcpy(v.addr(), d, l * sizeof(*d)) 
// Mm data1_m = zeros(1, numpt); memcpy(data1_m.addr(), data1, numpt * sizeof(double));

M2C_API void AlgDynTest(double* cdata1, int cdata1_cnt,
						double* cdata2, int cdata2_cnt,
						double cnumpt, double cfclk, double cnumbit, double cr,
						double& cSNR__o, double& cSINAD__o, double& cSFDR__o, double& cENOB__o)
{
	DECLEAR_Mm(data1, cdata1, cdata1_cnt);
	DECLEAR_Mm(data2, cdata2, cdata2_cnt);
	Mm numpt = cnumpt;
	Mm fclk = cfclk;
	Mm numbit = cnumpt; 
	Mm r = cr;

	Mm SNR__o; 
	Mm SINAD__o;
	Mm SFDR__o; 
	Mm ENOB__o;

	AlgDynTest(data1, data2, numpt, fclk, numbit, r, i_o, SNR__o, SINAD__o, SFDR__o,  ENOB__o);

	cSNR__o = SNR__o.r(1, 1); 
	cSINAD__o = SINAD__o.r(1, 1);
	cSFDR__o = SFDR__o.r(1, 1); 
	cENOB__o = ENOB__o.r(1, 1);
}