#include "stdafx.h"
#include "OutputUtil.h"
#include "v57enumdecode.h"
#include "v57struct.h"

OutputUtil::OutputUtil() {
    //v57::initEnumDecodeMap(m_enumDecodeMap);
}

void OutputUtil::CreateOutput46(void* arg) {
    /* This function would normally convert the binary data to which
       arg points into a struct, which would include enum fields
       that need to be decoded into human-readable string descriptions.
    */
    auto const& t = *static_cast<v57::SomeStruct*>(arg);
    decode_enum(m_szMsgData, ";$ ID:$ %s", "Tactical_Ids_t", t.system_activated, m_szWorkStr);
}
