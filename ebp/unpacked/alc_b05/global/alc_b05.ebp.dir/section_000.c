// File size: 181168 Bytes
// Author:    mtanaka
// Source:    alc_b05.src
// Date:      00/00 00:00
// Binary:    E:\ff12-tools\The.Insurgents.Workshop.v1.0.1 - Copia\files\source\plan_map\alc_b\alc_b05\global\alc_b05.ebp.dir\section_000.bin

option authorName = "mtanaka";
option fileName = "alc_b05.src";
option dataFile = "alc_b05.src.data";
option spawnOrder = {-1, -1, -1, -1, -1, -1, -1, -1};
option unknownLocation = 640;
option unknownNavIcon = 3;
option weatherProbability = {100, 0, 0};
option trapOffset = 0x0;

//======================================================================
//               Global and scratchpad variable imports               //
//======================================================================
import global   short   シナリオフラグ = 0x00;
import global   char    global_var_1 = 0x073e;
import global   char    global_var_2 = 0x073f;
import global   int     global_var_3 = 0x0740;
import global   char    global_var_4 = 0x0744;
import global   char    global_var_5 = 0x0745;
import global   char    global_var_6 = 0x0746;
import global   char    global_var_7 = 0x0747;
import global   char    global_var_8 = 0x074b;
import global   float   mp_map_set_angle = 0x0900;
import global   float   mp_map_set_x = 0x0904;
import global   float   mp_map_set_y = 0x0908;
import global   float   mp_map_set_z = 0x090c;
import global   int     mp_map_flg = 0x0910;
import global   char    mp_last_weather = 0x0940;
import global   char    mp_4map = 0x0941;
import global   char    mp_map_set_hitse = 0x0943;
import global   int     g_com_set_get_label = 0x0c88;
import global   int     g_com_set_get_label_2 = 0x0c8c;
import global   u_char  g_com_counter_for_horidasi[10] = 0x0cd0;
import global   u_char  g_com_check_for_horidasi[2] = 0x0cda;
import global   int     g_com_set_get_label_3 = 0x0cf0;


//======================================================================
//                        Alchemist variables                        	//
//======================================================================
// flow flags
import scratch1   u_char		flow_status = 0x50;
import scratch1   u_char		flow_selected = 0x51;
import scratch1   u_char		flow_success = 0x52;
import scratch1   u_char		flow_reset = 0x53;
import scratch1   u_char		flow_load_equipment = 0x54;
import scratch1   u_char		flow_check_attribute = 0x4B;
import scratch1   u_char		flow_check_element = 0x4E;
import scratch1   u_char		flow_poll_mode = 0x4A;

// selected flags
import scratch1   u_char		selected_category = 0x55;
import scratch1   u_char		selected_subcategory = 0x56;
import scratch1   short			selected_equipment_id = 0x57;
import scratch1   u_char		selected_tier = 0x5A;

// obtainer values from lua
import scratch1   short			obtained_initial = 0x5B;
import scratch1   short			obtained_extra = 0x5D;
import scratch1   short			obtained_total = 0x5F;
import scratch1   short			obtained_tier1 = 0x61;
import scratch1   short			obtained_tier2 = 0x63;
import scratch1   short			obtained_tier3 = 0x65;
import scratch1   u_char		obtained_current_attribute = 0x4C;
import scratch1   u_char		obtained_current_element = 0x4F;

// loaded upgrade list
import scratch1   u_short		upgrade_item_ids[3] = 0x67;
import scratch1   u_char		upgrade_item_qtys[3] = 0x6D;
import scratch1   u_short		upgrade_gil[1] = 0x70;

// loaded equipment list
import scratch1   u_short		equipment_list[31] = 0x76;


//======================================================================
//                        File scope variables                        //
//======================================================================
int     file_var_s0_1[8];        // pos: 0x10;
char    file_var_s0_2[8];        // pos: 0x1900;
float   file_var_s0_3;           // pos: 0x3d00;
char    file_var_s0_4;           // pos: 0xc0;
float   file_var_s0_5[8];        // pos: 0x90;
float   file_var_s0_6[8];        // pos: 0xb0;
float   file_var_s0_7[8];        // pos: 0xd0;
int     file_var_s0_8[8];        // pos: 0x1980;
u_char  file_var_s0_9;           // pos: 0x4000;

actor ReposDirector(0)
{

	function init()
	{
		return;
	}

	function repos_main()
	{
		while (true)
		{
			if (file_var_s0_1[1])
			{
				if (file_var_s0_2[1])
				{
					if (!(sysCheckdistance3d(NPC01, file_var_s0_3)))
					{
						if (file_var_s0_4)
						{
							sysReqewi(4, NPC01::clip_hide);
						}
						else
						{
							sysReqew(4, NPC01::clip_hide);
						}
					}
				}
				else if (checkdistance3d_531(file_var_s0_5[1], file_var_s0_6[1], file_var_s0_7[1], file_var_s0_3))
				{
					file_var_s0_8[1] = 1;
					if (file_var_s0_4)
					{
						sysReqewi(3, NPC01::clip_show);
					}
					else
					{
						sysReqsw(3, NPC01::clip_show);
					}
					sysReq(1, NPC01::logic_main);
					sysReqchg(2, NPC01::talk_01a);
				}
				wait(1);
			}
			if (file_var_s0_1[2])
			{
				if (file_var_s0_2[2])
				{
					if (!(sysCheckdistance3d(NPC02, file_var_s0_3)))
					{
						if (file_var_s0_4)
						{
							sysReqewi(4, NPC02::clip_hide);
						}
						else
						{
							sysReqew(4, NPC02::clip_hide);
						}
					}
				}
				else if (checkdistance3d_531(file_var_s0_5[2], file_var_s0_6[2], file_var_s0_7[2], file_var_s0_3))
				{
					file_var_s0_8[2] = 2;
					if (file_var_s0_4)
					{
						sysReqewi(3, NPC02::clip_show);
					}
					else
					{
						sysReqsw(3, NPC02::clip_show);
					}
					sysReq(1, NPC02::logic_main);
					sysReqchg(2, NPC02::talk_02a);
				}
				wait(1);
			}
			if (file_var_s0_1[3])
			{
				if (file_var_s0_2[3])
				{
					if (!(sysCheckdistance3d(NPC03, file_var_s0_3)))
					{
						if (file_var_s0_4)
						{
							sysReqewi(4, NPC03::clip_hide);
						}
						else
						{
							sysReqew(4, NPC03::clip_hide);
						}
					}
				}
				else if (checkdistance3d_531(file_var_s0_5[3], file_var_s0_6[3], file_var_s0_7[3], file_var_s0_3))
				{
					file_var_s0_8[3] = 3;
					if (file_var_s0_4)
					{
						sysReqewi(3, NPC03::clip_show);
					}
					else
					{
						sysReqsw(3, NPC03::clip_show);
					}
					sysReq(1, NPC03::logic_main);
					sysReqchg(2, NPC03::talk_03a);
				}
				wait(1);
			}
			if (file_var_s0_1[4])
			{
				if (file_var_s0_2[4])
				{
					if (!(sysCheckdistance3d(NPC04, file_var_s0_3)))
					{
						if (file_var_s0_4)
						{
							sysReqewi(4, NPC04::clip_hide);
						}
						else
						{
							sysReqew(4, NPC04::clip_hide);
						}
					}
				}
				else if (checkdistance3d_531(file_var_s0_5[4], file_var_s0_6[4], file_var_s0_7[4], file_var_s0_3))
				{
					file_var_s0_8[4] = 4;
					if (file_var_s0_4)
					{
						sysReqewi(3, NPC04::clip_show);
					}
					else
					{
						sysReqsw(3, NPC04::clip_show);
					}
					sysReq(1, NPC04::logic_main);
					sysReqchg(2, NPC04::talk_04a);
				}
				wait(1);
			}
			if (file_var_s0_1[5])
			{
				if (file_var_s0_2[5])
				{
					if (!(sysCheckdistance3d(NPC05, file_var_s0_3)))
					{
						if (file_var_s0_4)
						{
							sysReqewi(4, NPC05::clip_hide);
						}
						else
						{
							sysReqew(4, NPC05::clip_hide);
						}
					}
				}
				else if (checkdistance3d_531(file_var_s0_5[5], file_var_s0_6[5], file_var_s0_7[5], file_var_s0_3))
				{
					file_var_s0_8[5] = 5;
					if (file_var_s0_4)
					{
						sysReqewi(3, NPC05::clip_show);
					}
					else
					{
						sysReqsw(3, NPC05::clip_show);
					}
					sysReq(1, NPC05::logic_main);
					sysReqchg(2, NPC05::talk_05a);
				}
				wait(1);
			}
			if (file_var_s0_1[6])
			{
				if (file_var_s0_2[6])
				{
					if (!(sysCheckdistance3d(NPC06, file_var_s0_3)))
					{
						if (file_var_s0_4)
						{
							sysReqewi(4, NPC06::clip_hide);
						}
						else
						{
							sysReqew(4, NPC06::clip_hide);
						}
					}
				}
				else if (checkdistance3d_531(file_var_s0_5[6], file_var_s0_6[6], file_var_s0_7[6], file_var_s0_3))
				{
					file_var_s0_8[6] = 6;
					if (file_var_s0_4)
					{
						sysReqewi(3, NPC06::clip_show);
					}
					else
					{
						sysReqsw(3, NPC06::clip_show);
					}
					sysReq(1, NPC06::logic_main);
					sysReqchg(2, NPC06::talk_06a);
				}
				wait(1);
			}
			if (file_var_s0_1[7])
			{
				if (file_var_s0_2[7])
				{
					if (!(sysCheckdistance3d(NPC07, file_var_s0_3)))
					{
						if (file_var_s0_4)
						{
							sysReqewi(4, NPC07::clip_hide);
						}
						else
						{
							sysReqew(4, NPC07::clip_hide);
						}
					}
				}
				else if (checkdistance3d_531(file_var_s0_5[7], file_var_s0_6[7], file_var_s0_7[7], file_var_s0_3))
				{
					file_var_s0_8[7] = 7;
					if (file_var_s0_4)
					{
						sysReqewi(3, NPC07::clip_show);
					}
					else
					{
						sysReqsw(3, NPC07::clip_show);
					}
					sysReq(1, NPC07::logic_main);
					sysReqchg(2, NPC07::talk_07a);
				}
				wait(1);
			}
			if (file_var_s0_4)
			{
				return;
			}
			while (file_var_s0_9)
			{
				wait(1);
			}
			wait(1);
		}
	}
}

//======================================================================
//                        File scope variables                        //
//======================================================================
u_char  file_var_s1_1;           // pos: 0x4010;
int     file_var_s1_2;           // pos: 0x3f40;
int     file_var_s1_3;           // pos: 0x3c40;
int     file_var_s1_4;           // pos: 0x65c0;
int     file_var_s1_5;           // pos: 0x3bc0;
int     file_var_s1_6[8];        // pos: 0x30;
int     file_var_s1_7[8];        // pos: 0x70;
int     file_var_s1_8[8];        // pos: 0x50;
float   file_var_s1_9[8];        // pos: 0xf0;
int     file_var_s1_10[8];       // pos: 0x1100;
int     file_var_s1_11[8];       // pos: 0x1300;
float   file_var_s1_12[8];       // pos: 0x1500;
float   file_var_s1_13[8];       // pos: 0x1700;
int     file_var_s1_14;          // pos: 0x3e80;
int     file_var_s1_15;          // pos: 0x3c00;
int     file_var_s1_16[8][16];   // pos: 0x1bc0;
float   file_var_s1_17;          // pos: 0x6500;
float   file_var_s1_18;          // pos: 0x6540;

