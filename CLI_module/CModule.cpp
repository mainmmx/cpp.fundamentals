/*
 * CModule.cpp
 *
 *  Created on: Aug 8, 2013
 *      Author: mmx
 */

#include "CModule.h"

//CModule::CModule()
//{
//	m_name = "";
//	m_threadFunction = NULL;
//	m_params = NULL;
//	m_paramsNumber = 0;
//}

CModule::CModule(
		const std::string & name,
		void* (*threadFunction)(void* threadArgs),
		s_param* params,
		int paramsNumber)
{
	m_name = name;
	m_threadFunction = threadFunction;
//	for (int i = 0; i < paramsNumber; ++i) m_params[i] = params[i];
	m_params = params;
	m_paramsNumber = paramsNumber;
}

CModule::~CModule()
{
	;
}

