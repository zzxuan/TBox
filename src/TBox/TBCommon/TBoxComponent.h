#pragma once

#include <Windows.h>
#include "TBoxContext.h"

class CTBoxComponent
{
public:
	CTBoxComponent(void){};

	virtual void OnInit(CTboxConext *context) = 0;
	virtual void OnDestory() = 0;
};