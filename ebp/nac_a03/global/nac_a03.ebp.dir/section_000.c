// File size: 49888 Bytes
// Author:    t-hirose & FehDead
// Source:    nac_a03.src
// Date:      00/00 00:00
// Binary:    E:\ff12-tools\The.Insurgents.Workshop.v1.0.1 - Copia\files\source\plan_map\nac_a\nac_a03\global\nac_a03.ebp.dir\section_000.bin

option authorName = "t-hirose & FehDead";
option fileName = "nac_a03.src";
option spawnOrder = {-1, 1, -1, -1, -1, -1, -1, -1};
option unknownScriptId = 1;
option weatherProbability = {100, 0, 0};
option trapOffset = 0x0;

//====================0x38==================================================
//               Global and scratchpad variable imports               //
//======================================================================
import global   short   シナリオフラグ = 0x00;
import global   u_char  global_var_1 = 0x05b8;
import global   float   mp_map_set_angle = 0x0900;
import global   float   mp_map_set_x = 0x0904;
import global   float   mp_map_set_y = 0x0908;
import global   float   mp_map_set_z = 0x090c;
import global   int     mp_map_flg = 0x0910;
import global   char    mp_last_weather = 0x0940;
import global   char    mp_4map = 0x0941;
import global   char    mp_map_set_hitse = 0x0943;
import global   u_char  g_btl_魔神竜 = 0x0a18;
import global   u_char  g_btl_nm_ロビー = 0x0a54;
import global   u_char  g_btl_nm_ゴリアテ = 0x0a5a;
import global   float   g_com_navi_footcalc[3] = 0x0c7c;
import global   u_char  g_com_mnp_ナルビナ城塞市街地ロケタイ = 0x0cbd;
import global   u_char  g_com_counter_for_horidasi[10] = 0x0cd0;
import global   u_char  g_com_check_for_horidasi[2] = 0x0cda;
import scratch1 u_char  scratch1_var_1 = 0xc0;

//======================================================================
//                        Alchemist variables                        	//
//======================================================================

// flow flags
import scratch1   u_char		flow_poll_mode = 0x64;
import scratch1   u_char		flow_check_attribute = 0x65;
import scratch1   u_char		flow_check_element = 0x66;
import scratch1   u_char		flow_talk_status = 0x67;
import scratch1   u_char		flow_selected_intention = 0x68;
import scratch1   u_char		flow_confirmed_intention = 0x69;
import scratch1   u_char		flow_reset_flow = 0x6A;
import scratch1   u_char		flow_load_equipment = 0x6B;

// notification flags
import scratch1   u_char		notification_show_tier_message = 0x6C;
import scratch1   u_char		notification_show_supply_message = 0x6D;

// quest flags
import scratch1   u_char		quest_unlocked_tiers = 0x6E;
import scratch1   u_char		quest_main_quest_status = 0x6F;
import scratch1   u_char		quest_unlocked_elements[8] = 0x70;
import scratch1   u_char		quest_unlocked_attributes[17] = 0x78;
import scratch1   int				quest_main_quest_gil[1] = 0x90;

// selected flags
import scratch1   u_char		selected_category = 0x89;
import scratch1   u_char		selected_subcategory = 0x8A;
import scratch1   u_char		selected_tier = 0x8B;
import scratch1   short			selected_equipment_id = 0x8E;

// current values from checkElement/checkAttribute
import scratch1   u_char		current_element = 0x8C;
import scratch1   u_char		current_attribute = 0x8D;

// refinement values from lua
import scratch1   short			refinement_default_attribute_value = 0x94;
import scratch1   short			refinement_extra_attribute_value = 0x96;
import scratch1   short			refinement_total_attribute_value = 0x98;
import scratch1   short			refinement_tier1_attribute_value = 0x9A;
import scratch1   short			refinement_tier2_attribute_value = 0x9C;
import scratch1   short			refinement_tier3_attribute_value = 0x9E;

// loaded upgrade list from lua
import scratch1   u_short		load_upgrade_item_ids[3] = 0xA0;
import scratch1   u_char		load_upgrade_item_qtys[3] = 0xA6;
import scratch1   u_short		load_upgrade_gil[1] = 0xA9;

// loaded equipment list from lua
import scratch1   u_short		load_equipment_list[31] = 0xB0;

