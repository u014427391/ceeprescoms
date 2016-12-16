

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Jul 05 11:04:21 2014
 */
/* Compiler settings for project2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __project2_h_h__
#define __project2_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Iproject2_FWD_DEFINED__
#define __Iproject2_FWD_DEFINED__
typedef interface Iproject2 Iproject2;
#endif 	/* __Iproject2_FWD_DEFINED__ */


#ifndef __project2_FWD_DEFINED__
#define __project2_FWD_DEFINED__

#ifdef __cplusplus
typedef class project2 project2;
#else
typedef struct project2 project2;
#endif /* __cplusplus */

#endif 	/* __project2_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __project2_LIBRARY_DEFINED__
#define __project2_LIBRARY_DEFINED__

/* library project2 */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_project2;

#ifndef __Iproject2_DISPINTERFACE_DEFINED__
#define __Iproject2_DISPINTERFACE_DEFINED__

/* dispinterface Iproject2 */
/* [uuid] */ 


EXTERN_C const IID DIID_Iproject2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("138BD86D-7208-4D55-92AF-7D388F8DB8CC")
    Iproject2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct Iproject2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Iproject2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Iproject2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Iproject2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Iproject2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Iproject2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Iproject2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Iproject2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } Iproject2Vtbl;

    interface Iproject2
    {
        CONST_VTBL struct Iproject2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Iproject2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Iproject2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Iproject2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Iproject2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Iproject2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Iproject2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Iproject2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __Iproject2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_project2;

#ifdef __cplusplus

class DECLSPEC_UUID("4E19AEBB-D321-4A0B-B5B7-B9BE7E723ED4")
project2;
#endif
#endif /* __project2_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


