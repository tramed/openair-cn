/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under 
 * the Apache License, Version 2.0  (the "License"); you may not use this file
 * except in compliance with the License.  
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */


#ifndef S6A_MESSAGES_H_
#define S6A_MESSAGES_H_

int s6a_generate_update_location(s6a_update_location_req_t *ulr_p);
int s6a_generate_authentication_info_req(s6a_auth_info_req_t *uar_p);
int s6a_generate_notify_req(s6a_notify_req_t *uar_p);

int s6a_ula_cb(struct msg **msg, struct avp *paramavp,
               struct session *sess, void *opaque,
               enum disp_action *act);
int s6a_aia_cb(struct msg **msg, struct avp *paramavp,
               struct session *sess, void *opaque,
               enum disp_action *act);
int s6a_clr_cb(struct msg **msg, struct avp *paramavp,
               struct session *sess, void *opaque,
               enum disp_action *act);
int s6a_rr_cb(struct msg **msg, struct avp *paramavp,
               struct session *sess, void *opaque,
               enum disp_action *act);
int s6a_na_cb(struct msg **msg, struct avp *paramavp,
               struct session *sess, void *opaque,
               enum disp_action *act);

int s6a_add_result_code_mme(struct msg *ans, struct avp *failed_avp,
                        int result_code, int experimental);

int s6a_parse_subscription_data(struct avp *avp_subscription_data,
                                subscription_data_t *subscription_data);

#endif /* S6A_MESSAGES_H_ */