actor __MJ_CTRL000(0)
{

	function init()
	{
		reqenable(12);
		setmapjumpgroup(1);
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	char    local_var_s0f1_1;        // pos: 0x00;

	function mapjump(12)
	{
		local_var_s0f1_1 = 1;
		if (local_var_s0f1_1)
		{
			regI3 = sysucoff();
			if (regI3)
			{
				clearmapjumpstatus();
				sysucon();
			}
			else
			{
				mp_last_weather = getweatherslot();
				spotsoundtrans(40, 0);
				fadelayer(6);
				fadeprior(255);
				fadeout_d0(2, 12);
				for (regI0 = 1; regI0 <= 15; regI0 = (regI0 + 1))
				{
					setmapidmj(regI0, 1, 1);
				}
				if ((check_move_battlestatus(0) == 1 || istownmap() == 1))
				{
					ucmove_52b(0, 231.825546, 22.8100471, 222.530716);
				}
				if ((check_move_battlestatus(1) == 1 || istownmap() == 1))
				{
					ucmove_52b(1, 231.825546, 22.8100471, 222.530716);
				}
				if ((check_move_battlestatus(2) == 1 || istownmap() == 1))
				{
					ucmove_52b(2, 231.825546, 22.8100471, 222.530716);
				}
				if ((check_move_battlestatus(3) == 1 || istownmap() == 1))
				{
					ucmove_52b(3, 231.825546, 22.8100471, 222.530716);
				}
				wait(12);
				stopspotsound();
				pausesestop();
				fadesync();
				wait(2);
				mapjump(0x0277, 2, 0);
			}
		}
		return;
	}
}

actor setup(0)
{

	function init()
	{
		return;
	}

	function event()
	{
		switch (シナリオフラグ)
		{
			case 0x0122:
				musicfadeout_231(getnowmusicno(), 180, 1);
				stopenvsound_3de(180);
				wait(90);
				musicstop(getnowmusicno());
				wait(1);
				musicclear(getnowmusicno());
				setcharseplayall(0);
				break;
			default:
				if (g_com_mnp_ナルビナ城塞市街地ロケタイ == 0)
				{
					stopenvsoundall();
					setcharseplayall(0);
				}
				break;
		}
		return;
	}
}

//======================================================================
//                        File scope variables                        //
//======================================================================
u_char  file_var_s2_1;           // pos: 0x1c;

actor 監督(0)
{

	function init()
	{
		switch (シナリオフラグ)
		{
			case 0x0122:
				sethpmenu(0);
				ucoff();
				settrapshowstatus(0);
				fadeout(1);
				fadecancel_15a(2);
				break;
			default:
				sysReqewi(1, 常駐NPC配置監督::常駐NPC配置);
				if ((g_com_mnp_ナルビナ城塞市街地ロケタイ != 0 && lastmap() == 0x0320))
				{
					sethpmenu(0);
					ucoff();
					settrapshowstatus(0);
				}
				if (g_com_mnp_ナルビナ城塞市街地ロケタイ == 0)
				{
					fadecancel_15a(2);
					fadeout(0);
					sethpmenu(0);
					ucoff();
					settrapshowstatus(0);
				}
				break;
		}
		return;
	}

	function main(1)
	{
		switch (シナリオフラグ)
		{
			case 0x0122:
				bganimeplay_9e(10, 0, 0);
				シナリオフラグ = 0x012c;
				eventread(125);
				eventreadsync();
				setcharseplayall(1);
				eventplay();
				waitv(&scratch1_var_1);
				fadelayer(5);
				whiteout(0);
				eventsync();
				シナリオフラグ = 0x012d;
				mapjump(48, 0, 1);
				break;
			default:
				if (g_com_mnp_ナルビナ城塞市街地ロケタイ == 0)
				{
					bganimeplay_9e(10, 0, 0);
					sethpmenufast(0);
					maskopenfast(0);
					pausesestop();
					resetbehindcamerafovyroll();
					settrapshowstatus(0);
					sysReqew(1, ロケタイエフェクト監督::ロケタイエフェクト読込);
					moviestandby(1);
					sysReqew(1, ロケタイエフェクト監督::ロケタイエフェクト読込終了待ち);
					moviestandbysync();
					sethpmenufast(0);
					settrapshowstatus(0);
					movieplay(1);
					sysReq(1, movieSkip監督::Skip監視);
					sysReq(1, ロケタイエフェクト監督::ロケタイエフェクト再生);
					sysReqwait(movieSkip監督::Skip監視);
					movieplaysync();
					movieend();
					clearnavimapfootmark();
					sysFreqcancel2_575(ロケタイエフェクト監督, 0);
					wait(1);
					mesclose(0);
					mesclose(1);
					mesclose(2);
					mesclose(3);
					mesclose(4);
					mesclose(5);
					mesclose(6);
					mesclose(7);
					if (file_var_s2_1 != 0)
					{
					}
					if (file_var_s2_1 == 0)
					{
						sysReqew(1, ロケタイエフェクト監督::ロケタイエフェクト再生終了待ち);
					}
					fadelayer(6);
					fadeout(0);
					sethpmenufast(1);
					maskclosefast(0);
					setfocusstatus(0);
					blurstop_549(0);
					blurstop_549(1);
					resetbehindcamerafovyroll();
					setalllightstatus(0, 1);
					resetmapambient();
					seteventfogstatus(0);
					setlightallcutstatus(0);
					clearnavimapfootmark();
					clear_force_char_nearfade();
					setmaphighmodeldepth(-1);
					setmapmodelstatus(1);
					setstatuserrordispdenystatus(0);
					settrapshowstatus(1);
					sysReqew(2, ジョニー::bindoff_ジョニー);
					sysReqew(1, ロケイベント監督::re_set_ジョニー);
					sysReqew(1, ロケイベント監督::re_play_ジョニー);
					g_com_mnp_ナルビナ城塞市街地ロケタイ = 1;
					startenvsoundall();
					setcharseplayall(1);
					fadein(30);
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
					switch (lastmap())
					{
						case 0x0320:
							bganimeplay_9e(10, 60, 60);
							sysReqew(1, フェード::フェードまち);
							sysReqew(1, 扉::閉じる);
							ucon();
							sethpmenu(1);
							clear_force_char_nearfade();
							setmaphighmodeldepth(-1);
							setmapmodelstatus(1);
							setstatuserrordispdenystatus(0);
							settrapshowstatus(1);
							break;
						default:
							bganimeplay_9e(10, 0, 0);
							break;
					}
				}
				sysReq(1, 常駐NPC配置監督::常駐NPC配置_後読み);
				break;
		}
		return;
	}
}

//======================================================================
//                        File scope variables                        //
//======================================================================
u_char  file_var_s3_1;           // pos: 0x17;
u_char  file_var_s3_2;           // pos: 0x18;
u_char  file_var_s3_3;           // pos: 0x19;

actor 常駐NPC配置監督(0)
{

	function init()
	{
		sysDVAR(5, g_btl_魔神竜);
		sysDVAR(10, file_var_s3_1);
		sysDVAR(11, global_var_1);
		return;
	}

	function main(1)
	{
		return;
	}

	function 常駐NPC配置()
	{
		modelread(0x03000003);
		modelread(0x03000000);
		modelread(0x03000005);
		modelreadsync(0x03000003);
		modelreadsync(0x03000000);
		modelreadsync(0x03000005);
		motionread(1);
		motionread(3);
		motionreadsync(1);
		motionreadsync(3);
		switch (シナリオフラグ)
		{
			case lte(0x05f0):
				sysReqchg(2, NAC_A03_NPC04::talk_step01);
				sysReqchg(2, NAC_A03_NPC06::talk_step01);
				sysReqchg(2, NAC_A03_NPC07::talk_step01);
				break;
			case lte(0x1004):
				sysReqchg(2, NAC_A03_NPC04::talk_step02);
				sysReqchg(2, NAC_A03_NPC06::talk_step02);
				sysReqchg(2, NAC_A03_NPC07::talk_step02);
				break;
			case lte(0x2af8):
				sysReqchg(2, NAC_A03_NPC04::talk_step03);
				sysReqchg(2, NAC_A03_NPC06::talk_step03);
				sysReqchg(2, NAC_A03_NPC07::talk_step03);
				break;
			default:
				break;
		}
		sysReqchg(2, NAC_A03_NPC01::talk_step01);
		sysReqchg(2, NAC_A03_NPC02::talk_step01);
		sysReqchg(2, NAC_A03_NPC08::talk_step01_01);
		sysReqchg(2, NAC_A03_NPC09::talk_step01_01);
		sysReqewi(1, ロケイベント監督::set_ジョニー);
		if (global_var_1 >= 5)
		{
			sysReqchg(2, NAC_A03_NPC05::talk_step01_ex);
		}
		else
		{
			sysReqchg(2, NAC_A03_NPC05::talk_step01);
		}
		if (g_btl_魔神竜 != 2)
		{
			sysReqchg(2, NAC_A03_NPC03::talk_step_btl);
		}
		else
		{
			sysReqchg(2, NAC_A03_NPC03::talk_step_btl_after);
		}
		sysReqiall(1, reqArr0);
		sysReqwait(NAC_A03_NPC01::set);
		sysReqwait(NAC_A03_NPC02::set);
		sysReqwait(NAC_A03_NPC03::set);
		if (シナリオフラグ >= 0x015e)
		{
			sysReqchg(2, マップ帝国君移植版::talk_step01);
			sysReqewi(1, マップ帝国君移植版::set_通行解除);
		}
		else
		{
			sysReqchg(2, マップ帝国君移植版::talk_step00);
			sysReqewi(1, マップ帝国君移植版::set_通行解除);
		}
		sysReqiall(1, reqArr1);
		sysReqwait(マップ帝国君用アタリ::setHitObj);
		sysReqwait(NAC_A03_NPC07用アタリ::setHitObj);
		sysReqwait(NAC_A03_NPC11用アタリ::setHitObj);
		sysReqiall(1, reqArr2);
		sysReqwait(マップ帝国君移植版::motion_TAG);
		sysReqwait(NAC_A03_NPC01::motion_TAG);
		sysReqwait(NAC_A03_NPC02::motion_TAG);
		sysReqwait(NAC_A03_NPC03::motion_TAG);
		sysReqall(1, reqArr3);
		if ((getclanrank() >= 7 && シナリオフラグ >= 0x0bb8))
		{
			if (isquestclear(145))
			{
				file_var_s3_2 = 5;
			}
			else if (g_btl_nm_ロビー == 2)
			{
				file_var_s3_2 = 4;
			}
			else if (g_btl_nm_ロビー == 1)
			{
				file_var_s3_2 = 3;
			}
			else if (isquestorder(145))
			{
				file_var_s3_2 = 2;
			}
			else
			{
				file_var_s3_2 = 1;
			}
		}
		else
		{
			file_var_s3_2 = 0;
		}
		if ((file_var_s3_2 >= 2 && file_var_s3_2 < 5))
		{
			modelread(0x03000006);
			modelreadsync(0x03000006);
			sysReqi(1, 依頼人モルガン::set_q145);
			sysReqwait(依頼人モルガン::set_q145);
			sysReqewi(1, 依頼人モルガン::motion_TAG_q145);
			sysReq(1, 依頼人モルガン::walk_q145);
			switch ((0x910000 | getquestscenarioflag(145)))
			{
				case 0x91000a:
					sysReqchg(2, 依頼人モルガン::talk_q145_step01);
					break;
				case 0x91000f:
					sysReqchg(2, 依頼人モルガン::talk_q145_step02);
					break;
				case 0x910014:
					sysReqchg(2, 依頼人モルガン::talk_q145_step03);
					break;
				case 0x91001e:
					sysReqchg(2, 依頼人モルガン::talk_q145_step04);
					break;
				default:
					break;
			}
		}
		if ((getclanrank() >= 7 && シナリオフラグ >= 0x1004))
		{
			if (isquestclear(151))
			{
				file_var_s3_3 = 5;
			}
			else if (g_btl_nm_ゴリアテ == 2)
			{
				file_var_s3_3 = 4;
			}
			else if (g_btl_nm_ゴリアテ == 1)
			{
				file_var_s3_3 = 3;
			}
			else if (isquestorder(151))
			{
				file_var_s3_3 = 2;
			}
			else
			{
				file_var_s3_3 = 1;
			}
		}
		else
		{
			file_var_s3_3 = 0;
		}
		if ((file_var_s3_3 >= 2 && file_var_s3_3 < 5))
		{
			modelread(0x03000002);
			modelreadsync(0x03000002);
			if ((0x970000 | getquestscenarioflag(151)) <= 0x97000a)
			{
				sysReqewi(1, 依頼人バロング::set_q151);
			}
			else
			{
				sysReqewi(1, 依頼人バロング::set_q151_02);
			}
			sysReqewi(1, 依頼人バロング::motion_TAG_q151);
			sysReq(1, 依頼人バロング::walk_q151);
			switch ((0x970000 | getquestscenarioflag(151)))
			{
				case 0x97000a:
					sysReqchg(2, 依頼人バロング::talk_q151_step01);
					break;
				case 0x97000f:
					sysReqchg(2, 依頼人バロング::talk_q151_step02);
					break;
				case 0x970014:
					sysReqchg(2, 依頼人バロング::talk_q151_step03);
					break;
				case 0x97001e:
					sysReqchg(2, 依頼人バロング::talk_q151_step04);
					break;
				default:
					break;
			}
		}
		if (((0x910000 | getquestscenarioflag(145)) == 0x91001e || (0x970000 | getquestscenarioflag(151)) == 0x97001e))
		{
			sysReqewi(1, ジョニー２号::set_subev);
			sysReqewi(1, ジョニー２号::motion_TAG_subev);
		}
		return;
	}

	function 常駐NPC配置_後読み()
	{
		modelread(0x03000001);
		modelread(0x03000002);
		modelread(0x03000004);
		modelread(0x03000007);
		modelreadsync(0x03000001);
		modelreadsync(0x03000002);
		modelreadsync(0x03000004);
		modelreadsync(0x03000007);
		motionread(2);
		motionreadsync(2);
		sysReqiall(1, reqArr4);
		sysReqiall(1, reqArr5);
		sysReqwait(NAC_A03_NPC04::set_後読み);
		sysReqwait(NAC_A03_NPC05::set_後読み);
		sysReqwait(NAC_A03_NPC06::set_後読み);
		sysReqwait(NAC_A03_NPC07::set_後読み);
		sysReqwait(NAC_A03_NPC08::set_後読み);
		sysReqwait(NAC_A03_NPC09::set_後読み);
		sysReqwait(NAC_A03_NPC10::set_後読み);
		sysReqwait(NAC_A03_NPC11::set_後読み);
		sysReqwait(NAC_A03_NPC12::set_後読み);
		sysReqwait(NAC_A03_NPC13::set_後読み);
		sysReqwait(NAC_A03_NPC14::set_後読み);
		sysReqwait(NAC_A03_NPC15::set_後読み);
		sysReqwait(NAC_A03_NPC16::set_後読み);
		sysReqwait(NAC_A03_NPC17::set_後読み);
		sysReqwait(NAC_A03_BG_NPC01::set_後読み_遠景);
		sysReqwait(NAC_A03_BG_NPC02::set_後読み_遠景);
		sysReqwait(NAC_A03_BG_NPC04::set_後読み_遠景);
		sysReqwait(NAC_A03_BG_NPC05::set_後読み_遠景);
		sysReqwait(サボテン１::set_後読み);
		sysReqall(1, reqArr6);
		sysReqall(1, reqArr7);
		return;
	}
}

//======================================================================
//                        File scope variables                        //
//======================================================================
u_char  file_var_s4_1;           // pos: 0x15;
u_char  file_var_s4_2;           // pos: 0x1a;
u_char  file_var_s4_3;           // pos: 0x1b;
u_char  file_var_s4_4;           // pos: 0xc0;
u_char  file_var_s4_5[8];        // pos: 0xd0;

actor 監視_NPC0809(0)
{

	function init()
	{
		return;
	}

	function walk_後読み()
	{
		sysReq(1, NAC_A03_NPC08::set_後読み表示OK);
		sysReq(1, NAC_A03_NPC09::set_後読み表示OK);
		sysReqwait(NAC_A03_NPC08::set_後読み表示OK);
		sysReqwait(NAC_A03_NPC09::set_後読み表示OK);
		sysReq(1, NAC_A03_NPC08::walk_00);
		sysReq(1, NAC_A03_NPC09::walk_00);
		sysReqwait(NAC_A03_NPC08::walk_00);
		sysReqwait(NAC_A03_NPC09::walk_00);
		sysReqchg(2, NAC_A03_NPC08::talk_step01_01);
		sysReqchg(2, NAC_A03_NPC09::talk_step01_01);
		sysReq(1, NAC_A03_NPC08::walk_01);
		sysReq(1, NAC_A03_NPC09::walk_01);
		while (true)
		{
			sysReqwait(NAC_A03_NPC08::walk_01);
			sysReqwait(NAC_A03_NPC09::walk_01);
			sysReqew(1, NAC_A03_NPC09::walk_01_02);
			sysReq(1, NAC_A03_NPC09::walk_02);
			waitv(&file_var_s4_1);
			sysReqew(1, NAC_A03_NPC08::walk_01_02);
			sysReq(1, NAC_A03_NPC08::walk_02);
			sysReqwait(NAC_A03_NPC09::walk_02);
			sysReqew(1, NAC_A03_NPC09::walk_03);
			sysReqwait(NAC_A03_NPC08::walk_02);
			sysReqchg(2, NAC_A03_NPC08::talk_step01_04);
			sysReqchg(2, NAC_A03_NPC09::talk_step01_04);
			sysReqew(1, NAC_A03_NPC08::walk_03);
			sysReqew(1, NAC_A03_NPC09::walk_04);
			sysReq(1, NAC_A03_NPC08::walk_04);
			sysReq(1, NAC_A03_NPC09::walk_05);
			sysReqwait(NAC_A03_NPC08::walk_04);
			sysReqwait(NAC_A03_NPC09::walk_05);
			sysReq(1, NAC_A03_NPC08::walk_05);
			sysReq(1, NAC_A03_NPC09::walk_06);
			sysReqwait(NAC_A03_NPC08::walk_05);
			sysReqwait(NAC_A03_NPC09::walk_06);
			sysReq(1, NAC_A03_NPC08::walk_耐え開始);
			sysReq(1, NAC_A03_NPC09::walk_耐え開始);
			file_var_s4_2 = 1;
			file_var_s4_3 = 1;
			sysReqchg(2, NAC_A03_NPC08::talk_step01_04_ex);
			sysReqchg(2, NAC_A03_NPC09::talk_step01_04_ex);
			sysReqwait(NAC_A03_NPC08::walk_耐え開始);
			sysReqwait(NAC_A03_NPC09::walk_耐え開始);
			wait(150);
			file_var_s4_4 = rand_29(2);
			if (file_var_s4_4 == 0)
			{
				sysReqew(1, NAC_A03_NPC09::walk_耐え終わり);
				file_var_s4_3 = 0;
				sysReqchg(2, NAC_A03_NPC08::talk_step01_05);
				sysReqchg(2, NAC_A03_NPC09::talk_step01_03);
				sysReqew(1, NAC_A03_NPC09::walk_07);
				file_var_s4_5[7] = 0;
				sysReqchg(2, NAC_A03_NPC09::talk_step01_01);
				sysReq(1, NAC_A03_NPC09::walk_01);
				waitv(&file_var_s4_1);
				file_var_s4_2 = 0;
				sysReqew(1, NAC_A03_NPC08::walk_耐え終わり);
				sysReqew(1, NAC_A03_NPC08::walk_06);
				waitv(&file_var_s4_1);
				sysReqchg(2, NAC_A03_NPC08::talk_step01_03);
				sysReqew(1, NAC_A03_NPC08::walk_07);
				file_var_s4_5[6] = 0;
				sysReqchg(2, NAC_A03_NPC08::talk_step01_01);
				sysReq(1, NAC_A03_NPC08::walk_01);
			}
			else
			{
				sysReqew(1, NAC_A03_NPC08::walk_耐え終わり);
				waitv(&file_var_s4_1);
				file_var_s4_2 = 0;
				sysReqchg(2, NAC_A03_NPC09::talk_step01_05);
				sysReqchg(2, NAC_A03_NPC08::talk_step01_03);
				sysReqew(1, NAC_A03_NPC08::walk_07);
				file_var_s4_5[6] = 0;
				sysReqchg(2, NAC_A03_NPC08::talk_step01_01);
				sysReq(1, NAC_A03_NPC08::walk_01);
				file_var_s4_3 = 0;
				sysReqew(1, NAC_A03_NPC09::walk_耐え終わり);
				sysReqchg(2, NAC_A03_NPC09::talk_step01_03);
				sysReqew(1, NAC_A03_NPC09::walk_07);
				file_var_s4_5[7] = 0;
				sysReqchg(2, NAC_A03_NPC09::talk_step01_01);
				sysReq(1, NAC_A03_NPC09::walk_01);
			}
		}
	}
}

actor q145イベント監督(0)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function 討伐開始()
	{
		questeffectread(209);
		effectreadsync();
		effectplay(0);
		effectsync();
		g_btl_nm_ロビー = 1;
		setquestscenarioflag(145, 20);
		return;
	}

	function 報酬()
	{
		sysSysreqwait(依頼人モルガン::talk);
		partyusemapid(1);
		setposparty(267.367645, 25.0759716, 104.4991, 3.02627802);
		resetbehindcamera(3.02627802, 0);
		sysReqall(2, reqArr8);
		sysReqew(2, ジョニー::bindoff_ジョニー);
		wait(30);
		sysReqwait(PC乗っ取り::walk_q145_準備);
		sysReqwait(依頼人モルガン::walk_q145_準備);
		sysReqwait(ジョニー２号::walk_q145_準備);
		camerastart_7e(0, 0x02000000);
		sysReq(1, ロケイベント監督::re_set_ジョニー);
		sethpmenufast(0);
		settrapshowstatus(0);
		setcharseplayall(1);
		fadein(30);
		fadesync();
		sysReq(2, 依頼人モルガン::walk_q145_話す);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000021);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, 依頼人モルガン::walk_q145_話し止める);
		wait(5);
		sysReqew(2, 依頼人モルガン::walk_q145_ジョニーに気付く);
		sysReq(2, 依頼人モルガン::walk_q145_話す);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000022);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, 依頼人モルガン::walk_q145_話し止める);
		camerastart_7e(0, 0x02000001);
		sysReqall(2, reqArr9);
		sysReq(2, PC乗っ取り::walk_ジョニーを見る);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000023);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー２号::walk_喋りやめ);
		sysReq(2, 依頼人モルガン::walk_q145_話す);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000024);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, 依頼人モルガン::walk_q145_話し止める);
		wait(5);
		sysReq(2, ジョニー２号::walk_言葉に詰まる);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000025);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReq(2, ジョニー２号::walk_q145_逃げる);
		wait(40);
		sysReqew(2, ジョニー２号::walk_消す);
		camerastart_7e(0, 0x02000000);
		sysReqall(2, reqArr10);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000026);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, 依頼人モルガン::walk_q145_話し止める);
		sysReqwait(PC乗っ取り::walk_q145_元に戻す);
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		questresultwindow(145);
		setquestorder(145, 0);
		setquestclear(145, 1);
		setquestok(145, 0);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		setquestscenarioflag(145, 50);
		global_var_1 = (global_var_1 + 1);
		fadeout(15);
		fadesync();
		setcharseplayall(0);
		sethpmenufast(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		setstatuserrordispdenystatus(0);
		unkCall_5ac(0, 0, 0);
		sysReqwait(ロケイベント監督::re_set_ジョニー);
		sysReqall(2, reqArr11);
		sysReqew(1, ロケイベント監督::re_play_ジョニー);
		sysReqwait(PC乗っ取り::walk_q145_クリアイベント終了);
		sysReqwait(依頼人モルガン::walk_q145_クリアイベント終了);
		cameraclear();
		partyusemapid(1);
		setposparty(267.152069, 24.3119411, 106.348824, 3.02627802);
		resetbehindcamera(3.02627802, 0);
		sysReqchg(2, 依頼人モルガン::talk_q145_step05);
		wait(30);
		showparty();
		if (distance_290(-1, g_com_navi_footcalc[0], g_com_navi_footcalc[2]) >= 0.800000012)
		{
			clearnavimapfootmark();
		}
		setnavimapfootmarkstatus(1);
		setcharseplayall(1);
		sethpmenufast(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		wait(1);
		fadein(30);
		fadesync();
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

actor q151イベント監督(0)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function 討伐開始()
	{
		questeffectread(215);
		effectreadsync();
		effectplay(0);
		effectsync();
		g_btl_nm_ゴリアテ = 1;
		setquestscenarioflag(151, 20);
		return;
	}

	function 報酬()
	{
		sysSysreqwait(依頼人バロング::talk);
		依頼人バロング.lookatoff();
		partyusemapid(1);
		setposparty(290.023438, 24.25, 129.897995, 2.00964189);
		resetbehindcamera(2.00964189, 0);
		sysReqall(2, reqArr12);
		sysReqew(2, ジョニー::bindoff_ジョニー);
		wait(30);
		sysReqwait(PC乗っ取り::walk_q151_準備);
		sysReqwait(依頼人バロング::walk_q151_準備);
		sysReqwait(ジョニー２号::walk_q151_準備);
		camerastart_7e(0, 0x02000002);
		sysReq(1, ロケイベント監督::re_set_ジョニー);
		sethpmenufast(0);
		settrapshowstatus(0);
		setcharseplayall(1);
		fadein(30);
		fadesync();
		sysReq(2, 依頼人バロング::walk_q151_驚く);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100002d);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, 依頼人バロング::walk_q151_話し止める);
		wait(5);
		sysReqew(2, 依頼人バロング::walk_q151_ジョニーに気付く);
		sysReq(2, 依頼人バロング::walk_q151_話す);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100002e);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, 依頼人バロング::walk_q151_話し止める);
		camerastart_7e(0, 0x02000003);
		sysReqall(2, reqArr13);
		sysReq(1, PC乗っ取り::walk_ジョニーを見る);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100002f);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー２号::walk_喋りやめ);
		wait(5);
		sysReqall(2, reqArr14);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000030);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, 依頼人バロング::walk_q151_話し止める);
		wait(5);
		sysReq(2, ジョニー２号::walk_言葉に詰まる);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000031);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReq(2, ジョニー２号::walk_q151_逃げる);
		wait(40);
		sysReqew(3, ジョニー２号::walk_消す);
		camerastart_7e(0, 0x02000002);
		sysReqall(2, reqArr15);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000032);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, 依頼人バロング::walk_q151_話し止める);
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		questresultwindow(151);
		setquestorder(151, 0);
		setquestclear(151, 1);
		setquestok(151, 0);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		setstatuserrorctrldenystatus_by_menu(0);
		setquestscenarioflag(151, 50);
		global_var_1 = (global_var_1 + 1);
		fadeout(15);
		fadesync();
		setcharseplayall(0);
		sethpmenufast(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		setstatuserrordispdenystatus(0);
		unkCall_5ac(0, 0, 0);
		sysReqwait(ロケイベント監督::re_set_ジョニー);
		sysReqwait(PC乗っ取り::walk_q151_元に戻す);
		sysReqall(2, reqArr16);
		sysReqew(1, ロケイベント監督::re_play_ジョニー);
		sysReqwait(PC乗っ取り::walk_q151_クリアイベント終了);
		sysReqwait(依頼人バロング::walk_q151_クリアイベント終了);
		cameraclear();
		partyusemapid(1);
		setposparty(288.656433, 24.25, 130.541489, 2.00964189);
		resetbehindcamera(2.00964189, 0);
		sysReqchg(2, 依頼人バロング::talk_q151_step05);
		wait(30);
		showparty();
		if (distance_290(-1, g_com_navi_footcalc[0], g_com_navi_footcalc[2]) >= 0.800000012)
		{
			clearnavimapfootmark();
		}
		setnavimapfootmarkstatus(1);
		setcharseplayall(1);
		sethpmenufast(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		wait(1);
		fadein(30);
		fadesync();
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

actor ロケイベント監督(0)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function set_ジョニー()
	{
		sysReqewi(1, ジョニー::set_subev);
		sysReqewi(1, ジョニー::motion_TAG_subev);
		switch (global_var_1)
		{
			case lte(0):
				sysReqchg(2, ジョニー::talk_step01_01);
				sysReq(1, ジョニー::walk_すぐ倒れる);
				break;
			case lte(2):
				sysReqchg(2, ジョニー::talk_step01_01);
				sysReq(1, ジョニー::walk_あまり倒れない);
				break;
			case lte(3):
				sysReqchg(2, ジョニー::talk_step03);
				sysReq(1, ジョニー::walk_倒れないけどヘタリ);
				break;
			case lte(4):
				sysReqchg(2, ジョニー::talk_step04);
				sysReq(1, ジョニー::walk_普通に走る);
				break;
			case lte(5):
				motionread(4);
				motionreadsync(4);
				sysReqchg(2, ジョニー::talk_step05);
				sysReq(1, ジョニー::walk_高速で走る);
				break;
			case gte(6):
				sysReqchg(2, ジョニー::talk_step06);
				sysReq(1, ジョニー::walk_高速で走る);
				break;
			default:
				break;
		}
		return;
	}

	function re_set_ジョニー()
	{
		sysReqewi(1, ジョニー::set_subev);
		sysReqewi(1, ジョニー::motion_TAG_subev);
		return;
	}

	function re_play_ジョニー()
	{
		switch (global_var_1)
		{
			case lte(0):
				sysReqchg(2, ジョニー::talk_step01_01);
				sysReq(1, ジョニー::walk_すぐ倒れる);
				break;
			case lte(2):
				sysReqchg(2, ジョニー::talk_step01_01);
				sysReq(1, ジョニー::walk_あまり倒れない);
				break;
			case lte(3):
				sysReqchg(2, ジョニー::talk_step03);
				sysReq(1, ジョニー::walk_倒れないけどヘタリ);
				break;
			case lte(4):
				sysReqchg(2, ジョニー::talk_step04);
				sysReq(1, ジョニー::walk_普通に走る);
				break;
			case lte(5):
				motionread(4);
				motionreadsync(4);
				sysReqchg(2, ジョニー::talk_step05);
				sysReq(1, ジョニー::walk_高速で走る);
				break;
			case gte(6):
				sysReqchg(2, ジョニー::talk_step06);
				sysReq(1, ジョニー::walk_高速で走る);
				break;
			default:
				break;
		}
		if (global_var_1 >= 5)
		{
			sysReqchg(2, NAC_A03_NPC05::talk_step01_ex);
		}
		return;
	}

	function ジョニーお礼渡す()
	{
		sysSysreqwait(ジョニー::talk);
		sysReqall(2, reqArr17);
		wait(30);
		sysReqwait(PC乗っ取り::walk_jony_準備);
		sysReqwait(ジョニー::walk_jony_準備);
		camerastart_7e(0, 0x02000004);
		sethpmenufast(0);
		settrapshowstatus(0);
		setcharseplayall(1);
		fadein(60);
		wait(120);
		fadesync();
		sysReqall(2, reqArr18);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100003b);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー::walk_jony_話し止める);
		wait(5);
		sysReqall(2, reqArr19);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100003c);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー::walk_jony_話し止める);
		wait(10);
		sysReqall(2, reqArr20);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100003d);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー::walk_jony_話し止める);
		wait(5);
		sysReqall(2, reqArr21);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100003e);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー::walk_jony_話し止める);
		wait(10);
		sysReqall(2, reqArr22);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100003f);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー::walk_jony_話し止める);
		camerastart_7e(0, 0x02000005);
		wait(5);
		sysReq(2, ジョニー::walk_jony_話す);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000040);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー::walk_jony_話し止める);
		camerastart_7e(0, 0x02000006);
		sysReqall(2, reqArr23);
		wait(5);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000041);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqwait(ジョニー::walk_jony_頑張る);
		sysReqew(2, ジョニー::walk_jony_お礼渡す);
		sebsoundplay(0, 39);
		additemmes(0x906a, 1);
		sysReqall(2, reqArr24);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000042);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー::walk_jony_話し止める);
		camerastart_7e(0, 0x02000007);
		sysReqall(2, reqArr25);
		sysReqwait(ジョニー::walk_jony_走っていく);
		sysReqall(2, reqArr26);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000043);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		sysReqew(3, ジョニー::walk_jony_話し止める);
		global_var_1 = 6;
		sysReq(2, ジョニー::walk_jony_去る);
		fadeout(30);
		fadesync();
		setcharseplayall(0);
		sethpmenufast(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		setstatuserrordispdenystatus(0);
		sysReqall(3, reqArr27);
		sysReqwait(ジョニー::walk_jony_クリアイベント終了);
		sysReqwait(PC乗っ取り::walk_jony_クリアイベント終了);
		sysReqewi(1, ジョニー::set_subev);
		sysReqewi(1, ジョニー::motion_TAG_subev);
		sysReqchg(2, ジョニー::talk_step06);
		sysReq(1, ジョニー::walk_高速で走る);
		partyusemapid(1);
		setposparty(296.860748, 24.7253838, 135.884293, -0.809916019);
		resetbehindcamera(-0.809916019, 0);
		cameraclear();
		wait(30);
		showparty();
		if (distance_290(-1, g_com_navi_footcalc[0], g_com_navi_footcalc[2]) >= 0.800000012)
		{
			clearnavimapfootmark();
		}
		setnavimapfootmarkstatus(1);
		setcharseplayall(1);
		sethpmenufast(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		wait(1);
		fadein(30);
		fadesync();
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

actor ロケタイエフェクト監督(0)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function ロケタイエフェクト読込()
	{
		locationeffectread_128(31, 4);
		return;
	}

	function ロケタイエフェクト読込終了待ち()
	{
		effectreadsync_e1(31);
		return;
	}

	function ロケタイエフェクト再生()
	{
	local_jmp_0:
		if (getmovieframe() >= 120)
		{
			effectplay_e2(31, 0);
		}
		else
		{
			wait(1);
			goto local_jmp_0;
		}
		return;
	}

	function ロケタイエフェクト再生終了待ち()
	{
		effectsync_e3(31);
		return;
	}
}

actor movieSkip監督(0)
{

	function init()
	{
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	u_char  local_var_s9f1_1;        // pos: 0xc0;
	int     local_var_s9f1_2;        // pos: 0x00;
	int     local_var_s9f1_3;        // pos: 0x40;
	int     local_var_s9f1_4;        // pos: 0x80;

	function Skip監視()
	{
		file_var_s2_1 = 0;
		local_var_s9f1_1 = 0;
		local_var_s9f1_2 = 0;
	local_jmp_0:
		local_var_s9f1_3 = padt();
		local_var_s9f1_4 = getmoviestatus();
		if (local_var_s9f1_4 == 3)
		{
			if ((local_var_s9f1_3 & 8))
			{
				switch (local_var_s9f1_1)
				{
					case 0:
						if (getscreenaspect() == 0)
						{
							amest(3, 0x0100004e, 60, 0x0331, 0);
						}
						else
						{
							amest(3, 0x0100004e, 120, 0x0331, 0);
						}
						local_var_s9f1_1 = 1;
						break;
					default:
						mesclose(3);
						local_var_s9f1_1 = 0;
						break;
				}
			}
			else if (((local_var_s9f1_3 & get_pad_ok()) && local_var_s9f1_1 == 1))
			{
				sebsoundplay(0, 2);
				straightpcmtrans(29, 0);
				fadelayer(6);
				fadeout_d0(2, 15);
				fadesync_d3(2);
				effectcancelall();
				local_var_s9f1_4 = getmoviestatus();
				if (local_var_s9f1_4 == 3)
				{
					moviecancel();
				}
				movieend();
				fadeout_d0(0, 0);
				fadein_d2(2, 0);
				local_var_s9f1_2 = 1;
				file_var_s2_1 = 1;
				wait(1);
				mesclose(0);
				mesclose(1);
				mesclose(2);
				mesclose(3);
				mesclose(4);
				mesclose(5);
				mesclose(6);
				mesclose(7);
				goto local_jmp_15;
			}
		}
		else
		{
			goto local_jmp_15;
		}
		if (local_var_s9f1_2 != 1)
		{
			wait(1);
			goto local_jmp_0;
		}
	local_jmp_15:
		mesclose(3);
		return;
	}
}

actor Map_Director(0)
{

	function init()
	{
		setmapjumpgroupflag(81);
		switch (lastmap())
		{
			case 0x0320:
				bganimeplay_9e(10, 60, 60);
				resetbehindcamera((getmapjumpanglebyindex(nowjumpindex()) + 3.14159274), 0);
				break;
		}
		return;
	}

	function main(1)
	{
		if (シナリオフラグ >= 0x015e)
		{
			if (!(ismapjumpgroupflag(0x0145)))
			{
				setmapjumpgroupflag(0x0145);
			}
		}
		else if (ismapjumpgroupflag(0x0145))
		{
			releasemapjumpgroupflag(0x0145);
		}
		return;
	}
}

actor 扉(0)
{

	function init()
	{
		return;
	}

	function 開く()
	{
		bganimeplay_9e(10, 0, 50);
		wait(15);
		mp_map_flg = mapsoundplay(3);
		wait(5);
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
			mapjump(0x0320, 1, 0);
		}
		return;
	}

	function 閉じる()
	{
		bganimeplay_9e(10, 60, 100);
		wait(15);
		mapsoundplay(4);
		bganimesync(10);
		return;
	}
}

actor フェード(0)
{

	function init()
	{
		return;
	}

	function フェードまち()
	{
		fadesync_d3(2);
		return;
	}
}

actor Alchemist_Utility(0)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function Notify()
	{
		musictrans(-1, 30, 32);
		setstatuserrorctrldenystatus_by_menu(1);
		seteventtimestop(1);
		moveblurcaptureonce();
		movebluraplpha(1);
		moveblurfade(15);
		moveblurfadesync();
		sebsoundplay(0, 40);
		wait(6);
		mes(0, 0x01000000 | 181, 0x03c0, 0x021c, 0, 0, 4, 1);
		messync(0, 1);
		wait(6);
		musictrans(-1, 30, 127);
		moveblurclearfade(15);
		moveblurfadesync();
		seteventtimestop(0);
		return;
	}
}