actor EventDirector(0)
{

	function init()
	{
		file_var_s0_4 = 1;
		file_var_s1_1 = 1;
		file_var_s1_2 = nowjumpindex();
		file_var_s0_3 = 33;
		switch (nowlocationmap())
		{
			case 38:
			case 47:
			case 49:
				setcharclipdistance_327(30, 3);
				break;
		}
		file_var_s1_3 = 1;
		if ((0x390000 | getquestscenarioflag(57)) >= 0x39000a)
		{
			if ((0x3b0000 | getquestscenarioflag(59)) < 0x3b001e)
			{
				file_var_s1_4 = 1;
			}
		}
		file_var_s1_5 = (file_var_s1_5 + 1);
		file_var_s0_1[file_var_s1_5] = 0x01b333;
		file_var_s1_6[file_var_s1_5] = file_var_s1_4;
		if (!((file_var_s1_4 & file_var_s1_3)))
		{
			file_var_s0_1[file_var_s1_5] = 0;
		}
		file_var_s1_7[file_var_s1_5] = 0x02dd;
		file_var_s1_8[file_var_s1_5] = 1;
		file_var_s0_5[file_var_s1_5] = 10.6347895;
		file_var_s0_6[file_var_s1_5] = 3.36875796;
		file_var_s0_7[file_var_s1_5] = 10.7549953;
		file_var_s1_9[file_var_s1_5] = 3.04572296;
		file_var_s1_10[file_var_s1_5] = 0;
		file_var_s1_11[file_var_s1_5] = 0;
		file_var_s1_12[file_var_s1_5] = 0;
		file_var_s1_13[file_var_s1_5] = 0;
		file_var_s1_14 = 0;
		file_var_s1_16[file_var_s1_5][file_var_s1_15] = 99;
		file_var_s1_15 = 0;
		file_var_s1_5 = (file_var_s1_5 + 1);
		file_var_s0_1[file_var_s1_5] = 0x01b349;
		file_var_s1_6[file_var_s1_5] = (file_var_s1_4 | 8);
		if (!(((file_var_s1_4 | 8) & file_var_s1_3)))
		{
			file_var_s0_1[file_var_s1_5] = 0;
		}
		file_var_s1_7[file_var_s1_5] = 68;
		file_var_s1_8[file_var_s1_5] = 1;
		file_var_s0_5[file_var_s1_5] = 10.5283804;
		file_var_s0_6[file_var_s1_5] = 3.36757588;
		file_var_s0_7[file_var_s1_5] = 8.2504282;
		file_var_s1_9[file_var_s1_5] = 0.159725994;
		file_var_s1_10[file_var_s1_5] = 0;
		file_var_s1_11[file_var_s1_5] = 0;
		file_var_s1_12[file_var_s1_5] = 0;
		file_var_s1_13[file_var_s1_5] = 0;
		file_var_s1_14 = 0;
		file_var_s1_16[file_var_s1_5][file_var_s1_15] = 99;
		file_var_s1_15 = 0;
		file_var_s1_5 = (file_var_s1_5 + 1);
		file_var_s0_1[file_var_s1_5] = 0x0197ef;
		file_var_s1_6[file_var_s1_5] = 1;
		if (!((1 & file_var_s1_3)))
		{
			file_var_s0_1[file_var_s1_5] = 0;
		}
		file_var_s1_7[file_var_s1_5] = 0x1033;
		file_var_s1_8[file_var_s1_5] = 0x0402;
		file_var_s0_5[file_var_s1_5] = 4.33702898;
		file_var_s0_6[file_var_s1_5] = 0.00404000003;
		file_var_s0_7[file_var_s1_5] = 25.1645584;
		file_var_s1_9[file_var_s1_5] = 1.66087198;
		file_var_s1_10[file_var_s1_5] = 0;
		file_var_s1_11[file_var_s1_5] = 0;
		file_var_s1_12[file_var_s1_5] = 2;
		file_var_s1_13[file_var_s1_5] = 0;
		file_var_s1_14 = 0;
		file_var_s1_16[file_var_s1_5][file_var_s1_15] = 99;
		file_var_s1_15 = 0;
		file_var_s1_5 = (file_var_s1_5 + 1);
		file_var_s0_1[file_var_s1_5] = 0x019607;
		file_var_s1_6[file_var_s1_5] = 1;
		if (!((1 & file_var_s1_3)))
		{
			file_var_s0_1[file_var_s1_5] = 0;
		}
		file_var_s1_7[file_var_s1_5] = 0x03a0;
		file_var_s1_8[file_var_s1_5] = 0x0c10;
		file_var_s0_5[file_var_s1_5] = 10.3768759;
		file_var_s0_6[file_var_s1_5] = 0.00171600003;
		file_var_s0_7[file_var_s1_5] = 22.3251247;
		file_var_s1_9[file_var_s1_5] = 0.604348004;
		file_var_s1_10[file_var_s1_5] = 0;
		file_var_s1_11[file_var_s1_5] = 0;
		file_var_s1_12[file_var_s1_5] = 0;
		file_var_s1_13[file_var_s1_5] = 0;
		file_var_s1_14 = 0;
		file_var_s1_16[file_var_s1_5][file_var_s1_15] = 99;
		file_var_s1_15 = 0;
		file_var_s1_5 = (file_var_s1_5 + 1);
		file_var_s0_1[file_var_s1_5] = 0x01966b;
		file_var_s1_6[file_var_s1_5] = 9;
		if (!((9 & file_var_s1_3)))
		{
			file_var_s0_1[file_var_s1_5] = 0;
		}
		file_var_s1_7[file_var_s1_5] = 0x03a1;
		file_var_s1_8[file_var_s1_5] = 0x0c10;
		file_var_s0_5[file_var_s1_5] = 11.1811275;
		file_var_s0_6[file_var_s1_5] = 0.00237399992;
		file_var_s0_7[file_var_s1_5] = 22.312746;
		file_var_s1_9[file_var_s1_5] = -0.254455;
		file_var_s1_10[file_var_s1_5] = 0;
		file_var_s1_11[file_var_s1_5] = 0;
		file_var_s1_12[file_var_s1_5] = 0;
		file_var_s1_13[file_var_s1_5] = 0;
		file_var_s1_14 = 0;
		file_var_s1_16[file_var_s1_5][file_var_s1_15] = 99;
		file_var_s1_15 = 0;
		if (((0x340000 | getquestscenarioflag(52)) >= 0x340032 && (0x340000 | getquestscenarioflag(52)) < 0x340064))
		{
			file_var_s1_14 = 1;
		}
		file_var_s1_5 = (file_var_s1_5 + 1);
		file_var_s0_1[file_var_s1_5] = 0x0193fe;
		file_var_s1_6[file_var_s1_5] = file_var_s1_14;
		if (!((file_var_s1_14 & file_var_s1_3)))
		{
			file_var_s0_1[file_var_s1_5] = 0;
		}
		file_var_s1_7[file_var_s1_5] = 0x02c9;
		file_var_s1_8[file_var_s1_5] = 0x0c10;
		file_var_s0_5[file_var_s1_5] = 6.37337589;
		file_var_s0_6[file_var_s1_5] = 3.36840105;
		file_var_s0_7[file_var_s1_5] = 13.9345446;
		file_var_s1_9[file_var_s1_5] = 0.632972002;
		file_var_s1_10[file_var_s1_5] = 0;
		file_var_s1_11[file_var_s1_5] = 0;
		file_var_s1_12[file_var_s1_5] = 0;
		file_var_s1_13[file_var_s1_5] = 0;
		file_var_s1_14 = 0;
		file_var_s1_16[file_var_s1_5][file_var_s1_15] = 99;
		file_var_s1_15 = 0;
		file_var_s1_5 = (file_var_s1_5 + 1);
		file_var_s0_1[file_var_s1_5] = 0x01a47a;
		file_var_s1_6[file_var_s1_5] = 1;
		if (!((1 & file_var_s1_3)))
		{
			file_var_s0_1[file_var_s1_5] = 0;
		}
		file_var_s1_7[file_var_s1_5] = 0x0436;
		file_var_s1_8[file_var_s1_5] = 0x0404;
		file_var_s0_5[file_var_s1_5] = 5.64970779;
		file_var_s0_6[file_var_s1_5] = 3.38032293;
		file_var_s0_7[file_var_s1_5] = 4.55014801;
		file_var_s1_9[file_var_s1_5] = 2.38535309;
		file_var_s1_10[file_var_s1_5] = 1;
		file_var_s1_11[file_var_s1_5] = 0;
		file_var_s1_12[file_var_s1_5] = 0;
		file_var_s1_13[file_var_s1_5] = 0;
		file_var_s1_14 = 0;
		file_var_s1_16[file_var_s1_5][file_var_s1_15] = 99;
		file_var_s1_15 = 0;
		file_var_s1_9[1] = (3.14159274 + atan2((file_var_s0_5[1] - file_var_s0_5[2]), (file_var_s0_7[1] - file_var_s0_7[2])));
		file_var_s1_9[2] = (3.14159274 + atan2((file_var_s0_5[2] - file_var_s0_5[1]), (file_var_s0_7[2] - file_var_s0_7[1])));
		wait(1);
		motionread(0);
		motionreadsync(0);
		sysReqewi(3, ReposDirector::repos_main);
		file_var_s0_4 = 0;
		sysReq(1, ReposDirector::repos_main);
		sysReqall(3, reqArr0);
		wait(2);
		return;
	}

	function main(1)
	{
		file_var_s1_17 = 0x010b;
		file_var_s1_18 = 138;
		while (true)
		{
			wait(1);
		}
	}
}

actor イベント特殊効果画面(0)
{

	function init()
	{
		return;
	}

	function だいじなものゲット()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label, 1);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}

	function システムメッセージ表示()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		setmeswinmesid(0, g_com_set_get_label);
		ames_1fe(0, 0x01000023, 0x03c0, 0x021c, 4, 0);
		messync(0, 1);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}

	function だいじなものゲット_FADE付()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label, 1);
		wait(8);
		musictrans(-1, 30, 127);
		fadeout(15);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}

	function システムメッセージ表示_FADE付()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		setmeswinmesid(0, g_com_set_get_label);
		ames_1fe(0, 0x01000023, 0x03c0, 0x021c, 4, 0);
		messync(0, 1);
		wait(8);
		musictrans(-1, 30, 127);
		fadeout(15);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}

	function だいじなものゲット_MJFADE付()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label, 1);
		wait(8);
		musictrans(-1, 30, 127);
		fadeout_d0(2, 15);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}

	function ゲット＆メッセージ表示()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label, 1);
		wait(6);
		setmeswinmesid(0, g_com_set_get_label_2);
		ames_1fe(0, 0x01000023, 0x03c0, 0x021c, 4, 0);
		messync(0, 1);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}

	function ゲット＆ゲット()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label, 1);
		wait(6);
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label_2, 1);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}

	function GET_SYSMES_GET表示()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label, 1);
		wait(6);
		setmeswinmesid(0, g_com_set_get_label_2);
		ames_1fe(0, 0x01000023, 0x03c0, 0x021c, 4, 0);
		messync(0, 1);
		wait(6);
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label_3, 1);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}

	function GET_SYSMES_SYSMES表示()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		sebsoundplay(0, 40);
		additemmes(g_com_set_get_label, 1);
		wait(6);
		setmeswinmesid(0, g_com_set_get_label_2);
		ames_1fe(0, 0x01000023, 0x03c0, 0x021c, 4, 0);
		messync(0, 1);
		wait(6);
		setmeswinmesid(0, g_com_set_get_label_3);
		ames_1fe(0, 0x01000023, 0x03c0, 0x021c, 4, 0);
		messync(0, 1);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		return;
	}
}

actor Map_Director(0)
{

	function init()
	{
		return;
	}
}

actor RECT_LEAF(1)
{

	function init()
	{
		sysDVAR(30, global_var_2);
		sysDVAR(31, global_var_5);
		sysDVAR(32, global_var_4);
		sysDVAR(33, global_var_7);
		sysDVAR(34, global_var_6);
		sysDVAR(35, global_var_3);
		if (global_var_2 >= 28)
		{
			if ((haveitem(0x2113) < 28 && haveitem(0x2112) == 0))
			{
				if ((global_var_3 == 0 || global_var_3 != nowmap()))
				{
					global_var_3 = nowmap();
					setrect_25(11.9885912, 3.36720204, 4.48180389, 1, 1, 0);
					setwh(2, 2, 1, 1);
					reqenable(2);
					recttocircle();
					reqdisable(3);
					reqenable(8);
					reqenable(13);
					fieldsignicon(2);
					fieldsignmes(0x01000024);
					showfieldsign();
					settouchuconly(1);
					charcommoneffectplay(13);
					charcommoneffecttrigger(1);
					talkang(1.57079637);
				}
			}
		}
		return;
	}

	function talk(2)
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		if (((global_var_8 && haveitem(0x2112) == 0) && rand_29(100) < 20))
		{
			rectdisable();
			charcommoneffectstop();
			sebsoundplay(0, 39);
			additemmes(0x2112, 1);
		}
		else
		{
			rectdisable();
			charcommoneffectstop();
			sebsoundplay(0, 39);
			additemmes(0x2113, 1);
			if ((haveitem(0x2113) == 3 && global_var_1 == 0))
			{
				g_com_set_get_label = 139;
				sysReqew(1, イベント特殊効果画面::システムメッセージ表示);
				wait(1);
				global_var_1 = 1;
			}
		}
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}
}

actor door_out(1)
{

	function init()
	{
		fieldsign(0);
		reqenable(2);
		return;
	}

	function talk(2)
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		mp_map_set_angle = 0;
		pausesestop();
		sysReqew(1, map_ダミーＰＣ::扉オープン１);
		mp_map_flg = 0;
		mp_map_flg = sebsoundplay(1, 3);
		animeplay(100);
		wait(15);
		regI3 = sysucoff();
		if (regI3)
		{
			clearmapjumpstatus();
			sysucon();
		}
		else
		{
			mp_last_weather = getweatherslot();
			steppoint(3);
			mp_4map = 30;
			fadelayer(6);
			fadeprior(255);
			fadeout_d0(2, mp_4map);
			steppoint(4);
			wait(15);
			steppoint(3);
			spotsoundtrans(15, 0);
			steppoint(2);
			wait(17);
			stopspotsound();
			pausesestop();
			hideparty();
			eventsoundplaysync(mp_map_flg);
			steppoint(1);
			setbattlethinkstatus_freetarget_group(-1, 0);
			voicestopall();
			mapjump(0x0280, 5, 1);
		}
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	char    local_var_s5f2_1;        // pos: 0x20;

	function フィールドサインＯＫ()
	{
		fieldsignicon(2);
		reqenable(2);
		local_var_s5f2_1 = 0;
		return;
	}

	function フィールドサインＮＯＴ()
	{
		fieldsignicon(3);
		reqenable(2);
		local_var_s5f2_1 = 1;
		return;
	}

	function フィールドサインＯＮ()
	{
		reqdisable(3);
		reqenable(8);
		reqenable(13);
		reqenable(2);
		return;
	}

	function フィールドサインＯＦＦ()
	{
		reqdisable(8);
		reqdisable(13);
		reqdisable(2);
		return;
	}
}

//======================================================================
//                        File scope variables                        //
//======================================================================
int     file_var_s6_1;           // pos: 0x3d80;

