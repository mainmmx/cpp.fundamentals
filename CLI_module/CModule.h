/*
 * CModule.h
 *
 *  Created on: Aug 8, 2013
 *      Author: mmx
 */

#ifndef CMODULE_H_
#define CMODULE_H_

#include "GlobalConstants.h"
#include <string>

typedef enum
{
	C_INTEGER,
	C_STRING
} e_paramType;

struct s_param
{
	std::string name;
	e_paramType type;
	void* value;
};

struct s_threadArgs
{
	s_param* params;
	int paramsNumber;
};

class CModule
{
private:
	std::string m_name;
	void* (*m_threadFunction)(void* threadArgs);
	s_param* m_params;
	int m_paramsNumber;
public:
//	CModule();
	CModule(
			const std::string & name,
			void* (*threadFunction)(void* threadArgs),
			s_param* params,
			int paramsNumber);
	~CModule();
};

#endif /* CMODULE_H_ */