actor 武器屋の看板(1)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		setrect_25(279.60672, 26.2999687, 135.233444, 1, 1, 0);
		setwh(2, 2, 1, 1);
		reqenable(2);
		recttocircle();
		reqdisable(3);
		reqenable(8);
		reqenable(13);
		fieldsignicon(3);
		fieldsignmes(0x0100004a);
		showfieldsign();
		settouchuconly(1);
		talkang(1.57079637);
		return;
	}

	function talk(2)
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setmeswincaptionid(0, 3);
		amese(0, 0x0100004b);
		messync(0, 1);
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function fieldsign1(8)
	{
		return;
	}

	function fieldsign2(13)
	{
		return;
	}

	function rect_off()
	{
		rectdisable();
		return;
	}

	function rect_on()
	{
		rectenable();
		return;
	}
}

actor 防具屋の看板(1)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		setrect_25(297.378723, 25.9530869, 145.720779, 1, 1, 0);
		setwh(2, 2, 1, 1);
		reqenable(2);
		recttocircle();
		reqdisable(3);
		reqenable(8);
		reqenable(13);
		fieldsignicon(3);
		fieldsignmes(0x0100004c);
		showfieldsign();
		settouchuconly(1);
		talkang(1.57079637);
		return;
	}

	function talk(2)
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setmeswincaptionid(0, 3);
		amese(0, 0x0100004d);
		messync(0, 1);
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function fieldsign1(8)
	{
		return;
	}

	function fieldsign2(13)
	{
		return;
	}

	function rect_off()
	{
		rectdisable();
		return;
	}

	function rect_on()
	{
		rectenable();
		return;
	}
}

actor PC00(5) : 0x80
{

	function init()
	{
		setupbattle(0);
		return;
	}
}

actor PC01(5) : 0x81
{

	function init()
	{
		setupbattle(1);
		return;
	}
}

actor PC02(5) : 0x82
{

	function init()
	{
		setupbattle(2);
		return;
	}
}

actor PC03(5) : 0x83
{

	function init()
	{
		setupbattle(3);
		return;
	}
}

actor マップ帝国君移植版(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step00()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000001);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	u_char  local_var_s19f4_1;       // pos: 0x00;

	function talk_step01()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		askpos(0, 0, 127);
		local_var_s19f4_1 = aaske(0, 0x01000002);
		mesclose(0);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		switch (local_var_s19f4_1)
		{
			case 0:
				setkutipakustatus(1);
				setunazukistatus(1);
				amese(0, 0x01000003);
				messync(0, 1);
				setkutipakustatus(0);
				setunazukistatus(0);
				sysReqew(1, 扉::開く);
				break;
			case 1:
				setkutipakustatus(1);
				setunazukistatus(1);
				amese(0, 0x01000004);
				messync(0, 1);
				setkutipakustatus(0);
				setunazukistatus(0);
				break;
			default:
				break;
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

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			setaturnlookatlockstatus(1);
			aturn_261(getdestrotangzx_227(0));
		}
		return;
	}

	function set_通行解除()
	{
		setpos(307.173828, 29, 125.979683);
		dir(-1.02696502);
		bindp2_d4(0x03000000, 1, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setnpcname(0x02af);
		return;
	}

	function motion_TAG()
	{
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}
}

actor マップ帝国君用アタリ(6)
{

	function init()
	{
		return;
	}

	function setHitObj()
	{
		usemapid(0);
		setpos(308.328674, 29, 126.070335);
		dir(0.601315022);
		bindhitobj();
		set_ignore_hitgroup(1);
		setradius_221(1, 1);
		setheight(0.800000012);
		setweight(-1);
		return;
	}

	function setHitObj_omoi()
	{
		usemapid(0);
		setpos(308.328674, 29, 126.070335);
		dir(0.601315022);
		bindhitobj();
		set_ignore_hitgroup(1);
		setradius_221(1, 1);
		setheight(0.800000012);
		setweight(-1);
		weight_upper_pc();
		return;
	}

	function clearHitObj()
	{
		bindoff();
		return;
	}
}

actor NAC_A03_NPC01(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000005);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		openfullscreenmenu_48d(2, 4);
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
		if (g_com_counter_for_horidasi[3] >= 255)
		{
			g_com_counter_for_horidasi[3] = 255;
		}
		else
		{
			g_com_counter_for_horidasi[3] = (g_com_counter_for_horidasi[3] + 1);
		}
		if ((g_com_counter_for_horidasi[3] >= 15 && !((g_com_check_for_horidasi[0] & 8))))
		{
			sethoridashi(0xd07e);
			g_com_check_for_horidasi[0] = (g_com_check_for_horidasi[0] | 8);
		}
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function set()
	{
		setpos(296.213837, 24.25, 144.64682);
		dir(-0.991225004);
		bindp2_d4(0x03000003, 2, 2);
		setweight(-1);
		set_ignore_hitgroup(1);
		setshopname(4);
		setoverheadicontype(1);
		return;
	}

	function motion_TAG()
	{
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function walk()
	{
		motionloop(1);
		motionplay(0x11000001);
		return;
	}
}

actor NAC_A03_NPC02(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000006);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		openfullscreenmenu_48d(2, 3);
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
		if (g_com_counter_for_horidasi[1] >= 255)
		{
			g_com_counter_for_horidasi[1] = 255;
		}
		else
		{
			g_com_counter_for_horidasi[1] = (g_com_counter_for_horidasi[1] + 1);
		}
		if ((g_com_counter_for_horidasi[1] >= 30 && !((g_com_check_for_horidasi[0] & 2))))
		{
			sethoridashi(0xd064);
			g_com_check_for_horidasi[0] = (g_com_check_for_horidasi[0] | 2);
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

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			setaturnlookatlockstatus(1);
			aturn_261(getdestrotangzx_227(0));
		}
		return;
	}

	function set()
	{
		usemapid(0);
		setpos(277.521942, 24.2500038, 135.063828);
		dir(2.31438398);
		bindp2_d4(0x03000003, 1, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setshopname(3);
		setoverheadicontype(1);
		settalkradiusoffset(2.1468811, 0, -1.87242198);
		talkradius(0.200000003);
		wait(1);
		fetchambient_4e1(280.153412, 24.25, 133.651474);
		return;
	}

	function motion_TAG()
	{
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function walk()
	{
		while (true)
		{
			sysLookata(NAC_A03_NPC13);
			setkutipakustatus(1);
			setunazukistatus(1);
			wait((90 + rand_29(60)));
			setkutipakustatus(0);
			setunazukistatus(0);
			wait((60 + rand_29(60)));
		}
	}
}

actor NAC_A03_NPC03(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step_btl()
	{
		setkubifuristatus(0);
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000007);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step_btl_after()
	{
		setkubifuristatus(0);
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000008);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			setaturnlookatlockstatus(1);
			aturn_261(getdestrotangzx_227(0));
		}
		setkubifuristatus(1);
		return;
	}

	function set()
	{
		setpos(274.931244, 23.7658558, 168.288925);
		dir(2.04770994);
		bindp2_d4(0x03000000, 1, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setnpcname(0x02af);
		return;
	}

	function motion_TAG()
	{
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function walk()
	{
		setkubifuristatus(1);
		while (true)
		{
			aturny(276.479431, 163.246338);
			lookatoff();
			move(276.479431, 23.7658558, 163.246338);
			aturny(286.031189, 163.0168);
			lookatoff();
			move(286.031189, 23.7658558, 163.0168);
			aturny(274.931244, 168.288925);
			lookatoff();
			move(274.931244, 23.7658558, 168.288925);
		}
	}
}

actor NAC_A03_NPC04(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
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
		stdmotionplay(0x01000012);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000009);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step02()
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
		stdmotionplay(0x01000012);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100000a);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step03()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100000b);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			setaturnlookatlockstatus(1);
			aturn_261(getdestrotangzx_227(0));
		}
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(292.205902, 23.7658558, 163.129044);
		dir(0.0444630012);
		bindp2_d4(0x03000000, 1, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setnpcname(0x02af);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_後読み()
	{
		while (true)
		{
			wait((30 + rand_29(40)));
			stdmotionplay(0x01000016);
			motionsync_282(1);
			stdmotionplay(0x01000011);
			motionsync_282(1);
		}
	}
}

actor NAC_A03_NPC05(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100000c);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_step01_ex()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100000d);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(306.573181, 25.2749844, 166.410812);
		dir(-2.52648497);
		bindp2_d4(0x03000001, 3, 1);
		setweight(-1);
		set_ignore_hitgroup(1);
		setnpcname(0x02a2);
		setautorelax(0);
		settalkradiusoffset(-0.330260992, -1.024984, -0.410385013);
		talkradius(0.600000024);
		hideshadow();
		wait(1);
		fetchambient_4e1(306.397766, 24.25, 165.195312);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		motionloop(1);
		motionplay(0x12000007);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor NAC_A03_NPC06(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100000e);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step02()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100000f);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step03()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000010);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			setaturnlookatlockstatus(1);
			aturn_261(getdestrotangzx_227(0));
		}
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		setpos(257.221619, 24.2500038, 132.112518);
		dir(1.81210995);
		bindp2_d4(0x03000003, 3, 2);
		setweight(-1);
		set_ignore_hitgroup(1);
		setnpcname(0x02a4);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_後読み()
	{
		while (true)
		{
			wait(rand_29(150));
			aturny(255.664337, 129.545776);
			lookatoff();
			move(255.664337, 24.25, 129.545776);
			turn_62(1.86119699);
			wait(rand_29(150));
			aturny(257.221619, 132.112518);
			lookatoff();
			move(257.221619, 24.2500038, 132.112518);
			turn_62(1.81210995);
		}
	}
}

actor NAC_A03_NPC07(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000011);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_step02()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000012);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_step03()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000013);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		setpos(264.610992, 24.2559643, 137.566803);
		dir(2.78569293);
		bindp2_d4(0x03000000, 1, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setnpcname(0x02b0);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor NAC_A03_NPC07用アタリ(6)
{

	function init()
	{
		return;
	}

	function setHitObj()
	{
		usemapid(0);
		setpos(263.672241, 24.2559643, 138.134079);
		dir(0);
		bindhitobj();
		set_ignore_hitgroup(1);
		setradius_221(1, 1);
		setheight(0.800000012);
		setweight(-1);
		return;
	}

	function setHitObj_omoi()
	{
		usemapid(0);
		setpos(263.672241, 24.2559643, 138.134079);
		dir(0);
		bindhitobj();
		set_ignore_hitgroup(1);
		setradius_221(1, 1);
		setheight(0.800000012);
		setweight(-1);
		weight_upper_pc();
		return;
	}

	function clearHitObj()
	{
		bindoff();
		return;
	}
}

actor NAC_A03_NPC08(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01_01()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		switch (シナリオフラグ)
		{
			case lte(0x05f0):
				setkutipakustatus(1);
				setunazukistatus(1);
				amese(0, 0x01000014);
				messync(0, 1);
				setkutipakustatus(0);
				setunazukistatus(0);
				break;
			case lte(0x1004):
				setkutipakustatus(1);
				setunazukistatus(1);
				amese(0, 0x01000015);
				messync(0, 1);
				setkutipakustatus(0);
				setunazukistatus(0);
				break;
			case lte(0x2af8):
				setkutipakustatus(1);
				setunazukistatus(1);
				amese(0, 0x01000016);
				messync(0, 1);
				setkutipakustatus(0);
				setunazukistatus(0);
				break;
			default:
				break;
		}
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_step01_03()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000017);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step01_04()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000018);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step01_04_ex()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000018);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_step01_05()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000019);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
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
			setaturnlookatlockstatus(1);
			aturn_261(getdestrotangzx_227(0));
		}
		if (file_var_s4_2 == 1)
		{
			motionloopframe(200, 0x0104);
			motionloop(1);
			motionplay_bb(0x12000009, 20);
		}
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		setpos(268.915924, 24.2560997, 140.013214);
		dir(2.159832);
		bindp2_d4(0x03000003, 4, 1);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		setnpcname(0x042d);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function set_後読み表示OK()
	{
		motionstartframe(120);
		motionplay(0x12000002);
		wait(1);
		motioncancel();
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_00()
	{
		motionstartframe(120);
		return;
	}

	function walk_01()
	{
		reqdisable(17);
		reqdisable(16);
		motionloopframe(120, 160);
		motionloop(1);
		motionplay(0x12000002);
		wait((150 + rand_29(50)));
		return;
	}

	function walk_01_02()
	{
		motiontrigger();
		motionsync();
		motionstartframe(161);
		motionplay(0x12000002);
		motionsync_282(1);
		return;
	}

	function walk_02()
	{
		stdmotionplay_2c2(0x01000000, 20);
		reqenable(17);
		reqenable(16);
		move(264.056122, 24.25, 125.243134);
		return;
	}

	function walk_03()
	{
		sysLookata(NAC_A03_NPC09);
		wait(30);
		lookatoff();
		return;
	}

	function walk_04()
	{
		move(260.378296, 24.2499962, 113.829056);
		sysLookata(NAC_A03_NPC09);
		return;
	}

	function walk_05()
	{
		lookatoff();
		sysTurna(NAC_A03_NPC09);
		return;
	}

	function walk_06()
	{
		motionplay_bb(0x12000005, 20);
		motionsync_282(1);
		stdmotionplay_2c2(0x01000000, 20);
		return;
	}

	function walk_07()
	{
		stdmotionplay_2c2(0x01000000, 20);
		reqdisable(16);
		move_5e(268.915924, 24.2560997, 140.013214, getdefaultrunspeed());
		turn_62(2.44208002);
		return;
	}

	function walk_耐え開始()
	{
		motionloopframe(200, 0x0104);
		motionloop(1);
		motionplay_bb(0x12000009, 20);
		return;
	}

	function walk_耐え終わり()
	{
		motiontrigger();
		motionsync_282(1);
		return;
	}
}

