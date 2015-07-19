#pragma once
#include "..\tbcommon\tboxcomponent.h"

class CTbtest :
	public CTBoxComponent
{
public:
	CTbtest(void);
	~CTbtest(void);

	virtual void OnInit(CTboxConext *context);

	virtual void OnDestory();

};
