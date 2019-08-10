#include "rcs_comm.h"
#include "uart_comm.h"
#include "route_list.h"
// #include "error_code.h"

int main()
{
    // // test uart comm
    // UARTComm uart_comm;
    // BufferFromDSP from_dsp;
    // BufferToDSP to_dsp;
    // unsigned char temp_ack = 10;
    // unsigned char temp_cf = 12;
    // to_dsp.setAck(&temp_ack, sizeof(temp_ack));
    // to_dsp.setControlFlag(&temp_cf, sizeof(temp_cf));
    // uart_comm.read(&from_dsp);
    // uart_comm.write(&to_dsp);
    // fprintf(stderr, ">>%u\n", *(from_dsp.getProtectCode()));
    // fprintf(stderr, ">>%u\n", *(from_dsp.getServoBrake()));
    // fprintf(stderr, ">>%u\n", *(from_dsp.getAck()));
    // fprintf(stderr, ">>%u\n", *(from_dsp.getCrc()));

    // // test rcs comm
    // RCSComm rcs_comm;
    // BufferToRCS to_rcs;
    // BufferFromRCS from_rcs;

    // unsigned char rcs_rc = 90;
    // unsigned char rcs_echo = 91;

    // to_rcs.setRequestCounter(&rcs_rc, sizeof(rcs_rc));
    // to_rcs.setEcho(&rcs_echo, sizeof(rcs_echo));
    // rcs_comm.read(&from_rcs);
    // rcs_comm.write(&to_rcs);

    // fprintf(stderr, ">>%u\n", *(from_rcs.getControlFlag()));
    // fprintf(stderr, ">>%u\n", *(from_rcs.getID()));
    // fprintf(stderr, ">>%u\n", (from_rcs.getCheckSum()));


    // test loop list stuct
    RouteList route_list;
    unsigned int groups = 6;
    unsigned int step = 8;
    unsigned int group_len = step * groups;
    unsigned char push_data[group_len];
    unsigned char pop_data[group_len];
    unsigned char get_data[group_len];
    for(int i = 0; i < groups; ++i) {
        memset(&push_data[i*step], i+1, step);
        memset(&pop_data[i*step], 0, step);
        memset(&get_data[i*step], 0, step);
    }

    printData(push_data, group_len, "pushdata", step);
    route_list.init(2, groups);

    // route_list.getData(get_data, 7);
    // route_list.popUp(get_data, 7);
    for(int i = 0; i < groups; ++i) {
        route_list.pushBack(&push_data[i*step], 2);
        if (i == 1) {
            route_list.popUp(pop_data, 3);
            printData(pop_data, group_len, "popdata", step);
        }
    }
    route_list.getData(get_data, 5);
    printData(get_data, group_len, "getdata", step);
    // route_list.popUp(get_data, 5);
    // route_list.popUp(get_data, 5);
    // route_list.popUp(get_data, 5);
    // route_list.popUp(get_data, 7);


    return 0;
}