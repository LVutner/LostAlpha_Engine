//=============================================================================
//  Filename:   UIGameLog.h
//	Created by Vitaly 'Mad Max' Maximov, mad-max@gsc-game.kiev.ua
//	Copyright 2005. GSC Game World
//	---------------------------------------------------------------------------
//  Multiplayer game log window
//=============================================================================

#pragma once

#include "UIScrollView.h"
#include "KillMessageStruct.h"

class CUIXml;
class CUIPdaKillMessage;
class CUIPdaMsgListItem;
class CUIStatic;
class CUITextWnd;

class CUIGameLog: public CUIScrollView
{
public:
							CUIGameLog		();
	CUITextWnd*				AddLogMessage	(LPCSTR msg);
	CUIPdaKillMessage*		AddLogMessage	(KillMessageStruct& msg);
	CUIPdaMsgListItem*		AddPdaMessage	(LPCSTR msg, float delay);
	void					AddChatMessage	(LPCSTR msg, LPCSTR author);
	virtual void			Update			();

	void					SetTextAtrib	(CGameFont* pFont, u32 color);
	u32						GetTextColor	()								{return txt_color;}

private:
	WINDOW_LIST				toDelList;
	float					kill_msg_height;
	u32						txt_color;
	CGameFont*				m_pFont;
};