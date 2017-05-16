#include "query.h"

int sjtu::transfer_date(const QString & str)
{
	/*
	int ans = 0, line = 0;
	int i;
	//2017/4/1
	for (i = 0; i < 4; ++i) {
		ans = ans * 10 + (str[i].unicode() - '0');
	}
	++i;
	//4/1
	if (str[i + 1] == '/')
		ans *= 10;
	ans = ans * 10 + (str[i++].unicode() - '0');
	++i;
	if (i == str.length() - 1)
		ans *= 10;
	ans = ans * 10 + (str[i].unicode() - '0');
	*/
	QStringList date_parts = str.split('/');
	int date = 0;
	for (int i = 0; i < 4; ++i)
		date = date * 10 + (date_parts[0][i].toLatin1() - '0');
	date = date * 100;
	if (date_parts[1][1].toLatin1() >= '0' && date_parts[1][1].toLatin1() <= '9') {
		date += 10 * (date_parts[1][0].toLatin1() - '0');
		date += date_parts[1][1].toLatin1() - '0';
	} else date += date_parts[1][0].toLatin1() - '0';
	date *= 100;
	if (date_parts[2][1].toLatin1() >= '0' && date_parts[2][1].toLatin1() <= '9') {
		date += 10 * (date_parts[2][0].toLatin1() - '0');
		date += date_parts[2][1].toLatin1() - '0';
	} else date += date_parts[2][0].toLatin1() - '0';
	return date;
	/*
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
			++line;
		}*/
		/*else if(str[i + 1] == '1')
		{
			if(str[i + 2] == '/')
				ans *= 10;
			else continue;
		}
		else ans *= 10;*/
//    }
   // return ans;
}
