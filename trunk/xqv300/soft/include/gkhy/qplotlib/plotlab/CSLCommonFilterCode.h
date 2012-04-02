//------------------------------------------------------------------------------
//
//                    Generated by VCL C++ .NET FrontEnd.
//                   (C)Copyright Boian Mitov 2005 - 2009
//                              www.mitov.com
//
//------------------------------------------------------------------------------
#ifndef CSLCommonFilterCode_H_
#define CSLCommonFilterCode_H_

//------------------------------------------------------------------------------
inline CTSLBasicCommonFilter::CTSLBasicCommonFilter() :
  Enabled( GetInstance(), _T( "Enabled" ) )
{
  LibraryHandle = VCL_LoadLibrary( "SignalLabBasicPkgCB6.bpl" );
}
//------------------------------------------------------------------------------
inline TLPFunctionEntry CTSLBasicCommonFilter::GetFunction( const char *function_name )
{
  TLPFunctionEntry Result = VCL_GetFunction( LibraryHandle, function_name );
  if( Result )
    return Result;

  return inherited::GetFunction( function_name );
}
//------------------------------------------------------------------------------
inline CTSLCommonFilter::CTSLCommonFilter() :
  SampleRate( (CTSLCommonFilter *)GetInstance(), &CTSLCommonFilter::GetVC_SampleRate)
{
  LibraryHandle = VCL_LoadLibrary( "SignalLabBasicPkgCB6.bpl" );
}
//------------------------------------------------------------------------------
inline TLPFunctionEntry CTSLCommonFilter::GetFunction( const char *function_name )
{
  TLPFunctionEntry Result = VCL_GetFunction( LibraryHandle, function_name );
  if( Result )
    return Result;

  return inherited::GetFunction( function_name );
}
//------------------------------------------------------------------------------
inline double CTSLCommonFilter::GetVC_SampleRate()
{
  static void *__0_FuncPtr_ = NULL;
  if( __0_FuncPtr_ == NULL )
    __0_FuncPtr_ = (void *)( GetFunction( "@Slcommonfilter@TSLCommonFilter@GetVC_SampleRate$qqrv" ));

  VCLHANDLE __0_ThisPtr_ = Get_VCL_FunctionHandle();

  union
    {
    struct
      {
      DWORD First;
      DWORD Second;
      } Words;
    double Value;
  } __0_RtnValue_;
  __0_RtnValue_.Value = 0;

  if( __0_FuncPtr_ && __0_ThisPtr_ )
    {
    _asm
      {
      push eax
      mov  eax,dword ptr [ __0_ThisPtr_ ]
      call dword ptr [ __0_FuncPtr_ ]
      fstp __0_RtnValue_
      pop  eax
      }
    }

  return __0_RtnValue_.Value;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
inline CTSLCommonRealFilter::CTSLCommonRealFilter() :
  OutputPin( GetInstance(), _T( "OutputPin" ) ),
  InputPin( GetInstance(), _T( "InputPin" ) )
{
  LibraryHandle = VCL_LoadLibrary( "SignalLabBasicPkgCB6.bpl" );
}
//------------------------------------------------------------------------------
inline TLPFunctionEntry CTSLCommonRealFilter::GetFunction( const char *function_name )
{
  TLPFunctionEntry Result = VCL_GetFunction( LibraryHandle, function_name );
  if( Result )
    return Result;

  return inherited::GetFunction( function_name );
}
//------------------------------------------------------------------------------
inline CTSLCommonComplexFilter::CTSLCommonComplexFilter() :
  OutputPin( GetInstance(), _T( "OutputPin" ) ),
  InputPin( GetInstance(), _T( "InputPin" ) )
{
  LibraryHandle = VCL_LoadLibrary( "SignalLabBasicPkgCB6.bpl" );
}
//------------------------------------------------------------------------------
inline TLPFunctionEntry CTSLCommonComplexFilter::GetFunction( const char *function_name )
{
  TLPFunctionEntry Result = VCL_GetFunction( LibraryHandle, function_name );
  if( Result )
    return Result;

  return inherited::GetFunction( function_name );
}
//------------------------------------------------------------------------------
inline CTSLCommonIntegerFilter::CTSLCommonIntegerFilter() :
  OutputPin( GetInstance(), _T( "OutputPin" ) ),
  InputPin( GetInstance(), _T( "InputPin" ) )
{
  LibraryHandle = VCL_LoadLibrary( "SignalLabBasicPkgCB6.bpl" );
}
//------------------------------------------------------------------------------
inline TLPFunctionEntry CTSLCommonIntegerFilter::GetFunction( const char *function_name )
{
  TLPFunctionEntry Result = VCL_GetFunction( LibraryHandle, function_name );
  if( Result )
    return Result;

  return inherited::GetFunction( function_name );
}
//------------------------------------------------------------------------------
inline CTSLCommonBinaryFilter::CTSLCommonBinaryFilter() :
  OutputPin( GetInstance(), _T( "OutputPin" ) ),
  InputPin( GetInstance(), _T( "InputPin" ) )
{
  LibraryHandle = VCL_LoadLibrary( "SignalLabBasicPkgCB6.bpl" );
}
//------------------------------------------------------------------------------
inline TLPFunctionEntry CTSLCommonBinaryFilter::GetFunction( const char *function_name )
{
  TLPFunctionEntry Result = VCL_GetFunction( LibraryHandle, function_name );
  if( Result )
    return Result;

  return inherited::GetFunction( function_name );
}
//------------------------------------------------------------------------------
#endif   // CSLCommonFilterCode_H_
//------------------------------------------------------------------------------