#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "vsoa_client.h"
#include "vsoa_position.h"
#include "vsoa_platform.h"
#include "cJSON.h"
#include <QString>

#define CLIENT_ADDR   "192.168.116.131"
#define CLIENT_PORT   3000
/* My server password */
#define MY_SERVER_PASSWD "123456"

#define RPC 0 //通过RRC方式获取数据
#define SUB 1 //通过订阅获取数据

/* My client */
static vsoa_client_t *client;

//double  speed;
//double  steering;

static void on_set_url (void *arg, struct vsoa_client *client, vsoa_header_t *vsoa_hdr, vsoa_payload_t *payload);
static void on_get_url (void *arg, struct vsoa_client *client, vsoa_header_t *vsoa_hdr, vsoa_payload_t *payload);
static void get_foo (void *arg, struct vsoa_client *client, vsoa_header_t *vsoa_hdr, vsoa_payload_t *payload);
static void onmessage (void *arg, struct vsoa_client *client, vsoa_url_t *url, vsoa_payload_t *payload, bool quick);
static void vsoa_json_stringify_free (char *str);
static char *vsoa_json_stringify (const vsoa_url_t *url, double data);
static bool vsoa_json_parse (double *data, const char *str, size_t len, const vsoa_url_t *url);
int client_set(char* key, double value);
int car_initialize();
//double client_get(char* key);
//char* setJsonData(char* key, double value);

#endif // CLIENT_H