actor NAC_A03_NPC09(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01_01()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		switch (シナリオフラグ)
		{
			case lte(0x05f0):
				setkutipakustatus(1);
				setunazukistatus(1);
				amese(0, 0x0100001a);
				messync(0, 1);
				setkutipakustatus(0);
				setunazukistatus(0);
				break;
			case lte(0x1004):
				setkutipakustatus(1);
				setunazukistatus(1);
				amese(0, 0x0100001b);
				messync(0, 1);
				setkutipakustatus(0);
				setunazukistatus(0);
				break;
			case lte(0x2af8):
				setkutipakustatus(1);
				setunazukistatus(1);
				amese(0, 0x0100001c);
				messync(0, 1);
				setkutipakustatus(0);
				setunazukistatus(0);
				break;
			default:
				break;
		}
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_step01_03()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100001d);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step01_04()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100001e);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step01_04_ex()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100001e);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_step01_05()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100001f);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
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
			setaturnlookatlockstatus(1);
			aturn_261(getdestrotangzx_227(0));
		}
		if (file_var_s4_3 == 1)
		{
			motionloopframe(125, 211);
			motionloop(1);
			motionplay_bb(0x1200000a, 20);
		}
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		setpos(270.836243, 24.25, 127.700546);
		dir(-2.98204088);
		bindp2_d4(0x03000004, 2, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		setnpcname(0x042d);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function set_後読み表示OK()
	{
		motionstartframe(149);
		motionplay(0x12000000);
		wait(1);
		motioncancel();
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_00()
	{
		motionstartframe(149);
		return;
	}

	function walk_01()
	{
		reqdisable(17);
		reqdisable(16);
		motionloopframe(149, 210);
		motionloop(1);
		motionplay(0x12000000);
		wait((0x012c + rand_29(60)));
		return;
	}

	function walk_01_02()
	{
		motiontrigger();
		motionsync();
		motionstartframe(211);
		motionplay(0x12000000);
		motionsync_282(1);
		return;
	}

	function walk_02()
	{
		stdmotionplay_2c2(0x01000000, 20);
		reqenable(17);
		reqenable(16);
		move(265.71994, 24.25, 122.613518);
		motionplay_bb(0x12000006, 20);
		motionsync_282(1);
		stdmotionplay_2c2(0x01000000, 20);
		return;
	}

	function walk_03()
	{
		sysLookata(NAC_A03_NPC08);
		return;
	}

	function walk_04()
	{
		lookatoff();
		return;
	}

	function walk_05()
	{
		stdmotionplay_2c2(0x01000000, 20);
		move(261.504456, 24.2499981, 113.09668);
		sysLookata(NAC_A03_NPC08);
		return;
	}

	function walk_06()
	{
		lookatoff();
		sysTurna(NAC_A03_NPC08);
		return;
	}

	function walk_07()
	{
		stdmotionplay_2c2(0x01000000, 20);
		reqdisable(16);
		move_5e(265.660858, 24.2499962, 121.518692, getdefaultrunspeed());
		move_5e(270.836243, 24.25, 127.700546, getdefaultrunspeed());
		turn_62(-2.98204088);
		return;
	}

	function walk_08()
	{
		stdmotionplay_2c2(0x01000000, 20);
		reqdisable(16);
		move(265.660858, 24.2499962, 121.518692);
		move(270.836243, 24.25, 127.700546);
		turn_62(-2.98204088);
		return;
	}

	function walk_耐え開始()
	{
		motionloopframe(125, 211);
		motionloop(1);
		motionplay_bb(0x1200000a, 20);
		return;
	}

	function walk_耐え終わり()
	{
		motiontrigger();
		motionsync_282(1);
		return;
	}
}

actor NAC_A03_NPC10(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(292.234161, 23.7658558, 164.274521);
		dir(-3.14033198);
		bindp2_d4(0x03000001, 2, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		reqdisable(2);
		wait(1);
		fetchambient_4e1(291.243378, 23.7658558, 163.900879);
		stdmotionread(21);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_後読み()
	{
		while (true)
		{
			wait(rand_29(150));
			stdmotionplay(0x01000012);
			motionsync();
			stdmotionplay(0x01000011);
			setkutipakustatus(1);
			setunazukistatus(1);
			motionsync();
			setkutipakustatus(0);
			setunazukistatus(0);
			stdmotionplay(0x01000000);
		}
	}
}

actor NAC_A03_NPC11(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(300.33316, 24.0350151, 162.800323);
		dir(-2.40376997);
		bindp2_d4(0x03000001, 4, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		reqdisable(2);
		motionloop(1);
		motionplay(0x12000003);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor NAC_A03_NPC11用アタリ(6)
{

	function init()
	{
		return;
	}

	function setHitObj()
	{
		usemapid(0);
		setpos(299.6922, 24.0350151, 164.090668);
		dir(0.196346);
		bindhitobj();
		set_ignore_hitgroup(1);
		setradius_221(2, 2);
		setheight(0.800000012);
		setweight(-1);
		return;
	}

	function setHitObj_omoi()
	{
		usemapid(0);
		setpos(299.6922, 24.0350151, 164.090668);
		dir(0.196346);
		bindhitobj();
		set_ignore_hitgroup(1);
		setradius_221(2, 2);
		setheight(0.800000012);
		setweight(-1);
		weight_upper_pc();
		return;
	}

	function clearHitObj()
	{
		bindoff();
		return;
	}
}

actor NAC_A03_NPC12(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(297.22525, 24.0031166, 154.341858);
		dir(1.39892602);
		bindp2_d4(0x03000004, 2, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		reqdisable(2);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_後読み()
	{
		setkubifuristatus(1);
		return;
	}
}

actor NAC_A03_NPC13(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		setpos(278.967041, 24.25, 131.868958);
		dir(-0.466352999);
		bindp2_d4(0x03000000, 1, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		reqdisable(2);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		motionloop(1);
		motionplay_bb(0x12000008, 20);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor NAC_A03_NPC14(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		setpos(263.264954, 24.2567654, 137.181702);
		dir(-2.45438409);
		bindp2_d4(0x03000001, 5, 2);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		reqdisable(2);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		motionstartframe(150);
		motionloopframe(150, 210);
		motionloop(1);
		motionplay(0x12000001);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor NAC_A03_NPC15(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(271.466614, 24.2565403, 143.436569);
		dir(1.76712799);
		bindp2_d4(0x03000004, 2, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		reqdisable(2);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		motionloop(1);
		motionplay(0x12000004);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor NAC_A03_NPC16(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(284.658722, 23.7658558, 168.292648);
		dir(3.10475707);
		bindp2_d4(0x03000002, 3, 3);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		reqdisable(2);
		wait(1);
		fetchambient_4e1(286.402496, 23.7658558, 166.58075);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		motionloop(1);
		motionplay(0x1200000b);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor NAC_A03_NPC17(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(270.772095, 24.25, 121.541359);
		dir(-0.674957991);
		bindp2_d4(0x03000002, 1, 2);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		reqdisable(2);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		motionstartframe(118);
		motionloopframe(118, 171);
		motionloop(1);
		motionplay(0x11000005);
		sysRlookata(-1);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor サボテン１(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01()
	{
		return;
	}

	function set_後読み()
	{
		hidecomplete();
		usemapid(0);
		setpos(268.565002, 25.0749874, 119.99556);
		dir(-1.01854897);
		bindp2_d4(0x03000007, 1, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		reqdisable(2);
		stdmotionread(1);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		motionstartframe(59);
		stdmotionplay(0x0100000a);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}
}

actor NAC_A03_BG_NPC01(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function set_後読み_遠景()
	{
		hidecomplete();
		usemapid(0);
		setpos(315.774078, 24.25, 169.47496);
		dir(1.74409795);
		bindp2_d4(0x03000003, 1, 1);
		setweight(-1);
		set_ignore_hitgroup(1);
		reqdisable(2);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_後読み_遠景()
	{
		while (true)
		{
			wait((60 + rand_29(40)));
			stdmotionplay(0x01000012);
			motionsync_282(1);
		}
	}
}

actor NAC_A03_BG_NPC02(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function set_後読み_遠景()
	{
		hidecomplete();
		usemapid(0);
		setpos(300.871552, 24.25, 174.513504);
		dir(2.08772993);
		bindp2_d4(0x03000002, 4, 1);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(1);
		reqdisable(2);
		bindc(1, 0x03000005, 2);
		motionloop(1);
		motionplay(0x1200000c);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_後読み_遠景()
	{
		while (true)
		{
			wait(rand_29(60));
			move(319.67569, 24.25, 172.025116);
			move(345.916779, 24.25, 164.002899);
			wait(rand_29(150));
			move(319.67569, 24.25, 172.025116);
			move(300.871552, 24.25, 174.513504);
		}
	}
}

actor NAC_A03_BG_NPC04(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function set_後読み_遠景()
	{
		hidecomplete();
		usemapid(0);
		setpos(263.716003, 25.25, 88.0195999);
		dir(0.498782009);
		bindp2_d4(0x03000004, 1, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		reqdisable(2);
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function bindoff_TAG()
	{
		bindoff();
		return;
	}
}

actor NAC_A03_BG_NPC05(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function set_後読み_遠景()
	{
		hidecomplete();
		usemapid(0);
		setpos(246.138824, 25.25, 87.3058701);
		dir(-0.102525003);
		bindp2_d4(0x03000002, 2, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		reqdisable(2);
		bindc(1, 0x03000005, 2);
		motionloop(1);
		motionplay(0x1200000c);
		rgbatrans(1, 1, 1, 0, 0);
		istouchucsync();
		clearhidecomplete();
		rgbatrans(1, 1, 1, 1, 10);
		return;
	}

	function walk_後読み_遠景()
	{
		while (true)
		{
			wait(rand_29(150));
			move(243.350983, 25.25, 87.833519);
			move(252.604874, 25.25, 101.007362);
			move(259.488342, 25.25, 99.1495285);
			move(263.191711, 25.25, 94.8482285);
			move(259.496246, 25.25, 78.4644775);
			move(252.336731, 25.25, 78.1823959);
			setpos(246.138824, 25.25, 87.3058701);
		}
	}
}

actor 依頼人モルガン(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	u_char  local_var_s45f3_1;       // pos: 0x00;

	function talk_q145_step01()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		askpos(0, 0, 127);
		local_var_s45f3_1 = aaske(0, 0x01000027);
		mesclose(0);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		if (local_var_s45f3_1 == 0)
		{
			setkutipakustatus(1);
			setunazukistatus(1);
			amese(0, 0x01000028);
			messync(0, 1);
			setkutipakustatus(0);
			setunazukistatus(0);
			sysReqew(1, q145イベント監督::討伐開始);
			sysReqchg(2, 依頼人モルガン::talk_q145_step03);
		}
		else
		{
			setkutipakustatus(1);
			setunazukistatus(1);
			amese(0, 0x01000029);
			messync(0, 1);
			setkutipakustatus(0);
			setunazukistatus(0);
			sysReqchg(2, 依頼人モルガン::talk_q145_step02);
			setquestscenarioflag(145, 15);
		}
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_q145_step02()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		askpos(0, 0, 127);
		local_var_s45f3_1 = aaske(0, 0x0100002a);
		mesclose(0);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		if (local_var_s45f3_1 == 0)
		{
			setkutipakustatus(1);
			setunazukistatus(1);
			amese(0, 0x01000028);
			messync(0, 1);
			setkutipakustatus(0);
			setunazukistatus(0);
			sysReqew(1, q145イベント監督::討伐開始);
			sysReqchg(2, 依頼人モルガン::talk_q145_step03);
		}
		else
		{
			setkutipakustatus(1);
			setunazukistatus(1);
			amese(0, 0x01000029);
			messync(0, 1);
			setkutipakustatus(0);
			setunazukistatus(0);
		}
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_q145_step03()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100002b);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_q145_step04()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		fadeout(30);
		fadesync();
		g_com_navi_footcalc[0] = getx_12b(-1);
		g_com_navi_footcalc[1] = gety_12c(-1);
		g_com_navi_footcalc[2] = getz_12d(-1);
		setnavimapfootmarkstatus(0);
		sethpmenufast(0);
		settrapshowstatus(0);
		setcharseplayall(0);
		if (!(istownmap()))
		{
			setstatuserrordispdenystatus(1);
		}
		sysReq(1, q145イベント監督::報酬);
		return;
	}

	function talk_q145_step05()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100002c);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function set_q145()
	{
		usemapid(0);
		setpos(267.614716, 26.3523598, 101.876045);
		dir(0.601333976);
		bindp2_d4(0x03000006, 2, 0);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		setnpcname(0x02b3);
		settalkradiusoffset(0.154692993, -1.33818603, 2.26695299);
		talkradius(0.200000003);
		return;
	}

	function motion_TAG_q145()
	{
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function walk_q145()
	{
		stdmotionread(18);
		stdmotionreadsync();
		stdmotionplay_2c2(0x01000000, 0);
		return;
	}

	function walk_q145_準備()
	{
		sysLookata(-1);
		return;
	}

	function walk_q145_話す()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		return;
	}

	function walk_q145_話し止める()
	{
		setkutipakustatus(0);
		setunazukistatus(0);
		return 0;
	}

	function walk_q145_ジョニーに気付く()
	{
		sysLookata(ジョニー２号);
		return;
	}

	function walk_q145_元に戻す()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		sysLookata(-1);
		return;
	}

	function walk_q145_クリアイベント終了()
	{
		lookatoff();
		return;
	}
}

actor 依頼人バロング(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	//======================================================================
	//                   Local (script) scope variables                   //
	//======================================================================
	u_char  local_var_s46f3_1;       // pos: 0x00;

	function talk_q151_step01()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000033);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		motionstartframe(170);
		motionplay_bb(0x11000005, 15);
		motionratio(1.20000005);
		motionsync();
		stdmotionplay_2c2(0x01000000, 15);
		motionratio(1);
		sysAturna(-1);
		motionplay_bb(0x13000001, 15);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000034);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		stdmotionplay_2c2(0x01000000, 15);
		move(291.292786, 25.2499847, 129.3022);
		settalkradiusoffset(-0.838775992, -0.99998498, 0.716629028);
		motionloopframe(118, 171);
		motionloop(1);
		motionplay_bb(0x11000005, 15);
		setkutipakustatus(1);
		setunazukistatus(1);
		askpos(0, 0, 127);
		local_var_s46f3_1 = aaske(0, 0x01000035);
		mesclose(0);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		if (local_var_s46f3_1 == 0)
		{
			setkutipakustatus(1);
			setunazukistatus(1);
			amese(0, 0x01000036);
			messync(0, 1);
			setkutipakustatus(0);
			setunazukistatus(0);
			sysReqew(1, q151イベント監督::討伐開始);
			sysReqchg(2, 依頼人バロング::talk_q151_step03);
		}
		else
		{
			setkutipakustatus(1);
			setunazukistatus(1);
			amese(0, 0x01000037);
			messync(0, 1);
			setkutipakustatus(0);
			setunazukistatus(0);
			sysReqchg(2, 依頼人バロング::talk_q151_step02);
			setquestscenarioflag(151, 15);
		}
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_q151_step02()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		askpos(0, 0, 127);
		local_var_s46f3_1 = aaske(0, 0x01000038);
		mesclose(0);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		if (local_var_s46f3_1 == 0)
		{
			setkutipakustatus(1);
			setunazukistatus(1);
			amese(0, 0x01000036);
			messync(0, 1);
			setkutipakustatus(0);
			setunazukistatus(0);
			sysReqew(1, q151イベント監督::討伐開始);
			sysReqchg(2, 依頼人バロング::talk_q151_step03);
		}
		else
		{
			setkutipakustatus(1);
			setunazukistatus(1);
			amese(0, 0x01000037);
			messync(0, 1);
			setkutipakustatus(0);
			setunazukistatus(0);
		}
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_q151_step03()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysLookata(-1);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000039);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		lookatoff();
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_q151_step04()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		sysRlookata(-1);
		fadeout(30);
		fadesync();
		g_com_navi_footcalc[0] = getx_12b(-1);
		g_com_navi_footcalc[1] = gety_12c(-1);
		g_com_navi_footcalc[2] = getz_12d(-1);
		setnavimapfootmarkstatus(0);
		sethpmenufast(0);
		settrapshowstatus(0);
		setcharseplayall(0);
		if (!(istownmap()))
		{
			setstatuserrordispdenystatus(1);
		}
		sysReq(1, q151イベント監督::報酬);
		return;
	}

	function talk_q151_step05()
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
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x0100003a);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		aturn_261(getdestrotangzx_227(0));
		return;
	}

	function set_q151()
	{
		usemapid(0);
		usecharhit(0);
		setpos(295.270996, 25.2499847, 125.223259);
		dir(2.40528202);
		bindp2_d4(0x03000002, 2, 1);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		setnpcname(0x02b2);
		settalkradiusoffset(-4.77807617, -0.99998498, 4.33162689);
		talkradius(0.200000003);
		return;
	}

	function set_q151_02()
	{
		usemapid(0);
		setpos(291.292786, 25.2499847, 129.3022);
		dir(-0.859026015);
		bindp2_d4(0x03000002, 2, 1);
		setweight(-1);
		set_ignore_hitgroup(1);
		setautorelax(0);
		setnpcname(0x02b2);
		settalkradiusoffset(-0.838775992, -0.99998498, 0.216628999);
		talkradius(0.200000003);
		return;
	}

	function motion_TAG_q151()
	{
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function walk_q151()
	{
		motionlooppreset(1);
		motionloop(1);
		motionplay(0x11000005);
		return;
	}

	function walk_q151_準備()
	{
		sysLookata(-1);
		setautorelax(1);
		stdmotionplay(0x01000000);
		return;
	}

	function walk_q151_話す_モーションつき()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		stdmotionplay_2c2(0x01000002, 15);
		return;
	}

	function walk_q151_話す()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		return;
	}

	function walk_q151_話し止める()
	{
		setkutipakustatus(0);
		setunazukistatus(0);
		return 0;
	}

	function walk_q151_驚く()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		motionplay_bb(0x13000002, 15);
		return;
	}

	function walk_q151_ジョニーに気付く()
	{
		sysLookata(ジョニー２号);
		return;
	}

	function walk_q151_嫌な顔すんな()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		stdmotionplay_2c2(0x01000016, 15);
		return;
	}

	function walk_q151_元に戻す()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		stdmotionplay_2c2(0x01000002, 15);
		sysLookata(-1);
		return;
	}

	function walk_q151_クリアイベント終了()
	{
		lookatoff();
		return;
	}
}

actor ジョニー２号(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function set_subev()
	{
		setpos(264.898895, 24.2499981, 116.185089);
		dir(0);
		bindp2_d4(0x03000003, 4, 3);
		setweight(-1);
		set_ignore_hitgroup(1);
		setnpcname(0x02a1);
		hide();
		hideshadow();
		return;
	}

	function motion_TAG_subev()
	{
		stdmotionread(21);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function walk_q145_準備()
	{
		setpos(265.188782, 24.2500019, 109.928879);
		dir(2.72437096);
		return;
	}

	function walk_q151_準備()
	{
		setpos(286.898163, 24.25, 131.839447);
		dir(2.26807189);
		return;
	}

	function walk_q145_ジョニー来る()
	{
		show();
		showshadow();
		setkutipakustatus(1);
		setunazukistatus(1);
		rmove(266.332794, 24.250349, 107.267662);
		sysLookata(依頼人モルガン);
		return;
	}

	function walk_q151_ジョニー来る()
	{
		show();
		showshadow();
		setkutipakustatus(1);
		setunazukistatus(1);
		rmove(288.186401, 24.25, 130.818405);
		sysLookata(依頼人バロング);
		return;
	}

	function walk_q145_逃げる()
	{
		lookatoff();
		rmove_43(260.406982, 24.2552299, 110.365494, getdefaultrunspeed());
		return;
	}

	function walk_q151_逃げる()
	{
		lookatoff();
		rmove_43(285.965118, 24.2500019, 136.437332, getdefaultrunspeed());
		return;
	}

	function walk_喋りやめ()
	{
		setkutipakustatus(0);
		setunazukistatus(0);
		return;
	}

	function walk_言葉に詰まる()
	{
		lookatr_4bf(0, -1.39626348, 10);
		return;
	}

	function walk_消す()
	{
		movecancel();
		hide();
		hideshadow();
		return 0;
		return;
	}
}

actor PC乗っ取り(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function walk_ジョニーを見る()
	{
		sysAturna(ジョニー２号);
		return;
	}

	function walk_q145_準備()
	{
		capturepc(-1);
		sysLookata(依頼人モルガン);
		return;
	}

	function walk_q151_準備()
	{
		capturepc(-1);
		sysLookata(依頼人バロング);
		return;
	}

	function walk_q145_元に戻す()
	{
		sysAturna(依頼人モルガン);
		return;
	}

	function walk_q151_元に戻す()
	{
		sysAturna(依頼人バロング);
		return;
	}

	function walk_q145_クリアイベント終了()
	{
		lookatoff();
		releasepc();
		return;
	}

	function walk_q151_クリアイベント終了()
	{
		lookatoff();
		releasepc();
		return;
	}

	function walk_jony_準備()
	{
		capturepc(-1);
		usemapid(0);
		setpos(297.109039, 24.6639004, 135.629242);
		dir(-1.82848501);
		setautorelax(0);
		hidew();
		hides();
		rlookatr_4bb(1.57079637, 1.04719758);
		motionplay(0x14000002);
		return;
	}

	function walk_jony_ジョニー話始める()
	{
		motionsync();
		setbodyshake(0.00999999978);
		return;
	}

	function walk_jony_頑張る()
	{
		setpos(296.860748, 24.6389008, 135.884293);
		dir(-1.47259295);
		motionstartframe(155);
		motionplay(0x14000004);
		motionratio(0.600000024);
		sysRlookata(ジョニー);
		setbodyshake(0);
		motionsync();
		setbodyshake(0.00999999978);
		return;
	}

	function walk_jony_走っていく()
	{
		stdmotionplay_2c2(0x01000000, 0);
		motionratio(1);
		setbodyshake(0);
		return;
	}

	function walk_jony_クリアイベント終了()
	{
		lookatoff();
		showw();
		shows();
		setautorelax(1);
		usemapid(1);
		releasepc();
		return 0;
		return;
	}
}

actor NPC_Alchemist(6) {
	int stop_random_motion;
	int set_shop_name;
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
  // @description: attribute/element menu helper arrays
  int local_macro_id[13];
  int local_macro_attr[13];
  int local_choice_id[13];
  int local_choice_subcategory_id[13];
  int local_choice_dialog_id[13];

  function init() { return; }

  function main(1) {
    set_shop_name = -1;

    while (true) {
			if (quest_main_quest_status != set_shop_name) {
					set_shop_name = quest_main_quest_status;

					if (set_shop_name >= 4) {
							fieldsignmes(0x01000000 | 186);
					} else {
							fieldsignmes(0x01000000 | 185);
					}
			}

			if (stop_random_motion == 1) {
					wait(1);
					continue;
			}

			motionplay_bb(0x10000000, 20);
			wait(1);
			motionsync_282(1);
      wait((rand_29(90) + 90));
    }
    return;
	}

  function talkhold(16) { return; }

  function talkterm(17) {
    if (((getrotangzx() - getdestrotangzx_227(0)) *
         (getrotangzx() - getdestrotangzx_227(0))) > 0) {
      setaturnlookatlockstatus(1);
      aturn_261(getdestrotangzx_227(0));
    }
    return;
  }

  function set() {
    usemapid(0);
    setpos(273.3, 24.2500038, 130.3);
    dir(2.31438398);
    bindp2_d4(0x03000008, 3, 2);
    setweight(-1);
    set_ignore_hitgroup(1);
    setoverheadicontype(1);
    settalkradiusoffset(1.7, 1, -1);
    talkradius(0.4);
    wait(1);
    fetchambient_4e1(280.153412, 24.25, 133.651474);
    stdmotionread(16);
    stdmotionreadsync();
    setwalkspeed(getdefaultwalkspeed());
    stdmotionplay(0x01000000);

    return;
  }

  function talk(2) {
    // @description: dialog handler
		stop_random_motion = 0;
    flow_talk_status = 0;
    flow_poll_mode = 0;
    flow_selected_intention = 0;
    flow_confirmed_intention = 0;
    flow_reset_flow = 0;
    flow_load_equipment = 0;
    selected_category = 0;
    selected_subcategory = 0;
    selected_equipment_id = 0;
    selected_tier = 0;
    quest_unlocked_tiers = 1;

    sethpmenu(0);
    ucoff();
		lookatoff();
    settrapshowstatus(0);
    sysRturna(-1);
    if (isturn()) {
      turnsync();
      stdmotionplay_2c2(0x01000002, 20);
    }
    setkutipakustatus(1);
    setunazukistatus(1);
    setkubifuristatus(1);

		if (quest_main_quest_status == 0) {
			goto dialog_172;
		} else if (quest_main_quest_status == 1) {
				goto dialog_173;
		} else if (quest_main_quest_status == 2) {
				goto dialog_179;
		} else if (quest_main_quest_status == 3) {
				goto dialog_180;
		} else {
				goto dialog_79;
		}

		dialog_172:
    amese(0, 0x01000000 | 172);
    messync(0, 1);
    goto cleanup;

  dialog_173:
		flow_poll_mode = 2;
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 173);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 0) {
      goto dialog_175;
    } else {
      goto dialog_174;
    }

  dialog_174:
    amese(0, 0x01000000 | 174);
    messync(0, 1);
    goto cleanup;

	dialog_175:
		setmesmacro(0, 12, 0, quest_main_quest_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
		sysLookata(NAC_A03_NPC13);

    local_choice = aaske(0, 0x01000000 | 175);

    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_176;
    }

    if (havegill() < quest_main_quest_gil[0]) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_177;
    }

    if (quest_main_quest_gil[0] > 0) {
      gillwinstart((-1 * quest_main_quest_gil[0]));
      gillwinsync();
      subgill(quest_main_quest_gil[0]);
      wait(20);
      gillwinclose();
    }

    mesclose(0);
    messync(0, 1);

    quest_main_quest_status = 2;
    goto dialog_178;

  dialog_176:
		lookatoff();
    amese(0, 0x01000000 | 176);
    messync(0, 1);
    goto cleanup;

  dialog_177:
		lookatoff();
    amese(0, 0x01000000 | 177);
    messync(0, 1);
    goto cleanup;

  dialog_178:
		lookatoff();
    sebsoundplay(0, 38);
    amese(0, 0x01000000 | 178);
    messync(0, 1);
    goto cleanup;

  dialog_179:
    amese(0, 0x01000000 | 179);
    messync(0, 1);
    goto cleanup;

  dialog_180:
	  quest_main_quest_status = 4;
    amese(0, 0x01000000 | 180);
    messync(0, 1);
		wait(16);
    goto dialog_79;

  // @description: main menu
  dialog_79:
    flow_poll_mode = 1;

    if (notification_show_tier_message == 1) {
			sysReqew(0, Alchemist_Utility::Notify);
			notification_show_tier_message = 0;

			if (notification_show_supply_message == 1) {
					amese(0, 0x01000000 | 182);
					messync(0, 1);
					notification_show_supply_message = 0;
			} else if (notification_show_supply_message == 2) {
					amese(0, 0x01000000 | 183);
					messync(0, 1);
					notification_show_supply_message = 0;
			} else if (notification_show_supply_message == 3) {
					amese(0, 0x01000000 | 184);
					messync(0, 1);
					notification_show_supply_message = 0;
			}
		}

    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 79);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 0) {
      flow_talk_status = 2;
      goto dialog_80;
    } else if (local_choice == 1) {
      flow_talk_status = 3;
      goto dialog_81;
    } else if (local_choice == 2) {
      goto dialog_90;
    }

  dialog_80:
    flow_poll_mode = 1;
    amese(0, 0x01000000 | 80);
    messync(0, 1);
    goto dialog_82;

  dialog_81:
    flow_poll_mode = 1;
    amese(0, 0x01000000 | 81);
    messync(0, 1);
    goto dialog_83;

  // @description: element category selection
  dialog_82:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 82, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 2) {
      goto dialog_79;
    }
    if (local_choice == 3) {
      goto dialog_90;
    }

    local_category = local_choice;
    if (local_category == 0) {
      goto dialog_84;
    } else if (local_category == 1) {
      goto dialog_88;
    }

  // @description: attribute category selection
  dialog_83:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 6);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 83, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 6) {
      goto dialog_79;
    }
    if (local_choice == 7) {
      goto dialog_90;
    }

    local_category = local_choice;
    if (local_category == 0) {
      goto dialog_84;
    } else if (local_category == 1) {
      goto dialog_85;
    } else if (local_category == 2) {
      goto dialog_86;
    } else if (local_category == 3) {
      goto dialog_87;
    } else if (local_category == 4) {
      goto dialog_88;
    } else if (local_category == 5) {
      selected_category = 36;
      flow_load_equipment = 1;
      wait(16);
      flow_load_equipment = 0;
      goto dialog_89;
    }

  dialog_84:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 6);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 84, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 17) {
      if (flow_talk_status == 2) {
        goto dialog_82;
      } else {
        goto dialog_83;
      }
    }
    if (local_choice == 18) {
      goto dialog_90;
    }

    if (local_choice >= 0 && local_choice <= 16) {
      selected_category = local_choice + 1;
      flow_load_equipment = 1;
      wait(16);
      flow_load_equipment = 0;
      goto dialog_89;
    }

  dialog_85:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 5);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 85, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 3) {
      if (flow_talk_status == 2) {
        goto dialog_82;
      } else {
        goto dialog_83;
      }
    }
    if (local_choice == 4) {
      goto dialog_90;
    }

    if (local_choice >= 0 && local_choice <= 2) {
      selected_category = local_choice + 18;
      flow_load_equipment = 1;
      wait(16);
      flow_load_equipment = 0;
      goto dialog_89;
    }

  dialog_86:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 5);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 86, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 3) {
      if (flow_talk_status == 2) {
        goto dialog_82;
      } else {
        goto dialog_83;
      }
    }
    if (local_choice == 4) {
      goto dialog_90;
    }

    if (local_choice >= 0 && local_choice <= 2) {
      selected_category = local_choice + 21;
      flow_load_equipment = 1;
      wait(16);
      flow_load_equipment = 0;
      goto dialog_89;
    }

  dialog_87:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 5);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 87, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 8) {
      if (flow_talk_status == 2) {
        goto dialog_82;
      } else {
        goto dialog_83;
      }
    }
    if (local_choice == 9) {
      goto dialog_90;
    }

    if (local_choice >= 0 && local_choice <= 7) {
      selected_category = local_choice + 24;
      flow_load_equipment = 1;
      wait(16);
      flow_load_equipment = 0;
      goto dialog_89;
    }

  dialog_88:
    flow_poll_mode = 2;
    selected_subcategory = 0;
    flow_load_equipment = 0;

    setmeswinline(0, 6);
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 88, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 4) {
      if (flow_talk_status == 2) {
        goto dialog_82;
      } else {
        goto dialog_83;
      }
    }
    if (local_choice == 5) {
      goto dialog_90;
    }
    if (local_choice >= 0 && local_choice <= 3) {
      selected_category = local_choice + 32;
      flow_load_equipment = 1;
      wait(16);
      flow_load_equipment = 0;
      goto dialog_89;
    }

  return_to_category_dialog:
    if (selected_category >= 1 && selected_category <= 17) goto dialog_84;
    if (selected_category >= 18 && selected_category <= 20) goto dialog_85;
    if (selected_category >= 21 && selected_category <= 23) goto dialog_86;
    if (selected_category >= 24 && selected_category <= 31) goto dialog_87;
    if (selected_category >= 32 && selected_category <= 35) goto dialog_88;
    if (flow_talk_status == 2)
      goto dialog_82;
    else
      goto dialog_83;

  // @description: equipment list
  dialog_89:
    flow_poll_mode = 2;
    local_count = 0;
    local_equipment_qtty = 0;
    for (local_i = 0; local_i <= 30; local_i++) {
      if (load_equipment_list[local_i] == 0) {
        setaskselectignore(0, local_i);
      } else {
        local_count++;
        if (haveitem(load_equipment_list[local_i]) > 0) {
          setmesmacro(0, local_equipment_qtty, 1, load_equipment_list[local_i]);
          local_available_indices[local_equipment_qtty] = local_i;
          local_equipment_qtty++;
        } else {
          setaskselectignore(0, local_i);
        }
      }
    }

    if (local_equipment_qtty == 0) {
      amese(0, 0x01000000 | 91);
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
    local_equipment_index = aask(0, 0x01000000 | 89, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_equipment_index >= local_equipment_qtty) {
      goto return_to_category_dialog;
    }

    local_selected_equipment =
        load_equipment_list[local_available_indices[local_equipment_index]];
    selected_equipment_id = local_selected_equipment;
    flow_selected_intention = 1;

    if (flow_talk_status == 2) {
      goto dialog_92;
    } else if (flow_talk_status == 3) {
      if (selected_category >= 1 && selected_category <= 17) {
        goto dialog_113;
      } else if (selected_category == 36) {
        goto dialog_114;
      } else if (selected_category >= 18 && selected_category <= 23) {
        goto dialog_115;
      } else if (selected_category >= 24 && selected_category <= 35) {
        goto dialog_116;
      } else {
        goto cleanup;
      }
    } else {
      goto cleanup;
    }

  // @description: element selection
  dialog_92:
    flow_poll_mode = 2;
    local_macro_id[0] = 14;
    local_macro_id[1] = 15;
    local_macro_id[2] = 16;
    local_macro_id[3] = 17;
    local_macro_id[4] = 18;
    local_macro_id[5] = 19;
    local_macro_id[6] = 20;
    local_macro_id[7] = 21;

    local_choice_id[0] = 0;
    local_choice_id[1] = 1;
    local_choice_id[2] = 2;
    local_choice_id[3] = 3;
    local_choice_id[4] = 4;
    local_choice_id[5] = 5;
    local_choice_id[6] = 6;
    local_choice_id[7] = 7;

    local_choice_subcategory_id[0] = 1;
    local_choice_subcategory_id[1] = 2;
    local_choice_subcategory_id[2] = 3;
    local_choice_subcategory_id[3] = 4;
    local_choice_subcategory_id[4] = 5;
    local_choice_subcategory_id[5] = 6;
    local_choice_subcategory_id[6] = 7;
    local_choice_subcategory_id[7] = 8;

    local_choice_dialog_id[0] = 93;
    local_choice_dialog_id[1] = 94;
    local_choice_dialog_id[2] = 95;
    local_choice_dialog_id[3] = 96;
    local_choice_dialog_id[4] = 97;
    local_choice_dialog_id[5] = 98;
    local_choice_dialog_id[6] = 99;
    local_choice_dialog_id[7] = 100;

    setmesmacro(0, 7, 1, selected_equipment_id);

    local_count = 0;
    local_i = 0;
    while (local_i < 8) {
      setmesmacro(0, local_macro_id[local_i], 0, quest_unlocked_elements[local_i]);
      if (quest_unlocked_elements[local_i] == 0) {
        setaskselectignore(0, local_choice_id[local_i]);
      }
      if (quest_unlocked_elements[local_i] > 0) {
        local_count++;
      }
      local_i++;
    }
    local_count += 2;
    if (local_count > 10) {
      local_count = 10;
    }
    if (local_count > 7) {
      setmeswinline(0, 7);
    } else {
      setmeswinline(0, local_count);
    }
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 92, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);

    // Back is always option 9
    if (local_choice == 9) {
      goto dialog_89;
    }

    // Cleanse binding is always option 8
    if (local_choice == 8) {
      selected_subcategory = 9;
      goto check_element_before_remove;
    }

    if (local_choice >= 0 && local_choice < 8 &&
        quest_unlocked_elements[local_choice] > 0) {
      selected_subcategory = local_choice_subcategory_id[local_choice];
      if (local_choice == 0) {
        goto dialog_93;
      } else if (local_choice == 1) {
        goto dialog_94;
      } else if (local_choice == 2) {
        goto dialog_95;
      } else if (local_choice == 3) {
        goto dialog_96;
      } else if (local_choice == 4) {
        goto dialog_97;
      } else if (local_choice == 5) {
        goto dialog_98;
      } else if (local_choice == 6) {
        goto dialog_99;
      } else if (local_choice == 7) {
        goto dialog_100;
      }
    }

  dialog_93:
    flow_poll_mode = 2;
    selected_subcategory = 1;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 93);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_94:
    selected_subcategory = 2;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 94);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_95:
    selected_subcategory = 3;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 6);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 95);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_96:

    selected_subcategory = 4;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 96);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_97:
    selected_subcategory = 5;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 97);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_98:
    selected_subcategory = 6;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 98);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_99:
    selected_subcategory = 7;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 99);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  dialog_100:
    selected_subcategory = 8;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 100);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  // @description: check existing element before remove
  check_element_before_remove:
    flow_check_element = 1;
    wait(16);
    flow_check_element = 0;

    if (current_element == 0) {
      goto dialog_170;
    }
    goto dialog_101;

  dialog_101:

    selected_subcategory = 9;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 101);
    if (local_choice == 1) {
      gillwinclose();
      mesclose(0);
      messync(0, 1);
      goto dialog_89;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    goto check_element_before_apply;

  // @description: check existing element before apply
  check_element_before_apply:
    flow_check_element = 1;
    wait(16);
    flow_check_element = 0;

    if (current_element >= 1 && current_element <= 8) {
      switch (current_element) {
        case 1:
          goto dialog_159;
        case 2:
          goto dialog_160;
        case 3:
          goto dialog_162;
        case 4:
          goto dialog_161;
        case 5:
          goto dialog_163;
        case 6:
          goto dialog_164;
        case 7:
          goto dialog_165;
        case 8:
          goto dialog_166;
        default:
          goto dialog_112;
      }
    }
    goto dialog_112;

  dialog_159:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 159);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }
    goto dialog_112;

  dialog_160:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 160);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 1) {
      goto dialog_89;
    }

    goto dialog_112;

  dialog_161:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 161);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }
    goto dialog_112;

  dialog_162:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 162);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }
    goto dialog_112;

  dialog_163:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 163);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }
    goto dialog_112;

  dialog_164:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 164);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }
    goto dialog_112;

  dialog_165:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 166);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }
    goto dialog_112;

  dialog_166:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 167);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }
    goto dialog_112;

  // @description: no element to remove
  dialog_170:
    flow_poll_mode = 2;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 170);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      goto dialog_90;
    }

  // @description: no attribute to remove
  dialog_171:
    flow_poll_mode = 2;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 171);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      goto dialog_90;
    }

  // @description: alchemy animation
  dialog_112:
    flow_poll_mode = 1;
    amese(0, 0x01000000 | 112);
    messync(0, 1);

    sebsoundplay(0, 38);
    if (selected_subcategory != 9) {
      sysCommon2effectplay(PC00, 11);
    } else {
      sysCommon2effectplay(PC00, 10);
    }

    wait(35);

    if (flow_talk_status == 2) {
      switch (selected_subcategory) {
        case 1:
          goto dialog_103;
        case 2:
          goto dialog_104;
        case 3:
          goto dialog_105;
        case 4:
          goto dialog_106;
        case 5:
          goto dialog_107;
        case 6:
          goto dialog_108;
        case 7:
          goto dialog_109;
        case 8:
          goto dialog_110;
        case 9:
          goto dialog_111;
        default:
          goto dialog_103;
      }
    } else if (flow_talk_status == 3) {
      if (selected_subcategory == 0) {
        goto dialog_155;
      } else {
        goto attribute_success_dialog;
      }
    } else {
      goto dialog_103;
    }

  // @description: not enough items
  dialog_102:
    flow_poll_mode = 1;
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinclose();
    local_choice = aaske(0, 0x01000000 | 102);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      goto cleanup;
    }

  dialog_103:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 103);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  dialog_104:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 104);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  dialog_105:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 105);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  dialog_106:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 106);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  dialog_107:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 107);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  dialog_108:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 108);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  dialog_109:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 109);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  dialog_110:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 110);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  dialog_111:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 111);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto dialog_89;
    } else if (local_choice == 1) {
      flow_confirmed_intention = 1;
      wait(16);
      flow_confirmed_intention = 0;
      goto cleanup;
    }

  // @description: back to attribute menu
  return_to_attribute_menu:
    gillwinclose();

    if (selected_category >= 1 && selected_category <= 17) {
      goto dialog_113;
    } else if (selected_category == 36) {
      goto dialog_114;
    } else if (selected_category >= 18 && selected_category <= 23) {
      goto dialog_115;
    } else if (selected_category >= 24 && selected_category <= 35) {
      goto dialog_116;
    } else {
      goto dialog_89;
    }

  // @description: weapon attributes menu
  dialog_113:
    flow_poll_mode = 2;

    local_macro_id[0] = 22;
    local_macro_id[1] = 23;
    local_macro_id[2] = 24;
    local_macro_id[3] = 25;
    local_macro_id[4] = 26;
    local_macro_id[5] = 27;
    local_macro_id[6] = 28;
    local_macro_id[7] = 33;
    local_macro_id[8] = 34;
    local_macro_id[9] = 35;
    local_macro_id[10] = 36;
    local_macro_id[11] = 37;
    local_macro_id[12] = 38;

    local_macro_attr[0] = 0;
    local_macro_attr[1] = 1;
    local_macro_attr[2] = 2;
    local_macro_attr[3] = 3;
    local_macro_attr[4] = 4;
    local_macro_attr[5] = 5;
    local_macro_attr[6] = 6;
    local_macro_attr[7] = 11;
    local_macro_attr[8] = 12;
    local_macro_attr[9] = 13;
    local_macro_attr[10] = 14;
    local_macro_attr[11] = 15;
    local_macro_attr[12] = 16;

    local_choice_id[0] = 0;
    local_choice_id[1] = 1;
    local_choice_id[2] = 2;
    local_choice_id[3] = 3;
    local_choice_id[4] = 4;
    local_choice_id[5] = 5;
    local_choice_id[6] = 6;
    local_choice_id[7] = 7;
    local_choice_id[8] = 8;
    local_choice_id[9] = 9;
    local_choice_id[10] = 10;
    local_choice_id[11] = 11;
    local_choice_id[12] = 12;

    local_choice_subcategory_id[0] = 10;
    local_choice_subcategory_id[1] = 11;
    local_choice_subcategory_id[2] = 12;
    local_choice_subcategory_id[3] = 16;
    local_choice_subcategory_id[4] = 14;
    local_choice_subcategory_id[5] = 15;
    local_choice_subcategory_id[6] = 13;
    local_choice_subcategory_id[7] = 21;
    local_choice_subcategory_id[8] = 22;
    local_choice_subcategory_id[9] = 23;
    local_choice_subcategory_id[10] = 24;
    local_choice_subcategory_id[11] = 25;
    local_choice_subcategory_id[12] = 26;

    local_choice_dialog_id[0] = 117;
    local_choice_dialog_id[1] = 118;
    local_choice_dialog_id[2] = 119;
    local_choice_dialog_id[3] = 123;
    local_choice_dialog_id[4] = 121;
    local_choice_dialog_id[5] = 122;
    local_choice_dialog_id[6] = 120;
    local_choice_dialog_id[7] = 128;
    local_choice_dialog_id[8] = 129;
    local_choice_dialog_id[9] = 130;
    local_choice_dialog_id[10] = 131;
    local_choice_dialog_id[11] = 132;
    local_choice_dialog_id[12] = 133;

    setmesmacro(0, 0, 1, selected_equipment_id);

    local_count = 0;
    local_i = 0;
    while (local_i < 13) {
      setmesmacro(0, local_macro_id[local_i], 0,
                  quest_unlocked_attributes[local_macro_attr[local_i]]);
      if (quest_unlocked_attributes[local_macro_attr[local_i]] == 0) {
        setaskselectignore(0, local_choice_id[local_i]);
      }
      if (quest_unlocked_attributes[local_macro_attr[local_i]] > 0) {
        local_count++;
      }
      local_i++;
    }
    local_count += 2;

    if (local_count > 15) {
      local_count = 15;
    }

    if (local_count > 7) {
      setmeswinline(0, 7);
    } else {
      setmeswinline(0, local_count);
    }

    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 113, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 14) {
      goto dialog_89;
    }

    if (local_choice == 13) {
      selected_subcategory = 9;
      goto check_attribute_before_remove;
    }

    if (local_choice >= 0 && local_choice < 13 &&
        quest_unlocked_attributes[local_macro_attr[local_choice]] > 0) {
      selected_subcategory = local_choice_subcategory_id[local_choice];
      if (local_choice == 0) {
        goto dialog_117;
      } else if (local_choice == 1) {
        goto dialog_118;
      } else if (local_choice == 2) {
        goto dialog_119;
      } else if (local_choice == 3) {
        goto dialog_123;
      } else if (local_choice == 4) {
        goto dialog_121;
      } else if (local_choice == 5) {
        goto dialog_122;
      } else if (local_choice == 6) {
        goto dialog_120;
      } else if (local_choice == 7) {
        goto dialog_128;
      } else if (local_choice == 8) {
        goto dialog_129;
      } else if (local_choice == 9) {
        goto dialog_130;
      } else if (local_choice == 10) {
        goto dialog_131;
      } else if (local_choice == 11) {
        goto dialog_132;
      } else if (local_choice == 12) {
        goto dialog_133;
      }
    }

  dialog_114:
    flow_poll_mode = 2;
    local_macro_id[0] = 29;
    local_macro_id[1] = 30;
    local_macro_id[2] = 33;
    local_macro_id[3] = 34;
    local_macro_id[4] = 35;
    local_macro_id[5] = 36;
    local_macro_id[6] = 37;
    local_macro_id[7] = 38;

    local_macro_attr[0] = 7;
    local_macro_attr[1] = 8;
    local_macro_attr[2] = 11;
    local_macro_attr[3] = 12;
    local_macro_attr[4] = 13;
    local_macro_attr[5] = 14;
    local_macro_attr[6] = 15;
    local_macro_attr[7] = 16;

    local_choice_id[0] = 0;
    local_choice_id[1] = 1;
    local_choice_id[2] = 2;
    local_choice_id[3] = 3;
    local_choice_id[4] = 4;
    local_choice_id[5] = 5;
    local_choice_id[6] = 6;
    local_choice_id[7] = 7;

    local_choice_subcategory_id[0] = 17;
    local_choice_subcategory_id[1] = 18;
    local_choice_subcategory_id[2] = 21;
    local_choice_subcategory_id[3] = 22;
    local_choice_subcategory_id[4] = 23;
    local_choice_subcategory_id[5] = 24;
    local_choice_subcategory_id[6] = 25;
    local_choice_subcategory_id[7] = 26;

    local_choice_dialog_id[0] = 124;
    local_choice_dialog_id[1] = 125;
    local_choice_dialog_id[2] = 128;
    local_choice_dialog_id[3] = 129;
    local_choice_dialog_id[4] = 130;
    local_choice_dialog_id[5] = 131;
    local_choice_dialog_id[6] = 132;
    local_choice_dialog_id[7] = 133;

    setmesmacro(0, 0, 1, selected_equipment_id);
    local_count = 0;
    local_i = 0;
    while (local_i < 8) {
      setmesmacro(0, local_macro_id[local_i], 0,
                  quest_unlocked_attributes[local_macro_attr[local_i]]);
      if (quest_unlocked_attributes[local_macro_attr[local_i]] == 0) {
        setaskselectignore(0, local_choice_id[local_i]);
      }
      if (quest_unlocked_attributes[local_macro_attr[local_i]] > 0) {
        local_count++;
      }
      local_i++;
    }
    local_count += 2;
    if (local_count > 7) {
      setmeswinline(0, 7);
    } else {
      setmeswinline(0, local_count);
    }
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 114, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 9) {
      goto dialog_89;
    }

    if (local_choice >= 0 && local_choice < 8 &&
        quest_unlocked_attributes[local_macro_attr[local_choice]] > 0) {
      selected_subcategory = local_choice_subcategory_id[local_choice];
      if (local_choice == 0) {
        goto dialog_124;
      } else if (local_choice == 1) {
        goto dialog_125;
      } else if (local_choice == 2) {
        goto dialog_128;
      } else if (local_choice == 3) {
        goto dialog_129;
      } else if (local_choice == 4) {
        goto dialog_130;
      } else if (local_choice == 5) {
        goto dialog_131;
      } else if (local_choice == 6) {
        goto dialog_132;
      } else if (local_choice == 7) {
        goto dialog_133;
      }
    } else if (local_choice == 8) {
      selected_subcategory = 9;
      goto check_attribute_before_remove;
    }

  dialog_115:
    flow_poll_mode = 2;
    local_macro_id[0] = 31;
    local_macro_id[1] = 32;
    local_macro_id[2] = 33;
    local_macro_id[3] = 34;
    local_macro_id[4] = 35;
    local_macro_id[5] = 36;
    local_macro_id[6] = 37;
    local_macro_id[7] = 38;

    local_macro_attr[0] = 9;
    local_macro_attr[1] = 10;
    local_macro_attr[2] = 11;
    local_macro_attr[3] = 12;
    local_macro_attr[4] = 13;
    local_macro_attr[5] = 14;
    local_macro_attr[6] = 15;
    local_macro_attr[7] = 16;

    local_choice_id[0] = 0;
    local_choice_id[1] = 1;
    local_choice_id[2] = 2;
    local_choice_id[3] = 3;
    local_choice_id[4] = 4;
    local_choice_id[5] = 5;
    local_choice_id[6] = 6;
    local_choice_id[7] = 7;

    local_choice_subcategory_id[0] = 19;
    local_choice_subcategory_id[1] = 20;
    local_choice_subcategory_id[2] = 21;
    local_choice_subcategory_id[3] = 22;
    local_choice_subcategory_id[4] = 23;
    local_choice_subcategory_id[5] = 24;
    local_choice_subcategory_id[6] = 25;
    local_choice_subcategory_id[7] = 26;

    local_choice_dialog_id[0] = 126;
    local_choice_dialog_id[1] = 127;
    local_choice_dialog_id[2] = 128;
    local_choice_dialog_id[3] = 129;
    local_choice_dialog_id[4] = 130;
    local_choice_dialog_id[5] = 131;
    local_choice_dialog_id[6] = 132;
    local_choice_dialog_id[7] = 133;

    setmesmacro(0, 0, 1, selected_equipment_id);

    local_count = 0;
    local_i = 0;
    while (local_i < 8) {
      setmesmacro(0, local_macro_id[local_i], 0,
                  quest_unlocked_attributes[local_macro_attr[local_i]]);
      if (quest_unlocked_attributes[local_macro_attr[local_i]] == 0) {
        setaskselectignore(0, local_choice_id[local_i]);
      }
      if (quest_unlocked_attributes[local_macro_attr[local_i]] > 0) {
        local_count++;
      }
      local_i++;
    }
    local_count += 2;
    if (local_count > 7) {
      setmeswinline(0, 7);
    } else {
      setmeswinline(0, local_count);
    }
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 115, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 9) {
      goto dialog_89;
    }

    if (local_choice >= 0 && local_choice < 8 &&
        quest_unlocked_attributes[local_macro_attr[local_choice]] > 0) {
      selected_subcategory = local_choice_subcategory_id[local_choice];
      if (local_choice == 0) {
        goto dialog_126;
      } else if (local_choice == 1) {
        goto dialog_127;
      } else if (local_choice == 2) {
        goto dialog_128;
      } else if (local_choice == 3) {
        goto dialog_129;
      } else if (local_choice == 4) {
        goto dialog_130;
      } else if (local_choice == 5) {
        goto dialog_131;
      } else if (local_choice == 6) {
        goto dialog_132;
      } else if (local_choice == 7) {
        goto dialog_133;
      }
    } else if (local_choice == 8) {
      selected_subcategory = 9;
      goto check_attribute_before_remove;
    }

  dialog_116:
    flow_poll_mode = 2;
    local_macro_id[0] = 24;
    local_macro_id[1] = 28;
    local_macro_id[2] = 25;
    local_macro_id[3] = 33;
    local_macro_id[4] = 34;
    local_macro_id[5] = 35;
    local_macro_id[6] = 36;
    local_macro_id[7] = 37;
    local_macro_id[8] = 38;

    local_macro_attr[0] = 2;
    local_macro_attr[1] = 6;
    local_macro_attr[2] = 3;
    local_macro_attr[3] = 11;
    local_macro_attr[4] = 12;
    local_macro_attr[5] = 13;
    local_macro_attr[6] = 14;
    local_macro_attr[7] = 15;
    local_macro_attr[8] = 16;

    local_choice_id[0] = 0;
    local_choice_id[1] = 1;
    local_choice_id[2] = 2;
    local_choice_id[3] = 3;
    local_choice_id[4] = 4;
    local_choice_id[5] = 5;
    local_choice_id[6] = 6;
    local_choice_id[7] = 7;
    local_choice_id[8] = 8;

    local_choice_subcategory_id[0] = 12;
    local_choice_subcategory_id[1] = 16;
    local_choice_subcategory_id[2] = 13;
    local_choice_subcategory_id[3] = 21;
    local_choice_subcategory_id[4] = 22;
    local_choice_subcategory_id[5] = 23;
    local_choice_subcategory_id[6] = 24;
    local_choice_subcategory_id[7] = 25;
    local_choice_subcategory_id[8] = 26;

    local_choice_dialog_id[0] = 119;
    local_choice_dialog_id[1] = 123;
    local_choice_dialog_id[2] = 120;
    local_choice_dialog_id[3] = 128;
    local_choice_dialog_id[4] = 129;
    local_choice_dialog_id[5] = 130;
    local_choice_dialog_id[6] = 131;
    local_choice_dialog_id[7] = 132;
    local_choice_dialog_id[8] = 133;

    setmesmacro(0, 0, 1, selected_equipment_id);

    local_count = 0;
    local_i = 0;
    while (local_i < 9) {
      setmesmacro(0, local_macro_id[local_i], 0,
                  quest_unlocked_attributes[local_macro_attr[local_i]]);
      if (quest_unlocked_attributes[local_macro_attr[local_i]] == 0) {
        setaskselectignore(0, local_choice_id[local_i]);
      }
      if (quest_unlocked_attributes[local_macro_attr[local_i]] > 0) {
        local_count++;
      }
      local_i++;
    }
    local_count += 2;
    if (local_count > 7) {
      setmeswinline(0, 7);
    } else {
      setmeswinline(0, local_count);
    }
    askpos(0, 0, 1);
    local_choice = aask(0, 0x01000000 | 116, 48, 0x03fe, 1);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 10) {
      goto dialog_89;
    }

    if (local_choice >= 0 && local_choice < 9 &&
        quest_unlocked_attributes[local_macro_attr[local_choice]] > 0) {
      selected_subcategory = local_choice_subcategory_id[local_choice];
      if (local_choice == 0) {
        goto dialog_119;
      } else if (local_choice == 1) {
        goto dialog_123;
      } else if (local_choice == 2) {
        goto dialog_120;
      } else if (local_choice == 3) {
        goto dialog_128;
      } else if (local_choice == 4) {
        goto dialog_129;
      } else if (local_choice == 5) {
        goto dialog_130;
      } else if (local_choice == 6) {
        goto dialog_131;
      } else if (local_choice == 7) {
        goto dialog_132;
      } else if (local_choice == 8) {
        goto dialog_133;
      }
    } else if (local_choice == 9) {
      selected_subcategory = 9;
      goto check_attribute_before_remove;
    }

  dialog_117:
    flow_poll_mode = 2;
    selected_subcategory = 10;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 117);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_118:
    flow_poll_mode = 2;
    selected_subcategory = 11;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 118);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_119:
    flow_poll_mode = 2;
    selected_subcategory = 12;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 119);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_120:
    flow_poll_mode = 2;
    selected_subcategory = 13;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 120);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_121:
    flow_poll_mode = 2;
    selected_subcategory = 14;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 121);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_122:
    flow_poll_mode = 2;
    selected_subcategory = 15;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 122);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_123:
    flow_poll_mode = 2;
    selected_subcategory = 16;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 123);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_124:
    flow_poll_mode = 2;
    selected_subcategory = 17;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 124);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_125:
    flow_poll_mode = 2;
    selected_subcategory = 18;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 125);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_126:
    flow_poll_mode = 2;
    selected_subcategory = 19;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 126);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_127:
    flow_poll_mode = 2;
    selected_subcategory = 20;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 127);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_128:
    flow_poll_mode = 2;
    selected_subcategory = 21;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 128);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_129:
    flow_poll_mode = 2;
    selected_subcategory = 22;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 129);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_130:
    flow_poll_mode = 2;
    selected_subcategory = 23;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 130);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_131:
    flow_poll_mode = 2;
    selected_subcategory = 24;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 131);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_132:
    flow_poll_mode = 2;
    selected_subcategory = 25;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 132);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  dialog_133:
    flow_poll_mode = 2;
    selected_subcategory = 26;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 8, 0, refinement_tier1_attribute_value);
    setmesmacro(0, 9, 0, refinement_tier2_attribute_value);
    setmesmacro(0, 10, 0, refinement_tier3_attribute_value);
    setmesmacro(0, 11, 0, quest_unlocked_tiers >= 1);
    setmesmacro(0, 12, 0, quest_unlocked_tiers >= 2);
    setmesmacro(0, 13, 0, quest_unlocked_tiers >= 3);

    if (quest_unlocked_tiers < 1 || refinement_tier1_attribute_value == 0) {
      setaskselectignore(0, 0);
    }
    if (quest_unlocked_tiers < 2 || refinement_tier2_attribute_value == 0) {
      setaskselectignore(0, 1);
    }
    if (quest_unlocked_tiers < 3 || refinement_tier3_attribute_value == 0) {
      setaskselectignore(0, 2);
    }

    local_count = 0;
    if (quest_unlocked_tiers >= 1 && refinement_tier1_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 2 && refinement_tier2_attribute_value > 0) {
      local_count = local_count + 1;
    }
    if (quest_unlocked_tiers >= 3 && refinement_tier3_attribute_value > 0) {
      local_count = local_count + 1;
    }
    local_count = local_count + 1;
    if (local_count < 2) {
      local_count = 2;
    }
    if (local_count > 4) {
      local_count = 4;
    }

    setmeswinline(0, local_count);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 133);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 3) {
      goto return_to_attribute_menu;
    }

    selected_tier = local_choice + 1;
    goto check_attribute_before_apply;

  // @description: check existing attribute before apply
  check_attribute_before_apply:

    flow_check_attribute = 1;
    wait(16);
    flow_check_attribute = 0;

    if (current_attribute >= 10 && current_attribute <= 26) {
      if (selected_tier == 1) {
        goto dialog_156;
      } else if (selected_tier == 2) {
        goto dialog_157;
      } else if (selected_tier == 3) {
        goto dialog_158;
      } else {
        goto dialog_156;
      }
    }

    if (selected_tier == 1) {
      goto dialog_134;
    } else if (selected_tier == 2) {
      goto dialog_135;
    } else if (selected_tier == 3) {
      goto dialog_136;
    } else {
      goto dialog_134;
    }

  // @description: tier 1 confirmation
  dialog_134:
    flow_poll_mode = 2;

    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 134);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto return_to_attribute_menu;
    }

    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    flow_confirmed_intention = 1;
    wait(16);
    flow_confirmed_intention = 0;
    goto dialog_167;

  // @description: tier 2 confirmation
  dialog_135:
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;
    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 135);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto return_to_attribute_menu;
    }
    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    flow_confirmed_intention = 1;
    wait(16);
    flow_confirmed_intention = 0;
    goto dialog_168;

  // @description: tier 3 confirmation
  dialog_136:
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;
    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 136);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto return_to_attribute_menu;
    }
    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    flow_confirmed_intention = 1;
    wait(16);
    flow_confirmed_intention = 0;
    goto dialog_169;

  // @description: check existing attribute before remove
  check_attribute_before_remove:
    flow_check_attribute = 1;
    wait(16);
    flow_check_attribute = 0;

    if (current_attribute == 0) {
      goto dialog_171;
    }
    goto dialog_137;

  // @description: remove attribute
  dialog_137:
    flow_poll_mode = 2;

    selected_subcategory = 9;
    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;
    setmesmacro(0, 0, 1, load_upgrade_item_ids[0]);
    setmesmacro(0, 1, 1, load_upgrade_item_ids[1]);
    setmesmacro(0, 2, 1, load_upgrade_item_ids[2]);
    setmesmacro(0, 3, 0, load_upgrade_item_qtys[0]);
    setmesmacro(0, 4, 0, load_upgrade_item_qtys[1]);
    setmesmacro(0, 5, 0, load_upgrade_item_qtys[2]);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 12, 0, load_upgrade_gil[0]);
    setmeswinline(0, 3);
    askpos(0, 0, 1);
    gillwinopen(havegill());
    local_choice = aaske(0, 0x01000000 | 137);
    if (local_choice == 1) {
      mesclose(0);
      messync(0, 1);
      goto return_to_attribute_menu;
    }
    if ((haveitem(load_upgrade_item_ids[0]) < load_upgrade_item_qtys[0] ||
         haveitem(load_upgrade_item_ids[1]) < load_upgrade_item_qtys[1] ||
         haveitem(load_upgrade_item_ids[2]) < load_upgrade_item_qtys[2]) &&
        (load_upgrade_gil[0] > 0 && havegill() < load_upgrade_gil[0])) {
      mesclose(0);
      messync(0, 1);
      goto dialog_102;
    }

    if (load_upgrade_gil[0] > 0) {
      gillwinstart((-1 * load_upgrade_gil[0]));
      gillwinsync();
      subgill(load_upgrade_gil[0]);
      wait(20);
      gillwinclose();
    }
    mesclose(0);
    messync(0, 1);
    flow_confirmed_intention = 1;
    wait(16);
    flow_confirmed_intention = 0;
    goto dialog_155;

  // @description: attribute success dialog route
  attribute_success_dialog:

    if (selected_subcategory == 10) {
      goto dialog_138;
    } else if (selected_subcategory == 11) {
      goto dialog_139;
    } else if (selected_subcategory == 12) {
      goto dialog_140;
    } else if (selected_subcategory == 13) {
      goto dialog_141;
    } else if (selected_subcategory == 14) {
      goto dialog_142;
    } else if (selected_subcategory == 15) {
      goto dialog_143;
    } else if (selected_subcategory == 16) {
      goto dialog_144;
    } else if (selected_subcategory == 17) {
      goto dialog_145;
    } else if (selected_subcategory == 18) {
      goto dialog_146;
    } else if (selected_subcategory == 19) {
      goto dialog_147;
    } else if (selected_subcategory == 20) {
      goto dialog_148;
    } else if (selected_subcategory == 21) {
      goto dialog_149;
    } else if (selected_subcategory == 22) {
      goto dialog_150;
    } else if (selected_subcategory == 23) {
      goto dialog_151;
    } else if (selected_subcategory == 24) {
      goto dialog_152;
    } else if (selected_subcategory == 25) {
      goto dialog_153;
    } else if (selected_subcategory == 26) {
      goto dialog_154;
    } else {
      goto return_to_attribute_menu;
    }

  dialog_138:
    flow_poll_mode = 2;
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 138);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_139:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 139);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_140:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 140);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_141:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 141);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_142:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 142);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_143:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 143);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_144:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 144);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_145:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 145);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_146:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 146);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_147:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 147);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_148:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 148);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_149:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 149);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_150:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 150);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_151:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 151);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_152:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 152);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_153:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 153);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  dialog_154:
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 154);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto cleanup;
    }

  // @description: attribute removal success
  dialog_155:
    sebsoundplay(0, 38);
    sysCommon2effectplay(PC00, 10);

    wait(35);

    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 155);
    mesclose(0);
    messync(0, 1);

    if (local_choice == 0) {
      goto return_to_attribute_menu;
    } else {
      goto dialog_90;
    }

  // @description: tier 1 overwrite
  dialog_156:
    flow_poll_mode = 2;

    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 156);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }

    if (selected_tier == 1) {
      goto dialog_134;
    } else if (selected_tier == 2) {
      goto dialog_135;
    } else if (selected_tier == 3) {
      goto dialog_136;
    } else {
      goto dialog_134;
    }

  // @description: tier 2 overwrite
  dialog_157:

    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;

    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 157);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }

    if (selected_tier == 1) {
      goto dialog_134;
    } else if (selected_tier == 2) {
      goto dialog_135;
    } else if (selected_tier == 3) {
      goto dialog_136;
    } else {
      goto dialog_135;
    }

  // @description: tier 3 overwrite
  dialog_158:

    flow_load_equipment = 1;
    wait(16);
    flow_load_equipment = 0;
    setmesmacro(0, 1, 0, refinement_default_attribute_value);
    setmesmacro(0, 2, 0, refinement_total_attribute_value);
    setmesmacro(0, 7, 1, selected_equipment_id);
    setmeswinline(0, 4);
    askpos(0, 0, 1);
    local_choice = aaske(0, 0x01000000 | 158);
    mesclose(0);
    messync(0, 1);
    if (local_choice == 1) {
      goto dialog_89;
    }
    if (selected_tier == 1) {
      goto dialog_134;
    } else if (selected_tier == 2) {
      goto dialog_135;
    } else if (selected_tier == 3) {
      goto dialog_136;
    } else {
      goto dialog_136;
    }

  // @description: tier 1 animation
  dialog_167:
    flow_poll_mode = 1;

    sebsoundplay(0, 39);
    amese(0, 0x01000000 | 168);
    messync(0, 1);

    sebsoundplay(0, 38);
    sysCommon2effectplay(PC00, 4);
    goto attribute_success_dialog;

  // @description: tier 2 animation
  dialog_168:
    flow_poll_mode = 1;

    sebsoundplay(0, 39);
    amese(0, 0x01000000 | 169);
    messync(0, 1);

    sebsoundplay(0, 38);
    sysCommon2effectplay(PC00, 4);
    goto attribute_success_dialog;

  // @description: tier 3 animation
  dialog_169:
    flow_poll_mode = 1;

    sebsoundplay(0, 39);
    amese(0, 0x01000000 | 170);
    messync(0, 1);

    sebsoundplay(0, 38);
    sysCommon2effectplay(PC00, 4);
    goto attribute_success_dialog;

  // @description: exit message
  dialog_90:
    flow_poll_mode = 1;
    amese(0, 0x01000000 | 90);
    messync(0, 1);
    goto cleanup;

  // @description: cleanup and restore
  cleanup:
    flow_talk_status = 0;
    flow_selected_intention = 0;
    flow_confirmed_intention = 0;
    flow_reset_flow = 0;
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
u_char  file_var_s49_1;          // pos: 0x16;

