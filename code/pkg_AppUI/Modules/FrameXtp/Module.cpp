#include "stdafx.h"
#include <afxdllx.h>
#include <Module/XModuleMacro.h>
#include <Module/XModuleImpl.h>

#include "Cx_FrameWndFactory.h"

XBEGIN_DEFINE_MODULE()
    XDEFINE_CLASSMAP_ENTRY(x3::CLSID_FrameWndFactory, Cx_FrameWndFactory)
XEND_DEFINE_MODULE_MFCEXTDLL()
