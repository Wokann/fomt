#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1042_TV_HarvestTheater.mary.h"

void EventScript_1042_TV_HarvestTheater(void)
{
    int var_0;
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
        case SEASON_FALL:
            SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode12);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode13);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode19);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode30);
                    break;
            }
            break;
        case SEASON_SUMMER:
        case SEASON_WINTER:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode31);
                    break;
                case DAY_02:
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode32);
                    break;
                case DAY_03:
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode33);
                    break;
                case DAY_04:
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode34);
                    break;
                case DAY_05:
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode35);
                    break;
                case DAY_06:
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode36);
                    break;
                case DAY_07:
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode37);
                    break;
                case DAY_08:
                    SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode38);
                    break;
                case DAY_09:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode39);
                    break;
                case DAY_10:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode40);
                    break;
                case DAY_11:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode41);
                    break;
                case DAY_12:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode42);
                    break;
                case DAY_13:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode43);
                    break;
                case DAY_14:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode44);
                    break;
                case DAY_15:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode45);
                    break;
                case DAY_16:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode46);
                    break;
                case DAY_17:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode47);
                    break;
                case DAY_18:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode48);
                    break;
                case DAY_19:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode49);
                    break;
                case DAY_20:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode50);
                    break;
                case DAY_21:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode51);
                    break;
                case DAY_22:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode52);
                    break;
                case DAY_23:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode53);
                    break;
                case DAY_24:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode54);
                    break;
                case DAY_25:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode55);
                    break;
                case DAY_26:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode56);
                    break;
                case DAY_27:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode57);
                    break;
                case DAY_28:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode58);
                    break;
                case DAY_29:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode59);
                    break;
                case DAY_30:
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    var_0 = ShowTelevisionMessage(gText_TV_HarvestTheater_Episode60);
                    break;
            }
            break;
    }
    EndTelevisionProgram();
    TalkClose();
    switch (var_0)
    {
        case TELEVISION_INPUT_UP_WEATHER:
        case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
        case TELEVISION_INPUT_RIGHT_NEWS:
        case TELEVISION_INPUT_LEFT_VARIETY:
            VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
            CallScript(EventScript_0540_TV_EntertainmentChannel);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
    }
}