actor ジョニー(6)
{

	function init()
	{
		return;
	}

	function main(1)
	{
		return;
	}

	function talk(2)
	{
		return;
	}

	function talk_step01_01()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setaturnlookatlockstatus(0);
		sysAturna(-1);
		stdmotionplay_2c2(0x01000002, 20);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000044);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step01_02()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000045);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		ucon();
		sethpmenu(1);
		clear_force_char_nearfade();
		setmaphighmodeldepth(-1);
		setmapmodelstatus(1);
		setstatuserrordispdenystatus(0);
		settrapshowstatus(1);
		return;
	}

	function talk_step03()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setaturnlookatlockstatus(0);
		sysAturna(-1);
		stdmotionplay_2c2(0x01000002, 20);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000046);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step04()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setaturnlookatlockstatus(0);
		sysAturna(-1);
		stdmotionplay_2c2(0x01000002, 20);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000047);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talk_step05()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setaturnlookatlockstatus(0);
		sysAturna(-1);
		motionplay_bb(0x14000000, 20);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000048);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
		fadeout(30);
		fadesync();
		g_com_navi_footcalc[0] = getx_12b(-1);
		g_com_navi_footcalc[1] = gety_12c(-1);
		g_com_navi_footcalc[2] = getz_12d(-1);
		setnavimapfootmarkstatus(0);
		sethpmenufast(0);
		settrapshowstatus(0);
		setcharseplayall(0);
		if (!(istownmap()))
		{
			setstatuserrordispdenystatus(1);
		}
		sysReq(1, ロケイベント監督::ジョニーお礼渡す);
		return;
	}

	function talk_step06()
	{
		sethpmenu(0);
		ucoff();
		settrapshowstatus(0);
		setaturnlookatlockstatus(0);
		sysAturna(-1);
		stdmotionplay_2c2(0x01000002, 20);
		stdmotionplay_2c2(0x01000010, 20);
		setkutipakustatus(1);
		setunazukistatus(1);
		amese(0, 0x01000049);
		messync(0, 1);
		setkutipakustatus(0);
		setunazukistatus(0);
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

	function talkhold(16)
	{
		return;
	}

	function talkterm(17)
	{
		if (((getrotangzx() - getdestrotangzx_227(0)) * (getrotangzx() - getdestrotangzx_227(0))) > 0)
		{
			setaturnlookatlockstatus(1);
			aturn_261(getdestrotangzx_227(0));
		}
		if (file_var_s3_1 == 0)
		{
			switch (global_var_1)
			{
				case lte(3):
					if (!((global_var_1 == 0 && getx_12b(49) == 282.419769)))
					{
						if (!(((global_var_1 <= 2 && getx_12b(49) == 282.419769) && file_var_s49_1 >= 1)))
						{
							motionloop(1);
							motionplay(0x11000002);
						}
					}
					break;
				case lte(4):
					break;
				case lte(5):
					break;
				case lte(6):
					motionloop(1);
					motionplay(0x11000004);
					break;
				default:
					break;
			}
		}
		return;
	}

	function set_subev()
	{
		usemapid(1);
		setpos(254.800446, 24.911808, 110.96273);
		dir(0.537962973);
		bindp2_d4(0x03000003, 4, 3);
		setweight(-1);
		setnpcname(0x02a1);
		setautorelax(1);
		return;
	}

	function talktype_enable()
	{
		reqenable(16);
		return;
	}

	function talktype_disable()
	{
		reqdisable(16);
		return;
	}

	function motion_TAG_subev()
	{
		stdmotionread(16);
		stdmotionreadsync();
		setwalkspeed(getdefaultwalkspeed());
		stdmotionplay(0x01000000);
		return;
	}

	function walk_すぐ倒れる()
	{
		file_var_s4_1 = 0;
		motionloop(1);
		motionplay_bb(0x11000002, 20);
		file_var_s3_1 = 0;
		move_5e(263.326447, 24.25, 130.546265, 0.0729160011);
		move_5e(272.16214, 24.2518711, 138.630829, 0.0729160011);
		file_var_s4_1 = 1;
		move_5e(282.419769, 23.7718849, 148.016357, 0.0729160011);
		reqdisable(2);
		setautorelax(0);
		motionloopframe(80, 140);
		motionloop(1);
		motionplay(0x11000003);
		rmove_43(292.501343, 23.7658558, 157.241653, 0.0729160011);
		wait(50);
		movecancel();
		file_var_s3_1 = 2;
		sysReqchg(2, ジョニー::talk_step01_02);
		file_var_s4_5[5] = 0;
		reqenable(2);
		return;
	}

	function walk_あまり倒れない()
	{
		file_var_s4_1 = 0;
		file_var_s49_1 = 0;
		while (file_var_s49_1 < 1)
		{
			motionloop(1);
			motionplay_bb(0x11000002, 20);
			file_var_s3_1 = 0;
			move_5e(263.326447, 24.25, 130.546265, 0.0729160011);
			move_5e(272.16214, 24.2518711, 138.630829, 0.0729160011);
			file_var_s4_1 = 1;
			move_5e(292.501343, 23.7658558, 157.241653, 0.0729160011);
			move_5e(303.241028, 24.25, 161.175323, 0.0729160011);
			move_5e(306.829437, 24.25, 160.510651, 0.0729160011);
			motionplay_bb(0x12000005, 10);
			file_var_s3_1 = 1;
			motionsync_282(1);
			motionloop(1);
			motionplay_bb(0x11000002, 20);
			file_var_s3_1 = 0;
			move_5e(303.241028, 24.25, 161.175323, 0.0729160011);
			file_var_s4_1 = 0;
			move_5e(292.501343, 23.7658558, 157.241653, 0.0729160011);
			move_5e(263.326447, 24.25, 130.546265, 0.0729160011);
			move_5e(254.800446, 24.911808, 110.96273, 0.0729160011);
			motionplay_bb(0x12000005, 10);
			file_var_s3_1 = 1;
			motionsync_282(1);
			file_var_s49_1 = (file_var_s49_1 + 1);
		}
		motionloop(1);
		motionplay_bb(0x11000002, 20);
		file_var_s3_1 = 0;
		move_5e(263.326447, 24.25, 130.546265, 0.0729160011);
		move_5e(272.16214, 24.2518711, 138.630829, 0.0729160011);
		file_var_s4_1 = 1;
		move_5e(282.419769, 23.7718849, 148.016357, 0.0729160011);
		reqdisable(2);
		setautorelax(0);
		motionloopframe(80, 140);
		motionloop(1);
		motionplay(0x11000003);
		rmove_43(292.501343, 23.7658558, 157.241653, 0.0729160011);
		wait(50);
		movecancel();
		file_var_s3_1 = 2;
		sysReqchg(2, ジョニー::talk_step01_02);
		file_var_s4_5[5] = 0;
		reqenable(2);
		return;
	}

	function walk_倒れないけどヘタリ()
	{
		file_var_s4_1 = 0;
		while (true)
		{
			motionloop(1);
			motionplay_bb(0x11000002, 20);
			file_var_s3_1 = 0;
			move_5e(263.326447, 24.25, 130.546265, 0.0729160011);
			move_5e(272.16214, 24.2518711, 138.630829, 0.0729160011);
			file_var_s4_1 = 1;
			move_5e(292.501343, 23.7658558, 157.241653, 0.0729160011);
			move_5e(303.241028, 24.25, 161.175323, 0.0729160011);
			move_5e(306.829437, 24.25, 160.510651, 0.0729160011);
			motionplay_bb(0x12000005, 10);
			file_var_s3_1 = 1;
			motionsync_282(1);
			motionloop(1);
			motionplay_bb(0x11000002, 20);
			file_var_s3_1 = 0;
			move_5e(303.241028, 24.25, 161.175323, 0.0729160011);
			file_var_s4_1 = 0;
			move_5e(292.501343, 23.7658558, 157.241653, 0.0729160011);
			move_5e(263.326447, 24.25, 130.546265, 0.0729160011);
			move_5e(254.800446, 24.911808, 110.96273, 0.0729160011);
			motionplay_bb(0x12000005, 10);
			file_var_s3_1 = 1;
			motionsync_282(1);
		}
	}

	function walk_普通に走る()
	{
		file_var_s4_1 = 0;
		while (true)
		{
			file_var_s3_1 = 0;
			move_5e(263.326447, 24.25, 130.546265, getdefaultrunspeed());
			move_5e(272.16214, 24.2518711, 138.630829, getdefaultrunspeed());
			file_var_s4_1 = 1;
			move_5e(292.501343, 23.7658558, 157.241653, getdefaultrunspeed());
			move_5e(303.241028, 24.25, 161.175323, getdefaultrunspeed());
			move_5e(306.829437, 24.25, 160.510651, getdefaultrunspeed());
			motionplay_bb(0x12000005, 20);
			file_var_s3_1 = 1;
			motionsync_282(1);
			file_var_s3_1 = 0;
			move_5e(303.241028, 24.25, 161.175323, getdefaultrunspeed());
			file_var_s4_1 = 0;
			move_5e(292.501343, 23.7658558, 157.241653, getdefaultrunspeed());
			move_5e(263.326447, 24.25, 130.546265, getdefaultrunspeed());
			move_5e(254.800446, 24.911808, 110.96273, getdefaultrunspeed());
			motionplay_bb(0x12000005, 20);
			file_var_s3_1 = 1;
			motionsync_282(1);
		}
	}

	function walk_高速で走る()
	{
		file_var_s4_1 = 0;
		while (true)
		{
			file_var_s3_1 = 0;
			motionloop(1);
			motionplay(0x11000004);
			move_5e(263.326447, 24.25, 130.546265, 0.163859993);
			move_5e(272.16214, 24.2518711, 138.630829, 0.163859993);
			file_var_s4_1 = 1;
			move_5e(292.501343, 23.7658558, 157.241653, 0.163859993);
			move_5e(303.241028, 24.25, 161.175323, 0.163859993);
			move_5e(306.829437, 24.25, 160.510651, 0.163859993);
			motionplay_bb(0x12000005, 5);
			motionratio(1);
			file_var_s3_1 = 1;
			motionsync_282(1);
			file_var_s3_1 = 0;
			motionloop(1);
			motionplay(0x11000004);
			move_5e(303.241028, 24.25, 161.175323, 0.163859993);
			file_var_s4_1 = 0;
			move_5e(292.501343, 23.7658558, 157.241653, 0.163859993);
			move_5e(263.326447, 24.25, 130.546265, 0.163859993);
			move_5e(254.800446, 24.911808, 110.96273, 0.163859993);
			motionplay_bb(0x12000005, 5);
			motionratio(1);
			file_var_s3_1 = 1;
			motionsync_282(1);
		}
	}

	function walk_休憩()
	{
		movecancel();
		stdmotionplay(0x01000012);
		motionsync_282(1);
		return;
	}

	function bindoff_ジョニー()
	{
		bindoff();
		return 0;
	}

	function walk_jony_準備()
	{
		movecancel();
		motioncancel();
		usemapid(0);
		setpos(296.313721, 24.6395035, 134.425583);
		dir(-0.331348002);
		motionloop(1);
		motionplay(0x14000003);
		rlookatr_4bb(0.52359879, -0.34906587);
		return 0;
	}

	function walk_jony_話す()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		return;
	}

	function walk_jony_話し止める()
	{
		setkutipakustatus(0);
		setunazukistatus(0);
		return 0;
	}

	function walk_jony_ジョニー話始める()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		return;
	}

	function walk_jony_過去の話()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		rlookatr_4bb(-0.52359879, -0.87266463);
		return;
	}

	function walk_jony_暗殺事件()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		rlookatr_4bb(0.52359879, -1.04719758);
		return;
	}

	function walk_jony_間違われた()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		rlookatr_4bb(0, 0.52359879);
		return;
	}

	function walk_jony_モブ討伐()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		rlookatr_4bb(-0.52359879, -0.87266463);
		return;
	}

	function walk_jony_頑張る()
	{
		setpos(295.899475, 24.6395035, 135.009125);
		dir(-0.0245510004);
		motionstartframe(213);
		motionplay(0x12000002);
		wait(5);
		setkutipakustatus(1);
		setunazukistatus(1);
		motionsync();
		stdmotionplay(0x01000000);
		sysLookata(PC乗っ取り);
		return;
	}

	function walk_jony_お礼渡す()
	{
		setkutipakustatus(0);
		setunazukistatus(0);
		motionplay_bb(0x14000001, 15);
		motionsync();
		return;
	}

	function walk_jony_仕事に戻る()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		return;
	}

	function walk_jony_走っていく()
	{
		usemapid(1);
		move_5e(290.284668, 24.2500038, 140.779114, getdefaultrunspeed());
		wait(20);
		raturn_25e(1.63351202);
		sysLookata(PC乗っ取り);
		turnsync();
		return;
	}

	function walk_jony_レックスに似てる()
	{
		setkutipakustatus(1);
		setunazukistatus(1);
		return;
	}

	function walk_jony_去る()
	{
		rmove_43(281.128387, 23.7658558, 149.317291, getdefaultrunspeed());
		lookatoff();
		return;
	}

	function walk_jony_クリアイベント終了()
	{
		movecancel();
		return 0;
		return;
	}
}

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

