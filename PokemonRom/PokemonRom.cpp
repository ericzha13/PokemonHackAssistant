#include "stdafx.h"
#include "PokemonRom.h"

LPCTSTR	rgszRomName[] =
{
	L"红宝石（日文版）",	// ruby jp
	L"蓝宝石（日文版）",	// sapphire jp
	L"红宝石（英文版）",	// ruby en
	L"蓝宝石（英文版）",	// sapphire en
	L"火红（日文版）",	// fire jp
	L"叶绿（日文版）",	// leaf jp
	L"火红（英文版）",	// fire en
	L"叶绿（英文版）",	// leaf en
	L"绿宝石（日文版）",	// emerald jp
	L"绿宝石（英文版）",	// emerald en
};

WORD wItemCounts[] =
{
	0x15D,		// ruby jp
	0x15D,		// sapphire jp
	0x15D,		// ruby en
	0x15D,		// sapphire en
	0x177,		// fire jp
	0x177,		// leaf jp
	0x177,		// fire en
	0x177,		// leaf en
	0x179,		// emerald jp
	0x179,		// emerald en
};

DWORD dwEncCounts[] =
{
	0x61,		// ruby jp
	0x61,		// sapphire jp
	0x61,		// ruby en
	0x61,		// sapphire en
	0x84,		// fire jp
	0x84,		// leaf jp
	0x84,		// fire en
	0x84,		// leaf en
	0x7C,		// emerald jp
	0x7C,		// emerald en
};

DWORD dwEncListEntryCounts[] =
{
	ENC_LAND_ENTRY_COUNT,	// enc_land
	ENC_WATER_ENTRY_COUNT,	// enc_water
	ENC_STONE_ENTRY_COUNT,	// enc_stone
	ENC_FISH_ENTRY_COUNT,	// enc_fish
};

DWORD dwEncListSizes[] =
{
	0x1F14,		// ruby jp
	0x1F14,		// sapphire jp
	0x1F14,		// ruby en
	0x1F14,		// sapphire en
	0x2918,		// fire jp
	0x2918,		// leaf jp
	0x2918,		// fire en
	0x2918,		// leaf en
	0x2564,		// emerald jp
	0x2564,		// emerald en
};

DWORD dwLvlupLearnListSizes[] =
{
	0x223E,		// ruby jp
	0x223E,		// sapphire jp
	0x223E,		// ruby en
	0x223E,		// sapphire en
	0x22BE,		// fire jp
	0x22C2,		// leaf jp
	0x22BE,		// fire en
	0x22C2,		// leaf en
	0x223E,		// emerald jp
	0x223E,		// emerald en
};

DWORD dwDeriveLearnListSizes[] =
{
	0x08E6,		// ruby jp
	0x08E6,		// sapphire jp
	0x08E6,		// ruby en
	0x08E6,		// sapphire en
	0x08E6,		// fire jp
	0x08E6,		// leaf jp
	0x08E6,		// fire en
	0x08E6,		// leaf en
	0x08E6,		// emerald jp
	0x08E6,		// emerald en
};

/////////////////////////////////////////////////
DWORD BREED_LIST_ADDRESS[] =
{
	0x001D09CC,		// ruby jp
	0x001D095C,		// sapphire jp
	0x001FEC18,		// ruby en
	0x001FEBA8,		// sapphire en
	0x0021118C,		// fire jp
	0x00211168,		// leaf jp
	0x00254784,		// fire en
	0x00254760,		// leaf en
	0x002F0D54,		// emerald jp
	0x003203CC,		// emerald en
};

DWORD DEOXYS_BREED_ABILITIES_ADDRESS[] =
{
	0x00000000,		// ruby jp
	0x00000000,		// sapphire jp
	0x00000000,		// ruby en
	0x00000000,		// sapphire en
	0x0021AA2E,		// fire jp
	0x0021AA0E,		// leaf jp
	0x0025E026,		// fire en
	0x0025E006,		// leaf en
	0x002FA6D6,		// emerald jp
	0x00329D48,		// emerald en
};

DWORD POKEDEX_HOUEN_ORDER_ADDRESS[] =
{
	0x001CDF94,		// ruby jp
	0x001CDF24,		// sapphire jp
	0x001FC1E0,		// ruby en
	0x001FC170,		// sapphire en
	0x0020E6C0,		// fire jp
	0x0020E69C,		// leaf jp
	0x00251CB8,		// fire en
	0x00251C94,		// leaf en
	0x002EE2D4,		// emerald jp
	0x0031D94C,		   		// emerald en
};

DWORD POKEDEX_KANTO_ORDER_ADDRESS[] =
{
	0x001CE2CA,		// ruby jp
	0x001CE25A,		// sapphire jp
	0x001FC516,		// ruby en
	0x001FC4A6,		// sapphire en
	0x0020E9F6,		// fire jp
	0x0020E9D2,		// leaf jp
	0x00251FEE,		// fire en
	0x00251FCA,		// leaf en
	0x002EE60A,		// emerald jp
	0x0031DC82,		// emerald en
};

DWORD EXP_LIST_ADDRESS[] =
{
	0x001CFD2C,		// ruby jp
	0x001CFCBC,		// sapphire jp
	0x001FDF78,		// ruby en
	0x001FDF08,		// sapphire en
	0x002104EC,		// fire jp
	0x002104C8,		// leaf jp
	0x00253AE4,		// fire en
	0x00253AC0,		// leaf en
	0x002F00B4,		// emerald jp
	0x0031F72C,		// emerald en
};

DWORD EVO_LIST_ADDRESS[] =
{
	0x001D591C,		// ruby jp
	0x001D58AC,		// sapphire jp
	0x00203B68,		// ruby en
	0x00203AF8,		// sapphire en
	0x0021615C,		// fire jp
	0x0021613C,		// leaf jp
	0x00259754,		// fire en
	0x00259734,		// leaf en
	0x002F5CA4,		// emerald jp
	0x0032531C,		// emerald en
};

DWORD ITEM_LIST_ADDRESS[] =
{
	0x0039A648,		// ruby jp
	0x0039A62C,		// sapphire jp
	0x003C5564,		// ruby en
	0x003C55BC,		// sapphire en
	0x003A06F8,		// fire jp
	0x003A0568,		// leaf jp
	0x003DB028,		// fire en
	0x003DAE64,		// leaf en
	0x0055CEE8,		// emerald jp
	0x005839A0,		// emerald en
};

DWORD SKILL_LIST_ADDRESS[] =
{
	0x001CCEE0,		// ruby jp
	0x001CCE70,		// sapphire jp
	0x001FB12C,		// ruby en
	0x001FB0BC,		// sapphire en
	0x0020D60C,		// fire jp
	0x0020D5E8,		// leaf jp
	0x00250C04,		// fire en
	0x00250BE0,		// leaf en
	0x002ED220,		// emerald jp
	0x0031C898,		// emerald en
};

DWORD ENC_ADDR_LIST_ADDRESS[] =
{
	0x00379304,		// ruby jp
	0x003792FC,		// sapphire jp
	0x0039D454,		// ruby en
	0x0039D29C,		// sapphire en
	0x00390B34,		// fire jp
	0x003909A4,		// leaf jp
	0x003C9CB8,		// fire en
	0x003C9AF4,		// leaf en
	0x0052D9F4,		// emerald jp
	0x00552D48,		// emerald en
};

DWORD ENC_LIST_ADDRESS[] =
{
	0x003773F0,		// ruby jp
	0x003773E8,		// sapphire jp
	0x0039B540,		// ruby en
	0x0039B388,		// sapphire en
	0x0038E21C,		// fire jp
	0x0038E08C,		// leaf jp
	0x003C73A0,		// fire en
	0x003C71DC,		// leaf en
	0x0052B490,		// emerald jp
	0x005507E4,		// emerald en
};

DWORD ANNOON_ENC_LIST_ADDRESS[] =
{
	0x00000000,		// doesn't exist in ruby jp
	0x00000000,		// doesn't exist in sapphire jp
	0x00000000,		// doesn't exist in ruby en
	0x00000000,		// doesn't exist in sapphire en
	0x00391598,		// fire jp
	0x00391408,		// leaf jp
	0x003CA71C,		// fire en
	0x003CA558,		// leaf en
	0x00000000,		// doesn't exist in emerald jp
	0x00000000,		// doesn't exist in emerald en
};

DWORD LVLUP_LEARN_ADDR_LIST_ADDRESS[] =
{
	0x001D997C,		// ruby jp
	0x001D990C,		// sapphire jp
	0x00207BC8,		// ruby en
	0x00207B58,		// sapphire en
	0x0021A1BC,		// fire jp
	0x0021A19C,		// leaf jp
	0x0025D7B4,		// fire en
	0x0025D794,		// leaf en
	0x002F9D04,		// emerald jp
	0x0032937C,		// emerald en
};

DWORD LVLUP_LEARN_LIST_ADDRESS[] =
{
	0x001D36DC,		// ruby jp
	0x001D366C,		// sapphire jp
	0x00201928,		// ruby en
	0x002018B8,		// sapphire en
	0x00213E9C,		// fire jp
	0x00213E78,		// leaf jp
	0x00257494,		// fire en
	0x00257470,		// leaf en
	0x002F3A64,		// emerald jp
	0x003230DC,		// emerald en
};

