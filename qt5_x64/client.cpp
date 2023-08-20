#include "client.h"

static bool vsoa_json_parse (double *data, const char *str, size_t len, const vsoa_url_t *url)
{
    cJSON *json, *item;

    json = cJSON_ParseWithLength(str, len);
    if (!json) {
        return	(false);
    }
    item = cJSON_GetObjectItem(json, &url->url[1]);
    if (item && cJSON_IsNumber(item)) {
        *data = cJSON_GetNumberValue(item);
    } else {
        goto	error;
    }
    cJSON_Delete(json);

    return	(true);

error:
    return	(false);
}

/*
 * Serialize the data into a JSON string
 */
static char * vsoa_json_stringify (const vsoa_url_t *url, double data)
{
    char *string;
    cJSON *json, *item;

    json = cJSON_CreateObject();
    if (!json) {
        return	(NULL);
    }

    item = cJSON_CreateNumber(data);
    if (!item) {
        goto	error;
    }
    if (!cJSON_AddItemToObject(json, &url->url[1], item)) {
        cJSON_Delete(item);
        goto	error;
    }

    string = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    return	(string);

error:
    cJSON_Delete(json);

    return	(NULL);
}

/*
 * Free vsoa_json_stringify() return value
 */
static void vsoa_json_stringify_free (char *str)
{
    if (str) {
        cJSON_free(str);
    }
}

/*
 * On message
 * (void *arg, vsoa_client_t *client, vsoa_url_t *url, vsoa_payload_t *payload, bool quick);
 */

static void onmessage (void *arg, struct vsoa_client *client, vsoa_url_t *url, vsoa_payload_t *payload, bool quick)
{
    double  data = 0;
    char string[32] = {0};



    printf("On message, URL: %.*s payload: %.*s\n",
           (int)url->url_len, url->url, (int)payload->param_len, payload->param);

    memcpy(string, url->url, url->url_len);
    url->url = string;
    string[url->url_len] = '\0';


    if (payload->param) {
        vsoa_json_parse(&data, payload->param, payload->param_len, url);
#if 0
        if (!memcmp("/leftfronttire", url->url, strlen(url->url)) | !memcmp("/rightfronttire", url->url, strlen(url->url)) |
                !memcmp("/leftreartire", url->url, strlen(url->url)) | !memcmp("/rightreartire", url->url, strlen(url->url))) {
            printf("data== %0.1f\r\n", (float)data);
        } else {
            printf("data== %d\r\n", (int)data);

        }
#endif
    }
}

/*
 * Get url
 */
#if 0
static void Client::get_foo (void *arg, struct vsoa_client *client, vsoa_header_t *vsoa_hdr, vsoa_payload_t *payload)
{
    struct data data;

    if (!vsoa_hdr) {
        fprintf(stderr, "VSOA server /foo reply timeout!\n");
        return;
    }

    if (!foo_json_parse(&data, payload->param, payload->param_len)) {
        fprintf(stderr, "VSOA server /foo reply format error!\n");
        return;
    }

    //    printf("RPC /foo reply foo: %d\n", data.foo);

    foo_json_parse_free(&data);
}
#endif
/*
 * Get url
 *
 */
static void on_get_url (void *arg, struct vsoa_client *client, vsoa_header_t *vsoa_hdr, vsoa_payload_t *payload)
{
    if (vsoa_hdr->status == VSOA_STATUS_SUCCESS) {
        printf("GET URL, param: %.*s\n",(int)payload->param_len, payload->param);
        printf("bug\n");
    }else {
        printf("vsoa_hdr->status=%d\n",vsoa_hdr->status);
    }
}

/*
 * Get url
 */
static void on_set_url (void *arg, struct vsoa_client *client, vsoa_header_t *vsoa_hdr, vsoa_payload_t *payload)
{

    if (vsoa_hdr->status == VSOA_STATUS_SUCCESS) {
        printf("SET URL, param: %.*s\n",(int)payload->param_len, payload->param);

    }else {
        printf("vsoa_hdr->status=%d\n",vsoa_hdr->status);
    }
}

/*
 * main function
 */
int client_set (char* key, double value)
{
    char info[256];
    vsoa_url_t url_current;
    socklen_t serv_len = sizeof(struct sockaddr_in);
    struct sockaddr_in addr;
    struct timespec timeout = { 1, 0 };
    vsoa_payload_t payload;

    url_current.url = key;
    url_current.url_len = strlen(key);
    char* cjson= vsoa_json_stringify(&url_current,value);


    if (!vsoa_position_lookup(AF_INET, "automobile_dash_board",
                              (struct sockaddr *)&addr, &serv_len, NULL, &timeout)) {
        fprintf(stderr, "Can not found VSOA server!\n");
        return  (-1);
    }

    client = vsoa_client_create(onmessage, NULL);
    if (!client) {
        fprintf(stderr, "Can not create VSOA client!\n");
        return  (-1);
    }

    if (!vsoa_client_connect(client, (struct sockaddr *)&addr, sizeof(struct sockaddr_in),
                             &timeout, MY_SERVER_PASSWD, info, sizeof(info))) {
        vsoa_client_close(client);
        fprintf(stderr, "Can not connect to VSOA server!\n");
        return  (-1);
    }

    printf("Server (%s) connected\n", info);

    payload.data = NULL;
    payload.data_len = 0;
    payload.param = cjson;
    payload.param_len = strlen(cjson);
    printf("url=%s\r\n",url_current.url);

    vsoa_client_call(client, VSOA_CLIENT_RPC_METHOD_SET,
                     &url_current, &payload, on_set_url, NULL, &timeout);
    printf("set successfully\n");
    return 0;
}