//======================================================================
//                          Map exit arrays                           //
//======================================================================

mapExitArray mapExitGroup0[6] = {

	exitStruct mapExit0 = {
		273.504944, 22.9741859, 175.956741, 1,
		264.234802, 22.9742012, 169.770706, 15, 0, 0
	};

	exitStruct mapExit1 = {
		0, 0, 0, 0,
		0, 0, 0, 0, 0, 0
	};

	exitStruct mapExit2 = {
		0, 0, 0, 0,
		0, 0, 0, 0, 0, 0
	};

	exitStruct mapExit3 = {
		0, 0, 0, 0,
		0, 0, 0, 0, 0, 0
	};

	exitStruct mapExit4 = {
		0, 0, 0, 0,
		0, 0, 0, 0, 0, 0
	};

	exitStruct mapExit5 = {
		304.466339, 29, 122.122765, 1,
		309.369415, 29, 127.025932, 15, 20, 0
	};

};

mapExitArray mapExitGroup1[0] = {

};

mapExitArray mapExitGroup2[0] = {

};

mapExitArray mapExitGroup3[4] = {

	exitStruct mapExit0 = {
		315, 28.9999943, 115, 0,
		0, 0, 0, 0, 0, 0
	};

	exitStruct mapExit1 = {
		315, 28.9999943, 115, 0,
		0, 0, 0, 0, 0, 0
	};

	exitStruct mapExit2 = {
		277.519989, 24.2500038, 135.063828, 0,
		0, 0, 0, 0, 0, 0
	};

	exitStruct mapExit3 = {
		296.213837, 24.2500019, 144.64682, 0,
		0, 0, 0, 0, 0, 0
	};

};