DWORD MACHINE_LEARN_LIST_ADDRESS[] =
{
	0x001CEEA4,		// ruby jp
	0x001CEE34,		// sapphire jp
	0x001FD0F0,		// ruby en
	0x001FD080,		// sapphire en
	0x0020F5D0,		// fire jp
	0x0020F5AC,		// leaf jp
	0x00252BC8,		// fire en
	0x00252BA4,		// leaf en
	0x002EF220,		// emerald jp
	0x0031E898,		// emerald en
};

DWORD MACHINE_SKILL_LIST_ADDRESS[] =
{
	0x0035017C,		// ruby jp
	0x0035010C,		// sapphire jp
	0x00376504,		// ruby en
	0x00376494,		// sapphire en
	0x00419D34,		// fire jp
	0x00419CBC,		// leaf jp
	0x0045A5A4,		// fire en
	0x00459FC4,		// leaf en
	0x005E144C,		// emerald jp
	0x00615B94,		// emerald en
};

DWORD DERIVE_LEARN_LIST_ADDRESS[] =
{
	0x001DAF78,		// ruby jp
	0x001DAF08,		// sapphire jp
	0x002091DC,		// ruby en
	0x0020916C,		// sapphire en
	0x0021B918,		// fire jp
	0x0021B8F8,		// leaf jp
	0x0025EF0C,		// fire en
	0x0025EEEC,		// leaf en
	0x002FB764,		// emerald jp
	0x0032ADD8,		// emerald en
};

DWORD BERRY_LIST_ADDRESS[] =
{
	0x003A1050,		// ruby jp
	0x003A1034,		// sapphire jp
	0x003CD2CC,		// ruby en
	0x003CD324,		// sapphire en
	0x003A48DC,		// fire jp
	0x003A474C,		// leaf jp
	0x003DF7E8,		// fire en
	0x003DF624,		// leaf en
	0x00563150,		// emerald jp
	0x0058A670,		// emerald en
};

DWORD SMALL_ICON_PALETTE_LIST_ADDRESS[] =
{
	0x00391A38,		// ruby jp
	0x00391A1C,		// sapphire jp
	0x00E966D8,		// ruby en
	0x00E966D8,		// sapphire en
	0x0039BC48,		// fire jp
	0x0039BAB8,		// leaf jp
	0x003D3740,		// fire en
	0x003D357C,		// leaf en
	0x005567A4,		// emerald jp
	0x00DDE1F8,		// emerald en
};

DWORD SMALL_ICON_ADDRESS_LIST_ADDRESS[] =
{
	0x00391A98,		// ruby jp
	0x00391A7C,		// sapphire jp
	0x003BBD20,		// ruby en
	0x003BBD78,		// sapphire en
	0x0039BCA8,		// fire jp
	0x0039BB18,		// leaf jp
	0x003D37A0,		// fire en
	0x003D35DC,		// leaf en
	0x00556804,		// emerald jp
	0x0057BCA8,		// emerald en
};

DWORD SMALL_ICON_PALETTE_INDEX_LIST_ADDRESS[] =
{
	0x00392178,		// ruby jp
	0x0039215C,		// sapphire jp
	0x003BC400,		// ruby en
	0x003BC458,		// sapphire en
	0x0039C388,		// fire jp
	0x0039C1F8,		// leaf jp
	0x003D3E80,		// fire en
	0x003D3CBC,		// leaf en
	0x00556EE4,		// emerald jp
	0x0057C388,		// emerald en
};

DWORD DEOXYS_ICON_EXTRA_ENTRY_COUNT[] =
{
	0,		// ruby jp
	0,		// sapphire jp
	0,		// ruby en
	0,		// sapphire en
	1,		// fire jp
	1,		// leaf jp
	1,		// fire en
	1,		// leaf en
	1,		// emerald jp
	1,		// emerald en
};

///////////////////////////////////////////////////////////////////////////////////////////////////
LPCTSTR szTypes[] =
{
	L"普通",	// 00
	L"格斗",	// 01
	L"飞行",	// 02
	L"毒",		// 03
	L"地面",	// 04
	L"岩石",	// 05
	L"虫",		// 06
	L"鬼",		// 07
	L"钢",		// 08
	L"？？？",	// 09
	L"炎",		// 0A
	L"水",		// 0B
	L"草",		// 0C
	L"电",		// 0D
	L"超能",	// 0E
	L"氷",		// 0F
	L"龙",		// 10
	L"恶"		// 11
};

DWORD dwTypesCount = sizeof(szTypes) / sizeof(szTypes[0]);

LPCTSTR szEggGroups[] =
{
	L"？？？",		// 00
	L"怪兽",		// 01
	L"水中１",		// 02
	L"虫",			// 03
	L"飞行",		// 04
	L"陆上",		// 05
	L"妖精",		// 06
	L"植物",		// 07
	L"人形",		// 08
	L"水中３",		// 09
	L"矿物",		// 0A
	L"不定形",		// 0B
	L"水中２",		// 0C
	L"百变怪",		// 0D
	L"龙",			// 0E
	L"未发现"		// 0F
};

DWORD dwEggGroupsCount = sizeof(szEggGroups) / sizeof(szEggGroups[0]);

EvoConditions	rgEvoConditions[] =
{
	{ L"不能进化",					L"没有参数",		evo_none },		// 00
	{ L"亲密度达到220",			L"没有参数",		evo_none },		// 01
	{ L"亲密度达到220，晚",		L"没有参数",		evo_none },		// 02
	{ L"亲密度达到220，早",		L"没有参数",		evo_none },		// 03
	{ L"升级",						L"最低等级",		evo_level },	// 04
	{ L"通信交换",					L"没有参数",		evo_none },		// 05
	{ L"通信交换，持有特定道具",	L"道具编号",		evo_item },		// 06
	{ L"使用特定道具",				L"道具编号",		evo_item },		// 07
	{ L"升级，攻击>防御",			L"最低等级",		evo_level },	// 08
	{ L"升级，攻击=防御",			L"最低等级",		evo_level },	// 09
	{ L"升级，攻击<防御",			L"最低等级",		evo_level },	// 0A
	{ L"升级，性格值%10<5",		L"最低等级",		evo_level },	// 0B
	{ L"升级，性格值%10>=5",		L"最低等级",		evo_level },	// 0C
	{ L"升级，不持有道具",		L"最低等级",		evo_level },	// 0D
	{ L"升级，持有道具",			L"最低等级",		evo_level },	// 0E
	{ L"美丽值",					L"最低美丽值",		evo_beauty }	// 0F
};

DWORD dwEvoConditionsCount = sizeof(rgEvoConditions) / sizeof(rgEvoConditions[0]);

SkillTargetType	rgSkillTargetTypes[] =
{
	{ 0x00, L"敌单体" },		// 00
	{ 0x01, L"不定" },			// 01
	//{ 0x02, L"？？？" },		// 02
	{ 0x04, L"敌或自身" },		// 04
	{ 0x08, L"敌全体" },		// 08
	{ 0x10, L"自身" },			// 10
	{ 0x20, L"自身以外" },		// 20
	{ 0x40, L"全体" },			// 40
	//{ 0x80, L"？？？" }		// 80
};

DWORD	dwSkillTargetTypesCount = sizeof(rgSkillTargetTypes) / sizeof(rgSkillTargetTypes[0]);

