//------------------------------------------------------------------------------
//
//                    Generated by VCL C++ .NET FrontEnd.
//                   (C)Copyright Boian Mitov 2005 - 2009
//                              www.mitov.com
//
//------------------------------------------------------------------------------
#ifndef CSLPairCode_H_
#define CSLPairCode_H_

//------------------------------------------------------------------------------
inline CTSLPair::CTSLPair() :
  InputPins( GetInstance(), _T( "InputPins" ) ),
  OutputPin( GetInstance(), _T( "OutputPin" ) )
{
  LibraryHandle = ::Get_SignalLabBasicPkgCB6();
  CLPComponent::OpenComponent( _T( "TSLPair" ) );
}
//------------------------------------------------------------------------------
inline TLPFunctionEntry CTSLPair::GetFunction( const char *function_name )
{
  TLPFunctionEntry Result = VCL_GetFunction( LibraryHandle, function_name );
  if( Result )
    return Result;

  return inherited::GetFunction( function_name );
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#endif   // CSLPairCode_H_
//------------------------------------------------------------------------------