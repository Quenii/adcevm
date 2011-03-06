/*
 * MATLAB Compiler: 4.0 (R14)
 * Date: Sun Sep 19 23:06:40 2010
 * Arguments: "-B" "macro_default" "-B" "csharedlib:libadc" "-W" "lib:libadc"
 * "-T" "link:lib" "-W" "lib:libadc" "-T" "link:lib" "AdcDynTest.m" "-v" 
 */

#include <stdio.h>
#include "libadc.h"
#ifdef __cplusplus
extern "C" {
#endif
extern const unsigned char __MCC_libadc_public_data[];
extern const char *__MCC_libadc_name_data;
extern const char *__MCC_libadc_root_data;
extern const unsigned char __MCC_libadc_session_data[];
extern const char *__MCC_libadc_matlabpath_data[];
extern const int __MCC_libadc_matlabpath_data_count;
extern const char *__MCC_libadc_mcr_runtime_options[];
extern const int __MCC_libadc_mcr_runtime_option_count;
extern const char *__MCC_libadc_mcr_application_options[];
extern const int __MCC_libadc_mcr_application_option_count;
#ifdef __cplusplus
}
#endif


static HMCRINSTANCE _mcr_inst = NULL;


#if defined( _MSC_VER) || defined(__BORLANDC__) || defined(__WATCOMC__) || defined(__LCC__)
#include <windows.h>

static char path_to_dll[_MAX_PATH];

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, void *pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        char szDllPath[_MAX_PATH];
        char szDir[_MAX_DIR];
        if (GetModuleFileName(hInstance, szDllPath, _MAX_PATH) > 0)
        {
             _splitpath(szDllPath, path_to_dll, szDir, NULL, NULL);
            strcat(path_to_dll, szDir);
        }
	else return FALSE;
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }
    return TRUE;
}
#endif
static int mclDefaultPrintHandler(const char *s)
{
    return fwrite(s, sizeof(char), strlen(s), stdout);
}

static int mclDefaultErrorHandler(const char *s)
{
    int written = 0, len = 0;
    len = strlen(s);
    written = fwrite(s, sizeof(char), len, stderr);
    if (len > 0 && s[ len-1 ] != '\n')
        written += fwrite("\n", sizeof(char), 1, stderr);
    return written;
}

bool libadcInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler
)
{
    if (_mcr_inst != NULL)
        return true;
    if (!mclmcrInitialize())
        return false;
    if (!mclInitializeComponentInstance(&_mcr_inst, __MCC_libadc_public_data,
                                        __MCC_libadc_name_data,
                                        __MCC_libadc_root_data,
                                        __MCC_libadc_session_data,
                                        __MCC_libadc_matlabpath_data,
                                        __MCC_libadc_matlabpath_data_count,
                                        __MCC_libadc_mcr_runtime_options,
                                        __MCC_libadc_mcr_runtime_option_count,
                                        true, NoObjectType, LibTarget,
                                        path_to_dll, error_handler,
                                        print_handler))
        return false;
    return true;
}

bool libadcInitialize(void)
{
    return libadcInitializeWithHandlers(mclDefaultErrorHandler,
                                        mclDefaultPrintHandler);
}

void libadcTerminate(void)
{
    if (_mcr_inst != NULL)
        mclTerminateInstance(&_mcr_inst);
}


void mlxAdcdyntest(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    mclFeval(_mcr_inst, "adcdyntest", nlhs, plhs, nrhs, prhs);
}

void mlfAdcdyntest(int nargout, mxArray** SNR, mxArray** SINAD
                   , mxArray** SFDR, mxArray** ENOB, mxArray* data
                   , mxArray* numpt, mxArray* fclk, mxArray* numbit)
{
    mclMlfFeval(_mcr_inst, "adcdyntest", nargout, 4, 4, SNR,
                SINAD, SFDR, ENOB, data, numpt, fclk, numbit);
}