DWORD GetTargetTypeIndex(BYTE bTargetType)
{
	DWORD	dwIndex;

	for(dwIndex = 0; dwIndex < dwSkillTargetTypesCount; ++dwIndex)
	{
		if(bTargetType == rgSkillTargetTypes[dwIndex].bCode)
			break;
	}
	if(dwIndex >= dwSkillTargetTypesCount)
		dwIndex = -1;

	return dwIndex;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
CPokemonRom::CPokemonRom(VOID)
{
	m_bOpened = FALSE;
	m_pRomFile = NULL;
	m_dwOpenFlags = 0;
	m_bIsFileReadOnly = TRUE;
	m_dwRomVersion = rom_emerald_jp;

	m_pSmallIconList = NULL;
	m_pTinyIconList = NULL;
	m_rghbmSmallIcons = NULL;

	m_pBreedList = NULL;
	m_pDeoxysBreedAblities = NULL;
	m_pPokedexHouenOrder = NULL;
	m_pPokedexKantoOrder = NULL;
	m_pExpList = NULL;
	m_pEvoList = NULL;
	m_pItemList = NULL;
	m_pSkillList = NULL;
	m_pEncAddressList = NULL;
	m_pEncList = NULL;
	m_pAnnoonEncList = NULL;
	m_pLvlupLearnAddressList = NULL;
	m_pLvlupLearnList = NULL;
	m_pMachineLearnList = NULL;
	m_pMachineSkillList = NULL;
	m_pDeriveLearnList = NULL;
	m_pDeriveLearnAddressList = NULL;
	m_pBerryList = NULL;
}

CPokemonRom::~CPokemonRom(VOID)
{
	CloseRom();
}

BOOL CPokemonRom::ReadBreedList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	try
	{
		if(!m_bOpened)
			throw 0;

		if(m_pRomFile)
		{
			m_pRomFile->Seek(BREED_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pBreedList, BREED_COUNT * sizeof(BreedListEntry)) !=
				BREED_COUNT * sizeof(BreedListEntry))
				throw 0;

			if(DEOXYS_BREED_ABILITIES_ADDRESS[m_dwRomVersion] != 0x00000000)
			{
				m_pRomFile->Seek(DEOXYS_BREED_ABILITIES_ADDRESS[m_dwRomVersion], CFile::begin);
				if(m_pRomFile->Read(m_pDeoxysBreedAblities, ABILITY_COUNT * sizeof(WORD)) !=
					ABILITY_COUNT * sizeof(WORD))
					throw 0;
			}
		}
		else
		{
			if(!lpVbaRam->ReadRom(BREED_LIST_ADDRESS[m_dwRomVersion],
									BREED_COUNT * sizeof(BreedListEntry),
									m_pBreedList))
				throw 0;

			if(DEOXYS_BREED_ABILITIES_ADDRESS[m_dwRomVersion] != 0x00000000)
			{
				if(!lpVbaRam->ReadRom(DEOXYS_BREED_ABILITIES_ADDRESS[m_dwRomVersion],
										ABILITY_COUNT * sizeof(WORD),
										m_pDeoxysBreedAblities))
					throw 0;
			}
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadPokedexOrder(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	try
	{
		if(!m_bOpened)
			throw 0;

		if(m_pRomFile)
		{
			m_pRomFile->Seek(POKEDEX_HOUEN_ORDER_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pPokedexHouenOrder + 1, (BREED_COUNT - 1) * sizeof(WORD)) !=
				(BREED_COUNT - 1) * sizeof(WORD))
				throw 0;
			m_pPokedexHouenOrder[0] = 0;

			m_pRomFile->Seek(POKEDEX_KANTO_ORDER_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pPokedexKantoOrder + 1, (BREED_COUNT - 1) * sizeof(WORD)) !=
				(BREED_COUNT - 1) * sizeof(WORD))
				throw 0;
			m_pPokedexKantoOrder[0] = 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(POKEDEX_HOUEN_ORDER_ADDRESS[m_dwRomVersion],
									(BREED_COUNT - 1) * sizeof(WORD),
									m_pPokedexHouenOrder + 1))
				throw 0;
			m_pPokedexHouenOrder[0] = 0;

			if(!lpVbaRam->ReadRom(POKEDEX_KANTO_ORDER_ADDRESS[m_dwRomVersion],
									(BREED_COUNT - 1) * sizeof(WORD),
									m_pPokedexKantoOrder + 1))
				throw 0;
			m_pPokedexKantoOrder[0] = 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadExpList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	try
	{
		if(!m_bOpened)
			throw 0;

		if(m_pRomFile)
		{
			m_pRomFile->Seek(EXP_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pExpList, EXP_COUNT * EXP_LIST_COUNT * sizeof(DWORD)) !=
				EXP_COUNT * EXP_LIST_COUNT * sizeof(DWORD))
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(EXP_LIST_ADDRESS[m_dwRomVersion],
									EXP_COUNT * EXP_LIST_COUNT * sizeof(DWORD),
									m_pExpList))
				throw 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadEvoList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	try
	{
		if(!m_bOpened)
			throw 0;

		if(m_pRomFile)
		{
			m_pRomFile->Seek(EVO_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pEvoList, BREED_COUNT * EVO_LIST_COUNT * sizeof(EvoListEntry)) != 
				BREED_COUNT * EVO_LIST_COUNT * sizeof(EvoListEntry))
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(EVO_LIST_ADDRESS[m_dwRomVersion],
									BREED_COUNT * EVO_LIST_COUNT * sizeof(EvoListEntry),
									m_pEvoList))
				throw 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadItemList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened)
			throw 0;

		switch(m_dwRomVersion)
		{
		case rom_ruby_jp:
		case rom_sapphire_jp:
		case rom_fire_jp:
		case rom_leaf_jp:
		case rom_emerald_jp:
			dwSize = wItemCounts[m_dwRomVersion] * sizeof(ItemListEntryJP);
			break;

		case rom_ruby_en:
		case rom_sapphire_en:
		case rom_fire_en:
		case rom_leaf_en:
		case rom_emerald_en:
			dwSize = wItemCounts[m_dwRomVersion] * sizeof(ItemListEntryEN);
			break;
		}

		if(m_pRomFile)
		{
			m_pRomFile->Seek(ITEM_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pItemList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(ITEM_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pItemList))
				throw 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadSkillList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened)
			throw 0;

		dwSize = SKILL_COUNT * sizeof(SkillListEntry);

		if(m_pRomFile)
		{
			m_pRomFile->Seek(SKILL_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pSkillList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(SKILL_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pSkillList))
				throw 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadEncList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened)
			throw 0;

		dwSize = dwEncCounts[m_dwRomVersion] * sizeof(EncAddressListEntry);
		if(m_pRomFile)
		{
			m_pRomFile->Seek(ENC_ADDR_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pEncAddressList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(ENC_ADDR_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pEncAddressList))
				throw 0;
		}

		dwSize = dwEncListSizes[m_dwRomVersion];
		if(m_pRomFile)
		{
			m_pRomFile->Seek(ENC_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pEncList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(ENC_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pEncList))
				throw 0;
		}

		dwSize = ANNOON_ENC_AREA_COUNT * ENC_LAND_ENTRY_COUNT;
		if(ANNOON_ENC_LIST_ADDRESS[m_dwRomVersion])
		{
			if(m_pRomFile)
			{
				m_pRomFile->Seek(ANNOON_ENC_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
				if(m_pRomFile->Read(m_pAnnoonEncList, dwSize) != dwSize)
					throw 0;
			}
			else
			{
				if(!lpVbaRam->ReadRom(ANNOON_ENC_LIST_ADDRESS[m_dwRomVersion],
										dwSize,
										m_pAnnoonEncList))
					throw 0;
			}
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadLvlupLearnList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened)
			throw 0;

		dwSize = BREED_COUNT * sizeof(DWORD);
		if(m_pRomFile)
		{
			m_pRomFile->Seek(LVLUP_LEARN_ADDR_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pLvlupLearnAddressList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(LVLUP_LEARN_ADDR_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pLvlupLearnAddressList))
				throw 0;
		}

		dwSize = dwLvlupLearnListSizes[m_dwRomVersion];
		if(m_pRomFile)
		{
			m_pRomFile->Seek(LVLUP_LEARN_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pLvlupLearnList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(LVLUP_LEARN_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pLvlupLearnList))
				throw 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadMachineLearnList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened)
			throw 0;

		dwSize = BREED_COUNT * MACHINE_LEARN_ENTRY_SIZE;
		if(m_pRomFile)
		{
			m_pRomFile->Seek(MACHINE_LEARN_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pMachineLearnList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(MACHINE_LEARN_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pMachineLearnList))
				throw 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadMachineSkillList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened)
			throw 0;

		dwSize = MACHINE_COUNT * sizeof(WORD);
		if(m_pRomFile)
		{
			m_pRomFile->Seek(MACHINE_SKILL_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pMachineSkillList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(MACHINE_SKILL_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pMachineSkillList))
				throw 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadDeriveLearnList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened)
			throw 0;

		dwSize = dwDeriveLearnListSizes[m_dwRomVersion];
		if(m_pRomFile)
		{
			m_pRomFile->Seek(DERIVE_LEARN_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pDeriveLearnList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(DERIVE_LEARN_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pDeriveLearnList))
				throw 0;
		}

		CalcDeriveLearnAddressList();
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::ReadBerryList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened)
			throw 0;

		dwSize = BERRY_COUNT * sizeof(BerryListEntry);
		if(m_pRomFile)
		{
			m_pRomFile->Seek(BERRY_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(m_pBerryList, dwSize) != dwSize)
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(BERRY_LIST_ADDRESS[m_dwRomVersion],
									dwSize,
									m_pBerryList))
				throw 0;
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::CreateSmallIconList(CVisualBoyHandler * lpVbaRam)
{
	BOOL	bResult = TRUE;
	DWORD	dwIndex, k, m, n;
	DWORD	dwSubListEntryCount, dwCurSubListEntryCount = 0;
	DWORD	dwSmallIconTotalCount = GetSmallIconTotalCount();

	SmallIconPaletteList *		pSmallIconPaletteList = NULL;
	SmallIconAddressList *		pSmallIconAddressList = NULL;
	SmallIconPaletteIndexList *	pSmallIconPaletteIndexList = NULL;
	SmallIconSubListEntry *		pSmallIconSubList = NULL;
	BYTE						bDIBit, bPaletteIndex;
	LPBITMAPINFO *				rgpBmInfo = NULL;
	LPBYTE						pbDIBits = NULL;	// no allocation
	DWORD						dwDIBIndex, dwByteIndex;
	CDC							dcScr, dcDes;
	CBitmap						bmDes, *pbmOld = NULL, *pbmNull = NULL;

	try
	{
		if(!m_bOpened)
			throw 0;

		// create image list 32x32
		if(m_pTinyIconList)
		{
			m_pTinyIconList->DeleteImageList();
			delete m_pTinyIconList;
			m_pTinyIconList = NULL;
		}
		if(m_dwOpenFlags & rom_tiny_image_list)
		{
			m_pTinyIconList = new CImageList;
			if(m_pTinyIconList == NULL)
				throw 0;

			bResult = m_pTinyIconList->Create(
							SMALL_ICON_BIT_WIDTH,
							SMALL_ICON_BIT_HEIGHT,
							ILC_COLORDDB,
							dwSmallIconTotalCount,
							0);
			if(!bResult)
				throw 0;
		}

		// create image list 64x64
		if(m_pSmallIconList)
		{
			m_pSmallIconList->DeleteImageList();
			delete m_pSmallIconList;
			m_pSmallIconList = NULL;
		}
		if(m_dwOpenFlags & rom_small_image_list)
		{
			m_pSmallIconList = new CImageList;
			if(m_pSmallIconList == NULL)
				throw 0;

			bResult = m_pSmallIconList->Create(
							SMALL_ICON_BIT_WIDTH2,
							SMALL_ICON_BIT_HEIGHT2,
							ILC_COLORDDB,
							dwSmallIconTotalCount,
							0);
			if(!bResult)
				throw 0;
		}

		// create image array 32x32
		if(m_rghbmSmallIcons)
		{
			for(dwIndex = 0; dwIndex < dwSmallIconTotalCount; ++dwIndex)
			{
				if(m_rghbmSmallIcons[dwIndex])
				{
					DeleteObject(m_rghbmSmallIcons[dwIndex]);
					m_rghbmSmallIcons[dwIndex] = NULL;
				}
			}
			delete []m_rghbmSmallIcons;
			m_rghbmSmallIcons = NULL;
		}

		m_rghbmSmallIcons = new HBITMAP[dwSmallIconTotalCount];
		if(m_rghbmSmallIcons == NULL)
			throw 0;
		ZeroMemory(m_rghbmSmallIcons, dwSmallIconTotalCount * sizeof(HBITMAP));

		/////////////////////////////////////////
		// create bitmapinfo
		pSmallIconPaletteList = new SmallIconPaletteList;
		if(pSmallIconPaletteList == NULL)
			throw 0;

		if(m_pRomFile)
		{
			m_pRomFile->Seek(SMALL_ICON_PALETTE_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(pSmallIconPaletteList, sizeof(SmallIconPaletteList)) != sizeof(SmallIconPaletteList))
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(SMALL_ICON_PALETTE_LIST_ADDRESS[m_dwRomVersion],
									sizeof(SmallIconPaletteList),
									pSmallIconPaletteList))
				throw 0;
		}

		rgpBmInfo = new LPBITMAPINFO[SMALL_ICON_PALETTE_LIST_ENTRY_COUNT];
		if(rgpBmInfo == NULL)
			throw 0;
		ZeroMemory(rgpBmInfo, SMALL_ICON_PALETTE_LIST_ENTRY_COUNT * sizeof(LPBITMAPINFO));

		for(dwIndex = 0; dwIndex < SMALL_ICON_PALETTE_LIST_ENTRY_COUNT; ++dwIndex)
		{
			rgpBmInfo[dwIndex] = (LPBITMAPINFO) new BYTE[sizeof(BITMAPINFO) + (SMALL_ICON_PALETTE_LIST_ENTRY_COLOR_COUNT - 1) * sizeof(RGBQUAD)];
			if(rgpBmInfo[dwIndex] == NULL)
				throw 0;

			LPBITMAPINFO	pBmInfo = rgpBmInfo[dwIndex];
			pBmInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
			pBmInfo->bmiHeader.biWidth = SMALL_ICON_BIT_WIDTH;
			pBmInfo->bmiHeader.biHeight = SMALL_ICON_BIT_HEIGHT;
			pBmInfo->bmiHeader.biPlanes = 1;
			pBmInfo->bmiHeader.biBitCount = SMALL_ICON_PALETTE_LIST_ENTRY_COLOR_DEPTH;
			pBmInfo->bmiHeader.biCompression = BI_RGB;
			pBmInfo->bmiHeader.biSizeImage = 0;
			pBmInfo->bmiHeader.biXPelsPerMeter = 0;
			pBmInfo->bmiHeader.biYPelsPerMeter = 0;
			pBmInfo->bmiHeader.biClrUsed = 0;
			pBmInfo->bmiHeader.biClrImportant = 0;

			for(n = 0; n < SMALL_ICON_PALETTE_LIST_ENTRY_COLOR_COUNT; ++n)
			{
				WORD	wColor = pSmallIconPaletteList->rgEntry[dwIndex].rgwColor[n];
				if(n == 0)
				{
					pBmInfo->bmiColors[n].rgbRed	= 0xFF;
					pBmInfo->bmiColors[n].rgbGreen	= 0xFF;
					pBmInfo->bmiColors[n].rgbBlue	= 0xFF;
				}
				else
				{
					pBmInfo->bmiColors[n].rgbRed	= (( wColor        & 0x1F) * 0xFF) / 0x1F;
					pBmInfo->bmiColors[n].rgbGreen	= (((wColor >> 5)  & 0x1F) * 0xFF) / 0x1F;
					pBmInfo->bmiColors[n].rgbBlue	= (((wColor >> 10) & 0x1F) * 0xFF) / 0x1F;
				}
				pBmInfo->bmiColors[n].rgbReserved = 0;
			}
		}

		delete pSmallIconPaletteList;
		pSmallIconPaletteList = NULL;

		/////////////////////////////////////////
		// read other things
		pSmallIconAddressList = new SmallIconAddressList;
		if(pSmallIconAddressList == NULL)
			throw 0;

		pSmallIconPaletteIndexList = new SmallIconPaletteIndexList;
		if(pSmallIconPaletteIndexList == NULL)
			throw 0;

		if(m_pRomFile)
		{
			m_pRomFile->Seek(SMALL_ICON_ADDRESS_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(pSmallIconAddressList, sizeof(SmallIconAddressList)) != sizeof(SmallIconAddressList))
				throw 0;

			m_pRomFile->Seek(SMALL_ICON_PALETTE_INDEX_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			if(m_pRomFile->Read(pSmallIconPaletteIndexList, sizeof(SmallIconPaletteIndexList)) != sizeof(SmallIconPaletteIndexList))
				throw 0;
		}
		else
		{
			if(!lpVbaRam->ReadRom(SMALL_ICON_ADDRESS_LIST_ADDRESS[m_dwRomVersion],
									sizeof(SmallIconAddressList),
									pSmallIconAddressList))
				throw 0;

			if(!lpVbaRam->ReadRom(SMALL_ICON_PALETTE_INDEX_LIST_ADDRESS[m_dwRomVersion],
									sizeof(SmallIconPaletteIndexList),
									pSmallIconPaletteIndexList))
				throw 0;
		}

		/////////////////////////////////////////
		// prepare dc and bm for stretching
		if(m_dwOpenFlags & rom_small_image_list)
		{
			if(!dcScr.CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL))
				throw 0;

			if(!dcDes.CreateCompatibleDC(&dcScr))
				throw 0;

			if(!bmDes.CreateCompatibleBitmap(&dcScr, SMALL_ICON_BIT_WIDTH2, SMALL_ICON_BIT_HEIGHT2))
				throw 0;

			dcScr.DeleteDC();
		}

		/////////////////////////////////////////
		// create each small icon
		dwDIBIndex = 0;
		for(dwIndex = 0; dwIndex < SMALL_ICON_ADDRESS_LIST_ENTRY_COUNT; ++dwIndex)
		{
			if(dwIndex == 410)	// special for ディオキシス
			{
				dwSubListEntryCount =
					(1 + DEOXYS_ICON_EXTRA_ENTRY_COUNT[m_dwRomVersion]) * SMALL_ICON_SUB_LIST_ENTRY_COUNT;
			}
			else
			{
				dwSubListEntryCount = SMALL_ICON_SUB_LIST_ENTRY_COUNT;
			}

			// make sure the memory is large enough to hold the small icons
			if(dwCurSubListEntryCount < dwSubListEntryCount)
			{
				if(pSmallIconSubList)
					delete []pSmallIconSubList;

				dwCurSubListEntryCount = dwSubListEntryCount;
				pSmallIconSubList = new SmallIconSubListEntry[dwCurSubListEntryCount];
				if(pSmallIconSubList == NULL)
					throw 0;
			}

			if(m_pRomFile)
			{
				m_pRomFile->Seek(pSmallIconAddressList->rgdwAddress[dwIndex] & 0x00FFFFFF, CFile::begin);
				if(m_pRomFile->Read(
						pSmallIconSubList,
						dwSubListEntryCount * sizeof(SmallIconSubListEntry)) !=
						dwSubListEntryCount * sizeof(SmallIconSubListEntry))
					throw 0;
			}
			else
			{
				if(!lpVbaRam->ReadRom(pSmallIconAddressList->rgdwAddress[dwIndex] & 0x00FFFFFF,
										dwSubListEntryCount * sizeof(SmallIconSubListEntry),
										pSmallIconSubList))
					throw 0;
			}

			for(k = 0; k < dwSubListEntryCount; ++k)
			{
				SmallIconSubListEntry *pBmEntry = &(pSmallIconSubList[k]);
				bPaletteIndex = pSmallIconPaletteIndexList->rgbPaletteIndex[dwIndex];
				if(bPaletteIndex >= SMALL_ICON_PALETTE_LIST_ENTRY_COUNT)
					bPaletteIndex = 0;

				m_rghbmSmallIcons[dwDIBIndex] =
					CreateDIBSection(
						NULL,
						rgpBmInfo[bPaletteIndex],
						DIB_RGB_COLORS,
						(VOID **)(&pbDIBits),
						NULL,
						0);
				if(m_rghbmSmallIcons[dwDIBIndex] == NULL)
					throw 0;

				for(m = 0; m < SMALL_ICON_BIT_HEIGHT; ++m)
				{
					for(n = 0; n < SMALL_ICON_BYTE_WIDTH; ++n)
					{
						// set dib bits
						bDIBit = pBmEntry->rgTile[m / SMALL_ICON_TILE_BIT_HEIGHT][n / SMALL_ICON_TILE_BTYE_WIDTH].rgbPixel[m % SMALL_ICON_TILE_BIT_HEIGHT][n % SMALL_ICON_TILE_BTYE_WIDTH];
						// bDIBit = pBmEntry->rgTile[m >> 3][n >> 2].rgbPixel[m & 7][n & 3];

						// swap nibles, and make it bottom-up
						dwByteIndex = (SMALL_ICON_BIT_HEIGHT - 1 - m) * SMALL_ICON_BYTE_WIDTH + n;
						pbDIBits[dwByteIndex] = ((bDIBit & 0x0F) << 4) + ((bDIBit >> 4) & 0x0F);
					}
				}

				// 32x32 image list
				if(m_dwOpenFlags & rom_tiny_image_list)
				{
					CBitmap	bm;
					bm.Attach(m_rghbmSmallIcons[dwDIBIndex]);
					if(m_pTinyIconList->Add(&bm, pbmNull) == -1)
					{
						throw 0;
					}
				}

				// 64x64 image list, set to dc and stretch to desired size
				if(m_dwOpenFlags & rom_small_image_list)
				{
					pbmOld = dcDes.SelectObject(&bmDes);
					if(0 == StretchDIBits(
							dcDes.m_hDC,
							0, 0,
							SMALL_ICON_BIT_WIDTH2, SMALL_ICON_BIT_HEIGHT2,
							0, 0,
							SMALL_ICON_BIT_WIDTH, SMALL_ICON_BIT_HEIGHT,
							pbDIBits, rgpBmInfo[bPaletteIndex], DIB_RGB_COLORS, SRCCOPY))
					{
						throw 0;
					}

					CBitmap *pbm = dcDes.SelectObject(pbmOld);

					if(m_pSmallIconList->Add(pbm, pbmNull) == -1)
					{
						throw 0;
					}
				}
				++dwDIBIndex;
			}
		}
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		bResult = FALSE;
		e->Delete();
	}

	if(pSmallIconPaletteList)
		delete pSmallIconPaletteList;

	if(pSmallIconAddressList)
		delete pSmallIconAddressList;

	if(pSmallIconPaletteIndexList)
		delete pSmallIconPaletteIndexList;

	if(pSmallIconSubList)
		delete []pSmallIconSubList;

	if(m_dwOpenFlags & rom_small_image_list)
	{
		dcScr.DeleteDC();
		dcDes.DeleteDC();
		bmDes.DeleteObject();
	}

	if(rgpBmInfo)
	{
		for(dwIndex = 0; dwIndex < SMALL_ICON_PALETTE_LIST_ENTRY_COUNT; ++dwIndex)
		{
			if(rgpBmInfo[dwIndex])
				delete [](LPBYTE)(rgpBmInfo[dwIndex]);
		}
		delete []rgpBmInfo;
	}

	return bResult;
}

