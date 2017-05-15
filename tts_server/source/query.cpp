#include "../../tts_server/header/query.h"

sjtu:: transfer_date(const QString & str)
{
    int ans = 0;
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] != '/')
            ans = ans * 10 + (str[i].unicode() - '0');
    }
    return ans;
}
