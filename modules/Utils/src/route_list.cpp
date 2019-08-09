#include "route_list.h"
#include "error_code.h"
/* public */
RouteList::
RouteList()
{
    this->list_data_begin = NULL;
    this->list_data_end = NULL;
    this->head_ptr = NULL;
    this->tail_ptr = NULL;
    this->total_length = 0;
    this->curr_length = 0;
}

RouteList::
~RouteList()
{
    this->list_data_end = NULL;
    this->head_ptr = NULL;
    this->tail_ptr = NULL;
    if (this->list_data_begin != NULL) {
        delete[] this->list_data_begin;
    }
    this->total_length = 0;
    this->axis_num = 0;
    this->step_len = 0;
    this->curr_length = 0;
}

int RouteList::
init(unsigned int axis_num=6, unsigned int list_length=30)
{
    this->total_length = list_length;
    this->step_len = PER_POS_LEN_BYTE*axis_num;
    this->list_data_begin = new unsigned char[this->step_len*list_length];
    this->list_data_end = this->list_data_begin + (this->total_length - 1)*this->step_len;
    this->head_ptr = this->tail_ptr = this->list_data_begin;
    this->axis_num = axis_num;
    return OK;
}

int RouteList::
getData(unsigned char* route_data, unsigned int steps=5)
{
    if (route_data == NULL || steps > this->curr_length) {
        throwErrorCode(ARGS_INVALID);
    }
    if (this->head_ptr + len_byte > this->list_data_end) {  // pop data split to 2 block
        int rest_len = this->head_ptr + len_byte - this->list_data_end;
        memcpy(pop_data, this->head_ptr, len_byte - rest_len);
        memcpy(&pop_data[len_byte - rest_len], this->list_data_begin, rest_len);
    } else {
        memcpy(pop_data, this->head_ptr, len_byte);
    }
    return OK;
}

int RouteList::
getRouteLen()
{
    return this->curr_length;
}

int RouteList::
popUp(unsigned char* pop_data, unsigned int steps)
{
    if (pop_data == NULL || steps > this->curr_length) {
        throwErrorCode(ARGS_INVALID);
    }
    int len_byte = steps * this->step_len;
    if (this->head_ptr + len_byte > this->list_data_end) {  // pop data split to 2 block
        int rest_len = this->head_ptr + len_byte - this->list_data_end;
        memcpy(pop_data, this->head_ptr, len_byte - rest_len);
        memcpy(&pop_data[len_byte - rest_len], this->list_data_begin, rest_len);
        this->head_ptr = this->data_begin + rest_len;
    } else {
        memcpy(pop_data, this->head_ptr, len_byte);
        this->head_ptr += len_byte;
    }
    this->curr_length -= steps;
    return this->curr_length;       // return current length
}

int RouteList::
pushBack(const unsigned char* push_data, unsigned int steps)
{
    if (pop_data == NULL || steps + this->curr_length > this->total_length) {
        throwErrorCode(ARGS_INVALID);
    }
    int len_byte = steps * this->step_len;
    if (this->tail_ptr + len_byte > this->list_data_end) {  // push data split to 2 block
        int rest_len = this->tail_ptr + len_byte - this->list_data_end;
        memcpy(push_data, this->tail_ptr, len_byte - rest_len);
        memcpy(&push_data[len_byte - rest_len], this->list_data_begin, rest_len);
        this->tail_ptr = this->data_begin + rest_len; 
    } else {
        memcpy(push_data, this->tail_ptr, len_byte);
        this->tail_ptr += len_byte;
    }
    this->curr_length += steps;
    return this->curr_length;
}


/* private */
// unsigned char* nextStep(unsigned char* curr_ptr, unsigned int steps)
// {
//     steps = steps % this->total_length;     // avoid steps larger then total length
//     int len_byte = steps * this->step_len;
//     if (this->curr_ptr + len_byte > this->list_data_end) {
//         this->curr_ptr = this->list_data_begin + (this->curr_ptr + len_byte - this->list_data_end);
//     } else {
//         this->curr_ptr += len_byte;
//     }
//     return this->curr_ptr;
// }

// unsigned char* prevStep(unsigned char* curr_ptr, unsigned int steps)
// {
//     steps = steps % this->total_length;     // avoid steps larger then total length
//     int len_byte = steps * this->step_len;
//     if (this->curr_ptr - steps < this->list_data_begin) {
//         this->curr_ptr = this->list_data_end - (len_byte - this->curr_ptr - this->list_data_begin); // pointer address cannot be negative
//     } else {
//         this->curr_ptr -= len_byte;
//     }
//     return this->curr_ptr;
// }