mapExitArray mapExitGroup4[0] = {

};

//======================================================================
//                     Map jump position vectors                      //
//======================================================================

mjPosArr1 mapJumpPositions1[3] = {

	mjPos mapJumpPos0 = {
		271.414459, 22.8100471, 168.48996, 2.43717551,
		0, 0, 0, 0
	};

	mjPos mapJumpPos1 = {
		271.414459, 22.8100471, 168.48996, 2.43717551,
		0, 0, 0, 0
	};

	mjPos mapJumpPos2 = {
		303.89447, 22.8100471, 127.640251, -0.813732147,
		0, 0, 0, 0
	};

};

mjPosArr2 mapJumpPositions2[5] = {

	mjPos mapJumpPos0 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos1 = {
		231.825546, 22.8100471, 222.530716, -0.606330991,
		0, 0, 0, 0
	};

	mjPos mapJumpPos2 = {
		271.414459, 22.8100471, 168.48996, 2.43717551,
		0, 0, 0, 0
	};

	mjPos mapJumpPos3 = {
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	mjPos mapJumpPos4 = {
		303.89447, 22.8100471, 127.640251, -0.813732147,
		0, 0, 0, 0
	};

};

//======================================================================
//                      Unknown position arrays                       //
//======================================================================
unkPos1 unknownPosition0[7] = {306.677917, 29, 125.26841, 0.649999976, 2, 0.785397112, 0};
unkPos1 unknownPosition1[7] = {307, 29, 125, 4, 4, 0.785397112, 0};

unkPos2 unknownPosition0[7] = {307, 30.2000008, 125, 2, 2, 0, 0};

//======================================================================
//                         Unknown u16 Arrays                         //
//======================================================================

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
	unk16ArrEntry unknown16Array20 = {267, 1, 325, 325, 1, 65535, 0, 0};
};