//double client_get(char *key)
//{
//    char info[256];
//    vsoa_url_t url_current;
//    socklen_t serv_len = sizeof(struct sockaddr_in);
//    struct sockaddr_in addr;
//    struct timespec timeout = { 1, 0 };
//    vsoa_payload_t payload;

//    if (!vsoa_position_lookup(AF_INET, "automobile_dash_board",
//                              (struct sockaddr *)&addr, &serv_len, NULL, &timeout)) {
//        fprintf(stderr, "Can not found VSOA server!\n");
//        return  0;
//    }

//    client = vsoa_client_create(onmessage, NULL);
//    if (!client) {
//        fprintf(stderr, "Can not create VSOA client!\n");
//        return  0;
//    }

//    if (!vsoa_client_connect(client, (struct sockaddr *)&addr, sizeof(struct sockaddr_in),
//                             &timeout, MY_SERVER_PASSWD, info, sizeof(info))) {
//        vsoa_client_close(client);
//        fprintf(stderr, "Can not connect to VSOA server!\n");
//        return  0;
//    }

//    printf("Server (%s) connected\n", info);

//    char* c_json;
//    url_current.url = key;
//    url_current.url_len  = strlen(url_current.url);
//    payload.data = NULL;
//    payload.data_len = 0;
//    payload.param = NULL;
//    payload.param_len = 0;
//    printf("url=%s\r\n",url_current.url);

//    vsoa_client_call(client, VSOA_CLIENT_RPC_METHOD_GET,
//                     &url_current, NULL, on_get_url, NULL, &timeout);

//    printf("GET URL, param: %s\n",url_current.url);
//    printf("%s\n",payload.param);
//    printf("%lf\n",payload.data);
//    double data;
//    const char *jsonString = "{\"speed\": 123.45}";
//    size_t jsonStringLen = strlen(jsonString);
//    vsoa_url_t url;
//    url.url = key;

//    bool suc = vsoa_json_parse(&data, payload.param, payload.param_len, &url_current);
//    if (suc) {
//        printf("Parsed data: %f\n", data);
//    } else {
//        printf("Failed to parse JSON\n");
//    }
//    printf("get successfully\n");


//    return 0;
//}



int car_initialize()
{
    char* speed_key = "/speed";
    double speed_value = 1;
    client_set(speed_key,speed_value);
    // set 100
    char* power_key = "/power";
    double power_value = 100;
    client_set(power_key,power_value);
    // switch N
    char* gear_key = "/gear";
    double gear_value = 2;
    client_set(gear_key,gear_value);
    char* mileage_key = "/mileage";
    double mileage_value = 10050;
    client_set(mileage_key,mileage_value);
    char* seatbeltwaring_key = "/seatbeltwaring";
    double seatbeltwaring_value = 0;
    client_set(seatbeltwaring_key,seatbeltwaring_value);
    char* abswarning_key = "/abswarning";
    double abswarning_value = 1;
    client_set(abswarning_key,abswarning_value);

    char* leftfronttire_key = "/leftfronttire";
    double leftfronttire_value = 2.5;
    client_set(leftfronttire_key,leftfronttire_value);
    char* rightfronttire_key = "/rightfronttire";
    double rightfronttire_value = 2.5;
    client_set(rightfronttire_key,rightfronttire_value);
    char* leftreartire_key = "/leftreartire";
    double leftreartire_value = 2.5;
    client_set(leftreartire_key,leftreartire_value);
    char* rightreartire_key = "/rightreartire";
    double rightreartire_value = 2.5;
    client_set(rightreartire_key,rightreartire_value);

    char* airbag_key = "/airbag_key";
    double airbag_value = 0;
    client_set(airbag_key,airbag_value);
//    char* door_key = "/leftfronttire";
//    double lfdoor_value = 1;
//    double rfdoor_value = 2;
//    double lbdoor_value = 4;
//    double rbdoor_value = 8;
//    client_set(door_key,lfdoor_value);
//    client_set(door_key,rfdoor_value);
//    client_set(door_key,lbdoor_value);
//    client_set(door_key,rbdoor_value);
    return 0;
}
