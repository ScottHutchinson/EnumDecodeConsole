#pragma once
#include "Constants.h"

#define MAX_DST         (655360) //must match m_szMsgData allocation in Base_GML_OutputUtil.h
#define MAX_TMP         (65535) //must match m_szWorkStr allocation in Base_GML_OutputUtil.h

using std::string;
using std::unordered_map;

using enum_class_name = char*;
typedef const string(*pfnEnumDecode)(const int idx);
typedef unordered_map<enum_class_name, pfnEnumDecode> enum_decode_map;

class CBase_OutputUtil {
public:
    CBase_OutputUtil() = default;
    ~CBase_OutputUtil() = default;

    enum_decode_map m_enumDecodeMap; // A map for retrieving a pointer to an enum decode function given the name of an enum class.

	using DWORD = unsigned long;
	DWORD m_dxData[MAX_DST]{}; // This represents the message data that would be passed to a CVerxxxxxx_GML_OutputUtil instance from a function handler.
	char		m_szMsgData[MAX_DST]{};							// Main work string
	char		m_szWorkStr[MAX_TMP]{};							// Secondary work string
    const string DecodeEnum(const enum_class_name enumClassName, const int idx);

    void decode_enum(char * dst, const char * fmt, enum_class_name enumClassName, const u32_t idx, char * tmp);
};
