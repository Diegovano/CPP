#pragma once
#include <iostream>

template<class _Ty>
void LowLog(_Ty toLog)
{
	#ifdef DEBUG
	std::cout << "LOW_LOG: " << toLog << std::endl;
	#endif
}

template<class _Ty>
void Log(_Ty toLog)
{
	std::cout << "LOG: " << toLog << std::endl;
}

template<class _Ty, class... _Others>
void Log(_Ty toLog, _Others... toLogEx)
{
	std::cout << "LOG: " << toLog << toLogEx << std::endl;
}

template<class _Ty>
void Error(_Ty toError)
{
	std::cerr << "ERROR: " << toError << std::endl;
}