#pragma once

class Include1
{
public:
	Include1(){}
	~Include1(){}
	inline const char* getText()
	{
		#ifdef CHECK_DEFINED
			return "confirmed";
		#else
			return "NOOOOO";
		#endif
	}
};