unk16Arr3 unknown16Arrays3[5] = {
	unk16ArrEntry unknown16Array0 = {0, 768, 1, 1};
	unk16ArrEntry unknown16Array1 = {1, 768, 1, 1};
	unk16ArrEntry unknown16Array2 = {2, 768, 1, 1};
	unk16ArrEntry unknown16Array3 = {3, 768, 1, 1};
	unk16ArrEntry unknown16Array4 = {4, 768, 1, 1};
};

//======================================================================
//                      REQALL/REQWAITALL arrays                      //
//======================================================================

reqa   reqArr0[] = {
	NAC_A03_NPC01::set,
	NAC_A03_NPC02::set,
	NAC_A03_NPC03::set,
	NPC_Alchemist::set
};

reqa   reqArr1[] = {
	マップ帝国君用アタリ::setHitObj,
	NAC_A03_NPC07用アタリ::setHitObj,
	NAC_A03_NPC11用アタリ::setHitObj
};

reqa   reqArr2[] = {
	マップ帝国君移植版::motion_TAG,
	NAC_A03_NPC01::motion_TAG,
	NAC_A03_NPC02::motion_TAG,
	NAC_A03_NPC03::motion_TAG
};

reqa   reqArr3[] = {
	NAC_A03_NPC01::walk,
	NAC_A03_NPC02::walk,
	NAC_A03_NPC03::walk
};

reqa   reqArr4[] = {
	NAC_A03_NPC04::set_後読み,
	NAC_A03_NPC05::set_後読み,
	NAC_A03_NPC06::set_後読み,
	NAC_A03_NPC07::set_後読み,
	NAC_A03_NPC08::set_後読み,
	NAC_A03_NPC09::set_後読み,
	NAC_A03_NPC10::set_後読み,
	NAC_A03_NPC11::set_後読み,
	NAC_A03_NPC12::set_後読み,
	NAC_A03_NPC13::set_後読み,
	NAC_A03_NPC14::set_後読み,
	NAC_A03_NPC15::set_後読み,
	NAC_A03_NPC16::set_後読み,
	NAC_A03_NPC17::set_後読み,
	サボテン１::set_後読み
};

reqa   reqArr5[] = {
	NAC_A03_BG_NPC01::set_後読み_遠景,
	NAC_A03_BG_NPC02::set_後読み_遠景,
	NAC_A03_BG_NPC04::set_後読み_遠景,
	NAC_A03_BG_NPC05::set_後読み_遠景
};

reqa   reqArr6[] = {
	監視_NPC0809::walk_後読み,
	NAC_A03_NPC04::walk_後読み,
	NAC_A03_NPC06::walk_後読み,
	NAC_A03_NPC10::walk_後読み,
	NAC_A03_NPC12::walk_後読み
};

reqa   reqArr7[] = {
	NAC_A03_BG_NPC01::walk_後読み_遠景,
	NAC_A03_BG_NPC02::walk_後読み_遠景,
	NAC_A03_BG_NPC05::walk_後読み_遠景
};

reqa   reqArr8[] = {
	依頼人モルガン::walk_q145_準備,
	ジョニー２号::walk_q145_準備,
	PC乗っ取り::walk_q145_準備
};

reqa   reqArr9[] = {
	ジョニー２号::walk_q145_ジョニー来る
};

reqa  reqArr10[] = {
	依頼人モルガン::walk_q145_元に戻す,
	PC乗っ取り::walk_q145_元に戻す
};

reqa  reqArr11[] = {
	依頼人モルガン::walk_q145_クリアイベント終了,
	PC乗っ取り::walk_q145_クリアイベント終了
};

reqa  reqArr12[] = {
	依頼人バロング::walk_q151_準備,
	ジョニー２号::walk_q151_準備,
	PC乗っ取り::walk_q151_準備
};

reqa  reqArr13[] = {
	ジョニー２号::walk_q151_ジョニー来る
};

reqa  reqArr14[] = {
	依頼人バロング::walk_q151_嫌な顔すんな
};

reqa  reqArr15[] = {
	依頼人バロング::walk_q151_元に戻す,
	PC乗っ取り::walk_q151_元に戻す
};

reqa  reqArr16[] = {
	依頼人バロング::walk_q151_クリアイベント終了,
	PC乗っ取り::walk_q151_クリアイベント終了
};

reqa  reqArr17[] = {
	PC乗っ取り::walk_jony_準備,
	ジョニー::walk_jony_準備
};

reqa  reqArr18[] = {
	PC乗っ取り::walk_jony_ジョニー話始める,
	ジョニー::walk_jony_ジョニー話始める
};

reqa  reqArr19[] = {
	ジョニー::walk_jony_過去の話
};

reqa  reqArr20[] = {
	ジョニー::walk_jony_暗殺事件
};

reqa  reqArr21[] = {
	ジョニー::walk_jony_間違われた
};

reqa  reqArr22[] = {
	ジョニー::walk_jony_モブ討伐
};

reqa  reqArr23[] = {
	PC乗っ取り::walk_jony_頑張る,
	ジョニー::walk_jony_頑張る
};

reqa  reqArr24[] = {
	ジョニー::walk_jony_仕事に戻る
};

reqa  reqArr25[] = {
	PC乗っ取り::walk_jony_走っていく,
	ジョニー::walk_jony_走っていく
};

reqa  reqArr26[] = {
	ジョニー::walk_jony_レックスに似てる
};

reqa  reqArr27[] = {
	PC乗っ取り::walk_jony_クリアイベント終了,
	ジョニー::walk_jony_クリアイベント終了
};