VOID CPokemonRom::CalcDeriveLearnAddressList(VOID)
{
	DWORD	dwIndex, dwCount;
	WORD *	rgwSkills = NULL;
	WORD	wSkill, wBreed;

	if(m_bOpened && m_pDeriveLearnList && m_pDeriveLearnAddressList)
	{
		ZeroMemory(m_pDeriveLearnAddressList, BREED_COUNT * sizeof(DWORD));

		rgwSkills = reinterpret_cast<WORD *>(m_pDeriveLearnList);
		dwCount = dwDeriveLearnListSizes[m_dwRomVersion] / sizeof(WORD);

		for(dwIndex = 0; dwIndex < dwCount; ++dwIndex)
		{
			wSkill = rgwSkills[dwIndex];

			if(wSkill == 0xFFFF)	// the end of the whole list
				break;

			if(wSkill >= 20000)
			{
				wBreed = wSkill - 20000;
				if(	wBreed < BREED_COUNT &&
					dwIndex < dwCount - 1 &&
					rgwSkills[dwIndex + 1] < SKILL_COUNT)
				{
					m_pDeriveLearnAddressList[wBreed] = (dwIndex + 1) * sizeof(WORD);
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
INT CPokemonRom::OpenRom(LPCTSTR lpszFileName, CVisualBoyHandler * lpVbaRam, DWORD dwOpenFlags)
{
	BOOL	bResult, bWarning = FALSE;
	CHAR	szGameTitle[0x10];
	CHAR	szGameVersion[0x20];

	CloseRom();

	try
	{
		/////////////////////////////////////////
		m_dwOpenFlags = dwOpenFlags;

		// open rom file
		if(lpszFileName)
		{
			m_pRomFile = new CFile;
			if(m_pRomFile == NULL)
				throw 0;

			bResult = m_pRomFile->Open(lpszFileName, CFile::modeReadWrite | CFile::shareDenyNone, NULL);
			if(!bResult)
			{
				bResult = m_pRomFile->Open(lpszFileName, CFile::modeRead | CFile::shareDenyNone, NULL);
				if(!bResult)
					throw 0;
				else
					m_bIsFileReadOnly = TRUE;
			}
			else
			{
				m_bIsFileReadOnly = FALSE;
			}

			// check rom
			m_pRomFile->Seek(0x000000A0, CFile::begin);
			if(m_pRomFile->Read(szGameTitle, sizeof(szGameTitle)) != sizeof(szGameTitle))
				throw 0;

			m_pRomFile->Seek(0x00000108, CFile::begin);
			if(m_pRomFile->Read(szGameVersion, sizeof(szGameVersion)) != sizeof(szGameVersion))
				throw 0;
		}
		else if(lpVbaRam)
		{
			m_bIsFileReadOnly = TRUE;

			// check rom
			if(!lpVbaRam->Read(0x080000A0, sizeof(szGameTitle), szGameTitle))
				throw 0;

			if(!lpVbaRam->Read(0x08000108, sizeof(szGameVersion), szGameVersion))
				throw 0;
		}
		else
		{
			throw 0;
		}

		if(strncmp(szGameTitle, "POKEMON RUBYAXVJ", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_ruby_jp;
		}
		else if(strncmp(szGameTitle, "POKEMON SAPPAXPJ", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_sapphire_jp;
		}
		else if(strncmp(szGameTitle, "POKEMON RUBYAXVE", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_ruby_en;
		}
		else if(strncmp(szGameTitle, "POKEMON SAPPAXPE", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_sapphire_en;
		}
		else if(strncmp(szGameTitle, "POKEMON FIREBPRJ", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_fire_jp;
		}
		else if(strncmp(szGameTitle, "POKEMON LEAFBPGJ", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_leaf_jp;
		}
		else if(strncmp(szGameTitle, "POKEMON FIREBPRE", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_fire_en;
		}
		else if(strncmp(szGameTitle, "POKEMON LEAFBPGE", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_leaf_en;
		}
		else if(strncmp(szGameTitle, "POKEMON EMERBPEJ", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_emerald_jp;
		}
		else if(strncmp(szGameTitle, "POKEMON EMERBPEE", sizeof(szGameTitle)) == 0)
		{
			m_dwRomVersion = rom_emerald_en;
		}
		else if(strncmp(szGameTitle, "YJencrypted", sizeof(szGameTitle)) == 0)
		{
			if(strncmp(szGameVersion, "pokemon red version", sizeof(szGameVersion)) == 0)
			{
				m_dwRomVersion = rom_fire_jp;
			}
			else if(strncmp(szGameVersion, "pokemon green version", sizeof(szGameVersion)) == 0)
			{
				m_dwRomVersion = rom_leaf_jp;
			}
			else if(strncmp(szGameVersion, "pokemon emerald version", sizeof(szGameVersion)) == 0)
			{
				m_dwRomVersion = rom_emerald_jp;
			}
			else
			{
				bResult = FALSE;
			}
		}
		else
		{
			throw 0;
		}

		m_bOpened = TRUE;

		/////////////////////////////////////////
		// allocate memroy & read contents
		if(m_dwOpenFlags & rom_breed_list)
		{
			m_pBreedList = new BreedListEntry[BREED_COUNT];
			if(m_pBreedList == NULL)
				throw 0;

			if(DEOXYS_BREED_ABILITIES_ADDRESS[m_dwRomVersion] != 0x00000000)
			{
				m_pDeoxysBreedAblities = new WORD[ABILITY_COUNT];
				if(m_pDeoxysBreedAblities == NULL)
					throw 0;
			}

			bResult = ReadBreedList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_pokedex_order)
		{
			m_pPokedexHouenOrder = new WORD[BREED_COUNT];
			if(m_pPokedexHouenOrder == NULL)
				throw 0;
			m_pPokedexKantoOrder = new WORD[BREED_COUNT];
			if(m_pPokedexKantoOrder == NULL)
				throw 0;

			bResult = ReadPokedexOrder(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_experience_list)
		{
			m_pExpList = new DWORD[EXP_COUNT * EXP_LIST_COUNT];
			if(m_pExpList == NULL)
				throw 0;

			bResult = ReadExpList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_evolution_list)
		{
			m_pEvoList = new EvoListEntry[BREED_COUNT * EVO_LIST_COUNT];
			if(m_pEvoList == NULL)
				throw 0;

			bResult = ReadEvoList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_item_list)
		{
			switch(m_dwRomVersion)
			{
			case rom_ruby_jp:
			case rom_sapphire_jp:
			case rom_fire_jp:
			case rom_leaf_jp:
			case rom_emerald_jp:
				m_pItemList = new BYTE[wItemCounts[m_dwRomVersion] * sizeof(ItemListEntryJP)];
				break;

			case rom_ruby_en:
			case rom_sapphire_en:
			case rom_fire_en:
			case rom_leaf_en:
			case rom_emerald_en:
				m_pItemList = new BYTE[wItemCounts[m_dwRomVersion] * sizeof(ItemListEntryEN)];
				break;
			}
			if(m_pItemList == NULL)
				throw 0;

			bResult = ReadItemList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_skill_list)
		{
			m_pSkillList = new SkillListEntry[SKILL_COUNT];
			if(m_pSkillList == NULL)
				throw 0;

			bResult = ReadSkillList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_encounter_list)
		{
			m_pEncAddressList = new EncAddressListEntry[dwEncCounts[m_dwRomVersion]];
			if(m_pEncAddressList == NULL)
				throw 0;
			m_pEncList = new BYTE[dwEncListSizes[m_dwRomVersion]];
			if(m_pEncList == NULL)
				throw 0;
			switch(m_dwRomVersion)
			{
			case rom_fire_jp:
			case rom_leaf_jp:
			case rom_fire_en:
			case rom_leaf_en:
				m_pAnnoonEncList = new BYTE[ANNOON_ENC_AREA_COUNT * ENC_LAND_ENTRY_COUNT];
				if(m_pAnnoonEncList == NULL)
					throw 0;
				break;
			}

			bResult = ReadEncList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_lvlup_learn_list)
		{
			m_pLvlupLearnAddressList = new DWORD[BREED_COUNT];
			if(m_pLvlupLearnAddressList == NULL)
				throw 0;
			m_pLvlupLearnList = new BYTE[dwLvlupLearnListSizes[m_dwRomVersion]];
			if(m_pLvlupLearnList == NULL)
				throw 0;

			bResult = ReadLvlupLearnList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_machine_learn_list)
		{
			m_pMachineLearnList = new BYTE[BREED_COUNT * MACHINE_LEARN_ENTRY_SIZE];
			if(m_pMachineLearnList == NULL)
				throw 0;

			bResult = ReadMachineLearnList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_machine_skill_list)
		{
			m_pMachineSkillList = new WORD[MACHINE_COUNT];
			if(m_pMachineSkillList == NULL)
				throw 0;

			bResult = ReadMachineSkillList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_derive_learn_list)
		{
			m_pDeriveLearnList = new BYTE[dwDeriveLearnListSizes[m_dwRomVersion]];
			if(m_pDeriveLearnList == NULL)
				throw 0;
			m_pDeriveLearnAddressList = new DWORD[BREED_COUNT];
			if(m_pDeriveLearnAddressList == NULL)
				throw 0;

			bResult = ReadDeriveLearnList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		if(m_dwOpenFlags & rom_berry_list)
		{
			m_pBerryList = new BerryListEntry[BERRY_COUNT];
			if(m_pBerryList == NULL)
				throw 0;

			bResult = ReadBerryList(lpVbaRam);
			if(!bResult)
				throw 0;
		}

		/////////////////////////////////////////
		// create small icon image list
		bResult = CreateSmallIconList(lpVbaRam);
		if(!bResult)
			throw 0;

		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	if(!bResult)
	{
		CloseRom();
	}

	m_bOpened = bResult;

	return bResult;
}

VOID CPokemonRom::CloseRom(VOID)
{
	DWORD	dwIndex;
	DWORD	dwSmallIconTotalCount = GetSmallIconTotalCount();

	if(m_pRomFile)
	{
		if(m_pRomFile->m_hFile != CFile::hFileNull)
		{
			m_pRomFile->Close();
		}
		delete m_pRomFile;
		m_pRomFile = NULL;
	}
	m_bOpened = FALSE;
	m_bIsFileReadOnly = TRUE;
	m_dwOpenFlags = 0;

	if(m_pSmallIconList)
	{
		m_pSmallIconList->DeleteImageList();
		delete m_pSmallIconList;
		m_pSmallIconList = NULL;
	}

	if(m_pTinyIconList)
	{
		m_pTinyIconList->DeleteImageList();
		delete m_pTinyIconList;
		m_pTinyIconList = NULL;
	}

	if(m_rghbmSmallIcons)
	{
		for(dwIndex = 0; dwIndex < dwSmallIconTotalCount; ++dwIndex)
		{
			if(m_rghbmSmallIcons[dwIndex])
			{
				DeleteObject(m_rghbmSmallIcons[dwIndex]);
				m_rghbmSmallIcons[dwIndex] = NULL;
			}
		}
		delete []m_rghbmSmallIcons;
		m_rghbmSmallIcons = NULL;
	}

	if(m_pBreedList)
	{
		delete []m_pBreedList;
		m_pBreedList = NULL;
	}
	if(m_pDeoxysBreedAblities)
	{
		delete []m_pDeoxysBreedAblities;
		m_pDeoxysBreedAblities = NULL;
	}

	if(m_pPokedexHouenOrder)
	{
		delete []m_pPokedexHouenOrder;
		m_pPokedexHouenOrder = NULL;
	}
	if(m_pPokedexKantoOrder)
	{
		delete []m_pPokedexKantoOrder;
		m_pPokedexKantoOrder = NULL;
	}

	if(m_pExpList)
	{
		delete []m_pExpList;
		m_pExpList = NULL;
	}

	if(m_pEvoList)
	{
		delete []m_pEvoList;
		m_pEvoList = NULL;
	}

	if(m_pItemList)
	{
		delete [](LPBYTE)(m_pItemList);
		m_pItemList = NULL;
	}

	if(m_pSkillList)
	{
		delete []m_pSkillList;
		m_pSkillList = NULL;
	}

	if(m_pEncAddressList)
	{
		delete []m_pEncAddressList;
		m_pEncAddressList = NULL;
	}
	if(m_pEncList)
	{
		delete []m_pEncList;
		m_pEncList = NULL;
	}
	if(m_pAnnoonEncList)
	{
		delete []m_pAnnoonEncList;
		m_pAnnoonEncList = NULL;
	}

	if(m_pLvlupLearnAddressList)
	{
		delete []m_pLvlupLearnAddressList;
		m_pLvlupLearnAddressList = NULL;
	}
	if(m_pLvlupLearnList)
	{
		delete []m_pLvlupLearnList;
		m_pLvlupLearnList = NULL;
	}

	if(m_pMachineLearnList)
	{
		delete []m_pMachineLearnList;
		m_pMachineLearnList = NULL;
	}

	if(m_pMachineSkillList)
	{
		delete []m_pMachineSkillList;
		m_pMachineSkillList = NULL;
	}

	if(m_pDeriveLearnList)
	{
		delete []m_pDeriveLearnList;
		m_pDeriveLearnList = NULL;
	}
	if(m_pDeriveLearnAddressList)
	{
		delete []m_pDeriveLearnAddressList;
		m_pDeriveLearnAddressList = NULL;
	}

	if(m_pBerryList)
	{
		delete []m_pBerryList;
		m_pBerryList = NULL;
	}
}

DWORD CPokemonRom::GetRomVersion(VOID)
{
	return m_dwRomVersion;
}

LPCTSTR	CPokemonRom::GetRomName(VOID)
{
	LPCTSTR	szRomName = _T("");

	if(m_bOpened)
	{
		szRomName = rgszRomName[m_dwRomVersion];
	}

	return szRomName;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
BreedListEntry * CPokemonRom::GetBreedListEntry(WORD wBreed)
{
	BreedListEntry * pEntry = NULL;

	if(m_bOpened && (m_dwOpenFlags & rom_breed_list) && wBreed < BREED_COUNT)
		pEntry = &(m_pBreedList[wBreed]);

	return pEntry;
}

WORD * CPokemonRom::GetDeoxysBreedAbilities()
{
	if(m_bOpened && (m_dwOpenFlags & rom_breed_list))
		return m_pDeoxysBreedAblities;
	else
		return NULL;
}

DWORD * CPokemonRom::GetExpList(BYTE bExpType)
{
	DWORD * pExpList = NULL;

	if(m_bOpened && (m_dwOpenFlags & rom_experience_list) && bExpType < EXP_COUNT)
		pExpList = &(m_pExpList[bExpType * EXP_COUNT]);

	return pExpList;
}

EvoListEntry * CPokemonRom::GetEvoListEntry(WORD wBreed, BYTE bIndex)
{
	EvoListEntry * pEntry = NULL;

	if(m_bOpened && (m_dwOpenFlags & rom_evolution_list) && wBreed < BREED_COUNT && bIndex < EVO_LIST_COUNT)
		pEntry = &(m_pEvoList[wBreed * EVO_LIST_COUNT + bIndex]);

	return pEntry;
}

ItemListEntry * CPokemonRom::GetItemListEntry(DWORD wItem)
{
	ItemListEntry *	pEntry = NULL;

	if(m_bOpened && (m_dwOpenFlags && rom_item_list) && wItem < wItemCounts[m_dwRomVersion])
	{
		switch(m_dwRomVersion)
		{
		case rom_ruby_jp:
		case rom_sapphire_jp:
		case rom_fire_jp:
		case rom_leaf_jp:
		case rom_emerald_jp:
			pEntry = &((reinterpret_cast<ItemListEntryJP *>(m_pItemList))[wItem].Entry);
			break;

		case rom_ruby_en:
		case rom_sapphire_en:
		case rom_fire_en:
		case rom_leaf_en:
		case rom_emerald_en:
			pEntry = &((reinterpret_cast<ItemListEntryEN *>(m_pItemList))[wItem].Entry);
			break;
		}
	}

	return pEntry;
}

SkillListEntry * CPokemonRom::GetSkillListEntry(DWORD wSkill)
{
	SkillListEntry * pEntry = NULL;

	if(m_bOpened && (m_dwOpenFlags & rom_skill_list) && wSkill < SKILL_COUNT)
		pEntry = &(m_pSkillList[wSkill]);

	return pEntry;
}

EncLandList * CPokemonRom::GetEncLandList(DWORD dwEncIndex)
{
	EncLandList * pEncList = NULL;
	LONG	lOffset;

	if(m_bOpened && (m_dwOpenFlags & rom_encounter_list) && dwEncIndex < dwEncCounts[m_dwRomVersion])
	{
		lOffset = m_pEncAddressList[dwEncIndex].dwLandEncAddress;
		if(lOffset != 0x00000000)
		{
			lOffset -= 0x08000000 + ENC_LIST_ADDRESS[m_dwRomVersion];
			lOffset -= ENC_LAND_ENTRY_COUNT * sizeof(EncEntry);
			if(lOffset >= 0x00000000 && lOffset < (LONG)(dwEncListSizes[m_dwRomVersion]))
			{
				pEncList = reinterpret_cast<EncLandList *>(m_pEncList + lOffset);
			}
		}
	}

	return pEncList;
}

EncWaterList* CPokemonRom::GetEncWaterList(DWORD dwEncIndex)
{
	EncWaterList * pEncList = NULL;
	LONG	lOffset;

	if(m_bOpened && (m_dwOpenFlags & rom_encounter_list) && dwEncIndex < dwEncCounts[m_dwRomVersion])
	{
		lOffset = m_pEncAddressList[dwEncIndex].dwWaterEncAddress;
		if(lOffset != 0x00000000)
		{
			lOffset -= 0x08000000 + ENC_LIST_ADDRESS[m_dwRomVersion];
			lOffset -= ENC_WATER_ENTRY_COUNT * sizeof(EncEntry);
			if(lOffset >= 0x00000000 && lOffset < (LONG)(dwEncListSizes[m_dwRomVersion]))
			{
				pEncList = reinterpret_cast<EncWaterList *>(m_pEncList + lOffset);
			}
		}
	}

	return pEncList;
}

EncStoneList* CPokemonRom::GetEncStoneList(DWORD dwEncIndex)
{
	EncStoneList * pEncList = NULL;
	LONG	lOffset;

	if(m_bOpened && (m_dwOpenFlags & rom_encounter_list) && dwEncIndex < dwEncCounts[m_dwRomVersion])
	{
		lOffset = m_pEncAddressList[dwEncIndex].dwStoneEncAddress;
		if(lOffset != 0x00000000)
		{
			lOffset -= 0x08000000 + ENC_LIST_ADDRESS[m_dwRomVersion];
			lOffset -= ENC_STONE_ENTRY_COUNT * sizeof(EncEntry);
			if(lOffset >= 0x00000000 && lOffset < (LONG)(dwEncListSizes[m_dwRomVersion]))
			{
				pEncList = reinterpret_cast<EncStoneList *>(m_pEncList + lOffset);
			}
		}
	}

	return pEncList;
}

EncFishList * CPokemonRom::GetEncFishList(DWORD dwEncIndex)
{
	EncFishList * pEncList = NULL;
	LONG	lOffset;

	if(m_bOpened && (m_dwOpenFlags & rom_encounter_list) && dwEncIndex < dwEncCounts[m_dwRomVersion])
	{
		lOffset = m_pEncAddressList[dwEncIndex].dwFishEncAddress;
		if(lOffset != 0x00000000)
		{
			lOffset -= 0x08000000 + ENC_LIST_ADDRESS[m_dwRomVersion];
			lOffset -= ENC_FISH_ENTRY_COUNT * sizeof(EncEntry);
			if(lOffset >= 0x00000000 && lOffset < (LONG)(dwEncListSizes[m_dwRomVersion]))
			{
				pEncList = reinterpret_cast<EncFishList *>(m_pEncList + lOffset);
			}
		}
	}

	return pEncList;
}

EncEntry * CPokemonRom::GetEncList(DWORD dwEncIndex, DWORD dwEncType)
{
	EncEntry *	pEntry = NULL;

	switch(dwEncType)
	{
	case enc_land:
		pEntry = reinterpret_cast<EncEntry *>(GetEncLandList(dwEncIndex));
		break;

	case enc_water:
		pEntry = reinterpret_cast<EncEntry *>(GetEncWaterList(dwEncIndex));
		break;

	case enc_stone:
		pEntry = reinterpret_cast<EncEntry *>(GetEncStoneList(dwEncIndex));
		break;

	case enc_fish:
		pEntry = reinterpret_cast<EncEntry *>(GetEncFishList(dwEncIndex));
		break;
	}

	return pEntry;
}

BYTE * CPokemonRom::GetAnnoonEncList(DWORD dwEncIndex)
{
	BYTE *	pList = NULL;
	WORD	wAreaId;

	if(m_bOpened && m_pAnnoonEncList && dwEncIndex < dwEncCounts[m_dwRomVersion])
	{
		// area id: 0x1B02 - 0x2102
		wAreaId = m_pEncAddressList[dwEncIndex].wAreaId;
		switch(wAreaId)
		{
		case 0x1B02:
		case 0x1C02:
		case 0x1D02:
		case 0x1E02:
		case 0x1F02:
		case 0x2002:
		case 0x2102:
			pList = m_pAnnoonEncList + ((wAreaId >> 8) - 0x1B) * ENC_LAND_ENTRY_COUNT;
			break;
		}
	}

	return pList;
}

LvlupLearnListEntry * CPokemonRom::GetLvlupLearnList(WORD wBreed)
{
	LvlupLearnListEntry *pList = NULL;
	LONG	lOffset;

	if(m_bOpened && (m_dwOpenFlags & rom_lvlup_learn_list) && wBreed < BREED_COUNT)
	{
		lOffset = m_pLvlupLearnAddressList[wBreed];
		lOffset -= 0x08000000 + LVLUP_LEARN_LIST_ADDRESS[m_dwRomVersion];
		if(lOffset >= 0x00000000 && lOffset < (LONG)(dwLvlupLearnListSizes[m_dwRomVersion]))
		{
			pList = reinterpret_cast<LvlupLearnListEntry *>(m_pLvlupLearnList + lOffset);
		}
	}

	return pList;
}

BYTE * CPokemonRom::GetMachineLearnList(WORD wBreed)
{
	BYTE *	pList = NULL;

	if(m_bOpened && (m_dwOpenFlags & rom_machine_learn_list) && wBreed < BREED_COUNT)
		pList = m_pMachineLearnList + wBreed * MACHINE_LEARN_ENTRY_SIZE;

	return pList;
}

WORD * CPokemonRom::GetDeriveLearnList(WORD wBreed)
{
	WORD *	pList = NULL;
	DWORD	dwAddress;

	if(m_bOpened && (m_dwOpenFlags & rom_derive_learn_list) && wBreed < BREED_COUNT)
	{
		dwAddress = m_pDeriveLearnAddressList[wBreed];
		if(dwAddress)
		{
			pList = reinterpret_cast<WORD *>(m_pDeriveLearnList + dwAddress);
		}
	}

	return pList;
}

BerryListEntry * CPokemonRom::GetBerryListEntry(DWORD dwIndex)
{
	BerryListEntry *pBerry = NULL;

	if(m_bOpened && (m_dwOpenFlags & rom_berry_list) && dwIndex < BERRY_COUNT)
	{
		pBerry = &(m_pBerryList[dwIndex]);
	}

	return pBerry;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CPokemonRom::SaveBreedList(VOID)
{
	BOOL	bResult;
	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		m_pRomFile->Seek(BREED_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pBreedList, BREED_COUNT * sizeof(BreedListEntry));

		if(DEOXYS_BREED_ABILITIES_ADDRESS[m_dwRomVersion] != 0x00000000)
		{
			m_pRomFile->Seek(DEOXYS_BREED_ABILITIES_ADDRESS[m_dwRomVersion], CFile::begin);
			m_pRomFile->Write(m_pDeoxysBreedAblities, ABILITY_COUNT * sizeof(WORD));
		}

		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveExpList(VOID)
{
	BOOL	bResult;
	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		m_pRomFile->Seek(EXP_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pExpList, EXP_LIST_COUNT * EXP_COUNT * sizeof(DWORD));
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveEvoList(VOID)
{
	BOOL	bResult;
	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		m_pRomFile->Seek(EVO_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pEvoList, BREED_COUNT * EVO_LIST_COUNT * sizeof(EvoListEntry));
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveItemList(VOID)
{
	BOOL	bResult;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		switch(m_dwRomVersion)
		{
		case rom_ruby_jp:
		case rom_sapphire_jp:
		case rom_fire_jp:
		case rom_leaf_jp:
		case rom_emerald_jp:
			dwSize = wItemCounts[m_dwRomVersion] * sizeof(ItemListEntryJP);
			break;

		case rom_ruby_en:
		case rom_sapphire_en:
		case rom_fire_en:
		case rom_leaf_en:
		case rom_emerald_en:
			dwSize = wItemCounts[m_dwRomVersion] * sizeof(ItemListEntryEN);
			break;
		}

		m_pRomFile->Seek(ITEM_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pItemList, dwSize);
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveSkillList(VOID)
{
	BOOL	bResult;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		dwSize = SKILL_COUNT * sizeof(SkillListEntry);
		m_pRomFile->Seek(SKILL_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pSkillList, dwSize);
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveEncList(VOID)
{
	BOOL	bResult;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		dwSize = dwEncListSizes[m_dwRomVersion];
		m_pRomFile->Seek(ENC_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pEncList, dwSize);

		if(ANNOON_ENC_LIST_ADDRESS[m_dwRomVersion])
		{
			dwSize = ANNOON_ENC_AREA_COUNT * ENC_LAND_ENTRY_COUNT;
			m_pRomFile->Seek(ANNOON_ENC_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
			m_pRomFile->Write(m_pAnnoonEncList, dwSize);
		}

		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveLvlupLearnList(VOID)
{
	BOOL	bResult;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		dwSize = dwLvlupLearnListSizes[m_dwRomVersion];
		m_pRomFile->Seek(LVLUP_LEARN_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pLvlupLearnList, dwSize);
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveMachineLearnList(VOID)
{
	BOOL	bResult;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		dwSize = BREED_COUNT * MACHINE_LEARN_ENTRY_SIZE;
		m_pRomFile->Seek(MACHINE_LEARN_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pMachineLearnList, dwSize);
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveMachineSkillList(VOID)
{
	BOOL	bResult;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		dwSize = MACHINE_COUNT * sizeof(WORD);
		m_pRomFile->Seek(MACHINE_SKILL_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pMachineSkillList, dwSize);
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveDeriveLearnList(VOID)
{
	BOOL	bResult;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		dwSize = dwDeriveLearnListSizes[m_dwRomVersion];
		m_pRomFile->Seek(DERIVE_LEARN_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pDeriveLearnList, dwSize);
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

BOOL CPokemonRom::SaveBerryList(VOID)
{
	BOOL	bResult;
	DWORD	dwSize;

	try
	{
		if(!m_bOpened || m_bIsFileReadOnly)
			throw 0;

		dwSize = BERRY_COUNT * sizeof(BerryListEntry);
		m_pRomFile->Seek(BERRY_LIST_ADDRESS[m_dwRomVersion], CFile::begin);
		m_pRomFile->Write(m_pBerryList, dwSize);
		bResult = TRUE;
	}
	catch(int)
	{
		bResult = FALSE;
	}
	catch(CFileException *e)
	{
		e->Delete();
		bResult = FALSE;
	}

	return bResult;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
DWORD CPokemonRom::GetSmallIconTotalCount(VOID)
{
	DWORD	dwTotalCount = 0;

	if(m_bOpened)
	{
		dwTotalCount =
			(SMALL_ICON_ADDRESS_LIST_ENTRY_COUNT +
			 DEOXYS_ICON_EXTRA_ENTRY_COUNT[m_dwRomVersion]) *
			SMALL_ICON_SUB_LIST_ENTRY_COUNT;
	}

	return dwTotalCount;
}

DWORD CPokemonRom::GetSmallIconCount(WORD wBreed)
{
	if(wBreed < BREED_COUNT)
	{
		switch(wBreed)
		{
		case 201:	// アンノーン
			return (SMALL_ICON_SUB_LIST_ENTRY_COUNT * 28);
		case 410:	// ディオキシス
			return (SMALL_ICON_SUB_LIST_ENTRY_COUNT * (1 + DEOXYS_ICON_EXTRA_ENTRY_COUNT[m_dwRomVersion]));
		default:
			return SMALL_ICON_SUB_LIST_ENTRY_COUNT;
		}
	}
	else if(wBreed == 0xFFFF)	// egg
	{
		return SMALL_ICON_SUB_LIST_ENTRY_COUNT;
	}
	else
	{
		return 0;
	}
}

DWORD CPokemonRom::GetSmallIconIndex(WORD wBreed, DWORD dwIconIndex)
{
	DWORD	dwImageIndex;

	if(wBreed < 410)
	{
		switch(wBreed)
		{
		case 201:	// アンノーン
			if(dwIconIndex <= 1)
			{
				dwImageIndex = SMALL_ICON_SUB_LIST_ENTRY_COUNT * wBreed + dwIconIndex;
			}
			else
			{
				// additional for ディオキシス & egg
				dwImageIndex =
					SMALL_ICON_SUB_LIST_ENTRY_COUNT *
					(BREED_COUNT + DEOXYS_ICON_EXTRA_ENTRY_COUNT[m_dwRomVersion] + 1) +
					dwIconIndex - SMALL_ICON_SUB_LIST_ENTRY_COUNT;
			}
			break;

		default:
			dwImageIndex = SMALL_ICON_SUB_LIST_ENTRY_COUNT * wBreed;
			break;
		}
	}
	else if(wBreed == 410)	// ディオキシス
	{
		dwImageIndex = SMALL_ICON_SUB_LIST_ENTRY_COUNT * wBreed + dwIconIndex;
	}
	else if(wBreed < BREED_COUNT)
	{
		dwImageIndex =
			SMALL_ICON_SUB_LIST_ENTRY_COUNT *
			(wBreed + DEOXYS_ICON_EXTRA_ENTRY_COUNT[m_dwRomVersion]) +
			dwIconIndex;
	}
	else if(wBreed == 0xFFFF)	// egg
	{
		dwImageIndex =
			SMALL_ICON_SUB_LIST_ENTRY_COUNT *
			(BREED_COUNT + DEOXYS_ICON_EXTRA_ENTRY_COUNT[m_dwRomVersion]) +
			dwIconIndex;
	}
	else
	{
		dwImageIndex = 0;
	}
	return dwImageIndex;
}

HBITMAP CPokemonRom::GetSmallIcon(WORD wBreed, DWORD dwIndex)
{
	DWORD	dwIcon;

	dwIcon = GetSmallIconCount(wBreed);
	if(dwIcon > 0)
		dwIcon = GetSmallIconIndex(wBreed, min(dwIndex, dwIcon));

	return (m_rghbmSmallIcons[dwIcon]);
}

HBITMAP CPokemonRom::GetSmallIcon(WORD wBreed)
{
	DWORD	dwIcon;

	dwIcon = GetSmallIconCount(wBreed);
	if(dwIcon > 0)
		dwIcon = GetSmallIconIndex(wBreed, rand() % dwIcon);

	return (m_rghbmSmallIcons[dwIcon]);
}

WORD CPokemonRom::GetItemCount(VOID)
{
	WORD	wItemCount = 0;

	if(m_bOpened)
		wItemCount = wItemCounts[m_dwRomVersion];

	return wItemCount;
}

DWORD CPokemonRom::GetEncCount(VOID)
{
	DWORD	dwEncCount = 0;

	if(m_bOpened)
		dwEncCount = dwEncCounts[m_dwRomVersion];

	return dwEncCount;
}

DWORD CPokemonRom::GetEncListEntryCount(DWORD dwEncType)
{
	DWORD	dwEncListEntryCount = 0;

	if(m_bOpened && dwEncType < ENC_TYPE_COUNT)
		dwEncListEntryCount = dwEncListEntryCounts[dwEncType];

	return dwEncListEntryCount;
}

DWORD CPokemonRom::GetLvlupLearnListEntryCount(WORD wBreed)
{
	DWORD	dwCount = 0;
	WORD *	rgwList = reinterpret_cast<WORD *>(GetLvlupLearnList(wBreed));

	if(rgwList)
	{
		while(rgwList[dwCount] != 0xFFFF)
			++dwCount;
	}

	return dwCount;
}

DWORD CPokemonRom::GetDeriveLearnListEntryCount(WORD wBreed)
{
	DWORD	dwCount = 0;
	WORD *	rgwList = GetDeriveLearnList(wBreed);

	if(rgwList)
	{
		while(rgwList[dwCount] < SKILL_COUNT)
			++dwCount;
	}

	return dwCount;
}
