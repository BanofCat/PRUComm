#ifndef __MODULES_UTILS_ROUTE_LIST_H__
#define __MODULES_UTILS_ROUTE_LIST_H__


#define PER_POS_LEN_BYTE 4

class RouteList
{
private:
    unsigned int axis_num;
    unsigned int total_length;
    unsigned int curr_length;
    unsigned char* head_ptr;
    unsigned char* tail_ptr;
    unsigned char* list_data_begin;
    unsigned char* list_data_end;
    unsigned int step_len;

public:
    RouteList();
    ~RouteList();
    int init(unsigned int axis_num=6, unsigned int list_length=30);
    int getData(unsigned char* route_data, unsigned int steps);
    int pushBack(const unsigned char* push_data, unsigned int steps);
    int popUp(unsigned char* pop_data, unsigned int steps);
    int getRouteLen();


private:
    // unsigned char* nextStep(unsigned char* curr_ptr, unsigned int steps=1);
    // unsigned char* prevStep(unsigned char* curr_ptr, unsigned int steps=1);

}; // !class RouteList
#endif // !__MODULES_UTILS_ROUTE_LIST_H__