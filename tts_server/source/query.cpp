#include "../../tts_server/header/query.h"

int sjtu::transfer_date(const QString & str)
{
    int ans = 0, line = 0;
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] != '/')
            ans = ans * 10 + (str[i].unicode() - '0');
        else
        {
            if(!line)
            {
                if(str[i + 1] == '1')
                {
                    if(str[i + 2] == '/') ans *= 10;
                    else continue;
                }
                else ans *= 10;
            }
            else
            {
                if(i == str.length() - 2) ans *= 10;
                else continue;
            }
        }
        /*else if(str[i + 1] == '1')
        {
            if(str[i + 2] == '/')
                ans *= 10;
            else continue;
        }
        else ans *= 10;*/
    }
    return ans;
}