actor NPC_GUILD(6)
{

	function init()
	{
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s6f1_1;        // pos: 0xc0;
	int     local_var_s6f1_2;        // pos: 0x2c;
	int     local_var_s6f1_3;        // pos: 0x30;
	u_char  local_var_s6f1_4;        // pos: 0x48;
	char    local_var_s6f1_5;        // pos: 0x45;

	function begin()
	{
		hidecomplete();
		while (file_var_s0_9)
		{
			wait(1);
		}
		switch ((file_var_s1_6[local_var_s6f1_1] & 0x03c0))
		{
			case 64:
				modelread(0x03000008);
				modelreadsync(0x03000008);
				break;
			case 128:
				modelread(0x03000009);
				modelreadsync(0x03000009);
				break;
			case 192:
				modelread(0x0300000a);
				modelreadsync(0x0300000a);
				break;
			case 0x0100:
				modelread(0x0300000b);
				modelreadsync(0x0300000b);
				break;
			case 0x0140:
				modelread(0x0300000c);
				modelreadsync(0x0300000c);
				break;
			case 0x0180:
				modelread(0x0300000d);
				modelreadsync(0x0300000d);
				break;
		}
		usecharhit(0);
		bindp2_d4(0x03000004, 2, 3);
		local_var_s6f1_2 = 16;
		local_var_s6f1_3 = 0x01000000;
		stdmotionread(local_var_s6f1_2);
		stdmotionreadsync();
		stdmotionplay_2c2(local_var_s6f1_3, 0);
		setnpcname(0x03c3);
		setoverheadicontype(0);
		usemapid(0);
		usecharhit(0);
		setweight(-1);
		set_ignore_hitgroup(10);
		motionloop(1);
		fetchambient_4e1((3.44938302 + (sin(-3.08848) * 2)), 3.37279296, (9.50794125 + (cos(-3.08848) * 2)));
		setpos2(3.44938302, 3.37279296, 9.50794125);
		dir(-3.08848);
		talkradius(0.300000012);
		settalkradiusoffset(0, 0, -1.5);
		goto local_jmp_19;
		goto local_jmp_19;
		goto local_jmp_19;
		goto local_jmp_19;
		goto local_jmp_19;
	local_jmp_19:
		istouchucsync();
		bonecalcforce(-1);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		hideshadow();
		local_var_s6f1_4 = 1;
		local_var_s6f1_5 = 1;
		return;
	}

	function touch(3)
	{
		return;
	}

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
			{
				setaturnlookatlockstatus(1);
				aturn_261(getdestrotangzx_227(0));
			}
		}
		return;
	}

	function hit_disable()
	{
		usecharhit(0);
		return;
	}

	function event_show()
	{
		if (!(local_var_s6f1_4))
		{
			return;
		}
		clearhidecomplete();
		show_38(1);
		local_var_s6f1_5 = 1;
		return;
	}

	function event_hide()
	{
		hidecomplete();
		show_38(0);
		local_var_s6f1_5 = 0;
		return;
	}

	function main(1)
	{
		while (true)
		{
			motionplay_bb(0x10000000, 20);
			wait(1);
			motionsync_282(1);
			wait((rand_29(90) + 90));
		}
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s6f9_1;        // pos: 0x80;
	int     local_var_s6f9_2;        // pos: 0x00;
	int     local_var_s6f9_3;        // pos: 0x40;

	function talk(2)
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setaturnlookatlockstatus(0);
		sysRaturna(-1);
		regI2 = 0;
		if (isturn())
		{
			turnsync();
			stdmotionplay_2c2(0x01000002, 20);
		}
		else
		{
			regI2 = 1;
		}
		if (haveitem(0x2112))
		{
			local_var_s6f9_1 = 0;
		}
		if (haveitem(0x2113) >= 28)
		{
			local_var_s6f9_1 = 0;
		}
		if (シナリオフラグ < 0x0cb7)
		{
			local_var_s6f9_1 = 0;
		}
		if (local_var_s6f9_1 == 0)
		{
			local_var_s6f9_1 = 1;
			local_var_s6f9_2 = 1;
			local_var_s6f9_3 = 1;
			while (local_var_s6f9_2)
			{
				if (local_var_s6f9_3)
				{
					NPC_GUILD.setkutipakustatus(1);
					setunazukistatus(1);
					askpos(0, 0, 127);
					file_var_s6_1 = aaske(0, 0x01000000);
					mesclose(0);
					messync(0, 1);
					NPC_GUILD.setkutipakustatus(0);
					setunazukistatus(0);
				}
				else
				{
					NPC_GUILD.setkutipakustatus(1);
					setunazukistatus(1);
					askpos(0, 0, 127);
					file_var_s6_1 = aaske(0, 0x01000001);
					mesclose(0);
					messync(0, 1);
					NPC_GUILD.setkutipakustatus(0);
					setunazukistatus(0);
				}
				local_var_s6f9_3 = 0;
				switch (file_var_s6_1)
				{
					case 0:
						setmesmacro(0, 0, 0, haveitem(0x2113));
						setmesmacro(0, 1, 0, haveitem(0x2112));
						setmesmacro(0, 2, 0, 28);
						setmesmacro(0, 3, 0, (28 - haveitem(0x2113)));
						setmesmacro(0, 4, 0, (3 - haveitem(0x2113)));
						if (haveitem(0x2112) == 0)
						{
							switch (haveitem(0x2113))
							{
								case 0:
									NPC_GUILD.setkutipakustatus(1);
									NPC_GUILD.setunazukistatus(1);
									NPC_GUILD.amese(0, 0x01000002);
									NPC_GUILD.messync(0, 1);
									NPC_GUILD.setkutipakustatus(0);
									NPC_GUILD.setunazukistatus(0);
									break;
								case lt(3):
									if ((haveitem(0x2113) != 1 && (3 - haveitem(0x2113)) != 1))
									{
										NPC_GUILD.setkutipakustatus(1);
										NPC_GUILD.setunazukistatus(1);
										NPC_GUILD.amese(0, 0x01000003);
										NPC_GUILD.messync(0, 1);
										NPC_GUILD.setkutipakustatus(0);
										NPC_GUILD.setunazukistatus(0);
									}
									if ((haveitem(0x2113) == 1 && (3 - haveitem(0x2113)) != 1))
									{
										NPC_GUILD.setkutipakustatus(1);
										NPC_GUILD.setunazukistatus(1);
										NPC_GUILD.amese(0, 0x01000004);
										NPC_GUILD.messync(0, 1);
										NPC_GUILD.setkutipakustatus(0);
										NPC_GUILD.setunazukistatus(0);
									}
									if ((haveitem(0x2113) != 1 && (3 - haveitem(0x2113)) == 1))
									{
										NPC_GUILD.setkutipakustatus(1);
										NPC_GUILD.setunazukistatus(1);
										NPC_GUILD.amese(0, 0x01000005);
										NPC_GUILD.messync(0, 1);
										NPC_GUILD.setkutipakustatus(0);
										NPC_GUILD.setunazukistatus(0);
									}
									break;
								case lt(28):
									if ((haveitem(0x2113) != 1 && (28 - haveitem(0x2113)) != 1))
									{
										NPC_GUILD.setkutipakustatus(1);
										NPC_GUILD.setunazukistatus(1);
										NPC_GUILD.amese(0, 0x01000006);
										NPC_GUILD.messync(0, 1);
										NPC_GUILD.setkutipakustatus(0);
										NPC_GUILD.setunazukistatus(0);
									}
									if ((haveitem(0x2113) != 1 && (28 - haveitem(0x2113)) == 1))
									{
										NPC_GUILD.setkutipakustatus(1);
										NPC_GUILD.setunazukistatus(1);
										NPC_GUILD.amese(0, 0x01000007);
										NPC_GUILD.messync(0, 1);
										NPC_GUILD.setkutipakustatus(0);
										NPC_GUILD.setunazukistatus(0);
									}
									if (haveitem(0x2113) == 1)
									{
										NPC_GUILD.setkutipakustatus(1);
										NPC_GUILD.setunazukistatus(1);
										NPC_GUILD.amese(0, 0x01000006);
										NPC_GUILD.messync(0, 1);
										NPC_GUILD.setkutipakustatus(0);
										NPC_GUILD.setunazukistatus(0);
									}
									break;
								default:
									NPC_GUILD.setkutipakustatus(1);
									NPC_GUILD.setunazukistatus(1);
									NPC_GUILD.amese(0, 0x01000008);
									NPC_GUILD.messync(0, 1);
									NPC_GUILD.setkutipakustatus(0);
									NPC_GUILD.setunazukistatus(0);
									subitem(0x2113, 28);
									sebsoundplay(0, 39);
									additemmes(0x2112, 1);
									global_var_8 = 1;
									NPC_GUILD.setkutipakustatus(1);
									NPC_GUILD.setunazukistatus(1);
									NPC_GUILD.amese(0, 0x01000009);
									NPC_GUILD.messync(0, 1);
									NPC_GUILD.setkutipakustatus(0);
									NPC_GUILD.setunazukistatus(0);
									break;
							}
						}
						else
						{
							NPC_GUILD.setkutipakustatus(1);
							NPC_GUILD.setunazukistatus(1);
							NPC_GUILD.amese(0, 0x0100000a);
							NPC_GUILD.messync(0, 1);
							NPC_GUILD.setkutipakustatus(0);
							NPC_GUILD.setunazukistatus(0);
							local_var_s6f9_2 = 0;
						}
						break;
					case 1:
						NPC_GUILD.setkutipakustatus(1);
						NPC_GUILD.setunazukistatus(1);
						NPC_GUILD.amese(0, 0x0100000b);
						NPC_GUILD.messync(0, 1);
						NPC_GUILD.setkutipakustatus(0);
						NPC_GUILD.setunazukistatus(0);
						break;
					case 2:
						local_var_s6f9_2 = 0;
						break;
				}
				wait(1);
			}
			NPC_GUILD.setkutipakustatus(1);
			NPC_GUILD.setunazukistatus(1);
			NPC_GUILD.amese(0, 0x0100000c);
			NPC_GUILD.messync(0, 1);
			NPC_GUILD.setkutipakustatus(0);
			NPC_GUILD.setunazukistatus(0);
		}
		else
		{
			local_var_s6f9_1 = 0;
			NPC_GUILD.setkutipakustatus(1);
			setunazukistatus(1);
			askpos(0, 0, 127);
			file_var_s6_1 = aaske(0, 0x0100000d);
			mesclose(0);
			messync(0, 1);
			NPC_GUILD.setkutipakustatus(0);
			setunazukistatus(0);
			if (file_var_s6_1 == 0)
			{
				NPC_GUILD.setkutipakustatus(1);
				NPC_GUILD.setunazukistatus(1);
				NPC_GUILD.amese(0, 0x0100000e);
				NPC_GUILD.messync(0, 1);
				NPC_GUILD.setkutipakustatus(0);
				NPC_GUILD.setunazukistatus(0);
				gillwinopen(havegill());
				setmesmacro(0, 0, 0, getprice(0xb075));
				NPC_GUILD.setkutipakustatus(1);
				setunazukistatus(1);
				askpos(0, 0, 127);
				file_var_s6_1 = aaske(0, 0x0100000f);
				mesclose(0);
				messync(0, 1);
				NPC_GUILD.setkutipakustatus(0);
				setunazukistatus(0);
				if (file_var_s6_1 == 0)
				{
					if (havegill() >= getprice(0xb075))
					{
						gillwinstart((-1 * getprice(0xb075)));
						gillwinsync();
						NPC_GUILD.setkutipakustatus(1);
						NPC_GUILD.setunazukistatus(1);
						NPC_GUILD.amese(0, 0x01000010);
						NPC_GUILD.messync(0, 1);
						NPC_GUILD.setkutipakustatus(0);
						NPC_GUILD.setunazukistatus(0);
						gillwinclose();
						sebsoundplay(0, 39);
						additemmes(0x2113, 1);
						if ((haveitem(0x2113) == 3 && global_var_1 == 0))
						{
							g_com_set_get_label = 139;
							sysReqew(1, イベント特殊効果画面::システムメッセージ表示);
							wait(1);
							global_var_1 = 1;
						}
						subgill(getprice(0xb075));
					}
					else
					{
						NPC_GUILD.setkutipakustatus(1);
						NPC_GUILD.setunazukistatus(1);
						NPC_GUILD.amese(0, 0x01000011);
						NPC_GUILD.messync(0, 1);
						NPC_GUILD.setkutipakustatus(0);
						NPC_GUILD.setunazukistatus(0);
					}
				}
				gillwinclose();
			}
		}
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		stdmotionplay_2c2(0x01000000, 20);
		return;
	}
}

actor NPC_婆さん(6)
{

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s7f0_1;        // pos: 0x44;

	function init()
	{
		local_var_s7f0_1 = 1;
		switch ((local_var_s7f0_1 & 0x03c0))
		{
			case 64:
				modelread(0x03000008);
				modelreadsync(0x03000008);
				break;
			case 128:
				modelread(0x03000009);
				modelreadsync(0x03000009);
				break;
			case 192:
				modelread(0x0300000a);
				modelreadsync(0x0300000a);
				break;
			case 0x0100:
				modelread(0x0300000b);
				modelreadsync(0x0300000b);
				break;
			case 0x0140:
				modelread(0x0300000c);
				modelreadsync(0x0300000c);
				break;
			case 0x0180:
				modelread(0x0300000d);
				modelreadsync(0x0300000d);
				break;
		}
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s7f1_1;        // pos: 0x24;
	int     local_var_s7f1_2;        // pos: 0x28;
	u_char  local_var_s7f1_3;        // pos: 0x40;
	char    local_var_s7f1_4;        // pos: 0x3d;

	function begin()
	{
		if ((local_var_s7f0_1 & 1))
		{
			hidecomplete();
			while (file_var_s0_9)
			{
				wait(1);
			}
			bindp2_d4(0x03000007, 1, 3);
			local_var_s7f1_1 = 16;
			local_var_s7f1_2 = 0x01000000;
			if ((local_var_s7f0_1 & 0x0140))
			{
				local_var_s7f1_1 = 19;
			}
			stdmotionread(local_var_s7f1_1);
			stdmotionreadsync();
			stdmotionplay_2c2(local_var_s7f1_2, 0);
			setnpcname(0);
			setoverheadicontype(0);
			if ((local_var_s7f0_1 & 8))
			{
				usemapid(0);
			}
			else
			{
				usemapid(1);
			}
			usecharhit(1);
			setweight(-1);
			motionloop(1);
			setpos2(1.23134899, 0.0029829999, 25.753521);
			dir(-1.52550006);
			set_ignore_hitgroup(10);
			switch ((local_var_s7f0_1 & 0x03c0))
			{
				case 64:
					bindc(0, 0x03000008, 2);
					break;
				case 128:
					bindc(1, 0x03000009, 2);
					break;
				case 192:
					bindc(1, 0x0300000a, 2);
					break;
				case 0x0100:
					bindc(0, 0x0300000b, 2);
					break;
				case 0x0140:
					bindc(0, 0x0300000c, 2);
					break;
				case 0x0180:
					bindc(0, 0x0300000d, 2);
					break;
			}
			if ((local_var_s7f0_1 & 0x1000))
			{
				rgbatrans(1, 1, 1, 0, 0);
				istouchucsync();
				clearhidecomplete();
				rgbatrans(1, 1, 1, 1, 0);
			}
			else
			{
				istouchucsync();
				bonecalcforce(-1);
				rgbatrans(1, 1, 1, 0, 0);
				istouchucsync();
				clearhidecomplete();
				rgbatrans(1, 1, 1, 1, 10);
			}
			local_var_s7f1_3 = 1;
			local_var_s7f1_4 = 1;
		}
		return;
	}

	function touch(3)
	{
		return;
	}

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
			{
				setaturnlookatlockstatus(1);
				aturn_261(getdestrotangzx_227(0));
			}
		}
		return;
	}

	function hit_disable()
	{
		usecharhit(0);
		return;
	}

	function event_show()
	{
		if ((!(local_var_s7f1_3) || (local_var_s7f0_1 & 0x0800)))
		{
			return;
		}
		clearhidecomplete();
		show_38(1);
		local_var_s7f1_4 = 1;
		return;
	}

	function event_hide()
	{
		if ((local_var_s7f0_1 & 0x0400))
		{
			return;
		}
		hidecomplete();
		show_38(0);
		local_var_s7f1_4 = 0;
		return;
	}

	function main(1)
	{
		usemapid(0);
		setpos2(1.23134899, 0.0029829999, 25.753521);
		dir(-1.52550006);
		setaccr_123(0.00100000005, 2);
		setwalkspeed(getdefaultwalkspeed());
		while (true)
		{
			setkubifuristatus(1);
			wait((rand_29(90) + 90));
			move(4.19999981, 0.0029829999, 25.75);
			setkubifuristatus(0);
			sysLookata(NPC03);
			setkutipakustatus(1);
			setunazukistatus(1);
			if (getucstatus())
			{
				NPC03.sysLookata(NPC_婆さん);
			}
			wait((rand_29(90) + 90));
			setkutipakustatus(0);
			setunazukistatus(0);
			if (getucstatus())
			{
				NPC03.lookatoff();
			}
			move(1.23134899, 0.0029829999, 25.75);
		}
	}
}

//======================================================================
//                        File scope variables                        //
//======================================================================
int     file_var_s8_1;           // pos: 0x1b80;
u_char  file_var_s8_2[64];       // pos: 0x5a00;
u_char  file_var_s8_3[64];       // pos: 0x5600;
u_char  file_var_s8_4[64];       // pos: 0x5e00;
char    file_var_s8_5;           // pos: 0xd0;
int     file_var_s8_6;           // pos: 0x3d40;
int     file_var_s8_7;           // pos: 0x5080;
float   file_var_s8_8[4][8];     // pos: 0x4040;
float   file_var_s8_9;           // pos: 0x50c0;
float   file_var_s8_10[4][8];    // pos: 0x4840;
float   file_var_s8_11;          // pos: 0x5100;

