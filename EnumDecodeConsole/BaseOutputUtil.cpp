#include "stdafx.h"
#include "Base_OutputUtil.h"

// This function finds a pointer to a decode function in a map given
// the name of an enum class, then calls the decode function for the 
// specified index (idx) and returns the string representation of the
// enumerator.
const string CBase_OutputUtil::DecodeEnum(const enum_class_name enumClassName, const int idx) {
    string ret;
    const auto found = m_enumDecodeMap.find(enumClassName);
    if (found == m_enumDecodeMap.end())
    {
        // handle decode function not found for the specified enumClassName value.
        CString notFoundMsg;
        notFoundMsg.Format("%d (Decode not found for %s)", idx, enumClassName);
        //CNGDARTBaseDoc::AddLogEntryToQueue(notFoundMsg.GetString(), LogEntryType::Trace);
        ret = notFoundMsg.GetString();
    }
    else
    {
        pfnEnumDecode pfn = found->second;
        ret = pfn(idx);
    }
    return ret;
}

// hutch: This is the wrapper function used in GML.
void CBase_OutputUtil::decode_enum(char* dst, const char* fmt, enum_class_name enumClassName, const u32_t idx, char* tmp) {
    string stdDecodedValue = DecodeEnum(enumClassName, idx);
    sprintf_s(tmp, MAX_TMP, fmt, stdDecodedValue.c_str());
    strcat_s(dst, MAX_DST, tmp);
}