actor NPC01(6)
{

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s8f0_1;        // pos: 0x38;
	u_char  local_var_s8f0_2;        // pos: 0x41;
	int     local_var_s8f0_3;        // pos: 0x40;
	int     local_var_s8f0_4;        // pos: 0x80;

	function init()
	{
		local_var_s8f0_1 = 1;
		local_var_s8f0_2 = 1;
		file_var_s8_1 = (file_var_s8_1 + 1);
		local_var_s8f0_3 = file_var_s8_1;
		local_var_s8f0_4 = local_var_s8f0_3;
		file_var_s0_8[local_var_s8f0_4] = local_var_s8f0_3;
		file_var_s8_2[local_var_s8f0_3] = getmyid();
		file_var_s8_3[getmyid()] = local_var_s8f0_3;
		return;
	}

	function talk_03a()
	{
		setkubifuristatus(0);
		if (!((file_var_s1_8[local_var_s8f0_3] & 0x0800)))
		{
			sysRlookata(-1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
		}
		else
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
			setaturnlookatlockstatus(0);
			sysRaturna(-1);
			regI2 = 0;
			if (isturn())
			{
				turnsync();
				stdmotionplay_2c2(0x01000002, 20);
			}
			else
			{
				regI2 = 1;
			}
		}
		NPC03.setkutipakustatus(1);
		NPC03.setunazukistatus(1);
		NPC03.amese(0, 0x01000012);
		NPC03.messync(0, 1);
		NPC03.setkutipakustatus(0);
		NPC03.setunazukistatus(0);
		openfullscreenmenu_48d(2, 51);
		if (g_com_counter_for_horidasi[0] >= 255)
		{
			g_com_counter_for_horidasi[0] = 255;
		}
		else
		{
			g_com_counter_for_horidasi[0] = (g_com_counter_for_horidasi[0] + 1);
		}
		if ((g_com_counter_for_horidasi[0] >= 100 && !((g_com_check_for_horidasi[0] & 1))))
		{
			sethoridashi(0xd066);
			g_com_check_for_horidasi[0] = (g_com_check_for_horidasi[0] | 1);
		}
		for (regI0 = 0; regI0 < 64; regI0 = (regI0 + 1))
		{
			file_var_s8_4[regI0] = 0;
		}
		lookatoff();
		if ((file_var_s1_6[local_var_s8f0_3] & 4))
		{
			setkubifuristatus(1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
		}
		else
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
			stdmotionplay_2c2(0x01000000, 20);
		}
		return;
	}

	function talk_01a()
	{
		setkubifuristatus(0);
		if (!((file_var_s1_8[local_var_s8f0_3] & 0x0800)))
		{
			sysRlookata(-1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
		}
		else
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
			setaturnlookatlockstatus(0);
			sysRaturna(-1);
			regI2 = 0;
			if (isturn())
			{
				turnsync();
				stdmotionplay_2c2(0x01000002, 20);
			}
			else
			{
				regI2 = 1;
			}
		}
		switch ((0x3b0000 | getquestscenarioflag(59)))
		{
			case lt(0x3b000a):
				NPC01.setkutipakustatus(1);
				setunazukistatus(1);
				askpos(0, 0, 127);
				file_var_s6_1 = aaske(0, 0x01000013);
				mesclose(0);
				messync(0, 1);
				NPC01.setkutipakustatus(0);
				setunazukistatus(0);
				if (file_var_s6_1)
				{
					NPC01.setkutipakustatus(1);
					NPC01.setunazukistatus(1);
					NPC01.amese(0, 0x01000014);
					NPC01.messync(0, 1);
					NPC01.setkutipakustatus(0);
					NPC01.setunazukistatus(0);
				}
				else
				{
					NPC01.setkutipakustatus(1);
					NPC01.setunazukistatus(1);
					NPC01.amese(0, 0x01000015);
					NPC01.messync(0, 1);
					NPC01.setkutipakustatus(0);
					NPC01.setunazukistatus(0);
					setquestscenarioflag(59, 10);
				}
				break;
			case lt(0x3b0014):
				NPC01.setkutipakustatus(1);
				NPC01.setunazukistatus(1);
				NPC01.amese(0, 0x01000017);
				NPC01.messync(0, 1);
				NPC01.setkutipakustatus(0);
				NPC01.setunazukistatus(0);
				break;
			case lt(0x3b001e):
				NPC01.setkutipakustatus(1);
				setunazukistatus(1);
				askpos(0, 0, 127);
				file_var_s6_1 = aaske(0, 0x01000018);
				mesclose(0);
				messync(0, 1);
				NPC01.setkutipakustatus(0);
				setunazukistatus(0);
				if (file_var_s6_1)
				{
					NPC01.setkutipakustatus(1);
					NPC01.setunazukistatus(1);
					NPC01.amese(0, 0x01000019);
					NPC01.messync(0, 1);
					NPC01.setkutipakustatus(0);
					NPC01.setunazukistatus(0);
				}
				else
				{
					NPC01.setkutipakustatus(1);
					NPC01.setunazukistatus(1);
					NPC01.amese(0, 0x0100001a);
					NPC01.messync(0, 1);
					NPC01.setkutipakustatus(0);
					NPC01.setunazukistatus(0);
					subitem(0x80a3, 1);
					setquestscenarioflag(59, 30);
				}
				break;
			default:
				NPC01.setkutipakustatus(1);
				NPC01.setunazukistatus(1);
				NPC01.amese(0, 0x0100001b);
				NPC01.messync(0, 1);
				NPC01.setkutipakustatus(0);
				NPC01.setunazukistatus(0);
				break;
		}
		for (regI0 = 0; regI0 < 64; regI0 = (regI0 + 1))
		{
			file_var_s8_4[regI0] = 0;
		}
		lookatoff();
		if ((file_var_s1_6[local_var_s8f0_3] & 4))
		{
			setkubifuristatus(1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
		}
		else
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
			stdmotionplay_2c2(0x01000000, 20);
		}
		return;
	}

	function talk_04a()
	{
		setkubifuristatus(0);
		if (!((file_var_s1_8[local_var_s8f0_3] & 0x0800)))
		{
			sysRlookata(-1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
		}
		else
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
			setaturnlookatlockstatus(0);
			sysRaturna(-1);
			regI2 = 0;
			if (isturn())
			{
				turnsync();
				stdmotionplay_2c2(0x01000002, 20);
			}
			else
			{
				regI2 = 1;
			}
		}
		settalknpcname(0x03a0);
		settalknpcname(0x03a1);
		sysLookata(NPC05);
		NPC04.setkutipakustatus(1);
		NPC04.setunazukistatus(1);
		NPC04.amese(0, 0x0100001c);
		NPC04.messync(0, 1);
		NPC04.setkutipakustatus(0);
		NPC04.setunazukistatus(0);
		NPC05.sysLookata(NPC04);
		NPC05.setkutipakustatus(1);
		NPC05.setunazukistatus(1);
		NPC05.amese(0, 0x0100001d);
		NPC05.messync(0, 1);
		NPC05.setkutipakustatus(0);
		NPC05.setunazukistatus(0);
		lookatoff();
		NPC05.lookatoff();
		for (regI0 = 0; regI0 < 64; regI0 = (regI0 + 1))
		{
			file_var_s8_4[regI0] = 0;
		}
		lookatoff();
		if ((file_var_s1_6[local_var_s8f0_3] & 4))
		{
			setkubifuristatus(1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
		}
		else
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
			stdmotionplay_2c2(0x01000000, 20);
		}
		return;
	}

	function talk_05a()
	{
		return;
	}

	function talk_02a()
	{
		setkubifuristatus(0);
		if (!((file_var_s1_8[local_var_s8f0_3] & 0x0800)))
		{
			sysRlookata(-1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
		}
		else
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
			setaturnlookatlockstatus(0);
			sysRaturna(-1);
			regI2 = 0;
			if (isturn())
			{
				turnsync();
				stdmotionplay_2c2(0x01000002, 20);
			}
			else
			{
				regI2 = 1;
			}
		}
		if ((0x340000 | getquestscenarioflag(52)) < 0x340064)
		{
			NPC06.setkutipakustatus(1);
			NPC06.setunazukistatus(1);
			NPC06.amese(0, 0x0100001e);
			NPC06.messync(0, 1);
			NPC06.setkutipakustatus(0);
			NPC06.setunazukistatus(0);
			sysLookata(-1);
			NPC06.setkutipakustatus(1);
			NPC06.setunazukistatus(1);
			NPC06.amese(0, 0x0100001f);
			NPC06.messync(0, 1);
			NPC06.setkutipakustatus(0);
			NPC06.setunazukistatus(0);
			sebsoundplay(0, 39);
			additemmes(0x906b, 1);
			NPC06.setkutipakustatus(1);
			NPC06.setunazukistatus(1);
			NPC06.amese(0, 0x01000020);
			NPC06.messync(0, 1);
			NPC06.setkutipakustatus(0);
			NPC06.setunazukistatus(0);
			lookatoff();
			setquestscenarioflag(52, 100);
		}
		else
		{
			NPC06.setkutipakustatus(1);
			NPC06.setunazukistatus(1);
			NPC06.amese(0, 0x01000021);
			NPC06.messync(0, 1);
			NPC06.setkutipakustatus(0);
			NPC06.setunazukistatus(0);
		}
		for (regI0 = 0; regI0 < 64; regI0 = (regI0 + 1))
		{
			file_var_s8_4[regI0] = 0;
		}
		lookatoff();
		if ((file_var_s1_6[local_var_s8f0_3] & 4))
		{
			setkubifuristatus(1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
		}
		else
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
			stdmotionplay_2c2(0x01000000, 20);
		}
		return;
	}

	symlink talk_06a(talk_02a) : -1;

	function talk_07a()
	{
		setkubifuristatus(0);
		if (!((file_var_s1_8[local_var_s8f0_3] & 0x0800)))
		{
			sysRlookata(-1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
		}
		else
		{
			sethpmenu(0);
			ucoff();
			settrapshowstatus(0);
			setaturnlookatlockstatus(0);
			sysRaturna(-1);
			regI2 = 0;
			if (isturn())
			{
				turnsync();
				stdmotionplay_2c2(0x01000002, 20);
			}
			else
			{
				regI2 = 1;
			}
		}
		NPC07.setkutipakustatus(1);
		NPC07.setunazukistatus(1);
		NPC07.amese(0, 0x01000022);
		NPC07.messync(0, 1);
		NPC07.setkutipakustatus(0);
		NPC07.setunazukistatus(0);
		for (regI0 = 0; regI0 < 64; regI0 = (regI0 + 1))
		{
			file_var_s8_4[regI0] = 0;
		}
		lookatoff();
		if ((file_var_s1_6[local_var_s8f0_3] & 4))
		{
			setkubifuristatus(1);
		}
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
		}
		else
		{
			ucon();
			sethpmenu(1);
			clear_force_char_nearfade();
			setmaphighmodeldepth(-1);
			setmapmodelstatus(1);
			setstatuserrordispdenystatus(0);
			settrapshowstatus(1);
			stdmotionplay_2c2(0x01000000, 20);
		}
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s8f8_1;        // pos: 0x24;
	int     local_var_s8f8_2;        // pos: 0x28;
	u_char  local_var_s8f8_3;        // pos: 0x40;

	function begin()
	{
		hidecomplete();
		while (file_var_s0_9)
		{
			wait(1);
		}
		switch ((file_var_s1_6[local_var_s8f0_3] & 0x03c0))
		{
			case 64:
				modelread(0x03000008);
				modelreadsync(0x03000008);
				break;
			case 128:
				modelread(0x03000009);
				modelreadsync(0x03000009);
				break;
			case 192:
				modelread(0x0300000a);
				modelreadsync(0x0300000a);
				break;
			case 0x0100:
				modelread(0x0300000b);
				modelreadsync(0x0300000b);
				break;
			case 0x0140:
				modelread(0x0300000c);
				modelreadsync(0x0300000c);
				break;
			case 0x0180:
				modelread(0x0300000d);
				modelreadsync(0x0300000d);
				break;
		}
		usecharhit(0);
		if (!(file_var_s0_1[local_var_s8f0_3]))
		{
			return 0;
		}
		switch (file_var_s0_1[local_var_s8f0_3])
		{
			case 0x01b6ac:
				bindp2_d4(0x0300000e, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b6ad:
				bindp2_d4(0x0300000e, 0, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b710:
				bindp2_d4(0x0300000f, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x018da8:
				bindp2_d4(0x03000010, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019390:
				bindp2_d4(0x03000000, 1, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0193b7:
				bindp2_d4(0x03000000, 5, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0193a3:
				bindp2_d4(0x03000000, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0193b0:
				bindp2_d4(0x03000000, 4, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019387:
				bindp2_d4(0x03000000, 0, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0193f4:
				bindp2_d4(0x03000001, 1, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019407:
				bindp2_d4(0x03000001, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01941d:
				bindp2_d4(0x03000001, 5, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019414:
				bindp2_d4(0x03000001, 4, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019401:
				bindp2_d4(0x03000001, 2, 5);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0193fd:
				bindp2_d4(0x03000001, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0193fe:
				bindp2_d4(0x03000001, 2, 2);
				local_var_s8f8_1 = 18;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019476:
				bindp2_d4(0x03000011, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019461:
				bindp2_d4(0x03000011, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01946d:
				bindp2_d4(0x03000011, 3, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019464:
				bindp2_d4(0x03000011, 2, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019476:
				bindp2_d4(0x03000011, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019457:
				bindp2_d4(0x03000011, 1, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0194bd:
				bindp2_d4(0x03000012, 1, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0194c5:
				bindp2_d4(0x03000012, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0194d0:
				bindp2_d4(0x03000012, 3, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0195e8:
				bindp2_d4(0x03000002, 1, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0195f1:
				bindp2_d4(0x03000002, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019607:
				bindp2_d4(0x03000002, 4, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0195fe:
				bindp2_d4(0x03000002, 3, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01964c:
				bindp2_d4(0x03000003, 1, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019655:
				bindp2_d4(0x03000003, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01966b:
				bindp2_d4(0x03000003, 4, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019662:
				bindp2_d4(0x03000003, 3, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019708:
				bindp2_d4(0x03000013, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01978b:
				bindp2_d4(0x03000004, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019796:
				bindp2_d4(0x03000004, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019783:
				bindp2_d4(0x03000004, 2, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01977a:
				bindp2_d4(0x03000004, 1, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0197ef:
				bindp2_d4(0x03000006, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0197fa:
				bindp2_d4(0x03000006, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0197e7:
				bindp2_d4(0x03000006, 2, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0197de:
				bindp2_d4(0x03000006, 1, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0197d0:
				bindp2_d4(0x03000006, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019853:
				bindp2_d4(0x03000007, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01985e:
				bindp2_d4(0x03000007, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01984c:
				bindp2_d4(0x03000007, 2, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019841:
				bindp2_d4(0x03000007, 1, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0198ae:
				bindp2_d4(0x03000005, 2, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0198ad:
				bindp2_d4(0x03000005, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0198b8:
				bindp2_d4(0x03000005, 3, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0198c1:
				bindp2_d4(0x03000005, 4, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x0198a4:
				bindp2_d4(0x03000005, 1, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019907:
				bindp2_d4(0x03000014, 1, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019912:
				bindp2_d4(0x03000014, 2, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01991b:
				bindp2_d4(0x03000014, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019928:
				bindp2_d4(0x03000014, 4, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01996b:
				bindp2_d4(0x03000015, 1, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019976:
				bindp2_d4(0x03000015, 2, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01997f:
				bindp2_d4(0x03000015, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01998c:
				bindp2_d4(0x03000015, 4, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019b61:
				bindp2_d4(0x03000016, 1, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019b69:
				bindp2_d4(0x03000016, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019b76:
				bindp2_d4(0x03000016, 3, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019b7e:
				bindp2_d4(0x03000016, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019b6c:
				bindp2_d4(0x03000016, 2, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019bd7:
				bindp2_d4(0x03000017, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019bcd:
				bindp2_d4(0x03000017, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019bd8:
				bindp2_d4(0x03000017, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019bc6:
				bindp2_d4(0x03000017, 1, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019bcd:
				bindp2_d4(0x03000017, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019c1c:
				bindp2_d4(0x03000018, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019c1d:
				bindp2_d4(0x03000018, 0, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019c1e:
				bindp2_d4(0x03000018, 0, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019c1f:
				bindp2_d4(0x03000018, 0, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019c20:
				bindp2_d4(0x03000018, 0, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019c3d:
				bindp2_d4(0x03000018, 3, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019ce4:
				bindp2_d4(0x03000019, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x019cef:
				bindp2_d4(0x03000019, 1, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a46f:
				bindp2_d4(0x0300001a, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a47a:
				bindp2_d4(0x0300001a, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a465:
				bindp2_d4(0x0300001a, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a45d:
				bindp2_d4(0x0300001a, 1, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a4d3:
				bindp2_d4(0x0300001b, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a4de:
				bindp2_d4(0x0300001b, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a4c9:
				bindp2_d4(0x0300001b, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a4c1:
				bindp2_d4(0x0300001b, 1, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a5b3:
				bindp2_d4(0x0300001c, 5, 5);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a587:
				bindp2_d4(0x0300001c, 1, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a592:
				bindp2_d4(0x0300001c, 2, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a59d:
				bindp2_d4(0x0300001c, 3, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a5a8:
				bindp2_d4(0x0300001c, 4, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a5e0:
				bindp2_d4(0x0300001d, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a644:
				bindp2_d4(0x0300001e, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01a6a8:
				bindp2_d4(0x0300001f, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b1b7:
				bindp2_d4(0x03000020, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b1c2:
				bindp2_d4(0x03000020, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b1ad:
				bindp2_d4(0x03000020, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b21b:
				bindp2_d4(0x03000021, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b226:
				bindp2_d4(0x03000021, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b211:
				bindp2_d4(0x03000021, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b27f:
				bindp2_d4(0x03000022, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b28a:
				bindp2_d4(0x03000022, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b275:
				bindp2_d4(0x03000022, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b2e3:
				bindp2_d4(0x03000023, 3, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b2ee:
				bindp2_d4(0x03000023, 4, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b2d9:
				bindp2_d4(0x03000023, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b333:
				bindp2_d4(0x03000024, 1, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b33e:
				bindp2_d4(0x03000024, 2, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b349:
				bindp2_d4(0x03000024, 3, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b33d:
				bindp2_d4(0x03000024, 2, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01b968:
				bindp2_d4(0x03000025, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01bd5b:
				bindp2_d4(0x03000026, 1, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01bd66:
				bindp2_d4(0x03000026, 2, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01bd71:
				bindp2_d4(0x03000026, 3, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01bd7c:
				bindp2_d4(0x03000026, 4, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01bdbf:
				bindp2_d4(0x03000027, 1, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01bdca:
				bindp2_d4(0x03000027, 2, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01bdd5:
				bindp2_d4(0x03000027, 3, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01bde0:
				bindp2_d4(0x03000027, 4, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be24:
				bindp2_d4(0x03000028, 1, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be2f:
				bindp2_d4(0x03000028, 2, 3);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be3a:
				bindp2_d4(0x03000028, 3, 4);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be41:
				bindp2_d4(0x03000028, 4, 1);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be18:
				bindp2_d4(0x03000028, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be1f:
				bindp2_d4(0x03000028, 0, 7);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be1a:
				bindp2_d4(0x03000028, 0, 2);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be21:
				bindp2_d4(0x03000028, 0, 9);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01be1d:
				bindp2_d4(0x03000028, 0, 5);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01c264:
				bindp2_d4(0x03000029, 0, 0);
				local_var_s8f8_1 = 17;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01c96c:
				bindp2_d4(0x0300002a, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01de84:
				bindp2_d4(0x0300002b, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x018c18:
				bindp2_d4(0x0300002c, 0, 0);
				local_var_s8f8_1 = 1;
				local_var_s8f8_2 = 0x01000001;
				break;
			case 0x01cbcf:
				bindp2_d4(0x0300002d, 1, 1);
				local_var_s8f8_1 = 1;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01cbc4:
				bindp2_d4(0x0300002d, 0, 0);
				local_var_s8f8_1 = 1;
				local_var_s8f8_2 = 0x01000000;
				break;
			case 0x01ccf0:
				bindp2_d4(0x0300002e, 0, 0);
				local_var_s8f8_1 = 1;
				local_var_s8f8_2 = 0x01000001;
				break;
			case 0x01ee88:
				bindp2_d4(0x0300002f, 0, 0);
				local_var_s8f8_1 = 1;
				local_var_s8f8_2 = 0x01000001;
				break;
			default:
				bindp2_d4(0x03000018, 0, 0);
				local_var_s8f8_1 = 16;
				local_var_s8f8_2 = 0x01000000;
				break;
		}
		if ((file_var_s1_6[local_var_s8f0_3] & 0x0140))
		{
			local_var_s8f8_1 = 19;
		}
		setautorelax(1);
		stdmotionread(local_var_s8f8_1);
		stdmotionreadsync();
		if (file_var_s0_1[local_var_s8f0_3] == 0x0193fe)
		{
			stdmotionvariation(1);
		}
		stdmotionplay_2c2(local_var_s8f8_2, 0);
		set_ignore_hitgroup(10);
		usemapid(1);
		usecharhit(0);
		setweight(-1);
		setautorelax(1);
		switch ((file_var_s1_6[local_var_s8f0_3] & 0x03c0))
		{
			case 64:
				bindc(0, 0x03000008, 2);
				break;
			case 128:
				bindc(1, 0x03000009, 2);
				break;
			case 192:
				bindc(1, 0x0300000a, 2);
				break;
			case 0x0100:
				bindc(0, 0x0300000b, 2);
				break;
			case 0x0140:
				bindc(0, 0x0300000c, 2);
				break;
			case 0x0180:
				bindc(0, 0x0300000d, 2);
				break;
		}
		local_var_s8f8_3 = 1;
		return;
	}

	function main(1)
	{
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s8f10_1;       // pos: 0xc0;
	char    local_var_s8f10_2;       // pos: 0x3d;
	u_char  local_var_s8f10_3;       // pos: 0x3e;
	u_char  local_var_s8f10_4;       // pos: 0x3f;
	int     local_var_s8f10_5;       // pos: 0x18;
	int     local_var_s8f10_6;       // pos: 0x2c;
	int     local_var_s8f10_7;       // pos: 0x10;
	int     local_var_s8f10_8;       // pos: 0x14;
	float   local_var_s8f10_9;       // pos: 0x1c;
	float   local_var_s8f10_10;      // pos: 0x20;
	int     local_var_s8f10_11;      // pos: 0x30;
	int     local_var_s8f10_12;      // pos: 0x34;

	function logic_main()
	{
		while (true)
		{
			if (((local_var_s8f10_1 >= 0 && !(file_var_s8_5)) && local_var_s8f10_2))
			{
				local_var_s8f10_1 = (local_var_s8f10_1 + 1);
				if ((file_var_s1_6[local_var_s8f0_3] & 16))
				{
					if (local_var_s8f10_3 == 0)
					{
						if (local_var_s8f10_4)
						{
							local_var_s8f10_4 = (local_var_s8f10_4 - 1);
						}
						else
						{
							setkutipakustatus(0);
							setunazukistatus(0);
							if ((file_var_s1_10[local_var_s8f0_3] & 255))
							{
								local_var_s8f10_4 = rand_29(3);
							}
							else
							{
								local_var_s8f10_4 = rand_29(50);
							}
							local_var_s8f10_3 = 1;
						}
					}
					else if (local_var_s8f10_4)
					{
						local_var_s8f10_4 = (local_var_s8f10_4 - 1);
					}
					else
					{
						setkutipakustatus(1);
						setunazukistatus(1);
						if ((file_var_s1_10[local_var_s8f0_3] & 255))
						{
							local_var_s8f10_4 = rand_29(3);
						}
						else
						{
							local_var_s8f10_4 = rand_29(90);
						}
						local_var_s8f10_3 = 0;
					}
				}
				local_var_s8f10_5 = file_var_s1_16[local_var_s8f0_3][local_var_s8f10_1];
				local_var_s8f10_6 = file_var_s1_16[local_var_s8f0_3][(local_var_s8f10_1 - 1)];
				switch (local_var_s8f10_6)
				{
					case 1:
						setwalkspeed(getdefaultwalkspeed());
						local_var_s8f10_7 = file_var_s1_16[local_var_s8f0_3][(local_var_s8f10_1 + 0)];
						local_var_s8f10_8 = file_var_s1_16[local_var_s8f0_3][(local_var_s8f10_1 + 1)];
						aturn((0.00999999978 * local_var_s8f10_7), 0, (0.00999999978 * local_var_s8f10_8));
						lookatoff();
						move((0.00999999978 * local_var_s8f10_7), 0, (0.00999999978 * local_var_s8f10_8));
						local_var_s8f10_1 = (local_var_s8f10_1 + 2);
						break;
					case 2:
						setwalkspeed(getdefaultrunspeed());
						local_var_s8f10_7 = file_var_s1_16[local_var_s8f0_3][(local_var_s8f10_1 + 0)];
						local_var_s8f10_8 = file_var_s1_16[local_var_s8f0_3][(local_var_s8f10_1 + 1)];
						aturn((0.00999999978 * local_var_s8f10_7), 0, (0.00999999978 * local_var_s8f10_8));
						lookatoff();
						move((0.00999999978 * local_var_s8f10_7), 0, (0.00999999978 * local_var_s8f10_8));
						local_var_s8f10_1 = (local_var_s8f10_1 + 2);
						break;
					case 3:
						setwalkspeed(getdefaultwalkspeed());
						aturn(file_var_s0_5[local_var_s8f0_3], 0, file_var_s0_7[local_var_s8f0_3]);
						lookatoff();
						move(file_var_s0_5[local_var_s8f0_3], 0, file_var_s0_7[local_var_s8f0_3]);
						break;
					case 4:
						setwalkspeed(getdefaultrunspeed());
						aturn(file_var_s0_5[local_var_s8f0_3], 0, file_var_s0_7[local_var_s8f0_3]);
						lookatoff();
						move(file_var_s0_5[local_var_s8f0_3], 0, file_var_s0_7[local_var_s8f0_3]);
						break;
					case 31:
					case 32:
					case 33:
					case 34:
					case 35:
					case 36:
					case 37:
					case 38:
					case 39:
						wait((30 * ((1 + local_var_s8f10_6) - 31)));
						break;
					case 10:
						setaturnlookatlockstatus(1);
						aturn_261((0.00999999978 * local_var_s8f10_5));
						lookatoff();
						local_var_s8f10_1 = (local_var_s8f10_1 + 1);
						break;
					case 11:
						setwalkspeed(getdefaultwalkspeed());
						local_var_s8f10_9 = ((cos((file_var_s8_6 / 3.14159274)) * (0.00999999978 * local_var_s8f10_5)) + file_var_s0_5[local_var_s8f0_3]);
						local_var_s8f10_10 = ((sin((file_var_s8_6 / 3.14159274)) * (0.00999999978 * local_var_s8f10_5)) + file_var_s0_7[local_var_s8f0_3]);
						aturn(local_var_s8f10_9, 0, local_var_s8f10_10);
						lookatoff();
						move(local_var_s8f10_9, 0, local_var_s8f10_10);
						local_var_s8f10_1 = (local_var_s8f10_1 + 1);
						break;
					case 88:
						setpos2(file_var_s0_5[local_var_s8f0_3], file_var_s0_6[local_var_s8f0_3], file_var_s0_7[local_var_s8f0_3]);
						dir(file_var_s1_9[local_var_s8f0_3]);
						local_var_s8f10_1 = 0;
						wait(1);
						break;
					case 12:
						lookatt((getrotangzx() + 2), local_var_s8f10_5);
						lookatsync();
						wait(90);
						local_var_s8f10_1 = (local_var_s8f10_1 + 1);
						break;
					case 13:
						lookatt((getrotangzx() - 2), local_var_s8f10_5);
						lookatsync();
						wait(90);
						local_var_s8f10_1 = (local_var_s8f10_1 + 1);
						break;
					case 14:
						sysLookata(-1);
						wait(30);
						break;
					case 15:
						lookatoff();
						break;
					case 50:
					case 51:
					case 52:
					case 53:
						local_var_s8f10_11 = 0;
						local_var_s8f10_12 = 0;
						file_var_s8_7 = (local_var_s8f10_6 - 50);
						while (local_var_s8f10_11 >= 0)
						{
							file_var_s8_9 = ((((file_var_s8_8[file_var_s8_7][(local_var_s8f10_11 + 1)] - file_var_s8_8[file_var_s8_7][(local_var_s8f10_11 + 0)]) * local_var_s8f10_12) / 0x0100) + file_var_s8_8[file_var_s8_7][(local_var_s8f10_11 + 0)]);
							file_var_s8_11 = ((((file_var_s8_10[file_var_s8_7][(local_var_s8f10_11 + 1)] - file_var_s8_10[file_var_s8_7][(local_var_s8f10_11 + 0)]) * local_var_s8f10_12) / 0x0100) + file_var_s8_10[file_var_s8_7][(local_var_s8f10_11 + 0)]);
							if (distance_292(getx(), getz(), file_var_s8_9, file_var_s8_11) < 2)
							{
								if (local_var_s8f10_12 < 0x0100)
								{
									local_var_s8f10_12 = (local_var_s8f10_12 + 1);
								}
								else
								{
									local_var_s8f10_12 = 0;
									if (local_var_s8f10_11 < 6)
									{
										local_var_s8f10_11 = (local_var_s8f10_11 + 1);
									}
									else
									{
										local_var_s8f10_11 = -1;
									}
								}
							}
							else
							{
								setwalkspeed(getdefaultrunspeed());
								rmove(file_var_s8_9, 0, file_var_s8_11);
								wait(1);
							}
						}
						movesync();
						setwalkspeed(getdefaultrunspeed());
						move(file_var_s8_8[file_var_s8_7][7], 0, file_var_s8_10[file_var_s8_7][7]);
						break;
					case 60:
						if (distance_290(-1, getx(), getz()) > (0.00999999978 * local_var_s8f10_5))
						{
							local_var_s8f10_1 = (local_var_s8f10_1 - 1);
						}
						else
						{
							local_var_s8f10_1 = (local_var_s8f10_1 + 1);
						}
						wait(1);
						break;
					case 61:
						if (distance_290(-1, getx(), getz()) < (0.00999999978 * local_var_s8f10_5))
						{
							local_var_s8f10_1 = (local_var_s8f10_1 - 1);
						}
						else
						{
							local_var_s8f10_1 = (local_var_s8f10_1 + 1);
						}
						wait(1);
						break;
					case 77:
						local_var_s8f10_1 = (local_var_s8f10_1 + (local_var_s8f10_5 - 1));
						break;
					default:
						local_var_s8f10_1 = 0;
						motionloop(1);
						wait(1);
						break;
				}
				motionloop(1);
				switch ((file_var_s1_10[local_var_s8f0_3] & 255))
				{
					case 1:
						motionplay_bb(0x10000001, 0);
						motionsync_282(1);
						break;
				}
			}
			else
			{
				wait(1);
			}
		}
	}

	function logic_off()
	{
		lookatoff();
		local_var_s8f10_1 = -1;
		return 0;
	}

	function logic_cont()
	{
		lookatoff();
		local_var_s8f10_1 = 0;
		return;
	}

	function talk(2)
	{
		return;
	}

	function touch(3)
	{
		return;
	}

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if ((file_var_s1_8[local_var_s8f0_3] & 0x0400))
		{
			return;
		}
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
			{
				setaturnlookatlockstatus(1);
				aturn_261(getdestrotangzx_227(0));
			}
		}
		return;
	}

	function not_talk()
	{
		return;
	}

	function npc_halt()
	{
		motionratio(0);
		while (true)
		{
			wait(1);
		}
	}

	function hit_disable()
	{
		usecharhit(0);
		return;
	}

	function event_show()
	{
		if (!(local_var_s8f8_3))
		{
			return;
		}
		file_var_s0_2[local_var_s8f0_4] = 1;
		clearhidecomplete();
		local_var_s8f10_2 = 1;
		show();
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function event_hide()
	{
		if ((file_var_s1_6[local_var_s8f0_3] & 0x0400))
		{
			return;
		}
		file_var_s0_2[local_var_s8f0_4] = 0;
		local_var_s8f10_2 = 0;
		hide();
		hidecomplete();
		return;
	}

	function clip_hide()
	{
		if (!(local_var_s8f8_3))
		{
			return;
		}
		local_var_s8f10_2 = 0;
		incentryid();
		usemapid(0);
		usecharhit(0);
		reqdisable(2);
		lookatoff();
		movecancel();
		motioncancel();
		file_var_s0_2[local_var_s8f0_4] = 0;
		if (local_var_s8f10_1 >= 0)
		{
			setpos2(file_var_s0_5[local_var_s8f0_3], file_var_s0_6[local_var_s8f0_3], file_var_s0_7[local_var_s8f0_3]);
			local_var_s8f10_1 = 0;
		}
		hidecomplete();
		if (file_var_s0_4)
		{
			return;
		}
		return 0;
	}

	function clip_show()
	{
		if (file_var_s8_5)
		{
			return;
		}
		if (!(local_var_s8f8_3))
		{
			return;
		}
		local_var_s8f10_2 = 1;
		local_var_s8f0_3 = file_var_s0_8[local_var_s8f0_4];
		file_var_s0_2[local_var_s8f0_4] = 1;
		if (local_var_s8f10_1 >= 0)
		{
			usemapid(0);
			setpos2(file_var_s0_5[local_var_s8f0_3], file_var_s0_6[local_var_s8f0_3], file_var_s0_7[local_var_s8f0_3]);
			dir(file_var_s1_9[local_var_s8f0_3]);
			local_var_s8f10_1 = 0;
			wait(1);
		}
		istouchucsync();
		bonecalcforce(-1);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		if ((file_var_s1_6[local_var_s8f0_3] & 10))
		{
			incentryid();
			reqdisable(2);
		}
		else
		{
			reqenable(2);
			if (file_var_s1_7[local_var_s8f0_3] < 0x1000)
			{
				setnpcname(file_var_s1_7[local_var_s8f0_3]);
				setoverheadicontype(0);
			}
			else
			{
				setshopname((file_var_s1_7[local_var_s8f0_3] & 0x0fff));
				setoverheadicontype(1);
			}
		}
		if ((file_var_s1_6[local_var_s8f0_3] & 4))
		{
			setkubifuristatus(1);
		}
		if ((file_var_s1_6[local_var_s8f0_3] & 32))
		{
			sysRlookata(-1);
		}
		movecancel();
		setkutipakustatus(0);
		setunazukistatus(0);
		motionclear();
		showshadow();
		switch (file_var_s1_8[local_var_s8f0_3])
		{
			case 1:
				usemapid(1);
				fetchambient();
				usecharhit(1);
				setweight(-1);
				break;
			case 0x0400:
				usemapid(0);
				fetchambient_4e1((file_var_s0_5[local_var_s8f0_3] + (sin(file_var_s1_9[local_var_s8f0_3]) * 0.5)), file_var_s0_6[local_var_s8f0_3], (file_var_s0_7[local_var_s8f0_3] + (cos(file_var_s1_9[local_var_s8f0_3]) * 0.5)));
				usecharhit(1);
				setweight(-1);
				break;
			case 0x0402:
				usemapid(0);
				fetchambient_4e1((file_var_s0_5[local_var_s8f0_3] + (sin(file_var_s1_9[local_var_s8f0_3]) * 2)), file_var_s0_6[local_var_s8f0_3], (file_var_s0_7[local_var_s8f0_3] + (cos(file_var_s1_9[local_var_s8f0_3]) * 2)));
				usecharhit(0);
				talkradius(0.300000012);
				settalkradiusoffset(file_var_s1_12[local_var_s8f0_3], 0, file_var_s1_13[local_var_s8f0_3]);
				break;
			case 0x0404:
				usemapid(0);
				fetchambient_4e1((file_var_s0_5[local_var_s8f0_3] + (sin(file_var_s1_9[local_var_s8f0_3]) * 1)), file_var_s0_6[local_var_s8f0_3], (file_var_s0_7[local_var_s8f0_3] + (cos(file_var_s1_9[local_var_s8f0_3]) * 1)));
				usecharhit(1);
				setweight(-1);
				if ((file_var_s1_12[local_var_s8f0_3] | file_var_s1_13[local_var_s8f0_3]))
				{
					setradius_221(file_var_s1_12[local_var_s8f0_3], file_var_s1_13[local_var_s8f0_3]);
				}
				break;
			case 0x0c80:
				usemapid(0);
				fetchambient_4e1((file_var_s0_5[local_var_s8f0_3] + (sin(file_var_s1_9[local_var_s8f0_3]) * 2)), file_var_s0_6[local_var_s8f0_3], (file_var_s0_7[local_var_s8f0_3] + (cos(file_var_s1_9[local_var_s8f0_3]) * 2)));
				usecharhit(0);
				hideshadow();
				break;
			case 0x0c10:
				usemapid(0);
				fetchambient_4e1((file_var_s0_5[local_var_s8f0_3] + (sin(file_var_s1_9[local_var_s8f0_3]) * 0.5)), file_var_s0_6[local_var_s8f0_3], (file_var_s0_7[local_var_s8f0_3] + (cos(file_var_s1_9[local_var_s8f0_3]) * 0.5)));
				usecharhit(1);
				setweight(-1);
				break;
			case 32:
				usemapid(1);
				fetchambient();
				usecharhit(0);
				hide();
				break;
			case 64:
				hide();
				usemapid(0);
				fetchambient_4e1((file_var_s0_5[local_var_s8f0_3] + (sin(file_var_s1_9[local_var_s8f0_3]) * 0)), file_var_s0_6[local_var_s8f0_3], (file_var_s0_7[local_var_s8f0_3] + (cos(file_var_s1_9[local_var_s8f0_3]) * 0)));
				usecharhit(1);
				setweight(-1);
				break;
		}
		stdmotionplay_2c2(local_var_s8f8_2, 0);
		if (file_var_s0_4)
		{
			return;
		}
		if ((file_var_s1_10[local_var_s8f0_3] & 255))
		{
			setautorelax(0);
			motionloop(1);
		}
		else
		{
			motionclear();
			stdmotionplay_2c2(local_var_s8f8_2, 0);
		}
		if ((file_var_s1_10[local_var_s8f0_3] & 255) == 1)
		{
			motionplay_bb(0x10000001, 0);
		}
		return;
	}
}

symlink NPC02(NPC01) : 6;

symlink NPC03(NPC01) : 1;

symlink NPC04(NPC01) : 2;

symlink NPC05(NPC01) : 3;

symlink NPC06(NPC01) : 4;

symlink NPC07(NPC01) : 5;




actor NPC_Alchemist(6) {
  // @description: pause idle animations during dialog
  int stop_random_motion;
	int rantom_move_head;
  // @description: player choice
  int local_choice;
  // @description: equipment category
  int local_category;
  // @description: equipment list index
  int local_equipment_index;
  // @description: selected equipment id
  u_short local_selected_equipment;
  int local_i;
  int local_count;
  // @description: equipment count
  int local_equipment_qtty;
  int local_has_required_items;
  int local_element_id;
  int local_attribute_id;
  // @description: attribute tier
  int local_tier;
  // @description: equipment indexes
  int local_available_indices[32];

  function init()
  {
    return;
  }

  function begin() {
    // hidecomplete();
    // modelread(0x03000004);
    // modelreadsync(0x03000004);
    // bindp2_d4(0x03000004, 3, 1);
    // stdmotionread(16);
    // stdmotionreadsync();
    // stdmotionplay_2c2(0x0100001b, 6);
    // usemapid(0);
    // setnpcname(0x0423);
    // setoverheadicontype(0);
    // usecharhit(1);
    // setweight(-1);
    // set_ignore_hitgroup(10);
    // motionloop(1);
    // fetchambient_4e1((4.55 + (sin(-3.08848) * 2)), 3.376, (7.03 +
    // (cos(-3.08848) * 2))); setpos(11.4, 3.376, 1.8); dir(-0.8);
    // settalkradiusoffset(0, 0, -1.5);
    // istouchucsync();
    // bonecalcforce(-1);
    // rgbatrans(1, 1, 1, 0, 0);
    // istouchucsync();
    // clearhidecomplete();
    // rgbatrans(1, 1, 1, 1, 10);
    // hideshadow();
    // setnavimapfootmarkstatus(1);


		hidecomplete();

		modelread(0x03000004);
		modelreadsync(0x03000004);
		bindp2_d4(0x03000004, 3, 2);
		stdmotionread(16);
		stdmotionreadsync();
		stdmotionplay_2c2(0x0100001b, 6);
		fieldsignmes(0x01000000 | 1059);
		setnpcname(0x0423);

		setpos(11.4, 3.376, 1.8);
		dir(-0.6);
		setweight(-1);
		set_ignore_hitgroup(1);

		clearhidecomplete();
		setnavimapfootmarkstatus(1);
		rgbatrans(1, 1, 1, 1, 10);

		hideshadow();

    return;
  }

  function touch(3) {
    return;
  }

  function talkhold(16) {
    return;
  }

  function talkterm(17) {
    if (((getrotangzx() - getdestrotangzx_227(0)) *
         (getrotangzx() - getdestrotangzx_227(0))) > 0) {
      if (((getrotangzx() - getdestrotangzx_227(0)) *
           (getrotangzx() - getdestrotangzx_227(0))) > 0) {
        setaturnlookatlockstatus(1);
        aturn_261(getdestrotangzx_227(0));
      }
    }
    return;
  }

  function main(1) {
    while (true) {
      if (stop_random_motion == 1) {
        wait(1);
				lookatoff();
        continue;
      }

      motionplay_bb(0x10000000, 20);
      wait(1);
      motionsync_282(1);

			rantom_move_head = rand_29(2);
			if (rantom_move_head == 0)
			{
				lookatoff();
			}
			else
			{
				rantom_move_head = rand_29(2);
				if (rantom_move_head == 0)
				{
					sysLookata(-1);
				}
				else
				{
					sysLookata(0);
				}
			}

      wait((rand_29(180) + 90));
    }
  }

  // @description: dialog handler
  function talk(2) {
    stop_random_motion = 1;
    flow_status = 0;
    flow_poll_mode = 0;
    flow_selected = 0;
    flow_success = 0;
    flow_reset = 0;
    flow_load_equipment = 0;
    selected_category = 0;
    selected_subcategory = 0;
    selected_equipment_id = 0;
    selected_tier = 0;

    sethpmenu(0);
    ucoff();
    settrapshowstatus(0);
    sysRturna(-1);
    if (isturn()) {
      turnsync();
      stdmotionplay_2c2(0x01000002, 20);
    }
		setkutipakustatus(1);
    setunazukistatus(1);
    setkubifuristatus(1);

  // @description: main menu
  dialog_40:
    flow_poll_mode = 1;

    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 40);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 0) {
      flow_status = 2;
      goto dialog_41;
    } else if (local_choice == 1) {
      flow_status = 3;
      goto dialog_42;
    } else if (local_choice == 2) {
      goto dialog_51;
    }

  dialog_41:
    flow_poll_mode = 1;
    amese(0, 0x01000000 | 41);
    messync(0, 1);
    goto dialog_43;

  dialog_42:
    flow_poll_mode = 1;
    amese(0, 0x01000000 | 42);
    messync(0, 1);
    goto dialog_44;

  // @description: element category selection
  dialog_43:
    flow_poll_mode = 1;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 43, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 2) {
      goto dialog_40;
    }
    if (local_choice == 3) {
      goto dialog_51;
    }

    local_category = local_choice;
    if (local_category == 0) {
      goto dialog_45;
    } else if (local_category == 1) {
      goto dialog_49;
    }

  // @description: attribute category selection
  dialog_44:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 6);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 44, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 6) {
      goto dialog_40;
    }
    if (local_choice == 7) {
      goto dialog_51;
    }

    local_category = local_choice;
    if (local_category == 0) {
      goto dialog_45;
    } else if (local_category == 1) {
      goto dialog_46;
    } else if (local_category == 2) {
      goto dialog_47;
    } else if (local_category == 3) {
      goto dialog_48;
    } else if (local_category == 4) {
      goto dialog_49;
    } else if (local_category == 5) {
      selected_category = 36;
      flow_load_equipment = 1;
      wait(14);
      flow_load_equipment = 0;
      goto dialog_50;
    }

  dialog_45:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 6);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 45, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 17) {
      if (flow_status == 2) {
        goto dialog_43;
      } else {
        goto dialog_44;
      }
    }
    if (local_choice == 18) {
      goto dialog_51;
    }

    if (local_choice >= 0 && local_choice <= 16) {
      selected_category = local_choice + 1;
      flow_load_equipment = 1;
      wait(14);
      flow_load_equipment = 0;
      goto dialog_50;
    }

  dialog_46:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 5);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 46, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 3) {
      if (flow_status == 2) {
        goto dialog_43;
      } else {
        goto dialog_44;
      }
    }
    if (local_choice == 4) {
      goto dialog_51;
    }

    if (local_choice >= 0 && local_choice <= 2) {
      selected_category = local_choice + 18;
      flow_load_equipment = 1;
      wait(14);
      flow_load_equipment = 0;
      goto dialog_50;
    }

  dialog_47:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 5);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 47, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 3) {
      if (flow_status == 2) {
        goto dialog_43;
      } else {
        goto dialog_44;
      }
    }
    if (local_choice == 4) {
      goto dialog_51;
    }

    if (local_choice >= 0 && local_choice <= 2) {
      selected_category = local_choice + 21;
      flow_load_equipment = 1;
      wait(14);
      flow_load_equipment = 0;
      goto dialog_50;
    }

  dialog_48:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 5);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 48, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 8) {
      if (flow_status == 2) {
        goto dialog_43;
      } else {
        goto dialog_44;
      }
    }
    if (local_choice == 9) {
      goto dialog_51;
    }

    if (local_choice >= 0 && local_choice <= 7) {
      selected_category = local_choice + 24;
      flow_load_equipment = 1;
      wait(14);
      flow_load_equipment = 0;
      goto dialog_50;
    }

  dialog_49:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 6);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 49, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 4) {
      if (flow_status == 2) {
        goto dialog_43;
      } else {
        goto dialog_44;
      }
    }
    if (local_choice == 5) {
      goto dialog_51;
    }
    if (local_choice >= 0 && local_choice <= 3) {
      selected_category = local_choice + 32;
      flow_load_equipment = 1;
      wait(14);
      flow_load_equipment = 0;
      goto dialog_50;
    }

  return_to_category_dialog:
    if (selected_category >= 1 && selected_category <= 17) goto dialog_45;
    if (selected_category >= 18 && selected_category <= 20) goto dialog_46;
    if (selected_category >= 21 && selected_category <= 23) goto dialog_47;
    if (selected_category >= 24 && selected_category <= 31) goto dialog_48;
    if (selected_category >= 32 && selected_category <= 35) goto dialog_49;
    if (flow_status == 2)
      goto dialog_43;
    else
      goto dialog_44;

  // @description: equipment list
  dialog_50:
    flow_poll_mode = 2;
    local_count = 0;
    local_equipment_qtty = 0;
    for (local_i = 0; local_i <= 30; local_i++) {
      if (equipment_list[local_i] == 0) {
        setaskselectignore(0, local_i);
      } else {
        local_count++;
        if (haveitem(equipment_list[local_i]) > 0) {
          setmesmacro(0, local_equipment_qtty, 1, equipment_list[local_i]);
          local_available_indices[local_equipment_qtty] = local_i;
          local_equipment_qtty++;
        } else {
          setaskselectignore(0, local_i);
        }
      }
    }

    if (local_equipment_qtty == 0) {
      amese(0, 0x01000000 | 52);
      messync(0, 1);
      goto return_to_category_dialog;
    }

    for (local_i = local_equipment_qtty; local_i <= 30; local_i++) {
      setaskselectignore(0, local_i);
    }

    if (local_equipment_qtty > 6) {
      setmeswinline(0, 7);
    } else {
      setmeswinline(0, local_equipment_qtty + 1);
    }

    askpos(0, 0, local_equipment_qtty + 1);
    local_equipment_index = aask(0, 0x01000000 | 50, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_equipment_index >= local_equipment_qtty) {
      goto return_to_category_dialog;
    }

    local_selected_equipment =
        equipment_list[local_available_indices[local_equipment_index]];
    selected_equipment_id = local_selected_equipment;
    flow_selected = 1;

    if (flow_status == 2) {
      goto dialog_53;
    } else if (flow_status == 3) {
      if (selected_category >= 1 && selected_category <= 17) {
        goto dialog_74;
      } else if (selected_category == 36) {
        goto dialog_75;
      } else if (selected_category >= 18 && selected_category <= 23) {
        goto dialog_76;
      } else if (selected_category >= 24 && selected_category <= 35) {
        goto dialog_77;
      } else {
        goto cleanup;
      }
    } else {
      goto cleanup;
    }

  // @description: element selection
  dialog_53:
    flow_poll_mode = 2;
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 6);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 53, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 9) {
      goto dialog_50;
    }

    if (local_choice >= 0 && local_choice <= 8) {
      if (local_choice == 8) {
        selected_subcategory = 9;
      } else {
        selected_subcategory = local_choice + 1;
      }

      if (local_choice == 0) {
        goto dialog_54;
      } else if (local_choice == 1) {
        goto dialog_55;
      } else if (local_choice == 2) {
        goto dialog_56;
      } else if (local_choice == 3) {
        goto dialog_57;
      } else if (local_choice == 4) {
        goto dialog_58;
      } else if (local_choice == 5) {
        goto dialog_59;
      } else if (local_choice == 6) {
        goto dialog_60;
      } else if (local_choice == 7) {
        goto dialog_61;
      } else if (local_choice == 8) {
        selected_subcategory = 9;
        goto check_element_before_remove;
      }
    }

  dialog_54:
    flow_poll_mode = 2;
    selected_subcategory = 1;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 54);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_55:
    selected_subcategory = 2;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 55);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_56:
    selected_subcategory = 3;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 6);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 56);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_57:

    selected_subcategory = 4;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 57);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_58:
    selected_subcategory = 5;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 58);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_59:
    selected_subcategory = 6;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 59);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_60:
    selected_subcategory = 7;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 60);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_61:
    selected_subcategory = 8;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 61);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  // @description: check existing element before remove
  check_element_before_remove:
    flow_check_element = 1;
    wait(14);
    flow_check_element = 0;

    if (obtained_current_element == 0) {
      goto dialog_131;
    }
    goto dialog_62;

  dialog_62:

    selected_subcategory = 9;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 62);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto dialog_50;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  // @description: check existing element before apply
  check_element_before_apply:
    flow_check_element = 1;
    wait(14);
    flow_check_element = 0;

    if (obtained_current_element >= 1 && obtained_current_element <= 8) {
      switch (obtained_current_element) {
        case 1:
          goto dialog_120;
        case 2:
          goto dialog_121;
        case 3:
          goto dialog_123;
        case 4:
          goto dialog_122;
        case 5:
          goto dialog_124;
        case 6:
          goto dialog_125;
        case 7:
          goto dialog_126;
        case 8:
          goto dialog_127;
        default:
          goto dialog_73;
      }
    }
    goto dialog_73;

  dialog_120:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 120);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }
    goto dialog_73;

  dialog_121:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 121);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 1) {
      goto dialog_50;
    }

    goto dialog_73;

  dialog_122:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 122);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }
    goto dialog_73;

  dialog_123:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 123);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }
    goto dialog_73;

  dialog_124:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 124);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }
    goto dialog_73;

  dialog_125:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 125);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }
    goto dialog_73;

  dialog_126:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 127);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }
    goto dialog_73;

  dialog_127:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 128);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }
    goto dialog_73;

  // @description: no element to remove
  dialog_131:
    flow_poll_mode = 2;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 131);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      goto dialog_51;
    }

  // @description: no attribute to remove
  dialog_132:
    flow_poll_mode = 2;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 132);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      goto dialog_51;
    }

  // @description: alchemy animation
  dialog_73:
    flow_poll_mode = 1;
		sebsoundplay(0, 39);
    amese(0, 0x01000000 | 73);
    messync(0, 1);

    sebsoundplay(0, 38);
    if (selected_subcategory != 9) {
      sysCommon2effectplay(PC00, 11);
    } else {
      sysCommon2effectplay(PC00, 10);
    }

    wait(35);

    if (flow_status == 2) {
      switch (selected_subcategory) {
        case 1:
          goto dialog_64;
        case 2:
          goto dialog_65;
        case 3:
          goto dialog_66;
        case 4:
          goto dialog_67;
        case 5:
          goto dialog_68;
        case 6:
          goto dialog_69;
        case 7:
          goto dialog_70;
        case 8:
          goto dialog_71;
        case 9:
          goto dialog_72;
        default:
          goto dialog_64;
      }
    } else if (flow_status == 3) {
      if (selected_subcategory == 0) {
        goto dialog_116;
      } else {
        goto attribute_success_dialog;
      }
    } else {
      goto dialog_64;
    }

  // @description: not enough items
  dialog_63:
    flow_poll_mode = 1;
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinclose();
		sebsoundplay(0, 39);
    local_choice = aaske(0, 0x01000000 | 63);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      goto cleanup;
    }

  dialog_64:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 64);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  dialog_65:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 65);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  dialog_66:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 66);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  dialog_67:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 67);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  dialog_68:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 68);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  dialog_69:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 69);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  dialog_70:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 70);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  dialog_71:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 71);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  dialog_72:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 72);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_50;
    } else if (local_choice == 1) {
      flow_success = 1;
      wait(14);
      flow_success = 0;
      goto cleanup;
    }

  // @description: back to attribute menu
  return_to_attribute_menu:
    if (selected_category >= 1 && selected_category <= 17) {
      goto dialog_74;
    } else if (selected_category == 36) {
      goto dialog_75;
    } else if (selected_category >= 18 && selected_category <= 23) {
      goto dialog_76;
    } else if (selected_category >= 24 && selected_category <= 35) {
      goto dialog_77;
    } else {
      goto dialog_50;
    }

  // @description: weapon attributes menu
  dialog_74:
    flow_poll_mode = 2;
    setmesmacro(0, 0, 1, selected_equipment_id);
    setmeswinline(0, 7);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 74, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 14) {
      goto dialog_50;
    }

    if (local_choice == 0) {
      selected_subcategory = 10;
      goto dialog_78;
    } else if (local_choice == 1) {
      selected_subcategory = 11;
      goto dialog_79;
    } else if (local_choice == 2) {
      selected_subcategory = 12;
      goto dialog_80;
    } else if (local_choice == 3) {
      selected_subcategory = 16;
      goto dialog_84;
    } else if (local_choice == 4) {
      selected_subcategory = 14;
      goto dialog_82;
    } else if (local_choice == 5) {
      selected_subcategory = 15;
      goto dialog_83;
    } else if (local_choice == 6) {
      selected_subcategory = 13;
      goto dialog_81;
    } else if (local_choice == 7) {
      selected_subcategory = 21;
      goto dialog_89;
    } else if (local_choice == 8) {
      selected_subcategory = 22;
      goto dialog_90;
    } else if (local_choice == 9) {
      selected_subcategory = 23;
      goto dialog_91;
    } else if (local_choice == 10) {
      selected_subcategory = 24;
      goto dialog_92;
    } else if (local_choice == 11) {
      selected_subcategory = 25;
      goto dialog_93;
    } else if (local_choice == 12) {
      selected_subcategory = 26;
      goto dialog_94;
    } else if (local_choice == 13) {
      selected_subcategory = 9;
      goto check_attribute_before_remove;
    }

  dialog_75:
    flow_poll_mode = 2;
    setmesmacro(0, 0, 1, selected_equipment_id);
    setmeswinline(0, 7);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 75, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 9) {
      goto dialog_50;
    }

    if (local_choice == 0) {
      selected_subcategory = 17;
      goto dialog_85;
    } else if (local_choice == 1) {
      selected_subcategory = 18;
      goto dialog_86;
    } else if (local_choice == 2) {
      selected_subcategory = 21;
      goto dialog_89;
    } else if (local_choice == 3) {
      selected_subcategory = 22;
      goto dialog_90;
    } else if (local_choice == 4) {
      selected_subcategory = 23;
      goto dialog_91;
    } else if (local_choice == 5) {
      selected_subcategory = 24;
      goto dialog_92;
    } else if (local_choice == 6) {
      selected_subcategory = 25;
      goto dialog_93;
    } else if (local_choice == 7) {
      selected_subcategory = 26;
      goto dialog_94;
    } else if (local_choice == 8) {
      selected_subcategory = 9;
      goto check_attribute_before_remove;
    }

  dialog_76:
    flow_poll_mode = 2;
    setmesmacro(0, 0, 1, selected_equipment_id);
    setmeswinline(0, 7);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 76, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 9) {
      goto dialog_50;
    }

    if (local_choice == 0) {
      selected_subcategory = 19;
      goto dialog_87;
    } else if (local_choice == 1) {
      selected_subcategory = 20;
      goto dialog_88;
    } else if (local_choice == 2) {
      selected_subcategory = 21;
      goto dialog_89;
    } else if (local_choice == 3) {
      selected_subcategory = 22;
      goto dialog_90;
    } else if (local_choice == 4) {
      selected_subcategory = 23;
      goto dialog_91;
    } else if (local_choice == 5) {
      selected_subcategory = 24;
      goto dialog_92;
    } else if (local_choice == 6) {
      selected_subcategory = 25;
      goto dialog_93;
    } else if (local_choice == 7) {
      selected_subcategory = 26;
      goto dialog_94;
    } else if (local_choice == 8) {
      selected_subcategory = 9;
      goto check_attribute_before_remove;
    }

  dialog_77:
    flow_poll_mode = 2;
    setmesmacro(0, 0, 1, selected_equipment_id);
    setmeswinline(0, 7);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 77, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 10) {
      goto dialog_50;
    }

    if (local_choice == 0) {
      selected_subcategory = 12;
      goto dialog_80;
    } else if (local_choice == 1) {
      selected_subcategory = 16;
      goto dialog_84;
    } else if (local_choice == 2) {
      selected_subcategory = 13;
      goto dialog_81;
    } else if (local_choice == 3) {
      selected_subcategory = 21;
      goto dialog_89;
    } else if (local_choice == 4) {
      selected_subcategory = 22;
      goto dialog_90;
    } else if (local_choice == 5) {
      selected_subcategory = 23;
      goto dialog_91;
    } else if (local_choice == 6) {
      selected_subcategory = 24;
      goto dialog_92;
    } else if (local_choice == 7) {
      selected_subcategory = 25;
      goto dialog_93;
    } else if (local_choice == 8) {
      selected_subcategory = 26;
      goto dialog_94;
    } else if (local_choice == 9) {
      selected_subcategory = 9;
      goto check_attribute_before_remove;
    }

  dialog_78:
    flow_poll_mode = 2;
    selected_subcategory = 10;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 78);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_79:
    flow_poll_mode = 2;
    selected_subcategory = 11;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 79);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_80:
    flow_poll_mode = 2;
    selected_subcategory = 12;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 80);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_81:
    flow_poll_mode = 2;
    selected_subcategory = 13;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 81);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_82:
    flow_poll_mode = 2;
    selected_subcategory = 14;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 82);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_83:
    flow_poll_mode = 2;
    selected_subcategory = 15;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 83);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_84:
    flow_poll_mode = 2;
    selected_subcategory = 16;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 84);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_85:
    flow_poll_mode = 2;
    selected_subcategory = 17;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 85);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_86:
    flow_poll_mode = 2;
    selected_subcategory = 18;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 86);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_87:
    flow_poll_mode = 2;
    selected_subcategory = 19;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 87);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_88:
    flow_poll_mode = 2;
    selected_subcategory = 20;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 88);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_89:
    flow_poll_mode = 2;
    selected_subcategory = 21;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 89);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_90:
    flow_poll_mode = 2;
    selected_subcategory = 22;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 90);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_91:
    flow_poll_mode = 2;
    selected_subcategory = 23;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 91);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_92:
    flow_poll_mode = 2;
    selected_subcategory = 24;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 92);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_93:
    flow_poll_mode = 2;
    selected_subcategory = 25;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 93);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  dialog_94:
    flow_poll_mode = 2;
    selected_subcategory = 26;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, obtained_tier1);
    setmesmacro(0, 9, 0, obtained_tier2);
    setmesmacro(0, 10, 0, obtained_tier3);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 94);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    if (local_choice == 2) {
      selected_tier = 3;
      goto check_attribute_before_apply;
    }

    if (local_choice == 1) {
      selected_tier = 2;
      goto check_attribute_before_apply;
    }

    if (local_choice == 0) {
      selected_tier = 1;
      goto check_attribute_before_apply;
    }

  // @description: check existing attribute before apply
  check_attribute_before_apply:

    flow_check_attribute = 1;
    wait(14);
    flow_check_attribute = 0;

    if (obtained_current_attribute >= 10 && obtained_current_attribute <= 26) {
      if (selected_tier == 1) {
        goto dialog_117;
      } else if (selected_tier == 2) {
        goto dialog_118;
      } else if (selected_tier == 3) {
        goto dialog_119;
      } else {
        goto dialog_117;
      }
    }

    if (selected_tier == 1) {
      goto dialog_95;
    } else if (selected_tier == 2) {
      goto dialog_96;
    } else if (selected_tier == 3) {
      goto dialog_97;
    } else {
      goto dialog_95;
    }

  // @description: tier 1 confirmation
  dialog_95:
    flow_poll_mode = 2;

    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 95);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto return_to_attribute_menu;
    }

    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    flow_success = 1;
    wait(14);
    flow_success = 0;
    goto dialog_128;

  // @description: tier 2 confirmation
  dialog_96:
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;
    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 96);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto return_to_attribute_menu;
    }
    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    flow_success = 1;
    wait(14);
    flow_success = 0;
    goto dialog_129;

  // @description: tier 3 confirmation
  dialog_97:
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;
    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 97);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto return_to_attribute_menu;
    }
    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    flow_success = 1;
    wait(14);
    flow_success = 0;
    goto dialog_130;

  // @description: check existing attribute before remove
  check_attribute_before_remove:
    flow_check_attribute = 1;
    wait(14);
    flow_check_attribute = 0;

    if (obtained_current_attribute == 0) {
      goto dialog_132;
    }
    goto dialog_98;

  // @description: remove attribute
  dialog_98:
    flow_poll_mode = 2;

    selected_subcategory = 9;
    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;
    setmesmacro(0, 0, 1, upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, upgrade_gil[0]);
    setmeswinline(0, 3);
    askpos(0, 0, 1);
		gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 98);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto return_to_attribute_menu;
    }
    if (haveitem(upgrade_item_ids[0]) < upgrade_item_qtys[0] ||
        haveitem(upgrade_item_ids[1]) < upgrade_item_qtys[1] ||
        haveitem(upgrade_item_ids[2]) < upgrade_item_qtys[2]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0 && havegill() < upgrade_gil[0]) {
      mesclose(0);
      messync(0, 1);
      goto dialog_63;
    }

    if (upgrade_gil[0] > 0) {
      gillwinstart((-1 * upgrade_gil[0]));
      gillwinsync();
      subgill(upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    flow_success = 1;
    wait(14);
    flow_success = 0;
    goto dialog_116;

  // @description: attribute success dialog route
  attribute_success_dialog:

    if (selected_subcategory == 10) {
      goto dialog_99;
    } else if (selected_subcategory == 11) {
      goto dialog_100;
    } else if (selected_subcategory == 12) {
      goto dialog_101;
    } else if (selected_subcategory == 13) {
      goto dialog_102;
    } else if (selected_subcategory == 14) {
      goto dialog_103;
    } else if (selected_subcategory == 15) {
      goto dialog_104;
    } else if (selected_subcategory == 16) {
      goto dialog_105;
    } else if (selected_subcategory == 17) {
      goto dialog_106;
    } else if (selected_subcategory == 18) {
      goto dialog_107;
    } else if (selected_subcategory == 19) {
      goto dialog_108;
    } else if (selected_subcategory == 20) {
      goto dialog_109;
    } else if (selected_subcategory == 21) {
      goto dialog_110;
    } else if (selected_subcategory == 22) {
      goto dialog_111;
    } else if (selected_subcategory == 23) {
      goto dialog_112;
    } else if (selected_subcategory == 24) {
      goto dialog_113;
    } else if (selected_subcategory == 25) {
      goto dialog_114;
    } else if (selected_subcategory == 26) {
      goto dialog_115;
    } else {
      goto return_to_attribute_menu;
    }

  dialog_99:
    flow_poll_mode = 1;
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 99);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_100:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 100);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_101:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 101);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_102:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 102);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_103:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 103);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_104:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 104);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_105:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 105);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_106:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 106);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_107:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 107);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_108:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 108);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_109:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 109);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_110:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 110);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_111:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 111);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_112:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 112);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_113:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 113);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_114:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 114);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  dialog_115:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 115);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto cleanup;
    }

  // @description: attribute removal success
  dialog_116:
    sebsoundplay(0, 38);
    sysCommon2effectplay(PC00, 10);

    wait(35);

    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 116);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_51;
    }

  // @description: tier 1 overwrite
  dialog_117:
    flow_poll_mode = 2;

    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 117);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }

    if (selected_tier == 1) {
      goto dialog_95;
    } else if (selected_tier == 2) {
      goto dialog_96;
    } else if (selected_tier == 3) {
      goto dialog_97;
    } else {
      goto dialog_95;
    }

  // @description: tier 2 overwrite
  dialog_118:

    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;

    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 118);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }

    if (selected_tier == 1) {
      goto dialog_95;
    } else if (selected_tier == 2) {
      goto dialog_96;
    } else if (selected_tier == 3) {
      goto dialog_97;
    } else {
      goto dialog_96;
    }

  // @description: tier 3 overwrite
  dialog_119:

    flow_load_equipment = 1;
    wait(14);
    flow_load_equipment = 0;
    setmesmacro(0, 1, 0, obtained_initial);
    setmesmacro(0, 2, 0, obtained_total);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 119);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_50;
    }
    if (selected_tier == 1) {
      goto dialog_95;
    } else if (selected_tier == 2) {
      goto dialog_96;
    } else if (selected_tier == 3) {
      goto dialog_97;
    } else {
      goto dialog_97;
    }

  // @description: tier 1 animation
  dialog_128:
    flow_poll_mode = 1;

		sebsoundplay(0, 39);
    amese(0, 0x01000000 | 129);
    messync(0, 1);

    sebsoundplay(0, 38);
    sysCommon2effectplay(PC00, 4);
    goto attribute_success_dialog;

  // @description: tier 2 animation
  dialog_129:
    flow_poll_mode = 1;

		sebsoundplay(0, 39);
    amese(0, 0x01000000 | 130);
    messync(0, 1);

    sebsoundplay(0, 38);
    sysCommon2effectplay(PC00, 4);
    goto attribute_success_dialog;

  // @description: tier 3 animation
  dialog_130:
    flow_poll_mode = 1;

		sebsoundplay(0, 39);
    amese(0, 0x01000000 | 131);
    messync(0, 1);

    sebsoundplay(0, 38);
    sysCommon2effectplay(PC00, 4);
    goto attribute_success_dialog;

  // @description: exit message
  dialog_51:
    flow_poll_mode = 1;
    amese(0, 0x01000000 | 51);
    messync(0, 1);
    goto cleanup;

  // @description: cleanup and restore
  cleanup:
    stop_random_motion = 0;
    flow_status = 0;
    flow_selected = 0;
    flow_success = 0;
    flow_reset = 0;
    flow_load_equipment = 0;
    selected_category = 0;
    selected_subcategory = 0;
    selected_equipment_id = 0;
    selected_tier = 0;

		setkutipakustatus(0);
    setunazukistatus(0);
    setkubifuristatus(0);

    ucon();
    sethpmenu(1);
    clear_force_char_nearfade();
    setmaphighmodeldepth(-1);
    setmapmodelstatus(1);
    setstatuserrordispdenystatus(0);
    settrapshowstatus(1);
    stdmotionplay_2c2(0x01000000, 20);
    return;
  }
}

//======================================================================
//                        File scope variables                        //
//======================================================================
int     file_var_s15_1;          // pos: 0x5180;
int     file_var_s15_2;          // pos: 0x51c0;
float   file_var_s15_3[4];       // pos: 0x5200;
float   file_var_s15_4[4];       // pos: 0x5300;
float   file_var_s15_5[4];       // pos: 0x5400;
float   file_var_s15_6[4];       // pos: 0x5500;

actor PlayerJack0(6)
{

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s15f0_1;       // pos: 0x80;

	function init()
	{
		local_var_s15f0_1 = file_var_s15_1;
		file_var_s15_1 = (file_var_s15_1 + 1);
		return;
	}

	function main(1)
	{
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	int     local_var_s15f2_1;       // pos: 0x40;

	function simple_player_jack()
	{
		local_var_s15f2_1 = capturebattlemembeructop(local_var_s15f0_1);
		motionclear();
		motionloop(1);
		stdmotionplay(0x01000000);
		return;
	}

	function start_player_jack()
	{
		if (file_var_s15_2 != local_var_s15f0_1)
		{
			local_var_s15f2_1 = capturebattlemembeructop(local_var_s15f0_1);
			file_var_s15_2 = local_var_s15f0_1;
			if (local_var_s15f2_1)
			{
				setpos2(file_var_s15_3[local_var_s15f0_1], file_var_s15_4[local_var_s15f0_1], file_var_s15_5[local_var_s15f0_1]);
				dir(file_var_s15_6[local_var_s15f0_1]);
				motionclear();
				motionloop(1);
				stdmotionplay(0x01000000);
			}
		}
		return;
	}

	function end_player_jack()
	{
		if (local_var_s15f2_1)
		{
			local_var_s15f2_1 = 0;
			lookatoff();
			usemapid(1);
			usecharhit(1);
			releasepc();
		}
		return;
	}
}

symlink PlayerJack1(PlayerJack0) : 1;

symlink PlayerJack2(PlayerJack0) : 2;

symlink PlayerJack3(PlayerJack0) : 3;

actor map_ダミーＰＣ(6)
{

	function init()
	{
		return;
	}

	function 扉オープン()
	{
		capturepc(-1);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcerelax(1);
		motionsync_282(1);
		clearforcerelax();
		motionsync_282(1);
		lookatoff();
		releasepc();
		return;
	}

	function 扉オープン１()
	{
		capturepc(-1);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcerelax(1);
		stdmotioneventsync();
		wait(8);
		return;
	}

	function 扉オープン２()
	{
		motionsync_282(1);
		clearforcerelax();
		motionsync_282(1);
		lookatoff();
		releasepc();
		return;
	}

	function アイテム１()
	{
		capturepc(-1);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcerelax(0);
		motionsync_282(1);
		stdmotionplay_2c2(0x0100001b, 6);
		stdmotioneventsync();
		return;
	}

	function アイテム２()
	{
		motionsync_282(1);
		clearforcerelax();
		motionsync_282(1);
		releasepc();
		return;
	}

	function ギミックアタック()
	{
		capturepc(-1);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcefight(-1);
		motionsync_282(1);
		stdmotionplay(0x0100001c);
		stdmotioneventsync();
		if (mp_map_set_hitse != -1)
		{
			mapsoundplay(mp_map_set_hitse);
		}
		vibplay(6);
		wait(6);
		vibstop();
		motionsync_282(1);
		clearforcefight();
		motionsync_282(1);
		releasepc();
		return;
	}

	function ギミックアタック１()
	{
		capturepc(-1);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcefight(-1);
		motionsync_282(1);
		stdmotionplay(0x0100001c);
		stdmotioneventsync();
		if (mp_map_set_hitse != -1)
		{
			mapsoundplay(mp_map_set_hitse);
		}
		vibplay(6);
		wait(6);
		vibstop();
		return;
	}

	function ギミックアタック２()
	{
		motionsync_282(1);
		clearforcefight();
		motionsync_282(1);
		releasepc();
		return;
	}

	function ギミックアタック1()
	{
		capturepc(-1);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcefight(-1);
		motionsync_282(1);
		stdmotionplay(0x0100001c);
		stdmotioneventsync();
		if (mp_map_set_hitse != -1)
		{
			mapsoundplay(mp_map_set_hitse);
		}
		vibplay(6);
		wait(6);
		vibstop();
		return;
	}

	function ギミックアタック2()
	{
		motionsync_282(1);
		clearforcefight();
		motionsync_282(1);
		releasepc();
		return;
	}

	function ターン()
	{
		capturepc(-1);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		lookatoff();
		releasepc();
		return;
	}

	function 扉オープンxyz()
	{
		capturepc(-1);
		rlookat_257(mp_map_set_x, (mp_map_set_y + -1.20000005), mp_map_set_z);
		turn(mp_map_set_x, mp_map_set_y, mp_map_set_z);
		turnsync();
		setforcerelax(1);
		motionsync_282(1);
		clearforcerelax();
		motionsync_282(1);
		lookatoff();
		releasepc();
		return;
	}

	function 扉オープン１xyz()
	{
		capturepc(-1);
		rlookat_257(mp_map_set_x, (mp_map_set_y + -1.20000005), mp_map_set_z);
		turn(mp_map_set_x, mp_map_set_y, mp_map_set_z);
		turnsync();
		setforcerelax(1);
		stdmotioneventsync();
		wait(8);
		return;
	}

	function 扉オープン２xyz()
	{
		motionsync_282(1);
		clearforcerelax();
		motionsync_282(1);
		lookatoff();
		releasepc();
		return;
	}

	function ギミックアタックxyz()
	{
		capturepc(-1);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcefight(-1);
		motionsync_282(1);
		stdmotionplay(0x0100001c);
		stdmotioneventsync();
		if (mp_map_set_hitse != -1)
		{
			mapsoundplay(mp_map_set_hitse);
		}
		vibplay(6);
		wait(6);
		vibstop();
		motionsync_282(1);
		clearforcefight();
		motionsync_282(1);
		releasepc();
		return;
	}

	function ギミックアタック１xyz()
	{
		capturepc(-1);
		mp_map_set_angle = getangle(mp_map_set_x, mp_map_set_z);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcefight(-1);
		motionsync_282(1);
		stdmotionplay(0x0100001c);
		stdmotioneventsync();
		if (mp_map_set_hitse != -1)
		{
			mapsoundplay(mp_map_set_hitse);
		}
		vibplay(6);
		wait(6);
		vibstop();
		return;
	}

	function ギミックアタック２xyz()
	{
		motionsync_282(1);
		clearforcefight();
		motionsync_282(1);
		releasepc();
		return;
	}

	function ギミックアタックxyz1()
	{
		capturepc(-1);
		mp_map_set_angle = getangle(mp_map_set_x, mp_map_set_z);
		rlookat(mp_map_set_angle);
		turn_62(mp_map_set_angle);
		turnsync();
		setforcefight(-1);
		motionsync_282(1);
		stdmotionplay(0x0100001c);
		stdmotioneventsync();
		if (mp_map_set_hitse != -1)
		{
			mapsoundplay(mp_map_set_hitse);
		}
		vibplay(6);
		wait(6);
		vibstop();
		return;
	}

	function ギミックアタックxyz2()
	{
		motionsync_282(1);
		clearforcefight();
		motionsync_282(1);
		releasepc();
		return;
	}

	function アイテム１xyz()
	{
		capturepc(-1);
		rlookat_257(mp_map_set_x, (mp_map_set_y + -1.20000005), mp_map_set_z);
		turn(mp_map_set_x, mp_map_set_y, mp_map_set_z);
		turnsync();
		stdmotionplay_2c2(0x0100001b, 6);
		stdmotioneventsync();
		return;
	}

	function アイテム２xyz()
	{
		motionsync_282(1);
		clearforcerelax();
		motionsync_282(1);
		lookatoff();
		releasepc();
		return;
	}

	function ターンxyz()
	{
		capturepc(-1);
		rlookat_257(mp_map_set_x, (mp_map_set_y + -1.20000005), mp_map_set_z);
		turn(mp_map_set_x, mp_map_set_y, mp_map_set_z);
		turnsync();
		lookatoff();
		releasepc();
		return;
	}

	function map_behind_return()
	{
		capturepc(-1);
		setnoupdatebehindcamera(0);
		releasepc();
		return;
	}

	function ＳＥＴＰＯＳxyz()
	{
		capturepc(-1);
		setpos(mp_map_set_x, mp_map_set_y, mp_map_set_z);
		releasepc();
		return;
	}

	function ＳＥＴＴＵＲＮxyz()
	{
		capturepc(-1);
		turnt(mp_map_set_x, mp_map_set_y, mp_map_set_z, 0);
		releasepc();
		return;
	}
}

actor PC00(7) : 0x80
{

	function init()
	{
		setupbattle(0);
		return;
	}
}

actor PC01(7) : 0x81
{

	function init()
	{
		setupbattle(1);
		return;
	}
}

actor PC02(7) : 0x82
{

	function init()
	{
		setupbattle(2);
		return;
	}
}

actor PC03(7) : 0x83
{

	function init()
	{
		setupbattle(3);
		return;
	}
}

//======================================================================
//                          Map exit arrays                           //
//======================================================================

mapExitArray mapExitGroup0[0] = {

};

mapExitArray mapExitGroup1[0] = {

};

mapExitArray mapExitGroup2[0] = {

};

mapExitArray mapExitGroup3[0] = {

};

mapExitArray mapExitGroup4[0] = {

};

//======================================================================
//                     Map jump position vectors                      //
//======================================================================

mjPosArr1 mapJumpPositions1[2] = {

	mjPos mapJumpPos0 = {
		7.87427092, 0, 27.851902, 3.14159131,
		0, 0, 0, 0
	};

	mjPos mapJumpPos1 = {
		7.87427092, 0, 27.851902, 3.14159131,
		0, 0, 0, 0
	};

};

mjPosArr2 mapJumpPositions2[100] = {

	mjPos mapJumpPos0 = {
		7.87427092, 0, 27.851902, 3.14159131,
		0, 0, 0, 0
	};

	mjPos mapJumpPos1 = {
		7.87427092, 0, 27.851902, 3.14159131,
		0, 0, 0, 0
	};

	mjPos mapJumpPos2 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos3 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos4 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos5 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos6 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos7 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos8 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos9 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos10 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos11 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos12 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos13 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos14 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos15 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos16 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos17 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos18 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos19 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos20 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos21 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos22 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos23 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos24 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos25 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos26 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos27 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos28 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos29 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos30 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos31 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos32 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos33 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos34 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos35 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos36 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos37 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos38 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos39 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos40 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos41 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos42 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos43 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos44 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos45 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos46 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos47 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos48 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos49 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos50 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos51 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos52 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos53 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos54 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos55 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos56 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos57 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos58 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos59 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos60 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos61 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos62 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos63 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos64 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos65 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos66 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos67 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos68 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos69 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos70 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos71 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos72 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos73 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos74 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos75 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos76 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos77 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos78 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos79 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos80 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos81 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos82 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos83 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos84 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos85 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos86 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos87 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos88 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos89 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos90 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos91 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos92 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos93 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos94 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos95 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos96 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos97 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos98 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos99 = {
		2.37619901, -0, 29.7319183, 0,
		0, 0, 0, 0
	};

};

//======================================================================
//                      Unknown position arrays                       //
//======================================================================
unkPos1 unknownPosition0[7] = {8.00238037, 0, 31.6698322, 1, 0.400000006, 0, 0};
unkPos1 unknownPosition1[7] = {7.91474581, 0, 30.6036091, 1.5, 1.5, 0, 0};

unkPos2 unknownPosition0[7] = {0, 0, 0, 0, 0, 0, 0};
unkPos2 unknownPosition1[7] = {0, 0, 0, 0, 0, 0, 0};
unkPos2 unknownPosition2[7] = {8, 1.20000005, 32.0155983, 1, 0.300000012, 0, 0};

//======================================================================
//                         Unknown u16 Arrays                         //
//======================================================================

unk16Arr1 unknown16Arrays1[1] = {
	unk16ArrEntry unknown16Array0 = {1, 0, 2, 0, 1, 0, 0, 0};
};

unk16Arr2 unknown16Arrays2[21] = {
	unk16ArrEntry unknown16Array0 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array1 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array2 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array3 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array4 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array5 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array6 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array7 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array8 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array9 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array10 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array11 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array12 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array13 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array14 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array15 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array16 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array17 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array18 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array19 = {0, 0, 0, 0, 0, 65535, 0, 0};
	unk16ArrEntry unknown16Array20 = {0, 1, 0, 0, 1, 65535, 0, 0};
};

unk16Arr3 unknown16Arrays3[8] = {
	unk16ArrEntry unknown16Array0 = {0, 768, 1, 1};
	unk16ArrEntry unknown16Array1 = {1, 768, 1, 1};
	unk16ArrEntry unknown16Array2 = {2, 768, 1, 1};
	unk16ArrEntry unknown16Array3 = {3, 768, 1, 1};
	unk16ArrEntry unknown16Array4 = {4, 768, 1, 1};
	unk16ArrEntry unknown16Array5 = {5, 768, 1, 9};
	unk16ArrEntry unknown16Array6 = {6, 768, 1, 1};
	unk16ArrEntry unknown16Array7 = {7, 768, 1, 1};
};

//======================================================================
//                      REQALL/REQWAITALL arrays                      //
//======================================================================

reqa   reqArr0[] = {
	NPC_GUILD::begin,
	NPC_婆さん::begin,
	NPC01::begin,
	NPC02::begin,
	NPC03::begin,
	NPC04::begin,
	NPC05::begin,
	NPC06::begin,
	NPC07::begin,
	NPC_Alchemist::begin
};
